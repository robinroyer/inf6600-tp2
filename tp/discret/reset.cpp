#include "stdafx.h" 
#include "reset.h"
#include "cosimlib/cosim.h"

void Reset::reset(){
	//std::cout << "the value of the reset is : " << reset_from_user.read() << std::endl;
	reset_from_user.write(~reset_from_user.read());
}