#pragma once
#ifndef Mlecz_Defined
#define Mlecz_Defined


#include <iostream>
#include "Roslina.h"

class Swiat;
class Organizm;
class Roslina;

class Mlecz : public Roslina {
private:
	const char awatar = 'M';
	const int ratio = 20;
public:
	Mlecz();
	Mlecz(int x, int y, Swiat* swiat);

	char GetAwatar() const override;
	string GetGatunek() const override;

	void akcja() override;
	void kolizja(Organizm* atakujacy) override;
};
#endif