#include "stdafx.h" 
#include "stop.h"
#include "cosimlib/cosim.h"


void Stop::user_need_stop(){	
	sc_stop();
}