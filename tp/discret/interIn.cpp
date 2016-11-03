#include "stdafx.h" 
#include "interIn.h"
#include "cosimlib/cosim.h"


void interIN::process0(){
	//cout << "interIN::process0 \r\n";
	//std::cout << "the value of the port is : " << port0.read() << std::endl;
	port0.write(~port0.read());
}

void interIN::process1(){
	//cout << "interIN::process1 \r\n";
	//std::cout << "the value of the port is : " << port1.read() << std::endl;
	port1.write(~port1.read());
}

void interIN::process2(){
	//cout << "interIN::process2 \r\n";
	//std::cout << "the value of the port is : " << port2.read() << std::endl;
	port2.write(~port2.read());
}

void interIN::process3(){
	//cout << "interIN::process3 \r\n";
	//std::cout << "the value of the port is : " << port3.read() << std::endl;
	port3.write(~port3.read());
}

void interIN::process4(){
	//cout << "interIN::process4 \r\n";
	//std::cout << "the value of the port is : " << port4.read() << std::endl;
	port4.write(~port4.read());
}

void interIN::process5(){
	//cout << "interIN::process5 \r\n";
	//std::cout << "the value of the port is : " << port5.read() << std::endl;
	port5.write(~port5.read());
}

void interIN::process6(){
	//cout << "interIN::process6 \r\n";
	//std::cout << "the value of the port is : " << port6.read() << std::endl;
	port6.write(~port6.read());
}
