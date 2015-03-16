

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Sun Mar 15 10:21:47 2015
 */
/* Compiler settings for Proyecto.odl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __Proyecto_h_h__
#define __Proyecto_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IProyecto_FWD_DEFINED__
#define __IProyecto_FWD_DEFINED__
typedef interface IProyecto IProyecto;

#endif 	/* __IProyecto_FWD_DEFINED__ */


#ifndef __Document_FWD_DEFINED__
#define __Document_FWD_DEFINED__

#ifdef __cplusplus
typedef class Document Document;
#else
typedef struct Document Document;
#endif /* __cplusplus */

#endif 	/* __Document_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __Proyecto_LIBRARY_DEFINED__
#define __Proyecto_LIBRARY_DEFINED__

/* library Proyecto */
/* [version][uuid] */ 


DEFINE_GUID(LIBID_Proyecto,0xDC80CA4A,0x0D48,0x11D2,0xB3,0x9A,0xDC,0xF0,0xD4,0xC5,0x6A,0x32);

#ifndef __IProyecto_DISPINTERFACE_DEFINED__
#define __IProyecto_DISPINTERFACE_DEFINED__

/* dispinterface IProyecto */
/* [uuid] */ 


DEFINE_GUID(DIID_IProyecto,0xDC80CA4B,0x0D48,0x11D2,0xB3,0x9A,0xDC,0xF0,0xD4,0xC5,0x6A,0x32);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("DC80CA4B-0D48-11D2-B39A-DCF0D4C56A32")
    IProyecto : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IProyectoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IProyecto * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IProyecto * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IProyecto * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IProyecto * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IProyecto * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IProyecto * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IProyecto * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IProyectoVtbl;

    interface IProyecto
    {
        CONST_VTBL struct IProyectoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IProyecto_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IProyecto_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IProyecto_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IProyecto_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IProyecto_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IProyecto_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IProyecto_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IProyecto_DISPINTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_Document,0xDC80CA49,0x0D48,0x11D2,0xB3,0x9A,0xDC,0xF0,0xD4,0xC5,0x6A,0x32);

#ifdef __cplusplus

class DECLSPEC_UUID("DC80CA49-0D48-11D2-B39A-DCF0D4C56A32")
Document;
#endif
#endif /* __Proyecto_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


