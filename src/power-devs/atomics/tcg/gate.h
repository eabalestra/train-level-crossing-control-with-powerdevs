//CPP:tcg/random/uniform.cpp
//CPP:tcg/gate.cpp
#if !defined gate_h
#define gate_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"

#include "tcg/random/uniform.h"
#include "time.h"
#include "tcg/utils/constants.h"


class gate: public Simulator { 
// Declare the state,
// output variables
// and parameters

//output
double y;

//states
double state, sigma;

//params
double inf;
double kg1;
double kg2;
double kg3;

UniformDistribution* du;
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
