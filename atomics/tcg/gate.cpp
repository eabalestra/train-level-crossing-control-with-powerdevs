#include "gate.h"
void gate::init(double t,...) {
//The 'parameters' variable contains the parameters transferred from the editor.
va_list parameters;
va_start(parameters,t);
//To get a parameter: %Name% = va_arg(parameters,%Type%)
//where:
//      %Name% is the parameter name
//	%Type% is the parameter type
inf = 1e20;

u[0]=1.0;	// open
u[1]=0.0;	// lowering
u[2]=0.0;	// closed
u[3]=0.0;	// raising

sigma = inf;

y = 0.0;

kg1 = 1.0;
kg2 = 1.0;
kg3 = 2.0;
}
double gate::ta(double t) {
//This function returns a double.
return sigma;
}
void gate::dint(double t) {
printLog("INTERNAL TRANSITION\n");
if (u[1] == 1.0) // if state is lowering
{
	u[1] = 0.0;
	u[2] = 1.0;
	printLog("PASA A CLOSED\n"); 
}
else if (u[3] == 1.0)
{
	u[3] = 0.0;
	u[0] = 1.0;
	printLog("PASA A OPEN\n");
}
sigma = inf;
printLog("\n\n");
}
void gate::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition
printLog("EXTERNAL TRANSITION\n");
double xv;
xv=*(double*)(x.value);
printLog("LLEGO UN: %f\n", xv);
if (u[0] == 1.0 && xv == 6.0) // 6 = lower
{				
	u[0] = 0.0;
	u[1] = 1.0;
	sigma = kg1;
}
else if (u[2] == 1.0 && xv == 7.0) // 7 = raise
{	
	u[2] = 0.0;
	u[3] = 1.0;
	sigma = kg3 - kg2;
}
}
Event gate::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)

if (u[1] == 1.0) {
	y = 8;	//  = down
}
else if (u[3] == 1.0) {	
	y = 9;	//  = up
}
printLog("SACA UN %f\n",y);
printLog("VALOR DE OUTPUT GATE: %f", &y);
return Event(&y,0);
}
void gate::exit() {
//Code executed at the end of the simulation.

}
