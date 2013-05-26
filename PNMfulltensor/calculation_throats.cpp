/*functions to calculate the length of throats and radii of them*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;
/*
 * num_layer - the number of rows in the calculated direction;
 * 
 */
double rad_max(double radius_array[])
{
    double max;
    int length_array;
    length_array = sizeof(radius_array)/sizeof(double);
    max = radius_array[0];
    for (int i = 1; i < length_array; i++)
    {
        if (radius_array[i] > max)
            max = radius_array[i];
    }
    return max;
}
double *throats_length_y(long num_layer, long num_in_row, double pore_bodies[])
{
    double *LT = new double[num_layer - 1];     //pointer for the length of throats
    double array_1[num_in_row];
    double array_2[num_in_row];
    double max_array1;
    double max_array2;
    for (int i = 0; i < num_layer - 1; i++)
    {
        for (int j = 0; j < num_in_row; j++)
        {
            array_1[j] = pore_bodies[i * num_in_row + j];
            array_2[j] = pore_bodies[(i + 1) * num_in_row + j];
        }
        max_array1 = rad_max(array_1);
        max_array2 = rad_max(array_2);
        LT[i] = max_array1 + max_array2;
    }
    return LT;
}

double *throats_length_x(long num_layer, long num_in_row, double pore_bodies[])
{
    double *LT = new double[num_layer - 1];     //pointer for the length of throats
    double array_1[num_in_row];
    double array_2[num_in_row];
    double max_array1;
    double max_array2;
    for (int i = 0; i < num_layer - 1; i++)
    {
        for (int j = 0; j < num_in_row; j++)
        {
            array_1[j] = pore_bodies[j * num_in_row + i];
            array_2[j] = pore_bodies[j * num_in_row + i + 1];
        }
        max_array1 = rad_max(array_1);
        max_array2 = rad_max(array_2);
        LT[i] = max_array1 + max_array2;
    }
    return LT;    
}

double *throats_length_diagonal(double length_x[], double length_y[], long dir_y, 
                                long dir_x)
{
    double *LD = new double[dir_y * dir_x];
    long index;
    for (int i = 0; i < dir_y; i ++)
    {
        for (int j = 0; j < dir_x; j++)
        {
            index = j + dir_x * i;
            LD[index] = sqrt(pow(length_x[j], 2) + pow(length_y[i], 2));
        }
    }
    return LD;
}


