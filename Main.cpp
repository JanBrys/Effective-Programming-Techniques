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

	(c_tab_0+c_tab_1).vPrintTable();
	CTable c_tab_2;
	c_tab_2 = c_tab_0 + c_tab_1;
	c_tab_0 = c_tab_1;
	cout << "Tab 1: ";
	c_tab_0.vPrintTable();
	cout << endl << endl << "Tab 2: ";
	c_tab_1.vPrintTable();
	cout << endl << endl;
	cout << "Lista dodatkowa zad. 2: " << endl;
	cout << "Wywolanie dla int = 1: " <<  (c_tab_0 ^ 1) << endl;
	cout <<"Wywolanie dla int = 51: " <<(c_tab_0 ^ 51) << endl << endl << endl;

	cout << "Lista dodatkowa zad. 3: " << endl;
	CTable c_tab_3;
	for (int ii = 0; ii < c_tab_3.iLength(); ii++)
	{
		c_tab_3.vsetValueAt(ii, ii + 5);
	}
	c_tab_3.vPrintTable();
	CTable c_tab_4;
	for (int ii = 0; ii < c_tab_4.iLength(); ii++)
	{
		c_tab_4.vsetValueAt(ii, ii + 9);
	}
	c_tab_4.vPrintTable();
	cout << endl << "Wywolanie operatora zad.3: " << (c_tab_3 ^ c_tab_4) << endl;

	cout << "Dla tablicy nie posiadajacej tych samych elementow" << endl << endl;
	CTable c_tab_5;
	for (int ii = 0; ii < c_tab_5.iLength(); ii++)
	{
		c_tab_5.vsetValueAt(ii, ii + 50);
	}
	c_tab_5.vPrintTable();
	cout << endl << "Wywolanie operatora zad.3: " << (c_tab_3 ^ c_tab_5) << endl<< endl;
	cout << "Lista dodatkowa zad. 4: " << endl;

	(c_tab_3 & c_tab_4).vPrintTable();
	(c_tab_3 & c_tab_5).vPrintTable();

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
	*piTable = NULL;
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

}//v_fill_and_show_2_dim_table(int*** piTable, int iSizeX, int iSizeY)

