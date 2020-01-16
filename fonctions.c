#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "fonctions.h"
int count=0;z=0;
int n=0,m=0;
int T3[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};   // les moulins
int T4[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};   // les pions allignés

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void menu(char T[24],char T2[24]) // fonction d'affichage du menu de démarage du jeu
{
    int a,i,j;
    char x,y;
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
    printf("\tveuillez entrer votre choix:  ");
    scanf("%d",&a);
    switch(a)
    {
    case 1 :                      // Joueur contre Joueur
        system("cls");
        p:
        plateau(T,T2);
        p1:
        MOULIN(T2,T3,T4);
        for(i=0;i<16;i++)
        {
            if(T3[i]==i+1)
            {
                if(Player(count)==2)
                {
                    printf("\tMoulin pour le 1er joueur\n\n");
                    T3[i]=100;
                    printf("\t\tA vous de capturer\n\t");
                    w:
                    scanf("%s",&y);
                    j=posPion(y,T);
                    //else
                    if(T2[j]=='*')
                    {
                        T2[j]=T[j];
                    }
                    else
                    {
                        printf("Vous devez capturer l'un des pions de votre adversaire");
                        goto w;
                    }
                }
                if(Player(count)==1)
                {
                    printf("\tMoulin pour le 2eme joueur\n\n");
                    T3[i]=100;
                    printf("\t\tA vous de capturer");
                    w1:
                    scanf("%s",&y);
                    j=posPion(y,T);
                    //else
                    if(T2[j]=='$')
                    {
                        T2[j]=T[j];
                    }
                    else
                    {
                        printf("Vous devez capturer l'un des pions de votre adversaire");
                        goto w1;
                    }
                }
            }
        }
        /*if(Moulin(T2)==1)
        {
            Color(8,0);printf("\tMoulin pour le joueur 1");
        }
        if(Moulin(T2)==2)
        {
            Color(4,0);printf("\tMoulin pour le joueur 2");
        }
        z=0;*/

        /*if(MOULIN(T2,T3,T4)==1)
        {
            if(Player(count)==1)
            {
                printf("\tMoulin pour le 1er Joueur");
            }
            else
                printf("\tMoulin pour le 2eme Joueur");
            for(i=0;i<16;i++)
            {
                if(T3[i]==i+1)
                    T3[i]=0;
            }
        }*/

        /*if(Player(count)==1)
        {
            Color(8,0);printf("\n\tJoueur 1 a vous de jouer");Color(15,0);
        }
        else
            {Color(4,0);printf("\n\tJoueur 2 a vous de jouer");Color(15,0);}*/

        printf("\n\n\t----->  Donner la position du pion :  ");
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
    }
}

void plateau(char T[24],char T2[24])      //Permet l'affichage de la grille
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

int Player(int count1)   // permet de distinguer entre les joueurs
{
    int a;
    if(count1%2==0)
        {a=1;}
    else
        {a=2;}
    return a;
}

void coloriage(int x,char T[24],char T2[24])    // Permet l'affichage au debut et le colorige de chaque pions choisis par chaque joueur
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


void changer(int count1,char x,char T[24],char T2[24])   // permet de stocker les pions choisis par chaque joueur dans un autre tableau T2
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

void nbrPions(int count1)   // permet de calculer le nombre de pions posé par un joueur
{
    int a=0;
    a=Player(count1);
    if(a==1)
        n++;
    else
        m++;


}

int condition(int count1, char s, char T[24],char T2[24])     // Permet de ne pas repeter le mm choix d'un mm pions (case pleine)
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



/*nt Moulin(char T2[24])
{
    if((T2[0]=='$' && T2[1]=='$' && T2[2]=='$') || (T2[3]=='$' && T2[4]=='$' && T2[5]=='$') || (T2[6]=='$' && T2[7]=='$' && T2[8]=='$') || (T2[9]=='$' && T2[10]=='$' && T2[2]=='$') || (T2[11]=='$' && T2[1]=='$' && T2[12]=='$') || (T2[13]=='$' && T2[14]=='$' && T2[15]=='$') || (T2[16]=='$' && T2[17]=='$' && T2[18]=='$') || (T2[19]=='$' && T2[20]=='$' && T2[21]=='$') || (T2[22]=='$' && T2[23]=='$' && T2[2]=='$') || (T2[0]=='$' && T2[1]=='$' && T2[2]=='$') || (T2[0]=='$' && T2[1]=='$' && T2[2]=='$') || (T2[0]=='$' && T2[1]=='$' && T2[2]=='$') || (T2[0]=='$' && T2[1]=='$' && T2[2]=='$') || (T2[0]=='$' && T2[1]=='$' && T2[2]=='$') || (T2[0]=='$' && T2[1]=='$' && T2[2]=='$')||(T2[0]=='$' && T2[1]=='$' && T2[2]=='$'))
        z=1;
    if((T2[0]=='*' && T2[1]=='*' && T2[2]=='*') || (T2[3]=='*' && T2[4]=='*' && T2[5]=='*') || (T2[6]=='*-' && T2[7]=='*' && T2[8]=='*') || (T2[9]=='*' && T2[10]=='*' && T2[2]=='*') || (T2[11]=='*' && T2[1]=='*' && T2[12]=='*') || (T2[13]=='*' && T2[14]=='*' && T2[15]=='*') || (T2[16]=='*' && T2[17]=='*' && T2[18]=='*') || (T2[19]=='*' && T2[20]=='*' && T2[21]=='*') || (T2[22]=='*' && T2[23]=='*' && T2[2]=='*') || (T2[0]=='*' && T2[1]=='*' && T2[2]=='*') || (T2[0]=='*' && T2[1]=='*' && T2[2]=='*') || (T2[0]=='*' && T2[1]=='*' && T2[2]=='*') || (T2[0]=='*' && T2[1]=='*' && T2[2]=='*') || (T2[0]=='*' && T2[1]=='*' && T2[2]=='*') || (T2[0]=='*' && T2[1]=='*' && T2[2]=='*')||(T2[0]=='*' && T2[1]=='*' && T2[2]=='*'))
        z=2;
    return z;

}*/

int MOULIN(char T2[24])   // T3 et T4 : des variables globales
{
    if((T2[0]=='$' && T2[1]=='$' && T2[2]=='$') || (T2[0]=='*' && T2[1]=='*' && T2[2]=='*'))
    {
    if(T3[0]==0)
    {
        T3[0]=1;
        T4[0]=1;
    }
    }
    if((T2[3]=='$' && T2[4]==  '$' && T2[5]=='$') || (T2[3]=='*' && T2[4]=='*' && T2[5]=='*'))
    {
    if(T3[1]==0)
    {
        T3[1]=2;
        T4[1]=2;
    }
    }
    if((T2[6]=='$' && T2[7]=='$' && T2[8]=='$') || (T2[6]=='*' && T2[7]=='*' && T2[8]=='*'))
    {
    if(T3[2]==0)
    {
        T3[2]=3;
        T4[2]=3;
    }
    }
    if((T2[9]=='$' && T2[10]=='$' && T2[11]=='$') || (T2[9]=='*' && T2[10]=='*' && T2[11]=='*'))
    {
    if(T3[3]==0)
    {
        T3[3]=4;
        T4[3]=4;
    }
    }
    if((T2[12]=='$' && T2[13]=='$' && T2[14]=='$') || (T2[12]=='*' && T2[13]=='*' && T2[14]=='*'))
    {
    if(T3[4]==0)
    {
        T3[4]=5;
        T4[4]=5;
    }
    }
    if((T2[15]=='$' && T2[16]=='$' && T2[17]=='$') || (T2[15]=='*' && T2[16]=='*' && T2[17]=='*'))
    {
    if(T3[5]==0)
    {
        T3[5]=6;
        T4[5]=6;
    }
    }
    if((T2[18]=='$' && T2[19]=='$' && T2[20]=='$') || (T2[18]=='*' && T2[19]=='*' && T2[20]=='*'))
    {
    if(T3[6]==0)
    {
        T3[6]=7;
        T4[6]=7;
    }
    }
    if((T2[21]=='$' && T2[22]=='$' && T2[23]=='$') || (T2[21]=='*' && T2[22]=='*' && T2[23]=='*'))
    {
    if(T3[7]==0)
    {
        T3[7]=8;
        T4[7]=8;
    }
    }
    if((T2[0]=='$' && T2[9]=='$' && T2[21]=='$') || (T2[0]=='*' && T2[9]=='*' && T2[21]=='*'))
    {
    if(T3[8]==0)
    {
        T3[8]=9;
        T4[8]=9;
    }
    }
    if((T2[3]=='$' && T2[10]=='$' && T2[18]=='$') || (T2[3]=='*' && T2[10]=='*' && T2[18]=='*'))
    {
    if(T3[9]==0)
    {
        T3[9]=10;
        T4[9]=10;
    }
    }
    if((T2[6]=='$' && T2[11]=='$' && T2[15]=='$') || (T2[6]=='*' && T2[11]=='*' && T2[15]=='*'))
    {
    if(T3[10]==0)
    {
        T3[10]=11;
        T4[10]=11;
    }
    }
    if((T2[1]=='$' && T2[4]=='$' && T2[7]=='$') || (T2[1]=='*' && T2[4]=='*' && T2[7]=='*'))
    {
    if(T3[11]==0)
    {
        T3[11]=12;
        T4[11]=12;
    }
    }
    if((T2[16]=='$' && T2[19]=='$' && T2[22]=='$') || (T2[16]=='*' && T2[19]=='*' && T2[22]=='*'))
    {
    if(T3[12]==0)
    {
        T3[12]=13;
        T4[12]=13;
    }

    }
    if((T2[8]=='$' && T2[12]=='$' && T2[17]=='$') || (T2[8]=='*' && T2[12]=='*' && T2[17]=='*'))
    {
    if(T3[13]==0)
    {
        T3[13]=14;
        T4[13]=14;
    }

    }
    if((T2[5]=='$' && T2[13]=='$' && T2[20]=='$') || (T2[5]=='*' && T2[13]=='*' && T2[20]=='*'))
    {
    if(T3[14]==0)
    {
        T3[14]=15;
        T4[14]=15;
    }

    }
    if((T2[2]=='$' && T2[14]=='$' && T2[23]=='$') || (T2[2]=='*' && T2[14]=='*' && T2[23]=='*'))
    {
    if(T3[15]==0)
    {
        T3[15]=16;
        T4[15]=16;
    }

    }

}

int posPion(int x,char T2[24])  // permet de donner la position du pion choisis par l'utilisateur dans le tableau
{
    int i,y;
    for(i=0;i<24;i++)
    {
        if(x==T2[i])
            y=i;
            break;
    }
    return y;
}

/*void Moulin(char T2[24],int T33[16],int T44[16])
{
    if(MOULIN(T2,T33,T44)==1)
}*/






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
