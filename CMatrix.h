#pragma once
class CMatrix
{
public:
	CMatrix();
	CMatrix(int row_cnt, int col_cnt);
	~CMatrix();
	void operator=(const CMatrix& pcOther);
	CMatrix operator*(const CMatrix& pcOther);
private:
	int x=2;
	int y=3;
	float** pi_pointer;
};

