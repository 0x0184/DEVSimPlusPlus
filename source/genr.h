#pragma once
#include "stdafx.h"
#include "Tglobal.h"
#include "atomic.h"

class GENR : public ATOMIC {
public:
	int     InterArrivalTime;
//	int     ProcessingTime;
//	int     ProblemLevel;
	int     Count;
	
public:
	GENR();
	GENR(CString);
	GENR(char *);

    void ExtTransitionFN(double,DevsMessage);
	void IntTransitionFN(void);
	void OutputFN(void);
	void InitializeFN(void);
};

