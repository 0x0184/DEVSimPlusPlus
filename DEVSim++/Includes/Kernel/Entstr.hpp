#ifndef __ENTSTR_HPP__
#define __ENTSTR_HPP__

#include "Digraph.hpp"
#include "List.hpp"

class EntStr : public Digraph {
private:
	Model *CurrentItem;
	double Clock, LimitClock, CClock;
	List   ChildList;
public:
	EntStr(std::string);

	void SetLimit(double);
	void SetCurrentItem(Model*);
	void SetCurrentItem(std::string);
	Model* GetCurrentItem();
	void AddItem(Model*);
	void AddCouple(Model*, Model*, std::string, std::string);
	void AddCouple(std::string, std::string, std::string, std::string);

	double SetClock(double);
	double GetClock(void);
	double AddClock(double);

	void Initialize(void);
	void Restart(void);
	void StepStart(void);
	void OutputFN(double);

	void IntTransition(double);
	void Inject(std::string, std::string);

	void Done(Model*, double);
	void DoneInit(Model*, double);

	void IntTransition(void);
	void Output(double);
	void Output(void);
	void InitialModel(void);
};

#endif   // __ENTSTR_HPP__