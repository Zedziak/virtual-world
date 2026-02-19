#include <iostream>
#include <string>

#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"
#include "Czlowiek.h"

#define GORA 1
#define PRAWO 2
#define DOL 3
#define LEWO 4

using namespace std;

Czlowiek::Czlowiek(int x, int y, Swiat* swiat) : Zwierze(5, 4, x, y, swiat) {
	turyObecnegoStanuUmiejetnosci = 5;
	umiejetnoscAktywowana = false;
}

void Czlowiek::SetRuch(char ruch) {
	if (ruch == 'u') {
		ostatni_ruch = GORA;
	}
	else if (ruch == 'k') {
		ostatni_ruch = PRAWO;
	}
	else if (ruch == 'j') {
		ostatni_ruch = DOL;
	}
	else if (ruch == 'h') {
		ostatni_ruch = LEWO;
	}
}

void Czlowiek::SetCzyUmiejetnoscAktywowana(bool umiejetnoscAktywowana) {
	this->umiejetnoscAktywowana = umiejetnoscAktywowana;
}

void Czlowiek::SetTuryObecnegoStanuUmiejetnosci(int tury) {
	this->turyObecnegoStanuUmiejetnosci = tury;
}

int Czlowiek::GetOstatniRuch() const {
	return Zwierze::GetOstatniRuch();
}

bool Czlowiek::CzyUmiejetnoscAktywowana() const {
	return umiejetnoscAktywowana;
}

int Czlowiek::GetTuryObecnegoStanuUmiejetnosci() const {
	return turyObecnegoStanuUmiejetnosci;
}

char Czlowiek::GetAwatar() const {
	return awatar;
}

string Czlowiek::GetGatunek() const {
	return "Czlowiek";
}

string Czlowiek::Zapisz() const {
	string result = this->GetGatunek() + " " + to_string(sila) + " " + to_string(inicjatywa) + " ";
	result += to_string(x) + " " + to_string(y) + " " + to_string(wiek) + " " + to_string(umiejetnoscAktywowana) + " " + to_string(turyObecnegoStanuUmiejetnosci);
	return result;
}

void Czlowiek::akcja() {
	string komentarz;
	komentarz = this->GetGatunek() + ": \tprzemieszczenie z (" + to_string(x) + ", " + to_string(y) + ") na (";

	if (umiejetnoscAktywowana) {
		Organizm* org[8];
		org[0] = swiat->GetLokalizacja(x, y - 1);
		org[1] = swiat->GetLokalizacja(x + 1, y);
		org[2] = swiat->GetLokalizacja(x, y + 1);
		org[3] = swiat->GetLokalizacja(x - 1, y);
		org[4] = swiat->GetLokalizacja(x - 1, y - 1);
		org[5] = swiat->GetLokalizacja(x + 1, y + 1);
		org[6] = swiat->GetLokalizacja(x - 1, y + 1);
		org[7] = swiat->GetLokalizacja(x + 1, y - 1);

		for (int i = 0; i < 8; i++) {
			if (org[i] != nullptr) {
				swiat->zniszczOrganizm(org[i]);
			}
		}
	}

	swiat->SetLokalizacja(x, y, nullptr);
	if ((ostatni_ruch == 1) && (y - 1 != 0)) {
		y -= 1;
	}
	else if ((ostatni_ruch == 2) && (x + 1 != swiat->GetWidth() + 1)) {
		x += 1;
	}
	else if ((ostatni_ruch == 3) && (y + 1 != swiat->GetHeight() + 1)) {
		y += 1;
	}
	else if ((ostatni_ruch == 4) && (x - 1 != 0)) {
		x -= 1;
	}
	else {
		ostatni_ruch = 0;
		this->rysowanie();
	}
	komentarz += to_string(x) + ", " + to_string(y) + ")";
	swiat->komentuj(komentarz);
}

void Czlowiek::kolizja(Organizm* atakujacy) {
	Zwierze::kolizja(atakujacy);
}

void Czlowiek::ucieczka() {
	Zwierze::ucieczka();
}

void Czlowiek::AktywujUmiejetnosc() {
	umiejetnoscAktywowana = true;
	turyObecnegoStanuUmiejetnosci = 0;
	cout << "Umiejetnosc aktywowana - samopalenie" << endl;
}

void Czlowiek::DezaktywujUmiejetnosc() {
	umiejetnoscAktywowana = false;
	turyObecnegoStanuUmiejetnosci = 0;
}