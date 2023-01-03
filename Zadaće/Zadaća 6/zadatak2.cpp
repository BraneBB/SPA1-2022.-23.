#include <iostream>
#include <vector>

using namespace std;

int coin_change_count_bottom_up(int x)
{
    vector<int> C = {1, 2, 5};

	// sve vrijednosti tablice postavljamo na 0 jer u nju dodajemo
	// vrijednosti prethodnih, ranije izracunatih elemenata
	vector<int> dp(x + 1, 0);

	dp[0] = 1; // 0 novcica mozemo zapisati kao prazan skup

	for (int i = 1; i <= x; ++i)
		for (const int& c : C)
			if (c <= i)
				dp[i] += dp[i - c];

	return dp[x];
}

int main()
{
    int test1 = 3;
    int test2 = 4;
    int test3 = 5;
    int test4 = 6;
    int test5 = 7;
    int test6 = 8;

    cout << coin_change_count_bottom_up(test1) << endl;
    cout << coin_change_count_bottom_up(test2) << endl;
    cout << coin_change_count_bottom_up(test3) << endl;
    cout << coin_change_count_bottom_up(test4) << endl;
    cout << coin_change_count_bottom_up(test5) << endl;
    cout << coin_change_count_bottom_up(test6) << endl;
}