#include <iostream>
#include <vector>

using namespace std;

int binmod(int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= min(i, k); ++j)
        {
            if(j == 0 || j == i)
                dp[i][j] = 1;
            
            else
               dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 8647; 
        }
    }

    return dp[n][k];
}

int main()
{
    cout << binmod(8, 5) << endl;
    cout << binmod(1000, 500) << endl;
    cout << binmod(300, 56) << endl;
    cout << binmod(120, 120) << endl;
    cout << binmod(12, 10) << endl;
}