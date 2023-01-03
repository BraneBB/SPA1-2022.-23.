#include <iostream>
#include <vector>

using namespace std;

int hike(const vector<int> &H)
{
    vector<int> dp(H.size(), -1);
    
    dp[0] = 0;

    for (int i = 1; i < H.size(); ++i)
    {
        int jump2 = 1e9;
        int jump1 = dp[i - 1] + abs(H[i] - H[i - 1]);

        if(i > 1)
            jump2 = dp[i - 2] + abs(H[i] - H[i - 2]);
        
        dp[i] = min(jump1, jump2);
    }
    
    return dp[H.size() - 1];
}

int main()
{
    vector<int> test1 = {10, 30, 40, 20};
    vector<int> test2 = {10, 10};
    vector<int> test3 = {30, 10, 60, 10, 60, 50};

    cout << hike(test1) << endl;
    cout << hike(test2) << endl;
    cout << hike(test3) << endl;
}