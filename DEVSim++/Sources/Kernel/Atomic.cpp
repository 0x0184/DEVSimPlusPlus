#include "../../Includes/Kernel/Atomic.hpp"

Atomic::Atomic()
	: Atomic::Atomic("") { }

Atomic::Atomic(std::string entity_name)
	: Atomic::Atomic(entity_name, nullptr) { }

Atomic::Atomic(std::string entity_name, Model* parent) : Model(entity_name, parent) {
	SetClassName("Atomic");
	ElapsedTime = 0.0;
	SetLastEventTime(0.0);
	SetNextEventTime(INF);
	Passivate();
}

double Atomic::AddSigma(double sigma) {
	if (Sigma == INF) return INF;
	Sigma += sigma;
	return Sigma;
}

double Atomic::SubSigma(double sigma) {
	if (Sigma == INF) return INF;
	Sigma -= sigma;
	return Sigma;
}

double Atomic::AddTime(double time1, double time2) {
	if ((time1 == INF) || (time2 == INF)) return INF;
	return time1 + time2;
}

double Atomic::SubTime(double time1, double time2) {
	if ((time1 == INF) || (time2 == INF)) return INF;
	return time1 - time2;
}

void Atomic::HoldIn(std::string phase, double sigma) {
	Phase = phase;
	Sigma = sigma;
}

void Atomic::PassivateIn(std::string phase) {
	HoldIn(phase, INF);
}

void Atomic::Passivate(void) {
	HoldIn("passive", INF);
}

void Atomic::Continue(void) {
	HoldIn(Phase, SubTime(Sigma, ElapsedTime));
}

void Atomic::InitialModel(void) {
	InitializeFN();
	SetNextEventTime(Sigma);
	if (Parent) Parent->DoneInit((Model*) this, GetNextEventTime());
}

void Atomic::Inject(Model* S, DevsMessage message, double time) {
	Inject(message, time);
}

void Atomic::Inject(DevsMessage message) {
	Inject(message, GetNextEventTime());
}

void Atomic::Inject(DevsMessage message, double time) {
	if ((time < GetLastEventTime()) || (time > GetNextEventTime())) return;
	SetInMessage(message);
	ElapsedTime = time - GetLastEventTime();
	ExtTransitionFN(ElapsedTime, message);
	SetLastEventTime(time);
	SetNextEventTime(AddTime(GetLastEventTime(), Sigma));

	if (Parent) Parent->Done((Model*) this, GetNextEventTime());
}

void Atomic::IntTransition(void) {
	IntTransition(GetNextEventTime());
}

void Atomic::IntTransition(double time) {
	if (time != GetNextEventTime()) return;
	Output(time);
	IntTransitionFN();									  
	SetLastEventTime(time);
	SetNextEventTime(AddTime(GetLastEventTime(), Sigma));
	if (Parent) Parent->Done((Model*) this, GetNextEventTime());
}

void Atomic::MakeContent(void) {
	/**
	 * TODO: Not implemented.
	 */
}

void Atomic::MakeContent(std::string port, std::string message) {
	OutMessage.MakeContent(port, message);
	if (Parent) {
		OutMessage.MakeContent(port, message);
		Parent->Inject(this, OutMessage, GetNextEventTime());
	}
}

void Atomic::Output(void) {
	Output(GetNextEventTime());
}

void Atomic::Output(double time) {
	double Temp = GetNextEventTime();
	SetNextEventTime(time);
	OutputFN();
	SetNextEventTime(Temp);
}

void Atomic::Done(Model* parent, double time) {
	/**
	 * TODO: Not implemented.
	 */
}

void Atomic::DoneInit(Model* parent, double Time) {
	/**
	 * TODO: Not implemented.
	 */
}