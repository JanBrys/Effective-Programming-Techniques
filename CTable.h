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

	void operator=(const CTable& pcOther);
	CTable operator+(const CTable& pcOther);
	bool operator^(const int iValue);
	bool operator^(const CTable& pcOther);
	CTable operator&(const CTable& pcOther);

	void vSetName(string sName);
	void vPrintTable();
	bool bSetNewSize(int iTableLen);
	CTable* pcClone();

	void vFillTable(int iValue);

	void vsetValueAt(int iOffset, int inewValue);
	int iLength();
private:
	string s_name;
	int* pi_table;
	int i_table_len = 5;
};

