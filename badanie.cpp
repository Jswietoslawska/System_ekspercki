#include "badanie.h"

using namespace std;

badanie::badanie(PLEC Plec, int Wiek, string Nazwa_badania, int Co_ile_wykonywac, bool Wiek_w_latach = true, 
	bool Istnieja_czynniki_ryzyka = false, bool Etap_edukacji = false) :
	plec(Plec), wiek(Wiek), nazwa_badania(Nazwa_badania), co_ile_czasu_wykonywac(Co_ile_wykonywac), wiek_w_latach(Wiek_w_latach),
	istnieja_czynniki_ryzyka(Istnieja_czynniki_ryzyka), etap_edukacji(Etap_edukacji)
{

}