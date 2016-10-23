#include "stdafx.h" 
#include "reset.h"
#include "cosimlib/cosim.h"


void Reset::reset(){
	if (is_sol1_empty)
	{
		is_sol1_empty = false;
		reset_sol1_to_start.write(~reset_sol1_to_start.read());
	}
	else if (is_sol2_empty)
	{
		is_sol2_empty = false;
		reset_sol2_to_start.write(~reset_sol2_to_start.read());
	}
}


void Reset::sol1_empty(){
	bool is_sol1_empty = true;
}


void Reset::sol2_empty(){
	bool is_sol2_empty = true;
}
