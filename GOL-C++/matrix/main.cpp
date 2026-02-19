#include <iostream>
#include <conio.h>

#include "Swiat.h"
#include "Generator.h"

#define GATUNKI 10

using namespace std;

int main() {
	Swiat* swiat = nullptr;
	Generator* gen = nullptr;
	bool load = true;
	char input;
	int w, h;

	cout << "Autor: Hubert Zedlewski, 193339" << endl;
	cout << "Menu:" << endl;
	cout << "Wczytaj gre - L" << endl;
	cout << "Nowa gra - N" << endl;

	do {
		load = true;
		input = _getch();
		if (input == 'l') {
			swiat = new Swiat();
			gen = new Generator(swiat);
			load = true;
			if (!gen->wczytajSwiat()) {
				cout << "Niepoprawna nazwa" << endl;
				load = false;
			}
			break;
		}
		else if (input == 'n') {
			do {
				cout << "Podaj rozmiar mapy: ";
				cin >> w >> h;
				system("cls");
				if (w * h < (GATUNKI * 3))
					cout << "Zbyt ma³a mapa" << endl;
			} while (w * h < (GATUNKI * 3));
			swiat = new Swiat(w, h);
			gen = new Generator(swiat);
			gen->generujSwiat();
			break;	
		}
		else
			cout << "Blad, ponow dzialanie" << endl;
	} while ((input != 'l' || !load) && input != 'n');

	system("cls");
	swiat->rysujSwiat();

	do {
		while (input = _getch()) {
			if (input == 's') {
				gen->zapiszSwiat();
				break;
			}
			else if (input == 'v') {
				swiat->wykonajTure();
				system("cls");
				swiat->rysujSwiat();
				break;
			}
			else if (input == 'n') {
				system("cls");
				cout << "Nowa gra" << endl << endl;
				do
				{
					cout << "Podaj wymiary planszy: ";
					cin >> w >> h;
					system("cls");
				} while (w * h < (GATUNKI * 2));
				swiat = new Swiat(w, h);
				gen = new Generator(swiat);
				gen->generujSwiat();
				system("cls");
				swiat->rysujSwiat();
				break;
			}
			else
				cout << "Blad, ponow dzialanie" << endl;
		}
	} while (1);

	delete swiat, gen;

	return 0;
}