/*The function to generate the structure with coordination number can be 4 or 8 
 * in the whole network
 * The procedure follows the way as:
 * 1. Throats in horizontal direction is generated (num_pt_horiz);
 * 2. Throats in vertical direction is generated (num_pt_vert);
 * 3. Throats in diagonal direction is generated (num_pt_diag);
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
using namespace std;

long num_pt_horiz, num_pt_vert, num_pt_diag;

long structure_pt(long num_x, long num_y)
{
    num_pt_horiz = (num_x - 1) * num_y;
    num_pt_vert = (num_y - 1) * num_x;
    num_pt_diag = (num_x - 1) * (num_y - 1);
    long total_num_pt;
    total_num_pt = num_pt_horiz + num_pt_vert + num_pt_diag;
    return total_num_pt;
}

/*The function is to generate the connectivity matrix and in this modeling the 
 * style is pore throat - pore bodies, which means the row number of the matrix 
 * is the number of pore throat and each element in the row is the number of pore
 * body. The total number of elements is total_num_pt * 2
 */
long **cm_diagonal(long num_x, long num_y)       //cm is 'connectivity matrix '
{
    
    long** connectivity_mx = 0;
    long total_connectivity;
    total_connectivity = structure_pt(num_x, num_y);
    cout << "the total number of pore throats: " << total_connectivity << ".\n";
    connectivity_mx = new long*[total_connectivity];
    
    /*connecting information in horizontal direction*/
    long index_num;
    for (int i = 0; i <= num_y - 1; i++)
    {
        for (int j = 0; j <= num_x - 2; j++)
        {
            index_num = (num_x - 1) * i + j;
            connectivity_mx[index_num] = new long[2];
            connectivity_mx[index_num][0] = num_x * i + j;
            connectivity_mx[index_num][1] = num_x * i + (j + 1);
            /*cout << "the index for the matrix" << index_num << "\n";
            cout << "the elements in CM: " << connectivity_mx[index_num][0] << ", "
                    << connectivity_mx[index_num][1] << "\n";*/
        }
    }
    /*connectivity information in vertical direction*/
    for (int i = 0; i <= num_y - 2; i++)
    {
        for (int j = 0; j <= num_x - 1; j++)
        {
            index_num = (num_x - 1) * num_y + (i * num_x) + j;
            connectivity_mx[index_num] = new long[2];
            connectivity_mx[index_num][0] = num_x * i + j;
            connectivity_mx[index_num][1] = num_x * (i + 1) + j;
            /*cout << "the index for the matrix" << index_num << "\n";
            cout << "the elements in CM: " << connectivity_mx[index_num][0] << ", "
                    << connectivity_mx[index_num][1] << "\n";*/
        }
    }
    /*connectivity information in diagonal direction*/
    if (num_x%2 == 0)
    {
        for (int i = 0; i <= num_y - 2; i++)
        {
            
            if (i%2 == 0)
            {
                for (int j = 0; j <= num_x - 2; j++)
                {
                    if (j%2 == 0)
                    {   
                        index_num = index_num + 1;
                        connectivity_mx[index_num] = new long[2];
                        connectivity_mx[index_num][0] = j + i * num_x;
                        connectivity_mx[index_num][1] = (j + 1) + (i + 1) * num_x;
                        /*cout << "the index for the matrix" << index_num << "\n";
                        cout << "the elements in CM: " << connectivity_mx[index_num][0] << ", "
                                << connectivity_mx[index_num][1] << "\n";*/
                        if (j > 0)
                        {
                            index_num = index_num + 1;
                            connectivity_mx[index_num] = new long[2];
                            connectivity_mx[index_num][0] = j + i * num_x;
                            connectivity_mx[index_num][1] = j - 1 + (i + 1) * num_x;
                            /*cout << "the index for the matrix" << index_num << "\n";
                            cout << "the elements in CM: " << connectivity_mx[index_num][0] << ", "
                                << connectivity_mx[index_num][1] << "\n";*/
                        }
                    }
                }
            }
            else if (i%2 != 0)
            {
                for (int j = 0; j<= num_x -1; j++)
                {
                    if (j%2 != 0)
                    {
                        index_num = index_num + 1;
                        connectivity_mx[index_num] = new long[2];
                        connectivity_mx[index_num][0] = j + i * num_x;
                        connectivity_mx[index_num][1] = (j - 1) + (i + 1) * num_x;
                        /*cout << "the index for the matrix" << index_num << "\n";
                        cout << "the elements in CM: " << connectivity_mx[index_num][0] << ", "
                        << connectivity_mx[index_num][1] << "\n";*/
                        if (j < num_x - 1)
                        {
                            index_num = index_num + 1;
                            connectivity_mx[index_num] = new long[2];
                            connectivity_mx[index_num][0] = j + i * num_x;
                            connectivity_mx[index_num][1] = (j + 1) + (i + 1) * num_x;
                            /*cout << "the index for the matrix" << index_num << "\n";
                            cout << "the elements in CM: " << connectivity_mx[index_num][0] << ", "
                            << connectivity_mx[index_num][1] << "\n";*/
                        }
                    }
                }
            }
        }
    }
    else if (num_x%2 != 0)
    {
        int loop_index;
        for (int i = 0; i <= num_y - 2; i++)
        {
            if (i%2 == 0)
            {
                loop_index = 0;
                for (int j = 0; j <= num_x - 2; j++)
                {
                    loop_index = loop_index + 1;
                    if (j%2 == 0)
                    {
                        //loop_index = loop_index + 1;
                        if (j > 0)
                        {
                            index_num = index_num + 1;
                            connectivity_mx[index_num] = new long[2];
                            connectivity_mx[index_num][0] = j + i * num_x;
                            connectivity_mx[index_num][1] = (j - 1) + (i + 1) * num_x;
                            /*cout << "the index for the matrix" << index_num << "\n";
                            cout << "the elements in CM: " << connectivity_mx[index_num][0] << ", "
                            << connectivity_mx[index_num][1] << "\n";*/
                        }   
                        index_num = index_num + 1;
                        connectivity_mx[index_num] = new long[2];
                        connectivity_mx[index_num][0] = j + i * num_x;
                        connectivity_mx[index_num][1] = (j + 1) + (i + 1) * num_x;
                        /*cout << "the index for the matrix" << index_num << "\n";
                        cout << "the elements in CM: " << connectivity_mx[index_num][0] << ", "
                        << connectivity_mx[index_num][1] << "\n";*/               
                    }
                }
                index_num = index_num + 1;
                connectivity_mx[index_num] = new long[2];
                connectivity_mx[index_num][0] = loop_index + i * num_x;
                connectivity_mx[index_num][1] = loop_index - 1 + (i + 1) * num_x;
                /*cout << "the index for the matrix" << index_num << "\n";
                cout << "the elements in CM: " << connectivity_mx[index_num][0] << ", "
                    << connectivity_mx[index_num][1] << "\n";*/
            }
            else if (i%2 != 0)
            {
                for (int j = 0; j <= num_x - 2; j++)
                {
                    if (j%2 != 0)
                    {
                        index_num = index_num + 1;
                        connectivity_mx[index_num] = new long[2];
                        connectivity_mx[index_num][0] = j + i * num_x;
                        connectivity_mx[index_num][1] = (j + 1) + (i + 1) * num_x;
                        /*cout << "the index for the matrix" << index_num << "\n";
                        cout << "the elements in CM: " << connectivity_mx[index_num][0] << ", "
                        << connectivity_mx[index_num][1] << "\n";*/
                        index_num = index_num + 1;
                        connectivity_mx[index_num] = new long[2];
                        connectivity_mx[index_num][0] = j + i * num_x;
                        connectivity_mx[index_num][1] = (j - 1) + (i + 1) * num_x;
                        /*cout << "the index for the matrix" << index_num << "\n";
                        cout << "the elements in CM: " << connectivity_mx[index_num][0] << ", "
                        << connectivity_mx[index_num][1] << "\n";*/
                    }
                }
            }
        }
    }
    cout << "finish the connectivity matrix" << "\n";
    return connectivity_mx;
}