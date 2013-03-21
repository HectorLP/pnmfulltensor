/*the main code of pore-network modeling for calculating the full permeability 
 tensor.
*/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
double lognormal (int num_x, int num_y);

int main ()
{
    using namespace std;
    //srand(time(NULL));
    int num_x, num_y, total_PB; //num_x, num_y: the number of pore bodies in each
                                //direction; total_PB: total number of pore bodies
    num_x = 200;
    num_y = 200;
    total_PB = num_x * num_y; 
    double pore_bodies[total_PB];
    return 0;
}