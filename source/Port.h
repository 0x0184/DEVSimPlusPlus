#pragma once

#include "stdafx.h"
#include "entities.h"

typedef struct nd {
	 CString FromPort, 
	         ToPort;
	 ENTITIES *FromModel,
	          *ToModel;
	 struct nd *Next, *Before;
} PortPair;

class PORTS {
public:
	 PortPair *Head, *Tail, *Curr;

public:
     PORTS();
	 ~PORTS();

	 int  AddCoupling(ENTITIES *, ENTITIES *, CString , CString);
	 int  DelFromPort(CString);
	 int  DelToPort(CString);
	 void DelCurrentCoupling(void);
	 void DelAllCoupling(void);

	 int  IsInFromPort(CString);
	 int  IsInToPort(CString);

	 ENTITIES *GetFromModel(CString);
	 ENTITIES *GeToModel(CString);

	 ENTITIES *FindFirstFromModel(CString);
	 ENTITIES *FindFirstToModel(CString);

	 ENTITIES *FindNextFromModel(CString);
	 ENTITIES *FindNextToModel(CString);

	 ENTITIES *FindFirstFromToModel(CString);
	 ENTITIES *FindNextFromToModel(CString);

	 PortPair *FindFirstPair(CString);
	 PortPair *FindNextPair(CString);
	 
};