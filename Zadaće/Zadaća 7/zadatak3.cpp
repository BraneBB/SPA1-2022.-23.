#include <iostream>
#include <vector>

using namespace std;

int bellmod(int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = (dp[i - 1][i - 1]) % 8647;

        for (int j = 1; j <= i; ++j)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i][j - 1]) % 8647;
        
    }

    return dp[n][0];
}

int main()
{
    cout << bellmod(0) << endl;
    cout << bellmod(1) << endl;
    cout << bellmod(2) << endl;
    cout << bellmod(3) << endl;
    cout << bellmod(4) << endl;
    cout << bellmod(5) << endl;
    cout << bellmod(10) << endl;
    cout << bellmod(100) << endl;
    cout << bellmod(1000) << endl;
}