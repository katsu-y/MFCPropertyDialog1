
// MFCPropertyDialogWindow.h : header file
//

#pragma once

#include "PropertyPane.h"

// CMFCPropertyDialog dialog
class CMFCPropertyDialog : public CDialogEx
{
// Construction
public:
	CMFCPropertyDialog(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCPROPERTYDIALOG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	CPropertyPane m_prop;

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
