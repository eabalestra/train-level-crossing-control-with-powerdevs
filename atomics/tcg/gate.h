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
float y;

//states
float u[4], sigma;

//params
float inf;
float kg1;
float kg2;
float kg3;
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
