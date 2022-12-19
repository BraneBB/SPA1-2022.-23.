#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int max5set(const vector<int> &A) {
    int j = 0, res = 0;
    int n = A.size();
    
    for (int i = 0; i < n; ++i) {
        while (j < n && A[j] - A[i] <= 5)
            j++;
        
        res = max(res, j - i);
    }
    
    return res;
}

class Queue {
    stack<int> Input, Output;
    void fix();
    
public:
    void push(int); // pusha na back  Theta(1)
    int front(); // vrati front amortizirano Theta(1)
    void pop(); // popa front amortizirano Theta(1)
};

void Queue::push(int x) { // Theta(1)
    Input.push(x); // Theta(1)
    return ;
}

void Queue::fix() { // O(n)
    while (!Input.empty()) { // n puta
        Output.push(Input.top()); // Theta(1)
        Input.pop(); // Theta(1)
    }
    
    return ;
}

int Queue::front() { // amortizirano Theta(1)
    if (Output.empty())
        fix(); // O(n)
    
    return Output.top();
}

void Queue::pop() { // amortizirano Theta(1)
    if (Output.empty())
        fix(); // O(n)
    
    Output.pop();
    return ;
}


class minQueue {
    queue<int> Q;
    deque<int> minQ;
    
public:
    int front() { return Q.front(); }
    int min() { return minQ.front(); }
    
    void pop();
    void push(int);
};

void minQueue::push(int x) { // amortizirano Theta(1)
    Q.push(x); // amortizirano Theta(1)
    while (!minQ.empty() && minQ.back() > x) // O(n)
        minQ.pop_back();
   
    minQ.push_back(x);
    
    return ;
}

void minQueue::pop() {
    if (Q.front() == minQ.front())
        minQ.pop_front();
    
    Q.pop();
    
    return ;
}


int main() {
    vector<int> A = { 1, 2, 10, 12, 15, 16, 17 };
    
    cout << max5set(A) << endl;
    Queue Q;
    
    for (int i = 0; i < 10; ++i)
        Q.push(i);
    
    for (int i = 0; i < 10; ++i) {
        cout << Q.front() << ' ';
        Q.pop();
    }
    
    minQueue minQ;
    
    vector<int> B = { 3, 2, 5, 4, 6 };
    for (int x: B)
        minQ.push(x);
   
    cout << endl;
    
    for (int i = 0; i < 5; ++i) {
        cout << minQ.min() << ' ';
        minQ.pop();
    }
    
    return 0;
}