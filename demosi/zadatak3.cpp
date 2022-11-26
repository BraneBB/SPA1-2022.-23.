#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a (n);
    vector<int> b (m);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int i = 0, j = 0;
    int ans = 0;
	while (i < n && j < m){
		// apartman pase gostu
		if (abs(a[i] - b[j]) <= k)
        {
			++i; ++j;
			++ans;
		}
		else{
			// apartmant koji trazi je premal, trazimo mu veci
			if (a[i] - b[j] > k)
            {
				++j;
			}
			// apartman koji trazi je prevelik, idemo na sljedeceg gosta
			else{
				++i;
			}
		}
	}

    cout << ans << endl;
}