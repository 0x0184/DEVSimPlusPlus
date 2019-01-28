#pragma once
#include "stdafx.h"
#include "digraph.h"
#include "list.h"

class ENTSTR : public DIGRAPH {
public:
   MODELS *CurrentItem;
   double Clock, LimitClock, CClock;
   List   ChildList;

public:
   ENTSTR(CString);
   ENTSTR(char *);

   void SetLimit(double);
   int  SetCurrentItem(MODELS *);
   int  SCI(MODELS *);
   int  SetCurrentItem(CString );
   int  SetCurrentItem(const char* );
   int  SCI(CString );
   int  AddItem(MODELS *);
   int  AddCouple(MODELS *, MODELS *, char *, char *);
   int  AddCouple(MODELS *, MODELS *, CString, CString);
   int  AddCouple(char *, char *, char *, char *);
   int  AddCouple(CString, CString, CString, CString);

   double SetClock(double );
   double GetClock(void);
   double AddClock(double );

   void Initialize(void);
   void Restart(void);
   void StepStart(void);
   int  OutputFN(double);

   void IntTransition(double );
   void Inject(char *, void *);
   void Inject(CString, void *);

   void Done(MODELS *, double);
   void DoneInit(MODELS *, double);

   void IntTransition(void);
   void Output(double);
   void Output(void);
   void InitialModel(void);
};