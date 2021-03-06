
// EncryptedCodeConverterDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "Base64.h"
#include "Md5.h"


// CEncryptedCodeConverterDlg 对话框
class CEncryptedCodeConverterDlg : public CDialogEx
{
// 构造
public:
	CEncryptedCodeConverterDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ENCRYPTEDCODECONVERTER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    CButton m_Encoding;
    EncodingConverter *pConvert;
    Base64Converter converter1;
    Md5Converter converter2;
};
