#include <iostream>
#include <string>

#include "Swiat.h"
#include "Organizm.h"
#include "Roslina.h"

#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"

using namespace std;

Roslina::Roslina() : Organizm() {}

Roslina::Roslina(int sila, int x, int y, Swiat* swiat) : Organizm(sila, 0, x, y, swiat) {}

int Roslina::GetOstatniRuch() const {
	return 0;
}

bool Roslina::CzyZwierze() {
	return false;
}

string Roslina::Zapisz() const {
	string result = this->GetGatunek() + " " + to_string(this->GetSila()) + " " + to_string(this->GetInicjatywa()) + " ";
	result += to_string(this->GetX()) + " " + to_string(this->GetY()) + " " + to_string(this->GetWiek());
	return result;
}

void Roslina::akcja() {
	string komentarz;
	int* pointsX = new int[4];
	int* pointsY = new int[4];
	int* ruch = new int[4];
	int pointsCount = 0;
	swiat->generowaniePunktow(x, y, pointsX, pointsY, ruch, &pointsCount);

	if (pointsCount != 0) {
		int los = rand() % pointsCount;
		Organizm* org = this->stworzOrganizm(pointsX[los], pointsY[los], swiat);
		swiat->dodajOrganizm(org);

		komentarz = this->GetGatunek() + ": \trozsianie rosliny z pola (" + to_string(x) + ", ";
		komentarz += to_string(y) + ") na pole (" + to_string(pointsX[los]) + ", " + to_string(pointsY[los]) + ")";
		swiat->komentuj(komentarz);
	}
}

void Roslina::KomentarzOZabiciu(Organizm* atakowany) {
	string komentarz;
	komentarz = this->GetGatunek() + ": \tzaatakowal organizm " + atakowany->GetGatunek();
	swiat->komentuj(komentarz);
}

void Roslina::kolizja(Organizm* atakujacy) {
	atakujacy->KomentarzOZabiciu(this);
	if (this->GetSila() > atakujacy->GetSila()) {
		swiat->zniszczOrganizm(atakujacy);
		swiat->zniszczOrganizm(this);
	}
	else {
		swiat->SetLokalizacja(this->GetX(), this->GetY(), atakujacy);
		swiat->zniszczOrganizm(this);
		atakujacy->rysowanie();
	}
}

Organizm* Roslina::stworzOrganizm(int x, int y, Swiat* swiat) {
	if (typeid(*this) == typeid(Trawa)) {
		Trawa* tmp = new Trawa(x - 1, y - 1, swiat);
		return tmp;
	}
	else if (typeid(*this) == typeid(Mlecz)) {
		Mlecz* tmp = new Mlecz(x - 1, y - 1, swiat);
		return tmp;
	}
	else if (typeid(*this) == typeid(Guarana)) {
		Guarana* tmp = new Guarana(x - 1, y - 1, swiat);
		return tmp;
	}
	else if (typeid(*this) == typeid(WilczeJagody)) {
		WilczeJagody* tmp = new WilczeJagody(x - 1, y - 1, swiat);
		return tmp;
	}
	else if (typeid(*this) == typeid(BarszczSosnowskiego)) {
		BarszczSosnowskiego* tmp = new BarszczSosnowskiego(x - 1, y - 1, swiat);
		return tmp;
	}
}

void Roslina::SetRuch(char ruch) {}
void Roslina::cofniecie() {}
void Roslina::ucieczka() {}
