package pl.edu.pg.eti.ksg.po.project2.rosliny;

import pl.edu.pg.eti.ksg.po.project2.Roslina;
import pl.edu.pg.eti.ksg.po.project2.Organizm;
import pl.edu.pg.eti.ksg.po.project2.Komentator;
import pl.edu.pg.eti.ksg.po.project2.Swiat;
import pl.edu.pg.eti.ksg.po.project2.Punkt;

import java.awt.*;

public class Guarana extends Roslina {
    private static final int buff = 3;
    private static final int sila = 0;
    private static final int inicjatywa = 0;

    public Guarana(Swiat swiat, Punkt pozycja, int turaUrodzenia) {
        super(TypOrganizmu.GUARANA, swiat, pozycja, turaUrodzenia, sila, inicjatywa);
        setKolor(new Color(194, 11, 11));
        setSzansaRozmnazania(0.1);
    }

    @Override
    public String GetGatunek() {
        return "Guarana";
    }

    @Override
    public boolean SpecjalneDzialaniePodczasAtaku(Organizm atakujacy, Organizm ofiara) {
        Punkt tmpPozycja = this.getPozycja();
        getSwiat().UsunOrganizm(this);
        atakujacy.WykonajRuch(tmpPozycja);
        Komentator.DodajKomentarz(atakujacy.OrganizmToString() + " zjada " + this.OrganizmToString()
                + "  i zwieksza swoja sile o " + Integer.toString(buff));
        atakujacy.setSila(atakujacy.getSila() + buff);
        return true;
    }
}

