// RegisterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "netlibrary.h"
#include "RegisterDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// RegisterDlg dialog


RegisterDlg::RegisterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(RegisterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(RegisterDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void RegisterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(RegisterDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(RegisterDlg, CDialog)
	//{{AFX_MSG_MAP(RegisterDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// RegisterDlg message handlers
