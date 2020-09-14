#include <iostream>

using namespace std;

/*
This implementation is from here:
https://www.geeksforgeeks.org/recursive-c-program-linearly-search-element-given-array/
*/

int linear_search_recursive(int *haystack, int left, int right, int needle)
{
    if (right < left)
        return -1; //Not Found 
    if (haystack[left] == needle)
        return left;
    if (haystack[right] == needle)
        return right;
    return linear_search_recursive(haystack, left + 1, right - 1, needle);
}

int linear_search_recursive_only_left(int *haystack, int left, int needle, int array_length)
{
    //Base Case: #1, with a Stopping Criterion
    if(array_length < 1)
        return -1;
    
    //Base Case #2:
    if (haystack[left] == needle)
        return left;
    
    //Recursive Case Breaking down the input into smaller chunks in such a way that the stopping criterion must be reached
    return linear_search_recursive_only_left(haystack, left + 1, needle, array_length - 1);
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    int left = 0;
    int right = 4;
    int needle = 4;
    int array_length = 5;

    //With Left and Right:
    int element_index = linear_search_recursive(arr, left, right, needle);
    cout << "\n\nElement Index: (Implementation 1)" << element_index << endl;

    //Only Left:
    element_index = linear_search_recursive_only_left(arr, left, needle, array_length - 1);
    cout << "\n\nElement Index: (Implementation 2)" << element_index << endl;
}