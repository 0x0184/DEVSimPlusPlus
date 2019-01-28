#include "stdafx.h"
#include "mlist.h"
MList::MList(){
	Head = Tail = NULL;
	NumOfElement = 0;
}

MList::~MList(){ DelAll(); }

int  MList::GetLength(void){ return NumOfElement; }

int  MList::AddOne(MODELS *M){ return AddOne(M,INF); }
int  MList::AddOne(MODELS *M, double T){
	ListElement *p;

	if (IsIn(M)) return 0;
	if (NumOfElement >= 32767) return 0;

	p = new ListElement;
	p->Before = p->Next = NULL;
	p->WaitTime = T;
	p->Model = M;

	if (!Head) { Head = Tail = p; }
	else { 
		p->Before = Tail;
		Tail->Next = p;
		Tail = p;
	}

	NumOfElement++;
	return 1;
}

int  MList::DelOne(MODELS *M){ return DelOne(M->GetName()); }
int  MList::DelOne(CString M){
	ListElement *p;

	if (!IsIn(M)) return 0;
	if (NumOfElement <= 0) return 0;

	p = FindFirstList(M);

	if (p == Head){
		if (Head == Tail) {
			delete p;
			Head = Tail = NULL;
		}
		else {
			Head = p->Next;
			Head->Before = NULL;
			delete p;
		}
	}
	else if (p == Tail){
		if (Head == Tail) {
			delete p;
			Head = Tail = NULL;
		}
		else {
			Tail = p->Before;
			Tail->Next = NULL;
			delete p;
		}
	}
	else {
		p->Before->Next = p->Next;
		p->Next->Before = p->Before;
		delete p;
	}

	NumOfElement --;
	return 1;
}

void MList::DelAll(void){
	ListElement *p, *q;

	p = q = Head;

	if (p == NULL) return;

	do {
		if (p == Tail) break;
		p = p->Next;
		delete q;
		q = p;
	} while(1);

	delete q;
	NumOfElement = 0;
}

int  MList::IsIn(MODELS *M) { return IsIn(M->GetName()); }
int  MList::IsIn(CString M) {
	if (FindFirstList(M)) return 1;
	return 0;
}

ListElement *MList::FindFirstList(MODELS *M){ return FindFirstList(M->GetName()); }
ListElement *MList::FindFirstList(CString MName){
	ListElement *p;

	Curr = p = Head;

	if (p == NULL) return p;

	do {
		if (p == Tail) break;
		if (p->Model->GetName() == MName) {
			Curr = p->Next;
			return p;
		}
		p = p->Next;
	} while(1);

	if (p == Tail) Curr = NULL;
	if (p->Model->GetName() == MName) return p;
	return NULL;
}

ListElement *MList::FindNextList(MODELS *M){ return FindNextList(M->GetName()); }
ListElement *MList::FindNextList(CString MName){
	ListElement *p;

	p = Curr;

	if (p == NULL) return p;

	do {
		if (p == Tail) break;
		if (p->Model->GetName() == MName) {
			Curr = p->Next;
			return p;
		}
		p = p->Next;
	} while(1);

	if (p == Tail) Curr = NULL;
	if (p->Model->GetName() == MName) return p;
	return NULL;
}

ListElement *MList::FindFirstList(double Time){ Curr = Head; return FindNextList(Time); }
ListElement *MList::FindNextList(double Time){
	ListElement *p;

	p = Curr;

	if (p == NULL) return p;

	do {
		if (p == Tail) break;
		if (p->WaitTime == Time) {
			Curr = p->Next;
			return p;
		}
		p = p->Next;
	} while(1);

	if (p == Tail) Curr = NULL;
	if (p->WaitTime == Time) return p;
	return NULL;

}


void MList::SetOne(MODELS *M, double T){ SetOne(M->GetName(),T); }
void MList::SetOne(CString M, double T){
	ListElement *p;
	if (!IsIn(M)) return;
	p = FindFirstList(M);
	p->WaitTime = T;
}

double MList::GetOne(MODELS *M){ return GetOne(M->GetName()); }         	 
double MList::GetOne(CString M){
	ListElement *p;
	if (!IsIn(M)) return INF;
	p = FindFirstList(M);
	if (p == NULL) return INF;
	return p->WaitTime;
}

double MList::GetMinTime(void){
	ListElement *p;
	double Min=INF;

	p = Head;

	if (p == NULL) return INF;

	do {
		if (p->WaitTime < Min) Min = p->WaitTime;
		if (p == Tail) break;
		p = p->Next;
	} while(1);

	return Min;
}

void MList::AllInitial(void){
	ListElement *p;
	p = Head;
	if (p == NULL) return;
	do {
		p->Model->InitialModel();
		if (p == Tail) break;
		p = p->Next;
	} while(1);
}

void MList::DisplayMinTime(void){
	ListElement *p;
	double Min=INF;

	p = Head;

	if (p == NULL) return;

	do {

		char ttt[100];
		Display(p->Model->Name); Display(": "); sprintf(ttt,"%lf",p->WaitTime);
		Display(ttt); NewLine();

		if (p == Tail) break;
		p = p->Next;
	} while(1);

	return;
}


