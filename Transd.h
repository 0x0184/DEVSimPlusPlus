#pragma once
#include "stdafx.h"
#include "Tglobal.h"
#include "atomic.h"

typedef struct {
    CString ID;
	double  Time;
} JOB;

typedef struct {
    JOB Jobs[100];
	int Num;
} JOBS;

class Transd : public ATOMIC {
public:
    CString JobID;
	double  clock;
    JOBS    Arrive, Solve;

public:
	Transd(CString);
	Transd(char *);

    void ExtTransitionFN(double,DevsMessage);
	void IntTransitionFN(void);
	void OutputFN(void);
	void InitializeFN(void);

	void PrintArrive(void);
	void PrintSolve(void);
};



