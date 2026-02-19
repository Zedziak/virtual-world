#pragma once
#ifndef Wilk_Defined
#define Wilk_Defined

#include <iostream>
#include "Zwierze.h"

class Swiat;
class Organizm;
class Zwierze;

class Wilk : public Zwierze {
private:
	const char awatar = 'W';
public:
	Wilk();
	Wilk(int x, int y, Swiat* swiat);

	void SetRuch(char ruch) override;

	int GetOstatniRuch() const override;
	char GetAwatar() const override;
	string GetGatunek() const override;

	void akcja() override;
	void kolizja(Organizm* atakujacy) override;
};
#endif