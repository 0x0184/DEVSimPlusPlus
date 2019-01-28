#include "stdafx.h"
#include "process.h"


Process::Process(CString EName) : ATOMIC(EName) { 
    SetName(EName); 
}

Process::Process(char *EName) : ATOMIC(EName)  { 
    SetName(EName); 
}

void Process::ExtTransitionFN(double Time, DevsMessage MSG) {
	Display(Name); Display("(EXT) --> ");
	if (MSG.ContentPort() == "in") {

		// Put job into the Queue
		if(Tail < 50)
		{
			Queue[Tail++] = *((CString *)(MSG.ContentValue()));
			Display(MSG.ContentPort()); Display(":"); Display(JobID);
		}
		
		if (Phase == "busy"){
			Continue();
		}
		else
		{
			if(Front != Tail)
				HoldIn("busy",0.0);
		}
	}
	else Continue();
	NewLine();
}

void Process::IntTransitionFN(void) {
	Display(Name); Display("(INT) --> ");
	if (Phase == "busy"){
		// Get job from the Queue
		if(Front != Tail)
		{
			// processing
			JobID = Queue[Front++];
			Display(" process : "); Display(JobID);
			HoldIn("busy",PTime);
		}
		else
			Passivate();
	}
	else Continue();
	NewLine();
}

void Process::OutputFN(void) {
	Display(Name); Display("(OUT) --> ");
	
	if (Phase == "busy"){ 
		MakeContent("out",&JobID);
	}
	else MakeContent();
	NewLine();
}

void Process::InitializeFN(void){
	PTime = (double)7.0;
	Passivate();
	Front = Tail = 0;
}