#include <iostream>

using namespace std;


const int arr[] = {1, 2, 3, 4};

int where_is(int needle);
int search_the_array_for(int needle);
int is_it_at_index_one(int needle);
int is_it_at_index_two(int needle);
int is_it_at_index_three(int needle);
int is_it_at_index_four(int needle);

int where_is(int needle)
{
    return search_the_array_for(needle);
}

int search_the_array_for(int needle)
{
    if(is_it_at_index_one(needle)) return 1;
    if(is_it_at_index_two(needle)) return 2;
    if(is_it_at_index_three(needle)) return 3;
    if(is_it_at_index_four(needle)) return 4;
    return 0;
}

int is_it_at_index_one(int needle)
{
    if(needle == 1) return 1;
    else return 0;
}

int is_it_at_index_two(int needle)
{
    if(needle == 1) return 2;
    else return 0;
}


int is_it_at_index_three(int needle)
{
    if(needle == 3) return 3;
    else return 0;
}

int is_it_at_index_four(int needle)
{
    if(needle == 4) return 4;
    else return 0;
}

int main(void)
{
    int element_index = where_is(3);
    cout << "\n\nElement Index: " << element_index << endl;
}