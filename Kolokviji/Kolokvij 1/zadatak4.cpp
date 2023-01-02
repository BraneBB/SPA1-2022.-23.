#include <iostream>
#include <vector>

using namespace std;

int missing(vector<int> A, int k)
{
    vector<int> nums(A.size(), -1);

    for (int i = 0; i < A.size(); ++i)
    {
        nums[A[i]]++;
    }
    
    for (int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] == -1)
        {
            return i;
        }
    }
    
}

int main()
{
    vector<int> test1 = {2, 2, 3, 0, 3};
    vector<int> test2 = {2, 1, 3, 0, 3};
    vector<int> test3 = {1, 2, 3, 4, 5, 6, 7};

    cout << missing(test1, 3) << endl;
    cout << missing(test2, 4) << endl;
    cout << missing(test3, 7) << endl;
}