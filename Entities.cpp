#include "stdafx.h"
#include "Entities.h"

ENTITIES::ENTITIES(char *ename){
	SetClassName("ENTITIES");
	SetName(ename);
}

ENTITIES::ENTITIES(CString ename){
	SetClassName("ENTITIES");
	SetName(ename); 
	GettableChildren = 0;
}

ENTITIES::ENTITIES(){
	SetClassName("ENTITIES");
	SetName("");
	GettableChildren = 0;
}

void ENTITIES::SetClassName(CString CName){
	ClassName = CName;
}

void ENTITIES::SetClassName(char *CName){
	ClassName = CName;
}

void ENTITIES::SetName(CString EName){
	Name = EName;
}

void ENTITIES::SetName(char *EName){
	Name = EName;
}

CString ENTITIES::GetClassName(void){
	return ClassName;
}

CString ENTITIES::GetName(void){
	return Name;
}