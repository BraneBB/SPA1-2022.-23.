#include <iostream>
#include <vector>

using namespace std;

vector<int> bubble_sort(vector<int> &A)
{
    for (int i = 0; i < A.size() - 1; ++i)
    {
        for (int j = 0; j < A.size() - i; ++j)
        {
            if(A[j] > A[j + 1])
                swap(A[j], A[j + 1]);
        }
    }

    return A;
}

int main()
{
    vector<int> test = {0, 9, 2, 1, 2, 3, 4, 5, 6, 7, 9, 0};

    test = bubble_sort(test);

    for (auto &el : test)
        cout << el << " ";
}

// a) O = n^2 jer u najgorem slucaju prolazimo kroz dvije ugnjezdjene petlje i swapamo
//    omega = n^2 i za sortirano polje moramo proci kao kroz ne sortirano
//    theta = n^2 iz O i omega
// b) bubble sort algoritam sortira polje tako da krece otpocetka svaki put i swapa ako dva
//    susjedna elementa nisu u dobrom poretku, nakon prvog prolaska najveci element je na kraju
//    polja, nakon druge iteracije zadnji i predzadnji elementi su u dobrom poretku tako da je 
//    predzadnji manji od zadnjeg itd. do pocetka