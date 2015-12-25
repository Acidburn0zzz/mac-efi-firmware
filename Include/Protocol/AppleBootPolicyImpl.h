/** @file
  Apple protocol to get a volume's bootable file.

  Copyright (C) 2005 - 2015 Apple Inc.  All rights reserved.<BR>

  This program and the accompanying materials have not been licensed.
  Neither is its usage, its redistribution, in source or binary form,
  licensed, nor implicitely or explicitely permitted, except when
  required by applicable law.

  Unless required by applicable law or agreed to in writing, software
  distributed is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
  OR CONDITIONS OF ANY KIND, either express or implied.
**/

#ifndef APPLE_BOOT_POLICY_IMPL_H_
#define APPLE_BOOT_POLICY_IMPL_H_

#include APPLE_PROTOCOL_PRODUCER (AppleBootPolicy)

// APPLE_BOOT_POLICY_PROTOCOL_REVISION
#define APPLE_BOOT_POLICY_PROTOCOL_REVISION  0x01

// BootPolicyGetBootFileImpl
/** Locates the bootable file of the given volume.  Prefered are the values blessed,
    though if unavailable, hard-coded names are being verified and used if existing.

  The blessed paths are to be determined by the HFS Driver via EFI_FILE_PROTOCOL.GetInfo().
  The related identifier definitions are to be found in AppleBless.h.

  @param[in]  Device        The Device's Handle to perform the search on.
  @param[out] BootFilePath  A pointer to the device path pointer to set to the file path of the boot file.

  @return                       The status of the operation is returned.
  @retval EFI_NOT_FOUND         A bootable file could not be found on the given volume.
  @retval EFI_OUT_OF_RESOURCES  The memory necessary to complete the operation could not be allocated.
  @retval EFI_SUCCESS           The operation completed successfully and the BootFilePath Buffer has been filled.
  @retval other                 The status of an operation used to complete this operation is returned.
**/
EFI_STATUS
EFIAPI
BootPolicyGetBootFileImpl (
  IN  EFI_HANDLE            Device,
  OUT FILEPATH_DEVICE_PATH  **BootFilePath
  );

#endif // APPLE_BOOT_POLICY_IMPL_H_
