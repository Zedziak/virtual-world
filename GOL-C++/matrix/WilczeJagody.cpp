#include <iostream>

#include "Swiat.h"
#include "Organizm.h"
#include "Roslina.h"
#include "WilczeJagody.h"

WilczeJagody::WilczeJagody() : Roslina() {
	sila = 99;
}

WilczeJagody::WilczeJagody(int x, int y, Swiat* swiat) : Roslina(99, x, y, swiat) {}

char WilczeJagody::GetAwatar() const {
	return awatar;
}

string WilczeJagody::GetGatunek() const {
	return "Wilcze Jagody";
}

void WilczeJagody::akcja() {
	int ran = (rand() % 100) + 1;
	if (ran < ratio)
		Roslina::akcja();
}

void WilczeJagody::kolizja(Organizm* atakujacy) {
	swiat->zniszczOrganizm(atakujacy);
}