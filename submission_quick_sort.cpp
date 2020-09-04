#include <iostream>
#include <cstdlib>

using std::swap;

typedef struct midpoints_struct{
    int midpoint_one;
    int midpoint_two;
}midpoints_struct;

const int data_length = 100000;
int dataset[data_length];

int partition2(int *data, int left, int right) 
{
    int pivot = data[left];
    int midpoint = left;
    
    for (int i = left + 1; i <= right; i++) 
    {
        if (data[i] <= pivot) 
        {
            midpoint++;
            swap(data[i], data[midpoint]);
        }
    }
    swap(data[left], data[midpoint]);
    return midpoint;
} 

midpoints_struct partition_threeway(int *data, int input_size, int left_index, int right_index, bool debug)
{
    int newdata[input_size];
    int c1 = 0, region1[input_size];
    int c2 = 0, region2[input_size];
    int c3 = 0, region3[input_size];
    int pivot = data[left_index];

    for(int i = 0; i < input_size; i++)
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

void randomized_quick_sort(int *data, int input_size, int left, int right, int use_threeway_partition, bool debug) 
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

    midpoints_struct midpoints = partition_threeway(data, input_size, left, right, debug);
    randomized_quick_sort(data, input_size, left, midpoints.midpoint_one - 1, use_threeway_partition, debug);
    randomized_quick_sort(data, input_size, midpoints.midpoint_two + 1, right, use_threeway_partition, debug);
}

int main(int argc, char * argv[]) 
{
    int use_threeway_partition;
    int n;
    bool debug = false;
    std::cin >> n;
    int data[n];
    for (int i = 0; i < n; ++i) 
    {
        std::cin >> data[i];
    }

    randomized_quick_sort(data, n, 0, n - 1, use_threeway_partition = 1, debug);
    for (size_t i = 0; i < n; ++i) 
    {
        std::cout << data[i] << ' ';
    }
}