#include <iostream>

#include "Swiat.h"
#include "Roslina.h"
#include "Guarana.h"

Guarana::Guarana() : Roslina() {
	sila = 0;
}

Guarana::Guarana(int x, int y, Swiat* swiat) : Roslina(0, x, y, swiat) {}

char Guarana::GetAwatar() const {
	return awatar;
}

string Guarana::GetGatunek() const {
	return "Guarana";
}

void Guarana::akcja() {
	int ran = (rand() % 100) + 1;
	if (ran < ratio)
		Roslina::akcja();
}

void Guarana::kolizja(Organizm* atakujacy) {
	atakujacy->SetSila(atakujacy->GetSila() + 3);
	swiat->SetLokalizacja(this->GetX(), this->GetY(), atakujacy);
	swiat->zniszczOrganizm(this);
	atakujacy->rysowanie();
}