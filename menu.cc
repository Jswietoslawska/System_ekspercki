#pragma once
#include <stdio.h>
#include <iostream>
#include "badanie.h"
#include <vector>

using namespace std;

void ekran_powitalny();
void pytania_ogolne(vector<badanie> badania);
int pobierz_odpowiedz(int dolna_granica, int gorna_granica);
int pobierz_odpowiedz(int dolna_granica);

int main()
{
	setlocale(LC_ALL, "polish");
	ekran_powitalny();
	vector <badanie> badania;
	pytania_ogolne(badania);
}

void ekran_powitalny()
{
	cout << "SYSTEM EKSPERCKI" << endl;
	cout << "Badania profilaktyczne i okresowe oraz szczepienia i bilanse" << endl;
	cout << "System na podstawie odpowiedzi na pytania podaje list� sugerowanych bada�" << endl;
	cout << "profilaktycznych, okresowych, szczepie� oraz bilans�w." << endl;
	cout << "System nie stawia diagnozy i nie zast�puje konsulatcji z lekarzem." << endl;
	cout << "Wybieraj�c odpowied� wpisuj odpowiadaj�cy jej numer.";
}

void pytania_ogolne(vector<badanie> badania)
{
	int odpowiedz = 0;
	int wiek, plec;
	PLEC Plec;
	cout << endl << "B�dziesz odpowiada� za siebie czy za dziecko (poni�ej 16 r. �.)?" << endl;
	cout << "1 - za siebie, 2 - za dziecko" << endl;
	odpowiedz = pobierz_odpowiedz(1,2);
	cout << odpowiedz;
	switch (odpowiedz)
	{
	case 1: cout << endl << "Ile masz lat?" << endl;
		wiek = pobierz_odpowiedz(16);
		cout << endl << "Jakiej jestes p�ci?" << endl;
		cout << "1 - kobieta, 2 - m�czyzna" << endl;
		plec = pobierz_odpowiedz(1, 2);
		Plec = (plec == 1 ? kobieta: mezczyzna);
		break;
	case 2: cout << endl << "Ile dziecko ma lat?" << endl;
		wiek = pobierz_odpowiedz(0, 15);
		int wiek_w_miesiacach = -1;
		if (wiek <= 2)
		{
			cout << endl << "Podaj ile miesi�cy ma dziecko." << endl;
			wiek_w_miesiacach = pobierz_odpowiedz(0, 24);
		}
		cout << endl << "Jakiej dziecko jest p�ci?" << endl;
		cout << "1 - dziewczynka, 2 - ch�opiec" << endl;
		plec = pobierz_odpowiedz(1, 2);
		Plec = (plec == 1 ? kobieta : mezczyzna);
		break;
	}
}

int pobierz_odpowiedz(int dolna_granica, int gorna_granica)
{
	int odpowiedz;
	while (scanf_s("%d", &odpowiedz) != 1 || odpowiedz < dolna_granica || odpowiedz > gorna_granica || getchar() != '\n')
	{
		cout << "Podaj liczb� naturaln�, kt�ra jest wi�ksza lub r�wna " << dolna_granica << " i mniejsza lub r�wna " << gorna_granica << "." << endl;
		while (getchar() != '\n');
	}
	return odpowiedz;
}

int pobierz_odpowiedz(int dolna_granica)
{
	int odpowiedz;
	while (scanf_s("%d", &odpowiedz) != 1 || odpowiedz < dolna_granica || getchar() != '\n')
	{
		cout << "Podaj liczb� naturaln�, kt�ra jest wi�ksza lub r�wna " << dolna_granica << "." << endl;
		while (getchar() != '\n');
	}
	return odpowiedz;
}
