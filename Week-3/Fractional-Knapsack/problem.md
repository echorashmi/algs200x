Implement an algorithm for the fractional knapsack problem. 

Expected Output: Output the maximal value of fractions of items that fit into the knapsack. 

Examples:
[1]
Inputs:
3 50 (Number of Items, Capacity W)
60 20 (Value, Weight)
100 50
120 30

Output: 
180.0000

[2]
Inputs:
1 10
500 30

Output:
166.6667
(1/3rd of the only available item)

Constraints:
1 <= Number of Items n <= 10^3
0 <= Capacity W <= 2x10^6
0 <= Value <= 2x10^6
0 <= Weight Available <= 2x10^6
for all 1<= i <= n
With all numbers being integers.
Time Limit: C++ - 1 Second
Memory Limit: 512 Mb

Steps:
[A]: Design The Algorithm:
DONE 1. Design an Algorithm
    High Level Algorithm:
        DONE a. Calculate value per unit weight of all items
        b. Sort by value per unit weight in decreasing order - TODO
        c. Compare highest value item to capacity. 
            i. If it's available weight is greater than or equal to capacity: 
                Return the capacity * value per unit weight
            ii. If it's available weight is less than capacity:
                Add it to the total weight and total value of the loot. 
                Iterate (c) until condition (i) has been met and the loot is complete.
NOT DOING 2. Prove that it is correct (By using Proof by Induction or Proof by Contradiction).
    I don't quiet get the hang of this. Not sure how to proove this algorithm. 
    Steps for Proving:
    a. Prove Base Case (Using a Loop Invariant)
    b. Prove Inductive Case (Using the same Loop Invariant)
    c. Prove eventual termination
    d. Prove corectness (that the answer is the answer we expect)
    So, correction. I don't have to do those above steps. Since I am solving this using a Greedy Algorithm, I have to do the following:
        - Make a greedy choice (Using the largest number first)
        - Prove that the choice I made is a safe choice
        - Identify a subproblem
        - Solve the subproblem
        - Estimate the running time
NOT DOING 3. Try to estimate it's expected running time on the most complex inputs. 
    O(nlogn) based on what I remember from the video lecture. Not quiet sure how we get this, so I have to figure that out. 

[B]: Implement The Algorithm:
1. In main() take an argument argv to check that this is my internal test case or live case that the grader is expecting
2. Run it using the Compiler Flags Provided: make -f MakeFile
- (This is Empirical Analysis - analysing correctness by Experimentation and Observation - what I typically call "Brute Force")
3. Write the Sort Function

[C]: Testing & Debugging:
1. Small Data Set
2. Large Data Set (Check how long it takes to process a large data set)
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
1. Prepare the file for submission - Take inputs in expected format, and outputs in expected format. 