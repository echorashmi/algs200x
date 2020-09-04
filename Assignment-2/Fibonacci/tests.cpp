/*
    File to call test.cpp. 
*/
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <cassert>
#include <iostream>
#include "fibonacci.cpp"

int main(void)
{
    int n = 10;
    //std::cout << "Naive: " << fibonacci_naive(n) << '\n';
    //test_solution();
    std::cout << "Fast(" << n << "): " << fibonacci_fast(n) << '\n';
    return 0;
}