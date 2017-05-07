#include "stdafx.h"
#include "MFCPropertyDialog.h"
#include "PropertyPane.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CPropertyPane::CPropertyPane()
{
}

CPropertyPane::~CPropertyPane()
{
}

BEGIN_MESSAGE_MAP(CPropertyPane, CWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

BOOL CPropertyPane::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

int CPropertyPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	CRect rectDummy;
	m_wndPropList.Create(WS_VISIBLE | WS_CHILD, rectDummy, this, 2);

	return 0;
}

void CPropertyPane::OnPaint() 
{
	CPaintDC dc(this);
}

void CPropertyPane::OnSize(UINT nType, int cx, int cy)
{
	__super::OnSize(nType, cx, cy);

	if( m_wndPropList )
	{
		m_wndPropList.SetWindowPos(NULL,0,0,cx,cy,SWP_NOZORDER);
	}
}

void CPropertyPane::SetPropListFont()
{
	::DeleteObject(m_fntPropList.Detach());

	LOGFONT lf;
	afxGlobalData.fontRegular.GetLogFont(&lf);

	NONCLIENTMETRICS info;
	info.cbSize = sizeof(info);

	afxGlobalData.GetNonClientMetrics(info);

	lf.lfHeight = info.lfMenuFont.lfHeight;
	lf.lfWeight = info.lfMenuFont.lfWeight;
	lf.lfItalic = info.lfMenuFont.lfItalic;

	m_fntPropList.CreateFontIndirect(&lf);

	m_wndPropList.SetFont(&m_fntPropList);
}

void CPropertyPane::InitPropList()
{
	SetPropListFont();

	m_wndPropList.EnableHeaderCtrl(FALSE);
	m_wndPropList.EnableDescriptionArea(FALSE);
	m_wndPropList.SetDescriptionRows(1);
	m_wndPropList.SetVSDotNetLook(TRUE);
	m_wndPropList.MarkModifiedProperties(TRUE);

	m_wndPropList.SetCustomColors(RGB(228, 243, 254), RGB(46, 70, 165), RGB(200, 236, 209), RGB(33, 102, 49), RGB(255, 229, 216), RGB(128, 0, 0), RGB(159, 159, 255));

	CMFCPropertyGridProperty* pGroup = new CMFCPropertyGridProperty(_T("My Property"));
	CMFCPropertyGridProperty* pProp;
	int i;
	WCHAR szPropText[MAX_PATH];
	WCHAR szPropTitle[MAX_PATH];
	for(i = 0; i < 17; i++)
	{
		StringCchPrintf(szPropText,MAX_PATH,L"%d",2001+i);
		StringCchPrintf(szPropTitle,MAX_PATH,L"Item%d",i+1);
		pProp = new CMFCPropertyGridProperty( szPropTitle, (_variant_t) szPropText, L"");
		pGroup->AddSubItem(pProp);
	}

	m_wndPropList.AddProperty(pGroup);
}
