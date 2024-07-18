//CPP:tcg/train.cpp
#if !defined train_h
#define train_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"



class train: public Simulator { 
// Declare the state,
// output variables
// and parameters

// states
// u[0] = far
// u[1] = near
// u[2] = inside
// sigma = time advance
float u[3], sigma;

// output
float y;

// parameter
float kt1;
float kt2;

float inf;
public:
	train(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
