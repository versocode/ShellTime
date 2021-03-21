// StaticEx.cpp : implementation file
//

#include "stdafx.h"
#include "StaticEx.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define STATIC_TIMER    2001

/////////////////////////////////////////////////////////////////////////////
// CStaticEx

CStaticEx::CStaticEx()
{
    m_Font = new CFont;
    m_HighlightFont = new CFont;

    LOGFONT lf;
    memset(&lf,0,sizeof(LOGFONT));
    SystemParametersInfo(SPI_GETICONTITLELOGFONT,sizeof(LOGFONT),&lf,0);

    m_Font->CreateFontIndirect(&lf);

    lf.lfUnderline = TRUE;
    m_HighlightFont->CreateFontIndirect(&lf);

    m_Highlight = false;

    m_URL = "http://www.geocities.com/~macweb/shelltime/";

    m_Cursor = AfxGetApp()->LoadCursor(IDC_HYPERLINKCURSOR);

    m_Tracking = false;
}

CStaticEx::~CStaticEx()
{
    m_Font->DeleteObject();
    delete m_HighlightFont;
    m_HighlightFont->DeleteObject();
    delete m_Font;
}


BEGIN_MESSAGE_MAP(CStaticEx, CStatic)
	//{{AFX_MSG_MAP(CStaticEx)
	ON_WM_NCHITTEST()
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStaticEx message handlers

UINT CStaticEx::OnNcHitTest(CPoint point) 
{
    m_Highlight = true;
    Invalidate();

    SetTimer(STATIC_TIMER,100,NULL);
    SetCapture();

    ::SetCursor(m_Cursor);
	
	return CStatic::OnNcHitTest(point);
}

void CStaticEx::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

    CRect Area;
    GetClientRect(Area);
    dc.FillSolidRect(Area,GetSysColor(CTLCOLOR_DLG));


    dc.SetBkMode(TRANSPARENT);

    if (m_Highlight)
    {
        dc.SetTextColor(RGB(0,0,255));
        dc.SelectObject(m_HighlightFont);
    }
    else
    {
        dc.SetTextColor(RGB(0,0,0));
        dc.SelectObject(m_Font);
    }

    CString s;
    GetWindowText(s);
    dc.TextOut(0,0,s);
}

void CStaticEx::OnTimer(UINT nIDEvent) 
{
    if (STATIC_TIMER == nIDEvent)
    {
        CPoint pos;
        GetCursorPos(&pos);

        CRect a;
        GetWindowRect(a);

        m_Highlight = a.PtInRect(pos) ? true : false;
        
        if (!m_Highlight)
        {
            Invalidate();
            KillTimer(STATIC_TIMER);
            ReleaseCapture();
        }
    }
	
	CStatic::OnTimer(nIDEvent);
}

void CStaticEx::OnLButtonDown(UINT nFlags, CPoint point) 
{
    m_Tracking = true;
    SetCapture();

	CStatic::OnLButtonDown(nFlags, point);
}

void CStaticEx::OnLButtonUp(UINT nFlags, CPoint point) 
{
    CRect Area;
    GetClientRect(Area);
    if (Area.PtInRect(point))
    {
        ShellExecute(GetSafeHwnd(),NULL,m_URL,NULL,NULL,SW_SHOW);
    }
    ReleaseCapture();

	CStatic::OnLButtonUp(nFlags, point);
}

