
// ServerDlg.h : header file
//
/*
Coded by Robel Sharma
Date: 20-08-2013
If you use in any product please
make sure to write my credits

*/

#pragma once
#include "ServerManager.h"
#include <Windows.h>

// CServerDlg dialog
class CServerDlg : public CDialogEx
{
// Construction
public:
	CServerDlg(CWnd* pParent = NULL);	// standard constructor
	void ShowServerInfo(string sValue);
// Dialog Data
	enum { IDD = IDD_SERVER_DIALOG };

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
	afx_msg void OnEnChangeEdit2();
	CString m_buffer;
	CEdit m_Textbox;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();

	ServerManager *m_pServer;
	static UINT __cdecl StaticThreadFunc(LPVOID pParam);
    UINT ThreadFunc();
	void AppendTextToEditCtrl(CEdit& edit, LPCTSTR pszText);
	CEdit m_Portbox;

private:
	HANDLE m_Thread_handle;
	CWinThread *cTh;
};
