#pragma once
#include <stdio.h>
#include <iostream>
#include "badanie.h"
#include <vector>
#include <fstream>
#include "konwerter.h"
#include "uzytkownik.h"

using namespace std;

void ekran_powitalny();

int main()
{
	setlocale(LC_ALL, "polish");
	ekran_powitalny();
	uzytkownik Uzytkownik;
	Uzytkownik.pytania_ogolne();
	Uzytkownik.odsiew_ryzyko();
	Uzytkownik.odsiew_etap();
	Uzytkownik.odsiew_czas();
	Uzytkownik.proponowane_badania();
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