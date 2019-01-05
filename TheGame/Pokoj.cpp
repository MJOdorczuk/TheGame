#include "stdafx.h"
#include "Pokoj.h"



void Pokoj::dodaj_przedmiot(Przedmiot * przedmiot)
{
	this->wyposazenie.push_back(przedmiot);
}

Pokoj::Pokoj()
{
	this->nazwa = "";
	this->prawo = NULL;
	this->przod = NULL;
	this->lewo = NULL;
	this->tyl = NULL;
	cout << "Pokoj powstal" << endl;
}

Pokoj::Pokoj(string nazwa)
{
	this->nazwa = nazwa;
	this->prawo = NULL;
	this->przod = NULL;
	this->lewo = NULL;
	this->tyl = NULL;
	cout << nazwa << " istnieje " << endl;
}


Pokoj::~Pokoj()
{
}
