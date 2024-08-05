//CPP:tcg/random/uniform.cpp
//CPP:tcg/controller.cpp
#if !defined controller_h
#define controller_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"

#include "tcg/random/uniform.h"
#include "time.h"
#include "tcg/utils/constants.h"


class controller: public Simulator { 
// Declare the state,
// output variables
// and parameters

//output
// 1 is lower
// 2 is raise
double y;

//states
double state, sigma;

//params
double inf;
double kc1;
double kc2;
UniformDistribution* du;


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
