#include "stdafx.h" 
#include "stop.h"
#include "cosimlib/cosim.h"


void Stop::urgency_stop(){
	// Stop the simulation

}

void Stop::user_stop(){
	// End of simulation
	 sc_interrupt_here();
	// See this 2 functions if we need an other behaviour 
	// SC_STOP Call sc_stop(). See sc_stop() manual for further detail. 
	// SC_ABORT The action requests the report handler to call abort()
}