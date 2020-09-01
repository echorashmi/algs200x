# Uses python3
import sys
import math

def binary_search(data, start, end, needle):
    count = 0
    while(start < end):
        mid = math.floor(start + (end - start)/2)

        if(data[mid] == needle):
            count = count+1
            end = mid - 1
        else:
            start = mid + 1
    return count

def linear_search(a, x):
    for i in range(len(a)):
        if a[i] == x:
            return i
    return -1

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    print(data)
    n = data[0]
    m = data[n + 1]
    a = data[1 : n + 1]
    for x in data[n + 2:]:
        # replace with the call to binary_search when implemented
        print(binary_search(n, 0, len(n), x))
    
