#include "../../Includes/Kernel/Port.hpp"

#include "../../Includes/Kernel/Entity.hpp"

PORTS::PORTS(){
	Head = Tail = Curr = nullptr;
}

PORTS::~PORTS(){
	DelAllCoupling();
}

int  PORTS::AddCoupling(Entity *From, Entity *To, std::string FPort, std::string TPort){
	PortPair *Temp;

	Temp = new PortPair;

	if (Temp == nullptr) return 0;

	Temp->FromModel = From;
	Temp->ToModel   = To;
	Temp->FromPort  = FPort;
	Temp->ToPort    = TPort;
	Temp->Next      = nullptr;
	Temp->Before    = nullptr;

	if (Head == nullptr){
		Head = Temp; Tail = Temp;
	}
	else {
		Tail->Next   = Temp;
		Temp->Before = Tail;
		Tail         = Temp;
	}

	return 1;
}

int  PORTS::DelFromPort(std::string Port){
	Entity *p;

	p = FindFirstFromModel(Port);
	if (p == nullptr) return 0;

	do {
		DelCurrentCoupling();
		p = FindNextFromModel(Port);
	} while (p != nullptr);

	return 1;
}

int  PORTS::DelToPort(std::string Port){
	Entity *p;

	p = FindFirstToModel(Port);
	if (!p) return 0;

	do {
		DelCurrentCoupling();
		p = FindNextToModel(Port);
	} while (p);

	return 1;
}

void PORTS::DelCurrentCoupling(void){
	PortPair *p;

	if (Curr == nullptr) ;
	else 
		if (Curr == Head) {
			if (Head == Tail){ Head = Tail = nullptr; }
			else             { Head->Next->Before = nullptr; Head = Head->Next;  }
			delete Curr;
			Curr = Head;
		}
		else
			if (Curr == Tail) {
				if (Head == Tail){ Head = Tail = nullptr; }
				else             { Tail->Before->Next = nullptr; Tail = Tail->Before; }
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

	if (Head == nullptr) return;

	p = q = Head;

	while (p != Tail) {
		p = p->Next;
		q = p->Before;
		delete q;
	}

	delete p;

	Head = Tail = Curr = nullptr;
}

int  PORTS::IsInFromPort(std::string Port){
	Entity *T;

	T = FindFirstFromModel(Port);
	if (T) return 1;
	else   return 0;
}

int  PORTS::IsInToPort(std::string Port){
	Entity *T;

	T = FindFirstToModel(Port);
	if (T) return 1;
	else   return 0;
}

Entity *PORTS::GetFromModel(std::string Port){
	if (Curr == nullptr) return nullptr;
	return Curr->FromModel;
}

Entity *PORTS::GeToModel(std::string Port){
	if (Curr == nullptr) return nullptr;
	return Curr->ToModel;
}

Entity *PORTS::FindFirstFromModel(std::string Port){
	Curr = Head;
	return FindNextFromModel(Port);
}

Entity *PORTS::FindFirstToModel(std::string Port){
	Curr = Head;
	return FindNextToModel(Port);
}

Entity *PORTS::FindNextFromModel(std::string Port){
	PortPair *p;

	if (Curr == nullptr) return nullptr;

	do {
		if (Curr->FromPort == Port) break;
		if (Curr == Tail) { Curr = nullptr; return nullptr; }
		else Curr = Curr->Next;
	} while (true);

	p = Curr;
	if (Curr == Tail) Curr = nullptr;
	else Curr = Curr->Next;
	return p->FromModel;
}

Entity *PORTS::FindFirstFromToModel(std::string Port){
	Curr = Head;
	return FindNextFromToModel(Port);
}

Entity *PORTS::FindNextFromToModel(std::string Port){
	PortPair *p;

	if (Curr == nullptr) return nullptr;

	do {
		if (Curr->FromPort == Port) break;
		if (Curr == Tail) { Curr = nullptr; return nullptr; }
		else Curr = Curr->Next;
	} while (true);

	p = Curr;
	if (Curr == Tail) Curr = nullptr;
	else Curr = Curr->Next;
	return p->ToModel;
}

Entity *PORTS::FindNextToModel(std::string Port){
	PortPair *p;

	if (Curr == nullptr) return nullptr;

	do {
		if (Curr->ToPort == Port) break;
		if (Curr == Tail) { Curr = nullptr; return nullptr; }
		else Curr = Curr->Next;
	} while (true);

	p = Curr;
	if (Curr == Tail) Curr = nullptr;
	else Curr = Curr->Next;
	return p->ToModel;
}

PortPair *PORTS::FindFirstPair(std::string Port){
	Curr = Head;
	return FindNextPair(Port);
}

PortPair *PORTS::FindNextPair(std::string Port){
	PortPair *p;

	if (Curr == nullptr) return nullptr;

	do {
		if (Curr->FromPort == Port) break;
		if (Curr == Tail) { Curr = nullptr; return nullptr; }
		else Curr = Curr->Next;
	} while (true);

	p = Curr;
	if (Curr == Tail) Curr = nullptr;
	else Curr = Curr->Next;
	return p;
}
