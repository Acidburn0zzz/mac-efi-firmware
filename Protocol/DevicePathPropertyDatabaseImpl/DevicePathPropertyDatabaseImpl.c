/** @file
  Apple protocol to manage Device Properties from firmware.

  Copyright (C) 2005 - 2017, Apple Inc.  All rights reserved.<BR>

  This program and the accompanying materials have not been licensed.
  Neither is its usage, its redistribution, in source or binary form,
  licensed, nor implicitely or explicitely permitted, except when
  required by applicable law.

  Unless required by applicable law or agreed to in writing, software
  distributed is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
  OR CONDITIONS OF ANY KIND, either express or implied.
**/

#include <AppleEfi.h>

#include <Library/AppleDriverLib.h>

#include APPLE_PROTOCOL_PRODUCER (DevicePathPropertyDatabaseImpl)

#define EFI_DEVICE_PATH_PROPERTY_NODE_SIGNATURE  \
  EFI_SIGNATURE_32 ('D', 'p', 'n', '\0')

#define PROPERTY_NODE_FROM_LIST_ENTRY(Entry)   \
  ((EFI_DEVICE_PATH_PROPERTY_NODE *)(          \
    CR (                                       \
      Entry,                                   \
      EFI_DEVICE_PATH_PROPERTY_NODE_HDR,       \
      This,                                    \
      EFI_DEVICE_PATH_PROPERTY_NODE_SIGNATURE  \
      )                                        \
    ))

#define EFI_DEVICE_PATH_PROPERTY_NODE_SIZE(Node)  \
  (sizeof ((Node)->Hdr) + EfiDevicePathSize (&(Node)->DevicePath))

// EFI_DEVICE_PATH_PROPERTY_NODE_HDR
typedef struct {
  UINTN          Signature;           ///< 
  EFI_LIST_ENTRY This;                ///< 
  UINTN          NumberOfProperties;  ///< 
  EFI_LIST       Properties;          ///< 
} EFI_DEVICE_PATH_PROPERTY_NODE_HDR;

// DEVICE_PATH_PROPERTY_NODE
typedef struct {
  EFI_DEVICE_PATH_PROPERTY_NODE_HDR Hdr;         ///< 
  EFI_DEVICE_PATH_PROTOCOL          DevicePath;  ///< 
} EFI_DEVICE_PATH_PROPERTY_NODE;

#define EFI_DEVICE_PATH_PROPERTY_SIGNATURE  \
  EFI_SIGNATURE_32 ('D', 'p', 'p', '\0')

#define EFI_DEVICE_PATH_PROPERTY_FROM_LIST_ENTRY(Entry)  \
  CR (                                                   \
    (Entry),                                             \
    EFI_DEVICE_PATH_PROPERTY,                            \
    This,                                                \
    EFI_DEVICE_PATH_PROPERTY_SIGNATURE                   \
    )

#define EFI_DEVICE_PATH_PROPERTY_SIZE(Property)  \
  ((Property)->Name->Hdr.Size + (Property)->Value->Hdr.Size)

#define EFI_DEVICE_PATH_PROPERTY_VALUE_SIZE(Property)  \
  ((Property)->Value->Hdr.Size - sizeof ((Property)->Value->Hdr))

#define NEXT_EFI_DEVICE_PATH_PROPERTY(Property)                   \
  (EFI_DEVICE_PATH_PROPERTY *)(                                   \
    (UINTN)(Property) + EFI_DEVICE_PATH_PROPERTY_SIZE (Property)  \
    )

// EFI_DEVICE_PATH_PROPERTY
typedef struct {
  UINTN                         Signature;  ///< 
  EFI_LIST_ENTRY                This;       ///< 
  EFI_DEVICE_PATH_PROPERTY_DATA *Name;      ///< 
  EFI_DEVICE_PATH_PROPERTY_DATA *Value;     ///< 
} EFI_DEVICE_PATH_PROPERTY;

// TODO: Move to own header
//
#define UNKNOWN_PROTOCOL_GUID                             \
  { 0xC649D4F3, 0xD502, 0x4DAA,                           \
    { 0xA1, 0x39, 0x39, 0x4A, 0xCC, 0xF2, 0xA6, 0x3B } }

EFI_GUID mUnknownProtocolGuid = UNKNOWN_PROTOCOL_GUID;
//

// InternalGetPropertyNode
STATIC
EFI_DEVICE_PATH_PROPERTY_NODE *
InternalGetPropertyNode (
  IN EFI_DEVICE_PATH_PROPERTY_DATABASE  *Database,
  IN EFI_DEVICE_PATH_PROTOCOL           *DevicePath
  ) // sub_AC5
{
  EFI_DEVICE_PATH_PROPERTY_NODE *Node;
  UINTN                         DevicePathSize;
  BOOLEAN                       IsNodeNull;
  UINTN                         DevicePathSize2;
  INTN                          Result;

  Node = PROPERTY_NODE_FROM_LIST_ENTRY (
           GetFirstNode (&Database->Nodes)
           );

  DevicePathSize = EfiDevicePathSize (DevicePath);

  do {
    IsNodeNull = IsNull (&Database->Nodes, &Node->Hdr.This);

    if (IsNodeNull) {
      Node = NULL;

      break;
    }

    DevicePathSize2 = EfiDevicePathSize (&Node->DevicePath);

    if (DevicePathSize == DevicePathSize2) {
      Result = EfiCompareMem (DevicePath, &Node->DevicePath, DevicePathSize);

      if (Result == 0) {
        break;
      }
    }

    Node = PROPERTY_NODE_FROM_LIST_ENTRY (
             GetNextNode (&Database->Nodes, &Node->Hdr.This)
             );
  } while (TRUE);

  return Node;
}

// InternalGetProperty
STATIC
EFI_DEVICE_PATH_PROPERTY *
InternalGetProperty (
  IN CHAR16                         *Name,
  IN EFI_DEVICE_PATH_PROPERTY_NODE  *Node
  )
{
  EFI_DEVICE_PATH_PROPERTY *Property;

  BOOLEAN                  IsPropertyNull;
  INTN                     Result;

  Property = EFI_DEVICE_PATH_PROPERTY_FROM_LIST_ENTRY (
               GetFirstNode (&Node->Hdr.Properties)
               );

  do {
    IsPropertyNull = IsNull (&Node->Hdr.Properties, &Property->This);

    if (IsPropertyNull) {
      Property = NULL;

      break;
    }

    Result = EfiStrCmp (Name, (CHAR16 *)&Property->Value->Data);

    if (Result == 0) {
      break;
    }

    Property = EFI_DEVICE_PATH_PROPERTY_FROM_LIST_ENTRY (
                 GetNextNode (&Node->Hdr.Properties, &Property->This)
                 );
  } while (TRUE);

  return Property;
}

// InternalCallProtocol
STATIC
VOID
InternalCallProtocol (
  VOID
  ) // sub_BB0
{
  EFI_STATUS Status;
  UINTN      NumberHandles;
  EFI_HANDLE *Buffer;
  UINTN      Index;
  VOID       *Interface;

  Buffer = NULL;
  Status = gBS->LocateHandleBuffer (
                  ByProtocol,
                  &mUnknownProtocolGuid,
                  NULL,
                  &NumberHandles,
                  &Buffer
                  );

  if (Status == EFI_SUCCESS) {
    for (Index = 0; Index < NumberHandles; ++Index) {
      Status = gBS->HandleProtocol (
                      Buffer[Index],
                      &mUnknownProtocolGuid,
                      &Interface
                      );

      if (Status == EFI_SUCCESS) {
        if (*(UINT32 *)((UINTN)Interface + sizeof (UINT32)) == 0) {
          (*(VOID (EFIAPI **)(VOID *))((UINTN)Interface + 232)) (Interface);
        }
      }
    }
  }

  if (Buffer != NULL) {
    gBS->FreePool ((VOID *)Buffer);
  }
}

// DppDbGetPropertyValueImpl
/** Locates a device property in the database and returns its value into Value.

  @param[in]      This        A pointer to the protocol instance.
  @param[in]      DevicePath  The device path of the device to get the property
                              of.
  @param[in]      Name        The Name of the requested property.
  @param[out]     Value       The Buffer allocated by the caller to return the
                              value of the property into.
  @param[in, out] Size        On input the size of the allocated Value Buffer.
                              On output the size required to fill the Buffer.

  @return                       The status of the operation is returned.
  @retval EFI_BUFFER_TOO_SMALL  The memory required to return the value exceeds
                                the size of the allocated Buffer.
                                The required size to complete the operation has
                                been returned into Size.
  @retval EFI_NOT_FOUND         The given device path does not have a property
                                with the specified Name.
  @retval EFI_SUCCESS           The operation completed successfully and the
                                Value Buffer has been filled.
**/
EFI_STATUS
EFIAPI
DppDbGetPropertyValue (
  IN     EFI_DEVICE_PATH_PROPERTY_DATABASE_PROTOCOL  *This,
  IN     EFI_DEVICE_PATH_PROTOCOL                    *DevicePath,
  IN     CHAR16                                      *Name,
  OUT    VOID                                        *Value, OPTIONAL
  IN OUT UINTN                                       *Size
  ) // sub_593
{
  EFI_STATUS                        Status;

  EFI_DEVICE_PATH_PROPERTY_DATABASE *Database;
  EFI_DEVICE_PATH_PROPERTY_NODE     *Node;
  EFI_DEVICE_PATH_PROPERTY          *Property;
  UINTN                             PropertySize;
  BOOLEAN                           BufferTooSmall;

  ASSERT (This != NULL);
  ASSERT (DevicePath != NULL);
  ASSERT (Name != NULL);
  ASSERT (Size != NULL);
  ASSERT ((((*Size > 0) ? 1 : 0) ^ ((Value == NULL) ? 1 : 0)) != 0);

  Database = PROPERTY_DATABASE_FROM_PROTOCOL (This);
  Node     = InternalGetPropertyNode (Database, DevicePath);

  Status = EFI_NOT_FOUND;

  if (Node != NULL) {
    Property = InternalGetProperty (Name, Node);

    Status = EFI_NOT_FOUND;

    if (Property != NULL) {
      PropertySize   = EFI_DEVICE_PATH_PROPERTY_VALUE_SIZE (Property);
      BufferTooSmall = (BOOLEAN)(PropertySize > *Size);
      *Size          = PropertySize;

      Status = EFI_BUFFER_TOO_SMALL;

      if (!BufferTooSmall) {
        EfiCopyMem (Value, (VOID *)&Property->Value->Data, PropertySize);

        Status = EFI_SUCCESS;
      }
    }
  }

  ASSERT_EFI_ERROR (Status);

  return Status;
}

// DppDbSetPropertyImpl
/** Sets the sepcified property of the given device path to the provided Value.

  @param[in] This        A pointer to the protocol instance.
  @param[in] DevicePath  The device path of the device to set the property of.
  @param[in] Name        The Name of the desired property.
  @param[in] Value       The Buffer holding the value to set the property to.
  @param[in] Size        The size of the Value Buffer.

  @return                       The status of the operation is returned.
  @retval EFI_OUT_OF_RESOURCES  The memory necessary to complete the operation
                                could not be allocated.
  @retval EFI_SUCCESS           The operation completed successfully and the
                                Value Buffer has been filled.
**/
EFI_STATUS
EFIAPI
DppDbSetProperty (
  IN EFI_DEVICE_PATH_PROPERTY_DATABASE_PROTOCOL  *This,
  IN EFI_DEVICE_PATH_PROTOCOL                    *DevicePath,
  IN CHAR16                                      *Name,
  IN VOID                                        *Value,
  IN UINTN                                       Size
  ) // sub_617
{
  EFI_STATUS                        Status;

  EFI_DEVICE_PATH_PROPERTY_DATABASE *Database;
  EFI_DEVICE_PATH_PROPERTY_NODE     *Node;
  UINTN                             DevicePathSize;
  EFI_DEVICE_PATH_PROPERTY          *Property;
  INTN                              Result;
  UINTN                             PropertyNameSize;
  UINTN                             PropertyDataSize;
  EFI_DEVICE_PATH_PROPERTY_DATA     *PropertyData;

  ASSERT (This != NULL);
  ASSERT (DevicePath != NULL);
  ASSERT (Name != NULL);
  ASSERT (Value != NULL);
  ASSERT (Size > 0);

  Database = PROPERTY_DATABASE_FROM_PROTOCOL (This);
  Node     = InternalGetPropertyNode (Database, DevicePath);

  if (Node == NULL) {
    DevicePathSize = EfiDevicePathSize (DevicePath);
    Node           = EfiLibAllocateZeroPool (sizeof (Node) + DevicePathSize);

    Status = EFI_OUT_OF_RESOURCES;

    if (Node == NULL) {
      goto Done;
    } else {
      Node->Hdr.Signature = EFI_DEVICE_PATH_PROPERTY_NODE_SIGNATURE;

      InitializeListHead (&Node->Hdr.Properties);

      EfiCopyMem (
        (VOID *)&Node->DevicePath,
        (VOID *)DevicePath,
        DevicePathSize
        );

      InsertTailList (&Database->Nodes, &Node->Hdr.This);

      Database->Modified = TRUE;
    }
  }

  Property = InternalGetProperty (Name, Node);

  if (Property != NULL) {
    if (Property->Value->Hdr.Size == Size) {
      Result = EfiCompareMem ((VOID *)&Property->Value->Data, Value, Size);

      if (Result == 0) {
        Status = EFI_SUCCESS;
        goto Done;
      }
    }

    RemoveEntryList (&Property->This);

    --Node->Hdr.NumberOfProperties;

    gBS->FreePool ((VOID *)Property->Name);
    gBS->FreePool ((VOID *)Property->Value);
    gBS->FreePool ((VOID *)Property);
  }

  Database->Modified = TRUE;
  Property           = EfiLibAllocateZeroPool (sizeof (Property));

  Status = EFI_OUT_OF_RESOURCES;

  if (Property != NULL) {
    PropertyNameSize   = (EfiStrSize (Name) + sizeof (PropertyData->Hdr));
    PropertyData       = EfiLibAllocateZeroPool (PropertyNameSize);
    Property->Name     = PropertyData;

    if (PropertyData != NULL) {
      PropertyDataSize = (Size + sizeof (PropertyData->Hdr));
      PropertyData     = EfiLibAllocateZeroPool (PropertyDataSize);
      Property->Value  = PropertyData;

      if (PropertyData != NULL) {
        Property->Signature = EFI_DEVICE_PATH_PROPERTY_SIGNATURE;

        EfiStrCpy ((CHAR16 *)&Property->Name->Data, Name);

        Property->Name->Hdr.Size = (UINT32)PropertyNameSize;

        EfiCopyMem ((VOID *)&Property->Value->Data, (VOID *)Value, Size);

        Property->Value->Hdr.Size = (UINT32)PropertyDataSize;

        InsertTailList (&Node->Hdr.Properties, &Property->This);

        Status = EFI_SUCCESS;

        ++Node->Hdr.NumberOfProperties;
      }
    }
  }

Done:
  ASSERT_EFI_ERROR (Status);

  return Status;
}

// DppDbRemovePropertyImpl
/** Removes the sepcified property from the given device path.

  @param[in] This        A pointer to the protocol instance.
  @param[in] DevicePath  The device path of the device to set the property of.
  @param[in] Name        The Name of the desired property.

  @return                The status of the operation is returned.
  @retval EFI_NOT_FOUND  The given device path does not have a property with
                         the specified Name.
  @retval EFI_SUCCESS    The operation completed successfully.
**/
EFI_STATUS
EFIAPI
DppDbRemoveProperty (
  IN EFI_DEVICE_PATH_PROPERTY_DATABASE_PROTOCOL  *This,
  IN EFI_DEVICE_PATH_PROTOCOL                    *DevicePath,
  IN CHAR16                                      *Name
  ) // sub_7FF
{
  EFI_STATUS                        Status;

  EFI_DEVICE_PATH_PROPERTY_DATABASE *Database;
  EFI_DEVICE_PATH_PROPERTY_NODE     *Node;
  EFI_DEVICE_PATH_PROPERTY          *Property;

  ASSERT (This != NULL);
  ASSERT (DevicePath != NULL);
  ASSERT (Name != NULL);

  Database = PROPERTY_DATABASE_FROM_PROTOCOL (This);
  Node     = InternalGetPropertyNode (Database, DevicePath);

  if (Node == NULL) {
    Status = EFI_NOT_FOUND;
  } else {
    Property = InternalGetProperty (Name, Node);

    Status = EFI_NOT_FOUND;

    if (Property != NULL) {
      Database->Modified = TRUE;

      RemoveEntryList (&Property->This);

      --Node->Hdr.NumberOfProperties;

      gBS->FreePool ((VOID *)Property);

      Status = EFI_SUCCESS;

      if (Node->Hdr.NumberOfProperties == 0) {
        RemoveEntryList (&Node->Hdr.This);

        gBS->FreePool ((VOID *)Node);
      }
    }
  }

  ASSERT_EFI_ERROR (Status);

  return Status;
}

// DppDbGetPropertyBufferImpl
/** Returns a Buffer of all device properties into Buffer.

  @param[in]      This    A pointer to the protocol instance.
  @param[out]     Buffer  The Buffer allocated by the caller to return the
                          property Buffer into.
  @param[in, out] Size    On input the size of the allocated Buffer.
                          On output the size required to fill the Buffer.

  @return                       The status of the operation is returned.
  @retval EFI_BUFFER_TOO_SMALL  The memory required to return the value exceeds
                                the size of the allocated Buffer.
                                The required size to complete the operation has
                                been returned into Size.
  @retval EFI_SUCCESS           The operation completed successfully.
**/
EFI_STATUS
EFIAPI
DppDbGetPropertyBuffer (
  IN     EFI_DEVICE_PATH_PROPERTY_DATABASE_PROTOCOL  *This,
  OUT    EFI_DEVICE_PATH_PROPERTY_BUFFER             *Buffer, OPTIONAL
  IN OUT UINTN                                       *Size
  ) // sub_893
{
  EFI_STATUS                           Status;

  EFI_LIST                             *Nodes;
  BOOLEAN                              Result;
  EFI_DEVICE_PATH_PROPERTY_NODE        *NodeWalker;
  UINTN                                BufferSize;
  EFI_DEVICE_PATH_PROPERTY             *Property;
  UINT32                               NumberOfNodes;
  EFI_DEVICE_PATH_PROPERTY_BUFFER_NODE *BufferNode;
  VOID                                 *BufferPtr;

  ASSERT (This != NULL);
  ASSERT (Buffer != NULL);
  ASSERT (Size != NULL);

  Nodes  = &(PROPERTY_DATABASE_FROM_PROTOCOL (This))->Nodes;
  Result = IsListEmpty (Nodes);

  if (Result) {
    *Size  = 0;
    Status = EFI_SUCCESS;
  } else {
    InternalCallProtocol ();

    NodeWalker    = PROPERTY_NODE_FROM_LIST_ENTRY (GetFirstNode (Nodes));
    Result        = IsNull (Nodes, &NodeWalker->Hdr.This);
    BufferSize    = sizeof (Buffer->Hdr);
    NumberOfNodes = 0;

    while (!Result) {
      Property = EFI_DEVICE_PATH_PROPERTY_FROM_LIST_ENTRY (
                   GetFirstNode (&NodeWalker->Hdr.Properties)
                   );

      Result = IsNull (&NodeWalker->Hdr.Properties, &Property->This);

      while (!Result) {
        BufferSize += EFI_DEVICE_PATH_PROPERTY_SIZE (Property);

        Property = EFI_DEVICE_PATH_PROPERTY_FROM_LIST_ENTRY (
                     GetNextNode (&NodeWalker->Hdr.Properties, &Property->This)
                     );

        Result = IsNull (&NodeWalker->Hdr.Properties, &Property->This);
      }

      NodeWalker = PROPERTY_NODE_FROM_LIST_ENTRY (
                     GetNextNode (Nodes, &NodeWalker->Hdr.This)
                     );

      Result      = IsNull (Nodes, &NodeWalker->Hdr.This);
      BufferSize += EFI_DEVICE_PATH_PROPERTY_NODE_SIZE (NodeWalker);
      ++NumberOfNodes;
    }

    Result = (BOOLEAN)(*Size < BufferSize);
    *Size  = BufferSize;
    Status = EFI_BUFFER_TOO_SMALL;

    if (!Result) {
      Buffer->Hdr.Size          = (UINT32)BufferSize;
      Buffer->Hdr.MustBe1       = 1;
      Buffer->Hdr.NumberOfNodes = NumberOfNodes;

      NodeWalker = PROPERTY_NODE_FROM_LIST_ENTRY (
                     GetFirstNode (Nodes)
                     );

      Result = IsNull (&NodeWalker->Hdr.This, &NodeWalker->Hdr.This);
      Status = EFI_SUCCESS;

      if (!Result) {
        BufferNode = &Buffer->Node;

        do {
          BufferSize = EfiDevicePathSize (&NodeWalker->DevicePath);

          EfiCopyMem (
            (VOID *)&BufferNode->DevicePath,
            (VOID *)&NodeWalker->DevicePath,
            BufferSize
            );

          BufferNode->Hdr.NumberOfProperties = (UINT32)NodeWalker->Hdr.NumberOfProperties;

          Property = EFI_DEVICE_PATH_PROPERTY_FROM_LIST_ENTRY (
                       GetFirstNode (&NodeWalker->Hdr.Properties)
                       );

          Result      = IsNull (&NodeWalker->Hdr.Properties, &Property->This);
          BufferSize += sizeof (BufferNode->Hdr);
          BufferPtr   = (VOID *)((UINTN)Buffer + BufferSize);

          while (!Result) {
            EfiCopyMem (
              BufferPtr,
              (VOID *)Property->Name,
              (UINTN)Property->Name->Hdr.Size
              );

            EfiCopyMem (
              (VOID *)((UINTN)BufferPtr + (UINTN)Property->Name->Hdr.Size),
              Property->Value,
              (UINTN)Property->Value->Hdr.Size
              );

            BufferPtr = (VOID *)(
                          (UINTN)BufferPtr
                            + Property->Name->Hdr.Size
                              + Property->Value->Hdr.Size
                          );

            BufferSize += EFI_DEVICE_PATH_PROPERTY_SIZE (Property);
            Property    = EFI_DEVICE_PATH_PROPERTY_FROM_LIST_ENTRY (
                            GetNextNode (
                              &NodeWalker->Hdr.Properties,
                              &Property->This
                              )
                            );

            Result = IsNull (&NodeWalker->Hdr.Properties, &Property->This);
          }

          BufferNode->Hdr.Size = (UINT32)BufferSize;
          BufferNode           = (EFI_DEVICE_PATH_PROPERTY_BUFFER_NODE *)(
                                    (UINTN)BufferNode + BufferSize
                                    );

          NodeWalker = PROPERTY_NODE_FROM_LIST_ENTRY (
                         GetNextNode (Nodes, &NodeWalker->Hdr.This)
                         );
        } while (!IsNull (&NodeWalker->Hdr.This, &NodeWalker->Hdr.This));
      }
    }
  }

  ASSERT_EFI_ERROR (Status);

  return Status;
}
