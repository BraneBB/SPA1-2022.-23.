#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//fibonacci F(n) = F(n-1) + F(n-2)
vector<int> fib_dp(200000, -1);
int fib_rec(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  if (fib_dp[n] != -1) return fib_dp[n];
  int res = fib_rec(n-1) + fib_rec(n-2);
  fib_dp[n] = res;
  return res;
}

int fib_iter(int n) {
  vector<int> fib_dp(n+1);
  fib_dp[0] = 0;
  fib_dp[1] = 1;
  for (int i = 2; i <= n; ++i)
    fib_dp[i] = fib_dp[i-1] + fib_dp[i-2];

  return fib_dp[n];
}


// coin change, imamo kovanice C i koliko najmanje kovanica trebamo da vratimo x
// cc_dp[x] je koliko najmanje kovanica trebamo da vratimo sumu x
vector<int> cc_dp(200000, -1);
int cc_rec(int x, vector<int> &C) {
  if (x == 0) return 0;
  if (cc_dp[x] != -1) return cc_dp[x];
  int res = INT_MAX;
  for (int c: C)
    if (c <= x) // ako mozemo uzet kovanicu c
      res = min(res, 1 + cc_rec(x - c, C)); // pogledamo jel bolje uzet kovanicu c od dosad najboljeg vidjenog rjesenje

  cc_dp[x] = res;
  return res;
}

int cc_iter(int x, vector<int> &C) {
  vector<int> cc_dp(x+1, int(1e9));
  cc_dp[0] = 0;

  for (int i = 0; i <= x; ++i) {
    for (int c: C)
      if (c + i <= x)
        cc_dp[c+i] = min(cc_dp[c+i], 1 + cc_dp[i]);
  }

  return cc_dp[x];
}

// knapsack 0-1, imamo torbu u koju stanu predmeti sveukupne mase najvise x
// imam i nekoliko predmeta, predmet i ima vrijednost vi i tezinu wi
// kolika je najveca vrijednost koju mozemo stavit u torbu
// kn_dp[i][x] je najveca vrijednost ako je i-ti predmet na redu a imamo jos x mjesta u torbi
int kn_dp[1000][1000]; // treba postavit sve na -1 u mainu
int kn_rec(int i, int x, vector<pair<int,int>> &A) {
  if (i == -1) return 0;
  if (kn_dp[i][x] != -1) return kn_dp[i][x];
  int vi = A[i].first;
  int wi = A[i].second;
  int res1 = kn_rec(i-1, x, A); // ne izaberem predmet i
  int res2 = 0;
  if (wi <= x)
    res2 = vi + kn_rec(i-1, x-wi, A); // izaberem predmet i

  kn_dp[i][x] = max(res1, res2);
  return max(res1, res2);
}

int kn_iter(int x, vector<pair<int,int>> &A) {
  int n = A.size();
  int dp[n+1][x+1] = {}; // sve postavim na 0

  for (int i = 0; i < n; ++i) {
    int vi = A[i].first;
    int wi = A[i].second;
    for (int j = 0; j <= x; ++j) {
      if (j >= wi)
        dp[i+1][j] = max(dp[i][j], vi + dp[i][j-wi]);
      else
        dp[i+1][j] = dp[i][j];
    }
  }

  return dp[n][x];
}


int main() {
  cout << fib_rec(10) << ' '
    << fib_rec(5) << endl
    << fib_iter(10) << endl;
  cout << endl;

  int x = 17;
  vector<int> C = { 1, 5, 6, 9 };
  
  cout << cc_rec(x, C) << endl
    << cc_iter(x, C) << endl;
  cout << endl;

  for (int i = 0; i < 1000; ++i)
    for (int j = 0; j < 1000; ++j)
      kn_dp[i][j] = -1;

  x = 20;
  vector<pair<int,int>> A = { {1, 10}, {4,4}, {5,5}, {10,1} };
  cout << kn_rec(A.size() - 1, x, A) << endl
    << kn_iter(x, A) << endl;

  return 0;
}