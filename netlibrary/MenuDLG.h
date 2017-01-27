#if !defined(AFX_MENUDLG_H__E2E9704F_9FFD_46FA_AF66_88F32032307E__INCLUDED_)
#define AFX_MENUDLG_H__E2E9704F_9FFD_46FA_AF66_88F32032307E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MenuDLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// MenuDLG dialog

class MenuDLG : public CDialog
{
// Construction
public:
	MenuDLG(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(MenuDLG)
	enum { IDD = IDD_MENU };
	CString	password;
	CString	username;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MenuDLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(MenuDLG)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MENUDLG_H__E2E9704F_9FFD_46FA_AF66_88F32032307E__INCLUDED_)
