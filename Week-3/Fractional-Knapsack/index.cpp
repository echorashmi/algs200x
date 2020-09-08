/*
    Pending:
    1. Write the sort_vectors function to sort all vectors simultaneously. 
*/

#include <iostream>
#include <vector>

using std::vector;

//TODO: Sort Function of Vector Items. All 3 Vectors need to be sorted simultaneously to preserve the integrity of the calculation. 
void sort_vectors(vector<int> values_per_unit, vector <int> weights, vector <int> values)
{
    values_per_unit.operator[](1) = 100;
}

double get_optimal_value(int knapsack_capacity, vector<int> weights, vector<int> values) 
{
    double value = 10.0;
    //Step 1: Calculate value_per_unit_weight of each item.
    
    //1.a) Declare a Vector to be the same size as weights
    vector<int> values_per_unit(weights.size()); 
    
    //1.b) Calculate the vector values as value / weight 
    for (int i = 0; i < weights.size(); i++)
    {
        values_per_unit.operator[](i) = values.operator[](i) / weights.operator[](i);
    } 

    //Step 2: Sort by decreasing value_per_unit
    sort_vectors(&values_per_unit, weights, values);

    //1.b) Calculate the vector values as value / weight 
    for (int i = 0; i < weights.size(); i++)
    {
        std::cout << values_per_unit.operator[](i) << std::endl;
    }

    return value;
}

int main(int argc, char * argv[]) 
{
    int number_of_spices;
    int knapsack_capacity;
    vector<int> values;
    vector<int> weights;

    bool test = false;
    if(argc > 1)
    {
        test = true;
    }
    if(test == true) //Use Hard Coded Stub Values while I am working 
    {
        number_of_spices = 10;
        knapsack_capacity = 50;
        
        int stub_value;
        int stub_weight;

        time_t t;
        srand(t);
         
        for (int i = 0; i < number_of_spices; i++) 
        {
            stub_value  = rand() % (10 - 1 + 1) + 1; // On a Scale from 1 to 10 $;
            stub_weight = rand() % (10 - 1 + 1) + 1; // On a Scale from 1 to 10 kgs;
            values.push_back(stub_value);
            weights.push_back(stub_weight);   
        }
    }
    else //Else use User-Input Values for Live Testing with User Inputs
    {
        std::cin >> number_of_spices >> knapsack_capacity;
        
        values.resize(number_of_spices);
        weights.resize(number_of_spices);

        for (int i = 0; i < number_of_spices; i++) 
        {
            std::cin >> values[i] >> weights[i];
        }
    }

    double optimal_value = get_optimal_value(knapsack_capacity, weights, values);
    
    //std::cout.precision(10);
    //std::cout << optimal_value << std::endl;
    

    return 0;
}
