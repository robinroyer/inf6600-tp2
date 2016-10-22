#include "../libC/src/systemc.h"
#include "def.h"



SC_MODULE(UserInterface)
{
	// clock tick
	sc_int<sc_bit>tick;

	// Port declarations corresponding to signal from the main
	sc_out<sc_bit>port;

	// The methods listening to change on port
	void process();

	SC_CTOR(UserInterface) {

		SC_THREAD(process);
		sensitive_pos(tick);
	}
};