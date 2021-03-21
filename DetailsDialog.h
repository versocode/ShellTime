#if !defined(AFX_DETAILSDIALOG_H__44244E75_B5EA_11D2_BD83_00104B4597FC__INCLUDED_)
#define AFX_DETAILSDIALOG_H__44244E75_B5EA_11D2_BD83_00104B4597FC__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DetailsDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDetailsDialog dialog

class CDetailsDialog : public CDialog
{
// Construction
public:
	CDetailsDialog(CWnd* pParent = NULL);   // standard constructor

    void SetUptime(LPCTSTR Uptime) { m_Uptime = Uptime; }
    void SetReboot(LPCTSTR Reboot) { m_Reboot = Reboot; }

// Dialog Data
	//{{AFX_DATA(CDetailsDialog)
	enum { IDD = IDD_DETAILS };
	CString	m_Reboot;
	CString	m_Uptime;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDetailsDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDetailsDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DETAILSDIALOG_H__44244E75_B5EA_11D2_BD83_00104B4597FC__INCLUDED_)
