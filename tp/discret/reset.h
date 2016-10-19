#include "../libC/src/systemc.h"
#include "def.h"

SC_MODULE(Reset)
{
	// Port declarations corresponding to signal from the main
	sc_out<sc_bit>port;

	// The methods listening to change on port
	void process();

	SC_CTOR(Reset) {

		SC_METHOD(process);
		sensitive(port);
		dont_initialize();
	}
};