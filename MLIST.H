#pragma once
#include "stdafx.h"
#include "Tglobal.h"
#include "models.h"

typedef struct Mnd {
		MODELS *Model;
		double WaitTime;
		struct Mnd *Next, *Before;
} ListElement;

class MList {
	ListElement *Head, *Tail, *Curr;
	int  NumOfElement;

public:
     MList();
	 ~MList();

     int  GetLength(void);

     int  AddOne(MODELS *, double);
     int  AddOne(MODELS *);

	 int  DelOne(CString);
	 int  DelOne(MODELS *);
	 void DelAll(void);

	 int  IsIn(CString);
	 int  IsIn(MODELS *);

	 ListElement *FindFirstList(CString);
	 ListElement *FindFirstList(MODELS *);

	 ListElement *FindNextList(CString);
	 ListElement *FindNextList(MODELS *);

	 ListElement *FindFirstList(double );
	 ListElement *FindNextList(double );

	 void SetOne(CString, double);
	 void SetOne(MODELS *, double); 
	 
	 double GetOne(CString);
	 double GetOne(MODELS *);
	 
	 double GetMinTime(void);
	 void   AllInitial(void);         
	 void   DisplayMinTime(void);
};