#ifndef __MODEL_HPP__
#define __MODEL_HPP__

#include "Entity.hpp"
#include "Port.hpp"
#include "Message.hpp"

class Model : public Entity {
protected:
	Model *Parent;
	PORTS  Ports;
	double LastEventTime;
	double NextEventTime;
	DevsMessage InMessage;
	DevsMessage OutMessage;
public:
    Model();
	Model(std::string);
    Model(std::string, Model*);

	int AddCoupling(Model*, Model*, std::string, std::string);

	Model* GetParent(void);
	void SetParent(Model*);

	double GetLastEventTime(void);
	void SetLastEventTime(double);
	double GetNextEventTime(void);
	void SetNextEventTime(double);

	DevsMessage GetInMessage(void);
	void SetInMessage(DevsMessage);
	DevsMessage GetOutMessage(void);
	void SetOutMessage(DevsMessage);

    virtual void IntTransition(void)=0;
	virtual void IntTransition(double)=0;
	virtual void Inject(Model*, DevsMessage, double)=0;

	virtual void Inject(DevsMessage, double)=0;
	virtual void Inject(DevsMessage)=0;

	virtual void InitialModel(void)=0;
	virtual void Done(Model*, double)=0;
	virtual void DoneInit(Model*, double)=0;
};

#endif	// __MODEL_HPP__