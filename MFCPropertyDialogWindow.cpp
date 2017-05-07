// MFCPropertyDialogWindow.cpp : implementation file
//

#include "stdafx.h"
#include "MFCPropertyDialog.h"
#include "MFCPropertyDialogWindow.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCPropertyDialog dialog

CMFCPropertyDialog::CMFCPropertyDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCPropertyDialog::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCPropertyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCPropertyDialog, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()

// CMFCPropertyDialog message handlers

BOOL CMFCPropertyDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_prop.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW, 
			CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL);

	m_prop.InitPropList();

	CWnd *pPlaceHolder = GetDlgItem( IDC_PLACE_HOLDER );
	CRect rc;
	pPlaceHolder->GetWindowRect(&rc);
	GetDesktopWindow()->MapWindowPoints(this,&rc);

	m_prop.SetWindowPos(pPlaceHolder,rc.left,rc.top,rc.Width(),rc.Height(),0);

	pPlaceHolder->DestroyWindow();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCPropertyDialog::OnPaint()
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
HCURSOR CMFCPropertyDialog::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

