#pragma once
#ifndef BarszczSosnowskiego_Defined
#define BarszczSosnowskiego_Defined

#include <iostream>
#include "Roslina.h"

using namespace std;

class Swiat;
class Organizm;
class Roslina;

class BarszczSosnowskiego : public Roslina {
private:
	const char awatar = 'B';
	const int ratio = 10;
public:
	BarszczSosnowskiego();
	BarszczSosnowskiego(int x, int y, Swiat* swiat);

	char GetAwatar() const override;
	string GetGatunek() const override;

	void akcja() override;
	void kolizja(Organizm* atakujacy) override;
};
#endif