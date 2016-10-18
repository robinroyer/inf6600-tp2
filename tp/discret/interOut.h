#include "../libC/src/systemc.h"

SC_MODULE(interOut) 
{
	//portes
	sc_out<sc_bit>port7;
	sc_out<sc_bit>port8;
	sc_out<sc_bit>port9;

	void process7();
	void process8();
	void process9();


	
	//SC_CTOR(interOut) 
	//{
	//	SC_METHOD(nom_process);
	//	dont_initialize();
	//}
};