#include "../../Includes/Kernel/MList.hpp"

MList::MList(){
	Head = Tail = nullptr;
	NumOfElement = 0;
}

MList::~MList() {
	DelAll();
}

int  MList::GetLength(void) {
	return NumOfElement;
}

int  MList::AddOne(Model *M) {
	return AddOne(M, INF);
}

int  MList::AddOne(Model *M, double T){
	ListElement *p;

	if (IsIn(M)) return 0;
	if (NumOfElement >= 32767) return 0;

	p = new ListElement;
	p->Before = p->Next = nullptr;
	p->WaitTime = T;
	p->PModel = M;

	if (!Head) { Head = Tail = p; }
	else { 
		p->Before = Tail;
		Tail->Next = p;
		Tail = p;
	}

	NumOfElement++;
	return 1;
}

int  MList::DelOne(Model *M){ return DelOne(M->GetName()); }
int  MList::DelOne(std::string M){
	ListElement *p;

	if (!IsIn(M)) return 0;
	if (NumOfElement <= 0) return 0;

	p = FindFirstList(M);

	if (p == Head){
		if (Head == Tail) {
			delete p;
			Head = Tail = nullptr;
		}
		else {
			Head = p->Next;
			Head->Before = nullptr;
			delete p;
		}
	}
	else if (p == Tail){
		if (Head == Tail) {
			delete p;
			Head = Tail = nullptr;
		}
		else {
			Tail = p->Before;
			Tail->Next = nullptr;
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

	if (p == nullptr) return;

	do {
		if (p == Tail) break;
		p = p->Next;
		delete q;
		q = p;
	} while (true);

	delete q;
	NumOfElement = 0;
}

int  MList::IsIn(Model *M) {
	return IsIn(M->GetName());
}

int  MList::IsIn(std::string M) {
	if (FindFirstList(M)) return 1;
	return 0;
}

ListElement *MList::FindFirstList(Model *M) {
	return FindFirstList(M->GetName());
}

ListElement *MList::FindFirstList(std::string MName){
	ListElement *p;

	Curr = p = Head;

	if (p == nullptr) return p;

	do {
		if (p == Tail) break;
		if (p->PModel->GetName() == MName) {
			Curr = p->Next;
			return p;
		}
		p = p->Next;
	} while (true);

	if (p == Tail) Curr = nullptr;
	if (p->PModel->GetName() == MName) return p;
	return nullptr;
}

ListElement *MList::FindNextList(Model *M){ return FindNextList(M->GetName()); }
ListElement *MList::FindNextList(std::string MName){
	ListElement *p;

	p = Curr;

	if (p == nullptr) return p;

	do {
		if (p == Tail) break;
		if (p->PModel->GetName() == MName) {
			Curr = p->Next;
			return p;
		}
		p = p->Next;
	} while (true);

	if (p == Tail) Curr = nullptr;
	if (p->PModel->GetName() == MName) return p;
	return nullptr;
}

ListElement *MList::FindFirstList(double Time){ Curr = Head; return FindNextList(Time); }
ListElement *MList::FindNextList(double Time){
	ListElement *p;

	p = Curr;

	if (p == nullptr) return p;

	do {
		if (p == Tail) break;
		if (p->WaitTime == Time) {
			Curr = p->Next;
			return p;
		}
		p = p->Next;
	} while (true);

	if (p == Tail) Curr = nullptr;
	if (p->WaitTime == Time) return p;
	return nullptr;

}


void MList::SetOne(Model *M, double T){ SetOne(M->GetName(),T); }
void MList::SetOne(std::string M, double T){
	ListElement *p;
	if (!IsIn(M)) return;
	p = FindFirstList(M);
	p->WaitTime = T;
}

double MList::GetOne(Model *M){ return GetOne(M->GetName()); }         	 
double MList::GetOne(std::string M){
	ListElement *p;
	if (!IsIn(M)) return INF;
	p = FindFirstList(M);
	if (p == nullptr) return INF;
	return p->WaitTime;
}

double MList::GetMinTime(void){
	ListElement *p;
	double Min=INF;

	p = Head;

	if (p == nullptr) return INF;

	do {
		if (p->WaitTime < Min) Min = p->WaitTime;
		if (p == Tail) break;
		p = p->Next;
	} while (true);

	return Min;
}

void MList::AllInitial(void){
	ListElement *p;
	p = Head;
	if (p == nullptr) return;
	do {
		p->PModel->InitialModel();
		if (p == Tail) break;
		p = p->Next;
	} while (true);
}

void MList::DisplayMinTime(void){
	ListElement *p;
	double Min=INF;

	p = Head;

	if (p == nullptr) return;

	do {
		Logln(p->PModel->GetName() + ": " + std::to_string(p->WaitTime));
		if (p == Tail) break;
		p = p->Next;
	} while (true);

	return;
}


