#include "../libC/src/systemc.h"
#include "def.h"


SC_MODULE(Alarme)
{
	// Port declarations corresponding to signal from the main
	sc_in<sc_bit> sol1_5percent;
	sc_in<sc_bit> sol1_1percent;
	sc_in<sc_bit> sol2_5percent;
	sc_in<sc_bit> sol2_1percent;
	sc_in<sc_bit> critical_glycemia_level;

	// The methods listening to change on port
	void alert_sol1_5percent();
	void alert_sol1_1percent();
	void alert_sol2_5percent();
	void alert_sol2_1percent();
	void alert_critical_glycemia_level();

	SC_CTOR(Alarme) {
	
		SC_METHOD(alert_sol1_5percent);
		sensitive << sol1_5percent;
		dont_initialize();

		SC_METHOD(alert_sol1_1percent);
		sensitive << sol1_1percent;
		dont_initialize();

		SC_METHOD(alert_sol2_5percent);
		sensitive << sol2_5percent;
		dont_initialize();

		SC_METHOD(alert_sol2_1percent);
		sensitive << sol2_1percent;
		dont_initialize();

		SC_METHOD(alert_critical_glycemia_level);
		sensitive << critical_glycemia_level;
		dont_initialize();
	}
};