//CPP:tcg/random/uniform.cpp
//CPP:tcg/train.cpp
#if !defined train_h
#define train_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"

#include "tcg/random/uniform.h"
#include "tcg/utils/constants.h"
#include "time.h"


class train: public Simulator { 
// Declare the state,
// output variables
// and parameters

double state;
double sigma;

// output
double y;

// parameter
double kt1;
double kt2;

double inf;

bool isTrainPresent;
UniformDistribution* du;

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
