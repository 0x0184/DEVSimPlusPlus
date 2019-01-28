#pragma once
#include "stdafx.h"
#include "models.h"

typedef struct Lnd {
	CString  Name;
	MODELS *Address;
	struct Lnd *Before, 
	           *Next;
} ListElem;

class List {
public:
	 ListElem *Head, *Tail, *Curr;
	 int  Len;

public : 
	 List();
	 ~List();

	 void AddModel(CString, MODELS *);
	 void AddModel(char *, MODELS *);

	 int  Length(void);
	 int  IsEmpty(void);
	 int  IsIn(CString);
	 int  IsIn(char *);

	 int  Delete(CString);
	 int  Delete(char *);
	 void DeleteAll(void);

	 ListElem *FindFirst(CString);
	 ListElem *FindFirst(char *);

	 MODELS *GetModel(CString);
	 MODELS *GetModel(char *);
};