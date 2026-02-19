#include <conio.h>
#include <string>

#include "Organizm.h"
#include "Czlowiek.h"
#include "Swiat.h"

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

#define GORA 1
#define PRAWO 2
#define DOL 3
#define LEWO 4

using namespace std;

Swiat::Swiat() : Swiat(20, 20) {}

Swiat::Swiat(int w, int h) {
	width = w;
	height = h;

	liczbaOrg = 0;
	liczbaOrgBezNowych = 0;
	tura = 0;
	zycieCzlowieka = false;
	czlowiek = nullptr;
	organizmy = new Organizm* [w * h];
	mapa = new Organizm** [h + 2];
	komentarze = new string[5 * w * h];
	ileKomentarzy = 0;

	for (int y = 0; y < (height + 2); y++) {
		mapa[y] = new Organizm * [width + 2];
	}

	for (int y = 0; y < (height + 2); y++) {
		for (int x = 0; x < (width + 2); x++) {
			mapa[y][x] = nullptr;
		}
	}
}

int Swiat::GetWidth() const {
	return width;
}

int Swiat::GetHeight() const {
	return height;
}

int Swiat::GetLiczbaOrg() const {
	return liczbaOrg;
}

int Swiat::GetTura() const {
	return tura;
}

Organizm* Swiat::GetLokalizacja(int x, int y) const {
	if ((x > 0) && (x < (width + 2)) && (y > 0) && (y < (height + 2))) {
		return mapa[y][x];
	}
	return nullptr;
}

Organizm* Swiat::GetOrganizm(int i) const {
	return organizmy[i];
}

Czlowiek* Swiat::GetCzlowiek() const
{
	return czlowiek;
}

void Swiat::SetRozmiar(int w, int h) {
	width = w;
	height = h;
}

void Swiat::SetLokalizacja(int x, int y, Organizm* org) {
	mapa[y][x] = org;
}

void Swiat::SetTura(int n) {
	tura = n;
}

void Swiat::komentuj(string komentarz) {
	komentarze[ileKomentarzy] = komentarz;
	ileKomentarzy++;
}

void Swiat::dodajOrganizm(Organizm* org) {
	string komentarz;
	if ((liczbaOrg < width * height) && (mapa[org->GetY()][org->GetX()] == nullptr)) {
		organizmy[liczbaOrg] = org;
		liczbaOrg++;
		if (liczbaOrg > 1 && dynamic_cast<Zwierze*>(org)) {
			Organizm* tmp;
			int i = 0;
			while (i < liczbaOrg && organizmy[i]->GetInicjatywa() >= org->GetInicjatywa()) {
				i++;
			}
			for (int j = liczbaOrg - 2; j >= i; j--) {
				tmp = organizmy[j];
				organizmy[j] = organizmy[j + 1];
				organizmy[j + 1] = tmp;
			}
		}
		org->rysowanie();
		if (typeid(*org) == typeid(Czlowiek)) {
			zycieCzlowieka = true;
			czlowiek = dynamic_cast<Czlowiek*>(org);
		}
		komentarz = org->GetGatunek() + ": \tnarodziny nowego organizmu na polu (" + to_string(org->GetX()) + ", " + to_string(org->GetY()) + ")";
		this->komentuj(komentarz);
	}
	else if ((liczbaOrg < width * height) && (mapa[org->GetY()][org->GetX()] != nullptr)) {
		delete org;
	}
	else if (liczbaOrg >= width * height) {
		komentarz = "Brak miejsca na mapie";
		this->komentuj(komentarz);
	}
}

void Swiat::zniszczOrganizm(Organizm* org) {
	string komentarz;
	Organizm* temp;
	Organizm* atakowany;

	atakowany = mapa[org->GetY()][org->GetX()];
	if (atakowany == org) {
		mapa[org->GetY()][org->GetX()] = nullptr;
	}
	if (typeid(*org) == typeid(Czlowiek)) {
		zycieCzlowieka = false;
	}
	for (int i = 0; i < liczbaOrg; i++) {
		if (organizmy[i] == org) {
			organizmy[i] = nullptr;
			for (int j = i; j < liczbaOrg - 1; j++) {
				temp = organizmy[j];
				organizmy[j] = organizmy[j + 1];
				organizmy[j + 1] = temp;
			}
			i = liczbaOrg;
		}
	}
	liczbaOrg--;
	liczbaOrgBezNowych--;
	komentarz = org->GetGatunek() + ": smierc";
	this->komentuj(komentarz);
	delete org;
}

void Swiat::rysujSwiat() {
	cout << "Autor: Hubert Zedlewski 193339" << endl;
	cout << "Tura: " << tura << endl;
	cout << "Nowa gra - N" << endl;
	cout << "Zapisz - S" << endl;
	cout << "Rozegranie tury - V" << endl;

	int i = 0;
	while (i < liczbaOrg) {
		organizmy[i++]->rysowanie();
	}

	for (int y = 0; y < (height + 2); y++) {
		for (int x = 0; x < (width + 2); x++) {
			if (GetLokalizacja(x, y) == nullptr) {
				if ((x == 0) || (y == 0) || (x == width + 1) || (y == height + 1))
					cout << '#';
				else
					cout << ' ';
			}
			else {
				cout << GetLokalizacja(x, y)->GetAwatar();
			}
		}
		cout << endl;
	}
	cout << endl;
	i = 0;
	while (i < ileKomentarzy) {
		cout << komentarze[i++] << endl;
	}
	ileKomentarzy = 0;
}

void Swiat::generowaniePunktow(int x, int y, int* positionX, int* positionY, int* ruch, int* pointsCount) {
	if (y - 1 != 0 && mapa[y - 1][x] == nullptr) {
		positionX[*pointsCount] = x;
		positionY[*pointsCount] = y - 1;
		ruch[*pointsCount] = GORA;
		(*pointsCount)++;
	}
	if (x + 1 != width + 1 && mapa[y][x + 1] == nullptr) {
		positionX[*pointsCount] = x + 1;
		positionY[*pointsCount] = y;
		ruch[*pointsCount] = PRAWO;
		(*pointsCount)++;
	}
	if (y + 1 != height + 1 && mapa[y + 1][x] == nullptr) {
		positionX[*pointsCount] = x;
		positionY[*pointsCount] = y + 1;
		ruch[*pointsCount] = DOL;
		(*pointsCount)++;
	}
	if (x - 1 != 0 && mapa[y][x - 1] == nullptr) {
		positionX[*pointsCount] = x - 1;
		positionY[*pointsCount] = y;
		ruch[*pointsCount] = LEWO;
		(*pointsCount)++;
	}
}

void Swiat::wykonajTure() {
	liczbaOrgBezNowych = liczbaOrg;
	if (zycieCzlowieka) {
		cout << endl;
		if (!czlowiek->CzyUmiejetnoscAktywowana() && czlowiek->GetTuryObecnegoStanuUmiejetnosci() >= 5)
			cout << "Jesli chcesz aktywowac umiejetnosc (Calopalenie wcisnij X)" << endl;
		else if (!czlowiek->CzyUmiejetnoscAktywowana() && czlowiek->GetTuryObecnegoStanuUmiejetnosci() == 0)
			cout << "Umiejetnosc dezaktywowana" << endl;
		cout << "Rusz sie swoja postacia (X)" << endl;
	}
	bool ruch = true;
	if (zycieCzlowieka) {
		char input = _getch();
		char input2 = '0';
		while (input) {
			if (input == 'x') {
				if (!czlowiek->CzyUmiejetnoscAktywowana()) {
					czlowiek->AktywujUmiejetnosc();
					input2 = _getch();
				}
				if ((input2 != 224) || (input2 == '0' && czlowiek->CzyUmiejetnoscAktywowana())) {
					cout << "Zly klawisz" << endl;
					ruch = false;
					break;
				}
			}
			if (input == 'k' || input == 'u' || input == 'h' || input == 'j') {
				czlowiek->SetRuch(input);
				break;
			}
			else {
				cout << "Zly przycisk" << endl;
				ruch = false;
				break;
			}
		}
	}
	if (ruch)
		rozgrywkaTury();
}

void Swiat::rozgrywkaTury() {
	Organizm* org;
	Organizm* atakowany;
	Organizm* atakujacy;
	int i = 0;
	while (i < liczbaOrgBezNowych) {
		org = organizmy[i++];
		org->akcja();
		atakowany = mapa[org->GetY()][org->GetX()];
		if (atakowany == nullptr || org->GetOstatniRuch() == 0) {
			org->rysowanie();
		}
		else {
			atakowany->kolizja(org);
		}
	}
	i = 0;
	while (i < liczbaOrgBezNowych) {
		org = organizmy[i++];
		int wiek = org->GetWiek();
		org->SetWiek(wiek + 1);
	}
	if (zycieCzlowieka) {
		czlowiek->SetTuryObecnegoStanuUmiejetnosci(czlowiek->GetTuryObecnegoStanuUmiejetnosci() + 1);
		if (czlowiek->CzyUmiejetnoscAktywowana() && czlowiek->GetTuryObecnegoStanuUmiejetnosci() == 5) {
			czlowiek->DezaktywujUmiejetnosc();
		}
	}
	tura++;
}

Swiat::~Swiat() {
	delete[] organizmy;
	delete czlowiek;
	int y = 0;
	while (y < height) {
		delete mapa[y++];
	}
}
