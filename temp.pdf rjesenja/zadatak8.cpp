#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// zasto je ovo rjesenje zadatka ispravno
// ovaj problem se javlja u numerickoj matematici
// moze se pokazati da je najbolji odabir broja x bas medijan niza brojeva
// kada bi se svaki ovaj u apsolutnoj vrijednosti kvadrirao onda bi 
// rjesenje zadatka bila aritmeticka sredina
int min_abss(const vector<int> &A)
{
    sort(A.begin(), A.end());

    if(A.size() % 2 == 1)
        return A[(A.size() / 2) + 1];
    else
    {
        int med = (A.size() / 2);
        int sum1 = 0;
        int sum2 = 0;

        for (int i = 0; i < A.size(); ++i)
        {
            sum1 += abs(A[i] - A[med]);
        }

        for (int i = 0; i < A.size(); ++i)
        {
            sum2 += abs(A[i] - A[med + 1]);
        }

        return min(sum1, sum2);        
    }
}

int main()
{
    
}