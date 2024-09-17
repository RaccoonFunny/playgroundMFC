
// playgroundMFC.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CplaygroundMFCApp:
// Сведения о реализации этого класса: playgroundMFC.cpp
//

class CplaygroundMFCApp : public CWinApp
{
public:
	CplaygroundMFCApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CplaygroundMFCApp theApp;
