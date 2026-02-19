#include <iostream>

#include "Swiat.h"
#include "Roslina.h"
#include "Mlecz.h"

Mlecz::Mlecz() : Roslina() {
	sila = 0;
}

Mlecz::Mlecz(int x, int y, Swiat* swiat) : Roslina(0, x, y, swiat) {}

char Mlecz::GetAwatar() const {
	return awatar;
}

string Mlecz::GetGatunek() const {
	return "Mlecz";
}

void Mlecz::akcja() {
	int i = 0;
	while (i < 3) {
		int ran = (rand() % 100) + 1;
		if (ran < ratio)
			Roslina::akcja();
		i++;
	}
}

void Mlecz::kolizja(Organizm* atakujacy) {
	Roslina::kolizja(atakujacy);
}