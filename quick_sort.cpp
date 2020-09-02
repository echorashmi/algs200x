/*
* TODO: Test Cases - Refer to Section 3.4 (Testing & Debugging) of the Algorithms guide
*
*
*/

#include <iostream>
#include <cstdlib>

using std::swap;

typedef struct midpoints_struct{
    int midpoint_one;
    int midpoint_two;
}midpoints_struct;

const int data_length = 99999;
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

midpoints_struct partition3(int *data, int left, int right) 
{
    int pivot = data[left];
    int midpoint_one_var = left;
    int midpoint_two_var = left;

    for(size_t i = left + 1; i <= right; i++)
    {
        if(data[i] < pivot)
        { 
            midpoint_one_var++; 
            midpoint_two_var++;
            swap(data[i], data[midpoint_one_var]);
        }
        else if(data[i] == pivot)
        {
            midpoint_two_var++;
            swap(data[i], data[midpoint_two_var]);
        }
    }
    swap(data[left], data[midpoint_one_var]);

    midpoints_struct midpoints;
    midpoints.midpoint_one = midpoint_one_var;
    midpoints.midpoint_two = midpoint_two_var;

    return midpoints;
}

void randomized_quick_sort(int *data, int left, int right, int use_threeway_partition) 
{
    if (left >= right) 
    {
        return;
    }

    //We want to choose a random array item as a Pivot element, not just the first one. Reasons: https://stackoverflow.com/questions/41513856/can-someone-clarify-the-difference-between-quicksort-and-randomized-quicksort
    int random_index_of_array = left + rand() % (right - left + 1);
    int midpoint_one, midpoint_two;
    
    swap(data[left], data[random_index_of_array]);

    if (use_threeway_partition == 1)
    {
        midpoints_struct midpoints = partition3(data, left, right);
        randomized_quick_sort(data, left, midpoints.midpoint_one - 1, use_threeway_partition);
        randomized_quick_sort(data, midpoints.midpoint_two + 1, right, use_threeway_partition);
    } 
    else //Use Two Way Partition:
    {
        int midpoint = partition2(data, left, right);
        randomized_quick_sort(data, left, midpoint - 1, use_threeway_partition);
        randomized_quick_sort(data, midpoint + 1, right, use_threeway_partition);
    }
}

bool compare_two_arrays(int *array_one, int *array_two, int array_length)
{
    for(size_t i = 0; i < array_length; i++) //How to get the length of a array passed to a function?
    {
        if(array_one[i] != array_two[i])
        {
            return false;
        }
    }
    
    return true;
}

void generate()
{
    //Random Number Generator:
    int lower = 1;
    int upper = 1000000000;
    std::cout << "\nUpper Limit: " << upper;
    for (int i = 1; i <= data_length; i++)
    {
        int random_number = (rand() % (upper - lower + 1)) + lower;
        dataset[i] = random_number;
    }
}

int main() 
{
    /*
    int n;
    std::cin >> n;
    int data[n];
    for (int i = 0; i < n; ++i) 
    {
        std::cin >> data[i];
    }
    */
    int array_length   = data_length;
    int data_three_way[array_length];
    int data_two_way[array_length];
    int use_threeway_partition;
    generate();
    
    for (int i = 0; i < array_length; i++) 
    {
        data_three_way[i] = dataset[i];
        data_two_way[i]   = dataset[i];
    }
   
    randomized_quick_sort(data_three_way, 0, array_length - 1, use_threeway_partition = 1);
    randomized_quick_sort(data_two_way, 0, array_length - 1, use_threeway_partition = 0);

    std::cout << "\n\nComparision Result: " << compare_two_arrays(data_three_way, data_two_way, array_length);
    
    /*
    std::cout << "\n\nThree Way: \n";
    for (size_t i = 0; i < array_length; ++i) 
    {
        std::cout << dataset[i] << ' ';
    }

    std::cout << "\n\nTwo Way: \n";
    for (size_t i = 0; i < array_length; ++i) 
    {
        std::cout << dataset[i] << ' ';
    }
    */
    
    std::cout << "\n\n";
}
