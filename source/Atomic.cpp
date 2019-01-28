#include "stdafx.h"
#include "Atomic.h"

ATOMIC::ATOMIC() : MODELS(){ 
	SetClassName("Atomic");
	ElapsedTime = (double)0.0;
	SetLastEventTime((double)0.0);
	SetNextEventTime(INF);
	Passivate(); 
}

ATOMIC::ATOMIC(CString EName) : MODELS(EName) { 
	SetClassName("Atomic");
	ElapsedTime = (double)0.0;
	SetLastEventTime((double)0.0);
	SetNextEventTime(INF);
	Passivate(); 
}

ATOMIC::ATOMIC(char *EName) : MODELS(EName) { 
	SetClassName("Atomic");
	ElapsedTime = (double)0.0;
	SetLastEventTime((double)0.0);
	SetNextEventTime(INF);
	Passivate(); 
}

ATOMIC::ATOMIC(CString EName, MODELS *PModel) : MODELS(EName,PModel) { 
	SetClassName("Atomic");
	ElapsedTime = (double)0.0;
	SetLastEventTime((double)0.0);
	SetNextEventTime(INF);
	Passivate(); 
}

ATOMIC::ATOMIC(char *EName, MODELS *PModel) : MODELS(EName,PModel) { 
	SetClassName("Atomic");
	ElapsedTime = (double)0.0;
	SetLastEventTime((double)0.0);
	SetNextEventTime(INF);
	Passivate(); 
}


double ATOMIC::AddSigma(double S) {
	if (Sigma == INF) return INF;
	Sigma += S;
	return Sigma;
}

double ATOMIC::SubSigma(double S){
	if (Sigma == INF) return INF;
	Sigma -= S;
	return Sigma;
}

double ATOMIC::AddTime(double T1, double T2) {
	if ((T1 == INF) || (T2 == INF)) return INF;
	return T1 + T2;
}

double ATOMIC::SubTime(double T1, double T2) {
	if ((T1 == INF) || (T2 == INF)) return INF;
	return T1 - T2;
}

void ATOMIC::HoldIn(CString P, double S){
	Phase = P;
	Sigma = S;
}
void ATOMIC::HoldIn(const char* P, double S){
	Phase = P;
	Sigma = S;
}

void ATOMIC::HoldIn(CString P, int S){
	Phase = P;
	Sigma = (double)S;
}

void ATOMIC::PassivateIn(CString P)  { HoldIn(P,INF); }
void ATOMIC::Passivate(void)        { HoldIn("passive",INF); }
void ATOMIC::Continue(void)         { HoldIn(Phase,SubTime(Sigma,ElapsedTime)); }

void ATOMIC::InitialModel(void){
	InitializeFN();
	SetNextEventTime(Sigma);
	if (Parent) Parent->DoneInit((MODELS *)this,GetNextEventTime());
}

void ATOMIC::Inject(MODELS *S, DevsMessage MSG, double Time){ Inject(MSG,Time); }
void ATOMIC::Inject(DevsMessage MSG){ Inject(MSG,GetNextEventTime());}
void ATOMIC::Inject(DevsMessage MSG, double Time){
	if ((Time < GetLastEventTime()) || (Time > GetNextEventTime())) return;
	SetInMessage(MSG);
	ElapsedTime = Time - GetLastEventTime();
	ExtTransitionFN(ElapsedTime,MSG);
	SetLastEventTime(Time);
	SetNextEventTime(AddTime(GetLastEventTime(),Sigma));

	if (Parent) Parent->Done((MODELS *)this,GetNextEventTime());
}

void ATOMIC::IntTransition(void){ IntTransition(GetNextEventTime()); }
void ATOMIC::IntTransition(double Time){
	if (Time != GetNextEventTime()) return;
	Output(Time);
	IntTransitionFN();									  
	SetLastEventTime(Time);
	SetNextEventTime(AddTime(GetLastEventTime(),Sigma));
	if (Parent) Parent->Done((MODELS *)this,GetNextEventTime());
}

void ATOMIC::MakeContent(void){ return; }
void ATOMIC::MakeContent(CString Port, VOID *MSG){
	CString OPort;

	OutMessage.MakeContent(Port,MSG);
	if (Parent) {
		OutMessage.MakeContent(Port,MSG);
		Parent->Inject(this,OutMessage,GetNextEventTime());
	}
	return;
}

void ATOMIC::MakeContent(const char* Port, VOID *MSG){
	CString OPort;

	OutMessage.MakeContent((CString)Port,MSG);
	if (Parent) {
		OutMessage.MakeContent((CString)Port,MSG);
		Parent->Inject(this,OutMessage,GetNextEventTime());
	}
	return;
}

void ATOMIC::Output(void){ Output(GetNextEventTime()); }
void ATOMIC::Output(double Time){
	double Temp = GetNextEventTime();
	SetNextEventTime(Time);
	OutputFN();
	SetNextEventTime(Temp);
}

void ATOMIC::Done(MODELS *P, double Time){ return; }
void ATOMIC::DoneInit(MODELS *P, double Time){ return; }

