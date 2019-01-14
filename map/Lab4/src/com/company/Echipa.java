package com.company;


public class Echipa {
    private String nume;
    private int etapa;
    private int infrangeri;
    private int egaluri;
    private int victorii;
    private int goluri;
    private  int puncte;

    public Echipa()
    {
        this.nume = null;
        this.etapa = 0;
        this.infrangeri = 0;
        this.egaluri = 0;
        this.victorii = 0;
        this.goluri = 0;
        this.puncte = 0;
    }
    public Echipa(String n, int nr, int i, int e, int v, int g, int p)
    {
        this.nume = n;
        this.etapa = nr;
        this.infrangeri = i;
        this.egaluri = e;
        this.victorii = v;
        this.goluri = g;
        this.puncte = p;
    }
    public Echipa(Echipa e)
    {
        this.nume = e.nume;
        this.etapa = e.etapa;
        this.infrangeri = e.infrangeri;
        this.egaluri = e.egaluri;
        this.victorii =e.victorii;
        this.goluri = e.goluri;
        this.puncte = e.puncte;
    }

    public void setNume(String n) {
        this.nume = n;
    }

    public String getNume() {
        return this.nume;
    }

    public void setEtapa(int et) {
        this.etapa = et;
    }

    public int getEtapa() {
        return this.etapa;
    }
    public void setInfrangeri(int i) {
        this.infrangeri = i;
    }

    public int getInfrangeri() {
        return this.infrangeri;
    }
    public void setEgaluri(int e) {
        this.egaluri = e;
    }

    public int getEgaluri() {
        return this.egaluri;
    }

    public void setVictorii(int v) {
        this.victorii = v;
    }

    public int getVictorii() {
        return this.victorii;
    }
    public void setGoluri(int g) {
        this.goluri = g;
    }

    public int getGoluri() {
        return this.goluri;
    }
    public void setPuncte(int p) {
        this.puncte = p;
    }

    public int getPuncte() {
        return this.puncte;
    }

}
