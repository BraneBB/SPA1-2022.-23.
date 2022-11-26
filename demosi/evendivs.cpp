#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int even_divs(int n)
{
    return n - floor(sqrt(n));
}

int main()
{
    cout << even_divs(26);
}