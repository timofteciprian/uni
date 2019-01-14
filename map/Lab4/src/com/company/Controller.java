package com.company;

public class Controller {

    Repository repo;
    Echipa clasament[];
    //Constructor implicit

    public Controller()
    {
        this.repo=new Repository();
        clasament=this.repo.getClasament();
    }

    public void add(Echipa e) {
        this.repo.add(e);
    }

    public Echipa[] getClasament() {
        return this.repo.getClasament();
    }

    public void setEtapa(int et){
        repo.setEtapa(et);
    }

    public void setScor(String prima, String adoua, int scorPrima, int scorADoua){
        if(scorPrima > scorADoua) {
            repo.aduna(prima,0,0,1,scorPrima,3);
            repo.aduna(adoua,1,0,0,scorADoua,0);
        }
        else if (scorADoua == scorPrima){
            repo.aduna(prima,0,1,0,scorPrima,1);
            repo.aduna(adoua,0,1,0,scorADoua,1);
        }
        else {
            repo.aduna(prima,1,0,0,scorPrima,0);
            repo.aduna(adoua,0,0,1,scorADoua,3);
        }
    }

//    public void delete(String e)
//    {
//
//        for(int i=0;i<repo.getSize();i++)
//            if(clasament[i].getCota() == e)
//                repo.delete(i);
//    }
}
