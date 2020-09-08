#include <iostream>

void get_subgroup(int left, int right)
{
    
}

void create_groups(int *kids, int count)
{
    int segments[10]; //Need another data structure for this, not an array. Possibly a list? 
    int left = 1;

    while(left <= count)
    {
        get_subgroup(left, left+2); //current age + 2 age groups up.  
    }

    for(int i = 0; i < count; i++)
    {
        
    }
}

int main(void)
{
    int kids[] = {2, 3, 3, 4, 4, 5, 5, 7, 7, 8, 8, 10, 11, 11, 12, 12, 13, 15, 15, 16};
    create_groups(kids, 20);
}