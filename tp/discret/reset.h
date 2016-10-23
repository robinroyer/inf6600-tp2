#include "../libC/src/systemc.h"
#include "def.h"

SC_MODULE(Reset)
{
	bool is_sol1_empty = false;
	bool is_sol2_empty = false;

	// port out
	sc_out<sc_bit> reset_sol1_to_start;
	sc_out<sc_bit> reset_sol2_to_start;

	// port in
	sc_in<sc_bit> reset_from_user;
	sc_in<sc_bit> sol1_is_empty;
	sc_in<sc_bit> sol2_is_empty;
	
	// The methods listening to change on port
	void reset();
	void sol1_empty();
	void sol2_empty();

	SC_CTOR(Reset) {

		SC_METHOD(reset);
		sensitive(reset_from_user);
		dont_initialize();

		SC_METHOD(sol1_empty);
		sensitive(sol1_is_empty);
		dont_initialize();

		SC_METHOD(sol2_empty);
		sensitive(sol2_is_empty);
		dont_initialize();
	}
};