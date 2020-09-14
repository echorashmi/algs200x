#include <iostream>

using namespace std;
int recursive_sum_of_array(int *arr, int length)
{
    //Base Case
    if(length == 1)
    {
        return arr[length - 1];
    }

    int sum = arr[length - 1] 
                + recursive_sum_of_array(arr, length - 1);
    return sum;
}

int main(void)
{
    int arr[] = {1, 2, 3, 4};
    int length = 4;
    int sum = recursive_sum_of_array(arr, length);
    cout << "Sum: " << sum << endl;
}