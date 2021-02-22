#ifndef __ATOMIC_HPP__
#define __ATOMIC_HPP__

#include "Model.hpp"
#include "DEVSDEF.h"

class Atomic : public Model {
protected:
    double  Sigma;
	double  ElapsedTime;
    std::string Phase;
public:
    Atomic();
    Atomic(std::string);
    Atomic(std::string, Model*);

	void         HoldIn(std::string, double);
	void         PassivateIn(std::string);
	void         Passivate(void);
	void         Continue(void);

	double       AddSigma(double);
	double       SubSigma(double);
	double       AddTime(double, double);
	double       SubTime(double, double);

    void         IntTransition(void);
	void         IntTransition(double);
	void         Inject(Model*, DevsMessage, double);
	void         Inject(DevsMessage, double);
	void         Inject(DevsMessage);
	void         Output(void);
	void         Output(double);

	void         MakeContent(void);
	void         MakeContent(std::string, std::string);
	void         InitialModel(void);
	void         Done(Model*, double);
	void         DoneInit(Model*, double);

    virtual void ExtTransitionFN(double, DevsMessage)=0;
	virtual void IntTransitionFN(void)=0;
	virtual void OutputFN(void)=0;
	virtual void InitializeFN(void)=0;
};

#endif	// __ATOMIC_HPP__