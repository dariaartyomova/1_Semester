#include "functions.hpp"
#include <iostream>
#include <algorithm>



namespace mt
{
	void Read(int matrix[N_Max][N_Max], int& n, int& m)
	{
		std::cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				std::cin >> matrix[i][j];
	}

	void Write(int matrix[N_Max][N_Max], int n, int m)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				std::cout << matrix[i][j] << " ";
			std::cout << std::endl;
		}
	}

	bool isPrime(int x)
	{
		if (x < 2)
			return false;
		for (int d = 2; d < sqrt(x) + 1; d++)
			if (x % d == 0)
				return false;
		return true;
	}

	bool TwoPrimeExistsInMatrix(int matrix[N_Max][N_Max], int n, int m)
	{

		int Kprime = 0; //количество простых
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				if (isPrime(matrix[i][j]))
					Kprime+= 1;
		}
		if (Kprime >= 2)
			return true;
		else
			return false;
	}



	void findMinElems(int matrix[N_Max][N_Max], int& MinElems, int n, int m)
	{
		MinElems = 1000000;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				if (MinElems > matrix[i][j])
					MinElems = matrix[i][j];
		}
	}
	bool isOneMoreMinElem(int matrix[N_Max][N_Max], int n, int m, int MinElems)
	{
		int kOneMoreMinElem = 0; // количество еще одних миимальных элементов
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				if (matrix[i][j] == MinElems)
					kOneMoreMinElem += 1;
		}
		if (kOneMoreMinElem == 2)
			return true;
		else
			return false;
	}
	void ProizvedenieStr(int matrix[N_Max][N_Max], int n, int m, int pRows[N_Max])
	{
		for (int i = 0; i < n; i++)
		{
			pRows[i] = 1;
			for (int j = 0; j < m; j++)
			{
				pRows[i] *= matrix[i][j];
			}
		}
			

	}

	void SortDecrease(int matrix[N_Max][N_Max], int MinElems, int n, int m, int pRows[N_Max])
	{
		
		for (int i = 0; i < n - 1; i++)

			for (int j = i + 1; j < n; j++)
			{
				if (pRows[i] < pRows[j])
				{
					std::swap(pRows[i], pRows[j]);
					for (int k = 0; k < m; k++)
					{
						std::swap(matrix[i][k], matrix[j][k]);
					}
				}
					
				
						
			}
				
		
				
	}
}