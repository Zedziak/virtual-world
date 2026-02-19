#include <iostream>

#include "Swiat.h"
#include "Antylopa.h"

Antylopa::Antylopa() : Zwierze() {
	sila = 4;
	inicjatywa = 4;
}

Antylopa::Antylopa(int x, int y, Swiat* swiat) : Zwierze(4, 4, x, y, swiat) {}

void Antylopa::SetRuch(char ruch) {
	Zwierze::SetRuch(ruch);
}

int Antylopa::GetOstatniRuch() const {
	return Zwierze::GetOstatniRuch();
}

char Antylopa::GetAwatar() const {
	return awatar;
}

string Antylopa::GetGatunek() const {
	return "Antylopa";
}


void Antylopa::akcja() {
	swiat->SetLokalizacja(x, y, nullptr);
	this->Ruch(2);
}

void Antylopa::kolizja(Organizm* atakujacy) {
	int ran = rand() % 100 + 1;
	if (ran % 2 == 0 && atakujacy->GetAwatar() != awatar)
	{
		this->RuchNaWolnePole();
		if (ostatni_ruch != 0)
		{
			return;
		}
	}
	Zwierze::kolizja(atakujacy);
}