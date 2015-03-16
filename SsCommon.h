// SsCommon.h: interface archive.
//	Comment - Defines and externals for screen saver common shell
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SSCOMMON_H__0C3372C8_324B_11D2_A5A8_043A03C10000__INCLUDED_)
#define AFX_SSCOMMON_H__0C3372C8_324B_11D2_A5A8_043A03C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <GL\gl.h>
#include <GL\glaux.h>
#include <assert.h>

#define NUM_TEA_MATERIALS 24

enum {
    EMERALD = 0,
    JADE,
    OBSIDIAN,
    PEARL,
    RUBY,
    TURQUOISE,
    BRASS,
    BRONZE,
    CHROME,
    COPPER,
    GOLD,
    SILVER,
    BLACK_PLASTIC,
    CYAN_PLASTIC,
    GREEN_PLASTIC,
    RED_PLASTIC,
    WHITE_PLASTIC,
    YELLOW_PLASTIC,
    BLACK_RUBBER,
    CYAN_RUBBER,
    GREEN_RUBBER,
    RED_RUBBER,
    WHITE_RUBBER,
    YELLOW_RUBBER
};

// 'white' materials, for texturing

#define NUM_TEX_MATERIALS 4

enum {
    BRIGHT_WHITE = NUM_TEA_MATERIALS,
    WHITE,
    WARM_WHITE,
    COOL_WHITE
};

typedef struct strRGBA {
    GLfloat r;
    GLfloat g;
    GLfloat b;
    GLfloat a;
} RGBA;


typedef struct _MATERIAL {
    RGBA ka;
    RGBA kd;
    RGBA ks;
    GLfloat specExp;
} MATERIAL;


#endif // !defined(AFX_SSCOMMON_H__0C3372C8_324B_11D2_A5A8_043A03C10000__INCLUDED_)
