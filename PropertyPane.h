#pragma once

class CPropertyPane : public CWnd
{
// Construction
public:
	CPropertyPane();

	CMFCPropertyGridCtrl m_wndPropList;

	void InitPropList();
	void SetPropListFont();
	CFont m_fntPropList;

// Attributes
public:

// Operations
public:
// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CPropertyPane();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
