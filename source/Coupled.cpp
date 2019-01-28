#include "stdafx.h"
#include "Coupled.h"

COUPLED::COUPLED(CString EName) : MODELS(EName){ 
	GettableChildren = 1;
	return; 
}

COUPLED::COUPLED(char *EName) : MODELS(EName){ 
	GettableChildren = 1;
	return; 
}

void COUPLED::AddChild(MODELS *M){ Children.AddOne(M); }
void COUPLED::AddChild(MODELS *M, double T) { Children.AddOne(M,T); }
int  COUPLED::IsDevsChild(MODELS *M) { return Children.IsIn(M); }
int  COUPLED::NumOfChild(void)   { return Children.GetLength(); }