#include "badanie.h"
#include <iostream>

using namespace std;

badanie::badanie(int Wiek, string Nazwa_badania, int Co_ile_wykonywac, bool Istnieja_czynniki_ryzyka = false, bool Etap_edukacji = false) :
	 wiek(Wiek), nazwa_badania(Nazwa_badania), co_ile_czasu_wykonywac(Co_ile_wykonywac), istnieja_czynniki_ryzyka(Istnieja_czynniki_ryzyka),
	etap_edukacji(Etap_edukacji), ilosc_czynnikow(0), wiek_w_miesiacach(-1)
{

}

badanie::badanie(string Nazwa_badania, int Co_ile_wykonywac, bool Istnieja_czynniki_ryzyka = false, bool Etap_edukacji = false) :
	nazwa_badania(Nazwa_badania), co_ile_czasu_wykonywac(Co_ile_wykonywac), istnieja_czynniki_ryzyka(Istnieja_czynniki_ryzyka),
	etap_edukacji(Etap_edukacji), ilosc_czynnikow(0), wiek_w_miesiacach(-1)
{

}

string badanie::get_nazwa()
{
	return nazwa_badania;
}

void badanie::set_czynniki_ryzyka(string Czynniki_ryzyka[N], int ilosc)
{
	ilosc_czynnikow = ilosc;
	for (int i = 0; i < ilosc; i++)
	{
		czynniki_ryzyka[i] = Czynniki_ryzyka[i];
	}
}

string* badanie::get_czynniki_ryzyka()
{
	return czynniki_ryzyka;
}

int badanie::get_ilosc_czynnikow()
{
	return ilosc_czynnikow;
}

bool badanie::get_etap()
{
	return etap_edukacji;
}
SZKOLA badanie::get_szkola()
{
	if (etap_edukacji)
		return szkola;
}
KLASA badanie::get_klasa()
{
	if (etap_edukacji)
		return klasa;
}
void badanie::set_etap(SZKOLA Szkola, KLASA Klasa)
{
	szkola = Szkola;
	klasa = Klasa;
}
int badanie::co_ile_wykonywac()
{
	return co_ile_czasu_wykonywac;
}