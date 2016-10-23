#include "stdafx.h" 
#include "controller.h"
#include "cosimlib/cosim.h"

void Controller::handle_antibiotic_injection(){
	while (true){
		if (time - last_antibiotic_injection >= antibiotic_interval){
			if (time - last_antibiotic_injection >= ONE_DAY)
			{
				start_anticoagulant.write(~start_anticoagulant);
				//wait(120)
				// Sleep est la cause d'un probleme d'edition des liens de lib systemC 
				Sleep(120 * 1000);
				time += 119;
				stop_anticoagulant.write(~stop_anticoagulant);
				last_anticoagulant_injection = time;
			}
			last_antibiotic_injection = time;
			start_antibiotic.write(~start_antibiotic);
		}
		time++;
		//wait(1);
		// Sleep est la cause d'un probleme d'edition des liens de lib systemC 
		Sleep(1000);
	}
}


void Controller::change_period_to_4_hours(){
	antibiotic_interval = FOUR_HOURS;
}

void Controller::change_period_to_6_hours(){
	antibiotic_interval = SIX_HOURS;
}
void Controller::change_period_to_8_hours(){
	antibiotic_interval = EIGHT_HOURS;
}
void Controller::change_period_to_12_hours(){
	antibiotic_interval = TWELVE_HOURS;
}
