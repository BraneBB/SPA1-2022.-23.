#include <iostream>
#include <vector>

using namespace std;

// n0 = 1, c = 5
int min_indx(int A[], int n) { // napravi <= 5n operacija sto znaci da je O(n)
    if (n == 1) return 0; // Baza: index sa najmanjim elementom upravo je 0, i izvrsi se 2 operacije (==, return)
    else { // Korak indukcije: treba pokazati da min_indx(A, n) <= 5n
    // Pretpostavke:
    // min_indx(A, n-1) vrati index sa najmanjim elementom iz A
    // min_indx(A, n-1) radi u <= 5(n-1) operacija
        int rec_min_indx = min_indx(A, n-1); // 5n - 5
        if (A[rec_min_indx] < A[n-1]) // 3 operacije (dvije [] i jedan <)
            return rec_min_indx; // 1 operacija
        else
            return n - 1; // 1 operacija
    } // Sveukupno min_indx(A, n) = 5(n-1) + 3 + 1 = 5n - 1 <= 5n    (jer 1<=n)


    // Zasto if/else ce vratiti index s najmanjim elementom u (A, n) ?
    // A[rec_min_indx] je manji od svih (A, n-1)
    // Ako je A[n-1] <= A[rec_min_indx] onda je i od ostalih zbog komentara iznad
    // Ako nije onda najmanji ostaje i dalje najmanji

    // Zeljeli smo pokazati da min_indx(A, n) ima O(n) operacija
    // Pokazali smo Bazu min_indx(A, 1) = 2 <= 5*1
    // Pretpostavili smo da min_indx(A, n-1) <= 5(n-1)
    // Pokazali smo Korak da sveukupno min_indx(A, n) <= 5n

}

int main() {
    int A[] = { 1, 2, -3, 4 }; // O(n)
    cout << min_indx(A, 4);

    return 0;
}