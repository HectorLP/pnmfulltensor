/*Function for generating the value from erf(x)
*       ===================================================
*       Purpose: This program computes the error function 
*                erf(x) using subroutine ERROR
*       Input:   x   --- Argument of erf(x)
*       Output:  ERR --- erf(x)
*       Example:
*                  x         erf(x)
*                ---------------------
*                 1.0       .84270079
*                 2.0       .99532227
*                 3.0       .99997791
*                 4.0       .99999998
*                 5.0      1.00000000
*       ===================================================
*/

#include <cmath>
#include <iostream>

double Error(double x)
{
	using namespace std;
	double eps, pi, x2;
	eps = 1.0e-15;
	pi = 3.141592653589793;
	x2 = x * x;
	double er, r, c0;
	double err;
	er = 1.0;
	r = 1.0;
	if (fabs(x) < 3.50)
	{
		for (int i = 1; i<=50; i++)
		{
			r = r * x2 / (i + 0.50);
			er = er + r;
			if  (fabs(r) <= fabs(er) * eps)
				r = 1.0;
		}
		c0 = 2.0 / sqrt(pi) * x * exp(-x2);
		err = c0 * er;
	}
	else 
	{
		for (int i = 1; i <= 12; i++)
		{
			r = -r * (i - 0.5) / x2;
			er = er + r;
		}
		c0 = exp(-x2) / (fabs(x) * sqrt(pi));
		err = 1.0 - c0 * er;
		if (x < 0)
			err = -err;
	}
	return err;
}
