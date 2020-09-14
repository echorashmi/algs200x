#include <iostream>
using namespace std;

int recursive_get_factorial(int num)
{
    //Base Case:
    if(num == 1)
    {
        return 1;
    }
    //Incremental Operation involving previous returned value:
    int factorial = num * recursive_get_factorial(num - 1);
    return factorial;
}

int main(void)
{
    int num = 3;
    int factorial = recursive_get_factorial(num);
    cout << factorial << endl;
}