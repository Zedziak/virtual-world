#pragma once
#ifndef WilczeJagody_Defined
#define WilczeJagody_Defined

#include <iostream>
#include <string.h>

#include "Roslina.h"

using namespace std;

class Swiat;
class Organizm;
class Roslina;

class WilczeJagody : public Roslina {
private:
	const char awatar = 'J';
	const int ratio = 20;
public:
	WilczeJagody();
	WilczeJagody(int x, int y, Swiat* swiat);

	char GetAwatar() const override;
	string GetGatunek() const override;

	void akcja() override;
	void kolizja(Organizm* atakujacy) override;
};
#endif