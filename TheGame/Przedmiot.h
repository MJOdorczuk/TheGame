#pragma once
#include <string>

using namespace std;

class Przedmiot
{
public:
	string nazwa;
	int efekt;
	Przedmiot();
	Przedmiot(string nazwa, int efekt);
	~Przedmiot();
};

