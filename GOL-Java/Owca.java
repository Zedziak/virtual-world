package pl.edu.pg.eti.ksg.po.project2.zwierzeta;

import pl.edu.pg.eti.ksg.po.project2.Zwierze;
import pl.edu.pg.eti.ksg.po.project2.Swiat;
import pl.edu.pg.eti.ksg.po.project2.Punkt;

import java.awt.*;

public class Owca extends Zwierze {
    private static final int zasieg = 1;
    private static final int szansa_ruchu = 1;
    private static final int sila = 4;
    private static final int inicjatywa = 4;

    public Owca(Swiat swiat, Punkt pozycja, int turaUrodzenia) {
        super(TypOrganizmu.OWCA, swiat, pozycja, turaUrodzenia, sila, inicjatywa);
        this.setZasiegRuchu(zasieg);
        this.setSzansaWykonywaniaRuchu(szansa_ruchu);
        setKolor(new Color(128, 128, 128));
    }

    @Override
    public String GetGatunek() {
        return "Owca";
    }
}
