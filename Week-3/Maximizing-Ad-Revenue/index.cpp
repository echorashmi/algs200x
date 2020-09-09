#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
using std::vector;

int partition_vector(vector <int> &data, int left, int right)
{
    int pivot = data.operator[](left);
    int midpoint = left;

    
    for (int i = left + 1; i <= right; i++)
    {
        //cout << "Comparing: " << data.operator[](i) << " with: " << pivot << endl;
        if(data.operator[](i) >= pivot)
        {
            midpoint++;
            swap(data.operator[](i), data.operator[](midpoint));
        }
    }
    swap(data.operator[](left), data.operator[](midpoint));
    return midpoint;
}

int sort_vector(vector <int> &data, int left, int right)
{
    if(left > right)
        return 0;

    time_t t;
    srand((unsigned) time(&t));

    int random_index_of_array = left + rand() % (right - left + 1);
    swap(data.operator[](left), data.operator[](random_index_of_array));

    int midpoint = partition_vector(data, left, right);
    sort_vector(data, left, midpoint - 1);
    sort_vector(data, midpoint + 1, right);

    return 1;
}

long long max_dot_product(vector<int> &profit_per_click, vector<int> &clicks_per_day) {
    long long result = 0;

    sort_vector(profit_per_click, 0, profit_per_click.size() - 1);
    sort_vector(clicks_per_day, 0, clicks_per_day.size() - 1);

    for (size_t i = 0; i < profit_per_click.size(); i++) 
    {
        result += ((long long) profit_per_click[i]) * clicks_per_day[i];
    }
    return result;
}

int main(int argc, char *argv[]) 
{
    size_t n;
    vector<int> profit_per_click(0), clicks_per_day(0);
    bool test = false;
    if(argc > 1)
    {
        test = true;
        int profit_per_click_array[] = {1, 3, -5};
        int clicks_per_day_array[]   = {-2, 4, 1};
        profit_per_click.insert(profit_per_click.end(), profit_per_click_array, profit_per_click_array+(sizeof(profit_per_click_array) / sizeof(profit_per_click_array[0])));
        clicks_per_day.insert(clicks_per_day.end(), clicks_per_day_array, clicks_per_day_array+(sizeof(clicks_per_day_array) / sizeof(clicks_per_day_array[0])));
    }
    else 
    {
        std::cin >> n;
        profit_per_click.resize(n);
        clicks_per_day.resize(n);
        for (size_t i = 0; i < n; i++) 
        {
            std::cin >> profit_per_click[i];
        }
        for (size_t i = 0; i < n; i++) 
        {
            std::cin >> clicks_per_day[i];
        }
    }
    std::cout << max_dot_product(profit_per_click, clicks_per_day) << std::endl;
}
