#ifndef __LIST_HPP__
#define __LIST_HPP__

#include "Model.hpp"

typedef struct Lnd {
	std::string  Name;
	Model *Address;
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

	 void AddModel(std::string, Model *);

	 int  Length(void);
	 int  IsEmpty(void);
	 int  IsIn(std::string);

	 int  Delete(std::string);
	 void DeleteAll(void);

	 ListElem *FindFirst(std::string);

	 Model *GetModel(std::string);
};

#endif	// __LIST_HPP__