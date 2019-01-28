#include "stdafx.h"
#include "Port.h"

#include "ENTITIES.h"


PORTS::PORTS(){
	Head = Tail = Curr = NULL;
}

PORTS::~PORTS(){
	DelAllCoupling();
}

int  PORTS::AddCoupling(ENTITIES *From, ENTITIES *To, CString FPort, CString TPort){
	PortPair *Temp;

	Temp = new PortPair;

	if (Temp == NULL) return 0;

	Temp->FromModel = From;
	Temp->ToModel   = To;
	Temp->FromPort  = FPort;
	Temp->ToPort    = TPort;
	Temp->Next      = NULL;
	Temp->Before    = NULL;

	if (Head == NULL){
		Head = Temp; Tail = Temp;
	}
	else {
		Tail->Next   = Temp;
		Temp->Before = Tail;
		Tail         = Temp;
	}

	return 1;
}

int  PORTS::DelFromPort(CString Port){
	ENTITIES *p;

	p = FindFirstFromModel(Port);
	if (!p) return 0;

	do {
		DelCurrentCoupling();
		p = FindNextFromModel(Port);
	} while(p);

	return 1;
}

int  PORTS::DelToPort(CString Port){
	ENTITIES *p;

	p = FindFirstToModel(Port);
	if (!p) return 0;

	do {
		DelCurrentCoupling();
		p = FindNextToModel(Port);
	} while(p);

	return 1;
}

void PORTS::DelCurrentCoupling(void){
	PortPair *p;

	if (Curr == NULL) ;
	else 
		if (Curr == Head) {
			if (Head == Tail){ Head = Tail = NULL; }
			else             { Head->Next->Before = NULL; Head = Head->Next;  }
			delete Curr;
			Curr = Head;
		}
		else
			if (Curr == Tail) {
				if (Head == Tail){ Head = Tail = NULL; }
				else             { Tail->Before->Next = NULL; Tail = Tail->Before; }
				delete Curr;
				Curr = Tail;
			}
			else {
				p = Curr->Next;
				p->Before = Curr->Before;
				Curr->Before->Next = p;
				delete Curr;
				Curr = p;
			}
}

void PORTS::DelAllCoupling(void){
	PortPair *p, *q;

	if (Head == NULL) return;

	p = q = Head;

	while (p != Tail) {
		p = p->Next;
		q = p->Before;
		delete q;
	}

	delete p;

	Head = Tail = Curr = NULL;
}

int  PORTS::IsInFromPort(CString Port){
	ENTITIES *T;

	T = FindFirstFromModel(Port);
	if (T) return 1;
	else   return 0;
}

int  PORTS::IsInToPort(CString Port){
	ENTITIES *T;

	T = FindFirstToModel(Port);
	if (T) return 1;
	else   return 0;
}

ENTITIES *PORTS::GetFromModel(CString Port){
	if (Curr == NULL) return NULL;
	return Curr->FromModel;
}

ENTITIES *PORTS::GeToModel(CString Port){
	if (Curr == NULL) return NULL;
	return Curr->ToModel;
}

ENTITIES *PORTS::FindFirstFromModel(CString Port){
	Curr = Head;
	return FindNextFromModel(Port);
}

ENTITIES *PORTS::FindFirstToModel(CString Port){
	Curr = Head;
	return FindNextToModel(Port);
}

ENTITIES *PORTS::FindNextFromModel(CString Port){
	PortPair *p;

	if (Curr == NULL) return NULL;

	do {
		if (Curr->FromPort == Port) break;
		if (Curr == Tail) { Curr = NULL; return NULL; }
		else Curr = Curr->Next;
	} while(1);

	p = Curr;
	if (Curr == Tail) Curr = NULL;
	else Curr = Curr->Next;
	return p->FromModel;
}

ENTITIES *PORTS::FindFirstFromToModel(CString Port){
	Curr = Head;
	return FindNextFromToModel(Port);
}

ENTITIES *PORTS::FindNextFromToModel(CString Port){
	PortPair *p;

	if (Curr == NULL) return NULL;

	do {
		if (Curr->FromPort == Port) break;
		if (Curr == Tail) { Curr = NULL; return NULL; }
		else Curr = Curr->Next;
	} while(1);

	p = Curr;
	if (Curr == Tail) Curr = NULL;
	else Curr = Curr->Next;
	return p->ToModel;
}

ENTITIES *PORTS::FindNextToModel(CString Port){
	PortPair *p;

	if (Curr == NULL) return NULL;

	do {
		if (Curr->ToPort == Port) break;
		if (Curr == Tail) { Curr = NULL; return NULL; }
		else Curr = Curr->Next;
	} while(1);

	p = Curr;
	if (Curr == Tail) Curr = NULL;
	else Curr = Curr->Next;
	return p->ToModel;
}

PortPair *PORTS::FindFirstPair(CString Port){
	Curr = Head;
	return FindNextPair(Port);
}

PortPair *PORTS::FindNextPair(CString Port){
	PortPair *p;

	if (Curr == NULL) return NULL;

	do {
		if (Curr->FromPort == Port) break;
		if (Curr == Tail) { Curr = NULL; return NULL; }
		else Curr = Curr->Next;
	} while(1);

	p = Curr;
	if (Curr == Tail) Curr = NULL;
	else Curr = Curr->Next;
	return p;
}
