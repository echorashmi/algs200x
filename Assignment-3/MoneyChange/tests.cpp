class TestCase{
    public:
    void small_data() 
    {
        assert(get_change(1) == 1);
        assert(get_change(2) == 2);
        assert(get_change(3) == 3);
        assert(get_change(4) == 4);
        assert(get_change(5) == 1);
        assert(get_change(6) == 2);
        assert(get_change(7) == 3);
        assert(get_change(8) == 4);
        assert(get_change(9) == 5);
        assert(get_change(10) == 1);
        assert(get_change(11) == 2);
        assert(get_change(12) == 3);
        assert(get_change(13) == 4);
    }

    void large_data()
    {
        int arr[] = {1000, 999, 945, 190, 555};

        for(int i = 0; i < 5; i++)
        {
            clock_t begin = clock();
            get_change(arr[i]);
            clock_t end = clock();
            double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("\nFor %i: %f seconds", arr[i], time_spent);
        }
        printf("\n");
    }

    void check_boundary()
    {
        int lower = 1;
        int upper = 1000;
        assert(get_change(lower) == 1);
        assert(get_change(upper) == 100);
    }

    void check_null()
    {
        //assert(get_change("a") == 0);
        assert(get_change(0) == 0);
        assert(get_change(-1) == 0);
        assert(get_change(10001) == 0);
        assert(get_change(-10) == 0);
    }
};
/*
DONE 1. Small Data Set
DONE 2. Large Data Set (Check how long it takes to process a large data set)
3. Use generate() to generate random numbers as inputs
DONE 4. Check boundary values to ensure program processes correctly with short numbers (Below 1) and long sequences (Above 1000)
DONE 5. Check output when input is 0.
DONE 6. Check output when input is 1000.
DONE 7. Check empty values

[D]: Stress Testing:
1. Implement another algorithm to check the 2 programs producing the same result
2. Generate Random Test Cases:
3. Generate Biased Test Cases:
    a. With only small numbers
    b. With only large numbers
    c. With both composite and prime integers
*/