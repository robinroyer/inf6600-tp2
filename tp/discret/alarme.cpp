#include "stdafx.h" 
#include "cosimlib/cosim.h"
#include "alarme.h"


void Alarme::alert_sol1_5percent(){
	std::cout << "... Alerte, le volume de la solution 1 vient de passer à 5%." << std::endl;
}

void Alarme::alert_sol2_1percent(){
	std::cout << "... Alerte, le volume de la solution 1 vient de passer à 1%." << std::endl;
}

void Alarme::alert_sol2_1percent(){
	std::cout << "... Alerte, le volume de la solution 2 vient de passer à 5%." << std::endl;
}

void Alarme::alert_sol2_1percent(){
	std::cout << "... Alerte, le volume de la solution 2 vient de passer à 1%." << std::endl;
}	

void Alarme::alert_critical_glycemia_level(){
	std::cout << "... Alerte, la glycémie est à un niveau critique." << std::endl;
}	


