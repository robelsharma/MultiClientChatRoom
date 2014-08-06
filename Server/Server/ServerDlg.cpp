/*
Coded by Robel Sharma
Date: 20-08-2013
If you use in any product please
make sure to write my credits

*/
// ServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include <stdlib.h>
#include "ServerDlg.h"
#include "afxdialogex.h"
//#include <pthread.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CServerDlg dialog




CServerDlg::CServerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CServerDlg::IDD, pParent),
	m_pServer(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_buffer = _T("");
}

void CServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_buffer);
	DDX_Control(pDX, IDC_EDIT2, m_Textbox);
	DDX_Control(pDX, IDC_EDIT1, m_Portbox);
}

BEGIN_MESSAGE_MAP(CServerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT2, &CServerDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDCANCEL, &CServerDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CServerDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CServerDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CServerDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CServerDlg message handlers

BOOL CServerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

void CServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CServerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CServerDlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	
	//UpdateData(FALSE);
	//m_buffer="I am in";
	//UpdateData(FALSE);
}


void CServerDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CServerDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();
	OnBnClickedButton1();
}


void CServerDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	cTh = AfxBeginThread(
    StaticThreadFunc,
    this);
	
	//cTh->m_bAutoDelete = FALSE;
	m_Thread_handle = cTh->m_hThread;
	 
}


void CServerDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CloseHandle(m_Thread_handle);

	//AfxEndThread(0 ,true);
	//DWORD dwCode;  
    //GetExitCodeThread(cTh->m_hThread, &dwCode);  
    //delete cTh; 
	//Sleep(1);
	//m_pServer->ClearServer();
	delete m_pServer;
}

void CServerDlg::ShowServerInfo(string sValue)
{
	CString strLine(sValue.c_str());
	// add CR/LF to text
	//MessageBox(sValue.c_str());
	AppendTextToEditCtrl(m_Textbox, strLine);
	//DoModal();
	//UpdateData(TRUE);
}

void CServerDlg::AppendTextToEditCtrl(CEdit& edit, LPCTSTR pszText)
{
   // get the initial text length
   int nLength = edit.GetWindowTextLength();
   // put the selection at the end of text
   edit.SetSel(nLength, nLength);
   // replace the selection
   edit.ReplaceSel(pszText);
}

UINT __cdecl CServerDlg::StaticThreadFunc(LPVOID pParam)
{
	CServerDlg *pYourClass = reinterpret_cast<CServerDlg*>(pParam);
    UINT retCode = pYourClass->ThreadFunc();

    return retCode;
}

UINT CServerDlg::ThreadFunc()
{ 
    // Do your thing, this thread now has access to all the classes member variables
	CString txtname; 
	GetDlgItemText(IDC_EDIT1, txtname);
	int iPort = _wtoi( txtname.GetString() );

	if(iPort == 0)
	{
		return -1;
	}
	m_pServer = new ServerManager(this);
	m_pServer->StartListening(iPort);
	return 0;
}