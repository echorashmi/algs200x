class TestCase{
    public:
    void check_small_data_set()
    {

    }

    void check_time_large_data_set()
    {  

    }

    void generate(vector<int> &values, vector<int> &weights)
    {
        int number_of_spices = 10;
        int stub_value;
        int stub_weight;
        srand(time(0));
        for (int i = 0; i < number_of_spices; i++) 
        {
            stub_value  = rand() % 25 + 1; // On a Scale from 1 to $20;
            stub_weight = rand() % 5 + 1; // On a Scale from 1 to 20 kgs;
            values.push_back(stub_value);
            weights.push_back(stub_weight);   
        }
    }

    void check_boundary()
    {

    }

    void check_zero()
    {

    }

    void check_long_sequences()
    {

    }

    void check_empty()
    {

    }

    //Stress Test:
    void compare_against_another_algorithm()
    {

    }
};


/*
[C]: Testing & Debugging:
DONE 1. Small Data Set
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

*/