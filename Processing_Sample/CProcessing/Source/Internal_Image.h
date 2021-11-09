//------------------------------------------------------------------------------
// file:	Interal_Image.h
// author:	Daniel Hamilton
// brief:	API for loading and displaying images
//
// INTERNAL USE ONLY, DO NOT DISTRIBUTE
//
// Copyright � 2019 DigiPen, All rights reserved.
//------------------------------------------------------------------------------

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Defines:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Consts:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

typedef struct CP_Image_Struct
{
    int handle;              // handle to the nanoVG image
    char filepath[MAX_PATH]; // full path of the image
    int w;                   // width of the image
    int h;                   // height of the image
    int load_error;          // was there an error loading the image
} CP_Image_Struct;

//------------------------------------------------------------------------------
// Public Enums:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------


// INTERNAL USE
void CP_Image_Init(void);

// INTERNAL USE
void CP_ImageShutdown(void);

// This was implemented because of some screenshot melarchy
void CP_Image_ClearQueue_Free();

#ifdef __cplusplus
}
#endif
