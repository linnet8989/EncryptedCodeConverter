
// EncryptedCodeConverterDlg.h : ͷ�ļ�
//

#pragma once


// CEncryptedCodeConverterDlg �Ի���
class CEncryptedCodeConverterDlg : public CDialogEx
{
// ����
public:
	CEncryptedCodeConverterDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ENCRYPTEDCODECONVERTER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
