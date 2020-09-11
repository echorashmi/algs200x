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

int main(void)
{
    //Sorted Input Array:
    int arr[] = {1, 2, 2, 3, 4, 4, 6, 7, 8, 9, 10, 12, 13, 15};
    int element_index = linear_search(arr, 10, 14);
    cout << element_index << endl;
}