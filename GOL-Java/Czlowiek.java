package pl.edu.pg.eti.ksg.po.project2.zwierzeta;

import pl.edu.pg.eti.ksg.po.project2.Zwierze;
import pl.edu.pg.eti.ksg.po.project2.Organizm;
import pl.edu.pg.eti.ksg.po.project2.Komentator;
import pl.edu.pg.eti.ksg.po.project2.Swiat;
import pl.edu.pg.eti.ksg.po.project2.Punkt;
import pl.edu.pg.eti.ksg.po.project2.Umiejetnosc;

import java.awt.*;

public class Czlowiek extends Zwierze {
    private static final int zasieg = 1;
    private static final int szansa_ruchu = 1;
    private static final int sila = 5;
    private static final int inicjatywa = 4;
    private Kierunek kierunekRuchu;
    private Umiejetnosc umiejetnosc;

    public Czlowiek(Swiat swiat, Punkt pozycja, int turaUrodzenia) {
        super(TypOrganizmu.CZLOWIEK, swiat, pozycja, turaUrodzenia, sila, inicjatywa);
        this.setZasiegRuchu(zasieg);
        this.setSzansaWykonywaniaRuchu(szansa_ruchu);
        kierunekRuchu = Kierunek.BRAK_KIERUNKU;
        setKolor(Color.CYAN);
        umiejetnosc = new Umiejetnosc();
    }

    private void Calopalenie() {
        LosujPoleDowolne(getPozycja());
        int x = getPozycja().getX();
        int y = getPozycja().getY();
        Organizm tmpOrganizm = null;
        for (int i = 0; i < 4; i++) {
            if (i == 0 && !CzyKierunekZablokowany(Kierunek.DOL))
                tmpOrganizm = getSwiat().CoZnajdujeSieNaPolu(new Punkt(x, y + 1));
            else if (i == 1 && !CzyKierunekZablokowany(Kierunek.GORA))
                tmpOrganizm = getSwiat().CoZnajdujeSieNaPolu(new Punkt(x, y - 1));
            else if (i == 2 && !CzyKierunekZablokowany(Kierunek.LEWO))
                tmpOrganizm = getSwiat().CoZnajdujeSieNaPolu(new Punkt(x - 1, y));
            else if (i == 3 && !CzyKierunekZablokowany(Kierunek.PRAWO))
                tmpOrganizm = getSwiat().CoZnajdujeSieNaPolu(new Punkt(x + 1, y));
            if (tmpOrganizm != null) {
                getSwiat().UsunOrganizm(tmpOrganizm);
                Komentator.DodajKomentarz(GetGatunek() + " umiejetnoscia 'Calopalenie' zabija " + tmpOrganizm.GetGatunek());
            }
        }
    }

    @Override
    protected Punkt ZaplanujRuch() {
        int x = getPozycja().getX();
        int y = getPozycja().getY();
        LosujPoleDowolne(getPozycja());//BLOKUJE KIERUNKI NIEDOZWOLONE PRZY GRANICY SWIATU
        if (kierunekRuchu == Kierunek.BRAK_KIERUNKU ||
                CzyKierunekZablokowany(kierunekRuchu)) return getPozycja();
        else {
            if (kierunekRuchu == Kierunek.DOL) return new Punkt(x, y + 1);
            if (kierunekRuchu == Kierunek.GORA) return new Punkt(x, y - 1);
            if (kierunekRuchu == Kierunek.LEWO) return new Punkt(x - 1, y);
            if (kierunekRuchu == Kierunek.PRAWO) return new Punkt(x + 1, y);
            else return new Punkt(x, y);
        }
    }

    @Override
    public void Akcja() {
        if (umiejetnosc.getCzyJestAktywna()) {
            Komentator.DodajKomentarz(OrganizmToString() + " 'Calopalenie' jest aktywne(Pozostaly czas "
                    + umiejetnosc.getCzasTrwania() + " tur)");
            Calopalenie();
        }
        for (int i = 0; i < getZasiegRuchu(); i++) {
            Punkt przyszlaPozycja = ZaplanujRuch();

            if (getSwiat().CzyPoleJestZajete(przyszlaPozycja)
                    && getSwiat().CoZnajdujeSieNaPolu(przyszlaPozycja) != this) {
                Kolizja(getSwiat().CoZnajdujeSieNaPolu(przyszlaPozycja));
                break;
            } else if (getSwiat().CoZnajdujeSieNaPolu(przyszlaPozycja) != this) WykonajRuch(przyszlaPozycja);
            if (umiejetnosc.getCzyJestAktywna()) Calopalenie();
        }
        kierunekRuchu = Kierunek.BRAK_KIERUNKU;
        umiejetnosc.SprawdzWarunki();
    }

    @Override
    public String GetGatunek() {
        return "Czlowiek";
    }

    public Umiejetnosc getUmiejetnosc() {
        return umiejetnosc;
    }

    public void setKierunekRuchu(Kierunek kierunekRuchu) {
        this.kierunekRuchu = kierunekRuchu;
    }
}
