package pl.edu.pg.eti.ksg.po.project2.zwierzeta;

import pl.edu.pg.eti.ksg.po.project2.Zwierze;
import pl.edu.pg.eti.ksg.po.project2.Swiat;
import pl.edu.pg.eti.ksg.po.project2.Punkt;

import java.awt.*;

public class Wilk extends Zwierze {
    private static final int zasieg = 1;
    private static final int szansa_ruchu = 1;
    private static final int sila = 9;
    private static final int inicjatywa = 5;

    public Wilk(Swiat swiat, Punkt pozycja, int turaUrodzenia) {
        super(TypOrganizmu.WILK, swiat, pozycja, turaUrodzenia, sila, inicjatywa);
        this.setZasiegRuchu(zasieg);
        this.setSzansaWykonywaniaRuchu(szansa_ruchu);
        setKolor(new Color(42, 38, 38));
    }

    @Override
    public String GetGatunek() {
        return "Wilk";
    }
}
