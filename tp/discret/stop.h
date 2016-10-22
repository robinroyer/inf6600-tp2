#include "../libC/src/systemc.h"
#include "def.h"

SC_MODULE(Stop)
{
	// Port declarations corresponding to signal from the main
	sc_in<sc_bit>user_stop;
	sc_in<sc_bit>urgency_stop;

	// The methods listening to change on port
	void urgence_stop();
	void user_need_stop();

	SC_CTOR(Stop) {

		SC_METHOD(user_need_stop);
		sensitive(user_stop);
		dont_initialize();

		SC_METHOD(urgence_stop);
		sensitive(urgency_stop);
		dont_initialize();
	}
};