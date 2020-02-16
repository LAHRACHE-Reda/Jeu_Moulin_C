#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "fonctions.h"
char J1[25],J2[25];  // nom des joueurs
int count=0;
//int z=0;
int n=0,m=0;
int T3[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};   // les moulins
int T4[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};   // les pions allignés
int Tj[9]={100,100,100,100,100,100,100,100,100};   // pions Joueur
int Tm[9]={100,100,100,100,100,100,100,100,100};   // pions Machine
int T3m[3]={100,100,100};   // pions machine phase déplacement n'importe ou


void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void menu(char T[24],char T2[24]) // ------------------fonction d'affichage du menu de démarage du jeu-------------------
{
    int a,i,j,u,r;
    char x,y;
    P22:
    M2:
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
    case 1 :                  //------------------- Joueur contre Joueur ------------------------

        joueur_humain(T,T2);

    case 2 :                         //---------------------------------Joueur contre Machine---------------------------------------

        joueur_ordinateur(T,T2);


    case 3 :                              //-------------------------     Les régles        ------------------------
        system("cls");
        regles();
        printf("\n\n\n\t\t\t\t\t\tEntrez n'importe quel caractere pour sortir au menu");
        getch();
        system("cls");
        goto M2;

    case 4 :

        exit(EXIT_SUCCESS);

    default :

        printf("\n\nvous devez choisir un nombre entre 1 et 4 \n\n\n\n ");
        goto h;
    }
}

void plateau(char T[24],char T2[24])      //----------------------Permet l'affichage de la grille---------------------------
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
printf("\n\t\t\t\t\t\t     |         |                   |                   |        |");printf("\t");Color(0,8);printf("  ");Color(8,0);printf("  %s : ",J1);Color(8,0);printf(" %d Pions",n);Color(15,0);
printf("\n\t\t\t\t\t\t     |         |                   |                   |        |");
printf("\n\t\t\t\t\t\t     |         |                   |                   |        |");printf("\t");Color(0,4);printf("  ");Color(4,0);printf("  %s : ",J2);Color(4,0);printf(" %d Pions",m);Color(15,0);
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
printf("\n\t\t\t\t\t\t     |         |       |                      |        |        |");
printf("\n\t\t\t\t\t\t     |         |       |                      |        |        |");
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

int Player(int count1)   //--------------------------------- permet de distinguer entre les joueurs--------------------------------
{
    int a;
    if(count1%2==0)
        {a=1;}
    else
        {a=2;}
    return a;
}

void coloriage(int x,char T[24],char T2[24])    // ------------------Permet l'affichage des pions et le colorige de chaque pions choisis par chaque joueur------------------
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


void changer(int count1,char x,char T[24],char T2[24])   // ----------------permet de stocker les pions choisis par chaque joueur dans un autre tableau T2-------------------
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

void nbrPions(int count1)   // ---------------------permet de calculer le nombre de pions posé par chaque joueur-----------------------
{
    int a=0;
    a=Player(count1);
    if(a==1)
        n++;
    else
        m++;


}

int condition(int count1, char s, char T[24],char T2[24])     //-------------- Permet de ne pas repeter le mm choix d'un mm pions (case pleine)-------------------
{
    int c=0;
    int i;
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

void MOULIN(char T2[24])   // ---------------------Permet de detecter les différents cas de moulin   (T3 et T4 : des variables globales)------------------------
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

int posPion(char x,char T2[24])  // -------------------permet de donner la position du pion choisis par l'utilisateur dans le tableau de stockage--------------
{
    int i;
    for(i=0;i<24;i++)
    {
        if(T2[i]==x)
            break;
    }
    return i;
}

int cond_deplacer(char y ,char x ,char T[24] ,char T1[24])  //------------------permet de verifier la possibilite de deplacement d'un pion (y) vers la destination (x)-------------------
{
    char T0[2]="jb";
    char T02[3]="aec";
    char T33[2]="bo";
    char T44[2]="ke";
    char T55[4]="dbhf";
    char T6[2]="en";
    char T7[2]="lh";
    char T8[3]="gei";
    char T9[2]="hm";
    char T10[3]="vak";
    char T11[4]="jdsl";
    char T12[3]="kgp";
    char T13[3]="irn";
    char T14[4]="mfuo";
    char T15[3]="cxn";
    char T16[2]="lq";
    char T17[3]="ptr";
    char T18[2]="qm";
    char T19[2]="kt";
    char T20[4]="sqwu";
    char T21[2]="tn";
    char T22[2]="jw";
    char T23[3]="vtx";
    char T24[2]="wo";
    int c=0,pos,i;
    pos=posPion(x,T);
    if(y=='a')
    {
        for (i=0;i<2;i++)
        {
            if(x==T0[i] && T1[pos]!='*' && T1[pos]!='$')  c = 1;
        }
    }
    else if(y=='b')
    {
        for (i=0;i<3;i++)
        {
            if(x==T02[i] && T1[pos]!='*' && T1[pos]!='$')  c = 1;
        }
    }
      else if(y=='c')
    {
        for (i=0;i<2;i++)
        {
            if(x==T33[i] && T1[pos]!='*' && T1[pos]!='$')  c = 1;
        }
    }
      else if(y=='d')
    {
        for (i=0;i<2;i++)
        {
            if(x==T44[i] && T1[pos]!='*' && T1[pos]!='$')  c = 1;
        }
    }
      else if(y=='e')
    {
        for (i=0;i<4;i++)
        {
            if(x==T55[i] && T1[pos]!='*' && T1[pos]!='$')  c = 1;
        }
    }
      else if(y=='f')
    {
        for (i=0;i<2;i++)
        {
            if(x==T6[i] && T1[pos]!='*' && T1[pos]!='$')  c = 1;
        }
    }
      else if(y=='g')
    {
        for (i=0;i<2;i++)
        {
            if(x==T7[i] && T1[pos]!='*' && T1[pos]!='$')  c = 1;
        }
    }
      else if(y=='h')
    {
        for (i=0;i<3;i++)
        {
            if(x==T8[i] && T1[pos]!='*' && T1[pos]!='$')  c = 1;
        }
    }
      else if(y=='i')
    {
        for (i=0;i<2;i++)
        {
            if(x==T9[i] && T1[pos]!='*' && T1[pos]!='$')  c = 1;
        }
    }
      else if(y=='j')
    {
        for (i=0;i<3;i++)
        {
            if(x==T10[i] && T1[pos]!='*' && T1[pos]!='$')  c = 1;
        }
    }
      else if(y=='k')
    {
        for (i=0;i<4;i++)
        {
            if(x==T11[i] && T1[pos]!='*' && T1[pos]!='$')  c = 1;
        }
    }
      else if(y=='l')
    {
        for (i=0;i<3;i++)
        {
            if(x==T12[i] && T1[pos]!='*' && T1[pos]!='$')  c = 1;
        }
    }
      else if(y=='m')
    {
        for (i=0;i<3;i++)
        {
            if(x==T13[i] && T1[pos]!='*' && T1[pos]!='$')  c = 1;
        }
    }
      else if(y=='n')
    {
        for (i=0;i<4;i++)
        {
            if(x==T14[i] && T1[pos]!='*' && T1[pos]!='$')  c = 1;
        }
    }
      else if(y=='o')
    {
        for (i=0;i<3;i++)
        {
            if(x==T15[i] && T1[pos]!='*' && T1[pos]!='$')  c = 1;
        }
    }
      else if(y=='p')
    {
        for (i=0;i<2;i++)
        {
            if(x==T16[i] && T1[pos]!='*' && T1[pos]!='$')  c = 1;
        }
    }
      else if(y=='q')
    {
        for (i=0;i<3;i++)
        {
            if(x==T17[i] && T1[pos]!='*' && T1[pos]!='$')  c = 1;
        }
    }
      else if(y=='r')
    {
        for (i=0;i<2;i++)
        {
            if(x==T18[i] && T1[pos]!='*' && T1[pos]!='$')  c = 1;
        }
    }
      else if(y=='s')
    {
        for (i=0;i<2;i++)
        {
            if(x==T19[i] && T1[pos]!='*' && T1[pos]!='$')  c = 1;
        }
    }
      else if(y=='t')
    {
        for (i=0;i<4;i++)
        {
            if(x==T20[i] && T1[pos]!='*' && T1[pos]!='$')  c = 1;
        }
    }
      else if(y=='u')
    {
        for (i=0;i<2;i++)
        {
            if(x==T21[i] && T1[pos]!='*' && T1[pos]!='$')  c = 1;
        }
    }
      else if(y=='v')
    {
        for (i=0;i<2;i++)
        {
            if(x==T22[i] && T1[pos]!='*' && T1[pos]!='$')  c = 1;
        }
    }
      else if(y=='w')
    {
        for (i=0;i<3;i++)
        {
            if(x==T23[i] && T1[pos]!='*' && T1[pos]!='$')  c = 1;
        }
    }
      else if (y=='x')
    {
        for (i=0;i<2;i++)
        {
            if(x==T24[i] && T1[pos]!='*' && T1[pos]!='$')  c = 1;
        }
    }
    return c;
}

void deplacer(char y, char x, char T[24], char T1[24])    //------ permet le déplacement des pions (déplacer (y) vers (x)) -------
{
    int i,j;
    i=posPion(y,T);
    j=posPion(x,T);
    T1[i]=y;
    if(Player(count)==1) T1[j]='$';
    else T1[j]='*';
}

void Moulin2(char T2[24])    // ------------------------pour detecter un moulin une autre fois dans un mm emplacement après modification du moulin-----------------------------
{
    if(T2[0]=='a')
    {
        T3[0]=0;T4[0]=0;T3[8]=0;T4[8]=0;
    }
    if(T2[1]=='b')
    {
        T3[0]=0;T4[0]=0;T3[11]=0;T4[11]=0;
    }
    if(T2[2]=='c')
    {
        T3[0]=0;T4[0]=0;T3[15]=0;T4[15]=0;
    }
    if(T2[3]=='d')
    {
        T3[1]=0;T4[1]=0;T3[9]=0;T4[9]=0;
    }
    if(T2[4]=='e')
    {
        T3[1]=0;T4[1]=0;T3[11]=0;T4[11]=0;
    }
    if(T2[5]=='f')
    {
        T3[1]=0;T4[1]=0;T3[14]=0;T4[14]=0;
    }
    if(T2[6]=='g')
    {
        T3[2]=0;T4[2]=0;T3[10]=0;T4[10]=0;
    }
    if(T2[7]=='h')
    {
        T3[2]=0;T4[2]=0;T3[11]=0;T4[11]=0;
    }
    if(T2[8]=='i')
    {
        T3[2]=0;T4[2]=0;T3[13]=0;T4[13]=0;
    }
    if(T2[9]=='j')
    {
        T3[3]=0;T4[3]=0;T3[8]=0;T4[8]=0;
    }
    if(T2[10]=='k')
    {
        T3[3]=0;T4[3]=0;T3[9]=0;T4[9]=0;
    }
    if(T2[11]=='l')
    {
        T3[3]=0;T4[3]=0;T3[10]=0;T4[10]=0;
    }
    if(T2[12]=='m')
    {
        T3[4]=0;T4[4]=0;T3[13]=0;T4[13]=0;
    }
    if(T2[13]=='n')
    {
        T3[4]=0;T4[4]=0;T3[14]=0;T4[14]=0;
    }
    if(T2[14]=='o')
    {
        T3[4]=0;T4[4]=0;T3[15]=0;T4[15]=0;
    }
    if(T2[15]=='p')
    {
        T3[5]=0;T4[5]=0;T3[10]=0;T4[10]=0;
    }
    if(T2[16]=='q')
    {
        T3[5]=0;T4[5]=0;T3[12]=0;T4[12]=0;
    }
    if(T2[17]=='r')
    {
        T3[5]=0;T4[5]=0;T3[13]=0;T4[13]=0;
    }
    if(T2[18]=='s')
    {
        T3[6]=0;T4[6]=0;T3[9]=0;T4[9]=0;
    }
    if(T2[19]=='t')
    {
        T3[6]=0;T4[6]=0;T3[12]=0;T4[12]=0;
    }
    if(T2[20]=='u')
    {
        T3[6]=0;T4[6]=0;T3[14]=0;T4[14]=0;
    }
    if(T2[21]=='v')
    {
        T3[7]=0;T4[7]=0;T3[8]=0;T4[8]=0;
    }
    if(T2[22]=='w')
    {
        T3[7]=0;T4[7]=0;T3[12]=0;T4[12]=0;
    }
    if(T2[23]=='x')
    {
        T3[7]=0;T4[7]=0;T3[15]=0;T4[15]=0;
    }
}


int nbrPionPoseJ1(char T2[24])    //-------------------------calcule le nombre de pion du joueur 1 resté dans le plateau -------------
{
    int i,j1=0;
    for(i=0;i<24;i++)
    {
        if(T2[i]=='$')
            j1++;
    }
    return j1;
}

int nbrPionPoseJ2(char T2[24])      //----------------------calcule le nombre de pion du joueur 2 resté dans le plateau -----------------
{
    int i,j2=0;
    for(i=0;i<24;i++)
    {
        if(T2[i]=='*')
            j2++;
    }
    return j2;
}


void loading1()      //---------------------- loading partie 1 ----------------------
{
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t   .");
                Color(4,4);
                printf("    ");
                Color(8,0);
                printf(" ");
                Color(11,11);
                printf("aaaa");
                Color(8,0);
                printf(". ");

                printf("\n\t\t\t\t\t\t\t\t\t\t   .");
                Color(4,4);
                printf("    ");
                Color(8,0);
                printf(" ");
                Color(11,11);
                printf("aaaa");
                Color(8,0);
                printf(". ");
                /*
                color(8,0);
                printf("\n\t\t\t\t\t\t\t\t\t\t");
                color(11,11);
                printf("    aaaa            ");
                color(11,11);
                printf("aaaa");
                color(8,0);
                printf(". ");
                */

                printf("\n\n        \t\t\t\t\t\t\t\t      .");
                Color(4,4);
                printf("aaaa");

                Color(8,0);
                printf(" ");

                Color(8,0);
                printf("     ");

                Color(4,4);
                printf("    ");

                Color(8,0);
                printf(" ");

                Color(7,7);
                printf("aaaa");
                Color(8,0);
                printf(". ");

                printf("\n\t\t\t\t\t\t\t\t\t      .");
                Color(4,4);
                printf("aaaa");

                Color(8,0);
                printf(" ");

                Color(8,0);
                printf("     ");

                Color(4,4);
                printf("    ");

                Color(8,0);
                printf(" ");

                Color(7,7);
                printf("aaaa");
                Color(8,0);
                printf(". ");

                //////////////////

                printf("\n\n\t\t\t\t\t\t\t\t\t\t   .");
                Color(4,4);
                printf("    ");
                Color(8,0);
                printf(" ");
                Color(7,7);
                printf("aaaa");
                Color(8,0);
                printf(". ");

                printf("\n\t\t\t\t\t\t\t\t\t\t   .");
                Color(4,4);
                printf("    ");
                Color(8,0);
                printf(" ");
                Color(7,7);
                printf("aaaa");
                Color(8,0);
                printf(". ");
                printf("\n\n\n");
}

void loading2()                         //---------------------- loading partie 1 ----------------------
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t   .");
                Color(4,4);
                printf("    ");
                Color(8,0);
                printf(" ");
                Color(7,7);
                printf("aaaa");
                Color(8,0);
                printf(". ");

                printf("\n\t\t\t\t\t\t\t\t\t\t   .");
                Color(4,4);
                printf("    ");
                Color(8,0);
                printf(" ");
                Color(7,7);
                printf("aaaa");
                Color(8,0);
                printf(". ");
                /*
                color(8,0);
                printf("\n\t\t\t\t\t\t\t\t\t\t");
                color(11,11);
                printf("    aaaa            ");
                color(11,11);
                printf("aaaa");
                color(8,0);
                printf(". ");
                */

                printf("\n\n        \t\t\t\t\t\t\t\t      .");
                Color(4,4);
                printf("aaaa");

                Color(8,0);
                printf(" ");

                Color(7,7);
                printf("    ");

                Color(8,0);
                printf("      ");
                Color(7,7);
                printf("aaaa");
                Color(8,0);
                printf(". ");

                printf("\n\t\t\t\t\t\t\t\t\t      .");
                Color(4,4);
                printf("aaaa");

                Color(8,0);
                printf(" ");

                Color(7,7);
                printf("    ");

                Color(8,0);
                printf("      ");
                Color(7,7);
                printf("aaaa");
                Color(8,0);
                printf(". ");

                //////////////////

                printf("\n\n\t\t\t\t\t\t\t\t\t\t   .");
                Color(4,4);
                printf("    ");
                Color(8,0);
                printf(" ");
                Color(7,7);
                printf("aaaa");
                Color(8,0);
                printf(". ");

                printf("\n\t\t\t\t\t\t\t\t\t\t   .");
                Color(4,4);
                printf("    ");
                Color(8,0);
                printf(" ");
                Color(7,7);
                printf("aaaa");
                Color(8,0);
                printf(". ");
                printf("\n\n\n");
}

int cond_capture(char x)   // ----------------- verifier si un pion (x) appartient a un allignement de 3 pions-----------------
{
    int c=0;
    if (x=='a')
    {
        if(T4[0]==1 || T4[8]==9) c=1;
    }
    if (x=='b')
    {
        if(T4[0]==1 || T4[11]==12) c=1;
    }
    if (x=='c')
    {
        if(T4[0]==1 || T4[15]==16) c=1;
    }
    if (x=='d')
    {
        if(T4[9]==10 || T4[1]==2) c=1;
    }
    if (x=='e')
    {
        if(T4[11]==12 || T4[1]==2) c=1;
    }
    if (x=='f')
    {
        if(T4[1]==2 || T4[14]==15) c=1;
    }
    if (x=='g')
    {
        if(T4[2]==3 || T4[10]==11) c=1;
    }
    if (x=='h')
    {
        if(T4[2]==3 || T4[11]==12) c=1;
    }
    if (x=='i')
    {
        if(T4[2]==3 || T4[13]==14) c=1;
    }
    if (x=='j')
    {
        if(T4[3]==4 || T4[8]==9) c=1;
    }
    if (x=='k')
    {
        if(T4[3]==4 || T4[9]==10) c=1;
    }
    if (x=='l')
    {
        if(T4[3]==4 || T4[10]==11) c=1;
    }
    if (x=='m')
    {
        if(T4[4]==5 || T4[13]==14) c=1;
    }
    if (x=='n')
    {
        if(T4[4]==5 || T4[14]==15) c=1;
    }
    if (x=='o')
    {
        if(T4[4]==5 || T4[15]==16) c=1;
    }
    if (x=='p')
    {
        if(T4[5]==6 || T4[10]==11) c=1;
    }
    if (x=='q')
    {
        if(T4[5]==6 || T4[12]==13) c=1;
    }
    if (x=='r')
    {
        if(T4[5]==6 || T4[13]==14) c=1;
    }
    if (x=='s')
    {
        if(T4[6]==7 || T4[9]==10) c=1;
    }
    if (x=='t')
    {
        if(T4[6]==7 || T4[12]==13) c=1;
    }
    if (x=='u')
    {
        if(T4[6]==7 || T4[14]==15) c=1;
    }
    if (x=='v')
    {
        if(T4[7]==8 || T4[8]==9) c=1;
    }
    if (x=='w')
    {
        if(T4[7]==8 || T4[12]==13) c=1;
    }
    if (x=='x')
    {
        if(T4[7]==8 || T4[15]==16) c=1;
    }
    return c;
}



int Connd_Deplacement_Machine(char y,char T[24],char T1[24])   //-------------------- Permet de déplacement pour la machine -------------------------
{
    char T0[2]="jb";
    char T02[3]="aec";
    char T33[2]="bo";
    char T44[2]="ke";
    char T55[4]="dbhf";
    char T6[2]="en";
    char T7[2]="lh";
    char T8[3]="gei";
    char T9[2]="hm";
    char T10[3]="vak";
    char T11[4]="jdsl";                                        // ------------------(   y   ) le pion a déplacer --------------------
    char T12[3]="kgp";
    char T13[3]="irn";
    char T14[4]="mfuo";
    char T15[3]="cxn";
    char T16[2]="lq";
    char T17[3]="ptr";
    char T18[2]="qm";
    char T19[2]="kt";
    char T20[4]="sqwu";
    char T21[2]="tn";
    char T22[2]="jw";
    char T23[3]="vtx";
    char T24[2]="wo";
    int c=100,pos,i,k;
    if(y=='a')
    {

        for (i=0;i<2;i++)
        {
            k=posPion(T0[i],T);
            if(T1[k]!='*' && T1[k]!='$')
            {
                B:
                srand(time(NULL));
                int j=rand()%2;
                pos=posPion(T0[j],T);
                if(T1[pos]!='*' && T1[pos]!='$')  c=pos;
                else goto B;
                break;
            }
        }
    }
    else if(y=='b')
    {

        for (i=0;i<3;i++)
        {
            k=posPion(T02[i],T);
            if(T1[k]!='*' && T1[k]!='$')
            {
                B1:
                srand(time(NULL));
                int j=rand()%3;
                pos=posPion(T02[j],T);
                if(T1[pos]!='*' && T1[pos]!='$') c=pos;
                else goto B1;
                break;
            }
        }
    }
      else if(y=='c')
    {
       for (i=0;i<2;i++)
        {
            k=posPion(T33[i],T);
            if(T1[k]!='*' && T1[k]!='$')
            {
                B22:
                srand(time(NULL));
                int j=rand()%2;
                pos=posPion(T33[j],T);
                if(T1[pos]!='*' && T1[pos]!='$') c=pos;
                else goto B22;
                break;
            }
        }
    }
      else if(y=='d')
    {
        for (i=0;i<2;i++)
        {
            k=posPion(T44[i],T);
            if(T1[k]!='*' && T1[k]!='$')
            {
                B2:
                srand(time(NULL));
                int j=rand()%2;
                pos=posPion(T44[j],T);
                if(T1[pos]!='*' && T1[pos]!='$') c=pos;
                else goto B2;
                break;
            }
        }
    }
      else if(y=='e')
    {
        for (i=0;i<4;i++)
        {
            k=posPion(T55[i],T);
            if(T1[k]!='*' && T1[k]!='$')
            {
                B3:
                srand(time(NULL));
                int j=rand()%4;
                pos=posPion(T55[j],T);
                if(T1[pos]!='*' && T1[pos]!='$') c=pos;
                else goto B3;
                break;
            }
        }
    }
      else if(y=='f')
    {
        for (i=0;i<2;i++)
        {
            k=posPion(T6[i],T);
            if(T1[k]!='*' && T1[k]!='$')
            {
                B4:
                srand(time(NULL));
                int j=rand()%2;
                pos=posPion(T6[j],T);
                if(T1[pos]!='*' && T1[pos]!='$') c=pos;
                else goto B4;
                break;
            }
        }
    }
      else if(y=='g')
    {
        for (i=0;i<2;i++)
        {
            k=posPion(T7[i],T);
            if(T1[k]!='*' && T1[k]!='$')
            {
                B5:
                srand(time(NULL));
                int j=rand()%2;
                pos=posPion(T7[j],T);
                if(T1[pos]!='*' && T1[pos]!='$') c=pos;
                else goto B5;
                break;
            }
        }
    }
      else if(y=='h')
    {
        for (i=0;i<3;i++)
        {
            k=posPion(T8[i],T);
            if(T1[k]!='*' && T1[k]!='$')
            {
                B6:
                srand(time(NULL));
                int j=rand()%3;
                pos=posPion(T8[j],T);
                if(T1[pos]!='*' && T1[pos]!='$') c=pos;
                else goto B6;
                break;
            }
        }
    }
      else if(y=='i')
    {
        for (i=0;i<2;i++)
        {
            k=posPion(T9[i],T);
            if(T1[k]!='*' && T1[k]!='$')
            {
                B7:
                srand(time(NULL));
                int j=rand()%2;
                pos=posPion(T9[j],T);
                if(T1[pos]!='*' && T1[pos]!='$') c=pos;
                else goto B7;
                break;
            }
        }
    }
      else if(y=='j')
    {
        for (i=0;i<3;i++)
        {
            k=posPion(T10[i],T);
            if(T1[k]!='*' && T1[k]!='$')
            {
                B8:
                srand(time(NULL));
                int j=rand()%3;
                pos=posPion(T10[j],T);
                if(T1[pos]!='*' && T1[pos]!='$') c=pos;
                else goto B8;
                break;
            }
        }
    }
    else if(y=='k')
    {
        for (i=0;i=4;i++)
        {
            k=posPion(T11[i],T);
            if(T1[k]!='*' && T1[k]!='$')
            {
                B9:
                srand(time(NULL));
                int j=rand()%4;
                pos=posPion(T11[j],T);
                if(T1[pos]!='*' && T1[pos]!='$') c=pos;
                else goto B9;
                break;
            }
        }
    }
    else if(y=='l')
    {
        for (i=0;i<3;i++)
        {
            k=posPion(T12[i],T);
            if(T1[k]!='*' && T1[k]!='$')
            {
                B10:
                srand(time(NULL));
                int j=rand()%3;
                pos=posPion(T12[j],T);
                if(T1[pos]!='*' && T1[pos]!='$') c=pos;
                else goto B10;
                break;
            }
        }
    }
    else if(y=='m')
    {
        for (i=0;i<3;i++)
        {
            k=posPion(T13[i],T);
            if(T1[k]!='*' && T1[k]!='$')
            {
                B11:
                srand(time(NULL));
                int j=rand()%3;
                pos=posPion(T13[j],T);
                if(T1[pos]!='*' && T1[pos]!='$') c=pos;
                else goto B11;
                break;
            }
        }
    }
    else if(y=='n')
    {
        for (i=0;i<4;i++)
        {
            k=posPion(T14[i],T);
            if(T1[k]!='*' && T1[k]!='$')
            {
                B12:
                srand(time(NULL));
                int j=rand()%4;
                pos=posPion(T14[j],T);
                if(T1[pos]!='*' && T1[pos]!='$') c=pos;
                else goto B12;
                break;
            }
        }
    }
    else if(y=='o')
    {
        for (i=0;i<3;i++)
        {
            k=posPion(T15[i],T);
            if(T1[k]!='*' && T1[k]!='$')
            {
                B13:
                srand(time(NULL));
                int j=rand()%3;
                pos=posPion(T15[j],T);
                if(T1[pos]!='*' && T1[pos]!='$') c=pos;
                else goto B13;
                break;
            }
        }
    }
    else if(y=='p')
    {
        for (i=0;i<2;i++)
        {
            k=posPion(T16[i],T);
            if(T1[k]!='*' && T1[k]!='$')
            {
                B14:
                srand(time(NULL));
                int j=rand()%2;
                pos=posPion(T16[j],T);
                if(T1[pos]!='*' && T1[pos]!='$') c=pos;
                else goto B14;
                break;
            }
        }
    }
    else if(y=='q')
    {
        for (i=0;i<3;i++)
        {
            k=posPion(T17[i],T);
            if(T1[k]!='*' && T1[k]!='$')
            {
                B15:
                srand(time(NULL));
                int j=rand()%3;
                pos=posPion(T17[j],T);
                if(T1[pos]!='*' && T1[pos]!='$') c=pos;
                else goto B15;
                break;
            }
        }
    }
    else if(y=='r')
    {
        for (i=0;i<2;i++)
        {
            k=posPion(T18[i],T);
            if(T1[k]!='*' && T1[k]!='$')
            {
                B16:
                srand(time(NULL));
                int j=rand()%2;
                pos=posPion(T18[j],T);
                if(T1[pos]!='*' && T1[pos]!='$') c=pos;
                else goto B16;
                break;
            }
        }
    }
    else if(y=='s')
    {
        for (i=0;i<2;i++)
        {
            k=posPion(T19[i],T);
            if(T1[k]!='*' && T1[k]!='$')
            {
                B17:
                srand(time(NULL));
                int j=rand()%2;
                pos=posPion(T19[j],T);
                if(T1[pos]!='*' && T1[pos]!='$') c=pos;
                else goto B17;
                break;
            }
        }
    }
    else if(y=='t')
    {
        for (i=0;i<4;i++)
        {
            k=posPion(T20[i],T);
            if(T1[k]!='*' && T1[k]!='$')
            {
                B18:
                srand(time(NULL));
                int j=rand()%4;
                pos=posPion(T20[j],T);
                if(T1[pos]!='*' && T1[pos]!='$') c=pos;
                else goto B18;
                break;
            }
        }
    }
    else if(y=='u')
    {
        for (i=0;i<2;i++)
        {
            k=posPion(T21[i],T);
            if(T1[k]!='*' && T1[k]!='$')
            {
                B19:
                srand(time(NULL));
                int j=rand()%2;
                pos=posPion(T21[j],T);
                if(T1[pos]!='*' && T1[pos]!='$') c=pos;
                else goto B19;
                break;
            }
        }
    }
    else if(y=='v')
    {
        for (i=0;i<2;i++)
        {
            k=posPion(T22[i],T);
            if(T1[k]!='*' && T1[k]!='$')
            {
                B20:
                srand(time(NULL));
                int j=rand()%2;
                pos=posPion(T22[j],T);
                if(T1[pos]!='*' && T1[pos]!='$') c=pos;
                else goto B20;
                break;
            }
        }
    }
    else if(y=='w')
    {
        for (i=0;i<3;i++)
        {
            k=posPion(T23[i],T);
            if(T1[k]!='*' && T1[k]!='$')
            {
                B21:
                srand(time(NULL));
                int j=rand()%3;
                pos=posPion(T23[j],T);
                if(T1[pos]!='*' && T1[pos]!='$') c=pos;
                else goto B21;
                break;
            }
        }
    }
    else if (y=='x')
    {
        for (i=0;i<2;i++)
        {
            k=posPion(T24[i],T);
            if(T1[k]!='*' && T1[k]!='$')
            {
                B222:
                srand(time(NULL));
                int j=rand()%2;
                pos=posPion(T24[j],T);
                if(T1[pos]!='*' && T1[pos]!='$') c=pos;
                else goto B222;
                break;
            }
        }
    }
    return c;    // --------- si c=100 il doit chercher un autre pion à déplacer sinon c'est bien -------
}


void PionPose(char T2[24])       //------------Permet d'ajouter dans Tj et Tm pour la position de chaque pion posé------------------
{
    int i,l,r=0,q=0;
    for(l=0;l<9;l++)
    {
        Tj[l]=100;
        Tm[l]=100;
    }
    for(i=0;i<24;i++)
    {
        if(T2[i]=='$')     //----------Pour le joueur ---------
        {
            Tj[r]=i;
            r++;
        }
        if(T2[i]=='*')     // -----------Pour la machine---------
        {
            Tm[q]=i;
            q++;
        }
    }
}

void PionPoseMACHINE3(char T2[24])    //-----------permet de stocker les 3 pions rester pour la machine dans la phase du déplacement libre -----------------
{
     int i,l,q=0;
    for(l=0;l<3;l++)
    {
        T3m[l]=100;
    }
     for(i=0;i<24;i++)
    {
        if(T2[i]=='*')     // -----------Pour la machine---------
        {
            T3m[q]=i;
            q++;
        }
    }

}



int Blockage_Deplacement(char y ,char T[24] ,char T1[24])  //------------------permet de verifier la possibilite de deplacement d'un pion (y)-------------------
{
    char T0[2]="jb";
    char T02[3]="aec";
    char T33[2]="bo";
    char T44[2]="ke";
    char T55[4]="dbhf";
    char T6[2]="en";
    char T7[2]="lh";
    char T8[3]="gei";
    char T9[2]="hm";
    char T10[3]="vak";
    char T11[4]="jdsl";
    char T12[3]="kgp";
    char T13[3]="irn";
    char T14[4]="mfuo";
    char T15[3]="cxn";
    char T16[2]="lq";
    char T17[3]="ptr";
    char T18[2]="qm";
    char T19[2]="kt";
    char T20[4]="sqwu";
    char T21[2]="tn";
    char T22[2]="jw";
    char T23[3]="vtx";
    char T24[2]="wo";
    int c=0,pos,i;
    if(y=='a')
    {
        for (i=0;i<2;i++)
        {
            pos=posPion(T0[i],T);
            if(T1[pos]!='*' && T1[pos]!='$')
            {
                c = 1;
                break;
            }
        }
    }
    else if(y=='b')
    {
        for (i=0;i<3;i++)
        {
            pos=posPion(T02[i],T);
            if(T1[pos]!='*' && T1[pos]!='$')
            {
                c = 1;
                break;
            }
        }
    }
      else if(y=='c')
    {
        for (i=0;i<2;i++)
        {
            pos=posPion(T33[i],T);
            if(T1[pos]!='*' && T1[pos]!='$')
            {
                c = 1;
                break;
            }
        }
    }
      else if(y=='d')
    {
        for (i=0;i<2;i++)
        {
            pos=posPion(T44[i],T);
            if(T1[pos]!='*' && T1[pos]!='$')
            {
                c = 1;
                break;
            }
        }
    }
      else if(y=='e')
    {
        for (i=0;i<4;i++)
        {
            pos=posPion(T55[i],T);
            if(T1[pos]!='*' && T1[pos]!='$')
            {
                c = 1;
                break;
            }
        }
    }
      else if(y=='f')
    {
        for (i=0;i<2;i++)
        {
            pos=posPion(T6[i],T);
            if(T1[pos]!='*' && T1[pos]!='$')
            {
                c = 1;
                break;
            }
        }
    }
      else if(y=='g')
    {
        for (i=0;i<2;i++)
        {
            pos=posPion(T7[i],T);
            if(T1[pos]!='*' && T1[pos]!='$')
            {
                c = 1;
                break;
            }
        }
    }
      else if(y=='h')
    {
        for (i=0;i<3;i++)
        {
            pos=posPion(T8[i],T);
            if(T1[pos]!='*' && T1[pos]!='$')
            {
                c = 1;
                break;
            }
        }
    }
      else if(y=='i')
    {
        for (i=0;i<2;i++)
        {
            pos=posPion(T9[i],T);
            if(T1[pos]!='*' && T1[pos]!='$')
            {
                c = 1;
                break;
            }
        }
    }
      else if(y=='j')
    {
        for (i=0;i<3;i++)
        {
            pos=posPion(T10[i],T);
            if(T1[pos]!='*' && T1[pos]!='$')
            {
                c = 1;
                break;
            }
        }
    }
      else if(y=='k')
    {
        for (i=0;i<4;i++)
        {
            pos=posPion(T11[i],T);
            if(T1[pos]!='*' && T1[pos]!='$')
            {
                c = 1;
                break;
            }
        }
    }
      else if(y=='l')
    {
        for (i=0;i<3;i++)
        {
            pos=posPion(T12[i],T);
            if(T1[pos]!='*' && T1[pos]!='$')
            {
                c = 1;
                break;
            }
        }
    }
      else if(y=='m')
    {
        for (i=0;i<3;i++)
        {
            pos=posPion(T13[i],T);
            if(T1[pos]!='*' && T1[pos]!='$')
            {
                c = 1;
                break;
            }
        }
    }
      else if(y=='n')
    {
        for (i=0;i<4;i++)
        {
            pos=posPion(T14[i],T);
            if(T1[pos]!='*' && T1[pos]!='$')
            {
                c = 1;
                break;
            }
        }
    }
      else if(y=='o')
    {
        for (i=0;i<3;i++)
        {
            pos=posPion(T15[i],T);
            if(T1[pos]!='*' && T1[pos]!='$')
            {
                c = 1;
                break;
            }
        }
    }
      else if(y=='p')
    {
        for (i=0;i<2;i++)
        {
            pos=posPion(T16[i],T);
            if(T1[pos]!='*' && T1[pos]!='$')
            {
                c = 1;
                break;
            }
        }
    }
      else if(y=='q')
    {
        for (i=0;i<3;i++)
        {
            pos=posPion(T17[i],T);
            if(T1[pos]!='*' && T1[pos]!='$')
            {
                c = 1;
                break;
            }
        }
    }
      else if(y=='r')
    {
        for (i=0;i<2;i++)
        {
            pos=posPion(T18[i],T);
            if(T1[pos]!='*' && T1[pos]!='$')
            {
                c = 1;
                break;
            }
        }
    }
      else if(y=='s')
    {
        for (i=0;i<2;i++)
        {
            pos=posPion(T19[i],T);
            if(T1[pos]!='*' && T1[pos]!='$')
            {
                c = 1;
                break;
            }
        }
    }
      else if(y=='t')
    {
        for (i=0;i<4;i++)
        {
            pos=posPion(T20[i],T);
            if(T1[pos]!='*' && T1[pos]!='$')
            {
                c = 1;
                break;
            }
        }
    }
      else if(y=='u')
    {
        for (i=0;i<2;i++)
        {
            pos=posPion(T21[i],T);
            if(T1[pos]!='*' && T1[pos]!='$')
            {
                c = 1;
                break;
            }
        }
    }
      else if(y=='v')
    {
        for (i=0;i<2;i++)
        {
            pos=posPion(T22[i],T);
            if(T1[pos]!='*' && T1[pos]!='$')
            {
                c = 1;
                break;
            }
        }
    }
      else if(y=='w')
    {
        for (i=0;i<3;i++)
        {
            pos=posPion(T23[i],T);
            if(T1[pos]!='*' && T1[pos]!='$')
            {
                c = 1;
                break;
            }
        }
    }
      else if (y=='x')
    {
        for (i=0;i<2;i++)
        {
            pos=posPion(T24[i],T);
            if(T1[pos]!='*' && T1[pos]!='$')
            {
                c = 1;
                break;
            }
        }
    }
    return c;         // --------si c=1 donc y a pas de blockage----------
}



int Blockage_J1(char T[24] ,char T1[24])    //--------------Permet de verifier si le 1er joueur est bloqué ou non-----------------
{
    int i,c=0;
    for(i=0;i<24;i++)
    {
        if(T1[i]=='$')
        {
            if(Blockage_Deplacement(T[i],T,T1)==1)   // pas de problème pour le déplacement
            {
                c=1;
                break;
            }
            if(count<18)
                c=1;
        }
    }
    return c;     // si c=1 donc y a pas de blockage
}


int Blockage_J2(char T[24] ,char T1[24])       //--------------Permet de verifier si le 2eme joueur est bloqué ou non-----------------
{
    int i,c=0;
    for(i=0;i<24;i++)
    {
        if(T1[i]=='*')
        {
            if(Blockage_Deplacement(T[i],T,T1)==1)   // pas de problème pour le déplacement
            {
                c=1;
                break;
            }
            if(count<18)
                c=1;
        }
    }
    return c;   // si c=1 donc y a pas de blockage
}


int nbr_Pion(char Tx[3],char T[24],char T2[24])     //---------------------Permet de calculer le nombre de pions posés par le joueur dans un allignement de 3 pions--------------------
{
    int i,y,j=0;
    for(i=0;i<3;i++)
    {
        y=posPion(Tx[i],T);
        if(T2[y]=='$')
            j++;
    }
    return j;
}

int nbr_PionM(char Tx[3],char T[24],char T2[24])     //---------------------Permet de calculer le nombre de pions posés par la machine dans un allignement de 3 pions--------------------
{
    int i,y,j=0;
    for(i=0;i<3;i++)
    {
        y=posPion(Tx[i],T);
        if(T2[y]=='*')
            j++;
    }
    return j;
}


char Block_MoulinM(char T[24],char T2[24])      //-------------Permet de blocker la construction d'un moulin par l'adversaire-------------------
{
    int i,j;
    char c='z';
    char T1[3]="abc";char T22[3]="def";char T33[3]="ghi";char T44[3]="jkl";char T5[3]="mno";char T6[3]="pqr";char T7[3]="stu";char T8[3]="vwx";char T9[3]="ajv";char T10[3]="dks";char T11[3]="glp";char T12[3]="beh";char T13[3]="qtw";char T14[3]="imr";char T15[3]="fnu";char T16[3]="cox";
    if(c=='z')
    {
        if(nbr_Pion(T1,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T1[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T1[i];
                    break;
                }
            }
        }
    }
    if(c=='z')
    {
        if(nbr_Pion(T22,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T22[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T22[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_Pion(T33,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T33[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T33[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_Pion(T44,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T44[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T44[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_Pion(T5,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T5[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T5[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_Pion(T6,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T6[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T6[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_Pion(T7,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T7[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T7[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_Pion(T8,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T8[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T8[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_Pion(T9,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T9[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T9[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_Pion(T10,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T10[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T10[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_Pion(T11,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T11[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T11[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_Pion(T12,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T12[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T12[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_Pion(T13,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T13[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T13[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_Pion(T14,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T14[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T14[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_Pion(T15,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T15[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T15[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_Pion(T16,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T16[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T16[i];
                    break;
                }
            }
        }
    }
    return c;
}

char Moulin_Machine(char T[24],char T2[24])    //------------ permet a construire un moulin pour la machine-----------------
{
    int i,j;
    char c='z';
    char T1[3]="abc";char T22[3]="def";char T33[3]="ghi";char T44[3]="jkl";char T5[3]="mno";char T6[3]="pqr";char T7[3]="stu";char T8[3]="vwx";char T9[3]="ajv";char T10[3]="dks";char T11[3]="glp";char T12[3]="beh";char T13[3]="qtw";char T14[3]="imr";char T15[3]="fnu";char T16[3]="cox";
    if(c=='z')
    {
        if(nbr_PionM(T1,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T1[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T1[i];
                    break;
                }
            }
        }
    }
    if(c=='z')
    {
        if(nbr_PionM(T22,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T22[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T22[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_PionM(T33,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T33[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T33[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_PionM(T44,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T44[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T44[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_PionM(T5,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T5[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T5[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_PionM(T6,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T6[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T6[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_PionM(T7,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T7[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T7[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_PionM(T8,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T8[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T8[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_PionM(T9,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T9[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T9[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_PionM(T10,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T10[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T10[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_PionM(T11,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T11[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T11[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_PionM(T12,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T12[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T12[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_PionM(T13,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T13[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T13[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_PionM(T14,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T14[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T14[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_PionM(T15,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T15[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T15[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_PionM(T16,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T16[i],T);
                if(T2[j]!='$'&&T2[j]!='*')
                {
                    c=T16[i];
                    break;
                }
            }
        }
    }
    return c;
}


/*char deplacement_libre()
{
    char T1[3]="abc";char T22[3]="def";char T33[3]="ghi";char T44[3]="jkl";char T5[3]="mno";char T6[3]="pqr";char T7[3]="stu";char T8[3]="vwx";char T9[3]="ajv";char T10[3]="dks";char T11[3]="glp";char T12[3]="beh";char T13[3]="qtw";char T14[3]="imr";char T15[3]="fnu";char T16[3]="cox";


}*/

char captureM(char T[24],char T2[24])   //---------Permet de capturer le pion qui block le moulin pour la machine-----------+
{
    int i,j;
    char c='z';
    char T1[3]="abc";char T22[3]="def";char T33[3]="ghi";char T44[3]="jkl";char T5[3]="mno";char T6[3]="pqr";char T7[3]="stu";char T8[3]="vwx";char T9[3]="ajv";char T10[3]="dks";char T11[3]="glp";char T12[3]="beh";char T13[3]="qtw";char T14[3]="imr";char T15[3]="fnu";char T16[3]="cox";
    if(c=='z')
    {
        if(nbr_PionM(T1,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T1[i],T);
                if(T2[j]=='$' && cond_capture(T1[i])==0)
                {
                    c=T1[i];
                    break;
                }
            }
        }
    }
    if(c=='z')
    {
        if(nbr_PionM(T22,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T22[i],T);
                if(T2[j]=='$' && cond_capture(T22[i])==0)
                {
                    c=T22[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_PionM(T33,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T33[i],T);
                if(T2[j]=='$' && cond_capture(T33[i])==0)
                {
                    c=T33[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_PionM(T44,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T44[i],T);
                if(T2[j]=='$' && cond_capture(T44[i])==0)
                {
                    c=T44[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_PionM(T5,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T5[i],T);
                if(T2[j]=='$' && cond_capture(T5[i])==0)
                {
                    c=T5[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_PionM(T6,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T6[i],T);
                if(T2[j]=='$' && cond_capture(T6[i])==0)
                {
                    c=T6[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_PionM(T7,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T7[i],T);
                if(T2[j]=='$' && cond_capture(T7[i])==0)
                {
                    c=T7[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_PionM(T8,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T8[i],T);
                if(T2[j]=='$' && cond_capture(T8[i])==0)
                {
                    c=T8[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_PionM(T9,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T9[i],T);
                if(T2[j]=='$' && cond_capture(T9[i])==0)
                {
                    c=T9[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_PionM(T10,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T10[i],T);
                if(T2[j]=='$' && cond_capture(T10[i])==0)
                {
                    c=T10[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_PionM(T11,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T11[i],T);
                if(T2[j]=='$' && cond_capture(T11[i])==0)
                {
                    c=T11[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_PionM(T12,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T12[i],T);
                if(T2[j]=='$' && cond_capture(T12[i])==0)
                {
                    c=T12[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_PionM(T13,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T13[i],T);
                if(T2[j]=='$' && cond_capture(T13[i])==0)
                {
                    c=T13[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_PionM(T14,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T14[i],T);
                if(T2[j]=='$' && cond_capture(T14[i])==0)
                {
                    c=T14[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_PionM(T15,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T15[i],T);
                if(T2[j]=='$' && cond_capture(T15[i])==0)
                {
                    c=T15[i];
                    break;
                }
            }
        }
    }if(c=='z')
    {
        if(nbr_PionM(T16,T,T2)==2)
        {
            for(i=0;i<3;i++)
            {
                j=posPion(T16[i],T);
                if(T2[j]=='$' && cond_capture(T16[i])==0)
                {
                    c=T16[i];
                    break;
                }
            }
        }
    }
    return c;
}

/*char Attaque_depl_libre(char T[24],char T2[24])  //----------permet de donner le pion que la machine doit utiliser pour construire un moulin dans le déplacement libre---------------------
{
    //char T1[3]="abc";char T22[3]="def";char T33[3]="ghi";char T44[3]="jkl";char T5[3]="mno";char T6[3]="pqr";char T7[3]="stu";char T8[3]="vwx";char T9[3]="ajv";char T10[3]="dks";char T11[3]="glp";char T12[3]="beh";char T13[3]="qtw";char T14[3]="imr";char T15[3]="fnu";char T16[3]="cox";
    char T00[16][3]={"abc","def","ghi","jkl","mno","pqr","stu","vwx","ajv","dks","glp","beh","qtw","imr","fnu","cox"};
    int i,j,h;
    char c='z';
    for(i=0;i<16;i++)
    {
        if(nbr_PionM(T00[i],T,T2)==1)
        {
            for(j=0;j<3;j++)
            {
                h=posPion(T00[i][j],T);
                if(T2[h]=='*')
                {
                    c=T00[i][j];
                    break;
                }
            }
            break;
        }

    }
    return c;
}*/


void joueur_humain(char T[24],char T2[24])  //-------------------------------------------------JOUEUR VS JOUEUR------------------------------------------------------
{
    int r,u,i,j;
    char x,y;
    srand(time(NULL));
        r=rand()%2;
        count=r;
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tJoueur 1 entrez votre nom : ");
        scanf("%s",&J1);
        printf("\n\n\n\n\t\t\t\t\t\t\t\tJoueur 2 entrez votre nom : ");
        scanf("%s",&J2);
        system("cls");
        for(u=0;u<15;u++)
        {
            Sleep(200);
            system("cls");
            if(u%2==0)
            {
                loading1();
            }
            else
            {
                loading2();
            }

        }
        system("cls");
        p:
        if(count<18+r)                          //-------------------- Phase positionnement ------------------
        {
            plateau(T,T2);
            p1:
            if(Player(count)==1)
                {Color(8,0);printf("\n\t\t\t %s A vous de jouer",J1);Color(15,0);}
            else
                {Color(4,0);printf("\n\t\t\t %s A vous de jouer",J2);Color(15,0);}
            printf("\n\n\t----->  Donner la position du pion :  ");
            scanf("%s",&x);
            if (condition(count,x,T,T2)==0)
            {
                printf("vous devez choisir l'un des pions disponible");
                goto p1;
            }
            Moulin2(T2);
            changer(count,x,T,T2);
            nbrPions(count);
            MOULIN(T2);
            for(i=0;i<16;i++)
            {
                if(T3[i]==i+1)
                {
                    if(Player(count)==1)
                    {
                        MoulinJ1(i,T,T2);          //-----------Procédure Moulin pour le 1er Joueur y inclu CAPTURE----------------------
                    }
                    else
                    {
                        MoulinJ2(i,T,T2);           //-----------Procédure Moulin pour le 2eme Joueur y inclu CAPTURE----------------------
                    }
                }
            }
            count+=1;
        }
        if(count>17+r && nbrPionPoseJ1(T2)>2 && nbrPionPoseJ2(T2)>2)              //------------------- Phase déplacement  -------------------
        {
            L4:
            if (Blockage_J1(T,T2)==0)
                {goto q;}
            if (Blockage_J2(T,T2)==0)
                {goto r;}
            system("cls");
            plateau(T,T2);
            if(Player(count)==1)
            {
                Color(8,0);printf("\n\t\t\t %s choisi le pion a deplacer",J1);Color(15,0);

            }
            else
            {
                Color(4,0);printf("\n\t\t\t %s choisi le pion a deplacer",J2);Color(15,0);

            }
            M:
            scanf("%s",&y);
            if(Player(count)==1)
            {
                if(T2[posPion(y,T)]!='$')
                {
                    Color(8,0);printf("vous devez deplacer votre Pion ");Color(15,0);
                    goto M;
                }
                else
                {
                    if(nbrPionPoseJ1(T2)>3)                        //---------- Déplacement normale J2------------
                    {
                        Color(8,0);printf("\n\nChoisir la destination du pion ( ENTREZ 'z' si VOUS VOULEZ ANNULER VOTRE CHOIX ) : ");Color(15,0);
                        L:
                        scanf("%s",&x);
                        if(x=='z')
                        {
                            goto L4;
                        }
                        else
                        {
                            if (cond_deplacer(y,x,T,T2)==1)
                            {
                                deplacer(y,x,T,T2);
                            }
                            else
                            {
                                printf("il est impossible!\n STP choisis une autre destination ! ");
                                goto L;
                            }
                        }
                    }
                    if(nbrPionPoseJ1(T2)==3)                //------------- Déplacement dans n'importe quel destination J1-------
                    {
                        Color(8,0);printf("\n\nchoisir la destination du pion ( ENTREZ 'z' si VOUS VOULEZ ANNULER VOTRE CHOIX ) : ");Color(15,0);
                        L6:
                        scanf("%s",&x);
                        if(x=='z')
                        {
                            goto L4;
                        }
                        else if(T2[posPion(x,T)]==x)
                        {
                            deplacer(y,x,T,T2);
                        }
                        else
                        {
                            printf("Vous devez choisir une place libre ");
                            goto L6;
                        }
                    }
                }
            }
            else
            {
                if(T2[posPion(y,T)]!='*')
                {
                    Color(4,0);printf("vous devez deplacer votre Pion ");Color(15,0);
                    goto M;
                }
                else
                {
                    if(nbrPionPoseJ2(T2)>3)                             //---------- Déplacement normale J2------------
                    {
                        Color(4,0);printf("\n\nchoisir la destination du pion ( ENTREZ 'z' si VOUS VOULEZ ANNULER VOTRE CHOIX ) : ");Color(15,0);
                        L11:
                        scanf("%s",&x);
                        if(x=='z')
                        {
                            goto L4;
                        }
                        else
                        {
                            if (cond_deplacer(y,x,T,T2)==1)
                            {
                                deplacer(y,x,T,T2);
                            }
                            else
                            {
                                printf("il est impossible!\n STP choisis une autre destination ! ");
                                goto L11;
                            }
                        }
                    }
                    if(nbrPionPoseJ2(T2)==3)                    //------------- Déplacement dans n'importe quel destination J2-------
                    {
                        Color(4,0);printf("\n\nchoisir la destination du pion ( ENTREZ 'z' si VOUS VOULEZ ANNULER VOTRE CHOIX ) : ");Color(15,0);
                        L66:
                        scanf("%s",&x);
                        if(x=='z')
                        {
                            goto L4;
                        }
                        else if(T2[posPion(x,T)]==x)
                        {
                            deplacer(y,x,T,T2);
                        }
                        else
                        {
                            printf("Vous devez choisir une place libre ");
                            goto L66;
                        }
                    }
                }
            }
            Moulin2(T2);
            changer(count,x,T,T2);
            MOULIN(T2);
            for(i=0;i<16;i++)
            {
                if(T3[i]==i+1)
                {
                    if(Player(count)==1)
                    {
                        MoulinJ1(i,T,T2);
                    }
                    else
                    {
                        MoulinJ2(i,T,T2);
                    }
                }
            }
        if(nbrPionPoseJ1(T2)<3)               // ---------------------- le gagnant est le 2ème JOUEUR -----------------------
        {
            q:
            system("cls");
            YOU();
            printf("\n\n\n\n\n\t\t\t\t\t\t\t\t Le gagnant est : %s",J2);
            Color(15,0);
            Rejouer(T,T2);
            printf("\n\n\t\t\t\t\t\t\t\t\t ( Entrez n'importe quel caractere pour sortir de la partie ) ");
            getch();
            system("cls");
            menu(T,T2);
        }
        if(nbrPionPoseJ2(T2)<3)                  // ---------------------- le gagnant est le 1er JOUEUR -----------------------
        {
            r:
            system("cls");
            Color(8,0);
            YOU();
            printf("\n\n\n\n\n\t\t\t\t\t\t\t\t Le gagnant est : %s",J1);
            Color(15,0);
            Rejouer(T,T2);
            printf("\n\n\t\t\t\t\t\t\t\t\t ( Entrez n'importe quel caractere pour sortir de la partie ) ");
            getch();
            system("cls");
            menu(T,T2);
        }
        count++;
        }
        goto p;
}

void joueur_ordinateur(char T[24],char T2[24])
{
    int r,i,j;
    char x,y;
    srand(time(NULL));
        r=rand()%2;
        count=r;
        J2[0]='C';J2[1]='P';J2[2]='U';
        v:
        system("cls");
        Color(12,0);
        char str[]="\t\t\t\t\t\t ___________________________________________________________________\n\t\t\t\t\t\t|      _                    __  __                   _   _          |\n\t\t\t\t\t\t|     | |   ___    _   _   |  \\/  |   ___    _   _  | | (_)  _ __   |\n\t\t\t\t\t\t|  _  | |  / _ \\  | | | |  | |\\/| |  / _ \\  | | | | | | | | | '_ \\  |\n\t\t\t\t\t\t| | |_| | |  __/  | |_| |  | |  | | | (_) | | |_| | | | | | | | | | |\n\t\t\t\t\t\t|  \\___/   \\___|   \\__,_|  |_|  |_|  \\___/   \\__,_| |_| |_| |_| |_| |\n\t\t\t\t\t\t-___________________________________________________________________-";
        printf("%s\n\n\n\n",str);
        Color(14,0);
        printf("\t\t\t\t\t\t\t\t\t _______________________ \n");
        printf("\t\t\t\t\t\t\t\t\t|                       |\n");
        printf("\t\t\t\t\t\t\t\t\t|      1.IA FACILE      |\n");
        printf("\t\t\t\t\t\t\t\t\t|_______________________|\n");
        printf("\n\n");
        printf("\t\t\t\t\t\t\t\t\t _______________________ \n");
        printf("\t\t\t\t\t\t\t\t\t|                       |\n");
        printf("\t\t\t\t\t\t\t\t\t|      2.IA MOYENNE     |\n");
        printf("\t\t\t\t\t\t\t\t\t|_______________________|\n");
        printf("\n\n");
        printf("\tveuillez entrer votre choix:  ");
        int b;
        scanf("%d",&b);

        if(b==1)                      //-----------------------      IA FACILE      -----------------------------
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tJoueur 1 entrez votre nom : ");
            scanf("%s",&J1);
            system("cls");
            ff:
            PionPose(T2);
            if(count<18+r)
            {
                plateau(T,T2);
                p2:
                if (Player(count)==1)
                {
                    printf("\n\t\t\t %s A vous de jouer",J1);
                    printf("\n\n------->Donner la position du pion :  ");
                    scanf("%s",&x);
                    if (condition(count,x,T,T2)==0)
                    {
                        printf("vous devez choisir l'un des pions disponible  ");
                        goto p2;
                    }
                }
                else
                {
                    jj:
                    srand(time(NULL));
                    int ii=rand()%24;
                    if ((T2[ii]=='$') || (T2[ii]=='*'))
                    {
                        goto jj;
                    }
                    else
                    {
                        x=T[ii];
                        Sleep(1000);
                    }
                }
                Moulin2(T2);
                changer(count,x,T,T2);
                PionPose(T2);
                nbrPions(count);
                MOULIN(T2);
                for(i=0;i<16;i++)
                    {
                        if(T3[i]==i+1)
                        {
                            if(Player(count)==1)
                            {
                                MoulinJ1(i,T,T2);
                            }
                            else
                            {
                                Moulin_Machine_Facile(i,T,T2);
                            }
                        }
                    }
                count+=1;
            }
            if(count>17+r && nbrPionPoseJ1(T2)>2 && nbrPionPoseJ2(T2)>2)
            {
                L44:
                system("cls");
                plateau(T,T2);
                if(Player(count)==1)
                    {Color(8,0);printf("\n\t\t\t %s choisi le pion a deplacer",J1);Color(15,0);}
                else
                    {Color(4,0);printf("\n\t\t\t %s choisi le pion a deplacer",J2);Color(15,0);}

                if(Player(count)==1)
                {
                    M1:
                    scanf("%s",&y);
                    if(T2[posPion(y,T)]!='$')
                    {
                        Color(8,0);printf("vous devez deplacer votre Pion ");Color(15,0);
                        goto M1;
                    }
                    else
                    {
                        if(nbrPionPoseJ1(T2)>3)                        //---------- Déplacement normale J2------------
                        {
                            Color(8,0);printf("\n\nChoisir la destination du pion ( ENTREZ 'z' si VOUS VOULEZ ANNULER VOTRE CHOIX ) : ");Color(15,0);
                            L5:
                            scanf("%s",&x);
                            if(x=='z')
                            {
                                goto M1;
                            }
                            else
                            {
                                if (cond_deplacer(y,x,T,T2)==1)
                                {
                                    deplacer(y,x,T,T2);
                                    PionPose(T2);
                                }
                                else
                                {
                                    printf("il est impossible!\n STP choisis une autre destination ! ");
                                    goto L5;
                                }
                            }
                        }
                        if(nbrPionPoseJ1(T2)==3)                //------------- Déplacement dans n'importe quel destination J1-------------
                        {
                            Color(8,0);printf("\n\nchoisir la destination du pion ( ENTREZ 'z' si VOUS VOULEZ ANNULER VOTRE CHOIX ) : ");Color(15,0);
                            L77:
                            scanf("%s",&x);
                            if(x=='z')
                            {
                                goto M1;
                            }
                            else if(T2[posPion(x,T)]==x)
                            {
                                deplacer(y,x,T,T2);
                                PionPose(T2);
                            }
                            else
                            {
                                printf("Vous devez choisir une place libre ");
                                goto L77;
                            }
                        }
                    }
                }
                else
                {
                    if(nbrPionPoseJ2(T2)>3)
                    {
                        HHH:
                        srand(time(NULL));
                        int ii=rand()%9;
                        int d=Tm[ii];
                        if(Tm[ii]==100)
                        {
                            goto HHH;
                        }
                        if(Tm[ii]!=100)
                        {
                            int h=Connd_Deplacement_Machine(T[d],T,T2);
                            if(h!=100)
                            {
                                x=T[h];
                                deplacer(T[d],x,T,T2);
                                PionPose(T2);
                                Sleep(1000);
                            }
                            else
                            {
                                goto HHH;
                            }
                        }
                    }
                    if(nbrPionPoseJ2(T2)==3)
                    {
                        PionPoseMACHINE3(T2);
                        srand(time(NULL));
                        int ff=rand()%3;
                        int l=T3m[ff];   //---- position pion a déplacer -------
                        xx:
                        srand(time(NULL));
                        int kk=rand()%24;
                        x=T[kk];
                        if(T2[posPion(x,T)]==x)
                        {
                            deplacer(T[l],x,T,T2);
                            PionPoseMACHINE3(T2);
                            Sleep(1000);
                        }
                        else
                            {goto xx;}

                    }
                }
                Moulin2(T2);
                changer(count,x,T,T2);
                PionPose(T2);
                MOULIN(T2);
                for(i=0;i<16;i++)
                    {
                        if(T3[i]==i+1)
                        {
                            if(Player(count)==1)
                            {
                                MoulinJ1(i,T,T2);
                            }
                            else
                            {
                                Moulin_Machine_Facile(i,T,T2);
                            }
                        }
                    }
            if(nbrPionPoseJ1(T2)<3)                  // ---------------------- le gagnant est la machine -----------------------
            {
                system("cls");
                Color(4,0);
                printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t DOMAGE VOUS AVEZ PERDUE LA PARTIE !!");
                Color(15,0);
                Rejouer(T,T2);
                printf("\n\n\t\t\t\t\t\t\t\t\t ( Entrez n'importe quel caractere pour sortir de la partie ) ");
                getch();
                system("cls");
                //goto P22;
                menu(T,T2);
            }
            if(nbrPionPoseJ2(T2)<3)                 // ---------------------- le gagnant est le 1er JOUEUR -----------------------
            {
                system("cls");
                Color(8,0);
                YOU();
                printf("\n\n\n\n\n\t\t\t\t\t\t\t\t Le gagnant est : %s",J1);
                Color(15,0);
                Rejouer(T,T2);
                printf("\n\n\t\t\t\t\t\t\t\t\t ( Entrez n'importe quel caractere pour sortir de la partie ) ");
                getch();
                system("cls");
                menu(T,T2);
            }
            count++;
            }

            goto ff;
        }



        if(b==2)                            //-------------------------      IA MOYENNE      --------------------------------
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tJoueur 1 entrez votre nom : ");
            scanf("%s",&J1);
            system("cls");
            ff1:
            PionPose(T2);
            if(count<18+r)
            {
                plateau(T,T2);
                p12:
                if (Player(count)==1)           //--------------JOUEUR---------------
                {
                    printf("\n\t\t\t %s A vous de jouer",J1);
                    printf("\n\n------->Donner la position du pion :  ");
                    scanf("%s",&x);
                    if (condition(count,x,T,T2)==0)
                    {
                        printf("vous devez choisir l'un des pions disponible  ");
                        goto p12;
                    }
                }
                else             //-----------------MACHINE------------------
                {
                    char q=Block_MoulinM(T,T2);
                    char h=Moulin_Machine(T,T2);
                    int j=posPion(q,T),l=posPion(h,T);
                    if(h!='z')
                    {
                        x=h;
                    }
                    else
                    {
                        if(q!='z')
                        {
                            x=q;
                        }
                        else
                        {
                            jj1:
                            srand(time(NULL));
                            int ii=rand()%24;
                            if ((T2[ii]=='$') || (T2[ii]=='*'))
                            {
                                goto jj1;
                            }
                            else
                            {
                                x=T[ii];
                                Sleep(1000);
                            }
                        }
                    }
                }
                Moulin2(T2);
                changer(count,x,T,T2);
                PionPose(T2);
                nbrPions(count);
                MOULIN(T2);
                for(i=0;i<16;i++)
                    {
                        if(T3[i]==i+1)
                        {
                            if(Player(count)==1)
                            {
                                MoulinJ1(i,T,T2);
                            }
                            else
                            {
                                Moulin_Machine_Moyenne(i,T,T2);
                            }
                        }
                    }
                count+=1;
            }
            if(count>17+r && nbrPionPoseJ1(T2)>2 && nbrPionPoseJ2(T2)>2)
            {
                L442:
                system("cls");
                plateau(T,T2);
                if(Player(count)==1)
                    {Color(8,0);printf("\n\t\t\t %s choisi le pion a deplacer",J1);Color(15,0);}
                else
                    {Color(4,0);printf("\n\t\t\t %s choisi le pion a deplacer",J2);Color(15,0);}

                if(Player(count)==1)
                {
                    M11:
                    scanf("%s",&y);
                    if(T2[posPion(y,T)]!='$')
                    {
                        Color(8,0);printf("vous devez deplacer votre Pion ");Color(15,0);
                        goto M11;
                    }
                    else
                    {
                        if(nbrPionPoseJ1(T2)>3)                        //---------- Déplacement normale J2------------
                        {
                            Color(8,0);printf("\n\nChoisir la destination du pion ( ENTREZ 'z' si VOUS VOULEZ ANNULER VOTRE CHOIX ) : ");Color(15,0);
                            L52:
                            scanf("%s",&x);
                            if(x=='z')
                            {
                                goto L442;
                            }
                            else
                            {
                                if (cond_deplacer(y,x,T,T2)==1)
                                {
                                    deplacer(y,x,T,T2);
                                    PionPose(T2);
                                }
                                else
                                {
                                    printf("il est impossible!\n STP choisis une autre destination ! ");
                                    goto L52;
                                }
                            }
                        }
                        if(nbrPionPoseJ1(T2)==3)                //------------- Déplacement dans n'importe quel destination J1-------------
                        {
                            Color(8,0);printf("\n\nchoisir la destination du pion ( ENTREZ 'z' si VOUS VOULEZ ANNULER VOTRE CHOIX ) : ");Color(15,0);
                            L771:
                            scanf("%s",&x);
                            if(x=='z')
                            {
                                goto L442;
                            }
                            else if(T2[posPion(x,T)]==x)
                            {
                                deplacer(y,x,T,T2);
                                PionPose(T2);
                            }
                            else
                            {
                                printf("Vous devez choisir une place libre ");
                                goto L771;
                            }
                        }
                    }
                }
                else
                {
                    if(nbrPionPoseJ2(T2)>3)
                    {
                        HHH0:
                        srand(time(NULL));
                        int ii=rand()%9;
                        int d=Tm[ii];
                        if(Tm[ii]==100)
                        {
                            goto HHH0;
                        }
                        if(Tm[ii]!=100)
                        {
                            int h=Connd_Deplacement_Machine(T[d],T,T2);
                            if(h!=100)
                            {
                                x=T[h];
                                deplacer(T[d],x,T,T2);
                                PionPose(T2);
                                //Sleep(1000);
                            }
                            else
                            {
                                goto HHH0;
                            }
                        }
                    }
                    if(nbrPionPoseJ2(T2)==3)
                    {
                        char y;
                        /*if(Moulin_Machine(T,T2)!='z')
                        {
                            PionPoseMACHINE3(T2);
                            x=Moulin_Machine(T,T2);
                            y=Attaque_depl_libre(T,T2);
                            deplacer(y,x,T,T2);
                            PionPoseMACHINE3(T2);
                        }*/
                        if(Block_MoulinM(T,T2)!='z')
                        {
                            PionPoseMACHINE3(T2);
                            x=Block_MoulinM(T,T2);
                            srand(time(NULL));
                            int f=rand()%3;
                            y=T[T3m[f]];
                            deplacer(y,x,T,T2);
                            PionPoseMACHINE3(T2);
                        }
                        //if(Moulin_Machine(T,T2)=='z' && Block_MoulinM(T,T2)=='z')
                        else
                        {
                            PionPoseMACHINE3(T2);
                            srand(time(NULL));
                            int ff=rand()%3;
                            int l=T3m[ff];   //---- position pion a déplacer -------
                            xx0:
                            srand(time(NULL));
                            int kk=rand()%24;
                            x=T[kk];
                            if(T2[posPion(x,T)]==x)
                            {
                                deplacer(T[l],x,T,T2);
                                PionPoseMACHINE3(T2);
                                //Sleep(1000);
                            }
                            else
                                {goto xx0;}
                        }

                    }
                }
                Moulin2(T2);
                changer(count,x,T,T2);
                PionPose(T2);
                MOULIN(T2);
                for(i=0;i<16;i++)
                    {
                        if(T3[i]==i+1)
                        {
                            if(Player(count)==1)
                            {
                                MoulinJ1(i,T,T2);
                            }
                            else
                            {
                                Moulin_Machine_Moyenne(i,T,T2);
                            }
                        }
                    }
            if(nbrPionPoseJ1(T2)<3)                  // ---------------------- le gagnant est le 2ème JOUEUR -----------------------
            {
                system("cls");
                Color(4,0);
                printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t DOMAGE VOUS AVEZ PERDUE LA PARTIE !!");
                Color(15,0);
                Rejouer(T,T2);
                printf("\n\n\t\t\t\t\t\t\t\t\t ( Entrez n'importe quel caractere pour sortir de la partie ) ");
                getch();
                system("cls");
                menu(T,T2);
            }
            if(nbrPionPoseJ2(T2)<3)                 // ---------------------- le gagnant est le 1er JOUEUR -----------------------
            {
                system("cls");
                Color(8,0);
                YOU();
                printf("\n\n\n\n\n\t\t\t\t\t\t\t\t Le gagnant est : %s",J1);
                Color(15,0);
                Rejouer(T,T2);
                printf("\n\n\t\t\t\t\t\t\t\t\t ( Entrez n'importe quel caractere pour sortir de la partie ) ");
                getch();
                system("cls");
                menu(T,T2);
            }
            count++;
            }
                goto ff1;

        }



        else               // --------------b!=1 && b!=2----------------
        {
            printf("\n\nvous devez choisir l'un des choix possible \n\n\n\n ");
            getch();
            system("cls");
            goto v;
        }
}

void MoulinJ1(int i,char T[24],char T2[24])   //-----------Procédure Moulin pour le 1er Joueur y inclu CAPTURE----------------------
{
    char y;
    int j;
    system("cls");
    plateau(T,T2);
    Color(8,0);printf("\t\t\t\t\t\t\t\t\tMoulin pour %s\n\n",J1);Color(15,0);
    T3[i]=100;
    printf("\t\tA vous de capturer: \n\t");
    w:
    scanf("%s",&y);
    if(cond_capture(y)==1)
    {
        printf("vous ne pouvez pas capturer ce pion pour l'instant ");
        goto w;
    }
    else
    {
        j=posPion(y,T);
        if(T2[j]=='*')
        {
            T2[j]=T[j];
        }
        else
        {
            printf("Vous devez capturer l'un des pions de votre adversaire ");
            goto w;
        }
    }
}

void MoulinJ2(int i,char T[24],char T2[24])       //-----------Procédure Moulin pour le 2eme Joueur y inclu CAPTURE----------------------
{
    char y;
    int j;
    system("cls");
    plateau(T,T2);
    Color(4,0);printf("\t\t\t\t\t\t\t\t\tMoulin pour %s\n\n",J2);Color(15,0);
    T3[i]=100;
    printf("\t\tA vous de capturer: ");
    w1:
    scanf("%s",&y);
    if(cond_capture(y)==1)
    {
        printf("vous ne pouvez capturer ce pion pour l'instant ");
         goto w1;
    }
    if(cond_capture(y)==0)
    {
        j=posPion(y,T);
        if(T2[j]=='$')
        {
            T2[j]=T[j];
        }
        else
        {
            printf("Vous devez capturer l'un des pions de votre adversaire ");
            goto w1;
        }
    }
}


void YOU()
{
    Color(4,0);
    printf("\n\n\t\t\t\t\t\t\t\t            ___________    ____ \n");
    printf("\t\t\t\t\t\t\t\t     ______/   \\__//   \\__/____\\ \n");
    printf("\t\t\t\t\t\t\t\t   _/   \\_/  :           //____\\\\  \n");
    printf("\t\t\t\t\t\t\t\t  /|      :  :  ..      /        \\ \n");
    printf("\t\t\t\t\t\t\t\t | |     ::     ::      \\        / \n");
    printf("\t\t\t\t\t\t\t\t | |     :|     ||     \\ \\______/ \n");
    printf("\t\t\t\t\t\t\t\t | |     ||     ||      |\\  /  |  \n");
    printf("\t\t\t\t\t\t\t\t  \\|     ||     ||      |   / | \\ \n");
    printf("\t\t\t\t\t\t\t\t   |     ||     ||      |  / /_\\ \\ \n");
    printf("\t\t\t\t\t\t\t\t   | ___ || ___ ||      | /  /    \\ \n");
    printf("\t\t\t\t\t\t\t\t    \\_-_/  \\_-_/ | ____ |/__/      \\ \n");
    printf("\t\t\t\t\t\t\t\t                 _\\_--_/    \\      /  \n");
    printf("\t\t\t\t\t\t\t\t                /____             /  \n");
    printf("\t\t\t\t\t\t\t\t               /     \\           /  \n");
    printf("\t\t\t\t\t\t\t\t               \\______\\_________/ \n");
}

void Rejouer(char T[24],char T2[24])
{
    int i;
    count=0;
    n=0;m=0;
    for(i=0;i<16;i++)
    {
        T3[i]=0;T4[i]=0;
    }
    for(i=0;i<24;i++)
    {
        T2[i]=T[i];
    }
}


void Moulin_Machine_Facile(int i,char T[24],char T2[24])       //-----------Procédure Moulin pour le Machine Facile y inclu CAPTURE----------------------
{
    PionPose(T2);
    system("cls");
    plateau(T,T2);
    Color(4,0);printf("\t\t\t\t\t\t\t\t\tMoulin pour %s\n\n",J2);Color(15,0);
    T3[i]=100;
    HH:
    srand(time(NULL));
    int jj=rand()%9;
    if(Tj[jj]==100)
    {
        goto HH;
    }
    else
    {
        int r=Tj[jj];
        if(cond_capture(T[r])==1)
            {goto HH;}
        else
        {
            T2[r]=T[r];
            PionPose(T2);
        }
    }
}


void Moulin_Machine_Moyenne(int i,char T[24],char T2[24])            //-----------Procédure Moulin pour le Machine Moyenne y inclu CAPTURE----------------------
{
    PionPose(T2);
    system("cls");
    plateau(T,T2);
    Color(4,0);printf("\t\t\t\t\t\t\t\t\tMoulin pour %s\n\n",J2);Color(15,0);
    T3[i]=100;
    char a=captureM(T,T2);
    if(captureM(T,T2)!='z')
    {
        T2[posPion(a,T)]=a;
    }
    else
    {
        HH01:
        srand(time(NULL));
        int jj=rand()%9;
        if(Tj[jj]==100)
        {
            goto HH01;
        }
        else
        {
            int r=Tj[jj];
            if(cond_capture(T[r])==1)
                {goto HH01;}
            else
            {
                T2[r]=T[r];
                PionPose(T2);
                //Sleep(1000);
            }
        }
    }
}


