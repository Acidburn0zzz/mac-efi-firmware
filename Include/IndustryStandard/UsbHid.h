/** @file
  Copyright (C) 2015, CupertinoNet.  All rights reserved.<BR>

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  @par Specification Reference:
    - Universal Serial Bus HID Usage Tables 1.12
**/

#ifndef USB_HID_H_
#define USB_HID_H_

// USB HID Generic

// USB_HID_PAGE_USAGE
#define USB_HID_USAGE(UsageId, PageId) (((PageId) << 16) | (UsageId))

// USB_HID_PAGES
enum {
  UsbHidUndefined                       = 0x00,
  UsbHidGenericDesktopPage              = 0x01,
  UsbHidSimulationControlsPage          = 0x02,
  UsbHidVrControlsPage                  = 0x03,
  UsbHidSportControlsPage               = 0x04,
  UsbHidGameControlsPage                = 0x05,
  UsbHidGenericDeviceControlsPage       = 0x06,
  UsbHidKeyboardKeypadPage              = 0x07,
  UsbHidLedPage                         = 0x08,
  UsbHidButtonPage                      = 0x09,
  UsbHidOrdinalPage                     = 0x0A,
  UsbHidTelephonyDevicePage             = 0x0B,
  UsbHidConsumerPage                    = 0x0C,
  UsbHidDigitizers                      = 0x0D,
    // = 0x0E = Reserved
  UsbHidPidPage                         = 0x0F,
  UsbHidUnicodePage                     = 0x10,
    // = 0x11 - = 0x13 = Reserved
  UsbHidAlphaNumericDisplayPage         = 0x14,
    // = 0x15 - = 0x3F = Reserved
  UsbHidMedicalInstrumentPage           = 0x40,
    // = 0x41 - = 0x7F = Reserved
  UsbHidMonitorPage1                    = 0x80,
  UsbHidMonitorPage2                    = 0x81,
  UsbHidMonitorPage3                    = 0x82,
  UsbHidMonitorPage4                    = 0x83,
  UsbHidPowerPage1                      = 0x84,
  UsbHidPowerPage2                      = 0x85,
  UsbHidPowerPage3                      = 0x86,
  UsbHidPowerPage4                      = 0x87,
    // = 0x88 - = 0x8B = Reserved
  UsbHidBarCodeScannerPage              = 0x8C,
  UsbHidScalePage                       = 0x8D,
  UsbHidMagneticStripeReadingDevicePage = 0x8E,
  UsbHidReservedPointOfSalePage         = 0x8F,
  UsbHidCameraControlPage               = 0x90,
  UsbHidArcadePage                      = 0x91
    // = 0x92 - = 0xFEFF = Reserved
    // = 0xFF00 - = 0xFFFF = Vendor defined
};

// USB_HID_PAGE_ID
typedef UINT16 USB_HID_PAGE_ID;

// USB_HID_USAGE_ID
typedef UINT16 USB_HID_USAGE_ID;

// USB_HID_USAGE
typedef UINT32 USB_HID_USAGE;

// USB HID Consumer

#define USB_HID_CONSUMER_USAGE(UsageId)  \
  USB_HID_USAGE (UsbHidConsumerPage, (UsageId))

// USB HID Keyboard/Keypad

// USB_HID_KEYBOARD_KEY_PAD
#define USB_HID_KB_KP_USAGE(UsageId)  \
  USB_HID_USAGE (UsbHidKeyboardKeypadPage, (UsageId))

// USB HID Modifier Map
/// @{
#define USB_HID_KB_KP_MODIFIER_LEFT_CONTROL   BIT (0)
#define USB_HID_KB_KP_MODIFIER_LEFT_SHIFT     BIT (1)
#define USB_HID_KB_KP_MODIFIER_LEFT_ALT       BIT (2)
#define USB_HID_KB_KP_MODIFIER_LEFT_GUI       BIT (3)
#define USB_HID_KB_KP_MODIFIER_RIGHT_CONTROL  BIT (4)
#define USB_HID_KB_KP_MODIFIER_RIGHT_SHIFT    BIT (5)
#define USB_HID_KB_KP_MODIFIER_RIGHT_ALT      BIT (6)
#define USB_HID_KB_KP_MODIFIER_RIGHT_GUI      BIT (7)
/// @}

// Shortcuts for multiple modifers
/// @{
#define USB_HID_KB_KP_MODIFIERS_CONTROL  \
  (USB_HID_KB_KP_MODIFIER_LEFT_CONTROL | USB_HID_KB_KP_MODIFIER_RIGHT_CONTROL)

#define USB_HID_KB_KP_MODIFIERS_SHIFT  \
  (USB_HID_KB_KP_MODIFIER_LEFT_SHIFT | USB_HID_KB_KP_MODIFIER_RIGHT_SHIFT)

#define USB_HID_KB_KP_MODIFIERS_ALT  \
  (USB_HID_KB_KP_MODIFIER_LEFT_ALT | USB_HID_KB_KP_MODIFIER_RIGHT_ALT)

#define USB_HID_KB_KP_MODIFIERS_GUI  \
  (USB_HID_KB_KP_MODIFIER_LEFT_GUI | USB_HID_KB_KP_MODIFIER_RIGHT_GUI)
/// @}

// USB_HID_MODIFIERS
typedef UINT8 USB_HID_KB_MODIFIER_MAP;

// USBKBD_VALID_KEYCODE
#define USB_HID_KB_KP_VALID_KEYCODE(Key) ((UINT8)(Key) > 3)

// USB_HID_KB_USAGE_ID
enum {
  UsbHidUsageIdKbKpKeyReserved             = 0x00,
  UsbHidUsageIdKbKpKeyErrorRollOver        = 0x01,
  UsbHidUsageIdKbKpKeyPostFail             = 0x02,
  UsbHidUsageIdKbKpKeyErrorUndefined       = 0x03,
  UsbHidUsageIdKbKpKeyA                    = 0x04,
  UsbHidUsageIdKbKpKeyB                    = 0x05,
  UsbHidUsageIdKbKpKeyC                    = 0x06,
  UsbHidUsageIdKbKpKeyD                    = 0x07,
  UsbHidUsageIdKbKpKeyE                    = 0x08,
  UsbHidUsageIdKbKpKeyF                    = 0x09,
  UsbHidUsageIdKbKpKeyG                    = 0x0A,
  UsbHidUsageIdKbKpKeyH                    = 0x0B,
  UsbHidUsageIdKbKpKeyI                    = 0x0C,
  UsbHidUsageIdKbKpKeyJ                    = 0x0D,
  UsbHidUsageIdKbKpKeyK                    = 0x0E,
  UsbHidUsageIdKbKpKeyL                    = 0x0F,
  UsbHidUsageIdKbKpKeyM                    = 0x10,
  UsbHidUsageIdKbKpKeyN                    = 0x11,
  UsbHidUsageIdKbKpKeyO                    = 0x12,
  UsbHidUsageIdKbKpKeyP                    = 0x13,
  UsbHidUsageIdKbKpKeyQ                    = 0x14,
  UsbHidUsageIdKbKpKeyR                    = 0x15,
  UsbHidUsageIdKbKpKeyS                    = 0x16,
  UsbHidUsageIdKbKpKeyT                    = 0x17,
  UsbHidUsageIdKbKpKeyU                    = 0x18,
  UsbHidUsageIdKbKpKeyV                    = 0x19,
  UsbHidUsageIdKbKpKeyW                    = 0x1A,
  UsbHidUsageIdKbKpKeyX                    = 0x1B,
  UsbHidUsageIdKbKpKeyY                    = 0x1C,
  UsbHidUsageIdKbKpKeyZ                    = 0x1D,
  UsbHidUsageIdKbKpKeyOne                  = 0x1E,
  UsbHidUsageIdKbKpKeyTwo                  = 0x1F,
  UsbHidUsageIdKbKpKeyThree                = 0x20,
  UsbHidUsageIdKbKpKeyFour                 = 0x21,
  UsbHidUsageIdKbKpKeyFive                 = 0x22,
  UsbHidUsageIdKbKpKeySix                  = 0x23,
  UsbHidUsageIdKbKpKeySeven                = 0x24,
  UsbHidUsageIdKbKpKeyEight                = 0x25,
  UsbHidUsageIdKbKpKeyNine                 = 0x26,
  UsbHidUsageIdKbKpKeyZero                 = 0x27,
  UsbHidUsageIdKbKpKeyEnter                = 0x28,
  UsbHidUsageIdKbKpKeyEsc                  = 0x29,
  UsbHidUsageIdKbKpKeyBackSpace            = 0x2A,
  UsbHidUsageIdKbKpKeyTab                  = 0x2B,
  UsbHidUsageIdKbKpKeySpaceBar             = 0x2C,
  UsbHidUsageIdKbKpKeyMinus                = 0x2D,
  UsbHidUsageIdKbKpKeyEquals               = 0x2E,
  UsbHidUsageIdKbKpKeyLeftBracket          = 0x2F,
  UsbHidUsageIdKbKpKeyRightBracket         = 0x30,
  UsbHidUsageIdKbKpKeyBackslash            = 0x31,
  UsbHidUsageIdKbKpKeyNonUsHash            = 0x32,
  UsbHidUsageIdKbKpKeySemicolon            = 0x33,
  UsbHidUsageIdKbKpKeyQuotation            = 0x34,
  UsbHidUsageIdKbKpKeyAcute                = 0x35,
  UsbHidUsageIdKbKpKeyComma                = 0x36,
  UsbHidUsageIdKbKpKeyPeriod               = 0x37,
  UsbHidUsageIdKbKpKeySlash                = 0x38,
  UsbHidUsageIdKbKpKeyCLock                = 0x39,
  UsbHidUsageIdKbKpKeyF1                   = 0x3A,
  UsbHidUsageIdKbKpKeyF2                   = 0x3B,
  UsbHidUsageIdKbKpKeyF3                   = 0x3C,
  UsbHidUsageIdKbKpKeyF4                   = 0x3D,
  UsbHidUsageIdKbKpKeyF5                   = 0x3E,
  UsbHidUsageIdKbKpKeyF6                   = 0x3F,
  UsbHidUsageIdKbKpKeyF7                   = 0x40,
  UsbHidUsageIdKbKpKeyF8                   = 0x41,
  UsbHidUsageIdKbKpKeyF9                   = 0x42,
  UsbHidUsageIdKbKpKeyF10                  = 0x43,
  UsbHidUsageIdKbKpKeyF11                  = 0x44,
  UsbHidUsageIdKbKpKeyF12                  = 0x45,
  UsbHidUsageIdKbKpKeyPrint                = 0x46,
  UsbHidUsageIdKbKpKeySLock                = 0x47,
  UsbHidUsageIdKbKpKeyPause                = 0x48,
  UsbHidUsageIdKbKpKeyIns                  = 0x49,
  UsbHidUsageIdKbKpKeyHome                 = 0x4A,
  UsbHidUsageIdKbKpKeyPgUp                 = 0x4B,
  UsbHidUsageIdKbKpKeyDel                  = 0x4C,
  UsbHidUsageIdKbKpKeyEnd                  = 0x4D,
  UsbHidUsageIdKbKpKeyPgDn                 = 0x4E,
  UsbHidUsageIdKbKpKeyRightArrow           = 0x4F,
  UsbHidUsageIdKbKpKeyLeftArrow            = 0x50,
  UsbHidUsageIdKbKpKeyDownArrow            = 0x51,
  UsbHidUsageIdKbKpKeyUpArrow              = 0x52,
  UsbHidUsageIdKbKpPadKeyNLck              = 0x53,
  UsbHidUsageIdKbKpPadKeySlash             = 0x54,
  UsbHidUsageIdKbKpPadKeyAsterisk          = 0x55,
  UsbHidUsageIdKbKpPadKeyMinus             = 0x56,
  UsbHidUsageIdKbKpPadKeyPlus              = 0x57,
  UsbHidUsageIdKbKpPadKeyEnter             = 0x58,
  UsbHidUsageIdKbKpPadKeyOne               = 0x59,
  UsbHidUsageIdKbKpPadKeyTwo               = 0x5A,
  UsbHidUsageIdKbKpPadKeyThree             = 0x5B,
  UsbHidUsageIdKbKpPadKeyFour              = 0x5C,
  UsbHidUsageIdKbKpPadKeyFive              = 0x5D,
  UsbHidUsageIdKbKpPadKeySix               = 0x5E,
  UsbHidUsageIdKbKpPadKeySeven             = 0x5F,
  UsbHidUsageIdKbKpPadKeyEight             = 0x60,
  UsbHidUsageIdKbKpPadKeyNine              = 0x61,
  UsbHidUsageIdKbKpPadKeyIns               = 0x62,
  UsbHidUsageIdKbKpPadKeyDel               = 0x63,
  UsbHidUsageIdKbKpPadKeyNonUsBackslash    = 0x64,
  UsbHidUsageIdKbKpPadKeyApplication       = 0x65,
  UsbHidUsageIdKbKpPadKeyPower             = 0x66,
  UsbHidUsageIdKbKpPadKeyEquals            = 0x67,
  UsbHidUsageIdKbKpKeyF13                  = 0x68,
  UsbHidUsageIdKbKpKeyF14                  = 0x69,
  UsbHidUsageIdKbKpKeyF15                  = 0x6A,
  UsbHidUsageIdKbKpKeyF16                  = 0x6B,
  UsbHidUsageIdKbKpKeyF17                  = 0x6C,
  UsbHidUsageIdKbKpKeyF18                  = 0x6D,
  UsbHidUsageIdKbKpKeyF19                  = 0x6E,
  UsbHidUsageIdKbKpKeyF20                  = 0x6F,
  UsbHidUsageIdKbKpKeyF21                  = 0x70,
  UsbHidUsageIdKbKpKeyF22                  = 0x71,
  UsbHidUsageIdKbKpKeyF23                  = 0x72,
  UsbHidUsageIdKbKpKeyF24                  = 0x73,
  UsbHidUsageIdKbKpKeyExecute              = 0x74,
  UsbHidUsageIdKbKpKeyHelp                 = 0x75,
  UsbHidUsageIdKbKpKeyMenu                 = 0x76,
  UsbHidUsageIdKbKpKeySelect               = 0x77,
  UsbHidUsageIdKbKpKeyStop                 = 0x78,
  UsbHidUsageIdKbKpKeyAgain                = 0x79,
  UsbHidUsageIdKbKpKeyUndo                 = 0x7A,
  UsbHidUsageIdKbKpKeyCut                  = 0x7B,
  UsbHidUsageIdKbKpKeyCopy                 = 0x7C,
  UsbHidUsageIdKbKpKeyPaste                = 0x7D,
  UsbHidUsageIdKbKpKeyFind                 = 0x7E,
  UsbHidUsageIdKbKpKeyMute                 = 0x7F,
  UsbHidUsageIdKbKpKeyVolumeUp             = 0x80,
  UsbHidUsageIdKbKpKeyVolumeDown           = 0x81,
  UsbHidUsageIdKbKpLockKeyCLock            = 0x82,
  UsbHidUsageIdKbKpLockKeyNLock            = 0x83,
  UsbHidUsageIdKbKpLockKeySLock            = 0x84,
  UsbHidUsageIdKbKpPadKeyComma             = 0x85,
  UsbHidUsageIdKbKpPadKeyEqualSign         = 0x86,
  UsbHidUsageIdKbKpKeyInternational1       = 0x87,
  UsbHidUsageIdKbKpKeyInternational2       = 0x88,
  UsbHidUsageIdKbKpKeyInternational3       = 0x89,
  UsbHidUsageIdKbKpKeyInternational4       = 0x8A,
  UsbHidUsageIdKbKpKeyInternational5       = 0x8B,
  UsbHidUsageIdKbKpKeyInternational6       = 0x8C,
  UsbHidUsageIdKbKpKeyInternational7       = 0x8D,
  UsbHidUsageIdKbKpKeyInternational8       = 0x8E,
  UsbHidUsageIdKbKpKeyInternational9       = 0x8F,
  UsbHidUsageIdKbKpKeyLang1                = 0x90,
  UsbHidUsageIdKbKpKeyLang2                = 0x91,
  UsbHidUsageIdKbKpKeyLang3                = 0x92,
  UsbHidUsageIdKbKpKeyLang4                = 0x93,
  UsbHidUsageIdKbKpKeyLang5                = 0x94,
  UsbHidUsageIdKbKpKeyLang6                = 0x95,
  UsbHidUsageIdKbKpKeyLang7                = 0x96,
  UsbHidUsageIdKbKpKeyLang8                = 0x97,
  UsbHidUsageIdKbKpKeyLang9                = 0x98,
  UsbHidUsageIdKbKpKeyAlternateErase       = 0x99,
  UsbHidUsageIdKbKpKeySysReq               = 0x9A,
  UsbHidUsageIdKbKpKeyCancel               = 0x9B,
  UsbHidUsageIdKbKpKeyClear                = 0x9C,
  UsbHidUsageIdKbKpKeyPrior                = 0x9D,
  UsbHidUsageIdKbKpKeyReturn               = 0x9E,
  UsbHidUsageIdKbKpKeySeparator            = 0x9F,
  UsbHidUsageIdKbKpKeyOut                  = 0xA0,
  UsbHidUsageIdKbKpKeyOper                 = 0xA1,
  UsbHidUsageIdKbKpKeyClearAgain           = 0xA2,
  UsbHidUsageIdKbKpKeyCrSel                = 0xA3,
  UsbHidUsageIdKbKpKeyExSel                = 0xA4,
    // A5 - AF = Reserved
  UsbHidUsageIdKbKpPadKeyDoubleZero        = 0xB0,
  UsbHidUsageIdKbKpKeyTrippleZero          = 0xB1,
  UsbHidUsageIdKbKpKeyThousandsSeparator   = 0xB2,
  UsbHidUsageIdKbKpKeyDecimalSeparator     = 0xB3,
  UsbHidUsageIdKbKpKeyCurrencyUnit         = 0xB4,
  UsbHidUsageIdKbKpKeyCurrencySubUnit      = 0xB5,
  UsbHidUsageIdKbKpPadKeyLeftBracket       = 0xB6,
  UsbHidUsageIdKbKpPadKeyRightBracket      = 0xB7,
  UsbHidUsageIdKbKpPadKeyCurlyLeftBracket  = 0xB8,
  UsbHidUsageIdKbKpPadKeyCurlyRightBracket = 0xB9,
  UsbHidUsageIdKbKpPadKeyTab               = 0xBA,
  UsbHidUsageIdKbKpPadKeyBackspace         = 0xBB,
  UsbHidUsageIdKbKpPadKeyA                 = 0xBC,
  UsbHidUsageIdKbKpPadKeyB                 = 0xBD,
  UsbHidUsageIdKbKpPadKeyC                 = 0xBE,
  UsbHidUsageIdKbKpPadKeyD                 = 0xBF,
  UsbHidUsageIdKbKpPadKeyE                 = 0xC0,
  UsbHidUsageIdKbKpPadKeyF                 = 0xC1,
  UsbHidUsageIdKbKpPadKeyXor               = 0xC2,
  UsbHidUsageIdKbKpPadKeyCaret             = 0xC3,
  UsbHidUsageIdKbKpPadKeyPercent           = 0xC4,
  UsbHidUsageIdKbKpPadKeyLeftAngleBracket  = 0xC5,
  UsbHidUsageIdKbKpPadKeyRightAngleBracket = 0xC6,
  UsbHidUsageIdKbKpPadKeyBitwiseAnd        = 0xC7,
  UsbHidUsageIdKbKpPadKeyLogicalAnd        = 0xC8,
  UsbHidUsageIdKbKpPadKeyBitwiseOr         = 0xC9,
  UsbHidUsageIdKbKpPadKeyLogicalOr         = 0xCA,
  UsbHidUsageIdKbKpPadKeyColon             = 0xCB,
  UsbHidUsageIdKbKpPadKeyHash              = 0xCC,
  UsbHidUsageIdKbKpPadKeySpace             = 0xCD,
  UsbHidUsageIdKbKpPadKeyAt                = 0xCE,
  UsbHidUsageIdKbKpPadKeyExclamationMark   = 0xCF,
  UsbHidUsageIdKbKpPadKeyMemoryStore       = 0xD0,
  UsbHidUsageIdKbKpPadKeyMemoryRecall      = 0xD1,
  UsbHidUsageIdKbKpPadKeyMemoryClear       = 0xD2,
  UsbHidUsageIdKbKpPadKeyMemoryAdd         = 0xD3,
  UsbHidUsageIdKbKpPadKeyMemorySubtract    = 0xD4,
  UsbHidUsageIdKbKpPadKeyMemoryMultiply    = 0xD5,
  UsbHidUsageIdKbKpPadKeyMemoryDivide      = 0xD6,
  UsbHidUsageIdKbKpPadKeySign              = 0xD7,
  UsbHidUsageIdKbKpPadKeyClear             = 0xD8,
  UsbHidUsageIdKbKpPadKeyClearEntry        = 0xD9,
  UsbHidUsageIdKbKpPadKeyBinary            = 0xDA,
  UsbHidUsageIdKbKpPadKeyOctal             = 0xDB,
  UsbHidUsageIdKbKpPadKeyDecimal           = 0xDC,
  UsbHidUsageIdKbKpPadKeyHexadecimal       = 0xDD,
    // DE - DF = Reserved
  UsbHidUsageIdKbKpModifierKeyLeftControl  = 0xE0,
  UsbHidUsageIdKbKpModifierKeyLeftShift    = 0xE1,
  UsbHidUsageIdKbKpModifierKeyLeftAlt      = 0xE2,
  UsbHidUsageIdKbKpModifierKeyLeftGui      = 0xE3,
  UsbHidUsageIdKbKpModifierKeyRightControl = 0xE4,
  UsbHidUsageIdKbKpModifierKeyRightShift   = 0xE5,
  UsbHidUsageIdKbKpModifierKeyRightAlt     = 0xE6,
  UsbHidUsageIdKbKpModifierKeyRightGui     = 0xE7
    // E8 - FFFF = Reserved
};

// USB_HID_KB_USAGE
enum {
  UsbHidUsageKbKpKeyA                    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyA),
  UsbHidUsageKbKpKeyB                    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyB),
  UsbHidUsageKbKpKeyC                    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyC),
  UsbHidUsageKbKpKeyD                    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyD),
  UsbHidUsageKbKpKeyE                    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyE),
  UsbHidUsageKbKpKeyF                    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyF),
  UsbHidUsageKbKpKeyG                    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyG),
  UsbHidUsageKbKpKeyH                    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyH),
  UsbHidUsageKbKpKeyI                    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyI),
  UsbHidUsageKbKpKeyJ                    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyJ),
  UsbHidUsageKbKpKeyK                    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyK),
  UsbHidUsageKbKpKeyL                    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyL),
  UsbHidUsageKbKpKeyM                    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyM),
  UsbHidUsageKbKpKeyN                    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyN),
  UsbHidUsageKbKpKeyO                    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyO),
  UsbHidUsageKbKpKeyP                    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyP),
  UsbHidUsageKbKpKeyQ                    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyQ),
  UsbHidUsageKbKpKeyR                    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyR),
  UsbHidUsageKbKpKeyS                    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyS),
  UsbHidUsageKbKpKeyT                    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyT),
  UsbHidUsageKbKpKeyU                    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyU),
  UsbHidUsageKbKpKeyV                    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyV),
  UsbHidUsageKbKpKeyW                    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyW),
  UsbHidUsageKbKpKeyX                    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyX),
  UsbHidUsageKbKpKeyY                    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyY),
  UsbHidUsageKbKpKeyZ                    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyZ),
  UsbHidUsageKbKpKeyOne                  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyOne),
  UsbHidUsageKbKpKeyTwo                  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyTwo),
  UsbHidUsageKbKpKeyThree                = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyThree),
  UsbHidUsageKbKpKeyFour                 = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyFour),
  UsbHidUsageKbKpKeyFive                 = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyFive),
  UsbHidUsageKbKpKeySix                  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeySix),
  UsbHidUsageKbKpKeySeven                = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeySeven),
  UsbHidUsageKbKpKeyEight                = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyEight),
  UsbHidUsageKbKpKeyNine                 = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyNine),
  UsbHidUsageKbKpKeyZero                 = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyZero),
  UsbHidUsageKbKpKeyEnter                = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyEnter),
  UsbHidUsageKbKpKeyEscape               = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyEsc),
  UsbHidUsageKbKpKeyBackSpace            = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyBackSpace),
  UsbHidUsageKbKpKeyTab                  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyTab),
  UsbHidUsageKbKpKeySpaceBar             = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeySpaceBar),
  UsbHidUsageKbKpKeyMinus                = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyMinus),
  UsbHidUsageKbKpKeyEquals               = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyEquals),
  UsbHidUsageKbKpKeyLeftBracket          = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyLeftBracket),
  UsbHidUsageKbKpKeyRightBracket         = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyRightBracket),
  UsbHidUsageKbKpKeyBackslash            = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyBackslash),
  UsbHidUsageKbKpKeyNonUsHash            = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyNonUsHash),
  UsbHidUsageKbKpKeySemicolon            = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeySemicolon),
  UsbHidUsageKbKpKeyQuotation            = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyQuotation),
  UsbHidUsageKbKpKeyAcute                = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyAcute),
  UsbHidUsageKbKpKeyComma                = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyComma),
  UsbHidUsageKbKpKeyPeriod               = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyPeriod),
  UsbHidUsageKbKpKeySlash                = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeySlash),
  UsbHidUsageKbKpKeyCLock                = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyCLock),
  UsbHidUsageKbKpKeyF1                   = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyF1),
  UsbHidUsageKbKpKeyF2                   = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyF2),
  UsbHidUsageKbKpKeyF3                   = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyF3),
  UsbHidUsageKbKpKeyF4                   = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyF4),
  UsbHidUsageKbKpKeyF5                   = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyF5),
  UsbHidUsageKbKpKeyF6                   = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyF6),
  UsbHidUsageKbKpKeyF7                   = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyF7),
  UsbHidUsageKbKpKeyF8                   = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyF8),
  UsbHidUsageKbKpKeyF9                   = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyF9),
  UsbHidUsageKbKpKeyF10                  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyF10),
  UsbHidUsageKbKpKeyF11                  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyF11),
  UsbHidUsageKbKpKeyF12                  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyF12),
  UsbHidUsageKbKpKeyPrint                = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyPrint),
  UsbHidUsageKbKpKeySLock                = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeySLock),
  UsbHidUsageKbKpKeyPause                = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyPause),
  UsbHidUsageKbKpKeyIns                  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyIns),
  UsbHidUsageKbKpKeyHome                 = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyHome),
  UsbHidUsageKbKpKeyPgUp                 = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyPgUp),
  UsbHidUsageKbKpKeyDel                  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyDel),
  UsbHidUsageKbKpKeyEnd                  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyEnd),
  UsbHidUsageKbKpKeyPgDn                 = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyPgDn),
  UsbHidUsageKbKpKeyRightArrow           = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyRightArrow),
  UsbHidUsageKbKpKeyLeftArrow            = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyLeftArrow),
  UsbHidUsageKbKpKeyDownArrow            = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyDownArrow),
  UsbHidUsageKbKpKeyUpArrow              = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyUpArrow),
  UsbHidUsageKbKpPadKeyNLck              = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyNLck),
  UsbHidUsageKbKpPadKeySlash             = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeySlash),
  UsbHidUsageKbKpPadKeyAsterisk          = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyAsterisk),
  UsbHidUsageKbKpPadKeyMinus             = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyMinus),
  UsbHidUsageKbKpPadKeyPlus              = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyPlus),
  UsbHidUsageKbKpPadKeyEnter             = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyEnter),
  UsbHidUsageKbKpPadKeyOne               = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyOne),
  UsbHidUsageKbKpPadKeyTwo               = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyTwo),
  UsbHidUsageKbKpPadKeyThree             = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyThree),
  UsbHidUsageKbKpPadKeyFour              = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyFour),
  UsbHidUsageKbKpPadKeyFive              = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyFive),
  UsbHidUsageKbKpPadKeySix               = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeySix),
  UsbHidUsageKbKpPadKeySeven             = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeySeven),
  UsbHidUsageKbKpPadKeyEight             = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyEight),
  UsbHidUsageKbKpPadKeyNine              = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyNine),
  UsbHidUsageKbKpPadKeyIns               = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyIns),
  UsbHidUsageKbKpPadKeyDel               = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyDel),
  UsbHidUsageKbKpPadKeyNonUsBackslash    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyNonUsBackslash),
  UsbHidUsageKbKpPadKeyApplication       = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyApplication),
  UsbHidUsageKbKpPadKeyPower             = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyPower),
  UsbHidUsageKbKpPadKeyEquals            = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyEquals),
  UsbHidUsageKbKpKeyF13                  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyF13),
  UsbHidUsageKbKpKeyF14                  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyF14),
  UsbHidUsageKbKpKeyF15                  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyF15),
  UsbHidUsageKbKpKeyF16                  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyF16),
  UsbHidUsageKbKpKeyF17                  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyF17),
  UsbHidUsageKbKpKeyF18                  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyF18),
  UsbHidUsageKbKpKeyF19                  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyF19),
  UsbHidUsageKbKpKeyF20                  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyF20),
  UsbHidUsageKbKpKeyF21                  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyF21),
  UsbHidUsageKbKpKeyF22                  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyF22),
  UsbHidUsageKbKpKeyF23                  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyF23),
  UsbHidUsageKbKpKeyF24                  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyF24),
  UsbHidUsageKbKpKeyExecute              = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyExecute),
  UsbHidUsageKbKpKeyHelp                 = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyHelp),
  UsbHidUsageKbKpKeyMenu                 = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyMenu),
  UsbHidUsageKbKpKeySelect               = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeySelect),
  UsbHidUsageKbKpKeyStop                 = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyStop),
  UsbHidUsageKbKpKeyAgain                = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyAgain),
  UsbHidUsageKbKpKeyUndo                 = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyUndo),
  UsbHidUsageKbKpKeyCut                  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyCut),
  UsbHidUsageKbKpKeyCopy                 = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyCopy),
  UsbHidUsageKbKpKeyPaste                = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyPaste),
  UsbHidUsageKbKpKeyFind                 = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyFind),
  UsbHidUsageKbKpKeyMute                 = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyMute),
  UsbHidUsageKbKpKeyVolumeUp             = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyVolumeUp),
  UsbHidUsageKbKpKeyVolumeDown           = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyVolumeDown),
  UsbHidUsageKbKpLockKeyCLock            = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpLockKeyCLock),
  UsbHidUsageKbKpLockKeyNLock            = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpLockKeyNLock),
  UsbHidUsageKbKpLockKeySLock            = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpLockKeySLock),
  UsbHidUsageKbKpPadKeyComma             = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyComma),
  UsbHidUsageKbKpPadKeyEqualSign         = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyEqualSign),
  UsbHidUsageKbKpKeyInternational1       = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyInternational1),
  UsbHidUsageKbKpKeyInternational2       = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyInternational2),
  UsbHidUsageKbKpKeyInternational3       = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyInternational3),
  UsbHidUsageKbKpKeyInternational4       = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyInternational4),
  UsbHidUsageKbKpKeyInternational5       = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyInternational5),
  UsbHidUsageKbKpKeyInternational6       = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyInternational6),
  UsbHidUsageKbKpKeyInternational7       = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyInternational7),
  UsbHidUsageKbKpKeyInternational8       = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyInternational8),
  UsbHidUsageKbKpKeyInternational9       = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyInternational9),
  UsbHidUsageKbKpKeyLang1                = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyLang1),
  UsbHidUsageKbKpKeyLang2                = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyLang2),
  UsbHidUsageKbKpKeyLang3                = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyLang3),
  UsbHidUsageKbKpKeyLang4                = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyLang4),
  UsbHidUsageKbKpKeyLang5                = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyLang5),
  UsbHidUsageKbKpKeyLang6                = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyLang6),
  UsbHidUsageKbKpKeyLang7                = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyLang7),
  UsbHidUsageKbKpKeyLang8                = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyLang8),
  UsbHidUsageKbKpKeyLang9                = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyLang9),
  UsbHidUsageKbKpKeyAlternateErase       = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyAlternateErase),
  UsbHidUsageKbKpKeySysReq               = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeySysReq),
  UsbHidUsageKbKpKeyCancel               = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyCancel),
  UsbHidUsageKbKpKeyClear                = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyClear),
  UsbHidUsageKbKpKeyPrior                = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyPrior),
  UsbHidUsageKbKpKeyReturn               = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyReturn),
  UsbHidUsageKbKpKeySeparator            = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeySeparator),
  UsbHidUsageKbKpKeyOut                  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyOut),
  UsbHidUsageKbKpKeyOper                 = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyOper),
  UsbHidUsageKbKpKeyClearAgain           = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyClearAgain),
  UsbHidUsageKbKpKeyCrSel                = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyCrSel),
  UsbHidUsageKbKpKeyExSel                = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyExSel),
  UsbHidUsageKbKpPadKeyDoubleZero        = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyDoubleZero),
  UsbHidUsageKbKpKeyTrippleZero          = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyTrippleZero),
  UsbHidUsageKbKpKeyThousandsSeparator   = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyThousandsSeparator),
  UsbHidUsageKbKpKeyDecimalSeparator     = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyDecimalSeparator),
  UsbHidUsageKbKpKeyCurrencyUnit         = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyCurrencyUnit),
  UsbHidUsageKbKpKeyCurrencySubUnit      = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpKeyCurrencySubUnit),
  UsbHidUsageKbKpPadKeyLeftBracket       = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyLeftBracket),
  UsbHidUsageKbKpPadKeyRightBracket      = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyRightBracket),
  UsbHidUsageKbKpPadKeyCurlyLeftBracket  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyCurlyLeftBracket),
  UsbHidUsageKbKpPadKeyCurlyRightBracket = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyCurlyRightBracket),
  UsbHidUsageKbKpPadKeyTab               = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyTab),
  UsbHidUsageKbKpPadKeyBackspace         = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyBackspace),
  UsbHidUsageKbKpPadKeyA                 = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyA),
  UsbHidUsageKbKpPadKeyB                 = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyB),
  UsbHidUsageKbKpPadKeyC                 = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyC),
  UsbHidUsageKbKpPadKeyD                 = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyD),
  UsbHidUsageKbKpPadKeyE                 = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyE),
  UsbHidUsageKbKpPadKeyF                 = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyF),
  UsbHidUsageKbKpPadKeyXor               = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyXor),
  UsbHidUsageKbKpPadKeyCaret             = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyCaret),
  UsbHidUsageKbKpPadKeyPercent           = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyPercent),
  UsbHidUsageKbKpPadKeyLeftAngleBracket  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyLeftAngleBracket),
  UsbHidUsageKbKpPadKeyRightAngleBracket = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyRightAngleBracket),
  UsbHidUsageKbKpPadKeyBitwiseAnd        = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyBitwiseAnd),
  UsbHidUsageKbKpPadKeyLogicalAnd        = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyLogicalAnd),
  UsbHidUsageKbKpPadKeyBitwiseOr         = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyBitwiseOr),
  UsbHidUsageKbKpPadKeyLogicalOr         = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyLogicalOr),
  UsbHidUsageKbKpPadKeyColon             = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyColon),
  UsbHidUsageKbKpPadKeyHash              = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyHash),
  UsbHidUsageKbKpPadKeySpace             = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeySpace),
  UsbHidUsageKbKpPadKeyAt                = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyAt),
  UsbHidUsageKbKpPadKeyExclamationMark   = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyExclamationMark),
  UsbHidUsageKbKpPadKeyMemoryStore       = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyMemoryStore),
  UsbHidUsageKbKpPadKeyMemoryRecall      = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyMemoryRecall),
  UsbHidUsageKbKpPadKeyMemoryClear       = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyMemoryClear),
  UsbHidUsageKbKpPadKeyMemoryAdd         = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyMemoryAdd),
  UsbHidUsageKbKpPadKeyMemorySubtract    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyMemorySubtract),
  UsbHidUsageKbKpPadKeyMemoryMultiply    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyMemoryMultiply),
  UsbHidUsageKbKpPadKeyMemoryDivide      = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyMemoryDivide),
  UsbHidUsageKbKpPadKeySign              = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeySign),
  UsbHidUsageKbKpPadKeyClear             = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyClear),
  UsbHidUsageKbKpPadKeyClearEntry        = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyClearEntry),
  UsbHidUsageKbKpPadKeyBinary            = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyBinary),
  UsbHidUsageKbKpPadKeyOctal             = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyOctal),
  UsbHidUsageKbKpPadKeyDecimal           = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyDecimal),
  UsbHidUsageKbKpPadKeyHexadecimal       = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpPadKeyHexadecimal),
  UsbHidUsageKbKpModifierKeyLeftControl  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpModifierKeyLeftControl),
  UsbHidUsageKbKpModifierKeyLeftShift    = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpModifierKeyLeftShift),
  UsbHidUsageKbKpModifierKeyLeftOption   = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpModifierKeyLeftAlt),
  UsbHidUsageKbKpModifierKeyLeftCommand  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpModifierKeyLeftGui),
  UsbHidUsageKbKpModifierKeyRightControl = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpModifierKeyRightControl),
  UsbHidUsageKbKpModifierKeyRightShift   = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpModifierKeyRightShift),
  UsbHidUsageKbKpModifierKeyRightOption  = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpModifierKeyRightAlt),
  UsbHidUsageKbKpModifierKeyRightCommand = USB_HID_KB_KP_USAGE (UsbHidUsageIdKbKpModifierKeyRightGui)
};

#endif // USB_HID_H_
