; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=RegisterDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "netlibrary.h"

ClassCount=6
Class1=CNetlibraryApp
Class2=CNetlibraryDlg

ResourceCount=5
Resource1=IDR_MAINFRAME
Class3=login_dlg
Resource2=IDD_NETLIBRARY_DIALOG
Class4=MenuDLG
Resource3=IDD_MENU
Class5=RegisterDLG
Resource4="IDD_REGISTER"
Class6=RegisterDlg
Resource5=IDD_register

[CLS:CNetlibraryApp]
Type=0
HeaderFile=netlibrary.h
ImplementationFile=netlibrary.cpp
Filter=N

[CLS:CNetlibraryDlg]
Type=0
HeaderFile=netlibraryDlg.h
ImplementationFile=netlibraryDlg.cpp
Filter=D
LastObject=ENTER_BUTTON
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_NETLIBRARY_DIALOG]
Type=1
Class=CNetlibraryDlg
ControlCount=7
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IP_EDIT,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=PORT_EDIT,edit,1350631552
Control7=ENTER_BUTTON,button,1342242816

[CLS:login_dlg]
Type=0
HeaderFile=login_dlg.h
ImplementationFile=login_dlg.cpp
BaseClass=CDialog
Filter=D
LastObject=login_dlg

[DLG:IDD_MENU]
Type=1
Class=MenuDLG
ControlCount=7
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=USERNAME_INPUT,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=PASSWORD_INPUT,edit,1350631552
Control6=LOGIN_BUTTON,button,1342242816
Control7=REGISTER_BUTTON,button,1342242816

[CLS:MenuDLG]
Type=0
HeaderFile=MenuDLG.h
ImplementationFile=MenuDLG.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=LOGIN_BUTTON

[DLG:"IDD_REGISTER"]
Type=1
Class=?
ControlCount=9
Control1=IDC_STATIC,static,1342308352
Control2=REG_USERNAME,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=REG_PASSWORD,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=REG_PASSWORDCONFIRM,edit,1350631552
Control7=IDC_RADIO_ADMINISTRATER,button,1342177289
Control8=IDC_RADIO_READER,button,1342177289
Control9=REG_CONFIRM_BUTTON,button,1342242816

[DLG:IDD_register]
Type=1
Class=RegisterDlg
ControlCount=9
Control1=IDC_STATIC,static,1342308352
Control2=IDC_reguser,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_regpwd,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_regpwdconfirm,edit,1350631552
Control7=IDC_administrater,button,1342177289
Control8=IDC_RADIO2,button,1342177289
Control9=IDC_regbutton,button,1342242816

[CLS:RegisterDlg]
Type=0
HeaderFile=RegisterDlg.h
ImplementationFile=RegisterDlg.cpp
BaseClass=CDialog
Filter=D

