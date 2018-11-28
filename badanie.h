#pragma once
#include <string>
#define N 50
using namespace std;

enum PLEC {kobieta, mezczyzna};
enum SZKOLA {przedszkole, podstawowa, ponadpodstawowa};
enum KLASA {I, II, III, IV, V, VI, VII, VIII};

class badanie
{
public:
	badanie(int wiek, string nazwa_badania, int co_ile_wykonywac, bool istnieja_czynniki_ryzyka, bool etap_edukacji);
	badanie(string nazwa_badania, int co_ile_wykonywac, bool istnieja_czynniki_ryzyka, bool etap_edukacji);
	void set_czynniki_ryzyka(string czynniki_ryzyka[N], int ilosc);
	string* get_czynniki_ryzyka();
	string get_nazwa();
	int get_ilosc_czynnikow();
	bool get_etap();
	SZKOLA get_szkola();
	KLASA get_klasa();
	void set_etap(SZKOLA Szkola, KLASA Klasa);
	int co_ile_wykonywac();
private:
	PLEC plec;
	int wiek;
	int wiek_w_miesiacach;
	int ilosc_czynnikow;
	string nazwa_badania;
	int co_ile_czasu_wykonywac; //w miesi¹cach
	bool istnieja_czynniki_ryzyka; //true jeœli badanie jest zale¿ne od jakichœ czynników ryzyka, false w przeciwnym przypadku
	string czynniki_ryzyka[N];
	string pytanie_kiedy_bylo_ostatnie_badanie;
	bool etap_edukacji; //true jeœli badanie zale¿y od etapu edukacji
	SZKOLA szkola;
	KLASA klasa;
};