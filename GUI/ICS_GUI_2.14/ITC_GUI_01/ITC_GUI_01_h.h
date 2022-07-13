

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0595 */
/* at Tue Sep 14 13:40:48 2021
 */
/* Compiler settings for ITC_GUI_01.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0595 
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


#ifndef __ITC_GUI_01_h_h__
#define __ITC_GUI_01_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IITC_GUI_01_FWD_DEFINED__
#define __IITC_GUI_01_FWD_DEFINED__
typedef interface IITC_GUI_01 IITC_GUI_01;

#endif 	/* __IITC_GUI_01_FWD_DEFINED__ */


#ifndef __ITC_GUI_01_FWD_DEFINED__
#define __ITC_GUI_01_FWD_DEFINED__

#ifdef __cplusplus
typedef class ITC_GUI_01 ITC_GUI_01;
#else
typedef struct ITC_GUI_01 ITC_GUI_01;
#endif /* __cplusplus */

#endif 	/* __ITC_GUI_01_FWD_DEFINED__ */


#ifndef __ISET_ETHERNET_FWD_DEFINED__
#define __ISET_ETHERNET_FWD_DEFINED__
typedef interface ISET_ETHERNET ISET_ETHERNET;

#endif 	/* __ISET_ETHERNET_FWD_DEFINED__ */


#ifndef __SET_ETHERNET_FWD_DEFINED__
#define __SET_ETHERNET_FWD_DEFINED__

#ifdef __cplusplus
typedef class SET_ETHERNET SET_ETHERNET;
#else
typedef struct SET_ETHERNET SET_ETHERNET;
#endif /* __cplusplus */

#endif 	/* __SET_ETHERNET_FWD_DEFINED__ */


#ifndef __ISET_ITC_FWD_DEFINED__
#define __ISET_ITC_FWD_DEFINED__
typedef interface ISET_ITC ISET_ITC;

#endif 	/* __ISET_ITC_FWD_DEFINED__ */


#ifndef __SET_ITC_FWD_DEFINED__
#define __SET_ITC_FWD_DEFINED__

#ifdef __cplusplus
typedef class SET_ITC SET_ITC;
#else
typedef struct SET_ITC SET_ITC;
#endif /* __cplusplus */

#endif 	/* __SET_ITC_FWD_DEFINED__ */


#ifndef __ISET_ARC1_FWD_DEFINED__
#define __ISET_ARC1_FWD_DEFINED__
typedef interface ISET_ARC1 ISET_ARC1;

#endif 	/* __ISET_ARC1_FWD_DEFINED__ */


#ifndef __SET_ARC1_FWD_DEFINED__
#define __SET_ARC1_FWD_DEFINED__

#ifdef __cplusplus
typedef class SET_ARC1 SET_ARC1;
#else
typedef struct SET_ARC1 SET_ARC1;
#endif /* __cplusplus */

#endif 	/* __SET_ARC1_FWD_DEFINED__ */


#ifndef __ISET_ARC2_FWD_DEFINED__
#define __ISET_ARC2_FWD_DEFINED__
typedef interface ISET_ARC2 ISET_ARC2;

#endif 	/* __ISET_ARC2_FWD_DEFINED__ */


#ifndef __SET_ARC2_FWD_DEFINED__
#define __SET_ARC2_FWD_DEFINED__

#ifdef __cplusplus
typedef class SET_ARC2 SET_ARC2;
#else
typedef struct SET_ARC2 SET_ARC2;
#endif /* __cplusplus */

#endif 	/* __SET_ARC2_FWD_DEFINED__ */


#ifndef __ISET_DIST_FWD_DEFINED__
#define __ISET_DIST_FWD_DEFINED__
typedef interface ISET_DIST ISET_DIST;

#endif 	/* __ISET_DIST_FWD_DEFINED__ */


#ifndef __SET_DIST_FWD_DEFINED__
#define __SET_DIST_FWD_DEFINED__

#ifdef __cplusplus
typedef class SET_DIST SET_DIST;
#else
typedef struct SET_DIST SET_DIST;
#endif /* __cplusplus */

#endif 	/* __SET_DIST_FWD_DEFINED__ */


#ifndef __ISET_1553B_FWD_DEFINED__
#define __ISET_1553B_FWD_DEFINED__
typedef interface ISET_1553B ISET_1553B;

#endif 	/* __ISET_1553B_FWD_DEFINED__ */


#ifndef __SET_1553B_FWD_DEFINED__
#define __SET_1553B_FWD_DEFINED__

#ifdef __cplusplus
typedef class SET_1553B SET_1553B;
#else
typedef struct SET_1553B SET_1553B;
#endif /* __cplusplus */

#endif 	/* __SET_1553B_FWD_DEFINED__ */


#ifndef __IMWOD_LOAD_FWD_DEFINED__
#define __IMWOD_LOAD_FWD_DEFINED__
typedef interface IMWOD_LOAD IMWOD_LOAD;

#endif 	/* __IMWOD_LOAD_FWD_DEFINED__ */


#ifndef __MWOD_LOAD_FWD_DEFINED__
#define __MWOD_LOAD_FWD_DEFINED__

#ifdef __cplusplus
typedef class MWOD_LOAD MWOD_LOAD;
#else
typedef struct MWOD_LOAD MWOD_LOAD;
#endif /* __cplusplus */

#endif 	/* __MWOD_LOAD_FWD_DEFINED__ */


#ifndef __IFMT_NET_LOAD_FWD_DEFINED__
#define __IFMT_NET_LOAD_FWD_DEFINED__
typedef interface IFMT_NET_LOAD IFMT_NET_LOAD;

#endif 	/* __IFMT_NET_LOAD_FWD_DEFINED__ */


#ifndef __FMT_NET_LOAD_FWD_DEFINED__
#define __FMT_NET_LOAD_FWD_DEFINED__

#ifdef __cplusplus
typedef class FMT_NET_LOAD FMT_NET_LOAD;
#else
typedef struct FMT_NET_LOAD FMT_NET_LOAD;
#endif /* __cplusplus */

#endif 	/* __FMT_NET_LOAD_FWD_DEFINED__ */


#ifndef __IPRESET_LOAD_FWD_DEFINED__
#define __IPRESET_LOAD_FWD_DEFINED__
typedef interface IPRESET_LOAD IPRESET_LOAD;

#endif 	/* __IPRESET_LOAD_FWD_DEFINED__ */


#ifndef __PRESET_LOAD_FWD_DEFINED__
#define __PRESET_LOAD_FWD_DEFINED__

#ifdef __cplusplus
typedef class PRESET_LOAD PRESET_LOAD;
#else
typedef struct PRESET_LOAD PRESET_LOAD;
#endif /* __cplusplus */

#endif 	/* __PRESET_LOAD_FWD_DEFINED__ */


#ifndef __IMWOD_LOAD_STATUS_FWD_DEFINED__
#define __IMWOD_LOAD_STATUS_FWD_DEFINED__
typedef interface IMWOD_LOAD_STATUS IMWOD_LOAD_STATUS;

#endif 	/* __IMWOD_LOAD_STATUS_FWD_DEFINED__ */


#ifndef __MWOD_LOAD_STATUS_FWD_DEFINED__
#define __MWOD_LOAD_STATUS_FWD_DEFINED__

#ifdef __cplusplus
typedef class MWOD_LOAD_STATUS MWOD_LOAD_STATUS;
#else
typedef struct MWOD_LOAD_STATUS MWOD_LOAD_STATUS;
#endif /* __cplusplus */

#endif 	/* __MWOD_LOAD_STATUS_FWD_DEFINED__ */


#ifndef __IPRESET_STATUS_FWD_DEFINED__
#define __IPRESET_STATUS_FWD_DEFINED__
typedef interface IPRESET_STATUS IPRESET_STATUS;

#endif 	/* __IPRESET_STATUS_FWD_DEFINED__ */


#ifndef __PRESET_STATUS_FWD_DEFINED__
#define __PRESET_STATUS_FWD_DEFINED__

#ifdef __cplusplus
typedef class PRESET_STATUS PRESET_STATUS;
#else
typedef struct PRESET_STATUS PRESET_STATUS;
#endif /* __cplusplus */

#endif 	/* __PRESET_STATUS_FWD_DEFINED__ */


#ifndef __IBIT_SUMMARY_FWD_DEFINED__
#define __IBIT_SUMMARY_FWD_DEFINED__
typedef interface IBIT_SUMMARY IBIT_SUMMARY;

#endif 	/* __IBIT_SUMMARY_FWD_DEFINED__ */


#ifndef __BIT_SUMMARY_FWD_DEFINED__
#define __BIT_SUMMARY_FWD_DEFINED__

#ifdef __cplusplus
typedef class BIT_SUMMARY BIT_SUMMARY;
#else
typedef struct BIT_SUMMARY BIT_SUMMARY;
#endif /* __cplusplus */

#endif 	/* __BIT_SUMMARY_FWD_DEFINED__ */


#ifndef __IICS_CP_FWD_DEFINED__
#define __IICS_CP_FWD_DEFINED__
typedef interface IICS_CP IICS_CP;

#endif 	/* __IICS_CP_FWD_DEFINED__ */


#ifndef __ICS_CP_FWD_DEFINED__
#define __ICS_CP_FWD_DEFINED__

#ifdef __cplusplus
typedef class ICS_CP ICS_CP;
#else
typedef struct ICS_CP ICS_CP;
#endif /* __cplusplus */

#endif 	/* __ICS_CP_FWD_DEFINED__ */


#ifndef __IVOICE_MESSAGE_FWD_DEFINED__
#define __IVOICE_MESSAGE_FWD_DEFINED__
typedef interface IVOICE_MESSAGE IVOICE_MESSAGE;

#endif 	/* __IVOICE_MESSAGE_FWD_DEFINED__ */


#ifndef __VOICE_MESSAGE_FWD_DEFINED__
#define __VOICE_MESSAGE_FWD_DEFINED__

#ifdef __cplusplus
typedef class VOICE_MESSAGE VOICE_MESSAGE;
#else
typedef struct VOICE_MESSAGE VOICE_MESSAGE;
#endif /* __cplusplus */

#endif 	/* __VOICE_MESSAGE_FWD_DEFINED__ */


#ifndef __IFAULT_DATA_FWD_DEFINED__
#define __IFAULT_DATA_FWD_DEFINED__
typedef interface IFAULT_DATA IFAULT_DATA;

#endif 	/* __IFAULT_DATA_FWD_DEFINED__ */


#ifndef __FAULT_DATA_FWD_DEFINED__
#define __FAULT_DATA_FWD_DEFINED__

#ifdef __cplusplus
typedef class FAULT_DATA FAULT_DATA;
#else
typedef struct FAULT_DATA FAULT_DATA;
#endif /* __cplusplus */

#endif 	/* __FAULT_DATA_FWD_DEFINED__ */


#ifndef __IMWOD_LOAD2_FWD_DEFINED__
#define __IMWOD_LOAD2_FWD_DEFINED__
typedef interface IMWOD_LOAD2 IMWOD_LOAD2;

#endif 	/* __IMWOD_LOAD2_FWD_DEFINED__ */


#ifndef __MWOD_LOAD2_FWD_DEFINED__
#define __MWOD_LOAD2_FWD_DEFINED__

#ifdef __cplusplus
typedef class MWOD_LOAD2 MWOD_LOAD2;
#else
typedef struct MWOD_LOAD2 MWOD_LOAD2;
#endif /* __cplusplus */

#endif 	/* __MWOD_LOAD2_FWD_DEFINED__ */


#ifndef __IPRESET_LOAD2_FWD_DEFINED__
#define __IPRESET_LOAD2_FWD_DEFINED__
typedef interface IPRESET_LOAD2 IPRESET_LOAD2;

#endif 	/* __IPRESET_LOAD2_FWD_DEFINED__ */


#ifndef __PRESET_LOAD2_FWD_DEFINED__
#define __PRESET_LOAD2_FWD_DEFINED__

#ifdef __cplusplus
typedef class PRESET_LOAD2 PRESET_LOAD2;
#else
typedef struct PRESET_LOAD2 PRESET_LOAD2;
#endif /* __cplusplus */

#endif 	/* __PRESET_LOAD2_FWD_DEFINED__ */


#ifndef __IFMT_NET_LOAD2_FWD_DEFINED__
#define __IFMT_NET_LOAD2_FWD_DEFINED__
typedef interface IFMT_NET_LOAD2 IFMT_NET_LOAD2;

#endif 	/* __IFMT_NET_LOAD2_FWD_DEFINED__ */


#ifndef __FMT_NET_LOAD2_FWD_DEFINED__
#define __FMT_NET_LOAD2_FWD_DEFINED__

#ifdef __cplusplus
typedef class FMT_NET_LOAD2 FMT_NET_LOAD2;
#else
typedef struct FMT_NET_LOAD2 FMT_NET_LOAD2;
#endif /* __cplusplus */

#endif 	/* __FMT_NET_LOAD2_FWD_DEFINED__ */


#ifndef __IPRESET_STATUS2_FWD_DEFINED__
#define __IPRESET_STATUS2_FWD_DEFINED__
typedef interface IPRESET_STATUS2 IPRESET_STATUS2;

#endif 	/* __IPRESET_STATUS2_FWD_DEFINED__ */


#ifndef __PRESET_STATUS2_FWD_DEFINED__
#define __PRESET_STATUS2_FWD_DEFINED__

#ifdef __cplusplus
typedef class PRESET_STATUS2 PRESET_STATUS2;
#else
typedef struct PRESET_STATUS2 PRESET_STATUS2;
#endif /* __cplusplus */

#endif 	/* __PRESET_STATUS2_FWD_DEFINED__ */


#ifndef __IBIT_SUMMARY2_FWD_DEFINED__
#define __IBIT_SUMMARY2_FWD_DEFINED__
typedef interface IBIT_SUMMARY2 IBIT_SUMMARY2;

#endif 	/* __IBIT_SUMMARY2_FWD_DEFINED__ */


#ifndef __BIT_SUMMARY2_FWD_DEFINED__
#define __BIT_SUMMARY2_FWD_DEFINED__

#ifdef __cplusplus
typedef class BIT_SUMMARY2 BIT_SUMMARY2;
#else
typedef struct BIT_SUMMARY2 BIT_SUMMARY2;
#endif /* __cplusplus */

#endif 	/* __BIT_SUMMARY2_FWD_DEFINED__ */


#ifndef __ICtrlPowSup_FWD_DEFINED__
#define __ICtrlPowSup_FWD_DEFINED__
typedef interface ICtrlPowSup ICtrlPowSup;

#endif 	/* __ICtrlPowSup_FWD_DEFINED__ */


#ifndef __CtrlPowSup_FWD_DEFINED__
#define __CtrlPowSup_FWD_DEFINED__

#ifdef __cplusplus
typedef class CtrlPowSup CtrlPowSup;
#else
typedef struct CtrlPowSup CtrlPowSup;
#endif /* __cplusplus */

#endif 	/* __CtrlPowSup_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __ITC_GUI_01_LIBRARY_DEFINED__
#define __ITC_GUI_01_LIBRARY_DEFINED__

/* library ITC_GUI_01 */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ITC_GUI_01;

#ifndef __IITC_GUI_01_DISPINTERFACE_DEFINED__
#define __IITC_GUI_01_DISPINTERFACE_DEFINED__

/* dispinterface IITC_GUI_01 */
/* [uuid] */ 


EXTERN_C const IID DIID_IITC_GUI_01;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("6B05AC16-D1C7-4DCE-B56C-4EC1E6ACA41B")
    IITC_GUI_01 : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IITC_GUI_01Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IITC_GUI_01 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IITC_GUI_01 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IITC_GUI_01 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IITC_GUI_01 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IITC_GUI_01 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IITC_GUI_01 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IITC_GUI_01 * This,
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
    } IITC_GUI_01Vtbl;

    interface IITC_GUI_01
    {
        CONST_VTBL struct IITC_GUI_01Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IITC_GUI_01_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IITC_GUI_01_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IITC_GUI_01_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IITC_GUI_01_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IITC_GUI_01_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IITC_GUI_01_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IITC_GUI_01_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IITC_GUI_01_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ITC_GUI_01;

#ifdef __cplusplus

class DECLSPEC_UUID("429EBE3E-3D76-4298-9B50-EBA4C47632DA")
ITC_GUI_01;
#endif

#ifndef __ISET_ETHERNET_DISPINTERFACE_DEFINED__
#define __ISET_ETHERNET_DISPINTERFACE_DEFINED__

/* dispinterface ISET_ETHERNET */
/* [uuid] */ 


EXTERN_C const IID DIID_ISET_ETHERNET;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("4EBAF9A3-D8CA-4A87-A7EF-D99B1767E15E")
    ISET_ETHERNET : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ISET_ETHERNETVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISET_ETHERNET * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISET_ETHERNET * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISET_ETHERNET * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISET_ETHERNET * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISET_ETHERNET * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISET_ETHERNET * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISET_ETHERNET * This,
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
    } ISET_ETHERNETVtbl;

    interface ISET_ETHERNET
    {
        CONST_VTBL struct ISET_ETHERNETVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISET_ETHERNET_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISET_ETHERNET_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISET_ETHERNET_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISET_ETHERNET_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISET_ETHERNET_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISET_ETHERNET_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISET_ETHERNET_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ISET_ETHERNET_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SET_ETHERNET;

#ifdef __cplusplus

class DECLSPEC_UUID("D5663DEB-83F0-431A-A8F8-14516F07C00A")
SET_ETHERNET;
#endif

#ifndef __ISET_ITC_DISPINTERFACE_DEFINED__
#define __ISET_ITC_DISPINTERFACE_DEFINED__

/* dispinterface ISET_ITC */
/* [uuid] */ 


EXTERN_C const IID DIID_ISET_ITC;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("28B3BCF5-A0E6-4D3E-AAC3-7ACB64725948")
    ISET_ITC : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ISET_ITCVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISET_ITC * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISET_ITC * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISET_ITC * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISET_ITC * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISET_ITC * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISET_ITC * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISET_ITC * This,
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
    } ISET_ITCVtbl;

    interface ISET_ITC
    {
        CONST_VTBL struct ISET_ITCVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISET_ITC_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISET_ITC_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISET_ITC_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISET_ITC_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISET_ITC_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISET_ITC_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISET_ITC_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ISET_ITC_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SET_ITC;

#ifdef __cplusplus

class DECLSPEC_UUID("6D11709D-C4AC-4649-B38F-C5BAF023DB65")
SET_ITC;
#endif

#ifndef __ISET_ARC1_DISPINTERFACE_DEFINED__
#define __ISET_ARC1_DISPINTERFACE_DEFINED__

/* dispinterface ISET_ARC1 */
/* [uuid] */ 


EXTERN_C const IID DIID_ISET_ARC1;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("293F06B9-53B3-49C1-B5F5-53948C916EF3")
    ISET_ARC1 : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ISET_ARC1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISET_ARC1 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISET_ARC1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISET_ARC1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISET_ARC1 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISET_ARC1 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISET_ARC1 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISET_ARC1 * This,
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
    } ISET_ARC1Vtbl;

    interface ISET_ARC1
    {
        CONST_VTBL struct ISET_ARC1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISET_ARC1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISET_ARC1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISET_ARC1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISET_ARC1_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISET_ARC1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISET_ARC1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISET_ARC1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ISET_ARC1_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SET_ARC1;

#ifdef __cplusplus

class DECLSPEC_UUID("B7C6A205-2019-4441-8205-4B2CA9A83F92")
SET_ARC1;
#endif

#ifndef __ISET_ARC2_DISPINTERFACE_DEFINED__
#define __ISET_ARC2_DISPINTERFACE_DEFINED__

/* dispinterface ISET_ARC2 */
/* [uuid] */ 


EXTERN_C const IID DIID_ISET_ARC2;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("07B58DA5-557C-4270-BC24-7F301C0B81BC")
    ISET_ARC2 : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ISET_ARC2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISET_ARC2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISET_ARC2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISET_ARC2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISET_ARC2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISET_ARC2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISET_ARC2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISET_ARC2 * This,
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
    } ISET_ARC2Vtbl;

    interface ISET_ARC2
    {
        CONST_VTBL struct ISET_ARC2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISET_ARC2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISET_ARC2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISET_ARC2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISET_ARC2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISET_ARC2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISET_ARC2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISET_ARC2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ISET_ARC2_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SET_ARC2;

#ifdef __cplusplus

class DECLSPEC_UUID("06C7362C-BDCD-4206-A92D-D4FB2B7FB1F5")
SET_ARC2;
#endif

#ifndef __ISET_DIST_DISPINTERFACE_DEFINED__
#define __ISET_DIST_DISPINTERFACE_DEFINED__

/* dispinterface ISET_DIST */
/* [uuid] */ 


EXTERN_C const IID DIID_ISET_DIST;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("A667630F-464E-41D5-892B-E49578A4331D")
    ISET_DIST : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ISET_DISTVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISET_DIST * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISET_DIST * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISET_DIST * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISET_DIST * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISET_DIST * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISET_DIST * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISET_DIST * This,
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
    } ISET_DISTVtbl;

    interface ISET_DIST
    {
        CONST_VTBL struct ISET_DISTVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISET_DIST_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISET_DIST_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISET_DIST_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISET_DIST_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISET_DIST_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISET_DIST_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISET_DIST_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ISET_DIST_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SET_DIST;

#ifdef __cplusplus

class DECLSPEC_UUID("39845814-9B15-4CEF-A3D1-F097B8A43E50")
SET_DIST;
#endif

#ifndef __ISET_1553B_DISPINTERFACE_DEFINED__
#define __ISET_1553B_DISPINTERFACE_DEFINED__

/* dispinterface ISET_1553B */
/* [uuid] */ 


EXTERN_C const IID DIID_ISET_1553B;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("47E69852-7FA2-44E5-BB39-1C368A730BD5")
    ISET_1553B : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ISET_1553BVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISET_1553B * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISET_1553B * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISET_1553B * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISET_1553B * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISET_1553B * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISET_1553B * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISET_1553B * This,
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
    } ISET_1553BVtbl;

    interface ISET_1553B
    {
        CONST_VTBL struct ISET_1553BVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISET_1553B_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISET_1553B_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISET_1553B_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISET_1553B_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISET_1553B_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISET_1553B_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISET_1553B_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ISET_1553B_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SET_1553B;

#ifdef __cplusplus

class DECLSPEC_UUID("81178E7C-0BF7-424A-A93E-CCCEB1CEDE45")
SET_1553B;
#endif

#ifndef __IMWOD_LOAD_DISPINTERFACE_DEFINED__
#define __IMWOD_LOAD_DISPINTERFACE_DEFINED__

/* dispinterface IMWOD_LOAD */
/* [uuid] */ 


EXTERN_C const IID DIID_IMWOD_LOAD;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("D908D661-DE11-4CA1-AD04-9486E33C61EE")
    IMWOD_LOAD : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IMWOD_LOADVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMWOD_LOAD * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMWOD_LOAD * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMWOD_LOAD * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMWOD_LOAD * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMWOD_LOAD * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMWOD_LOAD * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMWOD_LOAD * This,
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
    } IMWOD_LOADVtbl;

    interface IMWOD_LOAD
    {
        CONST_VTBL struct IMWOD_LOADVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMWOD_LOAD_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMWOD_LOAD_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMWOD_LOAD_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMWOD_LOAD_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMWOD_LOAD_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMWOD_LOAD_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMWOD_LOAD_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IMWOD_LOAD_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_MWOD_LOAD;

#ifdef __cplusplus

class DECLSPEC_UUID("79F9FA5F-65AC-4204-99AD-D7AAEA03310F")
MWOD_LOAD;
#endif

#ifndef __IFMT_NET_LOAD_DISPINTERFACE_DEFINED__
#define __IFMT_NET_LOAD_DISPINTERFACE_DEFINED__

/* dispinterface IFMT_NET_LOAD */
/* [uuid] */ 


EXTERN_C const IID DIID_IFMT_NET_LOAD;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("C7E6F7CE-2DED-4A47-9A49-3E6A13454DB4")
    IFMT_NET_LOAD : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFMT_NET_LOADVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFMT_NET_LOAD * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFMT_NET_LOAD * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFMT_NET_LOAD * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFMT_NET_LOAD * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFMT_NET_LOAD * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFMT_NET_LOAD * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFMT_NET_LOAD * This,
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
    } IFMT_NET_LOADVtbl;

    interface IFMT_NET_LOAD
    {
        CONST_VTBL struct IFMT_NET_LOADVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFMT_NET_LOAD_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFMT_NET_LOAD_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFMT_NET_LOAD_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFMT_NET_LOAD_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFMT_NET_LOAD_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFMT_NET_LOAD_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFMT_NET_LOAD_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFMT_NET_LOAD_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_FMT_NET_LOAD;

#ifdef __cplusplus

class DECLSPEC_UUID("6B277791-DB48-46A8-9F61-04A3B1571423")
FMT_NET_LOAD;
#endif

#ifndef __IPRESET_LOAD_DISPINTERFACE_DEFINED__
#define __IPRESET_LOAD_DISPINTERFACE_DEFINED__

/* dispinterface IPRESET_LOAD */
/* [uuid] */ 


EXTERN_C const IID DIID_IPRESET_LOAD;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("EFE3EFE2-D885-4223-8DBE-DB5BB4F26DA8")
    IPRESET_LOAD : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IPRESET_LOADVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPRESET_LOAD * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPRESET_LOAD * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPRESET_LOAD * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPRESET_LOAD * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPRESET_LOAD * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPRESET_LOAD * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPRESET_LOAD * This,
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
    } IPRESET_LOADVtbl;

    interface IPRESET_LOAD
    {
        CONST_VTBL struct IPRESET_LOADVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPRESET_LOAD_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPRESET_LOAD_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPRESET_LOAD_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPRESET_LOAD_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IPRESET_LOAD_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IPRESET_LOAD_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IPRESET_LOAD_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IPRESET_LOAD_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_PRESET_LOAD;

#ifdef __cplusplus

class DECLSPEC_UUID("9EFC1C1B-75ED-496D-B8EF-56E98459014C")
PRESET_LOAD;
#endif

#ifndef __IMWOD_LOAD_STATUS_DISPINTERFACE_DEFINED__
#define __IMWOD_LOAD_STATUS_DISPINTERFACE_DEFINED__

/* dispinterface IMWOD_LOAD_STATUS */
/* [uuid] */ 


EXTERN_C const IID DIID_IMWOD_LOAD_STATUS;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("E7A4D5E4-58DF-4B65-8FAA-A50CA84B3FB8")
    IMWOD_LOAD_STATUS : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IMWOD_LOAD_STATUSVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMWOD_LOAD_STATUS * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMWOD_LOAD_STATUS * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMWOD_LOAD_STATUS * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMWOD_LOAD_STATUS * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMWOD_LOAD_STATUS * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMWOD_LOAD_STATUS * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMWOD_LOAD_STATUS * This,
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
    } IMWOD_LOAD_STATUSVtbl;

    interface IMWOD_LOAD_STATUS
    {
        CONST_VTBL struct IMWOD_LOAD_STATUSVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMWOD_LOAD_STATUS_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMWOD_LOAD_STATUS_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMWOD_LOAD_STATUS_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMWOD_LOAD_STATUS_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMWOD_LOAD_STATUS_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMWOD_LOAD_STATUS_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMWOD_LOAD_STATUS_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IMWOD_LOAD_STATUS_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_MWOD_LOAD_STATUS;

#ifdef __cplusplus

class DECLSPEC_UUID("49E71729-17E3-4313-A939-4101A783E8E0")
MWOD_LOAD_STATUS;
#endif

#ifndef __IPRESET_STATUS_DISPINTERFACE_DEFINED__
#define __IPRESET_STATUS_DISPINTERFACE_DEFINED__

/* dispinterface IPRESET_STATUS */
/* [uuid] */ 


EXTERN_C const IID DIID_IPRESET_STATUS;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("1EE600BB-74FE-46A4-93D3-6463B699D9F3")
    IPRESET_STATUS : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IPRESET_STATUSVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPRESET_STATUS * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPRESET_STATUS * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPRESET_STATUS * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPRESET_STATUS * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPRESET_STATUS * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPRESET_STATUS * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPRESET_STATUS * This,
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
    } IPRESET_STATUSVtbl;

    interface IPRESET_STATUS
    {
        CONST_VTBL struct IPRESET_STATUSVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPRESET_STATUS_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPRESET_STATUS_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPRESET_STATUS_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPRESET_STATUS_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IPRESET_STATUS_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IPRESET_STATUS_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IPRESET_STATUS_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IPRESET_STATUS_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_PRESET_STATUS;

#ifdef __cplusplus

class DECLSPEC_UUID("413A2A55-E2F0-4E8B-9DD1-41ABBA4F873B")
PRESET_STATUS;
#endif

#ifndef __IBIT_SUMMARY_DISPINTERFACE_DEFINED__
#define __IBIT_SUMMARY_DISPINTERFACE_DEFINED__

/* dispinterface IBIT_SUMMARY */
/* [uuid] */ 


EXTERN_C const IID DIID_IBIT_SUMMARY;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("2EDCFB4E-D184-4558-9296-5923016A44D5")
    IBIT_SUMMARY : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IBIT_SUMMARYVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBIT_SUMMARY * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBIT_SUMMARY * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBIT_SUMMARY * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IBIT_SUMMARY * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IBIT_SUMMARY * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IBIT_SUMMARY * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IBIT_SUMMARY * This,
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
    } IBIT_SUMMARYVtbl;

    interface IBIT_SUMMARY
    {
        CONST_VTBL struct IBIT_SUMMARYVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBIT_SUMMARY_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBIT_SUMMARY_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBIT_SUMMARY_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBIT_SUMMARY_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IBIT_SUMMARY_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IBIT_SUMMARY_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IBIT_SUMMARY_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IBIT_SUMMARY_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_BIT_SUMMARY;

#ifdef __cplusplus

class DECLSPEC_UUID("5333C881-0D1B-433C-A242-FD7EC5F60D36")
BIT_SUMMARY;
#endif

#ifndef __IICS_CP_DISPINTERFACE_DEFINED__
#define __IICS_CP_DISPINTERFACE_DEFINED__

/* dispinterface IICS_CP */
/* [uuid] */ 


EXTERN_C const IID DIID_IICS_CP;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("92F4EE27-6C21-4324-9128-76FF0519ADF2")
    IICS_CP : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IICS_CPVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IICS_CP * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IICS_CP * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IICS_CP * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IICS_CP * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IICS_CP * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IICS_CP * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IICS_CP * This,
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
    } IICS_CPVtbl;

    interface IICS_CP
    {
        CONST_VTBL struct IICS_CPVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IICS_CP_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IICS_CP_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IICS_CP_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IICS_CP_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IICS_CP_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IICS_CP_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IICS_CP_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IICS_CP_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ICS_CP;

#ifdef __cplusplus

class DECLSPEC_UUID("FD144883-AF7F-4A7D-ADEC-1B2928B6293A")
ICS_CP;
#endif

#ifndef __IVOICE_MESSAGE_DISPINTERFACE_DEFINED__
#define __IVOICE_MESSAGE_DISPINTERFACE_DEFINED__

/* dispinterface IVOICE_MESSAGE */
/* [uuid] */ 


EXTERN_C const IID DIID_IVOICE_MESSAGE;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("8BA951F5-0BB7-4E28-92F5-13F25D2B9F61")
    IVOICE_MESSAGE : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IVOICE_MESSAGEVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVOICE_MESSAGE * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVOICE_MESSAGE * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVOICE_MESSAGE * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IVOICE_MESSAGE * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IVOICE_MESSAGE * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IVOICE_MESSAGE * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IVOICE_MESSAGE * This,
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
    } IVOICE_MESSAGEVtbl;

    interface IVOICE_MESSAGE
    {
        CONST_VTBL struct IVOICE_MESSAGEVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVOICE_MESSAGE_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVOICE_MESSAGE_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVOICE_MESSAGE_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVOICE_MESSAGE_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IVOICE_MESSAGE_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IVOICE_MESSAGE_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IVOICE_MESSAGE_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IVOICE_MESSAGE_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_VOICE_MESSAGE;

#ifdef __cplusplus

class DECLSPEC_UUID("A3AA2925-32D0-42CC-BA0D-EE90ED1A8D3E")
VOICE_MESSAGE;
#endif

#ifndef __IFAULT_DATA_DISPINTERFACE_DEFINED__
#define __IFAULT_DATA_DISPINTERFACE_DEFINED__

/* dispinterface IFAULT_DATA */
/* [uuid] */ 


EXTERN_C const IID DIID_IFAULT_DATA;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("EA185368-4728-4774-BCD1-21D7757D2509")
    IFAULT_DATA : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFAULT_DATAVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFAULT_DATA * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFAULT_DATA * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFAULT_DATA * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFAULT_DATA * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFAULT_DATA * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFAULT_DATA * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFAULT_DATA * This,
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
    } IFAULT_DATAVtbl;

    interface IFAULT_DATA
    {
        CONST_VTBL struct IFAULT_DATAVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFAULT_DATA_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFAULT_DATA_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFAULT_DATA_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFAULT_DATA_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFAULT_DATA_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFAULT_DATA_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFAULT_DATA_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFAULT_DATA_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_FAULT_DATA;

#ifdef __cplusplus

class DECLSPEC_UUID("AC46178D-A268-4049-86C8-8E8DBD4F9B0A")
FAULT_DATA;
#endif

#ifndef __IMWOD_LOAD2_DISPINTERFACE_DEFINED__
#define __IMWOD_LOAD2_DISPINTERFACE_DEFINED__

/* dispinterface IMWOD_LOAD2 */
/* [uuid] */ 


EXTERN_C const IID DIID_IMWOD_LOAD2;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("46698E4B-8797-47B4-883C-3E43AA31478F")
    IMWOD_LOAD2 : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IMWOD_LOAD2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMWOD_LOAD2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMWOD_LOAD2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMWOD_LOAD2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMWOD_LOAD2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMWOD_LOAD2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMWOD_LOAD2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMWOD_LOAD2 * This,
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
    } IMWOD_LOAD2Vtbl;

    interface IMWOD_LOAD2
    {
        CONST_VTBL struct IMWOD_LOAD2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMWOD_LOAD2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMWOD_LOAD2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMWOD_LOAD2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMWOD_LOAD2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMWOD_LOAD2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMWOD_LOAD2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMWOD_LOAD2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IMWOD_LOAD2_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_MWOD_LOAD2;

#ifdef __cplusplus

class DECLSPEC_UUID("57F47681-25E1-421C-8E34-5433976A8F38")
MWOD_LOAD2;
#endif

#ifndef __IPRESET_LOAD2_DISPINTERFACE_DEFINED__
#define __IPRESET_LOAD2_DISPINTERFACE_DEFINED__

/* dispinterface IPRESET_LOAD2 */
/* [uuid] */ 


EXTERN_C const IID DIID_IPRESET_LOAD2;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("4A68286B-D723-4A5B-BFCC-EF8FFAFF329C")
    IPRESET_LOAD2 : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IPRESET_LOAD2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPRESET_LOAD2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPRESET_LOAD2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPRESET_LOAD2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPRESET_LOAD2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPRESET_LOAD2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPRESET_LOAD2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPRESET_LOAD2 * This,
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
    } IPRESET_LOAD2Vtbl;

    interface IPRESET_LOAD2
    {
        CONST_VTBL struct IPRESET_LOAD2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPRESET_LOAD2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPRESET_LOAD2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPRESET_LOAD2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPRESET_LOAD2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IPRESET_LOAD2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IPRESET_LOAD2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IPRESET_LOAD2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IPRESET_LOAD2_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_PRESET_LOAD2;

#ifdef __cplusplus

class DECLSPEC_UUID("F435EFFD-7B21-485A-87B3-F6CEFF94544F")
PRESET_LOAD2;
#endif

#ifndef __IFMT_NET_LOAD2_DISPINTERFACE_DEFINED__
#define __IFMT_NET_LOAD2_DISPINTERFACE_DEFINED__

/* dispinterface IFMT_NET_LOAD2 */
/* [uuid] */ 


EXTERN_C const IID DIID_IFMT_NET_LOAD2;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("98AB4848-660F-487E-873F-64D4FE97A393")
    IFMT_NET_LOAD2 : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFMT_NET_LOAD2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFMT_NET_LOAD2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFMT_NET_LOAD2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFMT_NET_LOAD2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFMT_NET_LOAD2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFMT_NET_LOAD2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFMT_NET_LOAD2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFMT_NET_LOAD2 * This,
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
    } IFMT_NET_LOAD2Vtbl;

    interface IFMT_NET_LOAD2
    {
        CONST_VTBL struct IFMT_NET_LOAD2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFMT_NET_LOAD2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFMT_NET_LOAD2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFMT_NET_LOAD2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFMT_NET_LOAD2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFMT_NET_LOAD2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFMT_NET_LOAD2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFMT_NET_LOAD2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFMT_NET_LOAD2_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_FMT_NET_LOAD2;

#ifdef __cplusplus

class DECLSPEC_UUID("2FB81347-3175-49A0-8359-25E571FA43FF")
FMT_NET_LOAD2;
#endif

#ifndef __IPRESET_STATUS2_DISPINTERFACE_DEFINED__
#define __IPRESET_STATUS2_DISPINTERFACE_DEFINED__

/* dispinterface IPRESET_STATUS2 */
/* [uuid] */ 


EXTERN_C const IID DIID_IPRESET_STATUS2;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("61BA0EBF-7A3C-45FB-9096-B86DF9A4AABE")
    IPRESET_STATUS2 : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IPRESET_STATUS2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPRESET_STATUS2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPRESET_STATUS2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPRESET_STATUS2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPRESET_STATUS2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPRESET_STATUS2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPRESET_STATUS2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPRESET_STATUS2 * This,
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
    } IPRESET_STATUS2Vtbl;

    interface IPRESET_STATUS2
    {
        CONST_VTBL struct IPRESET_STATUS2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPRESET_STATUS2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPRESET_STATUS2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPRESET_STATUS2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPRESET_STATUS2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IPRESET_STATUS2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IPRESET_STATUS2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IPRESET_STATUS2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IPRESET_STATUS2_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_PRESET_STATUS2;

#ifdef __cplusplus

class DECLSPEC_UUID("ADB8CF58-E989-499E-ADD3-DC3A9FF370F3")
PRESET_STATUS2;
#endif

#ifndef __IBIT_SUMMARY2_DISPINTERFACE_DEFINED__
#define __IBIT_SUMMARY2_DISPINTERFACE_DEFINED__

/* dispinterface IBIT_SUMMARY2 */
/* [uuid] */ 


EXTERN_C const IID DIID_IBIT_SUMMARY2;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("176AEA64-ACED-4471-B42E-9A1ACAFE343A")
    IBIT_SUMMARY2 : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IBIT_SUMMARY2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBIT_SUMMARY2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBIT_SUMMARY2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBIT_SUMMARY2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IBIT_SUMMARY2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IBIT_SUMMARY2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IBIT_SUMMARY2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IBIT_SUMMARY2 * This,
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
    } IBIT_SUMMARY2Vtbl;

    interface IBIT_SUMMARY2
    {
        CONST_VTBL struct IBIT_SUMMARY2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBIT_SUMMARY2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBIT_SUMMARY2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBIT_SUMMARY2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBIT_SUMMARY2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IBIT_SUMMARY2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IBIT_SUMMARY2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IBIT_SUMMARY2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IBIT_SUMMARY2_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_BIT_SUMMARY2;

#ifdef __cplusplus

class DECLSPEC_UUID("36C328B5-FF20-4AFA-A76A-AE148783D6D1")
BIT_SUMMARY2;
#endif

#ifndef __ICtrlPowSup_DISPINTERFACE_DEFINED__
#define __ICtrlPowSup_DISPINTERFACE_DEFINED__

/* dispinterface ICtrlPowSup */
/* [uuid] */ 


EXTERN_C const IID DIID_ICtrlPowSup;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("FF4A1FF5-E9D8-41D2-823D-5BA83B84FD14")
    ICtrlPowSup : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ICtrlPowSupVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICtrlPowSup * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICtrlPowSup * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICtrlPowSup * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICtrlPowSup * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICtrlPowSup * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICtrlPowSup * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICtrlPowSup * This,
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
    } ICtrlPowSupVtbl;

    interface ICtrlPowSup
    {
        CONST_VTBL struct ICtrlPowSupVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICtrlPowSup_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICtrlPowSup_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICtrlPowSup_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICtrlPowSup_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICtrlPowSup_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICtrlPowSup_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICtrlPowSup_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ICtrlPowSup_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CtrlPowSup;

#ifdef __cplusplus

class DECLSPEC_UUID("284A89BF-ADA3-4A27-9EA3-0FFC0F401E5D")
CtrlPowSup;
#endif
#endif /* __ITC_GUI_01_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


