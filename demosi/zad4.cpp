#include <iostream>
#include <stack>

using namespace std;
class minStack
{
    stack<pair<int,int>> S;

public:
    int min() { return S.top().second; }
    void pop() { S.pop(); }
    int top() { return S.top().first; }
    void push (int a)
    {
        if(S.empty())
            S.push(make_pair(a, a));
        
        else if (S.top().second > a)
            S.push(make_pair(a, a));
        
        else
            S.push(make_pair(a, S.top().second));
    }
};

int main()
{
    return 0;
}