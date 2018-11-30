#include "uzytkownik.h"
#include <fstream>
#include <iostream>
#include "konwerter.h"
using namespace std;

vector<badanie*> uzytkownik::wyszukaj_badania(int wiek, PLEC plec)
{
	string nazwa_pliku;
	vector<badanie*> badania;
	if (plec == kobieta)
		nazwa_pliku = "kobiety.txt";
	else
		nazwa_pliku = "mezczyzni.txt";
	ifstream plik(nazwa_pliku);
	if (plik)
	{
		while (!plik.eof())
		{
			string badanie_znak;
			int liczba1;
			int liczba2;
			bool w_przedziale;
			plik >> badanie_znak;
			if (Konwerter.czy_wiek_w_miesiacach(badanie_znak)&&wiek<=2&&wiek_w_miesiacach!=-1)
			{
				badanie_znak.clear();
				plik >> badanie_znak;
				if (badanie_znak == "-")
				{
					plik >> liczba1;
					plik >> liczba2;
					w_przedziale = Konwerter.wiek_w_przedziale(badanie_znak, liczba1, liczba2, wiek_w_miesiacach);
				}
				else
				{

					plik >> liczba1;
					w_przedziale = Konwerter.wiek_w_przedziale(badanie_znak, liczba1, wiek_w_miesiacach);
				}
			}
			else if (Konwerter.czy_wiek_w_miesiacach(badanie_znak))
			{
				string tekst;
				getline(plik, tekst);
				continue;
			}
			else
			{
				if (badanie_znak == "-")
				{
					plik >> liczba1;
					plik >> liczba2;
					w_przedziale = Konwerter.wiek_w_przedziale(badanie_znak, liczba1, liczba2, wiek);
				}
				else
				{
					plik >> liczba1;
					w_przedziale = Konwerter.wiek_w_przedziale(badanie_znak, liczba1, wiek);
				}
			}
			if (w_przedziale)
			{
				string ryzyko;
				plik >> ryzyko;
				string czynniki[50];
				bool czynniki_ryzyka;
				int i = 0;
				if (czynniki_ryzyka = Konwerter.wystepowanie_czynnikow_ryzyka(ryzyko))
				{
					string tekst;
					getline(plik, tekst, '#');
					while (tekst[0] != '%')
					{
						czynniki[i] = tekst;
						getline(plik, tekst, '#');
						i++;
					}
				}
				bool etap = false;
				SZKOLA szkola;
				KLASA klasa;
				string etap_szkolny;
				plik >> etap_szkolny;
				if (etap = Konwerter.wystepowanie_etapu_szkolnego(etap_szkolny))
				{
					string etap_szkola;
					plik >> etap_szkola;
					szkola = Konwerter.jaka_szkola(etap_szkola);
					if (szkola != przedszkole)
					{
						string etap_klasa;
						plik >> etap_klasa;
						klasa = Konwerter.jaka_klasa(etap_klasa);
					}
				}
				int ilosc_miesiecy;
				plik >> ilosc_miesiecy;
				string nazwa;
				getline(plik, nazwa);
				badanie *Badanie = new badanie(wiek, nazwa, ilosc_miesiecy, czynniki_ryzyka, etap);
				Badanie->set_czynniki_ryzyka(czynniki, i);
				if (etap)
					Badanie->set_etap(szkola, klasa);
				badania.push_back(Badanie);
			}
			else
			{
				string tekst;
				getline(plik, tekst);
			}
		}
		plik.close();
	}
	else
	{
		cout << "Wyst�pi� b��d przy otwieraniu pliku";
	}
	return badania;
}

vector<badanie*> uzytkownik::wyszukaj_badania(int wiek)
{
	string nazwa_pliku;
	vector<badanie*> badania;
	nazwa_pliku = "wiek.txt";
	ifstream plik(nazwa_pliku);
	if (plik)
	{
		while (!plik.eof())
		{
			string badanie_znak;
			int liczba1;
			int liczba2;
			bool w_przedziale;
			plik >> badanie_znak;
			if (Konwerter.czy_wiek_w_miesiacach(badanie_znak) && wiek <= 2 && wiek_w_miesiacach != -1)
			{
				badanie_znak.clear();
				plik >> badanie_znak;
				if (badanie_znak == "-")
				{
					plik >> liczba1;
					plik >> liczba2;
					w_przedziale = Konwerter.wiek_w_przedziale(badanie_znak, liczba1, liczba2, wiek_w_miesiacach);
				}
				else
				{

					plik >> liczba1;
					w_przedziale = Konwerter.wiek_w_przedziale(badanie_znak, liczba1, wiek_w_miesiacach);
				}
			}
			else if (Konwerter.czy_wiek_w_miesiacach(badanie_znak))
			{
				string tekst;
				getline(plik, tekst);
				continue;
			}
			else
			{
				if (badanie_znak == "-")
				{
					plik >> liczba1;
					plik >> liczba2;
					w_przedziale = Konwerter.wiek_w_przedziale(badanie_znak, liczba1, liczba2, wiek);
				}
				else
				{
					plik >> liczba1;
					w_przedziale = Konwerter.wiek_w_przedziale(badanie_znak, liczba1, wiek);
				}
			}
			if (w_przedziale)
			{
				string ryzyko;
				plik >> ryzyko;
				string czynniki[50];
				bool czynniki_ryzyka;
				int i = 0;
				if (czynniki_ryzyka = Konwerter.wystepowanie_czynnikow_ryzyka(ryzyko))
				{
					string tekst;
					getline(plik, tekst, '#');
					while (tekst[0] != '%')
					{
						czynniki[i] = tekst;
						getline(plik, tekst, '#');
						i++;
					}
				}
				bool etap = false;
				SZKOLA szkola;
				KLASA klasa;
				string etap_szkolny;
				plik >> etap_szkolny;
				if (etap = Konwerter.wystepowanie_etapu_szkolnego(etap_szkolny))
				{
					string etap_szkola;
					plik >> etap_szkola;
					szkola = Konwerter.jaka_szkola(etap_szkola);
					if (szkola != przedszkole)
					{
						string etap_klasa;
						plik >> etap_klasa;
						klasa = Konwerter.jaka_klasa(etap_klasa);
					}
				}
				int ilosc_miesiecy;
				plik >> ilosc_miesiecy;
				string nazwa;
				getline(plik, nazwa);
				badanie *Badanie = new badanie(wiek, nazwa, ilosc_miesiecy, czynniki_ryzyka, etap);
				Badanie->set_czynniki_ryzyka(czynniki, i);
				if (etap)
					Badanie->set_etap(szkola, klasa);
				badania.push_back(Badanie);
			}
			else
			{
				string tekst;
				getline(plik, tekst);
			}
		}
		plik.close();
	}
	else
	{
		cout << "Wyst�pi� b��d przy otwieraniu pliku";
	}
	return badania;
}

vector<badanie*> uzytkownik::wyszukaj_badania()
{
	string nazwa_pliku;
	vector<badanie*> badania;
	nazwa_pliku = "wszyscy.txt";
	ifstream plik(nazwa_pliku);
	if (plik)
	{
		while (!plik.eof())
		{
			string ryzyko;
			plik >> ryzyko;
			string czynniki[50];
			bool czynniki_ryzyka;
			int i = 0;
			if (czynniki_ryzyka = Konwerter.wystepowanie_czynnikow_ryzyka(ryzyko))
			{
				string tekst;
				getline(plik, tekst, '#');
				while (tekst[0] != '%')
				{
					czynniki[i] = tekst;
					getline(plik, tekst, '#');
					i++;
				}
			}
			bool etap = false;
			SZKOLA szkola;
			KLASA klasa;
			string etap_szkolny;
			plik >> etap_szkolny;
			if (etap = Konwerter.wystepowanie_etapu_szkolnego(etap_szkolny))
			{
				string etap_szkola;
				plik >> etap_szkola;
				szkola = Konwerter.jaka_szkola(etap_szkola);
				if (szkola != przedszkole)
				{
					string etap_klasa;
					plik >> etap_klasa;
					klasa = Konwerter.jaka_klasa(etap_klasa);
				}
			}
			int ilosc_miesiecy;
			plik >> ilosc_miesiecy;
			string nazwa;
			getline(plik, nazwa);
			badanie *Badanie = new badanie(nazwa, ilosc_miesiecy, czynniki_ryzyka, etap);
			Badanie->set_czynniki_ryzyka(czynniki, i);
			if (etap)
				Badanie->set_etap(szkola, klasa);
			badania.push_back(Badanie);
		}
		plik.close();
	}
	else
	{
		cout << "Wyst�pi� b��d przy otwieraniu pliku";
	}
	return badania;
}

void uzytkownik::pytania_ogolne()
{
	int odpowiedz = 0;
	int wiek, plec;
	PLEC Plec;
	cout << endl << "B�dziesz odpowiada� za siebie czy za dziecko (poni�ej 16 r. �.)?" << endl;
	cout << "1 - za siebie, 2 - za dziecko" << endl;
	odpowiedz = pobierz_odpowiedz(1, 2);
	odpowiedz_za_dziecko = (odpowiedz == 1 ? false : true);
	switch (odpowiedz)
	{
	case 1: cout << endl << "Ile masz sko�czonych lat?" << endl;
		wiek = pobierz_odpowiedz(16);
		cout << endl << "Jakiej jestes p�ci?" << endl;
		cout << "1 - kobieta, 2 - m�czyzna" << endl;
		plec = pobierz_odpowiedz(1, 2);
		Plec = (plec == 1 ? kobieta : mezczyzna);
		set_plec(Plec);
		break;
	case 2: cout << endl << "Ile dziecko ma sko�czonych lat?" << endl;
		wiek = pobierz_odpowiedz(0, 15);
		wiek_w_miesiacach = -1;
		if (wiek < 1)
		{
			cout << endl << "Podaj ile sko�czonych miesi�cy ma dziecko." << endl;
			wiek_w_miesiacach = pobierz_odpowiedz(0, 11);
		}
		else if (wiek >= 1 && wiek < 2)
		{
			cout << endl << "Podaj ile sko�czonych miesi�cy ma dziecko." << endl;
			wiek_w_miesiacach = pobierz_odpowiedz(12, 23);
		}
		cout << endl << "Jakiej dziecko jest p�ci?" << endl;
		cout << "1 - dziewczynka, 2 - ch�opiec" << endl;
		plec = pobierz_odpowiedz(1, 2);
		Plec = (plec == 1 ? kobieta : mezczyzna);
		set_plec(Plec);
		break;
	}
	vector<badanie*> badania_plec = wyszukaj_badania(wiek, Plec);
	for (vector<badanie*>::iterator it = badania_plec.begin(); it != badania_plec.end(); it++)
		badania.push_back(*it);
	vector<badanie*> badania_wiek = wyszukaj_badania(wiek);
	for (vector<badanie*>::iterator it = badania_wiek.begin(); it != badania_wiek.end(); it++)
		badania.push_back(*it);
	vector<badanie*> badania_ogol = wyszukaj_badania();
	for (vector<badanie*>::iterator it = badania_ogol.begin(); it != badania_ogol.end(); it++)
		badania.push_back(*it);
}

int uzytkownik:: pobierz_odpowiedz(int dolna_granica, int gorna_granica)
{
	int odpowiedz;
	while (scanf_s("%d", &odpowiedz) != 1 || odpowiedz < dolna_granica || odpowiedz > gorna_granica || getchar() != '\n')
	{
		cout << "Podaj liczb� naturaln�, kt�ra jest wi�ksza lub r�wna " << dolna_granica << " i mniejsza lub r�wna " << gorna_granica << "." << endl;
		while (getchar() != '\n');
	}
	return odpowiedz;
}

int uzytkownik:: pobierz_odpowiedz(int dolna_granica)
{
	int odpowiedz;
	while (scanf_s("%d", &odpowiedz) != 1 || odpowiedz < dolna_granica || getchar() != '\n')
	{
		cout << "Podaj liczb� naturaln�, kt�ra jest wi�ksza lub r�wna " << dolna_granica << "." << endl;
		while (getchar() != '\n');
	}
	return odpowiedz;
}

void uzytkownik::odsiew_ryzyko()
{
	vector<badanie*> po_odsiewie;
	if (odpowiedz_za_dziecko)
	{
		vector<badanie*>::iterator IT = badania.begin();
		for (; IT != badania.end(); IT++)
		{
			int i = (*IT)->get_ilosc_czynnikow();
			if (i != 0)
			{
				cout << "Czy Twojego dziecka dotyczy kt�rykolwiek z wymienionych czynnik�w?" << endl;
				string *czynniki = (*IT)->get_czynniki_ryzyka();
				for (int j = 0; j < i; j++)
				{
					cout << j + 1 << ". " << czynniki[j] << endl;
				}
				cout << "1 - tak, 2 - nie" << endl;
				int odpowiedz = pobierz_odpowiedz(1, 2);
				if (odpowiedz == 1)
				{
					po_odsiewie.push_back(*IT);
				}
			}
			else
				po_odsiewie.push_back(*IT);
		}
	}
	else
	{
		vector<badanie*>::iterator IT = badania.begin();
		for (; IT != badania.end(); IT++)
		{
			int i = (*IT)->get_ilosc_czynnikow();
			if(i!=0)
			{
				cout << "Czy dotyczy Ci� kt�rykolwiek z wymienionych czynnik�w?" << endl;
				string *czynniki = (*IT)->get_czynniki_ryzyka();
				for (int j = 0; j < i; j++)
				{
					cout << j + 1 << ". " << czynniki[j] << endl;
				}
				cout << "1 - tak, 2 - nie" << endl;
				int odpowiedz = pobierz_odpowiedz(1, 2);
				if (odpowiedz == 1)
				{
					po_odsiewie.push_back(*IT);
				}
			}
			else
				po_odsiewie.push_back(*IT);
		}
	}
	badania.clear();
	for (vector<badanie*>::iterator it = po_odsiewie.begin(); it != po_odsiewie.end(); it++)
		badania.push_back(*it);
}

void uzytkownik::odsiew_etap()
{
	vector<badanie*> po_odsiewie;
	if (odpowiedz_za_dziecko)
	{
		vector<badanie*>::iterator IT = badania.begin();
		for (; IT != badania.end(); IT++)
		{
			bool etap = (*IT)->get_etap();
			if (etap)
			{
				cout << "Czy Twojego dziecko znajduje si� na podanym etapie edukacji?" << endl;
				if ((*IT)->get_szkola() != przedszkole)
				{
					cout << "Szko�a " << Konwerter.jaka_szkola((*IT)->get_szkola()) << ", klasa " << Konwerter.jaka_klasa((*IT)->get_klasa()) << endl;
				}
				else
				{
					cout << "Przedszkole" << endl;
				}
				cout << "Je�li dziecko powtarza klas� (lub jest w przedszkolu d�u�ej ni� rok)" << endl;
				cout << "i na tym etapie edukacji znajduje si� wi�cej ni� rok znaznacz \"nie\"." << endl;
				cout << "1 - tak, 2 - nie" << endl;
				int odpowiedz = pobierz_odpowiedz(1, 2);
				if (odpowiedz == 1)
				{
					po_odsiewie.push_back(*IT);
				}
			}
			else
				po_odsiewie.push_back(*IT);
		}
	}
	else
	{
		vector<badanie*>::iterator IT = badania.begin();
		for (; IT != badania.end(); IT++)
		{
			bool etap = (*IT)->get_etap();
			if (etap)
			{
				cout << "Czy znajdujesz si� na podanym etapie edukacji?" << endl;
				if ((*IT)->get_szkola() != przedszkole)
				{
					cout << "Szko�a " << Konwerter.jaka_szkola((*IT)->get_szkola()) << ", klasa " << Konwerter.jaka_klasa((*IT)->get_klasa()) << endl;
				}
				cout << "Je�li powtarzasz klas� i znajdujesz si� na tym etapie edukacji wi�cej ni� rok znaznacz \"nie\"." << endl;
				cout << "1 - tak, 2 - nie" << endl;
				int odpowiedz = pobierz_odpowiedz(1, 2);
				if (odpowiedz == 1)
				{
					po_odsiewie.push_back(*IT);
				}
			}
			else
				po_odsiewie.push_back(*IT);
		}
	}
	badania.clear();
	for (vector<badanie*>::iterator it = po_odsiewie.begin(); it != po_odsiewie.end(); it++)
		badania.push_back(*it);
}

void uzytkownik::odsiew_czas()
{
	usuniecie_powielonych_badan();
	vector<badanie*> po_odsiewie;
	if (odpowiedz_za_dziecko)
	{
		vector<badanie*>::iterator IT = badania.begin();
		for (; IT != badania.end(); IT++)
		{
			int czas = (*IT)->co_ile_wykonywac();
			if (czas)
			{
				if(czas == 1)
					cout << "Czy w ci�gu ostatniego miesi�ca" << endl;
				else if (czas >= 24)
					cout << "Czy w ci�gu ostatnich " << ((*IT)->co_ile_wykonywac())/12 << " lat" << endl;
				else
					cout << "Czy w ci�gu ostatnich " << (*IT)->co_ile_wykonywac() << " miesi�cy" << endl;
				cout << "Twoje dziecko mia�o wykonane " << (*IT)->get_nazwa() << "?" << endl;
				cout << "Je�li nie pami�tasz zaznacz \"nie\"." << endl;
				cout << "1 - tak, 2 - nie" << endl;
				int odpowiedz = pobierz_odpowiedz(1, 2);
				if (odpowiedz == 2)
				{
					po_odsiewie.push_back(*IT);
				}
			}
			else
			{
				cout << "Czy Twoje dziecko mia�o wykonane " << (*IT)->get_nazwa() << "?" << endl;
				cout << "Je�li nie pami�tasz zaznacz \"nie\"." << endl;
				cout << "1 - tak, 2 - nie" << endl;
				int odpowiedz = pobierz_odpowiedz(1, 2);
				if (odpowiedz == 2)
				{
					po_odsiewie.push_back(*IT);
				}
			}
		}
	}
	else
	{
		vector<badanie*>::iterator IT = badania.begin();
		for (; IT != badania.end(); IT++)
		{
			int czas = (*IT)->co_ile_wykonywac();
			if (czas)
			{
				if (czas == 1)
					cout << "Czy w ci�gu ostatniego miesi�ca" << endl;
				else if (czas >= 24)
					cout << "Czy w ci�gu ostatnich " << ((*IT)->co_ile_wykonywac())/12 << " lat" << endl;
				else
					cout << "Czy w ci�gu ostatnich " << (*IT)->co_ile_wykonywac() << " miesi�cy" << endl;
				if (plec == kobieta)
				{
					cout << "mia�a� wykonywane " << (*IT)->get_nazwa() << "?" << endl;
				}
				else
				{
					cout << "mia�e� wykonywane " << (*IT)->get_nazwa() << "?" << endl;
				}
				cout << "Je�li nie pami�tasz zaznacz \"nie\"." << endl;
				cout << "1 - tak, 2 - nie" << endl;
				int odpowiedz = pobierz_odpowiedz(1, 2);
				if (odpowiedz == 2)
				{
					po_odsiewie.push_back(*IT);
				}
			}
			else
			{
				if (plec == kobieta)
				{
					cout << "Czy mia�a� wykonane " << (*IT)->get_nazwa() << "?" << endl;
				}
				else
				{
					cout << "Czy mia�e� wykonane " << (*IT)->get_nazwa() << "?" << endl;
				}
				cout << "Je�li nie pami�tasz zaznacz \"nie\"." << endl;
				cout << "1 - tak, 2 - nie" << endl;
				int odpowiedz = pobierz_odpowiedz(1, 2);
				if (odpowiedz == 2)
				{
					po_odsiewie.push_back(*IT);
				}
			}
		}
	}
	badania.clear();
	for (vector<badanie*>::iterator it = po_odsiewie.begin(); it != po_odsiewie.end(); it++)
		badania.push_back(*it);
}

void uzytkownik::proponowane_badania()
{
	vector<badanie*>::iterator IT = badania.begin();
	if (badania.empty())
	{
		cout << "Brak proponowanych bada� profilaktycznych, bilans�w i szczepie�." << endl;
	}
	else
	{
		if (odpowiedz_za_dziecko)
		{
			cout << "Proponowane badania profilaktyczne, bilanse i szczepienia dla Twojego dziecka:" << endl;
			for (int i=0; IT != badania.end(); IT++, i++)
			{
				cout << i + 1 << ". " << (*IT)->get_nazwa() << endl;
			}
			cout << "Pami�taj, �e przed ka�dym szczepieniem obowi�zkowa jest konsultacja z lekarzem." << endl;
		}
		else
		{
			cout << "Proponowane badania profilaktyczne, bilanse i szczepienia dla Ciebie:" << endl;
			for (int i = 0; IT != badania.end(); IT++, i++)
			{
				cout << i + 1 << ". " << (*IT)->get_nazwa() << endl;
			}
			cout << "Pami�taj, �e przed ka�dym szczepieniem obowi�zkowa jest konsultacja z lekarzem." << endl;
		}
	}
}

void uzytkownik::set_plec(PLEC Plec)
{
	plec = Plec;
}

void uzytkownik::usuniecie_powielonych_badan()
{
	vector<badanie*> po_odsiewie;
	vector<badanie*>::iterator IT = badania.begin();
	vector<badanie*>::iterator it = badania.begin();
	bool powielone = false;
	bool dodaj_powielone = false;
	for (int i = 0; IT != badania.end(); IT++, i++)
	{
		int j;
		for (j = 0, it = badania.begin(); it != badania.end(); it++, j++)
		{
			if (j!=i&&(*IT)->get_nazwa() == (*it)->get_nazwa())
			{
				powielone = true;
				if ((*IT)->co_ile_wykonywac() < (*it)->co_ile_wykonywac())
				{
					dodaj_powielone = true;
				}
				else
				{
					dodaj_powielone = false;
				}
			}
		}
		if (powielone == false || (powielone == true && dodaj_powielone == true))
		{
			po_odsiewie.push_back(*IT);
		}
		powielone = false;
	}
	badania.clear();
	for (vector<badanie*>::iterator it2 = po_odsiewie.begin(); it2 != po_odsiewie.end(); it2++)
		badania.push_back(*it2);
}