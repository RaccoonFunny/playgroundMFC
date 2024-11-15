﻿
// playgroundMFCDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "playgroundMFC.h"
#include "playgroundMFCDlg.h"
#include "afxdialogex.h"
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CplaygroundMFCDlg



CplaygroundMFCDlg::CplaygroundMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PLAYGROUNDMFC_DIALOG, pParent)
	, m_full(0)
	, m_half(1)
	, m_empty(2)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CplaygroundMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_full);
	DDX_Radio(pDX, IDC_RADIO2, m_half);
	DDX_Radio(pDX, IDC_RADIO3, m_empty);
}

BEGIN_MESSAGE_MAP(CplaygroundMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO1, &CplaygroundMFCDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO3, &CplaygroundMFCDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO2, &CplaygroundMFCDlg::OnBnClickedRadio2)
	ON_EN_CHANGE(IDC_EDIT1, &CplaygroundMFCDlg::OnEnChangeEdit1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_PROGRESS1, &CplaygroundMFCDlg::OnNMCustomdrawProgress1)
	ON_BN_CLICKED(IDC_BUTTON2, &CplaygroundMFCDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CplaygroundMFCDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Обработчики сообщений CplaygroundMFCDlg

BOOL CplaygroundMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	m_pEditControl = (CEdit*)GetDlgItem(IDC_EDIT1);
	pProgress = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS1);

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CplaygroundMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CplaygroundMFCDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CplaygroundMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CplaygroundMFCDlg::updateProgress(int percent) {
	CString percentStr;
	
	pProgress->SetPos(percent);
	percentStr.Format(_T("%d"), percent);
	m_pEditControl->SetWindowText(percentStr);
}



void CplaygroundMFCDlg::OnBnClickedRadio1()
{
	// TODO: добавьте свой код обработчика уведомлений
	updateProgress(100);
}


void CplaygroundMFCDlg::OnBnClickedRadio2()
{
	// TODO: добавьте свой код обработчика уведомлений
	updateProgress(50);
}

void CplaygroundMFCDlg::OnBnClickedRadio3()
{
	// TODO: добавьте свой код обработчика уведомлений
	updateProgress(0);
}



void CplaygroundMFCDlg::OnEnChangeEdit1()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.	
}


void CplaygroundMFCDlg::OnNMCustomdrawProgress1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: добавьте свой код обработчика уведомлений
	*pResult = 0;
}


void CplaygroundMFCDlg::OnBnClickedButton2()
{
	CString strValue;
	m_pEditControl->GetWindowText(strValue);
	int value = _ttoi(strValue);
	updateProgress(value);
}


void CplaygroundMFCDlg::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлений
	updateProgress(0);
}
