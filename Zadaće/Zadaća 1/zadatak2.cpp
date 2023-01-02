#include <iostream>
#include <vector>

using namespace std;

vector<int> selection_sort(vector<int> &A)
{
    for (int i = 0; i < A.size() - 1; ++i)
    {
        int min = i;

        for (int j = i + 1; j < A.size(); ++j)
        {
            if(A[min] > A[j])
                min = j;
        }

        if(min != i)
            swap(A[i], A[min]);
    }
    
    return A;
}

int main()
{
    vector<int> test = {0, 9, 2, 1, 2, 3, 4, 5, 6, 7, 9, 0};

    test = selection_sort(test);

    for (auto &el : test)
        cout << el << " ";
}

// a) T(n) = n^2, jer imamo dvije for petlje jednu unutar druge
// b) 4 3 2 1 (svaki niz brojeva koji je obrnuto sortirano)
// c) O = n^2 jer se obje petlje uvijek izvrse
//    omega = n^2 jer i dalje neovisno o sortiranosti prolazi se kroz unutarnju petlju
//    theta = n^2 iz O i omega 
// d) algoritam selection sort krece od prvog elementa i usporedjuje taj element sa svakim
//    iducim do kraja niza i usput trazi najmanji medju njima, kada dodje do kraja i ima
//    sacuvan indeks najmanjeg elementa swap-a taj najmanji i i-ti element od kojeg smo poceli gledati