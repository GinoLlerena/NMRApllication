// Structures.h: interface archive.
//	Comment - Defines enums and structures.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STRUCTURES_H__0C3372C7_324B_11D2_A5A8_043A03C10000__INCLUDED_)
#define AFX_STRUCTURES_H__0C3372C7_324B_11D2_A5A8_043A03C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

enum ParteRigida
{
	Ninguna,
	AnilloFenil,
	Bifenil,
	Trifenil
};

enum Medida
{
	Grados,
	Radianes
};

enum Eje 
{
	EjeEquis,
	EjeYe,
	EjeZeta
};

enum Simetria
{
	NoSimetria,
	D2,
	D4
};

struct StcParametro
{
	TCHAR strEtiqueta1[40];
	double dValor;
};

struct StcValorDual
{
	TCHAR strEtiqueta1[40];
	TCHAR strEtiqueta2[40];
	double dValor;
};

#endif // !defined(AFX_STRUCTURES_H__0C3372C7_324B_11D2_A5A8_043A03C10000__INCLUDED_)
