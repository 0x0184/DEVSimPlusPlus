#pragma once

#include "stdafx.h"
#include "coupled.h"
#include "message.h"

class DIGRAPH : public COUPLED {
public:
	ListElement *P;
public:
	DIGRAPH(CString );
	DIGRAPH(char *);

	void IntTransition(double);
	void IntTransition(void);
	void Inject(MODELS *, DevsMessage,double);
	void Output(double);
	void Inject(DevsMessage);
    void Inject(DevsMessage,double);
    void Output(void);

	void InitialModel(void);
	void Done(MODELS *, double);
	void DoneInit(MODELS *, double);

	double GetMinTime(void);
};
