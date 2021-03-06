#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "Przedmiot.h"
#include "Pokoj.h"

using namespace std;
// Vollo illo!
// cos
// sibling branch

const int PRZOD = 0;
const int TYL = 1;
const int LEWO = 2;
const int PRAWO = 3;


enum kierunek
{
	przod,
	lewo,
	tyl,
	prawo
};

Pokoj* generator() {
	Pokoj *kuchnia = new Pokoj("kuchnia");
	Przedmiot *stol = new Przedmiot("stol", 1);
	kuchnia->dodaj_przedmiot(stol);
	Przedmiot *krzeslo = new Przedmiot("krzeslo", -1);
	for (int i = 0; i < 4; i++)
	{
		kuchnia->dodaj_przedmiot(krzeslo);
	}

	Pokoj *salon = new Pokoj("salon");
	Przedmiot *kanapa = new Przedmiot("kanapa", 2);
	salon->dodaj_przedmiot(kanapa);

	Pokoj *sypialnia = new Pokoj("sypialnia");
	Przedmiot *lozko = new Przedmiot("lozko", 3);
	sypialnia->dodaj_przedmiot(lozko);

	kuchnia->przod = salon;
	salon->tyl = kuchnia;
	salon->przod = sypialnia;
	sypialnia->tyl = salon;

	return salon;
}

Pokoj* przemieszczanie(kierunek dk, Pokoj *lokacja)
{
	Pokoj *ret;
	switch (dk)
	{
	case przod:
		ret = lokacja->przod;
		break;
	case lewo:
		ret = lokacja->lewo;
		break;
	case tyl:
		ret = lokacja->tyl;
		break;
	case prawo:
		ret = lokacja->prawo;
		break;
	default:
		ret = NULL;
		break;
	}return ret;
}

void opis(Pokoj * lokacja)
{
	string kierunki[4] = { "z przodu", "z tylu", "na lewo", "na prawo" };
	Pokoj * pokoje[4] = { lokacja->przod, lokacja->tyl, lokacja->lewo, lokacja->prawo };
	cout << "w " << lokacja->nazwa << " znajduja sie:" << endl;
	for (Przedmiot * p : lokacja->wyposazenie)
	{
		cout << " - " << p->nazwa << endl;
	}
	for (int i = 0; i < 4; i++)
	{
		if (pokoje[i] == NULL)
		{
			cout << kierunki[i] << " nic nie ma" << endl;
		}
		else cout << kierunki[i] << " mamy " << pokoje[i]->nazwa << endl;
	}
}

int main()
{
	int punkty = 0;
	Pokoj *lokacja;
	lokacja = generator();
	int komenda;
	string lnazwa;
	bool przemiesc_sie = true;
	while (true)
	{
		if (przemiesc_sie) for (Przedmiot * p : lokacja->wyposazenie)
		{
			punkty += p->efekt;
		}
		cout << "Twoja punktacja wynosi " << punkty << endl;
		opis(lokacja);
		cin >> komenda;
		system("cls");
		kierunek dokad;
		przemiesc_sie = true;
		switch (komenda)
		{
		case 1:
			dokad = przod;
			break;
		case 2:
			dokad = tyl;
			break;
		default:
			cout << "NIE MA TAKIEJ KOMENDY" << endl;
			przemiesc_sie = false;
			break;
		}
		if (przemiesc_sie)
		{
			Pokoj *temp;
			temp = lokacja;
			lokacja = przemieszczanie(dokad, lokacja);
			if (lokacja == NULL)
			{
				lokacja = temp;
				cout << "brak przejscia" << endl;
				przemiesc_sie = false;
			}
		}
	}


	system("pause");
	return 0;
}