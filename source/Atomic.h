#pragma once
#include "stdafx.h"
#include "models.h"
#include "devsdef.h"

class ATOMIC : public MODELS {
public :
    double  Sigma;
	double  ElapsedTime;
    CString Phase;

public:
    ATOMIC();
    ATOMIC(CString );
    ATOMIC(char *);
    
    ATOMIC(CString, MODELS *);
    ATOMIC(char *, MODELS *);

    void         HoldIn(CString, double);
	void		 HoldIn(const char*, double);
	void         HoldIn(CString, int);
	void         PassivateIn(CString);
	void         Passivate(void);
	void         Continue(void);

	double       AddSigma(double);
	double       SubSigma(double);
	double       AddTime(double, double);
	double       SubTime(double, double);

    void         IntTransition(void);
	void         IntTransition(double);
	void         Inject(MODELS *,DevsMessage,double);
	void         Inject(DevsMessage,double);
	void         Inject(DevsMessage);
	void         Output(void);
	void         Output(double);

	void         MakeContent(void);
	void         MakeContent(CString, VOID *);
	void         MakeContent(const char*, VOID *);
	void         InitialModel(void);
	void         Done(MODELS *, double);
	void         DoneInit(MODELS *, double);

    virtual void ExtTransitionFN(double,DevsMessage )=0;
	virtual void IntTransitionFN(void)=0;
	virtual void OutputFN(void)=0;
	virtual void InitializeFN(void)=0;
};
