#include <iostream>
#include <cassert>
#include <vector>
#include <math.h>

using std::vector;

int binary_search(int *data, int start, int end, int needle) 
{
  if(end >= start)
  {
    int middle = start + (end - start) / 2;

    if(data[middle] == needle)
      return middle;
    
    if(data[middle] > needle)
      return binary_search(data, start, middle - 1, needle);

    return binary_search(data, middle + 1, end, needle);
  }
  return -1;
}

int linear_search(int *a, int n, int x) 
{
  
  for (int i = 0; i < n; ++i) 
  {
      if (a[i] == x)
      {
        return i;
      }
  }
  return -1;
}

int main() 
{
  int n = 5;
  int a[] = {1, 2, 3, 4, 5};
  int m = 2;
  int b[] = {3, 4};
  int c[5];
 
  for (int i = 0; i < m; ++i) 
  {
    //std::cout << linear_search(a, n, b[i]) << '\n';
    std::cout << binary_search(a, 0, 4, b[i]) << '\n';
  }
}
