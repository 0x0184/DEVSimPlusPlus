#include "stdafx.h"
#include "list.h"

List::List(){
	Head = Tail = Curr = NULL;
	Len = 0;
}

List::~List(){
	DeleteAll();
}

void List::AddModel(CString N, MODELS *M){
	if (IsIn(N)) return;
	Curr = new ListElem;
	Curr->Name = N;      Curr->Address = M;
	Curr->Before = NULL; Curr->Next = NULL;

	if (Head == NULL) {
		Head = Tail = Curr;
		Len = 1;
	}
	else {
		Tail->Next = Curr;
		Curr->Before = Tail;
		Tail = Curr;
		Len++;
	}
}

void List::AddModel(char *N, MODELS *M){
	if (IsIn(N)) return;
	Curr = new ListElem;
	Curr->Name = N;      Curr->Address = M;
	Curr->Before = NULL; Curr->Next = NULL;

	if (Head == NULL) {
		Head = Tail = Curr;
		Len = 1;
	}
	else {
		Tail->Next = Curr;
		Curr->Before = Tail;
		Tail = Curr;
		Len++;
	}
}

int  List::Length(void){ return Len; }
int  List::IsEmpty(void){ 
	if (Len == 0) return 1; 
	return 0;
}

int  List::IsIn(CString N){
	Curr = FindFirst(N);
	if (Curr == NULL) return 0;
	else return 1;
}

int  List::IsIn(char *N){
	Curr = FindFirst(N);
	if (Curr == NULL) return 0;
	else return 1;
}

int  List::Delete(CString N){
	Curr = FindFirst(N);
	if (Curr == NULL) return 0;

	if (Len == 1) {
		delete Curr;
		Head = Tail = Curr = NULL;
		Len = 0;
	}
	else if (Curr == Head) {
		Head->Next->Before = NULL;
		Head = Head->Next;
		delete Curr;
		Len--;
	}
	else if (Curr == Tail){
		Tail->Before->Next = NULL;
		Tail = Tail->Before;
		delete Curr;
		Len --;
	}
	else {
		Curr->Before->Next = Curr->Next;
		Curr->Next->Before = Curr->Before;
		delete Curr;
		Len --;
	}

	return 1;
}

int  List::Delete(char *N){
	Curr = FindFirst(N);
	if (Curr == NULL) return 0;

	if (Len == 1) {
		delete Curr;
		Head = Tail = Curr = NULL;
		Len = 0;
	}
	else if (Curr == Head) {
		Head->Next->Before = NULL;
		Head = Head->Next;
		delete Curr;
		Len--;
	}
	else if (Curr == Tail){
		Tail->Before->Next = NULL;
		Tail = Tail->Before;
		delete Curr;
		Len --;
	}
	else {
		Curr->Before->Next = Curr->Next;
		Curr->Next->Before = Curr->Before;
		delete Curr;
		Len --;
	}

	return 1;
}

void List::DeleteAll(void){
	ListElem *p, *q;

	if (IsEmpty()) return;

	if (Length() == 1) {
		delete Head;
		Head = Tail = Curr = NULL;
		Len = 0;
	}
	else {
		p = q = Head;

		do {
			q = p;
			p = p->Next;
			delete q;
			if (p == Tail) break;
		} while(1);

		delete p;
		Len = 0;
	}
}

ListElem *List::FindFirst(CString N){
	ListElem *p;
	if (IsEmpty()) return NULL;

	p = Head;

	do {
		if (p->Name == N) return p;
		if (p == Tail) break;
		p = p->Next;
	} while(1);

	return NULL;
}

ListElem *List::FindFirst(char *N){
	ListElem *p;
	if (IsEmpty()) return NULL;

	p = Head;

	do {
		if (p->Name == N) return p;
		if (p == Tail) break;
		p = p->Next;
	} while(1);

	return NULL;
}

MODELS *List::GetModel(CString N){
	Curr = FindFirst(N);
	if (Curr == NULL) return NULL;
	else return Curr->Address;
}

MODELS *List::GetModel(char *N){
	Curr = FindFirst(N);
	if (Curr == NULL) return NULL;
	else return Curr->Address;
}
