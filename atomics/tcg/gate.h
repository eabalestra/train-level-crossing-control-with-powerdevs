//CPP:tcg/gate.cpp
#if !defined gate_h
#define gate_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"



class gate: public Simulator { 
// Declare the state,
// output variables
// and parameters

//output
// 1 is down
// 2 is up
double y;

//states
double u[4], sigma;

//params
double inf;
double kg1;
double kg2;
double kg3;
public:
	gate(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
