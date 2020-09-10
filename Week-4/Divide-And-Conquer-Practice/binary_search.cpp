/*
    Bug: In the binary_search function, there is a bug. It's because I am resetting half_size each iteration, when what is expected is to find a way to retain the index so I can pass it back to the main function.
    I've temporarily worked around this by just printing "Found" from the binary_search function but woboy I gotsta work on that.

    Also, it doesn't work for the boundary condition where I have to find the number "15" (which is the 14th number of the array). 
*/

#include <iostream>

using namespace std;

int linear_search(int *haystack, int needle, int haystack_length)
{
    //Linear Search:
    for (int i = 0; i < haystack_length; i++)
    {
        if(needle == haystack[i])
        {
            cout << "Found it at: ";
            return i;
        }
    }
    return 0;
}

int binary_search(int *haystack, int needle, int haystack_length)
{
    int half_size = haystack_length / 2;
    //Compare haystack[half_size] with needle
    if(haystack[half_size] == needle) //Problem is that halfsize is being reset each iteration, it needs to persist. 
    {
        cout << "Found it! Unable to print location right now.";
        return half_size;
    }
    else if (haystack[half_size] > needle)
    {
        //recurse leftwards 
        binary_search(haystack, needle, half_size);
    }
    else
    {
        int *second_array = haystack + half_size;
        //recurse rightwards
        binary_search(second_array, needle, half_size);
    }
    return 0;
}

int main(void)
{
    //Sorted Input Array:
    int arr[] = {1, 2, 2, 3, 4, 4, 6, 7, 8, 9, 10, 12, 13, 15};
    //int element_index = linear_search(arr, 10, 14);
    int element_index = binary_search(arr, 15, 14);
    cout << element_index << endl;
}