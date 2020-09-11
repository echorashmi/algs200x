#include <iostream>

using namespace std;

int linear_search_recursive(int *haystack, int needle, int index, int haystack_length)
{
    /*
    cout << "\n-----Start-------\n";
    cout << "Iteration Starting: \n";
    cout << "Haystack:\t";
    for (int i = 0; i < haystack_length; i++)
    {
        cout << haystack[i] << "\t";
    }
    cout << "\nNeedle: \t" << needle;
    cout << "\nIndex: \t" << index;
    cout << "\nHaystack Length: \t" << haystack_length;
    cout << "\n-------End--------\n";
    */

    if(index == haystack_length - 1)
    //Base Case (when not found)
    {
        return -1;
    }
    //Base Case (when found)
    if (haystack[index] == needle)
    {
        return index;
    }
    
    index++;
    int result = linear_search_recursive(haystack, needle, index, haystack_length);
    cout << "\n\nResult: " << result;
    return result;
}

int main(void)
{
    //Sorted Input Array:
    //int arr[] = {1, 2, 2, 3, 4, 4, 6, 7, 8, 9, 10, 12, 13, 15};
    int arr[] = {1, 2, 3, 4, 5};
    int index = 0;
    int element_index = linear_search_recursive(arr, 5, index, 5);
    cout << "\n\nFinal Response in Main: " << element_index << endl;
}