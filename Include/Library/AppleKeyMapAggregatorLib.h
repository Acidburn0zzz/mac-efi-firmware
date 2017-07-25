/** @file
  Copyright (C) 2005 - 2017, Apple Inc.  All rights reserved.<BR>

  This program and the accompanying materials have not been licensed.
  Neither is its usage, its redistribution, in source or binary form,
  licensed, nor implicitely or explicitely permitted, except when
  required by applicable law.

  Unless required by applicable law or agreed to in writing, software
  distributed is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
  OR CONDITIONS OF ANY KIND, either express or implied.
**/

#ifndef APPLE_KEY_MAP_AGGREGATOR_LIB_H_
#define APPLE_KEY_MAP_AGGREGATOR_LIB_H_

#include APPLE_PROTOCOL_CONSUMER (AppleKeyMapAggregator)

// KeyMapAggrLibGetAppleKeyStrokes
EFI_STATUS
KeyMapAggrLibGetAppleKeyStrokes (
  OUT APPLE_MODIFIER_MAP  *Modifiers,
  OUT UINTN               *NumberOfKeys,
  OUT APPLE_KEY           **Keys
  );

// KeyMapAggrLibGetModifierStrokes
APPLE_MODIFIER_MAP
KeyMapAggrLibGetModifierStrokes (
  VOID
  );

// mAppleKeyMapAggregator
extern APPLE_KEY_MAP_AGGREGATOR_PROTOCOL *mAppleKeyMapAggregator;

#endif // APPLE_KEY_MAP_AGGREGATOR_LIB_H_
