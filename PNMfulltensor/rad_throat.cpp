/*The function for calculating the radius of each pore throat
 * 
 */

#include <iostream>
#include <cmath>

double Radius_Throat(double len_throat, double rad_PB1,double rad_PB2, 
                        double expon_num)
{
    using namespace std;
    double pi;
    pi = 3.1415926535897932;
    double relative_r1, relative_r2;
    relative_r1 = rad_PB1 / len_throat;
    relative_r2 = rad_PB2 / len_throat;
    double ti, tj, relative_throat;
    ti = relative_r1 * sin(pi / 4.0) / pow((1 - relative_r1 * cos(pi / 4.0)), 
            expon_num);
    tj = relative_r2 * sin(pi / 4.0) / pow((1 - relative_r2 * cos(pi / 4.0)) ,
            expon_num);
    relative_throat = ti * tj / pow((pow(relative_r1, 1.0 / expon_num) + pow(relative_r2,
            expon_num)), expon_num);
    double rad_throat;
    rad_throat = relative_throat * len_throat;
    return rad_throat;
}
