Goal: Check whether an input sequence contains a majority element. 
Input:  n (Number of Elements)
        a1 a2 a3 ... an
Output: 1 - if the sequence contains an element that appears [strictly more] than n/2 times.
        0 - otherwise

Constraints:
1 <= n <= 10^5
0 <= ai <= 10^9
for all 0 <= i < n
Time - Less than 1 second
Memory - Less than 512 MB

Examples:
[1]
5
2 3 9 2 2
Output:
1

[2]
4
1 2 3 4
Output:
0

[3]
4
1 2 3 1
Output:
0 (50% is not a majority)

Steps:
[A]: Design The Algorithm:
1. Design an Algorithm
1. a. Understand Starter Code. 
1. b. Understand Pseudo Code Algorithm #1 (Provided in the Question Bank):
    This has a Quadratic Run Time i.e. O(n^2), the performance is directly proportional to the squared size of the input data.  
    MajorityElement(a1, a2, ... an): 
        for i from 1 to n:
            currentElement = ai
            count = 0
            for j from 1 to n:
                if aj == currentElement:
                    count++
            if(count > n/2):
                return ai
        return "No Majority Element"
1. c. Design an Algorithm that uses Divide and Conquer Technique to design an O(nlogn) Algorithm. 
    i. Split array into 2 halves
    ii. Get number and max_count from first array
    iii. Get number and max_count from second array
    iv. Compare both numbers
        If both the number are same, sum up max count
            If max count is > n/2, return true (There is a Majority Element)
            else return false
1. d. Define a collection of test inputs.


2. Prove that it is correct (By using Proof by Induction or Proof by Contradiction).
3. Try to estimate it's expected running time on the most complex inputs. 
    
[B]: Implement The Algorithm:
1. In main() take an argument argv to check that this is my internal test case or live case that the grader is expecting
2. Run it using the Compiler Flags Provided: make -f MakeFile
- (This is Empirical Analysis - analysing correctness by Experimentation and Observation - what I typically call "Brute Force")

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