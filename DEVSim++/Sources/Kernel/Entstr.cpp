#include "../../Includes/Kernel/Entstr.hpp"

EntStr::EntStr(std::string entity_name) : Digraph(entity_name) {
	SetClassName("EntStr");
	ChildList.AddModel(entity_name, this);
	CurrentItem = this;
	Clock = 0.0;
	LimitClock = INF;
	CClock = 0.0;
}

void EntStr::SetLimit(double time) {
	LimitClock = time;
}

double EntStr::SetClock(double time) {
	Clock = time;
	return time;
}

double EntStr::GetClock(void) {
	return Clock;
}

double EntStr::AddClock(double time) {
	if ((Clock == INF) || (time == INF)) return SetClock(INF);
	Clock += time;
	if (Clock < 0) return SetClock(INF);
	return GetClock();
}

void EntStr::SetCurrentItem(Model* model) {
	CurrentItem = model;
}

void EntStr::SetCurrentItem(std::string model_name) {
	Model* model = ChildList.GetModel(model_name);
	if (model != nullptr) {
		CurrentItem = model;
	}
}

Model* EntStr::GetCurrentItem() {
	return CurrentItem;
}

void EntStr::AddItem(Model* model) {
	if (model == nullptr) {
		Logln("Null pointer assigned!");
		return;
	}
	if (CurrentItem == this) {
		if (((EntStr*) CurrentItem)->IsDevsChild(model)) return;
		((EntStr *)CurrentItem)->AddChild(model);
	}
	else {
		if (((Coupled*) CurrentItem)->IsDevsChild(model)) return;
		((Coupled*) CurrentItem)->AddChild(model);
	}
	ChildList.AddModel(model->GetName(), model);
	model->SetParent(CurrentItem);
}

void EntStr::AddCouple(Model* from_model, Model* to_model, std::string from_port, std::string to_port) {
	CurrentItem->AddCoupling(from_model, to_model, from_port, to_port);
}

void EntStr::AddCouple(std::string from_model, std::string to_model, std::string from_port, std::string to_port) {
	Model* fmodel = ChildList.GetModel(from_model);
	Model* tmodel = ChildList.GetModel(to_model);

	if (fmodel != nullptr && tmodel != nullptr) {
		AddCouple(fmodel, tmodel, from_port, to_port);
	}
}

void EntStr::Initialize(void) {
	Children.AllInitial();
	Clock = 0.0;
}

void EntStr::Restart(void) {
	double Time;
	ListElement *P;

	Logln("[" + GetClassName() + "] Restart..");

	Initialize();
	//Clock = (double)0.0;

	do {
		StepStart();
		Time = Children.GetMinTime();
		SetClock(Time);
		if (Time == INF) break;
		if (Time > LimitClock) break;
		P = Children.FindFirstList(Time);
		if (P == nullptr) break;
	} while (true);
}

void EntStr::StepStart(void) {
	double Time, TTime;
	ListElement *P;

	Logln("[" + GetClassName() + "] StepStart..");

	CClock = Children.GetMinTime();
	TTime = CClock;

	do {
		Time = Children.GetMinTime();
		if (CClock != Time) break;
		SetClock(Time); 
		if (Time == INF) break;
		if (Time > LimitClock) break;
		P = Children.FindFirstList(Time);
		if (P == nullptr) break;
		P->PModel->IntTransition(Time);
	} while (true);

	Logln("One step ended...");
	OutputFN(TTime);
}

void EntStr::IntTransition(double time) {
	/**
	 * TODO: Not implemented.
	 */
}

void EntStr::Inject(std::string port, std::string value) {
	OutMessage.MakeContent(port, value);
	Digraph::Inject(OutMessage, 0.0);
}

void EntStr::DoneInit(Model* model, double time) {
	Children.SetOne(model, time);
}

void EntStr::Done(Model* model, double time) {
	Children.SetOne(model, time);
}

void EntStr::IntTransition(void) {}
void EntStr::Output(double T) {}
void EntStr::Output(void) {}
void EntStr::InitialModel(void) {}

void EntStr::OutputFN(double clk) {
	Logln("Global Clock (Root): " + std::to_string(clk));
}