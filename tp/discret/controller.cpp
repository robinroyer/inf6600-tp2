#include "stdafx.h" 
#include "controller.h"
#include "cosimlib/cosim.h"

void Controller::handle_antibiotic_injection(){
	int t = antibiotic_interval -120;
	bool anticoagulant = false;
	bool antibiotic_should_start = false;

	int anticoagulant_start = 0;
	int antibiotic_start = 0;

	while (true){
		if (t > antibiotic_interval - 120){
			//anticoagulant
			if (time >= ONE_DAY && !anticoagulant){
				std::cout << "injection anticoagulant" << std::endl;
				start_anticoagulant.write(~start_anticoagulant);
				anticoagulant_start = t;
				anticoagulant = true;
			}
			if (anticoagulant && t > anticoagulant_start + 120)
			{
				stop_anticoagulant.write(~stop_anticoagulant);
				time = 0;
				anticoagulant = false;
				antibiotic_should_start = true;
			}
			//antibiotic
			if (t > antibiotic_interval && antibiotic_should_start)
			{
				t = 0;
				start_antibiotic.write(~start_antibiotic);
				antibiotic_should_start = false;
				time += antibiotic_interval;
			}

		}
		wait();
		t++;
	}
}


void Controller::change_period_to_4_hours(){
	antibiotic_interval = 150;
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
