#include <iostream>
#include <vector>

using namespace std;

int vacation(const vector<int> &A, const vector<int> &B, const vector<int> &C)
{
    vector<vector<int>> dp(A.size(), vector<int>(3));
    
    dp[0][0] = A[0];
    dp[0][1] = B[0];
    dp[0][2] = C[0];

    for (int i = 1; i < A.size(); ++i)
    {
        dp[i][0] = A[i] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = B[i] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = C[i] + min(dp[i - 1][1], dp[i - 1][0]);
    }

    return min(dp[A.size() - 1][0], min(dp[A.size() - 1][1], dp[A.size() - 1][2]));
    
}

int main()
{
    vector<int> A1 = {10, 20, 30};
    vector<int> B1 = {40, 50, 60};
    vector<int> C1 = {70, 80, 90};

    vector<int> A2 = {2,6,3};
    vector<int> B2 = {1,3,1};
    vector<int> C2 = {3,6,2};  

    vector<int> A3 = {6,8,2,7,4,2,7};
    vector<int> B3 = {7,8,5,8,6,3,5};
    vector<int> C3 = {8,3,2,6,8,4,1}; 

    cout << vacation(A1, B1, C1) << endl;
    cout << vacation(A2, B2, C2) << endl;
    cout << vacation(A3, B3, C3) << endl;
}