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
	//signaux interin aussi l'horloge
	sc_clock clk1("clk1",1,SC_SEC);

	// Signaux de InterIn
	sc_signal<sc_bit> ii_sol1_5percent;
	sc_signal<sc_bit> ii_sol1_1percent;
	sc_signal<sc_bit> ii_sol2_5percent;
	sc_signal<sc_bit> ii_sol2_1percent;
	sc_signal<sc_bit> ii_stop_antibiotic;
	sc_signal<sc_bit> ii_critical_glycemia;
	sc_signal<sc_bit> ii_normal_glycemia;

	// User Interface Events
	sc_signal<sc_bit> ui_period_4_hours;
	sc_signal<sc_bit> ui_period_6_hours;
	sc_signal<sc_bit> ui_period_8_hours;
	sc_signal<sc_bit> ui_period_12_hours;
	sc_signal<sc_bit> ui_reset_perfusion;
	sc_signal<sc_bit> ui_stop_simulation;
	sc_signal<sc_bit> ui_start_simulation;

	// Controller event
	sc_signal<sc_bit> c_start_anticoagulant_injection;
	sc_signal<sc_bit> c_stop_anticoagulant_injection;
	sc_signal<sc_bit> c_start_antibiotic_injection;

	// Reset event
	sc_signal<sc_bit> r_reset_perfusion1;
	sc_signal<sc_bit> r_reset_perfusion2;

	// Reset event
	sc_signal<sc_bit> sta_launch_perfusion1;
	sc_signal<sc_bit> sta_launch_perfusion2;
	sc_signal<sc_bit> sta_stop_perfusion1;
	sc_signal<sc_bit> sta_stop_perfusion2;
	sc_signal<sc_bit> sta_launch_glucose;
	sc_signal<sc_bit> sta_stop_glucose;

	// =============================== Module interIN
	//Definition du module
	interIN interIn("interIN");
	// mapping signals <-> ports
	interIn.port0(ii_sol1_5percent);		// => alert
	interIn.port1(ii_sol1_1percent);		// => stop perfusion 1
	interIn.port2(ii_sol2_5percent);		// => alert
	interIn.port3(ii_sol2_1percent);		// => stop perfusion 2
	interIn.port4(ii_stop_antibiotic);		// => stop antibiotic
	interIn.port5(ii_critical_glycemia);	// => inject de glucose
	interIn.port6(ii_normal_glycemia);		// => stop glucose injection

	// =============================== Module interOUT
	//Definition du module
	interOUT interOut("interOUT");
	// Signaux de InterOut
	interOut.event_start_sol1(sta_launch_perfusion1);
	interOut.event_stop_sol1(sta_stop_perfusion1);
	interOut.event_start_sol2(sta_launch_perfusion2);
	interOut.event_stop_sol2(sta_stop_perfusion2);
	interOut.event_start_glucose_injection(sta_launch_glucose);
	interOut.event_stop_glucose_injection(sta_stop_glucose);
	interOut.event_start_anticoagulant_injection(c_start_anticoagulant_injection);
	interOut.event_stop_anticoagulant_injection(c_stop_anticoagulant_injection);
	interOut.event_start_antibiotic_injection(c_start_antibiotic_injection);
	interOut.event_stop_antibiotic_injection(ii_stop_antibiotic);


	// =============================== Module Start
	Start start("Start");
	//Mapping events <-> ports
	//out
	start.start1(sta_launch_perfusion1);
	start.start2(sta_launch_perfusion2);
	start.stop1(sta_stop_perfusion1);
	start.stop2(sta_stop_perfusion2);
	start.start_glucose(sta_launch_glucose);
	start.stop_glucose(sta_stop_glucose);
	//in
	start.reset_sol1_from_reset(r_reset_perfusion1);
	start.reset_sol2_from_reset(r_reset_perfusion1);
	start.first_injection(ui_start_simulation);
	start.handle_start_injection1(ii_sol2_1percent);
	start.handle_start_injection2(ii_sol1_1percent);
	start.handle_urgency_injection(ii_critical_glycemia);
	start.handle_average_glycemia(ii_normal_glycemia);
	

	// =============================== Module Reset
	Reset reset("Reset");
	// Mapping signals <-> ports
	// in
	reset.reset_from_user(ui_reset_perfusion);
	reset.sol1_is_empty(ii_sol1_1percent);
	reset.sol2_is_empty(ii_sol2_1percent);
	// out
	reset.reset_sol1_to_start(r_reset_perfusion1);
	reset.reset_sol2_to_start(r_reset_perfusion2);



	// =============================== Module alarme
	Alarme alarme("Alarme");
	// Mapping des signaux <-> ports
	alarme.sol1_5percent(ii_sol1_5percent);
	alarme.sol1_1percent(ii_sol2_1percent);
	alarme.sol2_5percent(ii_sol2_5percent);
	alarme.sol2_1percent(ii_sol2_1percent);
	alarme.critical_glycemia_level(ii_critical_glycemia);
	

	// =============================== Module Stop
	Stop stop("Stop");
	// Mapped signal to ports
	stop.user_stop(ui_stop_simulation);


	// =============================== Module Controler
	Controller controller("Controller");
	// Mapping event <-> ports
	// in
	controller.period_4_hours(ui_period_4_hours);
	controller.period_6_hours(ui_period_6_hours);
	controller.period_8_hours(ui_period_8_hours);
	controller.period_12_hours(ui_period_12_hours);
	controller.tick(clk1.signal());
	//out
	controller.start_anticoagulant(c_start_anticoagulant_injection);
	controller.stop_anticoagulant(c_stop_anticoagulant_injection);
	controller.start_antibiotic(c_start_antibiotic_injection);


	// =============================== Module UserInterface
	UserInterface userInterface("UserInterface");
	//mapping
	userInterface.ui_period_4_hours(ui_period_4_hours);
	userInterface.ui_period_6_hours(ui_period_6_hours);
	userInterface.ui_period_8_hours(ui_period_8_hours);
	userInterface.ui_period_12_hours(ui_period_12_hours);
	userInterface.ui_reset_perfusion(ui_reset_perfusion);
	userInterface.ui_stop_simulation(ui_stop_simulation);
	userInterface.ui_start_simulation(ui_start_simulation);


	SET_COSIM
	MIXED_SIGNAL = true;
	FS = true;
	Speriod_0 = 0.01;

	sc_start(10000, SC_SEC); 
	_getch();

	CLOSE_COSIM  
	return 0;
};
