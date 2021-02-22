#ifndef __GENERATOR_HPP__
#define __GENERATOR_HPP__

#include "Kernel/Log.hpp"
#include "Kernel/Atomic.hpp"

class Generator : public Atomic {
public:
	int     InterArrivalTime;
//	int     ProcessingTime;
//	int     ProblemLevel;
	int     Count;
	
public:
	Generator();
	Generator(std::string);

    void ExtTransitionFN(double,DevsMessage);
	void IntTransitionFN(void);
	void OutputFN(void);
	void InitializeFN(void);
};

#endif	// __GENERATOR_HPP__