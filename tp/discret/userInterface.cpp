#include <string>
#include <iostream>
#include <sstream>
#include "stdafx.h" 
#include "userInterface.h"
#include "cosimlib/cosim.h"



/** 
* Module of user interface
*
*/
void UserInterface::handle_user_input(){
	std::string help = "Press : \r\n"
		"- '4' for a 4-hours injection period. \r\n"
		"- '6' for a 6-hours injection period. \r\n"
		"- '8' for a 8-hours injection period. \r\n"
		"- '12' for a 12-hours injection period. \r\n"
		"- 'reset' for replacing the perfusion. \r\n"
		"- 'start' to start the simulation. \r\n"
		"- 'stop' to stop the simulation. \r\n";

	std::cout << help << std::endl;

	string user = "";
	while (user != "stop"){
		Sleep(400);
		std::getline(std::cin, user);
		if (user == "4")
		{
			std::cout << "\r\nThe period is 4 hours !\r\n" << std::endl;
			if (period_number != 4)
			{
				period_number = 4;
				ui_period_4_hours.write(~ui_period_4_hours.read());
			}
		}
		else if (user == "6")
		{
			std::cout << "\r\nThe period is 6 hours !\r\n" << std::endl;
			if (period_number != 6)
			{
				period_number = 6;
				ui_period_6_hours.write(~ui_period_6_hours.read());
			}
		}
		else if (user == "8") 
		{
			std::cout << "\r\nThe period is 8 hours !\r\n" << std::endl;
			if (period_number!=8)
			{
				period_number = 8;
				ui_period_8_hours.write(~ui_period_8_hours.read());
			}
		}
		else if (user == "12")
		{
			std::cout << "\r\nThe period is 12 hours !\r\n" << std::endl;
			if (period_number != 12)
			{
				period_number = 12;
				ui_period_12_hours.write(~ui_period_12_hours.read());
			}
		}
		else if (user == "reset")
		{
			std::cout << "\r\nThe perfusion is reset !\r\n" << std::endl;
			ui_reset_perfusion.write(~ui_reset_perfusion.read());
		}
		else if (user == "start")
		{
			std::cout << "\r\n The simulation is starting !\r\n" << std::endl;
			ui_start_simulation.write(~ui_start_simulation.read());
		}
		else if (user != "stop")
		{
			std::cout << "\r\nWrong input !\r\n" << std::endl;
			std::cout << help << std::endl;
		}
	}
		
	std::cout << "Stop of the simulation!\r\n" << std::endl;
	ui_stop_simulation.write(~ui_stop_simulation.read());

}