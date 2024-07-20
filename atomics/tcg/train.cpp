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

sigma = 15.0;

y = 0.0;

kt1 = 2.0;
kt2 = 5.0;
}
double train::ta(double t) {
//This function returns a double.
return sigma;
}
void train::dint(double t) {
if (u[0] == 1.0)
{
	u[1] = 1.0;
	u[0] = 0.0;
	sigma = kt2 - kt1;
}
else if (u[1] == 1.0)
{
	u[1] = 0.0;
	u[2] = 1.0;
	sigma = kt2;
}
else if (u[2] == 1.0)
{
	u[0] = 1.0;
	u[2] = 0.0;
	sigma = 15.0;
}
}
void train::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition

}
Event train::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)

//3 in
//4 aproach
//5 exit
if (u[0] == 1.0)
{
	y = 4.0;
}
else if (u[1] == 1.0)
{
	y = 3.0;
}
else if (u[2] == 1.0)
{
	y = 5.0;
}

printLog("VALOR DE OUTPUT TRAIN: %f", &y);
return Event(&y, 0);
}
void train::exit() {
//Code executed at the end of the simulation.

}
