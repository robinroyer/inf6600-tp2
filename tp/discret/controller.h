#include "../libC/src/systemc.h"
#include "def.h"


SC_MODULE(Controller)
{
	// Port declarations corresponding to signal from the main
	sc_out<sc_bit>port;

	// The methods listening to change on port
	void process();

	SC_CTOR(Controller) {

		SC_METHOD(process);
		sensitive(port);
		dont_initialize();
	}
};