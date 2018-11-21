#pragma once
#include <string>
#define N 20
using namespace std;

enum PLEC {kobieta, mezczyzna};
enum SZKOLA {przedszkole, podstawowa, gimnazjum, ponadpodstawowa};
enum KLASA {I, II, III, IV, V, VI, VII, VIII};

class badanie
{
public:
	badanie(PLEC plec, int wiek, string nazwa_badania, int co_ile_wykonywac, bool wiek_w_latach, bool istnieja_czynniki_ryzyka, bool etap_edukacji);
	void set_czynniki_ryzyka(string czynniki_ryzyka[N]);
	string* get_czynniki_ryzyka();
private:
	PLEC plec;
	int wiek;
	bool wiek_w_latach; //false - je�li wiek jest podany w miesi�cach
	string nazwa_badania;
	int co_ile_czasu_wykonywac; //w miesi�cach
	bool istnieja_czynniki_ryzyka; //true je�li badanie jest zale�ne od jakich� czynnik�w ryzyka, false w przeciwnym przypadku
	string czynniki_ryzyka[N];
	bool etap_edukacji; //true je�li badanie zale�y od etapu edukacji
	SZKOLA szkola;
	KLASA klasa;
	string pytanie_kiedy_bylo_ostatnie_badanie;
};