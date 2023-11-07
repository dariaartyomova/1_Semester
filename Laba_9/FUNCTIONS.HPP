#pragma once
#define N_Max 100

namespace mt
{
	void Read(int matrix[N_Max][N_Max], int& n, int& m);

	void Write(int matrix[N_Max][N_Max], int n, int m);

	bool isPrime(int x);

	bool TwoPrimeExistsInMatrix(int matrix[N_Max][N_Max], int n, int m);

	void findMinElems(int matrix[N_Max][N_Max], int& MinElems, int n, int m);

	bool isOneMoreMinElem(int matrix[N_Max][N_Max], int n, int m, int MinElems);

	void ProizvedenieStr(int matrix[N_Max][N_Max], int n, int m, int pRows[N_Max]);

	void SortDecrease(int matrix[N_Max][N_Max], int MinElems, int n, int m, int pRows[N_Max]);

}

