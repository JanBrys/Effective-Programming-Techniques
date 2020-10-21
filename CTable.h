#pragma once
#include "Constants.h"

using namespace NSDefaultValues;

class CTable
{
public:
	CTable();
	CTable(string sName, int iTableLen);
	CTable(CTable& pcOther);
	~CTable();

	void vSetName(string sName);
	void vPrintTable();
	bool bSetNewSize(int iTableLen);
	CTable* pcClone();

	void vFillTable(int iValue);

private:
	string s_name;
	int* pi_table;
	int i_table_len;
};

