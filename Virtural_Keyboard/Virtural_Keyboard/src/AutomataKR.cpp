#include "StdAfx.h"
#include "AutomataKR.h"

const int BASE_CODE = 0xac00;		// ��������(��)
const int LIMIT_MIN = 0xac00;		// �������� MIN(��)
const int LIMIT_MAX = 0xd7a3;		// �������� MAX

// ���� ���̺�
wchar_t SOUND_TABLE[165] =
{
	/* �ʼ� 19�� 0 ~ 18 */
	_T('��'), _T('��'), _T('��'), _T('��'), _T('��'),
	_T('��'), _T('��'), _T('��'), _T('��'), _T('��'),
	_T('��'), _T('��'), _T('��'), _T('��'), _T('��'),
	_T('��'), _T('��'), _T('��'), _T('��'),
	/* �߼� 21�� 19 ~ 39 */
	_T('��'), _T('��'), _T('��'), _T('��'), _T('��'),
	_T('��'), _T('��'), _T('��'), _T('��'), _T('��'),
	_T('��'), _T('��'), _T('��'), _T('��'), _T('��'),
	_T('��'), _T('��'), _T('��'), _T('��'), _T('��'),
	_T('��'),
	/* ���� 28�� 40 ~ 67 */
	_T(' '), _T('��'), _T('��'), _T('��'), _T('��'),
	_T('��'), _T('��'), _T('��'), _T('��'), _T('��'),
	_T('��'), _T('��'), _T('��'), _T('��'), _T('��'),
	_T('��'), _T('��'), _T('��'), _T('��'), _T('��'),
	_T('��'), _T('��'), _T('��'), _T('��'), _T('��'),
	_T('��'), _T('��'), _T('��'),
	/* A~Z 26�� 68 ~ 94 */
	_T('A'), _T('B'), _T('C'), _T('D'), _T('E'),
	_T('F'), _T('G'), _T('H'), _T('I'), _T('J'),
	_T('K'), _T('L'), _T('M'), _T('N'), _T('O'),
	_T('P'), _T('Q'), _T('R'), _T('S'), _T('T'),
	_T('U'), _T('V'), _T('W'), _T('X'), _T('Y'),
	_T('Z'),
	/* a~z 26�� 95 ~ 121 */
	_T('a'), _T('b'), _T('c'), _T('d'), _T('e'),
	_T('f'), _T('g'), _T('h'), _T('i'), _T('j'),
	_T('k'), _T('l'), _T('m'), _T('n'), _T('o'),
	_T('p'), _T('q'), _T('r'), _T('s'), _T('t'),
	_T('u'), _T('v'), _T('w'), _T('x'), _T('y'),
	_T('z'),
	/* 0~9 10�� 122 ~ 132 */
	_T('0'), _T('1'), _T('2'), _T('3'), _T('4'),
	_T('5'), _T('6'), _T('7'), _T('8'), _T('9'),

	/* Ư������ 31�� 133 ~ 164 */
	_T('`'), _T('~'), _T('@'), _T('#'), _T('$'),
	_T('%'), _T('^'), _T('&'), _T('*'), _T('('),
	_T(')'), _T('-'), _T('_'), _T('='), _T('+'),
	_T('\\'), _T('|'), _T('['), _T('{'), _T(']'),
	_T('}'), _T(';'), _T(':'), _T('\''), _T('"'),
	_T(','), _T('<'), _T('.'), _T('>'), _T('/'),
	_T('?'),
};

// �ʼ� �ռ� ���̺�
int MIXED_CHO_CONSON[14][3] =
{
	{ 0, 0,15}, // ��,��,��
	{15, 0, 1}, // ��,��,��
	{ 1, 0, 0}, // ��,��,��

	{ 3, 3,16}, // ��,��,��
	{16, 3, 4}, // ��,��,��
	{ 4, 3, 3}, // ��,��,��

	{ 7, 7,17}, // ��,��,��
	{17, 7, 8}, // ��,��,��
	{ 8, 7, 7}, // ��,��,��

	{ 9, 9,10}, // ��,��,��
	{10, 9, 9}, // ��,��,��

	{12,12,14}, // ��,��,��
	{14,12,13}, // ��,��,��
	{13,12,12}  // ��,��,��
};

// �ʼ�,�߼� ���� �ռ� ���̺�
int MIXED_VOWEL[21][3] = 
{
	{27,19,28},	// ��,��,��
	{27,20,29},	// ��,��,��
	{27,39,30},	// ��,��,��
	{32,23,33},	// ��,��,��
	{32,24,34},	// ��,��,��
	{32,39,35},	// ��,��,��
	{37,39,38},	// ��,��,��
	
};

// ���� �ռ� ���̺�
int MIXED_JONG_CONSON[22][3] = 
{
	{41,41,64}, // ��,��,��
	{64,41,42}, // ��,��,��
	{42,41,41}, // ��,��,��

	{41,59,43}, // ��,��,��

	{44,62,45}, // ��,��,��
	{44,67,46}, // ��,��,��

	{47,47,65}, // ��,��,��
	{65,47,47}, // ��,��,��

	{48,41,49}, // ��,��,��
	{48,56,50}, // ��,��,��

	{48,57,51}, // ��,��,��
	{51,57,54}, // ��,��,��

	{48,59,52}, // ��,��,��
	{48,47,53}, // ��,��,��	
	{48,67,55}, // ��,��,��

	{57,57,66}, // ��,��,��
	{66,57,57}, // ��,��,��

	{57,59,58}, // ��,��,��

	{59,59,60}, // ��,��,��
	{60,59,59}, // ��,��,��

	{62,62,63}, // ��,��,��
	{63,62,62}  // ��,��,��
};

// ���� ���� ���̺�
int DIVIDE_JONG_CONSON[13][3] = 
{
	{41,41,42}, // ��,��,��
	{41,59,43}, // ��,��,��
	{44,62,45}, // ��,��,��
	{44,67,46}, // ��,��,��
	{48,41,49}, // ��,��,��
	{48,56,50}, // ��,��,��
	{48,57,51}, // ��,��,��
	{48,66,54}, // ��,��,��
	{48,59,52}, // ��,��,��
	{48,65,53}, // ��,��,��	
	{48,67,55}, // ��,��,��
	{57,59,58}, // ��,��,��
	{59,59,60}  // ��,��,��
};

int CAutomataKR::GetSoundTableValue(CString str)
{
	int i = 0;
	CString tmp;
	while (true)
	{
		tmp = SOUND_TABLE[i];
		if (tmp == str){
			break;
		}
		i++;
		
	}
	return i;
}

CAutomataKR::CAutomataKR(void)
{
	Clear();
}

CAutomataKR::~CAutomataKR(void)
{
}

// ���� �ʱ�ȭ
void CAutomataKR::Clear()
{
	m_nStatus		= HS_FIRST;
	completeText	= _T("");
	ingWord			= NULL;
	m_completeWord	= NULL;
}

// Ű�ڵ� �Է� �� ���� (������ int �ڵ尪�� �Է� �޾� �ѱ�����)
wchar_t CAutomataKR::SetKeyCode(int nKeyCode)
{
	m_completeWord = NULL;

	// Ư��Ű �Է�
	if(nKeyCode < 0)
	{
		m_nStatus = HS_FIRST;

		if(nKeyCode == KEY_CODE_SPACE) // ����
		{
			if(ingWord != NULL)
				completeText += ingWord;
			else
				completeText += _T(' ');

			ingWord = NULL;
		}
		else if(nKeyCode == KEY_CODE_ENTER) // ��������
		{
			if(ingWord != NULL)
				completeText += ingWord;

			completeText += _T("\r\n");

			ingWord = NULL;
		}
		else if(nKeyCode == KEY_CODE_BACKSPACE) // �����
		{
			if(ingWord == NULL)
			{
				if(completeText.GetLength() > 0)
				{
					if(completeText.Right(1) == _T("\n"))
						completeText = completeText.Left(completeText.GetLength() -2);
					else
						completeText = completeText.Left(completeText.GetLength() -1);
				}
			}
			else
			{
				m_nStatus = DownGradeIngWordStatus(ingWord);
			}
		}

		return m_completeWord;
	}


	if (ingWord == SOUND_TABLE[4] || ingWord == SOUND_TABLE[8] || ingWord == SOUND_TABLE[13] )
	{	
		
		m_nStatus = HS_FIRST_V;	
	}
	 
	switch(m_nStatus)
	{
	case HS_FIRST:
		// �ʼ�
		m_nPhonemez[0]	= nKeyCode;
		ingWord			= SOUND_TABLE[m_nPhonemez[0]];
		m_nStatus = nKeyCode > 18 && nKeyCode <68 ? HS_FIRST_C : HS_FIRST_V;
		break;

	case HS_FIRST_C:
		// ���� + ����
		if(nKeyCode > 18)	// ����
		{
			if(MixVowel(&m_nPhonemez[0], nKeyCode) == FALSE)
			{
				m_completeWord = SOUND_TABLE[m_nPhonemez[0]];
				m_nPhonemez[0] = nKeyCode;
			}
		}
		else				// ����
		{
			m_completeWord	= SOUND_TABLE[m_nPhonemez[0]];
			m_nPhonemez[0]	= nKeyCode;
			m_nStatus		= HS_FIRST_V;
		}
		break;

	case HS_FIRST_V:
		// ���� + ����
		if (nKeyCode > 18 && nKeyCode < 68)	// ����
		{
			m_nPhonemez[1]	= nKeyCode;
			m_nStatus		= HS_MIDDLE_STATE;
		}
		else				// ����
		{
			if(!MixInitial(nKeyCode))
			{
				
				m_completeWord = SOUND_TABLE[m_nPhonemez[0]];
				m_nPhonemez[0] = nKeyCode;
				m_nStatus		= HS_FIRST_V;
			}
		}
		break;

	case HS_MIDDLE_STATE:
		// �ʼ� + ���� + ����
		if(nKeyCode > 18)
		{
			if(MixVowel(&m_nPhonemez[1], nKeyCode) == FALSE)
			{
				m_completeWord	= CombineHangle(1);
				m_nPhonemez[0]	= nKeyCode;
				m_nStatus		= HS_FIRST_C;
			}
		}
		else
		{
			int jungCode = ToFinal(nKeyCode);

			if(jungCode > 0)
			{
				m_nPhonemez[2]	= jungCode;
				m_nStatus		= HS_END_STATE;
			}
			else
			{
				m_completeWord	= CombineHangle(1);
				m_nPhonemez[0]	= nKeyCode;
				m_nStatus		= HS_FIRST;
			}
		}
		break;

	case HS_END:
		// �ʼ� + �߼� + ����
		if(nKeyCode > 18)  
		{
			m_completeWord	= CombineHangle(1);
			m_nPhonemez[0]	= nKeyCode;
			m_nStatus		= HS_FIRST;
		}
		else
		{
			int jungCode = ToFinal(nKeyCode);
			if(jungCode > 0)
			{
				m_nPhonemez[2]	= jungCode;
				m_nStatus		= HS_END_STATE;
			}
			else
			{
				m_completeWord	= CombineHangle(1);
				m_nPhonemez[0]	= nKeyCode;
				m_nStatus		= HS_FIRST;
			}  
		}
		break;

	case HS_END_STATE:
		// �ʼ� + �߼� + ����(��) + ����(��)
		if(nKeyCode > 18)
		{
			m_completeWord = CombineHangle(1);

			m_nPhonemez[0]	= ToInitial(m_nPhonemez[2]);
			m_nPhonemez[1]	= nKeyCode;
			m_nStatus		= HS_MIDDLE_STATE;
		}
		else
		{
			int jungCode = ToFinal(nKeyCode);
			if(jungCode > 0)
			{
				m_nStatus = HS_END_EXCEPTION;

				if(!MixFinal(jungCode))
				{
					m_completeWord	= CombineHangle(2);
					m_nPhonemez[0]	= nKeyCode;
					m_nStatus		= HS_FIRST_V;
				}
			}
			else
			{
				m_completeWord	= CombineHangle(2);
				m_nPhonemez[0]	= nKeyCode;
				m_nStatus		= HS_FIRST_V;
			}  
		}
		break;

	case HS_END_EXCEPTION:
		// �ʼ� + �߼� + ����(������)
		if(nKeyCode > 18)  
		{
			DecomposeConsonant();
			m_nPhonemez[1]	= nKeyCode;
			m_nStatus		= HS_MIDDLE_STATE;
		}
		else
		{
			int jungCode = ToFinal(nKeyCode);
			if(jungCode > 0)
			{
				m_nStatus = HS_END_EXCEPTION;

				if(!MixFinal(jungCode))
				{
					m_completeWord	= CombineHangle(2);
					m_nPhonemez[0]	= nKeyCode;
					m_nStatus		= HS_FIRST_V;
				}
			}
			else
			{
				m_completeWord	= CombineHangle(2);
				m_nPhonemez[0]	= nKeyCode;
				m_nStatus		= HS_FIRST_V; 
			}
		}
		break;
	}

	// ���� ���̴� ���ڻ���
	CombineIngWord(m_nStatus);

	// �ϼ� ���ڿ� �����
	if (m_completeWord != NULL)
		completeText += TCHAR(m_completeWord);

	return m_completeWord;
}

// �ʼ����� ��ȯ
int CAutomataKR::ToInitial(int nKeyCode)
{
	switch(nKeyCode)
	{
	case 41: return 0;	// ��
	case 42: return 1;	// ��
	case 44: return 2;	// ��
	case 47: return 3;	// ��
	case 48: return 5;	// ��
	case 56: return 6;	// ��
	case 57: return 7;	// ��
	case 59: return 9;	// ��
	case 60: return 10;	// ��
	case 61: return 11;	// ��
	case 62: return 12;	// ��
	case 63: return 14;	// ��
	case 64: return 15;	// ��
	case 65: return 16;	// ��
	case 66: return 17;	// ��
	case 67: return 18;	// ��
	}
	return -1;
}

// �������� ��ȯ
int CAutomataKR::ToFinal(int nKeyCode)
{
	switch(nKeyCode)
	{
	case 0: return 41;	// ��
	case 1: return 42;	// ��
	case 2: return 44;	// ��
	case 3: return 47;	// ��
	case 5: return 48;	// ��
	case 6: return 56;	// ��
	case 7: return 57;	// ��
	case 9: return 59;	// ��
	case 10: return 60;	// ��
	case 11: return 61;	// ��
	case 12: return 62;	// ��
	case 14: return 63;	// ��
	case 15: return 64;	// ��
	case 16: return 65;	// ��
	case 17: return 66;	// ��
	case 18: return 67;	// ��
	}
	return -1;
}

// ��������
void CAutomataKR::DecomposeConsonant()
{
	int i = 0;
	if(m_nPhonemez[3] > 40 || m_nPhonemez[4] > 40)
	{
		do
		{
			if(DIVIDE_JONG_CONSON[i][2] == m_nPhonemez[2])
			{
				m_nPhonemez[3] = DIVIDE_JONG_CONSON[i][0];
				m_nPhonemez[4] = DIVIDE_JONG_CONSON[i][1];

				m_completeWord = CombineHangle(3);
				m_nPhonemez[0]	 = ToInitial(m_nPhonemez[4]);
				return;
			}
		}
		while(++i< 13);
	}

	m_completeWord = CombineHangle(1);
	m_nPhonemez[0]	 = ToInitial(m_nPhonemez[2]);
}

// �ʼ��ռ�
BOOL CAutomataKR::MixInitial(int nKeyCode)
{
	/*if(nKeyCode >= 19)
		return FALSE;

	int i = 0;
	do
	{
		if(MIXED_CHO_CONSON[i][0] == m_nPhonemez[0] && MIXED_CHO_CONSON[i][1] == nKeyCode)
		{
			m_nPhonemez[0] = MIXED_CHO_CONSON[i][2];
			return TRUE;
		}
	}
	while(++i < 14);

	*/
	return FALSE;
}

// �����ռ�
BOOL CAutomataKR::MixFinal(int nKeyCode)
{
	/*if(nKeyCode <= 40) return FALSE;

	int i = 0;
	do
	{
		if(MIXED_JONG_CONSON[i][0] == m_nPhonemez[2] && MIXED_JONG_CONSON[i][1] == nKeyCode)
		{
			m_nPhonemez[3] = m_nPhonemez[2];
			m_nPhonemez[4] = nKeyCode;
			m_nPhonemez[2] = MIXED_JONG_CONSON[i][2];

			return TRUE;
		}
	}
	while(++i < 22);

	*/
	return FALSE;
}

// �����ռ�
BOOL CAutomataKR::MixVowel(int * currentCode, int inputCode)
{
	
	int i = 0;
	do
	{
		if(MIXED_VOWEL[i][0] == * currentCode && MIXED_VOWEL[i][1] == inputCode)
		{
			*currentCode = MIXED_VOWEL[i][2];
			return TRUE;	
		}
	}
	while(++i< 21);

	
	return FALSE;
}

// �ѱ�����
wchar_t CAutomataKR::CombineHangle(int cho, int jung, int jong)
{
	// �ʼ� * 21 * 28 + (�߼� - 19) * 28 + (���� - 40) + BASE_CODE;
	return BASE_CODE - 572 + jong + cho * 588 + jung * 28;
}

wchar_t CAutomataKR::CombineHangle(int status)
{
	switch(status)
	{
	//�ʼ� + �߼�
	case 1: return CombineHangle(m_nPhonemez[0], m_nPhonemez[1], 40);

	//�ʼ� + �߼� + ����
	case 2: return CombineHangle(m_nPhonemez[0], m_nPhonemez[1], m_nPhonemez[2]);
	
	//�ʼ� + �߼� + ������01
	case 3: return CombineHangle(m_nPhonemez[0], m_nPhonemez[1], m_nPhonemez[3]);
	}
	return ' ';
}

void CAutomataKR::CombineIngWord(int status)
{
	switch(m_nStatus)
	{
	case HS_FIRST:
	case HS_FIRST_V:
	case HS_FIRST_C:
		ingWord = SOUND_TABLE[m_nPhonemez[0]];
		break;

	case HS_MIDDLE_STATE:
	case HS_END:
		ingWord = CombineHangle(1);
		break;

	case HS_END_STATE:
	case HS_END_EXCEPTION:
		ingWord = CombineHangle(2);
		break;
	}
}

int CAutomataKR::DownGradeIngWordStatus(wchar_t word)
{
	int iWord = word;

	//�ʼ��� �ִ� ���
	if(iWord < LIMIT_MIN || iWord > LIMIT_MAX)
	{
		ingWord = NULL;

		return HS_FIRST;
	}

	//�����ڵ� ü��
	//iWord = firstWord * (21*28)
	//		+ middleWord * 28
	//		+ lastWord * 27
	//		+ BASE_CODE;
	//
	int totalWord	= iWord - BASE_CODE;
	int iFirstWord	= totalWord / 28 / 21;	//�ʼ�
	int iMiddleWord = totalWord / 28 % 21;	//�߼�
	int iLastWord	= totalWord % 28;		//����

	m_nPhonemez[0] = iFirstWord; //�ʼ�����

	if(iLastWord == 0)	//������ ���� ���
	{
		ingWord = SOUND_TABLE[m_nPhonemez[0]];

		return HS_FIRST_V;
	}

	m_nPhonemez[1] = iMiddleWord + 19; //�߼�����

	iLastWord += 40;

	for(int i = 0; i < 13; i++)
	{
		if(iLastWord == DIVIDE_JONG_CONSON[i][2])
		{
			ingWord = CombineHangle(3);
			m_nPhonemez[2] = DIVIDE_JONG_CONSON[i][0]; // ��������
			return HS_END_EXCEPTION;
		}
	}

	ingWord = CombineHangle(1);

	return HS_MIDDLE_STATE;
}
