#include <iostream>
#include <vector>

using namespace std;

int int_log10(int n)
{
    int cnt = 0;
    while(n >= 10)
    {
        n /= 10;
        cnt++;
    }

    return cnt;
}

int main()
{
    cout << int_log10(1000);
}