#include "../libC/src/systemc.h"
#include "def.h"

SC_MODULE(Reset)
{
	// port out
	sc_out<sc_bit> reset_to_start;

	// port in
	sc_in<sc_bit> reset_from_user;
	
	// The methods listening to change on port
	void reset();

	SC_CTOR(Reset) {

		SC_METHOD(reset);
		sensitive(reset_from_user);
		dont_initialize();
	}
};