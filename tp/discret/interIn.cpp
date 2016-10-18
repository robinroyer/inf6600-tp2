#include "interIn.h"
#include "cosim.h"


//return_type_if_any
//module_name:: member_function_name() {
//interIN:: member_function_name() {
//	member_function_body
//} 

//void module_name::process_name(){
//void interIN::cosim_out_syn(){
	
//name_port ->write(ReadSignalFromSimulink(0)); //read from shared memory
//name_port ->write(ReadSignalFromSimulink(0));
//wait();

//}

//void  interIN::state_event_process_name() {
	//state_event_process_body
//}


//Si le type choisi pour « state event » est « bit » la syntaxe est:

// déclaration des ports – header file

sc_out<sc_bit> name_port_state_event; 


//implementation du processus - .cpp file

void interIN::process_name(){

	sc_bit value;
	cout << "interIN::process_name \r\n";
	value = name_port.read();
	std::cout << "the value of the port is : " << value << std::endl;
	name_port.write(~value);

}
