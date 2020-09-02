#include <iostream>
#include <cstdlib>

using std::swap;

typedef struct midpoints_struct{
    int midpoint_one; 
    int midpoint_two;
}midpoints_struct;

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

    for(int i = left + 1; i <= right; i++)
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

void randomized_quick_sort(int *data, int left, int right) {
    if (left >= right) 
    {
        return;
    }
    int random_index_of_array = left + rand() % (right - left + 1);
    int midpoint_one, midpoint_two;
    
    swap(data[left], data[random_index_of_array]);

    /*
        Three Way Partition:
    */
    midpoints_struct midpoints = partition3(data, left, right);
    randomized_quick_sort(data, left, midpoints.midpoint_one - 1);
    randomized_quick_sort(data, midpoints.midpoint_two + 1, right);
}


int main() {
    int n;
    std::cin >> n;

    int data[n];

    for (int i = 0; i < n; ++i) 
    {
        std::cin >> data[i];
    }
    randomized_quick_sort(data, 0, n - 1);
    for (int i = 0; i < n; ++i) 
    {
        std::cout << data[i] << ' ';
    }
}
