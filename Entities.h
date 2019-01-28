#pragma once
#include "stdafx.h"
#include <iostream>

class ENTITIES {
public:	
	CString ClassName;
	CString Name;
	int     GettableChildren;

public:
    ENTITIES(CString);
	ENTITIES(char *);
	ENTITIES();

	void SetClassName(CString);
	void SetClassName(char *);
	void SetName(CString);
	void SetName(char *);
	
	CString GetClassName(void);
	CString GetName(void);
};
