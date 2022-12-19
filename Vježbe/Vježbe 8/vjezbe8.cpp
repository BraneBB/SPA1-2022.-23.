#include <iostream>
#include <vector>

using namespace std;

int dp_bin[1001][1001]; // postavit u mainu na -1
int binomod(int n, int k) {
    if (n == k) return 1;
    if (k == 0) return 1;
    if (dp_bin[n][k] != -1) return dp_bin[n][k];
    int res = (binomod(n-1,k) + binomod(n-1,k-1)) % 8647;
    
    return dp_bin[n][k] = res;
}

int dp_bell[1001]; // postavit u mainu na -1
int bellmod(int n) {
    if (n == 0) return 1;
    if (dp_bell[n] != -1) return dp_bell[n];
    int res = 0;
    for (int i = 0; i < n; ++i)
        res = (res + ((binomod(n-1, i) * bellmod(i)) % 8647)) % 8647;
    
    return dp_bell[n] = res;
}

// LCS - longest common subsequence
// najduzi podniz koji se pojavljuje u oba stringa
// npr
// LCS("acdbc", "aaaddcc") = 3 jer "adc" ili "acc"
int dp_LCS[1001][1001]; // postavit u mainu na -1
string s1 = "acdbc", s2 = "aaaddcc"; // stringovi koje usporedjujemo
int LCS(int i, int j) { // usporedjujemo i-ti i j-ti char
    if (i >= s1.size() || j >= s2.size()) return 0;
    if (dp_LCS[i][j] != -1) return dp_LCS[i][j];
    
    int res = 0;
    if (s1[i] == s2[j]) res = 1 + LCS(i+1, j+1); // ili su jednaki i res++
    res = max(res, LCS(i+1, j)); // ili preskocim s1[i]
    res = max(res, LCS(i, j+1)); // ili preskocim s2[j]
    
    return dp_LCS[i][j] = res;
}

int main() {
    for (int i = 0; i < 1001; ++i)
        for (int j = 0; j < 1001; ++j)
            dp_bin[i][j] = -1;
        
    cout << binomod(10, 1) << endl
        << binomod(500, 100) << endl
        << binomod(8, 3) << endl;
    
    cout << endl;
    
    for (int i = 0; i < 1001; ++i)
        dp_bell[i] = -1;
   
    for (int i = 0; i < 10; ++i)
        cout << bellmod(i) << endl;
   
    cout << endl;
    
    for (int i = 0; i < 1001; ++i)
        for (int j = 0; j < 1001; ++j)
            dp_LCS[i][j] = -1;
    
    s1 = "abcdefgh";
    s2 = "aabbccddefgh";
    cout << LCS(0, 0) << endl;
    
    return 0;
}