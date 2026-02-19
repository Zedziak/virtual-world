#include <Windows.h>
#include <fstream>

#include "Swiat.h"
#include "Generator.h"
#include "Organizm.h"

#include "Czlowiek.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"

#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"

#define GATUNKI 10
#define MIEJSCA 20

using namespace std;

Generator::Generator(Swiat* world) {
	swiat = world;
}

void Generator::generujSwiat() {
	int w = swiat->GetWidth();
	int h = swiat->GetHeight();
	int orgPerGatunek = (w*h) / (GATUNKI + MIEJSCA);
	int* ileOrganizmow = new int[orgPerGatunek * (GATUNKI + 1)];
	this->wybierzLokalizacje(ileOrganizmow, &orgPerGatunek);
	int j = 0;
	int x = ileOrganizmow[j] % w;
	int y = (ileOrganizmow[j++] - x) / w;
	Organizm* gracz = new Czlowiek(x, y, swiat);
	swiat->dodajOrganizm(gracz);
	int i = 0;
	while (i < orgPerGatunek) {
		odczytajLokalizacje(ileOrganizmow, &x, &y, &j);
		Organizm* wilk = new Wilk(x, y, swiat);
		swiat->dodajOrganizm(wilk);

		odczytajLokalizacje(ileOrganizmow, &x, &y, &j);
		Organizm* owca = new Owca(x, y, swiat);
		swiat->dodajOrganizm(owca);

		odczytajLokalizacje(ileOrganizmow, &x, &y, &j);
		Organizm* lis = new Lis(x, y, swiat);
		swiat->dodajOrganizm(lis);

		odczytajLokalizacje(ileOrganizmow, &x, &y, &j);
		Organizm* zolw = new Zolw(x, y, swiat);
		swiat->dodajOrganizm(zolw);

		odczytajLokalizacje(ileOrganizmow, &x, &y, &j);
		Organizm* antylopa = new Antylopa(x, y, swiat);
		swiat->dodajOrganizm(antylopa);

		odczytajLokalizacje(ileOrganizmow, &x, &y, &j);
		Organizm* trawa = new Trawa(x, y, swiat);
		swiat->dodajOrganizm(trawa);

		odczytajLokalizacje(ileOrganizmow, &x, &y, &j);
		Organizm* mlecz = new Mlecz(x, y, swiat);
		swiat->dodajOrganizm(mlecz);

		odczytajLokalizacje(ileOrganizmow, &x, &y, &j);
		Organizm* guarana = new Guarana(x, y, swiat);
		swiat->dodajOrganizm(guarana);

		odczytajLokalizacje(ileOrganizmow, &x, &y, &j);
		Organizm* jagoda = new WilczeJagody(x, y, swiat);
		swiat->dodajOrganizm(jagoda);

		odczytajLokalizacje(ileOrganizmow, &x, &y, &j);
		Organizm* barszcz = new BarszczSosnowskiego(x, y, swiat);
		swiat->dodajOrganizm(barszcz);
		i++;
	}
}

void Generator::wybierzLokalizacje(int* lokalizacja, int* orgPerGatunek) {
	int w = swiat->GetWidth();
	int h = swiat->GetHeight();
	int genOrg = (*orgPerGatunek) * GATUNKI + 1;
	int* mapa = new int[w * h];
	int i = 0;
	while (i < w * h) {
		mapa[i++] = 0;
	}
	i = 0;
	while (i < genOrg) {
		int spawn;
		do {
			spawn = rand() % (w * h);
		} while (mapa[spawn] == 1);
		mapa[spawn] = 1;
		lokalizacja[i++] = spawn;
	}
}

void Generator::odczytajLokalizacje(int* lokalizacja, int* x, int* y, int* index) {
	int n = swiat->GetWidth();
	*x = lokalizacja[*index] % n;
	*y = (lokalizacja[*index] - *x) / n;
	(*index)++;
}

void Generator::zapiszSwiat() {
	ofstream zapis("dane.txt");

	int liczbaOrg = swiat->GetLiczbaOrg();
	zapis << swiat->GetWidth() << " " << swiat->GetHeight() << " " << swiat->GetTura() << " " << liczbaOrg << endl;
	Organizm* org = nullptr;
	for (int i = 0; i < liczbaOrg; i++)
	{
		org = swiat->GetOrganizm(i);
		zapis << org->Zapisz() << endl;
	}
	zapis.close();
	cout << "Stan gry zapisano" << endl;
}

bool Generator::wczytajSwiat() {
	bool result = true;
	const string plik = "dane.txt";
	ifstream odczyt(plik.c_str());
	if (odczyt.good()) {
		int n, m, tura, liczbaOrg;
		odczyt >> n >> m >> tura >> liczbaOrg;
		swiat->SetRozmiar(n, m);
		swiat->SetTura(tura);

		string nazwa, nazwa2;
		int sila, inicjatywa, x, y, wiek, umiejetnoscAktywowana, turyZUmiejetnoscia;
		bool aktywowana;

		int i = 0;
		while (i < liczbaOrg) {
			odczyt >> nazwa;
			if (nazwa == "Wilcze" || nazwa == "Barszcz") {
				odczyt >> nazwa2;
				nazwa += " " + nazwa2;
			}
			odczyt >> sila >> inicjatywa >> x >> y >> wiek;
			if (nazwa == "Czlowiek") {
				odczyt >> umiejetnoscAktywowana >> turyZUmiejetnoscia;
				Organizm* org = new Czlowiek(x - 1, y - 1, swiat);
				org->SetSila(sila);
				org->SetInicjatywa(inicjatywa);
				org->SetWiek(wiek);
				if (umiejetnoscAktywowana == 0) 
					aktywowana = false;
				else
					aktywowana = true;
				swiat->dodajOrganizm(org);
				swiat->GetCzlowiek()->SetCzyUmiejetnoscAktywowana(aktywowana);
				swiat->GetCzlowiek()->SetTuryObecnegoStanuUmiejetnosci(turyZUmiejetnoscia);
			}
			else {
				wczytajOrganizm(nazwa, sila, inicjatywa, x - 1, y - 1, wiek);
			}
			i++;
		}

		odczyt.close();
		cout << "Wczytano zapis gry" << endl;
	}
	else {
		cout << "Nie znaleziono pliku" << endl;
		result = false;
	}
	Sleep(2000);
	return result;
}

void Generator::wczytajOrganizm(string nazwa, int sila, int ini, int x, int y, int wiek)
{
	Organizm* org = nullptr;
	if (nazwa == "Wilk") {
		org = new Wilk(x, y, swiat);
	}
	else if (nazwa == "Owca") {
		org = new Owca(x, y, swiat);
	}
	else if (nazwa == "Lis") {
		org = new Lis(x, y, swiat);
	}
	else if (nazwa == "Zolw") {
		org = new Zolw(x, y, swiat);
	}
	else if (nazwa == "Antylopa") {
		org = new Antylopa(x, y, swiat);
	}
	else if (nazwa == "Trawa") {
		org = new Trawa(x, y, swiat);
	}
	else if (nazwa == "Mlecz") {
		org = new Mlecz(x, y, swiat);
	}
	else if (nazwa == "Guarana") {
		org = new Guarana(x, y, swiat);
	}
	else if (nazwa == "Barszcz Sosnowskiego") {
		org = new BarszczSosnowskiego(x, y, swiat);
	}
	else if (nazwa == "Wilcze Jagody") {
		org = new WilczeJagody(x, y, swiat);
	}

	if (org != nullptr) {
		org->SetSila(sila);
		org->SetInicjatywa(ini);
		org->SetWiek(wiek);
		swiat->dodajOrganizm(org);
	}
	else {
		cout << "Wczytywanie organizmu nie powiodlo sie: " << nazwa << endl;
	}
}

Generator::~Generator() {
	delete swiat;
}
