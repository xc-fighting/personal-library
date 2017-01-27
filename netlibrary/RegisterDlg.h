#if !defined(AFX_REGISTERDLG_H__94FD150C_23C6_486D_A148_A1850D46D822__INCLUDED_)
#define AFX_REGISTERDLG_H__94FD150C_23C6_486D_A148_A1850D46D822__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RegisterDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// RegisterDlg dialog

class RegisterDlg : public CDialog
{
// Construction
public:
	RegisterDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(RegisterDlg)
	enum { IDD = IDD_register };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RegisterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(RegisterDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGISTERDLG_H__94FD150C_23C6_486D_A148_A1850D46D822__INCLUDED_)
