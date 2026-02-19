#pragma once
#ifndef Antylopa_Defined
#define Antylopa_Defined
#include <iostream>

#include "Zwierze.h"

using namespace std;

class Swiat;
class Organizm;
class Zwierze;

class Antylopa : public Zwierze
{
private:
	const char awatar = 'A';
public:
	Antylopa();
	Antylopa(int x, int y, Swiat* swiat);

	void SetRuch(char ruch) override;

	int GetOstatniRuch() const override;
	char GetAwatar() const override;
	string GetGatunek() const override;

	void akcja() override;
	void kolizja(Organizm* atakujacy) override;
};
#endif