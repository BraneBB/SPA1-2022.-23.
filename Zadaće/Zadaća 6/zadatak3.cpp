#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//moze se rjesiti greedy :D
int LISgreedy(const vector<int>& A)
{
	int n = (int)A.size();

	vector<int> lis;
	lis.push_back(A[0]);

	for (int i = 1; i < n; ++i) {
		if (A[i] > lis.back())
			lis.push_back(A[i]);
		else 
		{
			auto lower = lower_bound(lis.begin(), lis.end(), A[i]);
			*lower = A[i];
		}
	}
		
	return lis.size();
}

int LIS(const vector<int>& A)
{
    vector<int> dp(A.size());
    
    dp[0] = 1;

    for (int i = 1; i < A.size(); ++i) 
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (A[i] > A[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
    }

    return *max_element(dp.begin(), dp.end());
}


int main()
{
    vector<int> test1 = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    vector<int> test2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 } ;
    vector<int> test3 = { 3, 8, 3, 8, 1, 5, 10, 5, 8, 10 };
    vector<int> test4 = { 10, 8, 6, 7, 7, 3, 2, 8, 6, 3 };

    cout << LIS(test1) << endl;
    cout << LIS(test2) << endl;
    cout << LIS(test3) << endl;
    cout << LIS(test4) << endl;
}