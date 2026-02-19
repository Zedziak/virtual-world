#include <iostream>

#include "Swiat.h"
#include "Organizm.h"

using namespace std;

Organizm::Organizm() {
	sila = 0;
	inicjatywa = 0;
	x = 0;
	y = 0;
	swiat = nullptr;
	wiek = 0;
}

Organizm::Organizm(int str, int ini, int w, int h, Swiat* world) {
	sila = str;
	inicjatywa = ini;
	x = w + 1;
	y = h + 1;
	swiat = world;
	wiek = 0;
}

void Organizm::SetSila(int str) {
	sila = str;
}

void Organizm::SetInicjatywa(int ini) {
	inicjatywa = ini;
}

void Organizm::SetPolozenie(int posx, int posy) {
	x = posx + 1;
	y = posy + 1;
}

void Organizm::SetWiek(int age) {
	wiek = age;
}

void Organizm::SetSwiat(Swiat* world) {
	swiat = world;
}

int Organizm::GetSila() const {
	return sila;
}

int Organizm::GetInicjatywa() const {
	return inicjatywa;
}

int Organizm::GetX() const {
	return x;
}

int Organizm::GetY() const {
	return y;
}

int Organizm::GetWiek() const {
	return wiek;
}

Swiat* Organizm::GetSwiat() const {
	return swiat;
}

void Organizm::rysowanie() {
	swiat->SetLokalizacja(x, y, this);
}