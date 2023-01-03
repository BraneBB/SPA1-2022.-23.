#include <iostream>
#include <vector>

using namespace std;

//sve isto za kxors samo esxclusive or staviti ili ^
vector<int> ksums (const vector<int> &A, int k)
{
    vector<int> sume;
    int suma = 0;
    for (int i = 0; i < k; ++i)
        suma += A[i];
    
    sume.push_back(suma);
    
    for (int i = k; i < A.size(); ++i)
    {
        suma += A[i] - A[i - k];
        sume.push_back(suma);
    }
    
    return sume;
}

int main()
{
    
}