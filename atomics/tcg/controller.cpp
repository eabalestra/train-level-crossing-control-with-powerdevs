#include "controller.h"
void controller::init(double t,...) {
	//The 'parameters' variable contains the parameters transferred from the editor.
va_list parameters;
va_start(parameters,t);
//To get a parameter: %Name% = va_arg(parameters,%Type%)
//where:
//      %Name% is the parameter name
//	%Type% is the parameter type
char *fvar;

fvar = va_arg(parameters,char*);
kc1 = getScilabVar(fvar);

fvar = va_arg(parameters,char*);
kc2 = getScilabVar(fvar);

fvar = va_arg(parameters,char*);
int seed = (strlen(fvar)==0 ? (int)time(0)+rand() : getScilabVar(fvar)); // random seed

inf = INF;
u[0]=1.0;
u[1]=0.0;
u[2]=0.0;
u[3]=0.0;
sigma = inf;
y = 0.0;
du = new UniformDistribution(seed);

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
	sigma = du->genUniform(0.0, kc1);
	printLog("CONTROLLER is SC2 will_be: %f\n", sigma);
}
else if (u[2] == 1.0 && xv == 3.0) // Train exits (3)
{
	u[2] = 0.0;
	u[3] = 1.0;
	sigma = du->genUniform(0.0, kc2);
	printLog("CONTROLLER is SC4 will_be %f\n", sigma);
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
	printLog("CONTROLLER - Lower!. c_time: %f\n", getTime());
}
else if (u[3] == 1.0) {	
	y = 2;	// 2 = raise
	printLog("CONTROLLER - Raise!. c_time: %f\n", getTime());
}
return Event(&y,0);
}
void controller::exit() {
//Code executed at the end of the simulation.

}
