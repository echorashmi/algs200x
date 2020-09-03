#include <iostream>
#include <stdio.h>
#include <math.h>

void print_reverse(int *, int);

class MyClass{
    public:
    void helloWorld()
    {
        printf("Hello World!");
    }
};

int main(void)
{
    MyClass myclass;
    myclass.helloWorld();
    /*
    const int n = 5;
    int arr[n] = {1, 2, 3, 4, 5};

    //1. Write a Program to Print a Reverse of an Array:
    print_reverse(arr, n);
    */
}

void print_reverse(int *arr, int n)
{
    //Practicing Swapping Digits:
    for(int i = 0, j = n-1; i < floor(n/2); i++, j--)
    {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
    
    for(int i = 0; i < n; i++)
    {
        printf("arr[%i]: %i\n", i, arr[i]);
    }
}