#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "fonctions.h"


void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void menu()
{
    int a;

    Color(12,0);
    char str[]="\t\t\t\t\t\t ___________________________________________________________________\n\t\t\t\t\t\t|      _                    __  __                   _   _          |\n\t\t\t\t\t\t|     | |   ___    _   _   |  \\/  |   ___    _   _  | | (_)  _ __   |\n\t\t\t\t\t\t|  _  | |  / _ \\  | | | |  | |\\/| |  / _ \\  | | | | | | | | | '_ \\  |\n\t\t\t\t\t\t| | |_| | |  __/  | |_| |  | |  | | | (_) | | |_| | | | | | | | | | |\n\t\t\t\t\t\t|  \\___/   \\___|   \\__,_|  |_|  |_|  \\___/   \\__,_| |_| |_| |_| |_| |\n\t\t\t\t\t\t-___________________________________________________________________-";
    printf("%s\n\n\n\n",str);
    Color(14,0);
    printf("\t\t\t\t\t\t\t\t\t _______________________ \n");
    printf("\t\t\t\t\t\t\t\t\t|                       |\n");
    printf("\t\t\t\t\t\t\t\t\t|   1.Joueur VS Joueur  |\n");
    printf("\t\t\t\t\t\t\t\t\t|_______________________|\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t\t _______________________ \n");
    printf("\t\t\t\t\t\t\t\t\t|                       |\n");
    printf("\t\t\t\t\t\t\t\t\t|  2.Joueur VS Machine  |\n");
    printf("\t\t\t\t\t\t\t\t\t|_______________________|\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t\t _______________________ \n");
    printf("\t\t\t\t\t\t\t\t\t|                       |\n");
    printf("\t\t\t\t\t\t\t\t\t|       3.Regles        |\n");
    printf("\t\t\t\t\t\t\t\t\t|_______________________|\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t\t _______________________ \n");
    printf("\t\t\t\t\t\t\t\t\t|                       |\n");
    printf("\t\t\t\t\t\t\t\t\t|        4.Exit         |\n");
    printf("\t\t\t\t\t\t\t\t\t|_______________________|\n");
    printf("\n\n\n\n");
    h:
    printf("veuillez entrer votre choix: ");
    scanf("%d",&a);
    switch(a)
    {
    case 1 :
        system("cls");
        plateau();
        //JvsJ();
    case 2 :
        system("cls");
        plateau();
        //JvsM();
    case 3 :
        system("cls");
        regles();
    case 4 :
        exit(EXIT_SUCCESS);
    default :
        printf("\n\nvous devez choisir un nombre entre 1 et 4 \n\n\n\n ");
        goto h;
        //system("cls");
        //menu();

    }
}

void plateau()
{
	int i;
    char pion;
    Color(12,0);
    char str[]="\t\t\t\t\t\t ___________________________________________________________________\n\t\t\t\t\t\t|      _                    __  __                   _   _          |\n\t\t\t\t\t\t|     | |   ___    _   _   |  \\/  |   ___    _   _  | | (_)  _ __   |\n\t\t\t\t\t\t|  _  | |  / _ \\  | | | |  | |\\/| |  / _ \\  | | | | | | | | | '_ \\  |\n\t\t\t\t\t\t| | |_| | |  __/  | |_| |  | |  | | | (_) | | |_| | | | | | | | | | |\n\t\t\t\t\t\t|  \\___/   \\___|   \\__,_|  |_|  |_|  \\___/   \\__,_| |_| |_| |_| |_| |\n\t\t\t\t\t\t-___________________________________________________________________-";
    printf("%s\n\n\n\n",str);
    Color(14,0);
    char plt[]="\n\n\n\n\t\t\t\t\t\t    a----------------------------b----------------------------c\n\t\t\t\t\t\t    |                            |                            |\n\t\t\t\t\t\t    |                            |                            |\n\t\t\t\t\t\t    |                            |                            |\n\t\t\t\t\t\t    |        d-------------------e-------------------f        |\n\t\t\t\t\t\t    |        |                   |                   |        |\n\t\t\t\t\t\t    |        |                   |                   |        |\n\t\t\t\t\t\t    |        |                   |                   |        |\n\t\t\t\t\t\t    |        |                   |                   |        |\n\t\t\t\t\t\t    |        |       g-----------h----------i        |        |\n\t\t\t\t\t\t    |        |       |                      |        |        |\n\t\t\t\t\t\t    |        |       |                      |        |        |\n\t\t\t\t\t\t    |        |       |                      |        |        |\n\t\t\t\t\t\t    |        |       |                      |        |        |\n\t\t\t\t\t\t    |        |       |                      |        |        |\n\t\t\t\t\t\t    j--------k-------l                      m--------n--------o\n\t\t\t\t\t\t    |        |       |                      |        |        |\n\t\t\t\t\t\t    |        |       |                      |        |        |\n\t\t\t\t\t\t    |        |       |                      |        |        |\n\t\t\t\t\t\t    |        |       |                      |        |        |\n\t\t\t\t\t\t    |        |       |                      |        |        |\n\t\t\t\t\t\t    |        |       p-----------q----------r        |        |\n\t\t\t\t\t\t    |        |                   |                   |        |\n\t\t\t\t\t\t    |        |                   |                   |        |\n\t\t\t\t\t\t    |        |                   |                   |        |\n\t\t\t\t\t\t    |        s-------------------t-------------------u        |\n\t\t\t\t\t\t    |                            |                            |\n\t\t\t\t\t\t    |                            |                            |\n\t\t\t\t\t\t    |                            |                            |\n\t\t\t\t\t\t    v----------------------------w----------------------------x";
    printf("%s",plt);
    printf("\n\n\n\n\n----> Entrez votre choix : ");
    scanf("%c",&pion);
    //i=posPion(plt,pion);
    //plt[i]=color(14,2);
    getch();

}

/*int posPion(tab,x)  // permet de donner la position du pion choisis par l'utilisateur dans le tableau
{
    int i,j;
    j=strlen(tab);
    for(i=0,i<j,i++)
    {
        if(x==tab[i])
            return i;
    }
}*/

void regles()
{
char str[]="\t\t\t\t\t\t _______________________________\n\t\t\t\t\t\t|  _____            _           |\n\t\t\t\t\t\t| |  __ \\          | |          |\n\t\t\t\t\t\t| | |__) |___  __ _| | ___  ___ |\n\t\t\t\t\t\t| |  _  // _ \\/ _` | |/ _ \\/ __||\n\t\t\t\t\t\t| | | \\ \\  __/ (_| | |  __/\\__ \\|\n\t\t\t\t\t\t| |_|  \\_\\___|\\__, |_|\\___||___/|\n\t\t\t\t\t\t|              __/ |            |\n\t\t\t\t\t\t|             |___/             |\n\t\t\t\t\t\t|_______________________________|";
Color(10,0);
printf("%s\n\n\n\n",str);
Color(9,0);
printf("\n\n\n     _________________________\n    |                         |\n    |  LE DEROULEMENT DU JEU  |\n    |_________________________|\n");
Color(15,0);
printf("\nLe jeu se deroule en deux phases :");
Color(4,0);
printf("\n\n\nPhase 1 - La pose\n-----------------");
Color(15,0);
printf("\nLes joueurs jouent a tour de role.\nChaque joueur place un pion.\nLe but est aligner trois pions en suivant une ligne.\nLorsqu un alignement est forme sur une ligne, les pions de cet alignement sont proteges.\nLe joueur peut alors capturer un pion adverse qui se trouve sur le plateau\n(sauf ceux presents dans un alignement de trois pions).\nLorsque tous les pions sont en places, la seconde phase commence.");
Color(4,0);
printf("\n\n\nPhase 2 - Le mouvement\n----------------------");
Color(15,0);
printf("\nA tour de role, chaque joueur deplace un pion en suivant les lignes vers une case libre.\nQuand un joueur parvient a former un nouvel alignement, il prend un pion du adversaire\na condition que ce pion ne fasse pas partie dans un moulin.");
Color(9,0);
printf("\n\n\n\t    ___________\n\t   |           |\n\t   |  Le But   |\n\t   |___________|\n");
Color(15,0);
printf("\nFaire des alignements de trois pions pour pouvoir capturer les pions du joueur adversse et le bloquer.\nLe jeu est arrete si un joueur a deux pions seulement ou ne peut plus en bouger.");
system("pause>null");

}

/*void JvsJ()
{

}*/
/*void JvsM()
{

}*/

