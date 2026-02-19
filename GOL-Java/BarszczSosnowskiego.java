package pl.edu.pg.eti.ksg.po.project2.rosliny;

import pl.edu.pg.eti.ksg.po.project2.Organizm;
import pl.edu.pg.eti.ksg.po.project2.Roslina;
import pl.edu.pg.eti.ksg.po.project2.Komentator;
import pl.edu.pg.eti.ksg.po.project2.Swiat;
import pl.edu.pg.eti.ksg.po.project2.Punkt;

import java.awt.*;
import java.util.Random;

public class BarszczSosnowskiego extends Roslina {
    private static final int sila = 10;
    private static final int inicjatywa = 0;

    public BarszczSosnowskiego(Swiat swiat, Punkt pozycja, int turaUrodzenia) {
        super(TypOrganizmu.BARSZCZ_SOSNOWSKIEGO, swiat, pozycja, turaUrodzenia, sila, inicjatywa);
        setKolor(Color.BLACK);
        setSzansaRozmnazania(0.05);
    }

    @Override
    public void Akcja() {
        int pozX = getPozycja().getX();
        int pozY = getPozycja().getY();
        LosujPoleDowolne(getPozycja());// BLOKUJE GRANICE
        for (int i = 0; i < 4; i++) {
            Organizm tmpOrganizm = null;
            if (i == 0 && !CzyKierunekZablokowany(Kierunek.DOL))
                tmpOrganizm = getSwiat().CoZnajdujeSieNaPolu(new Punkt(pozX, pozY + 1));
            else if (i == 1 && !CzyKierunekZablokowany(Kierunek.GORA))
                tmpOrganizm = getSwiat().CoZnajdujeSieNaPolu(new Punkt(pozX, pozY - 1));
            else if (i == 2 && !CzyKierunekZablokowany(Kierunek.LEWO))
                tmpOrganizm = getSwiat().CoZnajdujeSieNaPolu(new Punkt(pozX - 1, pozY));
            else if (i == 3 && !CzyKierunekZablokowany(Kierunek.PRAWO))
                tmpOrganizm = getSwiat().CoZnajdujeSieNaPolu(new Punkt(pozX + 1, pozY));

            if (tmpOrganizm != null && tmpOrganizm.CzyJestZwierzeciem()) {
                getSwiat().UsunOrganizm(tmpOrganizm);
                Komentator.DodajKomentarz(OrganizmToString() + " zabija " + tmpOrganizm.OrganizmToString());
            }
        }
        Random rand = new Random();
        int tmpLosowanie = rand.nextInt(100);
        if (tmpLosowanie < getSzansaRozmnazania() * 100) Rozprzestrzenianie();
    }

    @Override
    public String GetGatunek() {
        return "Barszcz Sosnowskiego";
    }

    @Override
    public boolean SpecjalneDzialaniePodczasAtaku(Organizm atakujacy, Organizm ofiara) {
        if (atakujacy.getSila() >= 10) {
            getSwiat().UsunOrganizm(this);
            Komentator.DodajKomentarz(atakujacy.OrganizmToString() + " zjada " + this.OrganizmToString());
            atakujacy.WykonajRuch(ofiara.getPozycja());
        }
        return true;
    }
}
