#ifndef __PROCESS_HPP__
#define __PROCESS_HPP__

#include "Kernel/Log.hpp"
#include "Kernel/Atomic.hpp"

class Process : public Atomic {
public:
    std::string JobID;
	double PTime;
    std::string Queue[50];
    int Front,Tail;
public:
	Process(std::string entity_name);

    void ExtTransitionFN(double, DevsMessage);
	void IntTransitionFN(void);
	void OutputFN(void);
	void InitializeFN(void);
};

#endif	// __PROCESS_HPP__