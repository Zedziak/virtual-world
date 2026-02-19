#include <iostream>
#include <typeinfo>

#include "Swiat.h"
#include "Zwierze.h"
#include "Roslina.h"
#include "BarszczSosnowskiego.h"

BarszczSosnowskiego::BarszczSosnowskiego() : Roslina() {
	sila = 10;
}

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y, Swiat* swiat) : Roslina(10, x, y, swiat) {}

char BarszczSosnowskiego::GetAwatar() const {
	return awatar;
}

string BarszczSosnowskiego::GetGatunek() const {
	return "Barszcz Sosnowskiego";
}

void BarszczSosnowskiego::akcja() {
	Organizm* org[4];
	org[0] = swiat->GetLokalizacja(x, y - 1);
	org[1] = swiat->GetLokalizacja(x + 1, y);
	org[2] = swiat->GetLokalizacja(x, y + 1);
	org[3] = swiat->GetLokalizacja(x - 1, y);

	if ((org[0] != nullptr) && org[0]->CzyZwierze())
		swiat->zniszczOrganizm(org[0]);
	if ((org[1] != nullptr) && org[1]->CzyZwierze())
		swiat->zniszczOrganizm(org[1]);
	if ((org[2] != nullptr) && org[2]->CzyZwierze())
		swiat->zniszczOrganizm(org[2]);
	if ((org[3] != nullptr) && org[3]->CzyZwierze())
		swiat->zniszczOrganizm(org[3]);
	int ran = (rand() % 100) + 1;
	if (ran < ratio)
		Roslina::akcja();
}

void BarszczSosnowskiego::kolizja(Organizm* atakujacy) {
	swiat->zniszczOrganizm(atakujacy);
	swiat->zniszczOrganizm(this);
}