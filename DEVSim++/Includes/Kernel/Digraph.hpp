#ifndef __DIGRAPH_HPP__
#define __DIGRAPH_HPP__

#include "Coupled.hpp"
#include "Message.hpp"

class Digraph : public Coupled {
private:
	ListElement *P;
public:
	Digraph(std::string);

	double GetMinTime(void);

	void IntTransition(void);
	void IntTransition(double);

	void Inject(DevsMessage);
	void Inject(DevsMessage, double);
	void Inject(Model*, DevsMessage, double);

	void InitialModel(void);
	void Done(Model*, double);
	void DoneInit(Model*, double);
};

#endif	// __DIGRAPH_HPP__