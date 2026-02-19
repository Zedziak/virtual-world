package pl.edu.pg.eti.ksg.po.project2.rosliny;

import pl.edu.pg.eti.ksg.po.project2.Roslina;
import pl.edu.pg.eti.ksg.po.project2.Swiat;
import pl.edu.pg.eti.ksg.po.project2.Punkt;

import java.awt.*;

public class Trawa extends Roslina {
    private static final int sila = 0;
    private static final int inicjatywa = 0;

    public Trawa(Swiat swiat, Punkt pozycja, int turaUrodzenia) {
        super(TypOrganizmu.TRAWA, swiat, pozycja, turaUrodzenia, sila, inicjatywa);
        setKolor(new Color(98, 180, 55, 255));
        setSzansaRozmnazania(0.4);
    }

    @Override
    public String GetGatunek() {
        return "Trawa";
    }
}
