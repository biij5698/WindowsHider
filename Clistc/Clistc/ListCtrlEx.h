
#include <vector>

using namespace std;

typedef int (*CallBack) (CString, CString);


class CListCtrlEx : public CListCtrl
{
public:
	CListCtrlEx();

public:
	BOOL AddColumn(
		LPCTSTR strItem,int nItem,
		int tam = 0,
		int nFmt = LVCFMT_LEFT,
		int nSubItem = -1,
		int nMask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM);
	BOOL AddItem(int nItem,int nSubItem,LPCTSTR strItem,int nImageIndex = -1);
	BOOL AddItem(int nItem,int nSubItem,string strItem,int nImageIndex = -1);
	BOOL DelItem(int nItem);
	BOOL DelAll();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListCtrlEx)
	//}}AFX_VIRTUAL


public:
	BOOL SelectItem(int intem);
	virtual void SetColumnSortCallback(int item, CallBack cb);
	bool m_doSort;
	bool Ord;
	int Tip;
	virtual ~CListCtrlEx();
	vector<CallBack> m_SortCallbacks;

protected:
	//{{AFX_MSG(CListCtrlEx)
	//afx_msg void OnColumnclick(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};
int IntComp(CString s1, CString s2);


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

// !defined(AFX_LISTCTRLEX_H__2B9243D2_7494_4761_8A7D_157B360F4D9C__INCLUDED_)
