#pragma once
#ifndef Trawa_Defined
#define Trawa_Defined

#include <iostream>
#include <string.h>

#include "Roslina.h"

using namespace std;

class Swiat;
class Organizm;
class Roslina;

class Trawa : public Roslina {
private:
	const char awatar = 'T';
	const int ratio = 50;
public:
	Trawa();
	Trawa(int x, int y, Swiat* swiat);

	char GetAwatar() const override;
	string GetGatunek() const override;

	void akcja() override;
	void kolizja(Organizm* atakujacy) override;
};
#endif