#include "stdafx.h" 
#include "start.h"
#include "cosimlib/cosim.h"


void Start::start_first_injection(){
	if (!is_sol1_working)
	{
		is_sol1_working = true;
		start1.write(~start1.read());
	}
}

void Start::reset_sol1(){
	if (is_sol1_empty && !is_sol1_working)
	{		
		is_sol1_empty = false;
	}
}
void Start::reset_sol2(){
	if (is_sol2_empty && !is_sol2_working)
	{
		is_sol2_empty = false;
	}
}


void Start::urgency_injection(){
	if (is_sol1_working)
	{
		is_sol1_working = false;
		stop1.write(~stop1.read());
	}

	if (is_sol2_working)
	{
		is_sol2_working = false;
		stop2.write(~stop2.read());
	}

	if (!is_glucose_working)
	{
		is_glucose_working = true;
		start_glucose.write(~start_glucose.read());
	}

}
void Start::average_glycemie(){
	if (is_glucose_working)
	{
		is_glucose_working = false;
		stop_glucose.write(~stop_glucose.read());
	}
	if (is_sol1_empty)
	{
		is_sol1_working = false;
		stop1.write(~stop1.read());
	}
	if (is_sol2_empty)
	{
		is_sol2_working = false;
		stop2.write(~stop2.read());
	}
}


void Start::start_injection1(){
	if (!is_sol1_empty)
	{
		if (is_sol2_working){
			is_sol2_working = false;
			is_sol2_empty = true;
			stop2.write(~stop2.read());
		}

		if (!is_sol1_working){
			is_sol1_working = true;
			start1.write(~start1.read());
		}
	}
	else{
	// no more insuline
		if (is_sol2_working){
			is_sol2_working = false;
			is_sol2_empty = true;
			stop2.write(~stop2.read());
		}
	}
}

void Start::start_injection2(){
	if (!is_sol2_empty)
	{
		if (is_sol1_working){
			is_sol1_working = false;
			is_sol1_empty = true;
			stop1.write(~stop1.read());
		}
		
		if (!is_sol2_working){
			is_sol2_working = true;
			start2.write(~start2.read());
		}
	}
	else{
		// no more insuline
		if (is_sol1_working){
			is_sol1_working = false;
			is_sol1_empty = true;
			stop1.write(~stop1.read());
		}
	}
}


