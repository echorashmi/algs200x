#include <iostream>

int gcd_euclid(int a, int b){
    if(b == 0){
        return a;
    }
    int ap = a%b;
    return gcd_euclid(b, ap);
}

//Brute Force Method:
long long lcm_naive(int a, int b) {
    for (long l = 1; l <= (long long) a * b; ++l)
        if (l % a == 0 && l % b == 0)
        return l;

    return (long long) a * b;
}

int lcm_explanation(int a, int b){
    int lcm;

    for (lcm = 1; lcm < a*b; lcm++){ //Start at 1 and multiply all the way up to a*b
        if(lcm % a == 0 && lcm % b == 0){ //Find a common divisor
            return lcm; //Return the lowest divisor possible
        }
    }

    return a*b; //If no divisor is found, return the multiplication of a*b
}

//Prime Factorization Method:
long long lcm_algo(long long a, long long b){
    return (a * b) / gcd_euclid(a, b);
}

int main() {
  long long a = 28851538, b = 1183019;
  //std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_algo(a, b) << std::endl;
  return 0;
}
