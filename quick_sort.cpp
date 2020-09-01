#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(int *a, int l, int r) 
{
    int x = a[l];
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] <= x) {
        j++;
        swap(a[i], a[j]);
        }
    }
    swap(a[l], a[j]);
    return j;
}

int partition3(int *a, int l, int r) 
{
    int x = a[l];
    int j = l;
    
    for (int i = l + 1; i <= r; i++) 
    {
        if (a[i] <= x) {
        j++;
        swap(a[i], a[j]);
        }
    }
    swap(a[l], a[j]);
    return j;
}

void randomized_quick_sort(int *a, int l, int r) {
    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    int m = partition2(a, l, r);

    //Left:
    randomized_quick_sort(a, l, m - 1);
    //Add a Middle one here:

    //Right:
    randomized_quick_sort(a, m + 1, r);
}

int main() {
    int n;
    std::cin >> n;

    int a[n];

    for (int i = 0; i < n; ++i) 
    {
        std::cin >> a[i];
    }

    randomized_quick_sort(a, 0, n - 1);

    for (int i = 0; i < n; ++i) 
    {
        std::cout << a[i] << ' ';
    }
}
