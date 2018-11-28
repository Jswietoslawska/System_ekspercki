#include "konwerter.h"
#include <iostream>
using namespace std;
bool konwerter::wiek_w_przedziale(string znak, int liczba1, int liczba2, int wiek)
{
	if (znak == "-")
	{
		if (wiek >= liczba1 && wiek <= liczba2)
		{
			return true;
		}
	}
	else
	{
		cout << "Wyst¹pi³ b³¹d";
	}
	return false;
}

bool konwerter::wiek_w_przedziale(string znak, int liczba1, int wiek)
{
	if (znak == ">")
	{
		if (wiek > liczba1)
			return true;
		else
			return false;
	}
	else if (znak == "<")
	{
		if (wiek < liczba1)
			return true;
		else
			return false;
	}
	else if (znak == "=")
	{
		if (wiek == liczba1)
			return true;
		else
			return false;
	}
	else if (znak == ">=")
	{
		if (wiek >= liczba1)
			return true;
		else
			return false;
	}
	else if (znak == "<=")
	{
		if (wiek <= liczba1)
			return true;
		else
			return false;
	}
	else
	{
		cout << "Wyst¹pi³ b³¹d";
	}
	return false;
}

bool konwerter::wystepowanie_czynnikow_ryzyka(string ryzyko)
{
	if (ryzyko == "R")
		return true;
	else if (ryzyko == "N")
		return false;
	else
		cout << "Wyst¹pi³ b³¹d";
	return false;
}

bool konwerter::wystepowanie_etapu_szkolnego(string etap)
{
	if (etap == "E")
		return true;
	else if (etap == "N")
		return false;
	else
		cout << "Wyst¹pi³ b³¹d";
	return false;
}

SZKOLA konwerter::jaka_szkola(string szkola)
{
	if (szkola == "przedszkole")
		return przedszkole;
	else if (szkola == "podstawowa")
		return podstawowa;
	else if (szkola == "ponadpostawowa")
		return ponadpodstawowa;
	else
		cout << "Wyst¹pi³ b³¹d";
}

KLASA konwerter::jaka_klasa(string klasa)
{
	if (klasa == "I")
		return I;
	else if (klasa == "II")
		return II;
	else if (klasa == "III")
		return III;
	else if (klasa == "IV")
		return IV;
	else if (klasa == "V")
		return V;
	else if (klasa == "VI")
		return VI;
	else if (klasa == "VII")
		return VII;
	else if (klasa == "VIII")
		return VIII;
	else
		cout << "Wyst¹pi³ b³¹d";
}

string konwerter::jaka_szkola(SZKOLA szkola)
{
	if (szkola == przedszkole)
		return "przedszkole";
	else if (szkola == podstawowa)
		return "podstawowa";
	else if (szkola == ponadpodstawowa)
		return "ponadpostawowa";
	else
		cout << "Wyst¹pi³ b³¹d";
}
string konwerter::jaka_klasa(KLASA klasa)
{
	if (klasa == I)
		return "I";
	else if (klasa == II)
		return "II";
	else if (klasa == III)
		return "III";
	else if (klasa == IV)
		return "IV";
	else if (klasa == V)
		return "V";
	else if (klasa == VI)
		return "VI";
	else if (klasa == VII)
		return "VII";
	else if (klasa == VIII)
		return "VIII";
	else
		cout << "Wyst¹pi³ b³¹d";
}

bool konwerter::czy_wiek_w_miesiacach(string znak)
{
	if (znak == "m")
		return true;
	else
		return false;
}