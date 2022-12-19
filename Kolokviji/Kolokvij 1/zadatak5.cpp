#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int closest(vector<int> A)
{
    sort(A.begin(), A.end());
    
    //10 na 9
    int mini = 1e9;

    for (int i = 0; i < A.size(); ++i)
    {
        if(i == 0)
            mini = min(abs(A[i] - A[i + 1]), mini);
        
        else if(i == A.size() - 1)
            mini = min(abs(A[i] - A[i - 1]), mini);

        else
        {
            mini = min(abs(A[i] - A[i + 1]), mini);
            mini = min(abs(A[i] - A[i - 1]), mini);
        }
    }

    return mini;
}

int main()
{
    vector<int> test1 = {4, 2, 5, 10};
    vector<int> test2 = {1, 3, 5, 10, 1};
    vector<int> test3 = {2000, 100, 1000, 10};

    cout << closest(test1) << endl;
    cout << closest(test2) << endl;
    cout << closest(test3) << endl;
}