#pragma once
#include "stdafx.h"
#include "Tglobal.h"
#include "Entstr.h"

#include "genr.h"
#include "Transd.h"
#include "Process.h"

ENTSTR * EFP;
void MakeSES(void)
{	

	EFP = new ENTSTR("ef-p");
	EFP->AddItem(new Process("Process"));
	EFP->AddItem(new DIGRAPH("ef"));

	EFP->AddCouple("ef", "Process", "OUT", "in");
	EFP->AddCouple("Process","ef", "out", "IN");           

	EFP->SetCurrentItem("ef");
	EFP->AddItem(new GENR("genr"));
	EFP->AddItem(new Transd("transd"));
	EFP->AddCouple("ef", "transd", "IN", "solved");
	EFP->AddCouple("transd", "genr", "out", "stop");

	EFP->AddCouple("genr", "ef", "out", "OUT");            
	EFP->AddCouple("genr", "transd", "out", "arriv");
}
void StartSimulation()
{
	EFP->Restart();
}