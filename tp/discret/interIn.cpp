#include "stdafx.h" 
#include "interIn.h"
#include "cosimlib/cosim.h"



//implementation du processus - .cpp file

void interIN::process0(){
	cout << "interIN::process0 \r\n";
	 sc_bit value = port0.read();
	std::cout << "the value of the port is : " << value << std::endl;
	port0.write(~value);
}

void interIN::process1(){
	//cout << "interIN::process1 \r\n";
	sc_bit value = port1.read();
	//std::cout << "the value of the port is : " << value << std::endl;
	port1.write(~value);
}

void interIN::process2(){
	//cout << "interIN::process2 \r\n";
	sc_bit value = port2.read();
	//std::cout << "the value of the port is : " << value << std::endl;
	port2.write(~value);
}

void interIN::process3(){
	//cout << "interIN::process3 \r\n";
	sc_bit value = port3.read();
	//std::cout << "the value of the port is : " << value << std::endl;
	port3.write(~value);
}

void interIN::process4(){
	//cout << "interIN::process4 \r\n";
	sc_bit value = port4.read();
	//std::cout << "the value of the port is : " << value << std::endl;
	port4.write(~value);
}

void interIN::process5(){
	//cout << "interIN::process5 \r\n";
	sc_bit value = port5.read();
	//std::cout << "the value of the port is : " << value << std::endl;
	port5.write(~value);
}

void interIN::process6(){
	//cout << "interIN::process6 \r\n";
	sc_bit value = port6.read();
	//std::cout << "the value of the port is : " << value << std::endl;
	port6.write(~value);
}
