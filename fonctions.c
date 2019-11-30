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
        //regles();
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

/*void regles()
{

}*/


/*void JvsJ()
{

}*/
/*void JvsM()
{

}*/

