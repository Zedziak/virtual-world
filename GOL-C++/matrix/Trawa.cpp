#include <iostream>

#include "Swiat.h"
#include "Organizm.h"
#include "Roslina.h"
#include "Trawa.h"

Trawa::Trawa() : Roslina() {
	sila = 0;
}

Trawa::Trawa(int w, int h, Swiat* swiat) : Roslina(0, w, h, swiat) {}

char Trawa::GetAwatar() const {
	return awatar;
}

string Trawa::GetGatunek() const {
	return "Trawa";
}

void Trawa::akcja() {
	int ran = (rand() % 100) + 1;
	if (ran < ratio)
		Roslina::akcja();
}

void Trawa::kolizja(Organizm* atakujacy) {
	Roslina::kolizja(atakujacy);
}