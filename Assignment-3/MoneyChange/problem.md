Minimum number of coins with denominations 1, 5, 10. 

Eg:
- Input: 28
- Output 6
    - How is Output Calculated? 10 x 2 Coins + 5 x 1 Coin + 1 x 3 Coins

Maximum Input: 1 <= m <= 1000
Time Limit: C++ - 1 Second
Memory Limit: 512 Mb

Steps:
[A]: Design The Algorithm:
DONE 1. Design an Algorithm
    f(m):
        int coins_10 = m/10;
        int rem_10 = m%10;

        int coins_5 = coins_10/5;
        int rem_5 = coins_5%5;

        int coins_1 = coins_5/1;

        return coins_10 + coins_5 + coins_1;
DONE 2. Prove that it is correct (Wut? How?)
    - Mathematically, Using Proof by Induction, or Proof by Contradiction.
    - I proved it using 2 hard numbers 1000 and 999.
    Shortened the code down to:
        f(m):
            int coins_10 = m/10;
            int rem_10 = m%10;
            if(rem_10 > 0):
                int coins_5 = coins_10/5;
                int rem_5 = coins_5%5;
            if(rem_5 > 0):
                int coins_1 = coins_5/1;
            return coins_10 + coins_5 + coins_1;
DONE 3. Try to estimate it's expected running time on the most complex inputs. 
    - Running time to me looks like O(1). But this I need to find out how to do properly. 


DONE [B]: Implement The Algorithm:
1. Run it using the Compiler Flags Provided: make -f MakeFile
- (This is Empirical Analysis - analysing correctness by Experimentation and Observation - what I typically call "Brute Force")

[C]: Testing & Debugging:
1. Small Data Set
    Failed. 
DONE 2. Large Data Set (Check how long it takes to process a large data set)
    For 1000: 0.000002 seconds
    For 999: 0.000000 seconds
    For 945: 0.000001 seconds
    For 190: 0.000001 seconds
    For 555: 0.000001 seconds
3. Use generate() to generate random numbers as inputs
4. Check boundary values to ensure program processes correctly with short numbers (Below 1) and long sequences (Above 1000)
5. Check output when input is 0.
6. Check output when input is 1000.
7. Check empty values

[D]: Stress Testing:
1. Implement another algorithm to check the 2 programs producing the same result
2. Generate Random Test Cases:
3. Generate Biased Test Cases:
a. With only small numbers
b. With only large numbers
c. With String Inputs
d. With both composite and Prime integers

[E]: Submit to Grader
DONE! It passed :) 