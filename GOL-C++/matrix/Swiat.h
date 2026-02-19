#pragma once
#ifndef Swiat_Defined
#define Swiat_Defined

#include <iostream>

using namespace std;

class Organizm;
class Czlowiek;

class Swiat {
private:
	int width, height;
	int tura;
	int liczbaOrg, liczbaOrgBezNowych;
	int ileKomentarzy;
	bool zycieCzlowieka;
	string* komentarze;
	Czlowiek* czlowiek;
	Organizm** organizmy;
	Organizm*** mapa;
	void rozgrywkaTury();
public:
	Swiat();
	Swiat(int w, int h);
	
	void SetRozmiar(int w, int h);
	void SetLokalizacja(int x, int y, Organizm* org);
	void SetTura(int n);
	void komentuj(string komentarz);

	int GetWidth() const;
	int GetHeight() const;
	int GetLiczbaOrg() const;
	int GetTura() const;
	Organizm* GetLokalizacja(int x, int y) const;
	Organizm* GetOrganizm(int i) const;
	Czlowiek* GetCzlowiek() const;

	void dodajOrganizm(Organizm* org);
	void zniszczOrganizm(Organizm* org);
	void generowaniePunktow(int x, int y, int* positionX, int* positionY, int* ruch, int* pointsCount);

	void wykonajTure();
	void rysujSwiat();

	~Swiat();
};
#endif