#include "../libC/src/systemc.h"
#include "def.h"


SC_MODULE(Controller)
{
	// We need to store the time of the first antibiotic injection of the day
	int time = -1;
	// Default value to force the first injection
	int last_antibiotic_injection = -1 * ONE_WEEK;
	int last_anticoagulant_injection = -1 * ONE_WEEK;

	// TIME CONSTANTES
	int ONE_HOUR = 3600; // Secondes
	int FOUR_HOURS = 4 * ONE_HOUR; // Secondes
	int SIX_HOURS = 6 * ONE_HOUR; // Secondes
	int EIGHT_HOURS = 8 * ONE_HOUR; // Secondes
	int TWELVE_HOURS = 12 * ONE_HOUR; // Secondes
	int ONE_DAY = 24 * ONE_HOUR;
	int ONE_WEEK =7 * ONE_DAY;

	// default value for the antibiotic interval is the average
	int antibiotic_interval = EIGHT_HOURS; 

	// Port declarations corresponding to signal from the main
	sc_in<sc_bit> period_4_hours;
	sc_in<sc_bit> period_6_hours;
	sc_in<sc_bit> period_8_hours;
	sc_in<sc_bit> period_12_hours;
	sc_in<bool> tick;
	
	// port out
	sc_out<sc_bit> start_anticoagulant;
	sc_out<sc_bit> stop_anticoagulant;
	sc_out<sc_bit> start_antibiotic;

	// The methods listening to change on port
	void change_period_to_4_hours();
	void change_period_to_6_hours();
	void change_period_to_8_hours();
	void change_period_to_12_hours();
	void handle_antibiotic_injection();

	SC_CTOR(Controller) {

		SC_METHOD(change_period_to_4_hours);
		sensitive(period_4_hours);
		dont_initialize();

		SC_METHOD(change_period_to_6_hours);
		sensitive(period_6_hours);
		dont_initialize();		
		
		SC_METHOD(change_period_to_8_hours);
		sensitive(period_8_hours);
		dont_initialize();

		SC_METHOD(change_period_to_12_hours);
		sensitive(period_12_hours);
		dont_initialize();

		SC_THREAD(handle_antibiotic_injection);
		sensitive << tick.pos();
		dont_initialize();

	}
};