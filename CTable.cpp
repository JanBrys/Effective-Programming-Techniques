#include "CTable.h"

CTable::CTable()
{
	s_name = s_DEFAULT_OBJECT_NAME;
	i_table_len = i_DEFAULT_TABLE_LEN;
	pi_table = new int[i_table_len];
	cout << endl << " bezp: " << "'<" << s_name << ">'" << endl;
}

CTable::CTable(string sName, int iTableLen)
{
	if (0 < iTableLen)
	{
		i_table_len = iTableLen;
	}
	else
	{
		i_table_len = i_DEFAULT_TABLE_LEN;
	}
	s_name = sName;
	pi_table = new int[i_table_len];
	cout << endl << " param: " << "'<" << s_name << ">'" << endl;
}

CTable::CTable(CTable& pcOther)
{
	s_name = pcOther.s_name + "_copy";
	i_table_len = pcOther.i_table_len;
	pi_table = new int[i_table_len];

	for (int ii = 0; ii < pcOther.i_table_len; ii++)
	{
		pi_table[ii] = pcOther.pi_table[ii];
	}

	cout << endl << " kopiuj: " << "'<" << s_name << ">'" << endl;
}

CTable::~CTable()
{
	delete[] pi_table;
	cout << endl << " usuwam: " << "'<" << s_name << ">'" << endl;
}

void CTable::vSetName(string sName)
{
	s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen)
{
	if (0 < iTableLen && iTableLen != i_table_len && iTableLen < 10000)
	{
		int i_table_len_tmp = i_table_len;
		int* pi_table_tmp = pi_table;
		i_table_len = iTableLen;
		pi_table = new int[i_table_len];
		for (int ii = 0; ii < i_table_len; ii++)
		{
			pi_table[ii] = pi_table_tmp[ii];
		}
		delete[] pi_table_tmp;
		return true;
	}
	else
	{
		return false;
	}
}

CTable* CTable::pcClone()
{
	return new CTable(*this);
}

void CTable::vFillTable(int iValue)
{
	for (int ii = 0; ii < i_table_len; ii++)
	{
		pi_table[ii] = iValue;
	}
}

void CTable::vPrintTable()
{
	cout << endl;
	for (int ii = 0; ii < i_table_len; ii++)
	{
		cout << pi_table[ii] << " ";
	}
	cout << endl;
}
