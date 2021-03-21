#if !defined(AFX_STATICEX_H__43A97DB2_B9B8_11D2_BD86_00104B4597FC__INCLUDED_)
#define AFX_STATICEX_H__43A97DB2_B9B8_11D2_BD86_00104B4597FC__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// StaticEx.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStaticEx window

class CStaticEx : public CStatic
{
public:
	CStaticEx();
	virtual ~CStaticEx();

    void SetURL(LPCTSTR URL) { m_URL = URL; }

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStaticEx)
	//}}AFX_VIRTUAL


	// Generated message map functions
protected:
    CFont*          m_Font;
    CFont*          m_HighlightFont;
    bool            m_Highlight;
    CString         m_URL;
    HCURSOR         m_Cursor;
    bool            m_Tracking;

	//{{AFX_MSG(CStaticEx)
	afx_msg UINT OnNcHitTest(CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATICEX_H__43A97DB2_B9B8_11D2_BD86_00104B4597FC__INCLUDED_)
