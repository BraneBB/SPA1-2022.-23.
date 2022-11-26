#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> books (n);
    for (int i = 0; i < n; ++i)
    {
        cin >> books[i];
    }

    int sum = 0;
    int count = 0;
    int j = 0;

    for (int i = 0; i < n; ++i)
    {
        sum += books[i];
        if (sum <= t)
            count++;
        else
        {
            sum = sum - books[j];
            j++;
        }
    
    }

    cout << count << endl;

}