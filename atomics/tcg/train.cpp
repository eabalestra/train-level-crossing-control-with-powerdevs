#include "train.h"
void train::init(double t,...) {
//The 'parameters' variable contains the parameters transferred from the editor.
va_list parameters;
va_start(parameters,t);
//To get a parameter: %Name% = va_arg(parameters,%Type%)
//where:
//      %Name% is the parameter name
//	%Type% is the parameter type

inf = 1e20;

u[0] = 1.0; // far
u[1] = 0.0; // near
u[2] = 0.0; // inside

sigma = inf;
isTrainPresent = false;

y = 0.0;

kt1 = 2.0;
kt2 = 5.0;

int seed = 123;
du = new UniformDistribution(seed);

}
double train::ta(double t) {
//This function returns a double.
return sigma;
}
void train::dint(double t) {
if (u[0] == 1.0)
{
	u[0] = 0.0;
	u[1] = 1.0;
	sigma = du->genUniform(kt1, kt2);
	printLog("TRAIN is Near. will_be: %f\n", sigma);
} 
else if (u[1] == 1.0)
{
	u[1] = 0.0;
	u[2] = 1.0;
	sigma = du->genUniform(0.0, kt2);
	printLog("TRAIN is Inside. will_be: %f\n", sigma);
} 
else if (u[2] == 1.0) 
{
	u[2] = 0.0;
	u[0] = 1.0;
	sigma = inf;
	printLog("TRAIN is Far. will_be: inf\n");
	isTrainPresent = false;
}
}
void train::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition

//double xv;
//xv=*(double*)(x.value);
if (!isTrainPresent && u[0] == 1.0)
{
	sigma = 0;
	printLog("TRAIN is Coming. in: %f\n", sigma);
}
else
{
	sigma = sigma - e;
}
}
Event train::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)

if (u[0] == 1.0) // aproach
{
	printLog("TRAIN - Approach! c_time: %f\n",getTime());
	y = 1.0;
}
else if (u[1] == 1.0) // in
{
	printLog("TRAIN - In! c_time: %f\n",getTime());
	y = 2.0;
}
else if (u[2] == 1.0) // exit
{
	printLog("TRAIN - Exit! c_time: %f\n",getTime());
	y = 3.0;
}

return Event(&y, 0);
}
void train::exit() {
//Code executed at the end of the simulation.

}
