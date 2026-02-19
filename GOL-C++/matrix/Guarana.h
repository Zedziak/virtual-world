#pragma once
#ifndef Guarana_Defined
#define Guarana_Defined

#include <iostream>
#include <string.h>

#include "Roslina.h"

using namespace std;

class Swiat;
class Organizm;
class Roslina;

class Guarana : public Roslina {
private:
	const char awatar = 'G';
	const int ratio = 20;
public:
	Guarana();
	Guarana(int x, int y, Swiat* swiat);

	char GetAwatar() const override;
	string GetGatunek() const override;

	void akcja() override;
	void kolizja(Organizm* atakujacy) override;
};
#endif
