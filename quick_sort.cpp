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

//Re-writing the procedure again. 
midpoints_struct partition_threeway(int *data, int left, int right, bool debug)
{
    int c1 = 0, region1[data_length]; //Less than Pivot
    int c2 = 0, region2[data_length]; //Equal to Pivot
    int c3 = 0, region3[data_length]; //Greater than Pivot
    int pivot = data[left];

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
    }
    
    int j = c1;
    for(int i = 0; i < c2; i++)
    {
        data[j] = region2[i];
        j++;
    }

    j = c1 + c2;
    for(int i = 0; i < c3; i++)
    {
        data[j] = region3[i];
        j++;
    }

    midpoints_struct midpoints;
    midpoints.midpoint_one = c1;
    midpoints.midpoint_two = c1 + c2;

    return midpoints;
}

midpoints_struct partition3(int *data, int left, int right, bool debug) 
{

    int pivot = data[left];
    int midpoint_one_var = left;
    int midpoint_two_var = left;

    for(int i = left + 1; i <= right; i++)
    {
        /*
        if(debug)
        {
            printf("\nComparing %i with %i: \n", data[i], pivot);
        }
        */
        if(data[i] < pivot)
        {
            /*
            if(debug)
            {
                printf("Less Than");
            }
            */
            midpoint_one_var++; 
            midpoint_two_var++;
            swap(data[i], data[midpoint_one_var]);
        }
        else if(data[i] > pivot)
        {
            /*
            if(debug)
            {
                printf("Greater Than");
            }
            */
            midpoint_two_var++;
            swap(data[i], data[midpoint_two_var]);
        }
        else if(data[i] == pivot)
        {
            /*
            if(debug)
            {
                printf("Equal To");
            }
            */
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

void randomized_quick_sort(int *data, int left, int right, int use_threeway_partition, bool debug) 
{
    if (left > right) 
    {
        return;
    }
    time_t t;
    srand((unsigned) time(&t));
    //We want to choose a random array item as a Pivot element, not just the first one. Reasons: https://stackoverflow.com/questions/41513856/can-someone-clarify-the-difference-between-quicksort-and-randomized-quicksort
    int random_index_of_array = left + rand() % (right - left + 1);
    int midpoint_one, midpoint_two;
    //printf("\n\nLeft: %i, Right: %i\n\n", random_index_of_array, right);
    swap(data[left], data[random_index_of_array]);

    /*
    std::cout << "\n\nAfter Randomization: \n\n";
    for(int i = 0; i < data_length; i++)
    {
        std::cout << data[i] << "\t";
    }
    */

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
        randomized_quick_sort(data, midpoint + 1, right, use_threeway_partition, debug);
    }
}

bool compare_two_arrays(int *array_one, int *array_two, int array_length)
{
    for(size_t i = 0; i < array_length; i++) //How to get the length of a array passed to a function?
    {
        if(array_one[i] != array_two[i])
        {
            //std::cout << i << "\t" << array_one[i] << "\t" << array_two[i] << "\n\n";
            return false;
        }
    }
    
    return true;
}

void generate()
{
    time_t t;
    srand((unsigned) time(&t)); //See TASKS.md Task #1
    //Random Number Generator:
    int lower = 1;
    int upper = 100000;
    //std::cout << "\nUpper Limit: " << upper;
    for (int i = 1; i <= data_length; i++)
    {
        int random_number = (rand() % (upper - lower + 1)) + lower;
        dataset[i] = random_number;
    }
}

bool check_if_sorted(int *input_array, int array_size)
{    
    for(int i = 0; i < array_size - 1 ; i++) 
    {
        //printf("\n Comparing: %i with %i", input_array[i], input_array[i+1]);
        if(input_array[i] > input_array[i+1])
        {
            printf("\n\n\nArray is not sorted at: %i \n", i);
            return false;
        }
    }
    printf("\nArray is sorted\n");
    return true;
}

int main(int argc, char * argv[]) 
{
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
        
        int data_three_way[array_length];
        //Generate a Test Data Set with Random Numbers:
        generate();
        
        //Assign the numbers to the 2 test arrays:
        for (int i = 0; i < array_length; i++) 
        {
            data_three_way[i] = dataset[i];
            data_two_way[i]   = dataset[i];
        }
        

        /*
        std::cout << "\n\nOriginal Array: \n";
        for(int i = 0; i < array_length; i++)
        {
            std::cout << data_three_way[i] << "\t";
        }
        */

        //Call Quick Sort using Three Way Partition: 
        //randomized_quick_sort(data_three_way, 0, array_length - 1, use_threeway_partition = 1, debug);

        //Call Quick Sort using Two Way Partition:
        //randomized_quick_sort(data_two_way, 0, array_length - 1, use_threeway_partition = 0, debug);

        //check_if_sorted(data_three_way, array_length);

        //Output the Comparision Result of Two Way v/s Three Way Partition. 
        //std::cout << "\n\nComparision Result: " << compare_two_arrays(data_three_way, data_two_way, array_length);

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
        for (size_t i = 0; i < n; ++i) 
        {
            std::cout << data[i] << ' ';
        }
    }
}