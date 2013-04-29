/*the main code of pore-network modeling for calculating the full permeability 
 tensor.
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

double *lognormal (int num_x, int num_y, double r_min, double r_max,
                  double r_mean, double r_var);
long** cm_diagonal(long num_x, long num_y);
long structure_pt(long num_x, long num_y);

int main ()
{
    using namespace std;
    //srand(time(NULL));
    long num_x, num_y, total_PB; //num_x, num_y: the number of pore bodies in each
                                //direction; total_PB: total number of pore bodies
    cout << "Please input the domain size (x - direction): ";
    cin >> num_x;
    cout << "\n";
    cout << "Please input the domain size (y - direction): ";
    cin >> num_y;
    cout << "\n";
    total_PB = num_x * num_y; 
    //statistic data on pore space
    double r_min, r_max, r_mean, r_var;
    cout << "Please input the value for minimum value of pore body radius: ";
    cin >> r_min;
    cout << "\n";
    cout << "Please input the value for maximum value of pore body radius: ";
    cin >> r_max;
    cout << "\n";
    cout << "Please input the value for the mean value of pore body radius: ";
    cin >> r_mean;
    cout << "\n";
    cout << "Please input the value for the variance of pore body radius: ";
    cin >> r_var;
    cout << "\n";
    double pore_bodies[total_PB];
    double *PB = lognormal(num_x, num_y, r_min, r_max, r_mean, r_var);
    ofstream PBfile("/home/hectorlp/Data/PB_radius.dat");       /*write the pore
    bodies radii into a file with fixed path*/
    for (int i = 0; i < total_PB; i++)
    {
        pore_bodies[i] = PB[i];
        PBfile << pore_bodies[i] << "\n";
    }
    delete[] PB;
    PBfile.close();
    
    cout << "The radii of pore bodies have been generated. "<<endl;
    /*construct the connectivity matrix and throat-body structure*/
    long total_num_throats = structure_pt(num_x, num_y);
    long connectivity_matrix[total_num_throats][2];
    long **MX_connectivity = cm_diagonal(num_x, num_y);
    ofstream ConnectMXfile("/home/hectorlp/Data/connectivity_mx.dat");
    for (int i = 0; i < total_num_throats; i++)
    {
        connectivity_matrix[i][0] = MX_connectivity[i][0];
        connectivity_matrix[i][1] = MX_connectivity[i][1];
        ConnectMXfile << connectivity_matrix[i][0];
        ConnectMXfile.width(8);
        ConnectMXfile << connectivity_matrix[i][1] << "\n";
    }
    //delete[] MX_connectivity;
    ConnectMXfile.close();
    cout << "clean the memory for the connectivity matrix.\n";
    for (int i = 0; i < total_num_throats; i++)
    {
        delete [] MX_connectivity[i];
    }
    delete [] MX_connectivity;
    /*calculate radii of pore throats*/
    
    double pore_throats[total_num_throats], length_throats_x[num_x - 1], 
            length_throats[num_y - 1];
    using std::max;
    for (int i = 0; i < num_y - 1; i++)
    {
        
    }
    
    /*Generate the buffering part*/
    
    return 0;
}