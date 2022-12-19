#include <iostream>

using namespace std;

void sums(int A[], int n) { // O(n^2)
    for (int i = 0; i < n; ++i) { // O(n)
        int sm = 0; // 1 operacija
        for (int j = 0; j <= i; ++j) // O(i)
            sm += A[j]; // 2 operacije
        cout << sm << ' ';
    }
    
    return ;
}

// n0 = 1, c = 7
int sums_brzi(int A[], int n) { // <= 7n operacija
    if (n == 1) { // 1 operacija
        cout << A[0] << ' '; // 3 operacije
        return A[0]; // 2 operacije
    // Baza svekupno 6 operacija <= 7*1
    } else { // Pretpostavka sums_brzi(A, n-1) <= 7(n-1)
      int sums_rec = sums_brzi(A, n-1); // 7(n-1) operacija
      cout << (A[n-1] + sums_rec) << ' '; // 4 operacije
      return A[n-1] + sums_rec; // 3 operacije
    }
    // Korak sveukupno sums_brzi(A, n) = 7(n-1) + 4 + 3 = 7n
    // sums_brzi(A, n) <= 7n   (zbog <= u pretpostavci)


    // Preostaje dokazat da radi ono sto hocemo
    // Baza: sums_brzi(A, 1) ispise sumu(A[1..1]) i vrati sumu(A[1..1])
    // Pretpostavka: sums_brzi(A, n-1) ispise sume redom kojim zelimo i vrati sumu(A[1..i-1])
    // Korak: ispisemo (A[1..i-1] + A[i]) i vratimo to sto upravo je suma(A[1..i])
    // ...
}

void sums_for(int A[], int n) { // O(n)
    int sm = 0; // 1 operacija
    for (int i = 0; i < n; ++i) { // n puta
        // u svakom koraku sm ce biti suma(A[1..i-1])
        // i ovdje ju pretvorimo u suma(A[1..i])
        // formulom suma(A[1..i]) = suma(A[1..i-1]) + A[i]
        sm += A[i]; // 2 operacije
        cout << sm << ' '; // 2 operacije
    }
 
    return ;
}

int main() {
  int A[] = { 1, 2, -3, -4 };
  sums(A, 4);

  return 0;
}