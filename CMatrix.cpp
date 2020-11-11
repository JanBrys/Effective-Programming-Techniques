#include "CMatrix.h"

CMatrix::CMatrix(int row_cnt, int col_cnt)
{
	x = row_cnt;
	y = col_cnt;

	pi_pointer = new float*[row_cnt];
	for (int i = 0; i < col_cnt; i++)
	{
		pi_pointer[i] = new float[col_cnt];
	}
}
CMatrix::CMatrix()
{
	pi_pointer = new float* [x];
	for (int i = 0; i < y; i++)
	{
		pi_pointer[i] = new float[y];
	}
}
CMatrix::~CMatrix()
{
	for (int i = 0; i < x; i++)
	{
		delete[] pi_pointer[i];
	}
	delete[](*pi_pointer);
}

void CMatrix::operator=(const CMatrix& pcOther)
{
	for (int i = 0; i < x; i++)
	{
		delete[] pi_pointer[i];
	}
	delete[](*pi_pointer);

	pi_pointer = new float* [pcOther.x];
	for (int i = 0; i < pcOther.y; i++)
	{
		pi_pointer[i] = new float[pcOther.y];
	}
}

CMatrix CMatrix::operator*(const CMatrix& pcOther)
{
	if (y == pcOther.x)
	{
		CMatrix tmp(x, pcOther.y);
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < pcOther.y; j++)
			{
				tmp.pi_pointer[i][j] = pi_pointer[i][y] * pcOther.pi_pointer[y][pcOther.y];
			}
		}
		return tmp;
	}
	return *this;
}

