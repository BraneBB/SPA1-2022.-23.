// 1. Zadatak, dana je lista A od n cijelih brojeva,
// i dan je broj x.
// Vratite bool postoji li dva elementa iz A tj, i i j td.
//  A[i] + A[j] = x

#include <iostream>
#include <vector>
#include <algorithm> // sort, binary_search

using namespace std;

// Omega(1) O(n^2)
bool has_x(const vector<int> &A, int x) {
    for (int i = 0; i < A.size(); ++i) {
        for (int j = i + 1; j < A.size(); ++j) {
            if (A[i] + A[j] == x)
                return true;
        }
    }
    
    return false;
}

// Zelim O(n log n)
bool has_x_faster(int A[], int n, int x) {
    sort(A, A + n); // Theta(n log n)
    
    for (int i = 0; i < n; ++i) { // n pokusaja
        int first = A[i]; // nasli smo prvog
        int second = x - A[i]; // mozda nadjemo drugog
        bool has_second = binary_search(A + i + 1, A + n, second);
        // binary_search = O(log n)
        // smijemo jer je sortiran A[i+1..n]
        if (has_second) return true; // ako smo nasli imamo rjesenje
    }
    
    return false;
}

// has_x_faster = Theta(n log n) + n * O(log n)

// 2. zadatak
// zelimo izracunati geometrijski niz oblika
// geo(x, n) = 1 + x + x^2 + x^3 + ... + x^n

// O(n)
int geo(int x, int n) {
    int geo_sum = 0;
    int curr_pwr = 1;
    for (int i = 0; i <= n; ++i) { // n puta
        geo_sum += curr_pwr;
        curr_pwr *= x;
        // O(1)
    }
    
    return geo_sum;
}

// O(n)
int geo2(int x, int n) {
    if (n == 0) return 1;
    else {
        return 1 + x * geo2(x, n - 1);
    }
}

// Theta(log n)
int fast_pow(int x, int n) {
    if (n == 0) return 1;
    if (n % 2 == 1) return x * fast_pow(x, n-1);
    int res = fast_pow(x, n/2);
    return res * res;
}

// Theta(log n)
int geo_fast(int x, int n) {
    return (fast_pow(x, n+1) - 1) / (x - 1);
}

// 3. zadatak
// Zelimo izracunati floor(sqrt(n))

// O(sqrt n)
int floor_sqrt(int n) {
    int lst = 0;
    for (int i = 0; i <= n; ++i) {
        if (i * i > n) break;
        else lst = i;
    }
    
    return lst;
}

int main() {
    int A[] = { 1, 3, 7, 2, 8 };
    int n = 5;
    int x = 15;
    
    cout << "Is x in A?: " << has_x_faster(A, n, x) << '\n'
         << "geo(3, 4) = " << geo_fast(3, 4) << '\n'
         << "floor(sqrt(80)) = " << floor_sqrt(80);
    return 0;
}
