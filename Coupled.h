#pragma once
#include "stdafx.h"
#include "models.h"
#include "mlist.h"

class COUPLED : public MODELS {
public:
   MList Children;

public:
   COUPLED(CString);
   COUPLED(char *);

   void AddChild(MODELS *);
   void AddChild(MODELS *, double);
   int  IsDevsChild(MODELS *);
   int  NumOfChild(void);
};



