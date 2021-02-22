#include "../Includes/Transducer.hpp"

Transducer::Transducer(std::string entity_name) : Atomic(entity_name) {
	SetName(entity_name);
}

void Transducer::ExtTransitionFN(double E, DevsMessage X) {
	JobID = X.ContentValue();
	Logln("JobID: " + JobID);
	clock += E;

	Logln(Name + "(EXT) --> :" + X.ContentPort() + ":" + JobID + " at " + std::to_string(clock));
	if (Phase == "active") {
		if (X.ContentPort() == "arriv") {
			Arrive.Jobs[Arrive.Num].ID = JobID;
			Arrive.Jobs[Arrive.Num].Time = clock;
			Arrive.Num++;
		}
		else if (X.ContentPort() == "solved") {
			Solve.Jobs[Solve.Num].ID = JobID;
			Solve.Jobs[Solve.Num].Time = clock;
			Solve.Num++;
		}
	}
	Continue();
}

void Transducer::IntTransitionFN(void) {
	Logln(Name + "(INT) --> ");
	if (Phase == "active") {
	    PrintArrive();
		PrintSolve();
		Passivate();
	}
	else Continue();
}

void Transducer::OutputFN(void) {
	Logln(Name + "(OUT) --> ");
	if (Phase == "active") 
		MakeContent("out", "NULL");
	else MakeContent();
}

void Transducer::InitializeFN(void) {
	  clock = (double) 0.0;

	  Arrive.Num = 0;
	  Solve.Num = 0;

	  HoldIn("active", (double) 100.0);
}


void Transducer::PrintArrive(void) {
	Logln("   ---------------------< Arrived Jobs >---------------------");
	for (int i = 0; i < Arrive.Num; i++) {
		Logln("(" + Arrive.Jobs[i].ID + ", " + std::to_string(Arrive.Jobs[i].Time) + ")");
	}
}

void Transducer::PrintSolve(void) {
	Logln("   ---------------------< Solved Jobs >---------------------");
	for (int i = 0; i < Solve.Num; i++) {
		Logln("(" + Solve.Jobs[i].ID + ", " + std::to_string(Solve.Jobs[i].Time) + ")");
	}
}