package com.company;
import java.io.*;
import java.util.Scanner;

public class Main {

    public static int citireOptiune (String msj){
        try{
            System.out.print(msj);
            Scanner s = new Scanner(System.in);
            int I = s.nextInt();
            return I;
        }
        catch(Exception ex){
            System.out.print("Ai gresit, mai incearca!");
            return citireOptiune(msj);

        }
    }



    public static int citireDinFisier(Cauciuc C[]) {
        int n = 0;
        try {
            BufferedReader fisIn = new BufferedReader(new FileReader(
                    "/Users/ciprian/Desktop/facultate/sem3/MAP_Java/Lab5/src/com/company/Bd.txt"));
            String nume;
            String tip;
            int stocI;
            int vandute;
            int pretU;

            String s;
            String[] felii;
            while ((s = fisIn.readLine()) != null) {

                felii = s.split(",");
                nume = felii[0];
                tip = felii[1];
                stocI = Integer.parseInt(felii[2]);
                vandute = Integer.parseInt(felii[3]);
                pretU = Integer.parseInt(felii[4]);

                C[n] = new Cauciuc();
                C[n].setDenumire(nume);
                C[n].setTip(tip);
                C[n].setStocInitial(stocI);
                C[n].setVandute(vandute);
                C[n].setPretUnitar(pretU);
                n++;
            }
            fisIn.close();
        }
        catch (Exception e) {
            System.out.println(e.getMessage());
            e.printStackTrace();
        }
        return n;
    }

    public static void afisareTot(int n, Cauciuc C[]){
        for(int i=0; i<n; i++){
            System.out.print(C[i].getDenumire()+"    ");
            System.out.print(C[i].getTip()+"        ");
            System.out.print(C[i].getStocInitial()+"      ");
            System.out.print(C[i].getVandute()+"      ");
            System.out.print(C[i].getPretUnitar()+"     ");
            System.out.println("");
        }
    }
    public static void mainSupportDisponibile(){
        System.out.println("Anvelope disponibile: "+"      ");
        System.out.println("");
        System.out.print("Denumire"+"         ");
        System.out.print("Tip"+"       ");
        System.out.print("Disponibile"+"       ");
        System.out.print("Pret Unitar"+"       ");
    }
    public static void afisareStocDisponibil(int n, Cauciuc C[]){
        int disponibile;
        mainSupportDisponibile();
        for(int i=0; i<n; i++){
            disponibile = C[i].getStocInitial()-C[i].getVandute();
            if(disponibile > 0) {
                System.out.println("");
                System.out.print(C[i].getDenumire() + "    ");
                System.out.print(C[i].getTip() + "        ");
                System.out.print(disponibile + "      ");
                System.out.print(C[i].getPretUnitar() + "     ");
            }
        }
    }
    public static void mainSupportIndisponibile(){
        System.out.println("Anvelope indisponibile: "+"      ");
        System.out.println("");
        System.out.print("Denumire"+"         ");
        System.out.print("Tip"+"       ");
        System.out.print("Pret Unitar"+"       ");
    }
    public static void afisareStocIndisponibil(int n, Cauciuc C[]){
        int indisponibile;
        mainSupportIndisponibile();
        for(int i=0; i<n; i++){
            indisponibile = C[i].getStocInitial()-C[i].getVandute();
            if(indisponibile <= 0) {
                System.out.println("");
                System.out.print(C[i].getDenumire() + "    ");
                System.out.print(C[i].getTip() + "        ");
                System.out.print(C[i].getPretUnitar() + "     ");
                System.out.println("");
            }

        }
    }

    public static void cumparareAnvelopa(int n, Cauciuc C[]) {
        Scanner s = new Scanner(System.in);
        System.out.print("Da-ti numele anvelopei:");
        String nume = s.next();
        System.out.print("Da-ti tipul anvelopei:");
        String tip = s.next();
        boolean gasit = false;

        for (int i = 0; i < n; i++) {
            if (C[i].getDenumire().equals(nume)  && C[i].getTip().equals(tip)){
                gasit = true;
                int disponibile = C[i].getStocInitial() - C[i].getVandute();
                if (disponibile > 0) {
                    System.out.println("Avem " + disponibile + " anvelope de acest model disponibile.");
                    System.out.println("Da-ti numarul de anvelope care vreti sa le cumparati: ");
                    int nr = s.nextInt();
                    if(nr > disponibile){
                        System.out.println("Mai avem doar "+ disponibile + " de anvelope disponibile!!!");
                    }else {
                        int vandute = C[i].getVandute() + nr;
                        C[i].setVandute(vandute);
                    }
                } else {
                    System.out.println("Nu mai avem acest produs in stoc.");
                }
            }
        }
        if(gasit == false){
            System.out.println("Nu avem acest produs.");
        }
    }

    public static int supportMain(){
        System.out.println("");
        System.out.println("1. Citire date din fisier.");
        System.out.println("2. Afisare marfa.");
        System.out.println("3. Afisare stoc disponibil.");
        System.out.println("4. Afisare stoc epuizat.");
        System.out.println("5. Cumparare anvelopa.");
        System.out.println("0. Exit.");
        int op = citireOptiune("Da-ti o optiune:");
        return op;
    }

    public static void main(String[] args) {
        int lungime = 0;
        int op = supportMain();
        Cauciuc C[] = new Cauciuc[100];


        while(op!=0){
            switch (op){
                case 1:
                    lungime = citireDinFisier(C);
                    System.out.println("Datele din fisier au fost citite.");
                    break;

                case 2:
                    afisareTot(lungime,C);
                    break;
                case 3:
                    afisareStocDisponibil(lungime,C);
                    break;
                case 4:
                    afisareStocIndisponibil(lungime,C);
                    break;
                case 5:
                    cumparareAnvelopa(lungime,C);
                    break;
                default:
                    System.out.println("Ai gresit optiunea, mai incearca!!!");
            }
            op = supportMain();
        }

    }
}
