from pomocnicze.wektor2d import Wektor2d
from symulacja.organizmy.zwierze import Zwierze


class Wilk(Zwierze):

    SILA = 9
    INICJATYWA = 5

    def __init__(self, polozenie: Wektor2d):
        super().__init__(polozenie, Wilk.SILA, Wilk.INICJATYWA)

    def rysowanie(self) -> str:
        return "#666564"

    def __str__(self):
        return "WILK"