#pragma once
#include "Przedmiot.h"
#include <vector>
#include <iostream>

class Pokoj
{
public:
	vector<Przedmiot *> wyposazenie;
	string nazwa;
	Pokoj *przod;
	Pokoj *tyl;
	Pokoj *lewo;
	Pokoj *prawo;
	void dodaj_przedmiot(Przedmiot * przedmiot);

	Pokoj(); // ctor
	Pokoj(string nazwa);
	~Pokoj(); // dstr
};

