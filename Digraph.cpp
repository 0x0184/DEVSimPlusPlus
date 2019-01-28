#include "stdafx.h"
#include "Digraph.h"
DIGRAPH::DIGRAPH(CString EName) : COUPLED(EName) { SetClassName("Digraph"); }
DIGRAPH::DIGRAPH(char *EName) : COUPLED(EName) { SetClassName("Digraph"); }

void DIGRAPH::IntTransition(double Time){
	if (Time != GetNextEventTime()) return;

	SetLastEventTime(Time);

	P = Children.FindFirstList(Time);
	if (P == NULL) return;

	do {
		P->Model->IntTransition(Time);
		P = Children.FindNextList(Time);
		if (P == NULL) break;
	} while(1);
}

/* --------------- Body of Inject Function in Atomic model --------------------
     if ((Time < GetLastEventTime()) || (Time > GetNextEventTime())) return;
	 SetInMessage(MSG);
	 ElapsedTime = Time - GetLastEventTime();
	 ExtTransitionFN(ElapsedTime,MSG);
	 SetLastEventTime(Time);
	 SetNextEventTime(AddTime(GetLastEventTime(),Sigma));

	 if (Parent) Parent->Done((MODELS *)this,GetNextEventTime());
*/

void DIGRAPH::Inject(MODELS *From, DevsMessage MSG, double Time){
	 PortPair *PPair, *Temp;
	 CString  PPort;

	 if ((From == this) && (Parent)) Parent->Inject(this,MSG,Time);

	 PPort = MSG.ContentPort();
	 PPair = Ports.FindFirstPair(PPort);
	 Temp = Ports.Curr;

	 do {
	 	if (PPair == NULL) break;

		OutMessage.MakeContent(PPair->ToPort,MSG.ContentValue());
		if ((PPair->FromModel == From) || (From == Parent))
		   ((MODELS *)(PPair->ToModel))->Inject(this,OutMessage,Time);
		Ports.Curr = Temp;
		PPair = Ports.FindNextPair(PPort);
		Temp = Ports.Curr;
	 } while(1);
}

void DIGRAPH::Output(double Time){}

void DIGRAPH::InitialModel(void){
	 Children.AllInitial();
	 if (Parent) Parent->DoneInit(this,GetMinTime());
	 SetNextEventTime(GetMinTime());
}

void DIGRAPH::Done(MODELS *M, double T){ 
     Children.SetOne(M,T); 
	 SetNextEventTime(GetMinTime());
	 if (Parent) Parent->Done(this,GetMinTime());
}

void DIGRAPH::DoneInit(MODELS *M, double T){ 
     Children.SetOne(M,T); 
}

double DIGRAPH::GetMinTime(void){ return Children.GetMinTime(); }

void DIGRAPH::IntTransition(void) {}
void DIGRAPH::Inject(DevsMessage MSG) {
	 Inject(this,MSG,GetNextEventTime());
}

void DIGRAPH::Inject(DevsMessage MSG, double T) {
	 Inject(this,MSG,T);
}

void DIGRAPH::Output(void) {}