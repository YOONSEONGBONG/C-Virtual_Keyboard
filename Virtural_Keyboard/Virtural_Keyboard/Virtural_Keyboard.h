
// Virtural_Keyboard.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CVirtural_KeyboardApp:
// �� Ŭ������ ������ ���ؼ��� Virtural_Keyboard.cpp�� �����Ͻʽÿ�.
//

class CVirtural_KeyboardApp : public CWinApp
{
public:
	CVirtural_KeyboardApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CVirtural_KeyboardApp theApp;