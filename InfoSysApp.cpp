// InfoSysApp.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "InfoSysApp.h"
#include "InfoSysDlg.h"
#include <sstream>
#include <fstream>
#include <codecvt>


#/*ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif*/

/////////////////////////////////////////////////////////////////////////////
// InfoSysApp

BEGIN_MESSAGE_MAP(InfoSysApp, CWinApp)
	//{{AFX_MSG_MAP(InfoSysApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGridCtrlDemoApp construction

InfoSysApp::InfoSysApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CGridCtrlDemoApp object

InfoSysApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CGridCtrlDemoApp initialization

BOOL InfoSysApp::InitInstance()
{
	// Standard initialization
#if !defined(_WIN32_WCE) && (_MFC_VER < 0x0700) 
#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
#endif

	std::locale::global(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));


	InfoSysDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
