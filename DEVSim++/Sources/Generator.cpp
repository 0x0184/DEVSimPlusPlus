#include "../Includes/Generator.hpp"

#include <iostream>

Generator::Generator() : Atomic() {
	SetName("Generator");
}

Generator::Generator(std::string EName) : Atomic(EName) {
	SetName(EName);
}

void Generator::ExtTransitionFN(double E, DevsMessage X) {
	Logln(Name + "(EXT) --> :" + X.ContentPort() + ": " + "When: " + std::to_string(AddTime(GetLastEventTime(), E)));
	
	if (X.ContentPort() == "stop") Passivate();
}

void Generator::IntTransitionFN(void) {
	Logln(Name + "(INT) --> Sigma: " + std::to_string(Sigma) + " / When: " + std::to_string(AddTime(GetLastEventTime(), Sigma)));
	if (Phase == "busy") { HoldIn("busy", InterArrivalTime); }
	else { Passivate(); }
}

void Generator::OutputFN(void){
	Logln(Name + "(OUT) --> Phase: " + Phase + " / Sigma: " + std::to_string(Sigma) + " / When: " + std::to_string(GetNextEventTime()));

	if (Phase == "busy") {
		MakeContent("out", "Job-" + std::to_string(Count++));
	}
	else MakeContent();
}

void Generator::InitializeFN(void){
	InterArrivalTime = 3;
	Count = 0;

	HoldIn("busy", 0.0);
}
