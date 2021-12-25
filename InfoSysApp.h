// GridCtrlDemo.h : main header file for the GRIDCTRLDEMO application
//

#if !defined(AFX_GRIDCTRLDEMO_H__34B6D7A4_9CDC_11D1_9C11_00A0243D1382__INCLUDED_)
#define AFX_GRIDCTRLDEMO_H__34B6D7A4_9CDC_11D1_9C11_00A0243D1382__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGridCtrlDemoApp:
// See GridCtrlDemo.cpp for the implementation of this class
//

class InfoSysApp : public CWinApp
{
public:
	InfoSysApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(InfoSysApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(InfoSysApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRIDCTRLDEMO_H__34B6D7A4_9CDC_11D1_9C11_00A0243D1382__INCLUDED_)
