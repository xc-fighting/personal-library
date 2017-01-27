// netlibrary.h : main header file for the NETLIBRARY application
//

#if !defined(AFX_NETLIBRARY_H__98CC3953_71B3_493C_8464_7C50256F6815__INCLUDED_)
#define AFX_NETLIBRARY_H__98CC3953_71B3_493C_8464_7C50256F6815__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNetlibraryApp:
// See netlibrary.cpp for the implementation of this class
//

class CNetlibraryApp : public CWinApp
{
public:
	CNetlibraryApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetlibraryApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNetlibraryApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETLIBRARY_H__98CC3953_71B3_493C_8464_7C50256F6815__INCLUDED_)
