#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int all_elements[5];
    //vector <int> all_elements(5);
    for (int i = 0; i < 5; i++) 
    {
        cin >> all_elements[i];
    }

    cout << "\n\nAwesome! You just typed in: \n";
    for (int i = 0; i < 5; i++) 
    {
        cout << all_elements[i] << "\t";
    }
    cout << endl << endl;
}