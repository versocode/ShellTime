// DetailsDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ShellTime.h"
#include "DetailsDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDetailsDialog dialog


CDetailsDialog::CDetailsDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CDetailsDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDetailsDialog)
	m_Reboot = _T("");
	m_Uptime = _T("");
	//}}AFX_DATA_INIT
}


void CDetailsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDetailsDialog)
	DDX_Text(pDX, IDC_REBOOTEDIT, m_Reboot);
	DDX_Text(pDX, IDC_UPTIMEEDIT, m_Uptime);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDetailsDialog, CDialog)
	//{{AFX_MSG_MAP(CDetailsDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDetailsDialog message handlers
