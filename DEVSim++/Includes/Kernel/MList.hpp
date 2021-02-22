#ifndef __MLIST_HPP__
#define __MLIST_HPP__

#include "Log.hpp"
#include "Model.hpp"

typedef struct Mnd {
		Model* PModel;
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

     int  AddOne(Model*, double);
     int  AddOne(Model*);

	 int  DelOne(std::string);
	 int  DelOne(Model*);
	 void DelAll(void);

	 int  IsIn(std::string);
	 int  IsIn(Model*);

	 ListElement *FindFirstList(std::string);
	 ListElement *FindFirstList(Model*);

	 ListElement *FindNextList(std::string);
	 ListElement *FindNextList(Model*);

	 ListElement *FindFirstList(double );
	 ListElement *FindNextList(double );

	 void SetOne(std::string, double);
	 void SetOne(Model*, double); 
	 
	 double GetOne(std::string);
	 double GetOne(Model*);
	 
	 double GetMinTime(void);
	 void   AllInitial(void);         
	 void   DisplayMinTime(void);
};

#endif	// __MLIST_HPP__