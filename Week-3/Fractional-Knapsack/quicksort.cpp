/*
    Problem Definition:
    Given 3 arrays: values, weights and value_per_unit, sort each array based on array value_per_unit in descending order. 
*/

#include <iostream>

void sort_descending(int *values, int *weights, int *value_per_unit)
{
    
}

int main(void)
{
    int values[] = {14, 6, 23, 4, 15, 8, 12, 19, 18, 24};
    int weights[] = {2, 2, 1, 3, 1, 3, 5, 5, 3, 1};
    int value_per_unit[] = {7, 3, 23, 1, 15, 2, 2, 3, 6, 24};
    sort_descending(values, weights, value_per_unit);
}

