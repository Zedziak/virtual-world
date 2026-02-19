#include <iostream>

#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"
#include "Lis.h"

class Swiat;
class Organizm;
class Zwierze;

Lis::Lis() : Zwierze() {
	sila = 3;
	inicjatywa = 7;
}

Lis::Lis(int x, int y, Swiat* swiat) : Zwierze(3, 7, x, y, swiat) {}

void Lis::SetRuch(char ruch) {
	Zwierze::SetRuch(ruch);
}

int Lis::GetOstatniRuch() const {
	return Zwierze::GetOstatniRuch();
}

char Lis::GetAwatar() const {
	return awatar;
}

string Lis::GetGatunek() const {
	return "Lis";
}

void Lis::akcja() {
	Zwierze::ucieczka();
}

void Lis::kolizja(Organizm* atakujacy) {
	Zwierze::kolizja(atakujacy);
}