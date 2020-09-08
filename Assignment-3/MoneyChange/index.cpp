#include <iostream>

int get_no_of_coins(int *money, int denomination)
{
    int no_of_coins = 0;
    no_of_coins = *money / denomination;
    *money = *money % denomination;
    return no_of_coins;
}

int get_change(int money)
{
    int coins_10 = get_no_of_coins(&money, 10);
    int coins_5  = get_no_of_coins(&money, 5);
    int coins_1  = get_no_of_coins(&money, 1);
    int no_of_coins = coins_10 + coins_1 + coins_5;

    return no_of_coins; 
}

int main(int argv, char * argc[]) 
{
    bool test = false;
    if(argv > 1) 
    {
        bool test = true;
        #include "tests.cpp"
        TestCase testcase;
        testcase.small_data();
        testcase.large_data();
        testcase.check_boundary();
        testcase.check_null();
    }
    else
    {
        int m;
        int error;
        try{
            std::cin >> m;
            if(m < 0){
                throw error;
            }
        }
        catch(int error){
            std::cout << "Please Enter Positive Integer!";
            main(argv, argc);
        }
        std::cout << get_change(m) << '\n';
    }
}