#include "stdafx.h"
#include "Models.h"

MODELS::MODELS(){
	SetClassName("MODELS");
	SetName("");
	Parent = NULL;
}

MODELS::MODELS(CString EName){
	SetClassName("MODELS");
	SetName(EName);
	Parent = NULL;
}

MODELS::MODELS(char *EName){
	SetClassName("MODELS");
	SetName(EName);
	Parent = NULL;
}

MODELS::MODELS(CString EName, MODELS *PModel){
	SetClassName("MODELS");
	SetName(EName);
	Parent = PModel;
}

MODELS::MODELS(char *EName, MODELS *PModel){
	SetClassName("MODELS");
	SetName(EName);
	Parent = PModel;
}

int MODELS::AddCoupling(MODELS *FModel, MODELS *TModel, CString FPort, CString TPort){
	return Ports.AddCoupling((ENTITIES *)FModel,(ENTITIES *)TModel,FPort,TPort);
}

double MODELS::GetLastEventTime(void){
	return LastEventTime;
}

double MODELS::GetNextEventTime(void){
	return NextEventTime;
}

void   MODELS::SetLastEventTime(double LTime){
	LastEventTime = LTime;
}

void   MODELS::SetNextEventTime(double NTime){
	NextEventTime = NTime;
}


DevsMessage MODELS::GetInMessage(void){
	return InMessage;
}

void   MODELS::SetInMessage(DevsMessage MSG){
	InMessage = MSG;
}

DevsMessage MODELS::GetOutMessage(void){
	return OutMessage;
}

void   MODELS::SetOutMessage(DevsMessage MSG){
	OutMessage = MSG;
}

void    MODELS::SetParent(MODELS *P){ Parent = P; }
MODELS *MODELS::GetParent(void) { return Parent; }
