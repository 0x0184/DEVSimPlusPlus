#pragma once

#include "stdafx.h"
#include "devsdef.h"


class DevsMessage {
public:
	  CString   Port;
	  void     *Value;

public:
    ~DevsMessage();
    void      MakeContent(CString , VOID *); 
	void      MakeContent(char *, VOID *); 
	void      MakeContent(void);
	double    ContentTime(void);
	CString    ContentPort(void);
	VOID      *ContentValue(void);
};