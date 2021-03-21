// ShellTime.h : main header file for the SHELLTIME application
//

#if !defined(AFX_SHELLTIME_H__E2B3F73A_B539_11D2_BD81_00104B4597FC__INCLUDED_)
#define AFX_SHELLTIME_H__E2B3F73A_B539_11D2_BD81_00104B4597FC__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "shelltimedlg.h"

#define WM_NOTIFYMYICON WM_APP + 1


/////////////////////////////////////////////////////////////////////////////
// CShellTimeApp:
// See ShellTime.cpp for the implementation of this class
//

class CShellTimeApp : public CWinApp
{
public:
	CShellTimeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShellTimeApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
    void InitIcon();

protected:
    CString m_tiptext;
    CShellTimeDlg m_Dialog;

	//{{AFX_MSG(CShellTimeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
    LRESULT OnNotifyIcon(WPARAM w,LPARAM l);
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHELLTIME_H__E2B3F73A_B539_11D2_BD81_00104B4597FC__INCLUDED_)
