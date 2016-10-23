#include "../libC/src/systemc.h"
#include "def.h"

SC_MODULE(Stop)
{
	// Port declarations corresponding to signal from the main
	sc_in<sc_bit>user_stop;

	// The methods listening to change on port
	void user_need_stop();

	SC_CTOR(Stop) {

		SC_METHOD(user_need_stop);
		sensitive << user_stop;
		dont_initialize();
	}
};