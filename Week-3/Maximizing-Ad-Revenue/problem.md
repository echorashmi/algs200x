Problem Definition:

You have N ads to place on a populat internet page. For each ad, you know how much the advertiser is willing to pay for one click on this ad. You have set up N slots on the page, and estimated the expected number of clicks per day for each slot. Your goal is to distribute the ads among the slots to maximize the total ad revenue. 

Given 2 sequences:
a1, a2, a3 . . . an - where ai is the profit per click of the i'th ad.
b1, b2, b3 . . . bn - where bi is the average number of clicks per day of the i'th slot.
We need to partition them into n pairs (ai, bj) such that the sum of their products is maximized. 

Input:
n 
a1 a2 a3
b1 b2 b3

Examples:
[1]:
3
1 3 -5
-2 4 1
Output:23
(23 = 3x4 + 1x-5 + 1x-2)

[2]:
1
23
39
Output:
897
(23x39)

Constraints:
1 <= n <= 1000
-10^5 <= a, b <= 10^5
For all 1 <= i <= n


Steps:
[A]: Design The Algorithm:
1. Design an Algorithm
    I have 2 approaches of doing this:
    Approach 1:
        1. Sort both input arrays in descending order
        2. Multiply a1 with b1, a2 with b2, . . . an with bn
        3. Add up sums of all the multipled pairs
        (My hesistation here is that it's a greedy choice and I'm not sure if this greedy choice is the safe / optimal choice or not) 
    Approach 2:
        1. Multiply every element in a with every element in b
        2. Sort the product in descending order
        3. For each element in array from top to bottom,
            a. Select top 1 to go on the Chosen Ad Stack
            b. Compare top 1's constituents to second top
                If there is overlap, discard second top
                If there is no overlap, add it to the Chosen Ad Stack
            c. Repeat a, b, moving elements to either Chosen Ad Stack or discarding elements as they appear in the iteration
        (My hesistation here is that this is more complex than the first approach, so if the first approach works, why do a second one?)
        Let's try and explore how I can proove if it's a safe choice or not. 
NOT DOING 2. Prove that it is correct (By using Proof by Induction or Proof by Contradiction).
    I don't quiet get the hang of this. Not sure how to proove this algorithm. 
    Steps for Proving:
    a. Prove Base Case (Using a Loop Invariant)
    b. Prove Inductive Case (Using the same Loop Invariant)
    c. Prove eventual termination
    d. Prove corectness (that the answer is the answer we expect)
    So, correction. I don't have to do those above steps. Since I am solving this using a Greedy Algorithm, I have to do the following:
        - Make a greedy choice 
        - Prove that the choice I made is a safe choice
        - Identify a subproblem
        - Solve the subproblem
        - Estimate the running time
NOT DOING 3. Try to estimate it's expected running time on the most complex inputs. 
    
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