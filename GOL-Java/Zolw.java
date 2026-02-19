package pl.edu.pg.eti.ksg.po.project2.zwierzeta;

import pl.edu.pg.eti.ksg.po.project2.Zwierze;
import pl.edu.pg.eti.ksg.po.project2.Organizm;
import pl.edu.pg.eti.ksg.po.project2.Komentator;
import pl.edu.pg.eti.ksg.po.project2.Swiat;
import pl.edu.pg.eti.ksg.po.project2.Punkt;

import java.awt.*;

public class Zolw extends Zwierze {
    private static final int zasieg = 1;
    private static final double szansa_ruchu = 0.25;
    private static final int sila = 2;
    private static final int inicjatywa = 1;

    public Zolw(Swiat swiat, Punkt pozycja, int turaUrodzenia) {
        super(TypOrganizmu.ZOLW, swiat, pozycja, turaUrodzenia, sila, inicjatywa);
        this.setZasiegRuchu(zasieg);
        this.setSzansaWykonywaniaRuchu(szansa_ruchu);
        setKolor(new Color(3, 52, 3));
    }

    @Override
    public String GetGatunek() {
        return "Zolw";
    }

    @Override
    public boolean SpecjalneDzialaniePodczasAtaku(Organizm atakujacy, Organizm ofiara) {
        if (this == ofiara) {
            if (atakujacy.getSila() < 5 && atakujacy.CzyJestZwierzeciem()) {
                Komentator.DodajKomentarz(OrganizmToString() + " odpiera atak " + atakujacy.OrganizmToString());
                return true;
            } else return false;
        } else {
            if (atakujacy.getSila() >= ofiara.getSila()) return false;
            else {
                if (ofiara.getSila() < 5 && ofiara.CzyJestZwierzeciem()) {
                    Komentator.DodajKomentarz(OrganizmToString() + " odpiera atak " + ofiara.OrganizmToString());
                    return true;
                } else return false;
            }
        }
    }
}
