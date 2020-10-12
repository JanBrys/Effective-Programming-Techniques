/*
	TODO = PRZETESTOWAÆ KLASÊ CTABLE (ALOKACJE STATYCZNA I DYNAMICZNA OBIEKTÓW)
*/
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
	//task 1
	cout << "Task 1:" << endl << endl;
	int i_size = 3;
	v_alloc_table_add_5(i_size);

	//task 2
	cout << "Task 2:" << endl << endl;
	int** pi_table;
	int i_sizeX = 2;
	int i_sizeY = 3;
	b_alloc_table_2_dim(&pi_table, i_sizeX, i_sizeY);
	v_fill_and_show_2_dim_table(&pi_table, i_sizeX, i_sizeY);

	//task 3
	b_dealloc_table_2_dim(&pi_table, i_sizeX);

	//task CTable
	CTable tab_1("foo", 2);
	tab_1.vPrintTable();
}


void v_alloc_table_add_5(int iSize)
{
	if (iSize < 1)
	{
		cout << "Array's size has to be a positive number." << endl;
	}
	else
	{
		int* pi_table = new int[iSize];

		for (int ii = 0; ii < iSize; ii++)
		{
			pi_table[ii] = ii + i_VALUE_ADDED_TO_OFFSET;
		}
		cout << "Tab: ";
		for (int ii = 0; ii < iSize; ii++)
		{
			cout << pi_table[ii] << " ";
			//cout << *(pi_table + ii) << " ";	// wez adres na ktory wskazuje pi_table -> przesun go o ii -> wez wartosc ktora sie tam znajduje
		}
		cout << endl << endl << endl;
		delete pi_table;
	}
}//v_alloc_table_add_5(int iSize)

bool b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY)
{
	if (iSizeX < 1 || iSizeY < 1)
	{
		cout << "One of the parameters is invalid." << endl;
		return false;
	}
	*piTable = new int* [iSizeX];
	for (int ii = 0; ii < iSizeX; ii++)
	{
		(*piTable)[ii] = new int[iSizeY];
	}
	return true;

}//b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY)

bool b_dealloc_table_2_dim(int*** piTable, int iSizeX)
{
	if (iSizeX < 1)
	{
		cout << "Parmeter iSizeX is invalid." << endl;
		return false;
	}
	for (int ii = 0; ii < iSizeX; ii++)
	{
		delete (*piTable)[ii];
	}
	delete (*piTable);
	return true;
}

void v_fill_and_show_2_dim_table(int*** piTable, int iSizeX, int iSizeY)
{
	for (int iix = 0; iix < iSizeX; iix++)
	{
		for (int iiy = 0; iiy < iSizeY; iiy++)
		{
			(*piTable)[iix][iiy] = i_VALUE_ADDED_TO_OFFSET + iiy;
		}
	}
	cout << "Matrix: " << endl;
	for (int iix = 0; iix < iSizeX; iix++)
	{
		for (int iiy = 0; iiy < iSizeY; iiy++)
		{
			cout << (*piTable)[iix][iiy] << " ";
		}
		cout << endl;
	}
}
void v_mod_table(CTable* pcTab, int iNewSize)
{

}
void v_mod_table(CTable cTab, int iNewSize)
{

}
//v_fill_and_show_2_dim_table(int*** piTable, int iSizeX, int iSizeY)

