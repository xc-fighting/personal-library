// netlibraryDlg.h : header file
//

#if !defined(AFX_NETLIBRARYDLG_H__3B70AC34_E432_42BD_BED6_141F04C85943__INCLUDED_)
#define AFX_NETLIBRARYDLG_H__3B70AC34_E432_42BD_BED6_141F04C85943__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNetlibraryDlg dialog

class CNetlibraryDlg : public CDialog
{
// Construction
public:
	CNetlibraryDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNetlibraryDlg)
	enum { IDD = IDD_NETLIBRARY_DIALOG };
	CString	ipaddr;
	int		portnumber;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetlibraryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNetlibraryDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnEnter();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETLIBRARYDLG_H__3B70AC34_E432_42BD_BED6_141F04C85943__INCLUDED_)
