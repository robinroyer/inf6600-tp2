#include "../libC/src/systemc.h"
#include "def.h"
SC_MODULE(interOUT)
{

	// Port declarations corresponding to signal from the main
	sc_out<sc_bit>vol1_5percent_alert;
	sc_out<sc_bit>vol1_1percent_alert_and_stop;
	sc_out<sc_bit>vol2_5percent_alert;
	sc_out<sc_bit>vol2_1percent_alert_and_stop;

	sc_out<sc_bit>critical_glycemia_level;
	sc_out<sc_bit>average_glycemia_level;

	sc_out<sc_bit>start_and_stop_anticoagulant_start_antibiotic;


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
	void start_antibiotic();
	void stop_antibiotic();
	// GLUCOSE INJECTION
	void start_glucose_injection();
	void stop_glucose_injection();

	SC_CTOR(interOUT) {
	
		SC_METHOD(stop_sol1);
		sensitive(vol1_1percent_alert_and_stop);
		dont_initialize();

		SC_METHOD(stop_sol2);
		sensitive(vol2_1percent_alert_and_stop);
		dont_initialize();

		SC_METHOD(start_glucose_injection);
		sensitive(critical_glycemia_level);
		dont_initialize();

		SC_METHOD(stop_glucose_injection);
		sensitive(average_glycemia_level);
		dont_initialize();
	}
};