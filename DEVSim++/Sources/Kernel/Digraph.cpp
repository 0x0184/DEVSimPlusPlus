#include "../../Includes/Kernel/Digraph.hpp"

Digraph::Digraph(std::string entity_name) : Coupled(entity_name) {
	SetClassName("Digraph");
}

double Digraph::GetMinTime(void) {
	return Children.GetMinTime();
}

void Digraph::IntTransition(void) {
	/**
	 * TODO: Not implemented.
	 */
}

void Digraph::IntTransition(double time) {
	if (time != GetNextEventTime()) return;

	SetLastEventTime(time);

	P = Children.FindFirstList(time);
	if (P == nullptr) return;

	do {
		P->PModel->IntTransition(time);
		P = Children.FindNextList(time);
		if (P == nullptr) break;
	} while (true);
}

/* --------------- Body of Inject Function in Atomic model --------------------
     if ((Time < GetLastEventTime()) || (Time > GetNextEventTime())) return;
	 SetInMessage(MSG);
	 ElapsedTime = Time - GetLastEventTime();
	 ExtTransitionFN(ElapsedTime,MSG);
	 SetLastEventTime(Time);
	 SetNextEventTime(AddTime(GetLastEventTime(),Sigma));

	 if (Parent) Parent->Done((Model *)this,GetNextEventTime());
*/

void Digraph::Inject(DevsMessage message) {
	Inject(this, message, GetNextEventTime());
}

void Digraph::Inject(DevsMessage message, double time) {
	Inject(this, message, time);
}

void Digraph::Inject(Model* from_model, DevsMessage message, double time) {
	 PortPair *PPair, *Temp;
	 std::string  PPort;

	 if ((from_model == this) && (Parent)) Parent->Inject(this, message, time);

	 PPort = message.ContentPort();
	 PPair = Ports.FindFirstPair(PPort);
	 Temp = Ports.Curr;

	 do {
	 	if (PPair == nullptr) break;

		OutMessage.MakeContent(PPair->ToPort, message.ContentValue());
		if ((PPair->FromModel == from_model) || (from_model == Parent))
		   ((Model*) (PPair->ToModel))->Inject(this, OutMessage, time);
		Ports.Curr = Temp;
		PPair = Ports.FindNextPair(PPort);
		Temp = Ports.Curr;
	 } while (true);
}

void Digraph::InitialModel(void) {
	 Children.AllInitial();
	 if (Parent) Parent->DoneInit(this, GetMinTime());
	 SetNextEventTime(GetMinTime());
}

void Digraph::Done(Model* model, double time) {
     Children.SetOne(model, time);
	 SetNextEventTime(GetMinTime());
	 if (Parent) Parent->Done(this, GetMinTime());
}

void Digraph::DoneInit(Model* model, double time) {
     Children.SetOne(model, time);
}