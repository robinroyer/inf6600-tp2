#include "../libC/src/systemc.h"
#include "def.h"

SC_MODULE(Start)
{

	bool is_sol1_empty = false;
	bool is_sol2_empty = false;

	bool is_sol1_working = false;
	bool is_sol2_working = false;
	bool is_glucose_working = false;

	// in
	sc_in<sc_bit> first_injection;
	sc_in<sc_bit> reset_sol1_from_reset;
	sc_in<sc_bit> reset_sol2_from_reset;
	sc_in<sc_bit> handle_start_injection1;
	sc_in<sc_bit> handle_start_injection2;
	sc_in<sc_bit> handle_urgency_injection;
	sc_in<sc_bit> handle_average_glycemia;

	
	// out
	sc_out<sc_bit> start1;
	sc_out<sc_bit> start2;
	sc_out<sc_bit> stop1;
	sc_out<sc_bit> stop2;
	sc_out<sc_bit> start_glucose;
	sc_out<sc_bit> stop_glucose;


	
	// The methods that start the first injection
	void reset_sol1();
	void reset_sol2();

	void start_first_injection();

	void urgency_injection();
	void average_glycemie();

	void start_injection1();
	void start_injection2();


	SC_CTOR(Start) {
		SC_METHOD(start_first_injection);
		sensitive << first_injection;

		SC_METHOD(reset_sol1);
		sensitive << reset_sol1_from_reset;
		dont_initialize();

		SC_METHOD(reset_sol2);
		sensitive << reset_sol2_from_reset;
		dont_initialize();

		SC_METHOD(start_injection1);
		sensitive << handle_start_injection1;
		dont_initialize();

		SC_METHOD(start_injection2);
		sensitive << handle_start_injection2;
		dont_initialize();

		SC_METHOD(urgency_injection);
		sensitive << handle_urgency_injection;
		dont_initialize();

		SC_METHOD(average_glycemie);
		sensitive << handle_average_glycemia;
		dont_initialize();
	}
};