#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//iz zadatka 7
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

// koristimo int_sqrt jer trebamo odraditi sve u log vremenu
// zasto je ovo rjesenje ispravno jedini brojevi koji imaju neparan broj djelitelja su
// kvadrati brojeva odnosno 1, 4, 9, 16, .. sa int_sqrt racunamo koliko takvih brojeva od 1 do n 
// onda samo oduzmemo od n da dobijemo broj brojeva koji imaju paran broj djelitelja
// matematika ukratko
int even_divs(int n)
{
    return n - int_sqrt(n);
}

int main()
{
    //1 do 26 ima 5 kvadrata 1 4 9 16 25 ostaje nam 21 broj
    cout << even_divs(26);
}