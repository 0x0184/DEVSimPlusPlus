#include "stdafx.h"
#include "message.h"
DevsMessage::~DevsMessage(){
	return;
}

void DevsMessage::MakeContent(char *P, VOID *V){
	Port = P;
	Value = V;
}

void DevsMessage::MakeContent(CString P, VOID *V){
	Port = P;
	Value = V;
}

void DevsMessage::MakeContent(void){
	Port = "";		   
	Value = NULL;
}


CString DevsMessage::ContentPort(void){
	return Port;
}

VOID *DevsMessage::ContentValue(void){
	return Value;
}