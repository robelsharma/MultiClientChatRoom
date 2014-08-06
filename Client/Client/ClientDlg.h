
// ClientDlg.h : header file
//
/*
Coded by Robel Sharma
Date: 20-08-2013
If you use in any product please
make sure to write my credits

*/

#pragma once
#include "ClientCon.h"
#include <Windows.h>
#include "resource.h"

// CClientDlg dialog
class CClientDlg : public CDialogEx
{
// Construction
public:
	CClientDlg(CWnd* pParent = NULL);	// standard constructor
	void ShowServerInfo(string sValue);

// Dialog Data
enum { IDD = IDD_CLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();

	ClientCon *m_pClient;
	static UINT __cdecl StaticThreadFunc(LPVOID pParam);
    UINT ThreadFunc();
	void AppendTextToEditCtrl(CEdit& edit, LPCTSTR pszText);
	CEdit m_Portbox;

private:
	HANDLE m_Thread_handle;
	CWinThread *cTh;

public:
	CEdit m_Textbox;
	afx_msg void OnBnClickedButton3();
};
