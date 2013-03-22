/*the main code of pore-network modeling for calculating the full permeability 
 tensor.
*/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
double lognormal (int num_x, int num_y, double r_min, double r_max,
                  double r_mean, double r_var);

int main ()
{
    using namespace std;
    //srand(time(NULL));
    int num_x, num_y, total_PB; //num_x, num_y: the number of pore bodies in each
                                //direction; total_PB: total number of pore bodies
    num_x = 200;
    num_y = 200;
    total_PB = num_x * num_y; 
    //statistic data on pore space
    double r_min, r_max, r_mean, r_var;
    double pore_bodies[total_PB];
    double *PB = lognormal(num_x, num_y, r_min, r_max, r_mean, r_var);
    for (int i = 0; i < total_PB; i++)
    {
        pore_bodies[i] = PB[i];
    }
    delete[] PB;
    cout << "The radii of pore bodies have been generated. "<<endl;
    return 0;
}