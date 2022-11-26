#include <iostream>
#include <vector>

using namespace std;

int int_sqrt(int n)
{
    int low, high, mid;
    low = 1;
    high = n;
    while(low <= high)
    {
        mid = (low + high) / 2;
        
        if (mid * mid == n)
            return mid;
        else if (mid * mid > n)
            high = mid - 1;
        else 
            low = mid + 1;
    }

    return high;
}

int main()
{
    cout << int_sqrt(100);
}