#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// U trgovini je rasprodaja, i za svaki racun od 2 ili vise proizvoda,
// dobijete najjeftiniji gratis
// Zelite kupiti n <= 2*10^5 proizvoda, i cijene su im A[i] < 10^9
// Smijete uzimati racuna koliko hocete i uci i izaci iz trgovine koliko hocete
// Dajte najjeftinije koliko mozete proci ako morate kupiti sve proizvode

int sale(const vector<int> &A) {
    vector<int> B = A;
    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());
    
    int cost = 0;
    for (int i = 0; i < (int) B.size(); i++)
        if (i % 2 == 0)
            cost += B[i];
    
    
    return cost;
}

// U selu od n < 2 *10^5 kuca, samo prva kuca ima struje
// Zelimo ih sve spojiti tako da prodjemo sto jeftinije
// Spajanje kuce i i kuce j kosta A[i] + A[j]
// Koliko najmanje mozemo platiti da (indirektno) spojimo sve kuce

int elect(const vector<int> &A) {
    vector<int> B = A;
    sort(B.begin(), B.end());
    int cost = 0;
    
    for (int i = 1; i < (int) B.size(); ++i)
        cost += B[0] + B[i];
    
    return cost;
}

// Imamo cestu podijeljenu na n <= 2*10^5 dijelova,
// Na i-tom dijelu se nalazi kuca akko A[i] == 1, inace prazan dio A[i] == 0
// Imamo lampe jake k, i ako postavimo lampu na i-ti dio, ona ce osvijetliti
// svo od i-k do i+k. Koliko najmanje lampi moramo postaviti da sve kuce butu
// osvijetljene

int lights(const vector<int> &A, int k) {
    int cnt = 0;
    for (int i = 0; i < (int) A.size(); ++i)
        if (A[i] == 1) {
            cnt++;
            i += 2 * k;
        }
    
    return cnt;
}


// Primjer ne greedy
// Imamo kovanice { 1, 3, 4 } i zelimo sto manje kovanica iskoristit da
// dobijem u sumi broj 6


// Danas je muzej bio popularan i strazara zanima koliko je bilo najvise ljudi
// u isto vrijeme u nekom trenutku
// Dano n <= 2*10^5 gostiju, i za svakog gosta dano je kad je dosao A[i].first 
// i vrijeme kad je otisao A[i].second <= 10^9, A[i].first <= A[i].second

int museum(const vector<pair<int,int>> &A) {
    vector<int> dolasci;
    vector<int> odlasci;
    for (auto p: A) {
        int l = p.first;
        int r = p.second;
        dolasci.push_back(l);
        odlasci.push_back(r);
    }
    
    sort(dolasci.begin(), dolasci.end());
    sort(odlasci.begin(), odlasci.end());
    int cnt = 0;
    int max_res = 0;
    int i = 0; // index za dolasci
    int j = 0; // index za odlasci
    while (i < (int) dolasci.size() || j < (int) odlasci.size()) {
        if (i < (int) dolasci.size() && dolasci[i] <= odlasci[j]) {
            cnt++;
            i++;
        } else {
            cnt--;
            j++;
        }
        
        max_res = max(max_res, cnt);
    }
    
    return max_res;
}

// Marica je na film festivalu, i pusta se n <= 2*10^5 razlicitih filmova.
// Za svaki film zna da pocinje u vremenu A[i].first
// i zavrsava u vremenu A[i].second < 10^9 od pocetka film festivala.
// Koliko najvise filmova stigne pogledat ako film mora pogledat od pocetka do kraja
// i cim zavrsi trenutni film, moze pocetk gledat sljedeci ili cekta da on pocne

int movies(const vector<pair<int,int>> &A) {
    vector<pair<int,int>> B = A;

    sort(B.begin(), B.end(), [](auto &x, auto &y) {
       if (x.second == y.second) return x.first < y.first;
       return x.second < y.second;
    });
    int t = 0;
    int cnt = 0;
    for (int i = 0; i < (int) B.size(); ++i) {
        int b = B[i].first;
        int e = B[i].second;
        //auto [b, e] = B[i];
        if (b < t) continue;
        cnt++;
        t = e;
    }
    
    return cnt;
}

int main() {
    vector<int> A = { 1, 2, 3 };
    cout << sale(A) << endl;
    cout << elect(A) << endl;
    vector<int> B = { 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1 };
    cout << lights(B, 3) << endl;
    vector<pair<int,int>> C = { {1, 3}, {2, 4}, {3, 5}, {5, 6} };
    cout << museum(C) << endl;
    cout << movies(C) << endl;
    
    return 0;
}