
#include "functions.hpp"
#include <iostream>


int main()
{
	int n, m;
	int matrix[N_Max][N_Max];
	int MinElems;
	int pRows[N_Max];

	mt::Read(matrix, n, m);
	mt::findMinElems(matrix, MinElems, n, m);

	if (mt::isOneMoreMinElem(matrix, n, m, MinElems) and mt::TwoPrimeExistsInMatrix(matrix, n, m))
	{
		mt::ProizvedenieStr(matrix, n, m, pRows);
		mt::SortDecrease(matrix, MinElems, n, m, pRows);

		mt::Write(matrix, n, m);
	}
	

	return 0;
}
