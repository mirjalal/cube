
// kvadrat ve daha sonra kub.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CkvadratvedahasonrakubApp:
// О реализации данного класса см. kvadrat ve daha sonra kub.cpp
//

class CkvadratvedahasonrakubApp : public CWinApp
{
public:
	CkvadratvedahasonrakubApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CkvadratvedahasonrakubApp theApp;