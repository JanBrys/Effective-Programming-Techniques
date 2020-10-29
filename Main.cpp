#include "CTable.h"

const int i_VALUE_ADDED_TO_OFFSET = 5;

void v_alloc_table_add_5(int iSize);
bool b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY);
bool b_dealloc_table_2_dim(int*** piTable, int iSizeX);

void v_fill_and_show_2_dim_table(int*** piTable, int iSizeX, int iSizeY);

void v_mod_table(CTable* pcTab, int iNewSize);
void v_mod_table(CTable cTab, int iNewSize);

int main()
{
	CTable c_tab_0, c_tab_1;

	c_tab_0.bSetNewSize(6);
	c_tab_1.bSetNewSize(4);
	for (int ii = 0; ii < c_tab_0.iLength(); ii++)
	{
		c_tab_0.vsetValueAt(ii, ii + 1);
	}
	for (int ii = 0; ii < c_tab_1.iLength(); ii++)
	{
		c_tab_1.vsetValueAt(ii, 51 + ii);
	}
	c_tab_0.vPrintTable();
	c_tab_1.vPrintTable();
	/*
	c_tab_0 = c_tab_1;
	c_tab_1.vsetValueAt(2, 123);
	c_tab_0.vPrintTable();
	c_tab_1.vPrintTable();
	*/
	(c_tab_0+c_tab_1).vPrintTable();

	c_tab_0 = c_tab_1;
	c_tab_0.vPrintTable();
	c_tab_1.vPrintTable();
}


void v_alloc_table_add_5(int iSize)
{
	if (iSize < 1 || iSize > 10000)
	{
		iSize = i_VALUE_ADDED_TO_OFFSET;
	}
	int* pi_table = new int[iSize];
	for (int ii = 0; ii < iSize; ii++)
	{
		pi_table[ii] = ii + i_VALUE_ADDED_TO_OFFSET;
	}
	for (int ii = 0; ii < iSize; ii++)
	{
		cout << pi_table[ii] << " ";
		//cout << *(pi_table + ii) << " ";	// wez adres na ktory wskazuje pi_table -> przesun go o ii -> wez wartosc ktora sie tam znajduje
	}
	delete[] pi_table;
}//v_alloc_table_add_5(int iSize)

bool b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY)
{
	if (iSizeX < 1 || iSizeY < 1 || iSizeX > 10000 || iSizeY > 10000)
	{
		return false;
	}
	*piTable = new int* [iSizeY];
	for (int ii = 0; ii < iSizeY; ii++)
	{
		(*piTable)[ii] = new int[iSizeX];
	}
	return true;

}//b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY)

bool b_dealloc_table_2_dim(int*** piTable, int iSizeX)
{
	if (iSizeX < 1 || iSizeX > 10000)
	{
		return false;
	}
	for (int ii = 0; ii < iSizeX; ii++)
	{
		delete[] (*piTable)[ii];
	}
	delete[] (*piTable);
	return true;
}

void v_fill_and_show_2_dim_table(int*** piTable, int iSizeX, int iSizeY)
{
	for (int iix = 0; iix < iSizeY; iix++)
	{
		for (int iiy = 0; iiy < iSizeX; iiy++)
		{
			(*piTable)[iix][iiy] = i_VALUE_ADDED_TO_OFFSET + iiy;
		}
	}
	cout << "Matrix: " << endl;
	for (int iix = 0; iix < iSizeY; iix++)
	{
		for (int iiy = 0; iiy < iSizeX; iiy++)
		{
			cout << (*piTable)[iix][iiy] << " ";
		}
		cout << endl;
	}
}
void v_mod_table(CTable* pcTab, int iNewSize)
{
	(*pcTab).bSetNewSize(iNewSize);
}

void v_mod_table(CTable cTab, int iNewSize)
{
	cTab.bSetNewSize(iNewSize);

}
//v_fill_and_show_2_dim_table(int*** piTable, int iSizeX, int iSizeY)

