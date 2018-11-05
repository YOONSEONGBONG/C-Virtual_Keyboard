
// Virtural_KeyboardDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"
#include "src/AutomataKR.h"
#include <string>

using namespace std;

// CVirtural_KeyboardDlg 대화 상자
class CVirtural_KeyboardDlg : public CDialogEx
{
// 생성입니다.
public:
	CVirtural_KeyboardDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG1};

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonEsc();
	afx_msg void OnBnClickedCheckCapstate();
	afx_msg void OnBnClickedCheckShift();
	afx_msg void OnBnClickedButtonF1();
	afx_msg void OnBnClickedButtonF2();
	afx_msg void OnBnClickedButtonF3();
	afx_msg void OnBnClickedButtonF4();
	afx_msg void OnBnClickedButtonF5();
	afx_msg void OnBnClickedButtonF6();
	afx_msg void OnBnClickedButtonF7();
	afx_msg void OnBnClickedButtonF8();
	afx_msg void OnBnClickedButtonF9();
	afx_msg void OnBnClickedButtonF10();
	afx_msg void OnBnClickedButtonF11();
	afx_msg void OnBnClickedButtonF12();
	afx_msg void OnBnClickedButtonFpu();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButtonDash();
	afx_msg void OnBnClickedButtonEqual();
	afx_msg void OnBnClickedButtonBackslush();
	afx_msg void OnBnClickedButtonBackspace();
	afx_msg void OnBnClickedButtonTab();
	afx_msg void OnBnClickedButtonQ();
	afx_msg void OnBnClickedButtonW();
	afx_msg void OnBnClickedButtonE();
	afx_msg void OnBnClickedButtonR();
	afx_msg void OnBnClickedButtonT();
	afx_msg void OnBnClickedButtonY();
	afx_msg void OnBnClickedButtonU();
	afx_msg void OnBnClickedButtonI();
	afx_msg void OnBnClickedButtonO();
	afx_msg void OnBnClickedButtonP();
	afx_msg void OnBnClickedButtonPreb();
	afx_msg void OnBnClickedButtonPostb();
	afx_msg void OnBnClickedButtonCaps();
	afx_msg void OnBnClickedButtonA();
	afx_msg void OnBnClickedButtonS();
	afx_msg void OnBnClickedButtonD();
	afx_msg void OnBnClickedButtonF();
	afx_msg void OnBnClickedButtonG();
	afx_msg void OnBnClickedButtonH();
	afx_msg void OnBnClickedButtonJ();
	afx_msg void OnBnClickedButtonK();
	afx_msg void OnBnClickedButtonL();
	afx_msg void OnBnClickedButtonSemi();
	afx_msg void OnBnClickedButtonUpper();
	afx_msg void OnBnClickedButtonShift();
	afx_msg void OnBnClickedButtonZ();
	afx_msg void OnBnClickedButtonX();
	afx_msg void OnBnClickedButtonC();
	afx_msg void OnBnClickedButtonV();
	afx_msg void OnBnClickedButtonB();
	afx_msg void OnBnClickedButtonN();
	afx_msg void OnBnClickedButtonM();
	afx_msg void OnBnClickedButtonComma();
	afx_msg void OnBnClickedButtonDot();
	afx_msg void OnBnClickedButtonSlush();
	afx_msg void OnBnClickedButtonCtrl();
	afx_msg void OnBnClickedButtonAlt();
	afx_msg void OnBnClickedButtonSpace();
	afx_msg void OnBnClickedButtonToggleIme();
	afx_msg void OnBnClickedButtonEnter();
	afx_msg void OnBnClickedButtondelete();
	
	void AppendText(int nCode);	// 문자추가
	void addDigit(CString digit);
	void CVirtural_KeyboardDlg::signChange(bool check);
	void CVirtural_KeyboardDlg::checkCaps();
	void CVirtural_KeyboardDlg::checkShift();
	
	CAutomataKR m_automataKr;	// Automata
	bool is_ko=true;
	CString m_Edit;
	CString digit;

	CButton is_check_shift;
	CButton is_check_caps;
	CButton btn_fpu;
	CButton btn_0;
	CButton btn_1;
	CButton btn_2;
	CButton btn_3;
	CButton btn_4;
	CButton btn_5;
	CButton btn_6;
	CButton btn_7;
	CButton btn_8;
	CButton btn_9;
	CButton btn_dash;
	CButton btn_equal;
	CButton btn_backslush;
	CButton btn_backspace;
	CButton btn_q;
	CButton btn_w;
	CButton btn_e;
	CButton btn_r;
	CButton btn_t;
	CButton btn_y;
	CButton btn_u;
	CButton btn_i;
	CButton btn_o;
	CButton btn_p;
	CButton btn_preb;
	CButton btn_postb;
	CButton btn_a;
	CButton btn_s;
	CButton btn_d;
	CButton btn_f;
	CButton btn_g;
	CButton btn_h;
	CButton btn_j;
	CButton btn_k;
	CButton btn_l;
	CButton btn_semi;
	CButton btn_upper;
	CButton btn_z;
	CButton btn_x;
	CButton btn_c;
	CButton btn_v;
	CButton btn_b;
	CButton btn_n;
	CButton btn_m;
	CButton btn_comma;
	CButton btn_dot;
	CButton btn_slush;

	//string eng_upper[26] = { "A", "B", "C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };
	//string eng[26] = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };
	//string kor_consonants[14] = { "ㄱ", "ㄴ", "ㄷ", "ㄹ", "ㅁ", "ㅂ", "ㅅ", "ㅇ", "ㅈ", "ㅊ", "ㅋ", "ㅌ", "ㅍ", "ㅎ" };
	//string kor_vowels[10] = { "ㅏ", "ㅑ", "ㅓ", "ㅕ", "ㅗ", "ㅛ", "ㅜ", "ㅠ", "ㅡ", "ㅣ" };
	//string kor_double_consnants[5] = { "ㄲ", "ㄸ", "ㅃ", "ㅆ", "ㅉ" };
	//string kor_diphthongs[10] = { "ㅐ", "ㅒ", "ㅔ", "ㅖ", "ㅘ", "ㅙ", "ㅞ", "ㅟ", "ㅢ" };

	CListBox m_list;
	CEdit m_edit;
	

	
	afx_msg void OnBnClickedButtonClear();
};
