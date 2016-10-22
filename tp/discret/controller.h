#include "../libC/src/systemc.h"
#include "def.h"


SC_MODULE(Controller)
{
	// The controller should coordinate all the actions
	// We will store all the control variables in controller
	// => The controller will trigger event to coordinate application
	bool injection_s1 = false;
	bool injection_s2 = false;
	bool injection_glucose = false;
	bool injection_anticoagulant = false;
	bool injection_antibiotic = false;

	// We need to store the time of the first antibiotic injection of the day
	// int -  time ?


	// TIME CONSTANTES
	int ONE_HOUR = 3600; // Secondes
	int FOUR_HOURS = 4 * ONE_HOUR; // Secondes
	int SIX_HOURS = 6 * ONE_HOUR; // Secondes
	int EIGHT_HOURS = 8 * ONE_HOUR; // Secondes
	int TWELVE_HOURS = 12 * ONE_HOUR; // Secondes

	// default value for the antibiotic interval is the average
	int antibiotic_interval = EIGHT_HOURS; 

	// Port declarations corresponding to signal from the main
	sc_in<sc_bit>interface_to_control;
	sc_in<sc_bit>antibiotic_injection
	
	// port out
	sc_out<sc_bit> reset_to_start;
	sc_out<sc_bit> start_antibiotic;
	sc_out<sc_bit> stop_antibiotic;

	// The methods listening to change on port
	void handle_antibiotic();


	// TODO here we should define the boolean for each solution and
	// variables to handle the last anticoagulant etc... 

	SC_CTOR(Controller) {

		SC_METHOD(handle_antibiotic);
		sensitive(antibiotic_injection);
		dont_initialize();
	}
};