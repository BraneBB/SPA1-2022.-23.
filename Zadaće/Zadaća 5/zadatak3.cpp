#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int apartments(const vector<int> &A, const vector<int> &B, int k)
{
    sort(A.begin(), A.end());
	sort(B.begin(), B.end());

    int i = 0, j = 0;
    int ans = 0;

	while (i < A.size() && j < B.size())
    {
		if (abs(A[i] - B[j]) <= k)
        {
			++i; 
            ++j;
			++ans;
		}
		else
        {
			if (A[i] - B[j] > k)
				++j;
			else
				++i;
		}
	}

    return ans;
}

int main()
{

}