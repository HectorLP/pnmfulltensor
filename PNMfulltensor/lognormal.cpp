//function for the truncated log-normal distribution
/*Purpose: this program generates the value from 
 *the truncated log-normal distribution
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

double Error(double x);

double *lognormal(int num_x, int num_y, double r_min, double r_max, double r_mean, double var)
{
	using namespace std;
	double term1, term2, er, denom1;
	double denom2, pi, a, b, c, x1, x2, fac;
	pi = 3.141592653589793;
	double x;
	long total_num;
	total_num = num_x * num_y;
	double *PB = new double[total_num];
	
	int bins;
	bins = 20;
	int h[bins];
	//caculate denom1
	term1 = log(r_max / r_mean);
	term2 = 2.0 * (pow(var, 2));
	x = term1 / (sqrt(term2));
	double err;
	err = Error(x);
	denom1 = err;
	//calculate denom2
	term1 = log(r_min/r_mean);
	term2 = 2.0 * (pow(var, 2));
	x = term1 / (sqrt(term2));
	err = Error(x);
	denom2 = err;

	a = 0.5 / (pow(var, 2));
	b = 1.0 - log(r_mean) / (pow(var, 2));
	fac = (exp(pow(b, 2)/(4.0 * a) - 0.5 / pow(var, 2)*pow(log(r_mean), 2))*sqrt(2.0) / ((denom1 - denom2)*sqrt(pi*pow(var, 2))));
	
	double uniform_x;
	srand(time(NULL));
	for (int i = 0; i < total_num; i++)
	{
		uniform_x = ((double)rand() / (double)RAND_MAX);
		//uniform_x = uniform_x * (1.0 - 0.0) + 0.0;
		//cout << "uniform x" << uniform_x << endl;
		term1 = (fac*uniform_x*(denom1-denom2)*sqrt(pi*pow(var, 2)))/sqrt(2.0);
		c = 0.5 / (pow(var, 2.0)) * pow(log(r_mean), 2.0) + log(term1);
		x1 = exp((-b+sqrt(pow(b, 2)-4*a*c))/(2.0*a));
		x2 = exp((-b-sqrt(pow(b, 2)-4*a*c))/(2.0*a));
		if (x1 <= r_max && x1 >= r_min)
		{
			PB[i] = x1; 
			//cout << PB;
		}
		else if (x2 <= r_max && x2 >= r_min)
		{
			PB[i] = x2;
			//cout << PB;
		}
	}
	return PB;
}
