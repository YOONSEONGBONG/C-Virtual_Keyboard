
// Virtural_KeyboardDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "Virtural_Keyboard.h"
#include "Virtural_KeyboardDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

const int BASE_CODE = 0xac00;

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{

public:
	CAboutDlg();

	
// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CVirtural_KeyboardDlg 대화 상자



CVirtural_KeyboardDlg::CVirtural_KeyboardDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CVirtural_KeyboardDlg::IDD, pParent)
	, m_Edit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVirtural_KeyboardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Edit);
	DDX_Control(pDX, IDC_BUTTON_0, btn_0);
	DDX_Control(pDX, IDC_CHECK_CAPSTATE, is_check_caps);
	DDX_Control(pDX, IDC_BUTTON_FPU, btn_fpu);
	DDX_Control(pDX, IDC_BUTTON_1, btn_1);
	DDX_Control(pDX, IDC_BUTTON_2, btn_2);
	DDX_Control(pDX, IDC_BUTTON_3, btn_3);
	DDX_Control(pDX, IDC_BUTTON_4, btn_4);
	DDX_Control(pDX, IDC_BUTTON_5, btn_5);
	DDX_Control(pDX, IDC_BUTTON_6, btn_6);
	DDX_Control(pDX, IDC_BUTTON_7, btn_7);
	DDX_Control(pDX, IDC_BUTTON_8, btn_8);
	DDX_Control(pDX, IDC_BUTTON_9, btn_9);
	DDX_Control(pDX, IDC_BUTTON_DASH, btn_dash);
	DDX_Control(pDX, IDC_BUTTON_EQUAL, btn_equal);
	DDX_Control(pDX, IDC_BUTTON_BACKSLUSH, btn_backslush);
	DDX_Control(pDX, IDC_BUTTON_BACKSPACE, btn_backspace);
	DDX_Control(pDX, IDC_BUTTON_Q, btn_q);
	DDX_Control(pDX, IDC_BUTTON_W, btn_w);
	DDX_Control(pDX, IDC_BUTTON_E, btn_e);
	DDX_Control(pDX, IDC_BUTTON_R, btn_r);
	DDX_Control(pDX, IDC_BUTTON_T, btn_t);
	DDX_Control(pDX, IDC_BUTTON_Y, btn_y);
	DDX_Control(pDX, IDC_BUTTON_U, btn_u);
	DDX_Control(pDX, IDC_BUTTON_I, btn_i);
	DDX_Control(pDX, IDC_BUTTON_O, btn_o);
	DDX_Control(pDX, IDC_BUTTON_P, btn_p);
	DDX_Control(pDX, IDC_BUTTON_PREB, btn_preb);
	DDX_Control(pDX, IDC_BUTTON_POSTB, btn_postb);
	DDX_Control(pDX, IDC_BUTTON_A, btn_a);
	DDX_Control(pDX, IDC_BUTTON_S, btn_s);
	DDX_Control(pDX, IDC_BUTTON_D, btn_d);
	DDX_Control(pDX, IDC_BUTTON_F, btn_f);
	DDX_Control(pDX, IDC_BUTTON_G, btn_g);
	DDX_Control(pDX, IDC_BUTTON_H, btn_h);
	DDX_Control(pDX, IDC_BUTTON_J, btn_j);
	DDX_Control(pDX, IDC_BUTTON_K, btn_k);
	DDX_Control(pDX, IDC_BUTTON_L, btn_l);
	DDX_Control(pDX, IDC_BUTTON_SEMI, btn_semi);
	DDX_Control(pDX, IDC_BUTTON_UPPER, btn_upper);
	DDX_Control(pDX, IDC_BUTTON_Z, btn_z);
	DDX_Control(pDX, IDC_BUTTON_X, btn_x);
	DDX_Control(pDX, IDC_BUTTON_C, btn_c);
	DDX_Control(pDX, IDC_BUTTON_V, btn_v);
	DDX_Control(pDX, IDC_BUTTON_B, btn_b);
	DDX_Control(pDX, IDC_BUTTON_N, btn_n);
	DDX_Control(pDX, IDC_BUTTON_M, btn_m);
	DDX_Control(pDX, IDC_BUTTON_COMMA, btn_comma);
	DDX_Control(pDX, IDC_BUTTON_DOT, btn_dot);
	DDX_Control(pDX, IDC_BUTTON_SlUSH, btn_slush);
	DDX_Control(pDX, IDC_CHECK_SHIFT, is_check_shift);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}

BEGIN_MESSAGE_MAP(CVirtural_KeyboardDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ESC, &CVirtural_KeyboardDlg::OnBnClickedButtonEsc)
	ON_BN_CLICKED(IDC_CHECK_CAPSTATE, &CVirtural_KeyboardDlg::OnBnClickedCheckCapstate)
	ON_BN_CLICKED(IDC_CHECK_SHIFT, &CVirtural_KeyboardDlg::OnBnClickedCheckShift)
	ON_BN_CLICKED(IDC_BUTTON_F1, &CVirtural_KeyboardDlg::OnBnClickedButtonF1)
	ON_BN_CLICKED(IDC_BUTTON_F2, &CVirtural_KeyboardDlg::OnBnClickedButtonF2)
	ON_BN_CLICKED(IDC_BUTTON_F3, &CVirtural_KeyboardDlg::OnBnClickedButtonF3)
	ON_BN_CLICKED(IDC_BUTTON_F4, &CVirtural_KeyboardDlg::OnBnClickedButtonF4)
	ON_BN_CLICKED(IDC_BUTTON_F5, &CVirtural_KeyboardDlg::OnBnClickedButtonF5)
	ON_BN_CLICKED(IDC_BUTTON_F6, &CVirtural_KeyboardDlg::OnBnClickedButtonF6)
	ON_BN_CLICKED(IDC_BUTTON_F7, &CVirtural_KeyboardDlg::OnBnClickedButtonF7)
	ON_BN_CLICKED(IDC_BUTTON_F8, &CVirtural_KeyboardDlg::OnBnClickedButtonF8)
	ON_BN_CLICKED(IDC_BUTTON_F9, &CVirtural_KeyboardDlg::OnBnClickedButtonF9)
	ON_BN_CLICKED(IDC_BUTTON_F10, &CVirtural_KeyboardDlg::OnBnClickedButtonF10)
	ON_BN_CLICKED(IDC_BUTTON_F11, &CVirtural_KeyboardDlg::OnBnClickedButtonF11)
	ON_BN_CLICKED(IDC_BUTTON_F12, &CVirtural_KeyboardDlg::OnBnClickedButtonF12)
	ON_BN_CLICKED(IDC_BUTTON_FPU, &CVirtural_KeyboardDlg::OnBnClickedButtonFpu)
	ON_BN_CLICKED(IDC_BUTTON_1, &CVirtural_KeyboardDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &CVirtural_KeyboardDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CVirtural_KeyboardDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CVirtural_KeyboardDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CVirtural_KeyboardDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CVirtural_KeyboardDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CVirtural_KeyboardDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CVirtural_KeyboardDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CVirtural_KeyboardDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_0, &CVirtural_KeyboardDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_DASH, &CVirtural_KeyboardDlg::OnBnClickedButtonDash)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &CVirtural_KeyboardDlg::OnBnClickedButtonEqual)
	ON_BN_CLICKED(IDC_BUTTON_BACKSLUSH, &CVirtural_KeyboardDlg::OnBnClickedButtonBackslush)
	ON_BN_CLICKED(IDC_BUTTON_BACKSPACE, &CVirtural_KeyboardDlg::OnBnClickedButtonBackspace)
	ON_BN_CLICKED(IDC_BUTTON_TAB, &CVirtural_KeyboardDlg::OnBnClickedButtonTab)
	ON_BN_CLICKED(IDC_BUTTON_Q, &CVirtural_KeyboardDlg::OnBnClickedButtonQ)
	ON_BN_CLICKED(IDC_BUTTON_W, &CVirtural_KeyboardDlg::OnBnClickedButtonW)
	ON_BN_CLICKED(IDC_BUTTON_E, &CVirtural_KeyboardDlg::OnBnClickedButtonE)
	ON_BN_CLICKED(IDC_BUTTON_R, &CVirtural_KeyboardDlg::OnBnClickedButtonR)
	ON_BN_CLICKED(IDC_BUTTON_T, &CVirtural_KeyboardDlg::OnBnClickedButtonT)
	ON_BN_CLICKED(IDC_BUTTON_Y, &CVirtural_KeyboardDlg::OnBnClickedButtonY)
	ON_BN_CLICKED(IDC_BUTTON_U, &CVirtural_KeyboardDlg::OnBnClickedButtonU)
	ON_BN_CLICKED(IDC_BUTTON_I, &CVirtural_KeyboardDlg::OnBnClickedButtonI)
	ON_BN_CLICKED(IDC_BUTTON_O, &CVirtural_KeyboardDlg::OnBnClickedButtonO)
	ON_BN_CLICKED(IDC_BUTTON_P, &CVirtural_KeyboardDlg::OnBnClickedButtonP)
	ON_BN_CLICKED(IDC_BUTTON_PREB, &CVirtural_KeyboardDlg::OnBnClickedButtonPreb)
	ON_BN_CLICKED(IDC_BUTTON_POSTB, &CVirtural_KeyboardDlg::OnBnClickedButtonPostb)
	ON_BN_CLICKED(IDC_BUTTON_CAPS, &CVirtural_KeyboardDlg::OnBnClickedButtonCaps)
	ON_BN_CLICKED(IDC_BUTTON_A, &CVirtural_KeyboardDlg::OnBnClickedButtonA)
	ON_BN_CLICKED(IDC_BUTTON_S, &CVirtural_KeyboardDlg::OnBnClickedButtonS)
	ON_BN_CLICKED(IDC_BUTTON_D, &CVirtural_KeyboardDlg::OnBnClickedButtonD)
	ON_BN_CLICKED(IDC_BUTTON_F, &CVirtural_KeyboardDlg::OnBnClickedButtonF)
	ON_BN_CLICKED(IDC_BUTTON_G, &CVirtural_KeyboardDlg::OnBnClickedButtonG)
	ON_BN_CLICKED(IDC_BUTTON_H, &CVirtural_KeyboardDlg::OnBnClickedButtonH)
	ON_BN_CLICKED(IDC_BUTTON_J, &CVirtural_KeyboardDlg::OnBnClickedButtonJ)
	ON_BN_CLICKED(IDC_BUTTON_K, &CVirtural_KeyboardDlg::OnBnClickedButtonK)
	ON_BN_CLICKED(IDC_BUTTON_L, &CVirtural_KeyboardDlg::OnBnClickedButtonL)
	ON_BN_CLICKED(IDC_BUTTON_SEMI, &CVirtural_KeyboardDlg::OnBnClickedButtonSemi)
	ON_BN_CLICKED(IDC_BUTTON_UPPER, &CVirtural_KeyboardDlg::OnBnClickedButtonUpper)
	ON_BN_CLICKED(IDC_BUTTON_SHIFT, &CVirtural_KeyboardDlg::OnBnClickedButtonShift)
	ON_BN_CLICKED(IDC_BUTTON_Z, &CVirtural_KeyboardDlg::OnBnClickedButtonZ)
	ON_BN_CLICKED(IDC_BUTTON_X, &CVirtural_KeyboardDlg::OnBnClickedButtonX)
	ON_BN_CLICKED(IDC_BUTTON_C, &CVirtural_KeyboardDlg::OnBnClickedButtonC)
	ON_BN_CLICKED(IDC_BUTTON_V, &CVirtural_KeyboardDlg::OnBnClickedButtonV)
	ON_BN_CLICKED(IDC_BUTTON_B, &CVirtural_KeyboardDlg::OnBnClickedButtonB)
	ON_BN_CLICKED(IDC_BUTTON_N, &CVirtural_KeyboardDlg::OnBnClickedButtonN)
	ON_BN_CLICKED(IDC_BUTTON_M, &CVirtural_KeyboardDlg::OnBnClickedButtonM)
	ON_BN_CLICKED(IDC_BUTTON_COMMA, &CVirtural_KeyboardDlg::OnBnClickedButtonComma)
	ON_BN_CLICKED(IDC_BUTTON_DOT, &CVirtural_KeyboardDlg::OnBnClickedButtonDot)
	ON_BN_CLICKED(IDC_BUTTON_SlUSH, &CVirtural_KeyboardDlg::OnBnClickedButtonSlush)
	ON_BN_CLICKED(IDC_BUTTON_CTRL, &CVirtural_KeyboardDlg::OnBnClickedButtonCtrl)
	ON_BN_CLICKED(IDC_BUTTON_ALT, &CVirtural_KeyboardDlg::OnBnClickedButtonAlt)
	ON_BN_CLICKED(IDC_BUTTON_SPACE, &CVirtural_KeyboardDlg::OnBnClickedButtonSpace)
	ON_BN_CLICKED(IDC_BUTTON_TOGGLE_IME, &CVirtural_KeyboardDlg::OnBnClickedButtonToggleIme)
	ON_BN_CLICKED(IDC_BUTTON_ENTER, &CVirtural_KeyboardDlg::OnBnClickedButtonEnter)
	ON_BN_CLICKED(IDC_BUTTON_delete, &CVirtural_KeyboardDlg::OnBnClickedButtondelete)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CVirtural_KeyboardDlg::OnBnClickedButtonClear)
END_MESSAGE_MAP()


// CVirtural_KeyboardDlg 메시지 처리기

BOOL CVirtural_KeyboardDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CVirtural_KeyboardDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CVirtural_KeyboardDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CVirtural_KeyboardDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CVirtural_KeyboardDlg::AppendText(int nCode)
{
	// 문자열 입력
	m_automataKr.SetKeyCode(nCode);

	CString strText = m_automataKr.completeText;
	
	if (m_automataKr.ingWord != NULL)
	{
		strText += m_automataKr.ingWord;
	}
	
	SetDlgItemText(IDC_EDIT1, strText);

	// Edit Focus 처리
	CEdit * pEdit = ((CEdit*)GetDlgItem(IDC_EDIT1));
	pEdit->SetSel(pEdit->GetWindowTextLength(), pEdit->GetWindowTextLength());
	pEdit->SetFocus();
}
//void CVirtural_KeyboardDlg::addDigit(CString digit)
//{
//	UpdateData(TRUE);
//		m_Edit += digit;
//		m_edit.SetSel(0, -1);
//		m_edit.ReplaceSel(m_Edit);
//		m_edit.SetFocus();
//		//AppendText(-3);
//	UpdateData(FALSE);
//}

void CVirtural_KeyboardDlg::signChange(bool check)
{
	if (is_ko == true)
	{
		if (check == true)
		{
			btn_w.SetWindowText(L"ㅉ");		btn_e.SetWindowText(L"ㄸ");			btn_r.SetWindowText(L"ㄲ");
			btn_t.SetWindowText(L"ㅆ");		btn_o.SetWindowText(L"ㅒ");			btn_p.SetWindowText(L"ㅖ");
			btn_q.SetWindowText(L"ㅃ");
		}
		else
		{
			btn_w.SetWindowText(L"ㅈ");		btn_e.SetWindowText(L"ㄷ");			btn_r.SetWindowText(L"ㄱ");
			btn_t.SetWindowText(L"ㅅ");		btn_y.SetWindowText(L"ㅛ");			btn_u.SetWindowText(L"ㅕ");
			btn_i.SetWindowText(L"ㅑ");		btn_o.SetWindowText(L"ㅐ");			btn_p.SetWindowText(L"ㅔ");
			btn_a.SetWindowText(L"ㅁ");		btn_s.SetWindowText(L"ㄴ");			btn_d.SetWindowText(L"ㅇ");
			btn_g.SetWindowText(L"ㅎ");		btn_h.SetWindowText(L"ㅗ");			btn_j.SetWindowText(L"ㅓ");
			btn_k.SetWindowText(L"ㅏ");		btn_l.SetWindowText(L"ㅣ");			btn_f.SetWindowText(L"ㄹ");
			btn_z.SetWindowText(L"ㅋ");		btn_x.SetWindowText(L"ㅌ");			btn_n.SetWindowText(L"ㅜ");
			btn_c.SetWindowText(L"ㅊ");		btn_v.SetWindowText(L"ㅍ");			btn_b.SetWindowText(L"ㅠ");
			btn_m.SetWindowText(L"ㅡ");		btn_q.SetWindowText(L"ㅂ");
		}
	}
	else
	{
		if (check == true)
		{
			btn_w.SetWindowText(L"W");		btn_e.SetWindowText(L"E");			btn_r.SetWindowText(L"R");
			btn_t.SetWindowText(L"T");		btn_y.SetWindowText(L"Y");			btn_u.SetWindowText(L"U");
			btn_i.SetWindowText(L"I");		btn_o.SetWindowText(L"O");			btn_p.SetWindowText(L"P");
			btn_a.SetWindowText(L"A");		btn_s.SetWindowText(L"S");			btn_d.SetWindowText(L"D");
			btn_g.SetWindowText(L"G");		btn_h.SetWindowText(L"H");			btn_j.SetWindowText(L"J");
			btn_k.SetWindowText(L"K");		btn_l.SetWindowText(L"L");			btn_f.SetWindowText(L"F");
			btn_z.SetWindowText(L"Z");		btn_x.SetWindowText(L"X");			btn_n.SetWindowText(L"N");
			btn_c.SetWindowText(L"C");		btn_v.SetWindowText(L"V");			btn_b.SetWindowText(L"B");
			btn_m.SetWindowText(L"M");		btn_q.SetWindowText(L"Q");
			
		}
		else
		{
			btn_w.SetWindowText(L"w");		btn_e.SetWindowText(L"e");			btn_r.SetWindowText(L"r");
			btn_t.SetWindowText(L"t");		btn_y.SetWindowText(L"y");			btn_u.SetWindowText(L"u");
			btn_i.SetWindowText(L"i");		btn_o.SetWindowText(L"o");			btn_p.SetWindowText(L"p");
			btn_a.SetWindowText(L"a");		btn_z.SetWindowText(L"z");			btn_x.SetWindowText(L"x");
			btn_s.SetWindowText(L"s");		btn_d.SetWindowText(L"d");			btn_f.SetWindowText(L"f");
			btn_g.SetWindowText(L"g");		btn_h.SetWindowText(L"h");			btn_j.SetWindowText(L"j");
			btn_k.SetWindowText(L"k");		btn_l.SetWindowText(L"l");			btn_m.SetWindowText(L"m");
			btn_c.SetWindowText(L"c");		btn_v.SetWindowText(L"v");			btn_b.SetWindowText(L"b");
			btn_n.SetWindowText(L"n");		btn_q.SetWindowText(L"q");
		
		}
	}
	
}

void CVirtural_KeyboardDlg::OnBnClickedCheckCapstate()
{
	if (is_check_caps.GetCheck() == 1)
	{
		signChange(true);
	}
	else
	{
		signChange(false);
	}
}

void CVirtural_KeyboardDlg::OnBnClickedCheckShift()
{
	
		if (is_check_shift.GetCheck() == 1)
		{
			btn_fpu.SetWindowText(L"~");    btn_1.SetWindowText(L"!");			btn_2.SetWindowText(L"@");
			btn_3.SetWindowText(L"#");      btn_4.SetWindowText(L"$");			btn_5.SetWindowText(L"%");
			btn_6.SetWindowText(L"^");	    btn_7.SetWindowText(L"&&");			btn_8.SetWindowText(L"*");
			btn_9.SetWindowText(L"(");      btn_0.SetWindowText(L")");          btn_dash.SetWindowText(L"_");
			btn_equal.SetWindowText(L"+");  btn_backslush.SetWindowText(L"|");  btn_upper.SetWindowText(L"\"");
			btn_comma.SetWindowText(L"<");	btn_preb.SetWindowText(L"{");		btn_postb.SetWindowText(L"}");
			btn_dot.SetWindowText(L">");	btn_slush.SetWindowText(L"?");
			btn_semi.SetWindowText(L":");
		}
		else
		{
			btn_fpu.SetWindowText(L"`");    btn_1.SetWindowText(L"1");          btn_2.SetWindowText(L"2");
			btn_3.SetWindowText(L"3");		btn_4.SetWindowText(L"4");			btn_5.SetWindowText(L"5");
			btn_6.SetWindowText(L"6");		btn_7.SetWindowText(L"7");			btn_8.SetWindowText(L"8");
			btn_9.SetWindowText(L"9");		btn_0.SetWindowText(L"0");			btn_dash.SetWindowText(L"-");
			btn_equal.SetWindowText(L"=");  btn_backslush.SetWindowText(L"\\"); btn_comma.SetWindowText(L",");
			btn_dot.SetWindowText(L".");	btn_slush.SetWindowText(L"/");		btn_preb.SetWindowText(L"[");
			btn_postb.SetWindowText(L"]");	btn_upper.SetWindowText(L"'");		btn_semi.SetWindowText(L";");	
		}
	
		if (is_check_shift.GetCheck() == 1)
		{
			signChange(true);
		}
		else
		{
			signChange(false);
		}
	
}

void CVirtural_KeyboardDlg::OnBnClickedButtonEsc()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CVirtural_KeyboardDlg::OnBnClickedButtonF1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CVirtural_KeyboardDlg::OnBnClickedButtonF2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CVirtural_KeyboardDlg::OnBnClickedButtonF3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CVirtural_KeyboardDlg::OnBnClickedButtonF4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CVirtural_KeyboardDlg::OnBnClickedButtonF5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CVirtural_KeyboardDlg::OnBnClickedButtonF6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CVirtural_KeyboardDlg::OnBnClickedButtonF7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CVirtural_KeyboardDlg::OnBnClickedButtonF8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CVirtural_KeyboardDlg::OnBnClickedButtonF9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CVirtural_KeyboardDlg::OnBnClickedButtonF10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CVirtural_KeyboardDlg::OnBnClickedButtonF11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CVirtural_KeyboardDlg::OnBnClickedButtonF12()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CVirtural_KeyboardDlg::OnBnClickedButtonFpu()
{
	btn_fpu.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButton1()
{
	btn_1.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButton2()
{
	btn_2.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButton3()
{
	btn_3.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButton4()
{
	btn_5.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButton5()
{
	btn_5.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButton6()
{
	btn_6.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButton7()
{
	btn_7.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButton8()
{
	btn_8.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButton9()
{
	btn_9.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButton0()
{
	btn_0.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonDash()
{
	btn_dash.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonEqual()
{	
	
	btn_equal.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonBackslush()
{
	btn_backslush.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonBackspace()
{	
		AppendText(-3);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonTab()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CVirtural_KeyboardDlg::OnBnClickedButtonQ()
{
	btn_q.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);		
}


void CVirtural_KeyboardDlg::OnBnClickedButtonW()
{
	btn_w.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonE()
{
	btn_e.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonR()
{
	btn_r.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonT()
{
	btn_t.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonY()
{
	btn_y.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonU()
{
	btn_u.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonI()
{
	btn_i.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
	
}


void CVirtural_KeyboardDlg::OnBnClickedButtonO()
{
	btn_o.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonP()
{
	btn_p.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonPreb()
{
	btn_preb.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}

void CVirtural_KeyboardDlg::OnBnClickedButtonPostb()
{
	btn_postb.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonCaps()
{	
	if (is_check_caps.GetCheck() == 1)
	{
		is_check_caps.SetCheck(0);
	}
	else{
		is_check_caps.SetCheck(1);
	}
	OnBnClickedCheckCapstate();
}


void CVirtural_KeyboardDlg::OnBnClickedButtonA()
{
	btn_a.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonS()
{
	btn_s.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonD()
{
	btn_d.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonF()
{
	btn_f.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonG()
{
	btn_g.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonH()
{
	btn_h.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonJ()
{
	btn_j.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonK()
{
	btn_k.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonL()
{
	btn_l.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonSemi()
{
	btn_semi.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonUpper()
{
	btn_upper.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonShift()
{
	if (is_check_shift.GetCheck() == 1)
	{
		is_check_shift.SetCheck(0);
	}
	else{
		is_check_shift.SetCheck(1);
	}
	OnBnClickedCheckShift();
		
}

void CVirtural_KeyboardDlg::OnBnClickedButtonZ()
{
	btn_z.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonX()
{
	btn_x.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonC()
{
	btn_c.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonV()
{
	btn_v.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonB()
{
	btn_b.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonN()
{
	btn_n.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonM()
{
	btn_m.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonComma()
{
	btn_comma.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonDot()
{
	btn_dot.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonSlush()
{
	btn_slush.GetWindowText(digit);
	AppendText(m_automataKr.GetSoundTableValue(digit));
	//addDigit(digit);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonCtrl()
{
	
}


void CVirtural_KeyboardDlg::OnBnClickedButtonAlt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CVirtural_KeyboardDlg::OnBnClickedButtonSpace()
{
	AppendText(-1);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonToggleIme()
{
	if (is_ko == true)
	{
		is_ko = false;	
	}
	else
	{
		is_ko = true;
	}
	signChange(false);
}


void CVirtural_KeyboardDlg::OnBnClickedButtonEnter()
{
	CString str;
	GetDlgItemText(IDC_EDIT1,str);
	m_list.AddString(str);
	m_automataKr.Clear();
	SetDlgItemText(IDC_EDIT1, L"");
	UpdateData(FALSE);
	
}


void CVirtural_KeyboardDlg::OnBnClickedButtondelete()
{
	int sel = m_list.GetCurSel();
	if (sel >= 0)
	{
		m_list.DeleteString(sel);
	}
	else
	{
		m_list.DeleteString(0);
	}

}


void CVirtural_KeyboardDlg::OnBnClickedButtonClear()
{
	CString str;
	m_automataKr.Clear();
	SetDlgItemText(IDC_EDIT1, L"");
	UpdateData(FALSE);
}
