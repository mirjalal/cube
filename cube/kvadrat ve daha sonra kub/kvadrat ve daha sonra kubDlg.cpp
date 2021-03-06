
// kvadrat ve daha sonra kubDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "kvadrat ve daha sonra kub.h"
#include "kvadrat ve daha sonra kubDlg.h"
#include "afxdialogex.h"
#include <afxwin.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
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


// диалоговое окно CkvadratvedahasonrakubDlg



CkvadratvedahasonrakubDlg::CkvadratvedahasonrakubDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CkvadratvedahasonrakubDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CkvadratvedahasonrakubDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CkvadratvedahasonrakubDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CkvadratvedahasonrakubDlg::OnBnClickedButton1)
//	ON_UPDATE_COMMAND_UI(AFX_IDC_COLOR_RED, &CkvadratvedahasonrakubDlg::OnUpdateAfxIdcColorRed)
//ON_BN_DOUBLECLICKED(IDC_BUTTON1, &CkvadratvedahasonrakubDlg::OnDoubleclickedButton1)
END_MESSAGE_MAP()


// обработчики сообщений CkvadratvedahasonrakubDlg

BOOL CkvadratvedahasonrakubDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CkvadratvedahasonrakubDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CkvadratvedahasonrakubDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
//		CPaintDC dc(this);
//		CPen l_YellowPen_ics = CPen(PS_SOLID, 2, RGB(255, 255, 0));
//		CBrush l_OrangeBrush_ics = CBrush(RGB(255, 128, 0));
//		dc.SelectObject(&l_YellowPen_ics);
//		dc.SelectObject(&l_OrangeBrush_ics);
//		dc.Rectangle(10, 10, 50, 50);
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CkvadratvedahasonrakubDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CkvadratvedahasonrakubDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CClientDC* paint = new CClientDC(this);
	double A1[4], A2[4], A3[4], A4[4], A5[4], A6[4], A7[4], A8[4];
	int B1[4], B2[4], B3[4], B4[4], B5[4], B6[4], B7[4], B8[4];
	double t[4][4], s[4][4], Rx[4][4], Ry[4][4], Rz[4][4], a[4][4], b[4][4], c[4][4], W[4][4];
	int length = 4;
	size_t i, j;
	double alpha, betta, qamma;
	alpha = 0.4;
	betta = 0.52;
	qamma = 0.2;

	//////////////////// kubun ilkin noqteleri
	A2[0] = 0;
	A2[1] = 0;
	A2[2] = 100;	// 2
	A2[3] = 1;

	A3[0] = 0;
	A3[1] = 100;
	A3[2] = 100;	// 3
	A3[3] = 1;

	A4[0] = 100;
	A4[1] = 100;	// 4
	A4[2] = 100;
	A4[3] = 1;

	A1[0] = 100;
	A1[1] = 0;		/// 1
	A1[2] = 100;
	A1[3] = 1;

	A6[0] = 0;		/// 6
	A6[1] = 0;
	A6[2] = 0;
	A6[3] = 1;

	A7[0] = 0;
	A7[1] = 100;	/// 7
	A7[2] = 0;
	A7[3] = 1;

	A8[0] = 100;
	A8[1] = 100;	/// 8
	A8[2] = 0;
	A8[3] = 1;

	A5[0] = 100;	// 5
	A5[1] = 0;
	A5[2] = 0;
	A5[3] = 1;


	/////////////////// t matrisi
	int Ty = 100;
	t[0][0] = 1;
	t[0][1] = 0;
	t[0][2] = 0;
	t[0][3] = 0;
	t[1][0] = 0;
	t[1][1] = 1;
	t[1][2] = 0;
	t[1][3] = 0;
	t[2][0] = 0;
	t[2][1] = 0;
	t[2][2] = 1;
	t[2][3] = 0;
	t[3][0] = 400;
	t[3][1] = Ty;
	t[3][2] = Ty;
	t[3][3] = 1;


	////////////////// s matrisi
	s[0][0] = 1;
	s[0][1] = 0;
	s[0][2] = 0;
	s[0][3] = 0;
	s[1][0] = 0;
	s[1][1] = 1;
	s[1][2] = 0;
	s[1][3] = 0;
	s[2][0] = 0;
	s[2][1] = 0;
	s[2][2] = 1;
	s[2][3] = 0;
	s[3][0] = 0;
	s[3][1] = 0;
	s[3][2] = 0;
	s[3][3] = 1;


	/////////////////// Rx matrisi 
	Rx[0][0] = 1;
	Rx[0][1] = 0;
	Rx[0][2] = 0;
	Rx[0][3] = 0;
	Rx[1][0] = 0;
	Rx[1][1] = cos(alpha);
	Rx[1][2] = sin(alpha);
	Rx[1][3] = 0;
	Rx[2][0] = 0;
	Rx[2][1] = -sin(alpha);
	Rx[2][2] = cos(alpha);
	Rx[2][3] = 0;
	Rx[3][0] = 0;
	Rx[3][1] = 0;
	Rx[3][2] = 0;
	Rx[3][3] = 1;


	////////////////////// Ry matrisi
	Ry[0][0] = cos(betta);
	Ry[0][1] = 0;
	Ry[0][2] = sin(betta);
	Ry[0][3] = 0;
	Ry[1][0] = 0;
	Ry[1][1] = 1;
	Ry[1][2] = 0;
	Ry[1][3] = 0;
	Ry[2][0] = sin(betta);
	Ry[2][1] = 0;
	Ry[2][2] = cos(betta);
	Ry[2][3] = 0;
	Ry[3][0] = 0;
	Ry[3][1] = 0;
	Ry[3][2] = 0;
	Ry[3][3] = 1;


	///////////////////// Rz matrisi
	Rz[0][0] = cos(qamma);
	Rz[0][1] = sin(qamma);
	Rz[0][2] = 0;
	Rz[0][3] = 0;
	Rz[1][0] = -sin(qamma);
	Rz[1][1] = cos(qamma);
	Rz[1][2] = 0;
	Rz[1][3] = 0;
	Rz[2][0] = 0;
	Rz[2][1] = 0;
	Rz[2][2] = 1;
	Rz[2][3] = 0;
	Rz[3][0] = 0;
	Rz[3][1] = 0;
	Rz[3][2] = 0;
	Rz[3][3] = 1;


	//////////////////// kvadratin cekilmesi
	paint->MoveTo(A1[0], A1[1]);
	paint->LineTo(A5[0], A5[1]);
	paint->LineTo(A8[0], A8[1]);
	paint->LineTo(A4[0], A4[1]);
	paint->LineTo(A1[0], A1[1]);

	paint->MoveTo(A1[0], A1[1]);
	paint->LineTo(A2[0], A2[1]);
	paint->LineTo(A3[0], A3[1]);
	paint->LineTo(A4[0], A4[1]);
	paint->LineTo(A1[0], A1[1]);

	paint->MoveTo(A4[0], A4[1]);
	paint->LineTo(A3[0], A3[1]);
	paint->LineTo(A7[0], A7[1]);
	paint->LineTo(A8[0], A8[1]);
	paint->LineTo(A4[0], A4[1]);

	paint->MoveTo(A5[0], A5[1]);
	paint->LineTo(A6[0], A6[1]);
	paint->LineTo(A7[0], A7[1]);
	paint->LineTo(A8[0], A8[1]);
	paint->LineTo(A5[0], A5[1]);

	paint->MoveTo(A1[0], A1[1]);
	paint->LineTo(A2[0], A2[1]);
	paint->LineTo(A6[0], A6[1]);
	paint->LineTo(A5[0], A5[1]);
	paint->LineTo(A1[0], A1[1]);

	paint->MoveTo(A2[0], A2[1]);
	paint->LineTo(A6[0], A6[1]);
	paint->LineTo(A7[0], A7[1]);
	paint->LineTo(A3[0], A3[1]);
	paint->LineTo(A2[0], A3[1]);


	//////////////////////// matrislerin hasili
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; j < length; j++)
		{
			a[i][j] = 0;
			for (size_t k = 0; k < length; k++)
			{
				a[i][j] += t[i][k] * s[k][j];
			}
		}
	}

	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; j < length; j++)
		{
			b[i][j] = 0;
			for (size_t k = 0; k < length; k++)
			{
				b[i][j] += a[i][k] * Rx[k][j];
			}
		}
	}

	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; j < length; j++)
		{
			c[i][j] = 0;
			for (size_t k = 0; k < length; k++)
			{
				c[i][j] += b[i][k] * Ry[k][j];
			}
		}
	}

	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; j < length; j++)
		{
			W[i][j] = 0;
			for (size_t k = 0; k < length; k++)
			{
				W[i][j] += c[i][k] * Rz[k][j];
			}
		}
	}

	//////////////////// her bir An[j] noqtesini W[j][i] matrisine vurub Bn[i] matrisine yazdim --->  Bn[i] += An[j] * W[j][i]
	for (i = 0; i < 4; i++)
	{
		B1[i] = 0;
		for (j = 0; j < 4; j++)
		{
			B1[i] += A1[j] * W[j][i];
		}
	}

	for (i = 0; i < 4; i++)
	{
		B2[i] = 0;
		for (j = 0; j < 4; j++)
		{
			B2[i] += A2[j] * W[j][i];
		}
	}

	for (i = 0; i < 4; i++)
	{
		B3[i] = 0;
		for (j = 0; j < 4; j++)
		{
			B3[i] += A3[j] * W[j][i];
		}
	}

	for (i = 0; i < 4; i++)
	{
		B4[i] = 0;
		for (j = 0; j < 4; j++)
		{
			B4[i] += A4[j] * W[j][i];
		}
	}

	for (i = 0; i < 4; i++)
	{
		B5[i] = 0;
		for (j = 0; j < 4; j++)
		{
			B5[i] += A5[j] * W[j][i];
		}
	}

	for (i = 0; i < 4; i++)
	{
		B6[i] = 0;
		for (j = 0; j < 4; j++)
		{
			B6[i] += A6[j] * W[j][i];
		}
	}

	for (i = 0; i < 4; i++)
	{
		B7[i] = 0;
		for (j = 0; j < 4; j++)
		{
			B7[i] += A7[j] * W[j][i];
		}
	}

	for (i = 0; i < 4; i++)
	{
		B8[i] = 0;
		for (j = 0; j < 4; j++)
		{
			B8[i] += A8[j] * W[j][i];
		}
	}

	CPen red = CPen(PS_SOLID, 1, RGB(255, 0, 0));
	paint->SelectObject(&red);
	paint->MoveTo(B1[0], B1[1]);
	paint->LineTo(B4[0], B4[1]);
	paint->LineTo(B8[0], B8[1]);
	paint->LineTo(B5[0], B5[1]);
	paint->LineTo(B1[0], B1[1]);

	paint->MoveTo(B4[0], B4[1]);
	paint->LineTo(B3[0], B3[1]);
	paint->LineTo(B7[0], B7[1]);
	paint->LineTo(B8[0], B8[1]);
	paint->LineTo(B4[0], B4[1]);

	paint->MoveTo(B1[0], B1[1]);
	paint->LineTo(B2[0], B2[1]);
	paint->LineTo(B6[0], B6[1]);
	paint->LineTo(B5[0], B5[1]);
	paint->LineTo(B1[0], B1[1]);

	paint->MoveTo(B2[0], B2[1]);
	paint->LineTo(B3[0], B3[1]);
	paint->LineTo(B7[0], B7[1]);
	paint->LineTo(B6[0], B6[1]);
	paint->LineTo(B2[0], B2[1]);

	paint->MoveTo(B5[0], B5[1]);
	paint->LineTo(B6[0], B6[1]);
	paint->LineTo(B7[0], B7[1]);
	paint->LineTo(B8[0], B8[1]);
	paint->LineTo(B5[0], B5[1]);


	
	////////////////////// kub
	//	CClientDC * paint = new CClientDC(this);
	//	COLORREF paint = RGB(255, 0, 0);
}