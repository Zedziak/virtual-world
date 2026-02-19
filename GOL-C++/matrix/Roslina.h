#pragma once
#ifndef Roslina_Defined
#define Roslina_Defined

#include <iostream>
#include <string.h>
#include "Organizm.h"

using namespace std;

class Swiat;
class Organizm;

class Roslina : public Organizm {
protected:
	Organizm* stworzOrganizm(int x, int y, Swiat* swiat) override;
public:
	Roslina();
	Roslina(int sila, int x, int y, Swiat* swiat);

	virtual char GetAwatar() const = 0;
	virtual string GetGatunek() const = 0;
	int GetOstatniRuch() const override;
	string Zapisz() const override;

	void KomentarzOZabiciu(Organizm* atakowany) override;
	bool CzyZwierze() override;
	void SetRuch(char ruch) override;
	void akcja() override;
	void kolizja(Organizm* atakujacy) override;
	void cofniecie() override;
	void ucieczka() override;
};
#endif