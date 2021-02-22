#ifndef __PORT_HPP__
#define __PORT_HPP__

#include "Entity.hpp"

typedef struct nd {
	 std::string FromPort, 
				ToPort;
	 Entity *FromModel,
	          *ToModel;
	 struct nd *Next, *Before;
} PortPair;

class PORTS {
public:
	 PortPair *Head, *Tail, *Curr;

public:
     PORTS();
	 ~PORTS();

	 int  AddCoupling(Entity *, Entity *, std::string, std::string);
	 int  DelFromPort(std::string);
	 int  DelToPort(std::string);
	 void DelCurrentCoupling(void);
	 void DelAllCoupling(void);

	 int  IsInFromPort(std::string);
	 int  IsInToPort(std::string);

	 Entity *GetFromModel(std::string);
	 Entity *GeToModel(std::string);

	 Entity *FindFirstFromModel(std::string);
	 Entity *FindFirstToModel(std::string);

	 Entity *FindNextFromModel(std::string);
	 Entity *FindNextToModel(std::string);

	 Entity *FindFirstFromToModel(std::string);
	 Entity *FindNextFromToModel(std::string);

	 PortPair *FindFirstPair(std::string);
	 PortPair *FindNextPair(std::string);
};

#endif	// __PORT_HPP__