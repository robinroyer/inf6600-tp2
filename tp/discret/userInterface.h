#include "../libC/src/systemc.h"
#include "def.h"



SC_MODULE(UserInterface)
{
	// default value
	int period_number = 8;

	
	// clock tick
	sc_in<bool>tick;

	// Port declarations corresponding to signal from the main
	sc_out<sc_bit> ui_period_4_hours;
	sc_out<sc_bit> ui_period_6_hours;
	sc_out<sc_bit> ui_period_8_hours;
	sc_out<sc_bit> ui_period_12_hours;
	sc_out<sc_bit> ui_reset_perfusion;
	sc_out<sc_bit> ui_stop_simulation;

	// The methods listening to change on port
	void handle_user_input();

	SC_CTOR(UserInterface) {

		SC_THREAD(handle_user_input);
		sensitive_pos(tick);
		dont_initialize();
	}
};