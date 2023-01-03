#include <iostream>
#include <vector>

using namespace std;

int books(const vector<int> &A, int t)
{
    int sum = 0, count = 0, j = 0;

    for (int i = 0; i < A.size(); ++i)
    {
        sum += A[i];

        if(sum <= t)
            count++;
        else
        {
            sum =- A[j];
            j++;
        }    
    }

    return count;
}

int main()
{

}