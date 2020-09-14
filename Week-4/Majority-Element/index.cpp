/*
TODO: Create a Call Tree for the Get Majority Element / Divide & Conquer Function, refer this video
https://www.youtube.com/watch?v=0nKIr3kAt-k
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using std::vector;

class MajorityElement{
    public:
    int count_of_elements;
    int left;
    int right;
    string env;
    vector<int> all_elements;
    vector<int> left_half;
    vector<int> right_half;

    void set_env(int argc)
    {
        if(argc > 1)
        {
            this->env = "test";
        }
        else
        {
            this->env = "live";
        }
    }

    void print_vector(string name)
    {
        cout << name;
        for(int i = 0; i < this->all_elements.size(); i++)
        {
            cout << this->all_elements[i] << "\t";
        }
        cout << endl << "Left: " << this->left;
        cout << endl << "Right: " << this->right;
    }

    void use_mock_data()
    {
        int all_elements_array[] = {2, 3, 9, 2, 2, 2};
        this->all_elements.insert(    
                                this->all_elements.end(), 
                                all_elements_array,
                                all_elements_array + 
                                    sizeof(all_elements_array) / 
                                        sizeof(all_elements_array[0])  
                                );
    }

    void use_live_data()
    {
        std::cin >> this->count_of_elements;
        this->all_elements.resize(this->count_of_elements);
        for (size_t i = 0; i < this->all_elements.size(); i++) 
        {
            std::cin >> this->all_elements[i];
        }
    }

    void partition()
    {
        //Create 2 partitions: 
        int left_size = this->all_elements.size() / 2;
        int right_size = this->all_elements.size() - left_size;

        for (int i = 0; i < left_size; i++)
        {
            this->left_half.push_back(this->all_elements[i]);
        }

        for (int i = right_size; i < this->all_elements.size(); i++)
        {
            this->right_half.push_back(this->all_elements[i]);
        }
    }

    void divide_and_conquer()
    {   
        //Recursive Calls:
        //int left_majority = get_majority_element(left_half, 0, left_size);
        //int right_majority = get_majority_element(right_half, 0, right_size);
        //cout << "\nLeft Majority: " << left_majority;
        //cout << "\nRight Majority: " << right_majority;
        this->partition();
        this->print_vector("Left Half Array");
        this->print_vector("Right Half Array");
    }

    int get_majority_element() 
    {
        if(this->left == this->right)
        {
            return -1;
        }
        if (this->left + 1 == this->right)
        {
            return this->all_elements[this->left];
        }
        this->divide_and_conquer();
        return 0;
    }
};

int main(int argc, char *argv[])
{
    MajorityElement meobject;
    meobject.set_env(argc);  //Sets Environment to Test or Live
    meobject.use_mock_data();   //Create the first mock data set
    meobject.print_vector("\nInput Array: "); //Print out the inputs to the function

    int result = meobject.get_majority_element();

    if(result == -1) //-1 Means there is no Majority Element Found
    {
        std::cout << 0 << '\n';
    }
    else //A Majority Element was Found
    {
        std::cout << 1 << '\n';
    }
}