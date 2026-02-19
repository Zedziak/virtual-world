#pragma once
#ifndef Lis_Defined
#define Lis_Defined

#include <iostream>
#include "Zwierze.h"

class Swiat;
class Organizm;
class Zwierze;

class Lis : public Zwierze {
private:
	const char awatar = 'L';
public:
	Lis();
	Lis(int x, int y, Swiat* swiat);

	void SetRuch(char ruch) override;

	int GetOstatniRuch() const override;
	char GetAwatar() const override;
	string GetGatunek() const override;

	void akcja() override;
	void kolizja(Organizm* atakujacy) override;
};
#endif