package com.company;

public class Cauciuc {
    private String denumire;
    private String tip;
    private int stocInitial;
    private int vandute;
    private int pretUnitar;

    public Cauciuc(){
        this.denumire = null;
        this.tip = null;
        this.stocInitial = 0;
        this.vandute = 0;
        this.pretUnitar = 0;
    }

    public Cauciuc(String d, String t, int s, int v, int p){
        this.denumire = d;
        this.tip = t;
        this.stocInitial = s;
        this.vandute = v;
        this.pretUnitar = p;
    }

    public Cauciuc(Cauciuc c){
        this.denumire = c.denumire;
        this.tip = c.tip;
        this.stocInitial = c.stocInitial;
        this.vandute = c.vandute;
        this.pretUnitar = c.pretUnitar;
    }

    public void setDenumire(String d){
        this.denumire = d;
    }
    public  String getDenumire(){
        return this.denumire;
    }

    public void setTip(String t){
        this.tip = t;
    }
    public String getTip(){
        return this.tip;
    }

    public void setStocInitial(int s){
        this.stocInitial = s;
    }
    public int getStocInitial(){
        return this.stocInitial;
    }

    public void setVandute(int v){
        this.vandute = v;
    }
    public int getVandute(){
        return this.vandute;
    }

    public void setPretUnitar(int pretUnitar) {
        this.pretUnitar = pretUnitar;
    }
    public int getPretUnitar(){
        return this.pretUnitar;
    }
}
