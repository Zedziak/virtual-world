#pragma once
#ifndef Generator_Defined
#define Generator_Defined

#include <iostream>

using namespace std;

class Swiat;

class Generator {
private:
	Swiat* swiat;
	void wybierzLokalizacje(int* pola, int* orgPerGat);
	void odczytajLokalizacje(int* pola, int* x, int* y, int* index);
	void wczytajOrganizm(string nazwa, int sila, int ini, int x, int y, int wiek);
public:
	Generator(Swiat* swiat);

	void generujSwiat();
	bool wczytajSwiat();
	void zapiszSwiat();

	~Generator();
};
#endif