from random import random

from pomocnicze.wektor2d import Wektor2d
from symulacja.organizmy.zwierze import Zwierze
from symulacja.organizmy.roslina import Roslina
from symulacja.swiat import Swiat


class Czlowiek(Zwierze):

    SILA = 5
    INICJATYWA = 4
    SPECJALNY_TURY = 5
    SPECJALNY_MNIEJ = 2

    def __init__(self, polozenie: Wektor2d):
        super().__init__(polozenie, Czlowiek.SILA, Czlowiek.INICJATYWA)
        self.__turySpecjalne = 0

    def akcja(self):
        ruch = self._swiat.popRuch()

        if ruch == Swiat.Ruch.GORA:
            self._zmienPolozenie(Wektor2d(-1, 0))

        elif ruch == Swiat.Ruch.DOL:
            self._zmienPolozenie(Wektor2d(1, 0))

        elif ruch == Swiat.Ruch.LEWO:
            self._zmienPolozenie(Wektor2d(0, -1))

        elif ruch == Swiat.Ruch.PRAWO:
            self._zmienPolozenie(Wektor2d(0, 1))

        elif ruch == Swiat.Ruch.SPECJALNY:
            self.__turySpecjalne = Czlowiek.SPECJALNY_TURY if self.__turySpecjalne == 0 else self.__turySpecjalne

        if self.__turySpecjalne > Czlowiek.SPECJALNY_MNIEJ:
            for y in range(-1,2):
                for x in range(-1, 2):
                    org = self._swiat.getOrganizmNaPozycji(self.getPolozenie() + Wektor2d(y,x))

                    if isinstance(org,Zwierze) or isinstance(org,Roslina):
                        if not isinstance(org, Czlowiek):
                            org.zabij()

        self.__turySpecjalne -= 1
        self.__turySpecjalne = 0 if self.__turySpecjalne <= 0 else self.__turySpecjalne

    def rysowanie(self) -> str:
        return "#fa34ed"

    def __str__(self):
        return "CZLOWIEK"

    def getTurySpecjalne(self):
        return self.__turySpecjalne

    def setTurySpecjalne(self, tury : int):
        self.__turySpecjalne = tury