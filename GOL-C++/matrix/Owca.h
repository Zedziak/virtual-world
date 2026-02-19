#pragma once
#ifndef Owca_Defined
#define Owca_Defined

#include <iostream>
#include "Zwierze.h"

using namespace std;

class Swiat;
class Organizm;
class Zwierze;

class Owca : public Zwierze {
private:
	const char awatar = 'O';
public:
	Owca();
	Owca(int x, int y, Swiat* swiat);

	void SetRuch(char ruch) override;

	int GetOstatniRuch() const override;
	char GetAwatar() const override;
	string GetGatunek() const override;

	void akcja() override;
	void kolizja(Organizm* atakujacy) override;
};
#endif