#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_fibonacci_huge(long long n, long long m) {
    if (n <= 1)
        return n;

    long long mod = n%m;
    return mod;
}

int main() {
    long long n = 15, m = 3;
    //std::cin >> n >> m;
    std::cout << get_fibonacci_huge(n, m) << '\n';
}

//Algorithm:
//1. Find Fibonacci of m. 
//2. Get n%m (remainder of n divide by m)
//3. n%m will give you the new value of "n" to use for F(n)mod(m), and that's what will be the final answer?
