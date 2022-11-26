#include <iostream>
#include <vector>

using namespace std;

struct Matrix
{
	// matricu mozemo definirati kao vektor vektora
	vector<vector<int>> A;
	Matrix() {}

	// konstruktor za kvadratnu matricu
	Matrix(int n) { A.assign(n, vector<int>(n));}

	//operator dohvacanja retka matrice 
	vector<int>& operator[](int n){ return A[n];}
};


Matrix matrixMultiplication(Matrix A, Matrix B)
{
    Matrix C (2);
    C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
    return C;
}

Matrix Matrixpow (Matrix &A, int n)
{
    if (n == 0)
	{
		Matrix base (2);
		base[0][0] = 1;
    	base[0][1] = 0;
    	base[1][0] = 0;
    	base[1][1] = 1;
		return base;
	}

	else if (n == 1)
	{
		return A;
	}

	else if (n % 2 == 0)
	{
		Matrix X = Matrixpow(A, n / 2);
		return matrixMultiplication(X, X);
	}

	else
	{
		return matrixMultiplication(A, Matrixpow(A, n - 1));
	}
}

int main()
{
	Matrix baseMatrix (2);
    baseMatrix[0][0] = 1;
    baseMatrix[0][1] = 1; 
    baseMatrix[1][0] = 1; 
    baseMatrix[1][1] = 0;
    
    Matrix B = Matrixpow (baseMatrix, 20);
	cout << B[0][1] << endl;
}