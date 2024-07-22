#include "controller.h"
void controller::init(double t,...) {
//The 'parameters' variable contains the parameters transferred from the editor.
va_list parameters;
va_start(parameters,t);
//To get a parameter: %Name% = va_arg(parameters,%Type%)
//where:
//      %Name% is the parameter name
//	%Type% is the parameter type
inf = 1e20;

u[0]=1.0;
u[1]=0.0;
u[2]=0.0;
u[3]=0.0;

sigma = inf;

y=0.0;

kc1=1.0;
kc2=1.0;
}
double controller::ta(double t) {
//This function returns a double.
return sigma;
}
void controller::dint(double t) {
if (u[1] == 1.0)
{
	u[1] = 0.0;
	u[2] = 1.0;
}
else if (u[3] == 1.0)
{
	u[3] = 0.0;
	u[0] = 1.0;
}
sigma = inf;

}
void controller::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition

double xv;
xv=*(double*)(x.value);

if (u[0] == 1.0 && xv == 1.0) // Train is approaching (1)
{
	u[0] = 0.0;
	u[1] = 1.0;
	sigma = kc1;
}
else if (u[2] == 1.0 && xv == 3.0) // Train exits (3)
{
	u[2] = 0.0;
	u[3] = 1.0;
	sigma = kc2;
}
}
Event controller::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)

if (u[1] == 1.0) {
	y = 1;	// 1 = lower
}
else if (u[3] == 1.0) {	
	y = 2;	// 2 = raise
}
return Event(&y,0);
}
void controller::exit() {
//Code executed at the end of the simulation.

}
