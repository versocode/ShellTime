// ShellTimeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ShellTime.h"
#include "ShellTimeDlg.h"
#include "detailsdialog.h"
#include "staticex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	CStaticEx	m_HomePageLink;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	//{{AFX_MSG(CAboutDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	DDX_Control(pDX, IDC_HOMEPAGE, m_HomePageLink);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShellTimeDlg dialog

CShellTimeDlg::CShellTimeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShellTimeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShellTimeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
//	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShellTimeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShellTimeDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CShellTimeDlg, CDialog)
	//{{AFX_MSG_MAP(CShellTimeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_TOP_EXIT, OnTopExit)
	ON_COMMAND(ID_TOP_ABOUT, OnTopAbout)
	ON_COMMAND(ID_TOP_DETAILS, OnTopDetails)
	//}}AFX_MSG_MAP
    ON_MESSAGE(WM_NOTIFYMYICON,OnNotifyIcon)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShellTimeDlg message handlers

BOOL CShellTimeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShellTimeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CShellTimeDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CShellTimeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


LRESULT CShellTimeDlg::OnNotifyIcon(WPARAM w,LPARAM l)
{
    if (w != 100)
        return FALSE;

    UINT msg = (UINT)l;

    switch (msg)
    {
        case WM_MOUSEMOVE:
            UpdateTooltip();
            break;

        case WM_RBUTTONDOWN:
            ContextMenu();
            break;

        case WM_LBUTTONDBLCLK:
            OnTopDetails();
            break;
    }

    return TRUE;
}


CTimeSpan CShellTimeDlg::GetUptime()
{
    DWORD t = GetTickCount();

    DWORD seconds = t / 1000;
    DWORD minutes = seconds / 60;
    DWORD hours   = minutes / 60;

    DWORD days    = hours / 24;
    if (days)
        hours   = hours % 24;

    minutes = minutes % 60;

    CTimeSpan sp(days,hours,minutes,0);
    return sp;
}



CString CShellTimeDlg::GetTipText()
{
    DWORD t = GetTickCount();
    CString fmt;
    fmt.LoadString(IDS_TIPTEXT);

    DWORD seconds = t / 1000;
    DWORD minutes = seconds / 60;
    DWORD hours   = minutes / 60;

    DWORD days    = hours / 24;
    if (days)
        hours   = hours % 24;

    //if (days)
        minutes = minutes % 60;


    CString DayString;
    if (days == 1)
        DayString.LoadString(IDS_DAY);
    else
        DayString.LoadString(IDS_DAYS);

    CString HourString;
    if (hours == 1)
        HourString.LoadString(IDS_HOUR);
    else
        HourString.LoadString(IDS_HOURS);

    CString MinString;
    if (minutes == 1)
        MinString.LoadString(IDS_MINUTE);
    else
        MinString.LoadString(IDS_MINUTES);
        
    CString s;
    s.Format(fmt,days,DayString,hours,HourString,minutes,MinString);
    return s;

}


void CShellTimeDlg::UpdateTooltip()
{
    NOTIFYICONDATA tnid;
    memset(&tnid,0,sizeof(NOTIFYICONDATA));
    tnid.cbSize = sizeof(NOTIFYICONDATA); 
    tnid.hWnd = GetSafeHwnd(); 
    tnid.uID = 100; 
    tnid.uFlags = NIF_TIP; 

    strcpy(tnid.szTip,GetTipText());
    Shell_NotifyIcon(NIM_MODIFY,&tnid);
}


void CShellTimeDlg::ContextMenu()
{
    CMenu m;
    m.LoadMenu(IDR_CONTEXT);
    CMenu *pMenu = m.GetSubMenu(0);

    CPoint p;
    GetCursorPos(&p);
    pMenu->TrackPopupMenu(TPM_RIGHTALIGN|TPM_RIGHTBUTTON,p.x,p.y,
                          this);  
}

// context menu handlers
void CShellTimeDlg::OnTopDetails() 
{
    CDetailsDialog dd;
    dd.SetUptime(GetTipText());

    // get uptime and currenttime
    CTimeSpan sp = GetUptime();
    time_t currenttime;
    time(&currenttime);
    CTime t(currenttime);

    // work out difference so we know when last reboot was.
    CTime rt = t - sp;

    CString ss = rt.Format("%A, %B %d, %Y, %H:%M" );

    dd.SetReboot(ss);

    dd.DoModal();
}

void CShellTimeDlg::OnTopExit() 
{
    PostQuitMessage(0);
}

void CShellTimeDlg::OnTopAbout() 
{
    CAboutDlg ad;
    ad.DoModal();
}



BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
