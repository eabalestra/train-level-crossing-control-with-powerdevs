#include "gate.h"
void gate::init(double t,...) {
//The 'parameters' variable contains the parameters transferred from the editor.
va_list parameters;
va_start(parameters,t);
//To get a parameter: %Name% = va_arg(parameters,%Type%)
//where:
//      %Name% is the parameter name
//	%Type% is the parameter type
char *fvar;

fvar = va_arg(parameters,char*);
kg1 = getScilabVar(fvar);

fvar = va_arg(parameters,char*);
kg2 = getScilabVar(fvar);

fvar = va_arg(parameters,char*);
kg3 = getScilabVar(fvar);

fvar = va_arg(parameters,char*);
int seed = (strlen(fvar)==0 ? (int)time(0)+rand() : getScilabVar(fvar)); // random seed

inf = INF;
state = OPEN;
sigma = inf;
y = 0.0;
du = new UniformDistribution(seed);

}
double gate::ta(double t) {
//This function returns a double.
return sigma;
}
void gate::dint(double t) {
if (state == LOWERING)
{
	state = CLOSED;
}
else if (state == RAISING)
{
	state = OPEN;
}
sigma = inf;
}
void gate::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition
double xv;
xv=*(double*)(x.value);
if (state == OPEN && xv == LOWER)
{				
	state = LOWERING;
	sigma = du->genUniform(0.0, kg1);
	printLog("GATE is Lowering. will_be: %f\n", sigma);
}
else if (state == CLOSED && xv == RAISE)
{	
	state = RAISING;
	sigma = du->genUniform(kg2, kg3);
	printLog("GATE is Raising. will_be: %f\n", sigma);
}
}
Event gate::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)

if (state == LOWERING) {
	y = DOWN;
	printLog("GATE - Down!. c_time: %f\n",getTime());

}
else if (state == RAISING) {
	y = UP;
	printLog("GATE - Up!. c_time: %f\n",getTime());
	printLog("\n\n");
}
return Event(&y,0);
}
void gate::exit() {
//Code executed at the end of the simulation.

}
