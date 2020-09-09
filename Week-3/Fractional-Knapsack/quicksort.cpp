/*
    Problem Definition:
    Given 3 vectors: values, weights and value_per_unit, sort each array based on array value_per_unit in descending order. 
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int partition_vector(vector <int> &values, vector <int> &weights, vector <int> &data, int left, int right)
{
    int pivot = data.operator[](left);
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

void sort_value_per_unit_vector(vector <int> &values, vector <int> &weights, vector <int> &value_per_unit_array, int left, int right)
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

void sort_descending_vector(vector <int> &values, vector <int>  &weights, vector <int> &value_per_unit, int array_length)
{
    cout << "\nBefore Sorting: \n\n";
    for (int i = 0; i < array_length; i++)
    {
        cout << value_per_unit.operator[](i) << "\t-\t" << weights.operator[](i) << "\t-\t" << values.operator[](i) << "\n";
    }
    
    sort_value_per_unit_vector(values, weights, value_per_unit, 0, array_length-1);

    cout << "\nAfter Sorting: \n\n";
    for (int i = 0; i < array_length; i++)
    {
        cout << value_per_unit.operator[](i) << "\t-\t" << weights.operator[](i) << "\t-\t" << values.operator[](i) << "\n";
    }
}

int main(void)
{
    int array_length = 10;
    int values[] = {14, 6, 23, 4, 15, 8, 12, 19, 18, 24};
    int weights[] = {2, 2, 1, 3, 1, 3, 5, 5, 3, 1};
    int value_per_unit[] = {7, 3, 23, 1, 15, 2, 2, 3, 6, 24};
    
    std::vector <int> values_vector(0);
    std::vector <int> weights_vector(0);
    std::vector <int> value_per_unit_vector(0);

    values_vector.insert(values_vector.end(), 
                            values, 
                            values + 
                                (sizeof(values) 
                                    / sizeof(values[0])));
    
    
    weights_vector.insert(weights_vector.end(), 
                            weights, 
                            weights + 
                                (sizeof(weights) 
                                    / sizeof(weights[0])));
    
    value_per_unit_vector.insert(value_per_unit_vector.end(), 
                            value_per_unit, 
                            value_per_unit + 
                                (sizeof(value_per_unit) 
                                    / sizeof(value_per_unit[0])));
    
    sort_descending_vector(values_vector, weights_vector, value_per_unit_vector, array_length);
}

