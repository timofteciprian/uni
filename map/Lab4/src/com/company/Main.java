package com.company;
import java.util.Scanner;

public class Main {

    public static void supportMain(){
        System.out.println("1. Citire echipe");
        System.out.println("2. Adaugare etapa si scorul obtinut");
        System.out.println("3. Afisare.");
    }

    public static  void fa()
    {
        Controller ctrl=new Controller();
        Scanner scan;

        int com = 1;
        while(com!=0) {
            supportMain();
            System.out.println("Adauga comanda:");
            scan = new Scanner(System.in);
            com = scan.nextInt();
            switch (com){
                case 1: {
                    Echipa c = new Echipa("Steaua", 0, 0, 0, 0, 0, 0);
                    ctrl.add(c);
                    Echipa c1 = new Echipa("Dinamo", 0, 0, 0, 0, 0, 0);
                    ctrl.add(c1);
                    Echipa c2 = new Echipa("Rapid", 0, 0, 0, 0, 0, 0);
                    ctrl.add(c2);
                    Echipa c3 = new Echipa("CSM", 0, 0, 0, 0, 0, 0);
                    ctrl.add(c3);
                    Echipa c4 = new Echipa("PoliTim", 0, 0, 0, 0, 0, 0);
                    ctrl.add(c4);
                    Echipa c5 = new Echipa("CFR", 0, 0, 0, 0, 0, 0);
                    ctrl.add(c5);

                }
                case 2: {
                    scan = new Scanner(System.in);
                    Echipa clasament[] = ctrl.getClasament();
                    int et = ctrl.repo.clasament[0].getEtapa();
                    ctrl.setEtapa(et + 1);
                    et = ctrl.repo.clasament[0].getEtapa();
                    System.out.println("Etapa: " + et);


                    System.out.println("Echipe:");
                    for (int i = 0; i < ctrl.repo.getSize(); i++)
                        System.out.print(clasament[i].getNume() + " ");
                    System.out.println();
                    System.out.println("Adauga echipele care au jucat si scorul obtinut.");

                    for (int i = 0; i <= 1; i++) {
                        System.out.println("Prima echipa:");
                        String prima = scan.nextLine();
                        System.out.println("A doua echipa:");
                        String adoua = scan.nextLine();
                        System.out.println("Adauga scorul gazdei:");
                        int scorPrima = scan.nextInt();
                        System.out.println("Adauga scorul oaspetilor:");
                        int scorADoua = scan.nextInt();
                        ctrl.setScor(prima, adoua, scorPrima, scorADoua);
                    }
                }
                case 3: {
                    Echipa clasament[] = ctrl.getClasament();
                    System.out.print("NUME" + "   ");
                    System.out.print("ET" + " ");
                    System.out.print('V' + " ");
                    System.out.print("E" + " ");
                    System.out.print("I" + " ");
                    System.out.print("G" + " ");
                    System.out.println();
                    for (int i = 0; i < ctrl.repo.getSize(); i++) {
                        System.out.print(clasament[i].getNume() + " ");
                        System.out.print(clasament[i].getEtapa() + " ");
                        System.out.print(clasament[i].getVictorii() + " ");
                        System.out.print(clasament[i].getEgaluri() + " ");
                        System.out.print(clasament[i].getInfrangeri() + " ");
                        System.out.print(clasament[i].getGoluri() + " ");
                        System.out.println();
                    }

                }
            }

        }
    }
    public static void main(String[] args)
    {
        fa();
//        citesteEtapa();
//        afisare();
    }
}
