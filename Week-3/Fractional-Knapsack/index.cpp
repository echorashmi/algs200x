#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
using std::vector;

int partition_vector(vector <int> &values, vector <int> &weights, vector <double> &data, int left, int right)
{
    double pivot = data.operator[](left);
    int midpoint = left;

    for (int i = left + 1; i <= right; i++)
    {
        if (data.operator[](i) >= pivot)
        {
            midpoint++;
            swap(data.operator[](i), data.operator[](midpoint));
            swap(values.operator[](i), values.operator[](midpoint));
            swap(weights.operator[](i), weights.operator[](midpoint));
        }
    }
    swap(data.operator[](left), data.operator[](midpoint));
    swap(values.operator[](left), values.operator[](midpoint));
    swap(weights.operator[](left), weights.operator[](midpoint));
    return midpoint;
}

void sort_value_per_unit_vector(vector <int> &values, vector <int> &weights, vector <double> &value_per_unit_array, int left, int right)
{
    if(left > right)
        return;
    
    time_t t;
    srand((unsigned) time(&t));

    int random_index_of_array = left + rand() % (right - left + 1);

    swap(value_per_unit_array.operator[](left), value_per_unit_array.operator[](random_index_of_array));
    swap(values.operator[](left), values.operator[](random_index_of_array));
    swap(weights.operator[](left), weights.operator[](random_index_of_array));

    int midpoint = partition_vector(values, weights, value_per_unit_array, left, right);
    sort_value_per_unit_vector(values, weights, value_per_unit_array, left, midpoint - 1);
    sort_value_per_unit_vector(values, weights, value_per_unit_array, midpoint + 1, right);
}

double get_optimal_value(int knapsack_capacity, vector<int> &weights, vector<int> &values) 
{
    double total_value = 0.0;
    double total_weight = 0.0;
    //Step 1: Calculate value_per_unit_weight of each item.
    
    //1.a) Declare a Vector to be the same size as weights
    vector<double> values_per_unit(weights.size()); 
    
    //1.b) Calculate (as double) the vector values as value / weight 
    for (int i = 0; i < weights.size(); i++)
    {
        values_per_unit.operator[](i) = (double)values.operator[](i) 
                                            / (double)weights.operator[](i);
    } 

    //Step 2: Sort by decreasing value_per_unit
    //sort_vectors(values_per_unit, weights, values);
    sort_value_per_unit_vector(values, weights, values_per_unit, 0, weights.size()-1);
    
    /*
    std::cout << "\n\nStarting KnapSack Capacity: \t" << knapsack_capacity;
    std::cout << "\nStarting KnapSack Value: \t" << total_value << std::endl << std::endl;
    */

    for (int i = 0; i < weights.size(); i++)
    {
        //Compare the largest to the capacity:
        
        //If it's available weight is greater than or equal to capacity
        if(weights.operator[](i) == knapsack_capacity)
        {   
            //Return the capacity * value per unit weight, because the knapsack will be full at this point. 
            total_value += knapsack_capacity * values_per_unit.operator[](i);
            break;
        }
        else if(weights.operator[](i) > knapsack_capacity)
        {
            //TODO: Still a bug here, not sure what. 
            //Only take the required amount here. 
            total_weight += knapsack_capacity;
            total_value += values_per_unit.operator[](i) * knapsack_capacity;
            knapsack_capacity = 0;
            break;
        }
        //Else If it's available weight is less than capacity:
        else if(weights.operator[](i) < knapsack_capacity)
        {
            //Add it to the total weight and total value of the loot, keeping in mind the capacity of the loot. 
            total_weight += weights.operator[](i);
            knapsack_capacity = knapsack_capacity - weights.operator[](i);
            total_value += values_per_unit.operator[](i) * weights.operator[](i);
        }
        /*
        std::cout << "\nKnapSack Capacity: \t" << knapsack_capacity;
        std::cout << "\nKnapSack Value: \t" << total_value;
        */
    }

    /*
    std::cout << "\n\nEnding KnapSack Capacity: \t" << knapsack_capacity << std::endl;
    std::cout << "\nEnding KnapSack Value: \t" << total_value << std::endl << std::endl;
    */
    
    /*
    //Print Out the Vectors:
    std::cout << "Values Per Unit\tValues\t\tWeights\n";
    for (int i = 0; i < weights.size(); i++)
    {
        std::cout   << values_per_unit.operator[](i) 
                    << "\t-\t"
                    << values.operator[](i)
                    << "\t-\t"
                    << weights.operator[](i)
                    << "\n";
    }
    */
    

    return total_value;
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
    if(test == true)
    {
        number_of_spices = 10;
        knapsack_capacity = 10;
        
        #include "tests.cpp"
        //TestCase testcase;
        //testcase.generate(values, weights);
        
        int arr_values[] = {7, 5, 24, 22, 17, 17, 12, 11, 4, 2};
        int arr_weights[] = {1, 1, 5, 5, 4, 5, 4, 5, 5, 4};
        values.insert(values.end(), arr_values, arr_values+(sizeof(arr_values)/sizeof(arr_values[0])));
        weights.insert(weights.end(), arr_weights, arr_weights+(sizeof(arr_weights)/sizeof(arr_weights[0])));
        
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

    //std::cout << "\n\nOptimal Loot Size: \t" << optimal_value << std::endl;
    
    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    

    return 0;
}
