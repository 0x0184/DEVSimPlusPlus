#include "stdafx.h"
#include "Entstr.h"
ENTSTR::ENTSTR(CString EName) : DIGRAPH(EName) {
	SetClassName("ENTSTR");
	SetName(EName);
	ChildList.AddModel(EName,this);
	CurrentItem = this;
	SetClock((double)0.0);
	LimitClock = INF;
	CClock = 0.0;
}

ENTSTR::ENTSTR(char *EName) : DIGRAPH(EName) {
	SetClassName("ENTSTR");
	SetName(EName);
	ChildList.AddModel(EName,this);
	CurrentItem = this;
	SetClock((double)0.0);
	LimitClock = INF;
	CClock = 0.0;
}


void ENTSTR::SetLimit(double T){
	LimitClock = T;
}

double ENTSTR::SetClock(double T){
	Clock = T;
	return T;
}

double ENTSTR::GetClock(void){ return Clock; }

double ENTSTR::AddClock(double T){
	if ((Clock == INF) || (T == INF)) return SetClock(INF);
	Clock += T;
	if (Clock < 0) return SetClock(INF);
	return GetClock();
}

int  ENTSTR::SCI(MODELS *Curr){ return SetCurrentItem(Curr); }
int  ENTSTR::SetCurrentItem(MODELS *Curr){
	CurrentItem = Curr;
	return 1;
}

int  ENTSTR::SCI(CString Curr){ return SetCurrentItem(Curr); }

int  ENTSTR::SetCurrentItem(CString Curr){
	MODELS *p;
	p = ChildList.GetModel(Curr);
	if (p == NULL) return 0;
	CurrentItem = p;
	return 1;
}

int  ENTSTR::SetCurrentItem(const char* Curr){
	MODELS *p;
	p = ChildList.GetModel((CString)Curr);
	if (p == NULL) return 0;
	CurrentItem = p;
	return 1;
}


int  ENTSTR::AddItem(MODELS *M){
	if (M == NULL)
		MessageBox (GetFocus(), (LPCWSTR)"Null pointer assigned", (LPCWSTR)"DLL", MB_OK | MB_SYSTEMMODAL);
	// MessageBox()의 2,3번째 매개변수를 LPCWSTR로 탑입캐스팅함 by Shin
	ASSERT(M != NULL);
	if (CurrentItem == this) {
		if (((ENTSTR *)CurrentItem)->IsDevsChild(M)) return 0;
		((ENTSTR *)CurrentItem)->AddChild(M);
		ChildList.AddModel(M->GetName(),M);
		M->SetParent(CurrentItem);
		return 1;
	}
	else {
		if (((COUPLED *)CurrentItem)->IsDevsChild(M)) return 0;
		((COUPLED *)CurrentItem)->AddChild(M);
		ChildList.AddModel(M->GetName(),M);
		M->SetParent(CurrentItem);
		return 1;
	}
}

int  ENTSTR::AddCouple(MODELS *FModel, MODELS *TModel, CString FPort, CString TPort){
	CurrentItem->AddCoupling(FModel, TModel, FPort, TPort);
	return 1;
}

int  ENTSTR::AddCouple(MODELS *FModel, MODELS *TModel, char *FPort, char *TPort){
	CurrentItem->AddCoupling(FModel, TModel, (CString)FPort, (CString)TPort);
	//AddCoupling()의 3,4번째 매개변수를 CString으로 타입캐스팅 by shin
	return 1;
}

int  ENTSTR::AddCouple(CString FModel, CString TModel, CString FPort, CString TPort){
	MODELS *F, *T;

	F = ChildList.GetModel(FModel);
	T = ChildList.GetModel(TModel);

	if ((F == NULL) || (T == NULL)) return 0;

	AddCouple(F,T,FPort,TPort);
	return 1;
}

int  ENTSTR::AddCouple(char *FModel, char *TModel, char *FPort, char *TPort){
	MODELS *F, *T;

	F = ChildList.GetModel(FModel);
	T = ChildList.GetModel(TModel);

	if ((F == NULL) || (T == NULL)) return 0;

	AddCouple(F,T,FPort,TPort);
	return 1;
}


void ENTSTR::Initialize(void){ 
	Children.AllInitial(); 
	Clock = 0.0;
}

void ENTSTR::Restart(void){
	double Time;
	ListElement *P;

	Initialize();
	Clock = (double)0.0;

	do {
		StepStart();
		Time = Children.GetMinTime();
		SetClock(Time); 
		if (Time == INF) break;
		if (Time > LimitClock) break;
		P = Children.FindFirstList(Time);
		if (P == NULL) break;
	} while(1);
}

void ENTSTR::StepStart(void){
	double Time, TTime;
	ListElement *P;

	CClock = Children.GetMinTime();
	TTime = CClock;

	do {
		Time = Children.GetMinTime();
		if (CClock != Time) break;
		SetClock(Time); 
		if (Time == INF) break;
		if (Time > LimitClock) break;
		P = Children.FindFirstList(Time);
		if (P == NULL) break;
		P->Model->IntTransition(Time);
	} while(1);


	Display("One step ended..."); 
	OutputFN(TTime);
}


void ENTSTR::IntTransition(double T){ return; }

void ENTSTR::Inject(CString P, void *V){ 
	OutMessage.MakeContent(P,V);
	DIGRAPH::Inject(OutMessage,(double)0.0);
}

void ENTSTR::Inject(char *P, void *V){ 
	OutMessage.MakeContent(P,V);
	DIGRAPH::Inject(OutMessage,(double)0.0);
}

void ENTSTR::DoneInit(MODELS *M, double T){ Children.SetOne(M,T); }
void ENTSTR::Done(MODELS *M, double T)    { Children.SetOne(M,T); }

void ENTSTR::IntTransition(void) {}
void ENTSTR::Output(double T) {}
void ENTSTR::Output(void) {}
void ENTSTR::InitialModel(void) {}

int  ENTSTR::OutputFN(double clk) {
	char ttt[1024];
	sprintf(ttt,"Global Clock (Root): %lf",clk);
	Display(ttt); NewLine();
	return 1;
}