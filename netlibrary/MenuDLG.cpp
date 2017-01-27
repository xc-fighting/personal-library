// MenuDLG.cpp : implementation file
//

#include "stdafx.h"
#include "netlibrary.h"
#include "MenuDLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MenuDLG dialog


MenuDLG::MenuDLG(CWnd* pParent /*=NULL*/)
	: CDialog(MenuDLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(MenuDLG)
	password = _T("");
	username = _T("");
	//}}AFX_DATA_INIT
}


void MenuDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(MenuDLG)
	DDX_Text(pDX, PASSWORD_INPUT, password);
	DDX_Text(pDX, USERNAME_INPUT, username);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(MenuDLG, CDialog)
	//{{AFX_MSG_MAP(MenuDLG)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MenuDLG message handlers
