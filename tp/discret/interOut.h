#include "../libC/src/systemc.h"
#include "def.h"
SC_MODULE(interOUT)
{
	// Port declarations corresponding to signal from the main
	sc_in<sc_bit> event_start_sol1;
	sc_in<sc_bit> event_stop_sol1;
	sc_in<sc_bit> event_start_sol2;
	sc_in<sc_bit> event_stop_sol2;
	sc_in<sc_bit> event_start_glucose_injection;
	sc_in<sc_bit> event_stop_glucose_injection;
	sc_in<sc_bit> event_start_anticoagulant_injection;
	sc_in<sc_bit> event_stop_anticoagulant_injection;
	sc_in<sc_bit> event_start_antibiotic_injection;
	sc_in<sc_bit> event_stop_antibiotic_injection;

	// The methods listening to change on port
	// SOLUTION 1
	void start_sol1();
	void stop_sol1();
	// SOLUTION 2
	void start_sol2();
	void stop_sol2();
	// ANTICOAGULANT
	void start_anticoagulant();
	void stop_anticoagulant();
	// ANTIBIOTIC
	void start_antibiotic_injection();
	void stop_antibiotic_injection();
	// GLUCOSE INJECTION
	void start_glucose_injection();
	void stop_glucose_injection();

	SC_CTOR(interOUT) {
	
		SC_METHOD(start_sol1);
		sensitive(event_start_sol1);
		dont_initialize();

		SC_METHOD(stop_sol1);
		sensitive(event_stop_sol1);
		dont_initialize();

		SC_METHOD(start_sol2);
		sensitive(event_start_sol2);
		dont_initialize();

		SC_METHOD(stop_sol2);
		sensitive(event_stop_sol2);
		dont_initialize();

		SC_METHOD(start_glucose_injection);
		sensitive(event_start_glucose_injection);
		dont_initialize();

		SC_METHOD(stop_glucose_injection);
		sensitive(event_stop_glucose_injection);
		dont_initialize();

		SC_METHOD(start_antibiotic_injection);
		sensitive(event_start_antibiotic_injection);
		dont_initialize();

		SC_METHOD(stop_antibiotic_injection);
		sensitive(event_stop_antibiotic_injection);
		dont_initialize();
	}
};