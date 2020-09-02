#include <iostream>
#include <stdio.h>

void swap(int *num_one, int *num_two)
{
    int tmp = *num_one;
    *num_one = *num_two;
    *num_two = tmp;
}

void swap_array_digits(int *arr)
{
    int tmp = arr[0];
    arr[0] = arr[1];
    arr[1] = tmp;
}

int main(void)
{
    //Swapping Ints inside an Array:
    int a[] = {2, 5};
    printf("a[0]: %i and a[1]: %i\n", a[0], a[1]);
    swap_array_digits(a);
    printf("a[0]: %i and a[1]: %i\n", a[0], a[1]);
    
    /*
    //Swapping Ints
    int a = 2, b = 5;
    printf("a: %i and b: %i\n", a, b);
    swap(&a, &b);
    printf("a: %i and b: %i\n", a, b);
    */
}