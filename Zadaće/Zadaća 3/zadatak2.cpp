#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& A, int l, int m, int r)
{
	int n1 = m - l + 1, n2 = r - m;	
	vector<int> L(n1 + 1), R(n2 + 1);

	for (int i = 0; i < n1; ++i)
		L[i] = A[l + i];

	for (int i = 0; i < n2; ++i)
		R[i] = A[m + 1 + i];

	L[n1] = R[n2] = 1e9;

	int i = 0, j = 0, inv = 0;

	for (int k = l; k <= r; ++k) 
    {
		if (L[i] <= R[j]) 
        {
			A[k] = L[i];
			i++;
		} 
        else 
        {
			inv += n1 - i;
			A[k] = R[j];
			j++;
		}
	}
	return inv;
}

int merge_sort(vector<int>& A, int l, int r)
{
	if (l >= r)
		return 0;

	int m = (l + r) / 2;

	int x = merge_sort(A, l, m);
	int y = merge_sort(A, m + 1, r);

	return x + y + merge(A, l, m, r);
}

int main()
{
	vector<int> A = {5, 4, 3, 2, 1};
    
	cout << merge_sort(A, 0, 4) << endl;
}