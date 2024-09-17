
// playgroundMFCDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CplaygroundMFCDlg
class CplaygroundMFCDlg : public CDialogEx
{
// Создание
public:
	CplaygroundMFCDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PLAYGROUNDMFC_DIALOG };
#endif

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
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnEnChangeEdit1();
	void updateProgress(int percent);
	afx_msg void OnNMCustomdrawProgress1(NMHDR* pNMHDR, LRESULT* pResult);
	CEdit* m_pEditControl;
	CProgressCtrl* pProgress;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	INT m_full;
	INT m_half;
	INT m_empty;
};
