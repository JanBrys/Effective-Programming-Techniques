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
	cout << "Test metody vSetValueAt: " << endl << endl;

	CTable* c_tab_1 = new CTable();

	for (int ii = 0; ii < c_tab_1->iLength(); ii++)
	{
		c_tab_1->vsetValueAt(ii, ii + 1);
	}
	cout << "Test dla indeksow mieszczacych sie w tablicy: " << endl;
	c_tab_1->vPrintTable();
	cout << endl << "Test dla indeksu ujemnego: " << endl;
	c_tab_1->vsetValueAt(-1, 10);
	c_tab_1->vPrintTable();

	cout << endl << "Test dla indeksu powyzej 10000: " << endl;
	c_tab_1->vsetValueAt(10001, 10);
	c_tab_1->vPrintTable();

	cout << endl << "Test dla indeksu wiekszego od rozmiaru tablicy i mniejszego od maksymalnego indeksu: " << endl;
	c_tab_1->vsetValueAt(10, 10);
	c_tab_1->vPrintTable();

	delete c_tab_1;
	c_tab_1 = NULL;

	cout << "Test dla operatora +: " << endl << endl;

	CTable* c_tab_2 = new CTable();
	CTable* c_tab_3 = new CTable();
	for (int ii = 0; ii < c_tab_2->iLength(); ii++)
	{
		c_tab_2->vsetValueAt(ii, ii + 1);
	}
	for (int ii = 0; ii < c_tab_3->iLength(); ii++)
	{
		c_tab_3->vsetValueAt(ii, ii + 10);
	}
	cout << "Tablica 1: " << endl;
	c_tab_2->vPrintTable();
	cout << endl << endl << "Tablica 2:" << endl;
	c_tab_3->vPrintTable();
	cout << endl << endl << "Po uzyciu operatora +" << endl;
	(*c_tab_2 + *c_tab_3).vPrintTable();

	delete c_tab_2;
	c_tab_2 = NULL;
	delete c_tab_3;
	c_tab_3 = NULL;
	
	cout << "LISTA 2 - ZADANIA DODATKOWE" << endl;
	cout << "Testy poprawionego operatora =" << endl << endl;
	CTable* c_tab_4 = new CTable();
	CTable* c_tab_5 = new CTable();
	for (int ii = 0; ii < c_tab_4->iLength(); ii++)
	{
		c_tab_4->vsetValueAt(ii, ii + 1);
	}
	for (int ii = 0; ii < c_tab_5->iLength(); ii++)
	{
		c_tab_5->vsetValueAt(ii, ii + 10);
	}
	cout << "Tablica 1: " << endl;
	c_tab_4->vPrintTable();
	cout <<  endl << "Tablica 2:" << endl;
	c_tab_5->vPrintTable();
	cout << "Uzycie operatora =" << endl;
	*c_tab_4 = *c_tab_5;
	cout << "Tablica 1: " << endl;
	c_tab_4->vPrintTable();
	cout << endl << "Tablica 2:" << endl;
	c_tab_5->vPrintTable();
	cout << "Zmiana wartosci w tablicy 1: nowa wartosc = 100 w indeksie = 3" << endl;
	c_tab_4->vsetValueAt(3, 100);
	cout << "Tablica 1: " << endl;
	c_tab_4->vPrintTable();
	cout << endl << "Tablica 2:" << endl;
	c_tab_5->vPrintTable();

	delete c_tab_4;
	c_tab_4 = NULL;
	delete c_tab_5;
	c_tab_5 = NULL;

	cout << "Testy poprawionego operatora ^ dla znajdowania liczby" << endl << endl;
	CTable* c_tab_6 = new CTable();
	for (int ii = 0; ii < c_tab_6->iLength(); ii++)
	{
		c_tab_6->vsetValueAt(ii, ii + 1);
	}
	cout << "Tablica: ";
	c_tab_6->vPrintTable();

	cout << "Test dla liczby 4: " << (*c_tab_6 ^ 4) << endl;
	cout << "Test dla liczby 10: " << (*c_tab_6 ^ 10) << endl;

	delete c_tab_6;
	c_tab_6 = NULL;

	cout << "Testy poprawionego operatora ^ dla znajdowania elementów drugiej tablicy" << endl << endl;
	CTable* c_tab_7 = new CTable();
	for (int ii = 0; ii < c_tab_7->iLength(); ii++)
	{
		c_tab_7->vsetValueAt(ii, ii + 1);
	}
	CTable* c_tab_8 = new CTable();
	c_tab_8->vsetValueAt(0, 10);
	c_tab_8->vsetValueAt(1, 11);
	c_tab_8->vsetValueAt(2, 5);
	c_tab_8->vsetValueAt(3, 13);
	c_tab_8->vsetValueAt(4, 10);

	CTable* c_tab_9 = new CTable();
	for (int ii = 0; ii < c_tab_9->iLength(); ii++)
	{
		c_tab_9->vsetValueAt(ii, ii + 10);
	}

	cout << "Tablica 1: ";
	c_tab_7->vPrintTable();
	cout << "Tablica 2: ";
	c_tab_8->vPrintTable();
	cout << "Tablica 3: ";
	c_tab_9->vPrintTable();
	cout << "Sprawdzenie dla Tablicy 1 i 2: " << (*c_tab_7 ^ (*c_tab_8)) << endl;
	cout << "Sprawdzenie dla Tablicy 1 i 3: " << (*c_tab_7 ^ (*c_tab_9));

	delete c_tab_7;
	c_tab_7 = NULL;
	delete c_tab_8;
	c_tab_8 = NULL;
	delete c_tab_9;
	c_tab_9 = NULL;

	cout <<endl << "Test dla operatora & dajacego przeciecie 2 tablic" << endl;

	CTable c_tab_10("", 4);
	CTable c_tab_11("", 2);

	c_tab_10.vsetValueAt(0, 1);
	c_tab_10.vsetValueAt(1, 2);
	c_tab_10.vsetValueAt(2, 3);
	c_tab_10.vsetValueAt(3, 2);

	c_tab_11.vsetValueAt(0, 4);
	c_tab_11.vsetValueAt(1, 5);

	cout << "Tablica 1: ";
	c_tab_10.vPrintTable();
	cout << "Tablica 2: ";
	c_tab_11.vPrintTable();
	cout << "Przeciecie tablic: " << endl;
	//dla 2 przypadkow ponizje zwracana jest pusta tablica, ktora ma dlugosc dluzszej tablicy wyrazenia
	cout << "Tablica 1 & Tablica 2:";
	(c_tab_10& c_tab_11).vPrintTable();
	cout << "Tablica 2 & Tablica 1:";
	(c_tab_11 & c_tab_10).vPrintTable();

	CTable c_tab_12;
	c_tab_12 = c_tab_10;
	cout << "Tablica 3: ";
	c_tab_12.vPrintTable();
	cout << "Tablica 1 & Tablica 3:";
	(c_tab_10 & c_tab_12).vPrintTable();

	CTable c_tab_13("",3);
	c_tab_13.vsetValueAt(0, 2);
	c_tab_13.vsetValueAt(1, 2);
	c_tab_13.vsetValueAt(2, 2);
	cout << "Tablica 4: ";
	c_tab_13.vPrintTable();

	cout << "Tablica 1 & Tablica 4:";
	(c_tab_10 & c_tab_13).vPrintTable();
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

