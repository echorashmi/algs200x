#include <iostream>
#include <cstdlib>
#include "helper.cpp"

using namespace std;
using std::swap;

typedef struct midpoints_struct{
    int midpoint_one;
    int midpoint_two;
}midpoints_struct;

HelperClass helper;

/*
* Splits input $data into three parts as follows:
* Part 1: Less than Left. Part 2: Equal to Left. Part 3: Greater than Left.
* Input: array to be split, left most element, right most element.
* Output: The 2 midpoint indices (Starting and ending bound of midpoint)
*/ 
midpoints_struct partition_threeway(int *data, int left_index, int right_index)
{
    int newdata[data_length];
    int c1 = 0, region1[data_length];
    int c2 = 0, region2[data_length];
    int c3 = 0, region3[data_length];
    int pivot = data[left_index];
    printf("\n\n Midpoint (Pivot) Value: %i \n\n", pivot);

    for(int i = 0; i < data_length; i++)
    {
        if(data[i] < pivot)
        {
            region1[c1] = data[i];
            c1++;
        }
        else if(data[i] == pivot)
        {
            region2[c2] = data[i];
            c2++;
        }
        else if(data[i] > pivot)
        {
            region3[c3] = data[i];
            c3++;
        }
    }

    helper.print_array(region1, c1);
    helper.print_array(region2, c2);
    helper.print_array(region3, c3);

    for(int i = 0; i < c1; i++)
    {
        data[i] = region1[i];
        newdata[i] = region1[i];
    }
    
    int j = c1;
    for(int i = 0; i < c2; i++)
    {
        data[j] = region2[i];
        newdata[j] = region2[i];
        j++;
    }

    j = c1 + c2;
    for(int i = 0; i < c3; i++)
    {
        data[j] = region3[i];
        newdata[j] = region3[i];
        j++;
    }
    midpoints_struct midpoints;
    midpoints.midpoint_one = c1;
    midpoints.midpoint_two = c1 + c2;

    return midpoints;
}

int main(void)
{
    midpoints_struct midpoints;
    
    int data[] = {10, 10, 20, 20, 5, 1, 8, 8, 9, 11, 6};
    int left_index = 0;
    int right_index = 10;

    midpoints = partition_threeway(data, left_index, right_index);

    printf("\n\nMidpoint One: %i, Midpoint Two: %i\n\n", midpoints.midpoint_one, midpoints.midpoint_two);

    printf("\n\nPartitioned Data Array: \n\n");
    helper.print_array(data, data_length);
    
}