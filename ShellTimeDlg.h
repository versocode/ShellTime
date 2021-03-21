// ShellTimeDlg.h : header file
//

#if !defined(AFX_SHELLTIMEDLG_H__E2B3F73C_B539_11D2_BD81_00104B4597FC__INCLUDED_)
#define AFX_SHELLTIMEDLG_H__E2B3F73C_B539_11D2_BD81_00104B4597FC__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CShellTimeDlg dialog

class CShellTimeDlg : public CDialog
{
// Construction
public:
	CShellTimeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CShellTimeDlg)
	enum { IDD = IDD_SHELLTIME_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShellTimeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

    CString GetTipText();
    CTimeSpan GetUptime();

    
    // Implementation
protected:
    void UpdateTooltip();
    void ContextMenu();

	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CShellTimeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTopExit();
	afx_msg void OnTopAbout();
	afx_msg void OnTopDetails();
	//}}AFX_MSG
    LRESULT OnNotifyIcon(WPARAM w,LPARAM l);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHELLTIMEDLG_H__E2B3F73C_B539_11D2_BD81_00104B4597FC__INCLUDED_)
