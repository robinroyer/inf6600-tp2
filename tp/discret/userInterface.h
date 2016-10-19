#include "../libC/src/systemc.h"
#include "def.h"





SC_MODULE(UserInterface)
{
	// Port declarations corresponding to signal from the main
	sc_out<sc_bit>port;

	// The methods listening to change on port
	void process();

	SC_CTOR(UserInterface) {

		SC_METHOD(process);
		sensitive(port);
		dont_initialize();
	}
};