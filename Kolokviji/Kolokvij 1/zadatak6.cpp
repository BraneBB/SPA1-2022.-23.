#include <iostream>
#include <vector>

using namespace std;

int subarray_sum(vector<int> A, int x)
{
    int sum = 0;
    int counter = 0;
    int move = 0;
 
    for (int i = 0; i < A.size(); ++i)
    {
        sum += A[i];
            
        while(sum >= x)
        {
            if(sum == x)
                counter++;
    
            sum -= A[move];
            move++;
        }
    }

    return counter;
}

int main()
{
    vector<int> test1 = {2, 4, 1, 2, 7};
    vector<int> test2 = {1, 1, 1, 1, 1, 1, 1, 1, 3, 4};
    vector<int> test3 = {1, 2, 3, 4, 5, 6, 7};
   
    cout << subarray_sum(test1, 7) << endl;
    cout << subarray_sum(test2, 7) << endl;
    cout << subarray_sum(test3, 8) << endl;
}