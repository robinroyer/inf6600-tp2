#include "../libC/src/systemc.h"
#include "def.h"

SC_MODULE(interIN)
{
	//port declaration corresponding to et_matx define
	sc_out<sc_bit>port0;
	sc_out<sc_bit>port1;
	sc_out<sc_bit>port2;
	sc_out<sc_bit>port3;
	sc_out<sc_bit>port4;
	sc_out<sc_bit>port5;
	sc_out<sc_bit>port6;

	// The methods listening to change on et_matx
	void process0();
	void process1();
	void process2();
	void process3();
	void process4();
	void process5();
	void process6();

	SC_CTOR(interIN)
	{
		//state event declaration	
		et_mat0 = new sc_event;
		//state event process	
		SC_METHOD(process0);
		sensitive(et_mat0);
		dont_initialize();

		//state event declaration	
		et_mat1 = new sc_event;
		//state event process	
		SC_METHOD(process1);
		sensitive(et_mat1);
		dont_initialize();

		//state event declaration	
		et_mat2 = new sc_event;
		//state event process	
		SC_METHOD(process2);
		sensitive(et_mat2);
		dont_initialize();

		//state event declaration	
		et_mat3 = new sc_event;
		//state event process	
		SC_METHOD(process3);
		sensitive(et_mat3);
		dont_initialize();

		//state event declaration	
		et_mat4 = new sc_event;
		//state event process	
		SC_METHOD(process4);
		sensitive(et_mat4);
		dont_initialize();

		//state event declaration	
		et_mat5 = new sc_event;
		//state event process	
		SC_METHOD(process5);
		sensitive(et_mat5);
		dont_initialize();

		//state event declaration	
		et_mat6 = new sc_event;
		//state event process	
		SC_METHOD(process6);
		sensitive(et_mat6);
		dont_initialize();
	}
};