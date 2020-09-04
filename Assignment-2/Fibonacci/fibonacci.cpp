#include <iostream>
#include <cassert>
#include <stdio.h>

int fibonacci_naive(int n)  
{
    if (n <= 1)
        return n;
    printf("%i\n", n);
    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) 
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    int fibonacci_value = 1;
    int fibonacci_array[n];
    fibonacci_array[0] = 0;
    fibonacci_array[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        fibonacci_array[i] = fibonacci_array[i-1] + fibonacci_array[i-2];
    }

    return fibonacci_array[n];
}

void test_solution() 
{
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
    {
        assert(fibonacci_fast(n) == fibonacci_naive(n));
    }
}

int main(int argc, char *argv[]) 
{
    if(argc > 1)
    {
        main_test();
    }
    else
    {
        int n = 0;
        std::cin >> n;
        //std::cout << "Naive: " << fibonacci_naive(n) << '\n';
        //test_solution();
        std::cout << "Fast(" << n << "): " << fibonacci_fast(n) << '\n';
        return 0;
    }
}