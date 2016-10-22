/*****************************************************************************
 
  main.cpp 
 
 *****************************************************************************/

/*****************************************************************************

  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
  changes you are making here.

      Name, Affiliation, Date:
  Description of Modification:

 *****************************************************************************/

// Visual Studio include
#include "stdafx.h"

// external lib
#include "../libC/src/systemc.h"
#include "conio.h"

// include du header de macros
#include "def.h"

// include des modules
#include "alarme.h"
#include "controller.h"
#include "interIn.h"
#include "interOut.h"
#include "reset.h"
#include "start.h"
#include "stop.h"
#include "userInterface.h"

int sc_main(int ac, char *av[])
{
  
	//TODO:implement the clock

	//signaux interin aussi l'horloge
	sc_clock clk1("clk1",1,SC_SEC);



	// =============================== Module interIN

	//Definition du module
	interIN interIn("interIN");

	// Signaux de InterIn
	sc_signal<sc_bit> sol1_5percent;
	sc_signal<sc_bit> sol1_1percent;
	sc_signal<sc_bit> sol2_5percent;
	sc_signal<sc_bit> sol2_1percent;
	sc_signal<sc_bit> stop_antibiotic; // really ??
	sc_signal<sc_bit> critical_glycemia;
	sc_signal<sc_bit> normal_glycemia;

	// mapping signals <-> ports
	interIn.port0(sol1_5percent);		// => alerte
	interIn.port1(sol1_1percent);		// => arret de la perfusion
	interIn.port2(sol1_5percent);		// => alerte
	interIn.port3(sol2_1percent);		// => arret de la perfusion
	interIn.port4(stop_antibiotic);		// => stop antiniotique
	interIn.port5(critical_glycemia);	// => injection de glucose
	interIn.port6(normal_glycemia);		// => arret d'injection de glucose
	//TODO: I did the mapping randomly => to Check


	// =============================== Module interOUT

	//Definition du module
	//interOUT interOut("interOUT");

	// Signaux de InterOut
	//interOut.vol1_5percent_alert(sol1_5percent);
	//interOut.vol1_1percent_alert_and_stop(sol1_1percent);
	//interOut.vol2_5percent_alert(sol1_5percent);
	//interOut.vol2_1percent_alert_and_stop(sol2_1percent);
	//interOut.critical_glycemia_level(critical_glycemia);
	//interOut.average_glycemia_level(normal_glycemia);
	//interOut.start_and_stop_anticoagulant_start_antibiotic();


	// =============================== Module Start
	//Start start("Start");

	// =============================== Module Reset
	//Reset reset("Reset");

	// =============================== Module alarme
	Alarme alarme("Alarme");

	// Mapping des signaux <-> ports
	alarme.sol1_5percent(sol1_5percent);
	alarme.sol1_1percent(sol2_1percent);
	alarme.sol2_5percent(sol2_5percent);
	alarme.sol2_1percent(sol2_1percent);
	alarme.critical_glycemia_level(critical_glycemia);
	

	// =============================== Module Stop
	//Stop stop("Stop");

	// =============================== Module Controler
	//Controller controller("Controller");

	// =============================== Module UserInterface
	UserInterface userInterface("UserInterface");

	// Mapping des signaux 
	userInterface.tick(clk1);

	// Events
	sc_signal<sc_bit> period_4_hours;
	sc_signal<sc_bit> period_6_hours;
	sc_signal<sc_bit> period_8_hours;
	sc_signal<sc_bit> period_12_hours;
	sc_signal<sc_bit> reset_perfusion;
	sc_signal<sc_bit> stop_simulation;

	//out
	userInterface.ui_period_4_hours(period_4_hours);
	userInterface.ui_period_6_hours(period_6_hours);
	userInterface.ui_period_8_hours(period_8_hours);
	userInterface.ui_period_12_hours(period_12_hours);
	userInterface.ui_reset_perfusion(reset_perfusion);
	userInterface.ui_stop_simulation(stop_simulation);

	//interfaces SystemC<->Simulink
	SET_COSIM

	MIXED_SIGNAL = true;
	FS = true;
	Speriod_0 = 0.01;



	sc_start(9000, SC_SEC); 
	_getch();

	CLOSE_COSIM  

	cout << "EXITING IN 2 SECONDES" << endl;
	Sleep(2000);
	return 0;
};
