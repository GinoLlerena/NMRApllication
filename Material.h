#ifndef _Material_H
#define _Material_H

#include "Sscommon.h"

static void InitMaterials( MATERIAL *pm, float *pd, int count );
void ss_InitMaterials();
void ss_InitTeaMaterials();
void ss_SetMaterial( MATERIAL *pMat );
MATERIAL *ss_RandomTeaMaterial(BOOL bSet);
int ss_iRand(int max);
void ss_SetTeaMaterial( int materialIndex );

#endif