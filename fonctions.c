#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "fonctions.h"
int count=0;
int n=0,m=0;

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void menu(char T[24],char T2[24]) // fonction d'affichage du menu de démarage du jeu
{
    int a;
    char x;
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
        //system("cls");
        //plateau(T,T2);
        system("cls");
        p:
        plateau(T,T2);
        p1:
        printf("\n\n------->Donner la position du pion :\n");
        scanf("%s",&x);
        if (condition(count,x,T,T2)==0)
        {
            printf("vous devez choisir l'un des pions disponible");
            goto p1;
        }
        changer(count,x,T,T2);
        nbrPions(count);
        count+=1;
        goto p;

    case 2 :
        system("cls");
        plateau(T,T2);

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

void plateau(char T[24],char T2[24])
{
system("cls");
Color(12,0);
char str[]="\t\t\t\t\t\t ___________________________________________________________________\n\t\t\t\t\t\t|      _                    __  __                   _   _          |\n\t\t\t\t\t\t|     | |   ___    _   _   |  \\/  |   ___    _   _  | | (_)  _ __   |\n\t\t\t\t\t\t|  _  | |  / _ \\  | | | |  | |\\/| |  / _ \\  | | | | | | | | | '_ \\  |\n\t\t\t\t\t\t| | |_| | |  __/  | |_| |  | |  | | | (_) | | |_| | | | | | | | | | |\n\t\t\t\t\t\t|  \\___/   \\___|   \\__,_|  |_|  |_|  \\___/   \\__,_| |_| |_| |_| |_| |\n\t\t\t\t\t\t-___________________________________________________________________-";
printf("%s",str);
printf("\n\n\n\n\t\t\t\t\t\t    ");coloriage(0,T,T2);printf("---------------------------");coloriage(1,T,T2);printf("--------------------------%");coloriage(2,T,T2);printf(" ");
printf("\n\t\t\t\t\t\t     |                             |                            |");
printf("\n\t\t\t\t\t\t     |                             |                            |");
printf("\n\t\t\t\t\t\t     |                             |                            |");
printf("\n\t\t\t\t\t\t     |        ");coloriage(3,T,T2);printf("-----------------");coloriage(4,T,T2);printf("-----------------");coloriage(5,T,T2);printf("       |");
printf("\n\t\t\t\t\t\t     |         |                   |                   |        |");
printf("\n\t\t\t\t\t\t     |         |                   |                   |        |");
printf("\n\t\t\t\t\t\t     |         |                   |                   |        |");
printf("\n\t\t\t\t\t\t     |         |                   |                   |        |");
printf("\n\t\t\t\t\t\t     |         |                   |                   |        |");
printf("\n\t\t\t\t\t\t     |         |                   |                   |        |");
printf("\n\t\t\t\t\t\t     |         |      ");coloriage(6,T,T2);printf("---------");coloriage(7,T,T2);printf("--------");coloriage(8,T,T2);printf("       |        |");
printf("\n\t\t\t\t\t\t     |         |       |                      |        |        |");
printf("\n\t\t\t\t\t\t     |         |       |                      |        |        |");
printf("\n\t\t\t\t\t\t     |         |       |                      |        |        |");
printf("\n\t\t\t\t\t\t     |         |       |                      |        |        |");
printf("\n\t\t\t\t\t\t     |         |       |                      |        |        |");
printf("\n\t\t\t\t\t\t    ");coloriage(9,T,T2);printf("-------");coloriage(10,T,T2);printf("-----");coloriage(11,T,T2);printf("                    ");coloriage(12,T,T2);printf("------");coloriage(13,T,T2);printf("------");coloriage(14,T,T2);
printf("\n\t\t\t\t\t\t     |         |       |                      |        |        |");
printf("\n\t\t\t\t\t\t     |         |       |                      |        |        |");Color(8,0);printf("\t Joueur1 : ");Color(8,0);printf(" %d Pions",n);Color(15,0);
printf("\n\t\t\t\t\t\t     |         |       |                      |        |        |");Color(4,0);printf("\t Joueur2 : ");Color(4,0);printf(" %d Pions",m);Color(15,0);
printf("\n\t\t\t\t\t\t     |         |       |                      |        |        |");
printf("\n\t\t\t\t\t\t     |         |       |                      |        |        |");
printf("\n\t\t\t\t\t\t     |         |      ");coloriage(15,T,T2);printf("---------");coloriage(16,T,T2);printf("--------");coloriage(17,T,T2);printf("       |        |");
printf("\n\t\t\t\t\t\t     |         |                   |                   |        |");
printf("\n\t\t\t\t\t\t     |         |                   |                   |        |");
printf("\n\t\t\t\t\t\t     |         |                   |                   |        |");
printf("\n\t\t\t\t\t\t     |         |                   |                   |        |");
printf("\n\t\t\t\t\t\t     |         |                   |                   |        |");
printf("\n\t\t\t\t\t\t     |         |                   |                   |        |");
printf("\n\t\t\t\t\t\t     |        ");coloriage(18,T,T2);printf("-----------------");coloriage(19,T,T2);printf("-----------------");coloriage(20,T,T2);printf("       |");
printf("\n\t\t\t\t\t\t     |                             |                            |");
printf("\n\t\t\t\t\t\t     |                             |                            |");
printf("\n\t\t\t\t\t\t     |                             |                            |");
printf("\n\t\t\t\t\t\t    ");coloriage(21,T,T2);printf("---------------------------");coloriage(22,T,T2);printf("--------------------------");coloriage(23,T,T2);



}


/*void execute()
{
    int i;
    char a;
    char plt[]="\n\n\n\n\t\t\t\t\t\t    a----------------------------b----------------------------c\n\t\t\t\t\t\t    |                            |                            |\n\t\t\t\t\t\t    |                            |                            |\n\t\t\t\t\t\t    |                            |                            |\n\t\t\t\t\t\t    |        d-------------------e-------------------f        |\n\t\t\t\t\t\t    |        |                   |                   |        |\n\t\t\t\t\t\t    |        |                   |                   |        |\n\t\t\t\t\t\t    |        |                   |                   |        |\n\t\t\t\t\t\t    |        |                   |                   |        |\n\t\t\t\t\t\t    |        |       g-----------h----------i        |        |\n\t\t\t\t\t\t    |        |       |                      |        |        |\n\t\t\t\t\t\t    |        |       |                      |        |        |\n\t\t\t\t\t\t    |        |       |                      |        |        |\n\t\t\t\t\t\t    |        |       |                      |        |        |\n\t\t\t\t\t\t    |        |       |                      |        |        |\n\t\t\t\t\t\t    j--------k-------l                      m--------n--------o\n\t\t\t\t\t\t    |        |       |                      |        |        |\n\t\t\t\t\t\t    |        |       |                      |        |        |\n\t\t\t\t\t\t    |        |       |                      |        |        |\n\t\t\t\t\t\t    |        |       |                      |        |        |\n\t\t\t\t\t\t    |        |       |                      |        |        |\n\t\t\t\t\t\t    |        |       p-----------q----------r        |        |\n\t\t\t\t\t\t    |        |                   |                   |        |\n\t\t\t\t\t\t    |        |                   |                   |        |\n\t\t\t\t\t\t    |        |                   |                   |        |\n\t\t\t\t\t\t    |        s-------------------t-------------------u        |\n\t\t\t\t\t\t    |                            |                            |\n\t\t\t\t\t\t    |                            |                            |\n\t\t\t\t\t\t    |                            |                            |\n\t\t\t\t\t\t    v----------------------------w----------------------------x";
	char pion;
	plateau(T,T2);
	scanf("%s",&a);
   // i=posPion(plt,a);

    plt[i]='x';              //positionner le pion
    system("cls");
    plateau(plt);
    getch();

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

}

int Player(int count1)
{
    int a;
    if(count1%2==0)
        {a=1;}
    else
        {a=2;}
    return a;
}

void coloriage(int x,char T[24],char T2[24])
{
            if (T2[x]=='$')
                {
                Color(0,8);printf(" %c ",T[x]);Color(15,0);
                }
            if (T2[x]=='*')
            {
                Color(0,4);printf(" %c ",T[x]);Color(15,0);
            }
            if (T2[x]!='$' && T2[x]!='*')
              {
                  Color(1,0);printf(" %c ",T[x]);Color(15,0);
              }

}


void changer(int count1,char x,char T[24],char T2[24])
{
    for (int i=0;i<24;i++)
    {
        int a;
        a=Player(count1);
        if (T[i]==x)
        {
            if(a==1)
            {
                T2[i]='$';
            }
            else
               {
                   T2[i]='*';
               }
        }
    }
}

void nbrPions(int count1)
{
    int a=0;
    a=Player(count1);
    if(a==1)
        n++;
    else
        m++;


}

int condition(int count1, char s, char T[24],char T2[24])
{
    int c=0;
    int i,a=Player(count1);
    for (i=0;i<24;i++)
    {
        if (T[i]==s)
        {
            c=1;
            break;
        }
    }
        if (T2[i]=='*'  || T2[i]=='$')
        {
            c=0;
        }

    return c;
}



/*int posPion(char *tab, char *x)  // permet de donner la position du pion choisis par l'utilisateur dans le tableau
{
    int i,j,y;
    j=strlen(tab);
    for(i=0;i<j;i++)
    {
        if(x==tab[i])
            y=i;
            break;
    }
    return y;
}*/


