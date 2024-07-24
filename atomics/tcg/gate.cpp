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

int seed = 445566;
du = new UniformDistribution(seed);

}
double gate::ta(double t) {
//This function returns a double.
return sigma;
}
void gate::dint(double t) {
if (u[1] == 1.0) // if state is lowering
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
void gate::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition
double xv;
xv=*(double*)(x.value);
if (u[0] == 1.0 && xv == 1.0) // 1 = lower
{				
	u[0] = 0.0;
	u[1] = 1.0;
	//sigma = kg1;
	sigma = du->genUniform(0.0, kg1);
	printLog("GATE is Lowering. will_be: %f\n", sigma);
}
else if (u[2] == 1.0 && xv == 2.0) // 2 = raise
{	
	u[2] = 0.0;
	u[3] = 1.0;
	//sigma = kg3 - kg2;
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

if (u[1] == 1.0) {
	y = 1;	// 1 = down
	printLog("GATE - Down!. c_time: %f\n",getTime());

}
else if (u[3] == 1.0) {	
	y = 2;	// 2 = up
	printLog("GATE - Up!. c_time: %f\n",getTime());
	printLog("\n\n");
}
return Event(&y,0);
}
void gate::exit() {
//Code executed at the end of the simulation.

}
