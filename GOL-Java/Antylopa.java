package pl.edu.pg.eti.ksg.po.project2.zwierzeta;

import pl.edu.pg.eti.ksg.po.project2.Zwierze;
import pl.edu.pg.eti.ksg.po.project2.Organizm;
import pl.edu.pg.eti.ksg.po.project2.Komentator;
import pl.edu.pg.eti.ksg.po.project2.Swiat;
import pl.edu.pg.eti.ksg.po.project2.Punkt;

import java.util.Random;
import java.awt.*;

public class Antylopa extends Zwierze {
    private static final int zasieg = 2;
    private static final int szansa_ruchu = 1;
    private static final int sila = 4;
    private static final int inicjatywa = 4;


    public Antylopa(Swiat swiat, Punkt pozycja, int turaUrodzenia) {
        super(TypOrganizmu.ANTYLOPA, swiat, pozycja, turaUrodzenia, sila, inicjatywa);
        this.setZasiegRuchu(zasieg);
        this.setSzansaWykonywaniaRuchu(szansa_ruchu);
        setKolor(new Color(98, 52, 7));
    }

    @Override
    public String GetGatunek() {
        return "Antylopa";
    }

    @Override
    public boolean SpecjalneDzialaniePodczasAtaku(Organizm atakujacy, Organizm ofiara) {
        Random rand = new Random();
        int tmpLosowanie = rand.nextInt(100);
        if (tmpLosowanie < 50) {
            if (this == atakujacy) {
                Komentator.DodajKomentarz(OrganizmToString() + " ucieka od " + ofiara.OrganizmToString());
                Punkt tmpPozycja = LosujPoleNiezajete(ofiara.getPozycja());
                if (!tmpPozycja.equals(ofiara.getPozycja()))
                    WykonajRuch(tmpPozycja);
            } else if (this == ofiara) {
                Komentator.DodajKomentarz(OrganizmToString() + " ucieka od " + atakujacy.OrganizmToString());
                Punkt tmpPozycja = this.getPozycja();
                WykonajRuch(LosujPoleNiezajete(this.getPozycja()));
                if (getPozycja().equals(tmpPozycja)) {
                    getSwiat().UsunOrganizm(this);
                    Komentator.DodajKomentarz(atakujacy.OrganizmToString() + " zabija " + OrganizmToString());
                }
                atakujacy.WykonajRuch(tmpPozycja);
            }
            return true;
        } else return false;
    }
}
