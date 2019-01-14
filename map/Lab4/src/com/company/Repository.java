package com.company;

public class Repository {
    Echipa clasament[] = new Echipa[15];
    int size;

    public Repository()
    {
        this.size = 0;
    }
    public void add(Echipa e)
    {
        this.clasament[size]=new Echipa();
        this.clasament[size]=e;
        this.size++;
    }

    public void delete(int pos)
    {
        for(int j=pos;j<this.size-1;j++)
            clasament[j]=clasament[j+1];
    }

    public void update(Echipa e,int pos)
    {
        clasament[pos]=e;
    }

    public Echipa[] getClasament()
    {
        return this.clasament;
    }

    public int getSize()
    {
        return this.size;
    }

    public void aduna(String nume, int infr, int eg, int vic,  int gol, int punct)
    {
        int infrangere, egal, victorie, goluri, puncte;
        for(int i=0; i<size; i++){
            if(clasament[i].getNume() == nume){
                infrangere = clasament[i].getInfrangeri();
                clasament[i].setInfrangeri(infr+infrangere);
                egal = clasament[i].getEgaluri();
                clasament[i].setEgaluri(eg+egal);
                victorie = clasament[i].getVictorii();
                clasament[i].setVictorii(vic+victorie);
                goluri = clasament[i].getGoluri();
                clasament[i].setGoluri(gol+goluri);
                puncte = clasament[i].getPuncte();
                clasament[i].setPuncte(punct+puncte);
            }
        }
    }
    public void setEtapa(int etapa){
        for(int i=0; i<size; i++){
            clasament[i].setEtapa(etapa);
        }
    }

}
