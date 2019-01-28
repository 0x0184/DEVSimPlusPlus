#pragma once

#include "stdafx.h"
#include "entities.h"
#include "port.h"
#include "message.h"

class MODELS : public ENTITIES {
public:
	MODELS *Parent;
	
	PORTS   Ports;
	
	double LastEventTime;
	double NextEventTime;

	DevsMessage InMessage,
	            OutMessage;

public:
    MODELS();
    MODELS(CString );
    MODELS(char *);
    
    MODELS(CString, MODELS *);
    MODELS(char *, MODELS *);

	void         SetParent(MODELS *);
	MODELS      *GetParent(void);

	int          AddCoupling(MODELS *, MODELS *, CString, CString);

	double       GetLastEventTime(void);
	double       GetNextEventTime(void);

	void         SetLastEventTime(double);
	void         SetNextEventTime(double);

	DevsMessage  GetInMessage(void);
	void         SetInMessage(DevsMessage);
	DevsMessage  GetOutMessage(void);
	void         SetOutMessage(DevsMessage);

    virtual void IntTransition(void)=0;
	virtual void IntTransition(double)=0;
	virtual void Inject(MODELS *,DevsMessage,double)=0;

	virtual void Inject(DevsMessage,double)=0;
	virtual void Inject(DevsMessage)=0;
	virtual void Output(void)=0;
	virtual void Output(double)=0;

	virtual void InitialModel(void)=0;
	virtual void Done(MODELS *, double)=0;
	virtual void DoneInit(MODELS *, double)=0;
};