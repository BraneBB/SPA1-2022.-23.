#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int towers(const vector<int> &A)
{
    vector<int>::iterator index;
    vector<int> tower;

    for(int i = 0; i < A.size(); ++i)
    {
        int x = A[i];

        index = upper_bound(tower.begin(), tower.end(), x);

        if (index - tower.begin() == tower.size())
            tower.push_back(x);
        else
            tower[index - tower.begin()] = x;
    }
    
    return tower.size();
}

int main()
{
   vector<int> A = {3, 8, 2, 1, 5};
   cout << towers(A) << endl;
}