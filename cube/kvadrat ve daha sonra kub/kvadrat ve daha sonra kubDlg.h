
// kvadrat ve daha sonra kubDlg.h : файл заголовка
//

#pragma once


// диалоговое окно CkvadratvedahasonrakubDlg
class CkvadratvedahasonrakubDlg : public CDialogEx
{
// Создание
public:
	CkvadratvedahasonrakubDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_KVADRATVEDAHASONRAKUB_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
//	afx_msg void OnUpdateAfxIdcColorRed(CCmdUI *pCmdUI);
//	afx_msg void OnDoubleclickedButton1();
};
