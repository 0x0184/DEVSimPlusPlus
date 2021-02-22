#ifndef __TRANSDUCER_HPP__
#define __TRANSDUCER_HPP__

#include "Kernel/Log.hpp"
#include "Kernel/Atomic.hpp"

typedef struct {
    std::string ID;
    double  Time;
} JOB;

typedef struct {
    JOB Jobs[100];
    int Num;
} JOBS;

class Transducer : public Atomic {
public:
    std::string JobID;
    double  clock;
    JOBS    Arrive, Solve;

public:
	Transducer(std::string);

    void ExtTransitionFN(double, DevsMessage);
	void IntTransitionFN(void);
	void OutputFN(void);
	void InitializeFN(void);

	void PrintArrive(void);
	void PrintSolve(void);
};

#endif	// __TRANSDUCER_HPP__