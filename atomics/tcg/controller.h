//CPP:tcg/controller.cpp
#if !defined controller_h
#define controller_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"



class controller: public Simulator { 
// Declare the state,
// output variables
// and parameters

//output
float y;

//states
float u[4], sigma;

//params
float inf;
float kc1;
float kc2;
public:
	controller(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
