#pragma once
#include "badanie.h"
#include <vector>
#include "konwerter.h"
class uzytkownik
{
public:
	void pytania_ogolne();
	void odsiew_ryzyko();
	void odsiew_etap();
	void odsiew_czas();
	void proponowane_badania();
	vector<badanie*> badania;
private:
	bool odpowiedz_za_dziecko;
	int wiek_w_miesiacach;
	vector<badanie*> wyszukaj_badania(int wiek, PLEC plec);
	vector<badanie*> wyszukaj_badania(int wiek);
	vector<badanie*> wyszukaj_badania();
	konwerter Konwerter;
	int pobierz_odpowiedz(int dolna_granica, int gorna_granica);
	int pobierz_odpowiedz(int dolna_granica);
};