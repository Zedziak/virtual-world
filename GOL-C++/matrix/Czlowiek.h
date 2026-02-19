#pragma once
#ifndef Czlowiek_Defined
#define Czlowiek_Defined

#include <iostream>
#include <string.h>

#include "Zwierze.h"

using namespace std;

class Swiat;
class Organizm;
class Zwierze;

class Czlowiek : public Zwierze {
private:
	const char awatar = 'X';
	bool umiejetnoscAktywowana;
	int turyObecnegoStanuUmiejetnosci;
public:
	Czlowiek(int x, int y, Swiat* swiat);

	void SetRuch(char ruch) override;
	void SetCzyUmiejetnoscAktywowana(bool umiejetnoscAktywowana);
	void SetTuryObecnegoStanuUmiejetnosci(int tury);

	int GetOstatniRuch() const override;
	bool CzyUmiejetnoscAktywowana() const;
	int GetTuryObecnegoStanuUmiejetnosci() const;
	char GetAwatar() const override;
	string GetGatunek() const override;
	string Zapisz() const override;

	void akcja() override;
	void kolizja(Organizm* atakujacy) override;
	void ucieczka() override;
	void AktywujUmiejetnosc();
	void DezaktywujUmiejetnosc();
};
#endif