#include <iostream>
#include <vector>

using namespace std;

bool recursiveBinarySearch(vector<int> &A, int left, int right, int x)
{
    if(left > right)
        return false;
    
    int mid = (left + right) / 2;
    
    if(A[mid] > x)
        recursiveBinarySearch(A, left, mid - 1, x);

    else if (A[mid] == x)
        return true;
    
    else
        recursiveBinarySearch(A, mid + 1, right, x);
}

bool iterativeBinarySearch(vector<int> &A, int x)
{
    int left = 0;
    int right = A.size() - 1;

    while(left <= right)
    {
        int mid = (left + right) / 2;
        
        if(A[mid] > x)
            right = mid - 1;
        
        else if (A[mid] == x)
            return true;
        
        else
            left = mid + 1;
    }

    return false;
}

int main()
{
    vector<int> sortedArray = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << recursiveBinarySearch(sortedArray, 0, sortedArray.size() - 1, -1) << endl;
    cout << recursiveBinarySearch(sortedArray, 0, sortedArray.size() - 1, 8) << endl;
    cout << recursiveBinarySearch(sortedArray, 0, sortedArray.size() - 1, 10) << endl;
    cout << endl;
    cout << iterativeBinarySearch(sortedArray, -1) << endl;
    cout << iterativeBinarySearch(sortedArray, 8) << endl;
    cout << iterativeBinarySearch(sortedArray, 10) << endl;
}