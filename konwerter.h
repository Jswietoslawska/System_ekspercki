#pragma once
#include <string>
#include "badanie.h"
using namespace std;
class konwerter
{
public:
	bool wiek_w_przedziale(string znak, int liczba1, int liczba2, int wiek);
	bool wiek_w_przedziale(string znak, int liczba1, int wiek);
	bool wystepowanie_czynnikow_ryzyka(string ryzyko);
	bool wystepowanie_etapu_szkolnego(string etap);
	SZKOLA jaka_szkola(string szkola);
	KLASA jaka_klasa(string klasa);
	string jaka_szkola(SZKOLA szkola);
	string jaka_klasa(KLASA klasa);
	bool czy_wiek_w_miesiacach(string znak);
};