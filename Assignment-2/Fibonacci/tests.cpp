class TestCase{
    public:
    void test_solution() 
    {
        assert(fibonacci_fast(3) == 2);
        assert(fibonacci_fast(10) == 55);
        for (int n = 0; n < 20; ++n)
        {
            assert(fibonacci_fast(n) == fibonacci_naive(n));
        }
    }
};