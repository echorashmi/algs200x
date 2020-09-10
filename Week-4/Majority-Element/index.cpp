#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using std::vector;

int get_majority_element_from_inner_array(vector <int> &all_elements)
{
    return 0;
}

int get_majority_element(vector<int> &all_elements, int left, int right) 
{
    cout << "\nInput Array: ";
    for(int i = 0; i < all_elements.size(); i++)
    {
        cout << all_elements[i] << "\t";
    }
    cout << endl << "Left: " << left;
    cout << endl << "Right: " << right;
    if(left == right)
    {
        cout << "\n\n\nThe End\n\n\n";
        return -1;
    }
    if (left + 1 == right)
    {
        cout << "\n\n\nAnother End. Left: " << left << " and Element at Left is: " << all_elements[left];
        return all_elements[left];
    }
    
    vector <int>left_half(0);
    vector <int>right_half(0);
    int left_size = all_elements.size() / 2;
    int right_size = all_elements.size() - left_size;

    for (int i = 0; i < left_size; i++)
    {
        left_half.push_back(all_elements[i]);
    }

    for (int i = right_size; i < all_elements.size(); i++)
    {
        right_half.push_back(all_elements[i]);
    }

    
        //Recursive Calls:
    int left_majority = get_majority_element(left_half, 0, left_size);
    int right_majority = get_majority_element(right_half, 0, right_size);
    //cout << "\nLeft Majority: " << left_majority;
    //cout << "\nRight Majority: " << right_majority;
    

    cout << "\nLeft Half Array: ";
    for(int i = 0; i < left_half.size(); i++)
    {
        cout << left_half[i] << "\t";
    }
    cout << endl;

    cout << "\nRight Half Array: ";
    for(int i = 0; i < right_half.size(); i++)
    {
        cout << right_half[i] << "\t";
    }
    cout << endl;

    return 0;
}

int main(int argc, char *argv[])
{
    int count_of_elements;
    vector<int> all_elements(0);
    bool test = false;
    if(argc > 1)
    {
        test = true;
    }
    if(test)
    {
        int all_elements_array[] = {2, 3, 9, 2, 2, 2};
        all_elements.insert(    
                                all_elements.end(), 
                                all_elements_array,
                                all_elements_array + 
                                    sizeof(all_elements_array) / 
                                        sizeof(all_elements_array[0])  
                            );
    }
    else
    {
        std::cin >> count_of_elements;
        all_elements.resize(count_of_elements);
        for (size_t i = 0; i < all_elements.size(); i++) 
        {
            std::cin >> all_elements[i];
        }
    }
    
    
    int result = get_majority_element(all_elements, 0, all_elements.size());
    if(result == -1) //-1 Means there is no Majority Element Found
    {
        std::cout << 0 << '\n';
    }
    else //A Majority Element was Found
    {
        std::cout << 1 << '\n';
    }
}


/*
    Original Code from Starter File
*/
int get_majority_element_starter(vector<int> &all_elements, int left, int right)
{
    if (left == right) 
    {
        return -1;
    }
    if (left + 1 == right) 
    {
        return all_elements[left];
    }
    //Write your code here
    return -1;
}