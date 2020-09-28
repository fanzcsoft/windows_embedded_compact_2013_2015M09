//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
//
// Use of this source code is subject to the terms of the Microsoft shared
// source or premium shared source license agreement under which you licensed
// this source code. If you did not accept the terms of the license agreement,
// you are not authorized to use this source code. For the terms of the license,
// please see the license agreement between you and Microsoft or, if applicable,
// see the SOURCE.RTF on your install media or the root of your tools installation.
// THE SOURCE CODE IS PROVIDED "AS IS", WITH NO WARRANTIES OR INDEMNITIES.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright 1998-2004  Microsoft Corporation.  All Rights Reserved.
//
// Module Name:
//
//     testsequences.h  
// 
// Abstract:
// 
//	This file contains the declaration of the key map test cases.
//

#pragma once

//
// This is the maximum number of keystrokes required
// to produce a character.  This includes the number
// of deadkeys to press but *not* the number of state
// keys.  
//
// number of VK_KEYs required to create a WM_CHAR.
// MAX_SEQUENCE_LENGTH must fit within the bits defined
// by STATE_NUMMASK as part of KEYBOARDSTATE.
//

#define MAX_SEQUENCE_LENGTH        4
#define MAX_NUM_GEN_CHARS		   4 // Max possible amount of chars generated by keystroke, it could be only 2
                                     // It must be greater or equal than testSequence.nNumUnicodeChars
//
// Keyboard states - pressing one of these keys
// causes the keyboard to change states when used
// for some keyboard layouts.
//

#define STATE_CAPSLOCK      0x10
#define STATE_SHIFT         0x40
#define STATE_ALTRIGHT      0x80
#define STATE_ALTLEFT       0x80
#define STATE_ALL           (STATE_CAPSLOCK & STATE_SHIFT & STATE_ALTRIGHT & STATE_ALTLEFT)

//
// structure of a single key test.  Includes the
// VK_KEYS, expected unicode codepoint, keyboard
// states to turn on etc..etc..
//

#define STATE_STATEMASK     0xF0        // hi-byte is key states
#define STATE_NUMMASK       0x0F        // low byte is number of keys

typedef WORD KEYBOARDSTATE;


//
// Define a single test sequence as well as a test
// keyboard
//

typedef struct
{
	KEYBOARDSTATE nNumVirtualKeys;
	BYTE byaVirtualKeys[MAX_SEQUENCE_LENGTH];
	INT nNumUnicodeChars;
	WCHAR wcaUnicodeChars[MAX_NUM_GEN_CHARS];
} testSequence;

typedef struct
{
    HKL InputLocale;
    testSequence *pKeyMaps;
    WORD numKeyMaps;
} testKeyboard;