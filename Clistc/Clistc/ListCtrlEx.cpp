
#include "stdafx.h"
#include "ListCtrlEx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



CListCtrlEx::CListCtrlEx()
{
	m_doSort = true;
}

CListCtrlEx::~CListCtrlEx()
{
}


BEGIN_MESSAGE_MAP(CListCtrlEx, CListCtrl)
	//{{AFX_MSG_MAP(CListCtrlEx)
	//ON_NOTIFY_REFLECT(LVN_COLUMNCLICK, OnColumnclick)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL CListCtrlEx::AddColumn(LPCTSTR strItem,int nItem,int tam,int nFmt,int nSubItem,int nMask)
{
	LV_COLUMN lvc;
	lvc.mask = nMask;
	lvc.fmt = nFmt;
	lvc.pszText = (LPTSTR) strItem;
	int tam2 = GetStringWidth(lvc.pszText) + 15;
	tam = tam>tam2?tam:tam2;
	lvc.cx = tam;
	if(nMask & LVCF_SUBITEM)
	{
		if(nSubItem != -1)
			lvc.iSubItem = nSubItem;
		else
			lvc.iSubItem = nItem;
	}
	return InsertColumn(nItem,&lvc);
}


BOOL CListCtrlEx::AddItem(int nItem,int nSubItem,string strItem,int nImageIndex)
{
	return AddItem(nItem, nSubItem, strItem.c_str(), nImageIndex);
}


BOOL CListCtrlEx::AddItem(int nItem,int nSubItem,LPCTSTR strItem,int nImageIndex)
{
	LV_ITEM lvItem;
	lvItem.mask = LVIF_TEXT;
	lvItem.iItem = nItem;
	lvItem.iSubItem = nSubItem;
	lvItem.pszText = (LPTSTR) strItem;

	if(nImageIndex != -1)
	{
		lvItem.mask |= LVIF_IMAGE;
		lvItem.iImage |= LVIF_IMAGE;
	}

	if(nSubItem == 0)
	{
		BOOL res=InsertItem(&lvItem);
		SetItemData(nItem,nItem);
		return res;
	}

	return SetItem(&lvItem);
}


BOOL CListCtrlEx::DelItem(int nItem)
{
	DeleteItem(nItem);
	return TRUE;
}


BOOL CListCtrlEx::DelAll()
{
	DeleteAllItems();
	return TRUE;
}


int CALLBACK Comparacion(LPARAM lParam1, LPARAM lParam2,LPARAM lParamSort)
{

	CListCtrlEx *GE = (CListCtrlEx *)lParamSort;
	int Val = 0;

	if (GE)
	{
		int Item1 = -1;
		int	Item2 = -1;
		int p=-1;
	
		bool rapido=0;
	
		LVFINDINFO FindInfo;
		FindInfo.flags = LVFI_PARAM;
		FindInfo.lParam = lParam1;
		Item1 = GE->FindItem( &FindInfo);

		if(rapido)
			p=Item1;
		
		FindInfo.lParam = lParam2;
		Item2 = GE->FindItem( &FindInfo,p);

		if(Item2<0) 
			Beep(400,400);
	
		CString It1 = GE->GetItemText(Item1,GE->Tip);
		CString It2 = GE->GetItemText(Item2,GE->Tip);
	
	
		if(GE->m_SortCallbacks.size() > GE->Tip  && GE->m_SortCallbacks[GE->Tip])
			Val = (*(GE->m_SortCallbacks[GE->Tip]))(It1,It2);
		else
			Val =  strcmp((char *)(LPCTSTR)It1,(char *)(LPCTSTR)It2);
	
		Val =(GE->Ord)? -Val :Val ;
	
		return Val;
	}

	return 0;
}
/*
void CListCtrlEx::OnColumnclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	
	if (Tip != pNMListView->iSubItem)
		Ord = false;
	else  
		Ord = !Ord;
	
	Tip = pNMListView->iSubItem;
	
	if (m_doSort)SortItems( Comparacion, (LPARAM)this);
	
	*pResult = 0;
}*/

void CListCtrlEx::SetColumnSortCallback(int item, CallBack cb)
{
	if(m_SortCallbacks.size()<item+1)
		m_SortCallbacks.resize(item+1);
	m_SortCallbacks[item] = cb;
}

int IntComp(CString s1, CString s2)
{
	int i1 = atoi(s1);
	int i2 = atoi(s2);
	if(i1==i2)return 0;
	if(i1<i2) return -1;
	return 1;
}

BOOL CListCtrlEx::SelectItem(int item)
{
	return SetItem( item,0,LVIF_STATE,NULL,0,LVNI_SELECTED | LVNI_FOCUSED,LVNI_SELECTED | LVNI_FOCUSED,NULL); 
}
