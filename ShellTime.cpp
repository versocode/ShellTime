// ShellTime.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ShellTime.h"
#include "ShellTimeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShellTimeApp

BEGIN_MESSAGE_MAP(CShellTimeApp, CWinApp)
	//{{AFX_MSG_MAP(CShellTimeApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
    ON_MESSAGE(WM_NOTIFYMYICON,OnNotifyIcon)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShellTimeApp construction

CShellTimeApp::CShellTimeApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CShellTimeApp object

CShellTimeApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CShellTimeApp initialization

BOOL CShellTimeApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif


    m_Dialog.Create(IDD_SHELLTIME_DIALOG,NULL);
	m_pMainWnd = &m_Dialog;

    InitIcon();

/*	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
*/
	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return TRUE;
}

void CShellTimeApp::InitIcon()
{
    NOTIFYICONDATA tnid;
    memset(&tnid,0,sizeof(NOTIFYICONDATA));

    tnid.cbSize = sizeof(NOTIFYICONDATA); 
    tnid.hWnd = m_pMainWnd->GetSafeHwnd(); 
    tnid.uID = 100; 
    tnid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP; 
    tnid.uCallbackMessage = WM_NOTIFYMYICON; 

    HICON h = LoadIcon(IDI_ICON1);
    tnid.hIcon = h;

    m_tiptext = "ShellTime";

    strcpy(tnid.szTip,m_tiptext);
    Shell_NotifyIcon(NIM_ADD,&tnid);
}


int CShellTimeApp::ExitInstance() 
{
    NOTIFYICONDATA tnid;  
    tnid.cbSize = sizeof(NOTIFYICONDATA);     
    tnid.hWnd = m_pMainWnd->GetSafeHwnd(); 
    tnid.uID = 100;

    Shell_NotifyIcon(NIM_DELETE, &tnid); 

    m_Dialog.DestroyWindow();


    return CWinApp::ExitInstance();
}


LRESULT CShellTimeApp::OnNotifyIcon(WPARAM w,LPARAM l)
{
    return 1;
}
