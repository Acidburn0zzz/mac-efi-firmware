/** @file
  Copyright (C) 2005 - 2015, Apple Inc.  All rights reserved.<BR>

  This program and the accompanying materials have not been licensed.
  Neither is its usage, its redistribution, in source or binary form,
  licensed, nor implicitely or explicitely permitted, except when
  required by applicable law.

  Unless required by applicable law or agreed to in writing, software
  distributed is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
  OR CONDITIONS OF ANY KIND, either express or implied.
**/

#include <AppleEfi.h>

#include APPLE_GUID_DEFINITION (AppleOSLoaded)

#include <Library/AppleDriverLib.h>

#include "OSInfoImplInternal.h"

// OSInfoOSName
VOID
EFIAPI
OSInfoOSName (
  IN CHAR8  *OSName
  )
{
  ASSERT (OSName != NULL);

  return;
}

// OSInfoOSVendor
VOID
EFIAPI
OSInfoOSVendor (
  IN CHAR8  *OSVendor
  )
{
  INTN Result;

  ASSERT (OSVendor != NULL);

  Result = EfiAsciiStrCmp (OSVendor, OS_INFO_VENDOR_NAME);

  if (Result == 0) {
    EfiLibNamedEventSignal (&gAppleOSLoadedNamedEventGuid);
  }
}
