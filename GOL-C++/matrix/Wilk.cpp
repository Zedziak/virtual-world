#include <iostream>

#include "Swiat.h"
#include "Organizm.h"
#include "Wilk.h"

class Swiat;
class Organizm;
class Zwierze;

Wilk::Wilk() : Zwierze() {
	sila = 9;
	inicjatywa = 5;
}

Wilk::Wilk(int x, int y, Swiat* swiat) : Zwierze(9, 5, x, y, swiat) {}

void Wilk::SetRuch(char ruch) {
	Zwierze::SetRuch(ruch);
}

int Wilk::GetOstatniRuch() const {
	return Zwierze::GetOstatniRuch();
}

char Wilk::GetAwatar() const {
	return awatar;
}

string Wilk::GetGatunek() const {
	return "Wilk";
}

void Wilk::akcja() {
	Zwierze::akcja();
}

void Wilk::kolizja(Organizm* atakujacy) {
	Zwierze::kolizja(atakujacy);
}