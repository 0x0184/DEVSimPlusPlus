#include "stdafx.h"
#include "genr.h"

GENR::GENR() : ATOMIC() {
	SetName("GENR");
}

GENR::GENR(CString EName) : ATOMIC(EName) {
	SetName(EName);
}

GENR::GENR(char *EName) : ATOMIC(EName) {
 	SetName(EName);
}

void GENR::ExtTransitionFN(double E, DevsMessage X){
	char GENRMessage[100]={0,}; 

	Display(Name); Display("(EXT) --> :");
	Display(X.ContentPort()); Display(": ");
	sprintf(GENRMessage,"When: %lf",AddTime(GetLastEventTime(),E));
	Display(GENRMessage);

	if (X.ContentPort() == "stop") Passivate();
	NewLine();
}

void GENR::IntTransitionFN(void){
	char GENRMessage[100]={0,}; 

	Display(Name); Display("(INT) --> ");
	sprintf(GENRMessage,"Sigma: %lf  When: %lf",Sigma, AddTime(GetLastEventTime(),Sigma));
	Display(GENRMessage);
	if (Phase == "busy") { HoldIn("busy", InterArrivalTime); }
	else { Passivate(); }
	NewLine();
}

void GENR::OutputFN(void){
	CString O;
	char Num[10]={0,};
	char GENRMessage[100]={0,}; 

	Display(Name); Display("(OUT) --> ");
	sprintf(GENRMessage,"Phase: %s  Sigma: %lf  When: %lf",Phase,Sigma,GetNextEventTime());
	Display(GENRMessage); NewLine();

	if (Phase == "busy"){
		 sprintf(Num,"%d",Count++);
		 O = "Job-";
		 O += Num;
		 MakeContent("out",&O);
	}
	else MakeContent();
}

void GENR::InitializeFN(void){
	InterArrivalTime = 3;
	Count = 0;

	HoldIn("busy",0.0);
}
