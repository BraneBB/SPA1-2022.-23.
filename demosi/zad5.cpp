#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> left_less(vector<int> &A)
{
    stack<pair<int,int>> S;
    vector<int> out;

    for (int i=0; i < A.size(); ++i)
    {
        while (!S.empty() && S.top().first >= A[i])
            S.pop();

        if (S.empty())
            out.push_back(-1);
        else
            out.push_back(S.top().second);
 
        
        S.push(make_pair(A[i], i + 1));
    }

    return out;
}

int main()
{
    vector<int> input = {2, 5, 1, 4, 8, 3, 2, 5};

    vector<int> output = left_less(input);

    for (auto &el : output)
    {
        cout << el << " ";
    }
    
    return 0;
}