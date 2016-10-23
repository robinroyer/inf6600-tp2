#include "stdafx.h" 
#include "interOut.h"
#include "cosimlib/cosim.h"


	void interOUT::start_sol1(){
		WriteSignalToSimulink(1, 0);
	}

	void interOUT::stop_sol1(){
		WriteSignalToSimulink(0, 0);
	}

	void interOUT::start_sol2(){
		WriteSignalToSimulink(1, 1);
	}

	void interOUT::stop_sol2(){
		WriteSignalToSimulink(0, 1);
	}

	void interOUT::start_anticoagulant(){
		WriteSignalToSimulink(1, 2);
	}

	void interOUT::stop_anticoagulant(){
		WriteSignalToSimulink(0, 2);
	}

	void interOUT::start_antibiotic_injection(){
		WriteSignalToSimulink(1, 3);
	}

	void interOUT::stop_antibiotic_injection(){
		WriteSignalToSimulink(0, 3);
	}

	void interOUT::start_glucose_injection(){
		WriteSignalToSimulink(1, 4);
	}

	void interOUT::stop_glucose_injection(){
		WriteSignalToSimulink(0, 4);
	}



