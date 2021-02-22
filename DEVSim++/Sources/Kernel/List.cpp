#include "../../Includes/Kernel/List.hpp"

List::List(){
	Head = Tail = Curr = nullptr;
	Len = 0;
}

List::~List(){
	DeleteAll();
}

void List::AddModel(std::string N, Model *M){
	if (IsIn(N)) return;
	Curr = new ListElem;
	Curr->Name = N;      Curr->Address = M;
	Curr->Before = nullptr; Curr->Next = nullptr;

	if (Head == nullptr) {
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

int  List::IsIn(std::string N){
	Curr = FindFirst(N);
	if (Curr == nullptr) return 0;
	else return 1;
}

int  List::Delete(std::string N){
	Curr = FindFirst(N);
	if (Curr == nullptr) return 0;

	if (Len == 1) {
		delete Curr;
		Head = Tail = Curr = nullptr;
		Len = 0;
	}
	else if (Curr == Head) {
		Head->Next->Before = nullptr;
		Head = Head->Next;
		delete Curr;
		Len--;
	}
	else if (Curr == Tail){
		Tail->Before->Next = nullptr;
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
		Head = Tail = Curr = nullptr;
		Len = 0;
	}
	else {
		p = q = Head;

		do {
			q = p;
			p = p->Next;
			delete q;
			if (p == Tail) break;
		} while (true);

		delete p;
		Len = 0;
	}
}

ListElem *List::FindFirst(std::string N){
	ListElem *p;
	if (IsEmpty()) return nullptr;

	p = Head;

	do {
		if (p->Name == N) return p;
		if (p == Tail) break;
		p = p->Next;
	} while (true);

	return nullptr;
}

Model *List::GetModel(std::string N){
	Curr = FindFirst(N);
	if (Curr == nullptr) return nullptr;
	else return Curr->Address;
}