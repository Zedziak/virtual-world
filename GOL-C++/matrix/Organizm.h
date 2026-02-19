#pragma once
#ifndef Organizm_Defined
#define Organizm_Defined

#include <iostream>
#include <string.h>

using namespace std;

class Swiat;

class Organizm {
protected:
	int sila;
	int inicjatywa;
	int x;
	int y;
	int wiek;
	Swiat* swiat;

	virtual Organizm* stworzOrganizm(int x, int y, Swiat* swiat) = 0;
public:
	Organizm();
	Organizm(int sila, int ini, int x, int y, Swiat* swiat);

	void SetSila(int sila);
	void SetInicjatywa(int inicjatywa);
	void SetPolozenie(int x, int y);
	void SetWiek(int wiek);
	void SetSwiat(Swiat* swiat);
	virtual void SetRuch(char ruch) = 0;

	int GetSila() const;
	int GetInicjatywa() const;
	int GetX() const;
	int GetY() const;
	int GetWiek() const;
	Swiat* GetSwiat() const;
	virtual int GetOstatniRuch() const = 0;
	virtual char GetAwatar() const = 0;
	virtual string GetGatunek() const = 0;
	virtual string Zapisz() const = 0;

	void rysowanie();
	virtual void cofniecie() = 0;
	virtual void akcja() = 0;
	virtual void ucieczka() = 0;
	virtual bool CzyZwierze() = 0;
	virtual void kolizja(Organizm* atakujacy) = 0;
	virtual void KomentarzOZabiciu(Organizm* atakowany) = 0;
};
#endif