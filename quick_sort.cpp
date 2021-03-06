/*
    To Do: Learn how to calculate Runtime of this Program from ALGS200x. 
    Once that's done, then start to optimize and reduce the run time of this Algo. 
*/
#include <iostream>
#include <cstdlib>
#include "helper.cpp"
//#include "partition.cpp"

using namespace std;
using std::swap;

typedef struct midpoints_struct{
    int midpoint_one;
    int midpoint_two;
}midpoints_struct;

int partition2(int *data, int left, int right) 
{
    int pivot = data[left]; //O(1)
    int midpoint = left; //O(n)? or //O(1)
    
    for (int i = left + 1; i <= right; i++) //Times O(n)
    {
        if (data[i] <= pivot)
        {
            midpoint++; //O(1)
            swap(data[i], data[midpoint]); //O(1)
        }
    }
    swap(data[left], data[midpoint]); //O(1)
    return midpoint; //O(1)
}

midpoints_struct partition_threeway(int *data, int left_index, int right_index, bool debug)
{
    int newdata[data_length];
    int c1 = 0, region1[data_length];
    int c2 = 0, region2[data_length];
    int c3 = 0, region3[data_length];
    int pivot = data[left_index];

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

void randomized_quick_sort(int *data, int left, int right, int use_threeway_partition, bool debug) 
{
    if (left > right) 
    {
        return;
    }
    time_t t;
    srand((unsigned) time(&t));
    
    int random_index_of_array = left + rand() % (right - left + 1);
    int midpoint_one, midpoint_two;
    
    swap(data[left], data[random_index_of_array]);

    if (use_threeway_partition == 1)
    {
        midpoints_struct midpoints = partition_threeway(data, left, right, debug);
        randomized_quick_sort(data, left, midpoints.midpoint_one - 1, use_threeway_partition, debug);
        randomized_quick_sort(data, midpoints.midpoint_two + 1, right, use_threeway_partition, debug);
    } 
    else //Use Two Way Partition:
    {
        int midpoint = partition2(data, left, right);
        randomized_quick_sort(data, left, midpoint - 1, use_threeway_partition, debug);
        randomized_quick_sort(data, midpoint, right, use_threeway_partition, debug);
    }
}

int main(int argc, char * argv[]) 
{
    HelperClass helper_object;
    bool set_debug_mode = false;
    bool debug = false;
    if(argv[1] && (strcmp(argv[1], "debug") == 0))
    {
        set_debug_mode = true;
    }
    
    if(set_debug_mode)
    {
        debug = true;
        const int array_length   = data_length;
        int data_two_way[array_length];
        int use_threeway_partition;
        
        //int data_three_way[array_length] = {0, 315, 402, 355, 27, 322, 391, 322, 119, 80};
        
        //int data_three_way[array_length];
        //Generate a Test Data Set with Random Numbers:
        helper_object.generate();
        
        //Assign the numbers to the 2 test arrays:
        for (int i = 0; i < array_length; i++) 
        {
            data_three_way[i] = dataset[i];
            data_two_way[i]   = dataset[i];
        }

        //Call Quick Sort using Three Way Partition: 
        randomized_quick_sort(data_three_way, 0, array_length - 1, use_threeway_partition = 1, debug);

        //Call Quick Sort using Two Way Partition:
        randomized_quick_sort(data_two_way, 0, array_length - 1, use_threeway_partition = 0, debug);

        helper_object.check_if_sorted(data_three_way, array_length);

        //Output the Comparision Result of Two Way v/s Three Way Partition. 
        std::cout << "\n\nComparision Result: " << helper_object.compare_two_arrays(data_three_way, data_two_way, array_length);

        std::cout << "\n\n";
    }
    else
    {
        int use_threeway_partition;
        int n;
        std::cin >> n;
        int data[n];
        for (int i = 0; i < n; ++i) 
        {
            std::cin >> data[i];
        }

        randomized_quick_sort(data, 0, n - 1, use_threeway_partition = 1, debug);
        
        printf("\n\nOutput: \n\n");
        for (size_t i = 0; i < n; ++i) 
        {
            std::cout << data[i] << ' ';
        }
        printf("\n\n");
    }
}