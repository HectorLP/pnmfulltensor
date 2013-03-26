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
    cout << "Please input the domain size (x - direction): ";
    cin >> num_x;
    cout << endl;
    cout << "Please input the domain size (y - direction): ";
    cin >> num_y;
    cout << endl;
    total_PB = num_x * num_y; 
    //statistic data on pore space
    double r_min, r_max, r_mean, r_var;
    cout << "Please input the value for minimum value of pore body radius: ";
    cin >> r_min;
    cout << endl;
    cout << "Please input the value for maximum value of pore body radius: ";
    cin >> r_max;
    cout << endl;
    cout << "Please input the value for the mean value of pore body radius: ";
    cin >> r_mean;
    cout << endl;
    cout << "Please input the value for the variance of pore body radius: ";
    cin >> r_var;
    cout << endl;
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