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
	cout << "Testowanie funkcji v_alloc_table_add_5(int iSize)" << endl << "iSize = -1:  ";
	v_alloc_table_add_5(-1);
	cout << endl << "iSize = 100000: ";
	v_alloc_table_add_5(100000);
	cout << endl << "iSize = 14: ";
	v_alloc_table_add_5(14);

	cout << endl << endl << "Testowanie funkcji b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY)" << endl;
	int** pi_table;
	cout << "X =5,Y=-5 => " << b_alloc_table_2_dim(&pi_table, 5, -5) << endl;
	cout << "X =-5,Y=5 => " << b_alloc_table_2_dim(&pi_table, -5, 5) << endl;
	cout << "X =-5,Y=-5 => " << b_alloc_table_2_dim(&pi_table, -5, -5) << endl;
	cout << "X =5,Y=3 => " << b_alloc_table_2_dim(&pi_table, 5, 3) << endl;
	v_fill_and_show_2_dim_table(&pi_table, 5, 3);

	cout << endl << endl << "Testowanie funkcji b_dealloc_table_2_dim(int*** piTable, int iSizeX)" << endl;
	cout << "iSizeX = -1 => " << b_dealloc_table_2_dim(&pi_table,-1) << endl;
	cout << "iSizeX = 100000 => " << b_dealloc_table_2_dim(&pi_table, 100000) << endl;
	cout << "iSizeX = 3 => " << b_dealloc_table_2_dim(&pi_table, 3) << endl << endl;
	
	cout << "Testy klasy CTable" << endl;
	cout << "Pierwszy przypadek: Sprawdzanie wszystkich zaimplementowanych metod" << endl;
	CTable c_tab_static_default;
	c_tab_static_default.vFillTable(1);
	c_tab_static_default.vPrintTable();
	c_tab_static_default.vSetName("Static CTable object");
	cout << endl << c_tab_static_default.bSetNewSize(-2);
	cout << endl << c_tab_static_default.bSetNewSize(100000);
	cout << endl << c_tab_static_default.bSetNewSize(5);
	cout << endl << c_tab_static_default.bSetNewSize(10);
	c_tab_static_default.vPrintTable();

	cout << "Sprawdzenie metody *pcClone()" << endl;
	CTable* pc_new_tab;
	pc_new_tab = c_tab_static_default.pcClone();
	delete pc_new_tab;

	cout << endl << "Dowod, ze tablice sa kopiowane:" << endl;
	c_tab_static_default.vPrintTable();

	cout << endl << "v_mod_table(CTable cTab, int iNewSize)" << endl;
	v_mod_table(c_tab_static_default, 5);
	c_tab_static_default.vPrintTable();
	
	cout << endl << "v_mod_table(CTable* pcTab, int iNewSize)" << endl;
	v_mod_table(&c_tab_static_default, 5);
	c_tab_static_default.vPrintTable();

	cout << endl << "Sprawdzenie konstruktora parametrycznego" << endl;
	CTable c_tab_static_param("param",5);

	cout << endl << "Sprawdzenie konstruktora kopiujacego" << endl;
	CTable c_tab_static_copy(c_tab_static_param);

	cout << endl << "Sprawdzenie alokacji statycznej tablicy" << endl;
	CTable c_tab[3];
	c_tab[0].vSetName("tab1");
	c_tab[1].vSetName("tab2");
	c_tab[2].vSetName("tab3");

	cout << endl << "Sprawdzenie alokacji dynamicznej tablicy" << endl;
	CTable* pc_tab = new CTable[3];
	delete[] pc_tab;

	cout << endl << "Ponizej usuwane sa ze stosu zmienne" << endl;
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
	pcTab->bSetNewSize(iNewSize);
}

void v_mod_table(CTable cTab, int iNewSize)
{
	cTab.bSetNewSize(iNewSize);

}
//v_fill_and_show_2_dim_table(int*** piTable, int iSizeX, int iSizeY)

