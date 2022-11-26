#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A;
    
    vector<int>::iterator index;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        index = upper_bound(A.begin(), A.end(), x);
        if (index - A.begin() == A.size())
            A.push_back(x);
        else
            A[index - A.begin()] = x;
    }

    cout << A.size() << endl;
}