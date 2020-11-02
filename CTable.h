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

/*
	w obu przypadkach ma wzrocic boola (podpunkt 2 i 3 z dodatkowej listy)
	w 4 biore przeciecie 2 tablic, jesli nie dziala to zwracam tablice pusta
	w przypadku kiedy wykonujemy metode operatorowa i zwraca inna niz wartosc typu prostego to z reguly musimy gdzies utworzyc obiekt, wypelnic go wartosciami ktore sa wymagane w kontekscie operacji i trzeba go zwrocic
	staje sie obiektem tymczasowym, staje sie L-wartoscia - normalnie dostepna dla programisty, mozna pod niego cos przypisac (left), moze stac po lewej stronie operatora przypisania

*/