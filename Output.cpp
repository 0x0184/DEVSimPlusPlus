#include "stdafx.h"
#include "Tglobal.h"
CEditView *pView = NULL;

void Display(char *str){
	CString Tstr;

	Tstr = str;
	if (!pView)
		pView = (CEditView *)(((CFrameWnd *)AfxGetMainWnd())->GetActiveView());
	pView->GetEditCtrl().SetSel(-1, -1, TRUE);
	pView->GetEditCtrl().ReplaceSel(Tstr);
}

void Display(CString Tstr){
	if (!pView)
		pView = (CEditView *)(((CFrameWnd *)AfxGetMainWnd())->GetActiveView());
	pView->GetEditCtrl().SetSel(-1, -1, TRUE);
	pView->GetEditCtrl().ReplaceSel(Tstr);
}

void NewLine(void){ Display("\r\n"); }

void Display(long val){
	char  temp[1024];
	sprintf(temp,"%ld",val);
	Display(temp);
}

void Display(double val){
	char  temp[1024];
	sprintf(temp,"%lf",val);
	Display(temp);
}

void Display(int val){
	char  temp[1024];
	sprintf(temp,"%d",val);
	Display(temp);
}

void Display(float val){
	char  temp[1024];
	sprintf(temp,"%f",val);
	Display(temp);
}