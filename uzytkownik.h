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
	void set_plec(PLEC plec);
private:
	vector<badanie*> badania;
	bool odpowiedz_za_dziecko;
	int wiek_w_miesiacach;
	PLEC plec;
	vector<badanie*> wyszukaj_badania(int wiek, PLEC plec); //wyszukuje badania w pliku kobiety.txt lub mezczyzni.txt
	vector<badanie*> wyszukaj_badania(int wiek); //wyszukuje badania w pliku wiek.txt
	vector<badanie*> wyszukaj_badania(); //wyszukuje badania w pliku wszyscy.txt
	konwerter Konwerter;
	int pobierz_odpowiedz(int dolna_granica, int gorna_granica);
	int pobierz_odpowiedz(int dolna_granica);
	void usuniecie_powielonych_badan();
};