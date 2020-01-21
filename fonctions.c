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

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void menu(char T[24],char T2[24]) // fonction d'affichage du menu de démarage du jeu
{
    int a,i,j,u;
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
    case 1 :               //------------------- Joueur contre Joueur ------------------------
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tJoueur 1 entrez votre nom : ");
        scanf("%s",&J1);
        printf("\n\t\t\t\t\t\t\t\tJoueur 2 entrez votre nom : ");
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
        if(count<18)    //-------------------- Phase positionnement ------------------
        {
            plateau(T,T2);
            p1:
            if(Player(count)==1)
                printf("\n\t\t\t %s A vous de jouer",J1);
            else
                printf("\n\t\t\t %s A vous de jouer",J2);
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
                        printf("\t\t\t\t\t\t\t\t\tMoulin pour %s\n\n",J1);
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
                    else
                    {
                        printf("\t\t\t\t\t\t\t\t\tMoulin pour %s\n\n",J2);
                        T3[i]=100;
                        printf("\t\tA vous de capturer: ");
                        w1:
                        scanf("%s",&y);
                        if(cond_capture(y)==1)
                        {
                            printf("vous ne pouvez capturer ce pion pour l'instant ");
                            goto w1;
                        }
                        else
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
                }
            }
            count+=1;
        }
        if(count>17 && nbrPionPoseJ1(T2)>2 && nbrPionPoseJ2(T2)>2)              //------------------- Phase déplacement  -------------------
        {
            L4:
            system("cls");
            plateau(T,T2);
            if(Player(count)==1)
                printf("\n\t\t\t %s choisi le pion a deplacer",J1);
            else
                printf("\n\t\t\t %s choisi le pion a deplacer",J2);
            M:
            scanf("%s",&y);
            if(Player(count)==1)
            {
                if(T2[posPion(y,T)]!='$')
                {
                    printf("vous devez deplacer votre Pion ");
                    goto M;
                }
                else
                {
                    if(nbrPionPoseJ1(T2)>3)       //---------- Déplacement normale J2------------
                    {
                        printf("\n\nchoisir la destination du pion ( ENTREZ 'z' si VOUS VOULEZ ANNULER VOTRE CHOIX ) : ");
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
                    if(nbrPionPoseJ1(T2)==3)      //------------- Déplacement dans n'importe quel destination J1-------
                    {
                        printf("\n\nchoisir la destination du pion ( ENTREZ 'z' si VOUS VOULEZ ANNULER VOTRE CHOIX ) : ");
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
                    printf("vous devez deplacer votre Pion ");
                    goto M;
                }
                else
                {
                    if(nbrPionPoseJ2(T2)>3)       //---------- Déplacement normale J2------------
                    {
                        printf("\n\nchoisir la destination du pion ( ENTREZ 'z' si VOUS VOULEZ ANNULER VOTRE CHOIX ) : ");
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
                    if(nbrPionPoseJ2(T2)==3)      //------------- Déplacement dans n'importe quel destination J2-------
                    {
                        printf("\n\nchoisir la destination du pion ( ENTREZ 'z' si VOUS VOULEZ ANNULER VOTRE CHOIX ) : ");
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
                        printf("\t\t\t\t\t\t\t\t\tMoulin pour %s\n\n",J1);
                        T3[i]=100;
                        printf("\t\tA vous de capturer: \n\t");
                        w11:
                        scanf("%s",&y);
                        if(cond_capture(y)==1)
                        {
                            printf("vous ne pouvez pas capturer ce pion pour l'instant ");
                            goto w11;
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
                                goto w11;
                            }
                        }

                    }
                    else
                    {
                        printf("\t\t\t\t\t\t\t\t\tMoulin pour %s\n\n",J2);
                        T3[i]=100;
                        printf("\t\tA vous de capturer: ");
                        w22:
                        scanf("%s",&y);
                        if(cond_capture(y)==1)
                        {
                            printf("Vous ne pouvez pas capturer ce pion pour l'instant ");
                            goto w22;
                        }
                        else
                        {
                            j=posPion(y,T);
                            if(T2[j]=='$')
                            {
                                T2[j]=T[j];
                            }
                            else
                            {
                                printf("Vous devez capturer l'un des pions de votre adversaire ");
                                goto w22;
                            }
                        }

                    }
                }
            }
        if(nbrPionPoseJ1(T2)<3)
        {
            system("cls");
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
            printf("\n\n\n\n\n\t\t\t\t\t\t\t\t Le gagnant est : %s",J2);
            printf("\n\n\t\t\t\t\t\t\t\t\t ( Entrez n'importe quel caractere pour sortir de la partie ) ");
            getch();
            system("cls");
            goto P22;
        }
        if(nbrPionPoseJ2(T2)<3)
        {
            system("cls");
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
            printf("\n\n\n\n\n\t\t\t\t\t\t\t\t Le gagnant est : %s",J1);
            printf("\n\n\t\t\t\t\t\t\t\t\t ( Entrez n'importe quel caractere pour sortir de la partie ) ");
            getch();
            system("cls");
            goto P22;
        }
        count++;
        }
        goto p;


    case 2 :
system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tJoueur 1 entrez votre nom : ");
        scanf("%s",&J1);
        system("cls");
        ff:
        if(count<18)
        {
        plateau(T,T2);
        p2:
        if (count%2==0)
        {
        printf("\n\t\t\t %s A vous de jouer",J1);
        printf("\n\n------->Donner la position du pion :\n");
        scanf("%s",&x);
        if (condition(count,x,T,T2)==0)
        {
            printf("vous devez choisir l'un des pions disponible");
            goto p2;
        }
        }
        else
        {
            jj:
            srand(time(NULL));
            int i=rand()%24;
            if ((T2[i]=='$') || (T2[i]=='*'))
                {
                  goto jj;
                }
            else
               {
               x=T[i];
               }
        }
        Moulin2(T2);
        changer(count,x,T,T2);
        nbrPions(count);
        MOULIN(T2);
        count+=1;
        goto ff;
    case 3 :
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

void MOULIN(char T2[24])   // T3 et T4 : des variables globales
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

int posPion(char x,char T2[24])  // permet de donner la position du pion choisis par l'utilisateur dans le tableau
{
    int i;
    for(i=0;i<24;i++)
    {
        if(T2[i]==x)
            break;
    }
    return i;
}

int cond_deplacer(char y ,char x ,char T[24] ,char T1[24])  //permet de verifier la possibilite de deplacement
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
        for (i=0;i<x;i++)
        {
            if(x==T24[i] && T1[pos]!='*' && T1[pos]!='$')  c = 1;
        }
    }
    return c;
}

void deplacer(char y, char x, char T[24], char T1[24])    // permet le déplacement des pions
{
    int i,j;
    i=posPion(y,T);
    j=posPion(x,T);
    T1[i]=y;
    if(Player(count)==1) T1[j]='$';
    else T1[j]='*';
}

void Moulin2(char T2[24])    // pour detecter un moulin une autre fois dans un mm emplacement après modification du moulin
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


int nbrPionPoseJ1(char T2[24])    // Permet de calculer le nombre de pion du joueur 1 resté dans le plateau
{
    int i,j1=0;
    for(i=0;i<24;i++)
    {
        if(T2[i]=='$')
            j1++;
    }
    return j1;
}

int nbrPionPoseJ2(char T2[24])      // Permet de calculer le nombre de pion du joueur 2 resté dans le plateau
{
    int i,j2=0;
    for(i=0;i<24;i++)
    {
        if(T2[i]=='*')
            j2++;
    }
    return j2;
}


void loading1()
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

void loading2()
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





int cond_capture(char x)     //------------------Permet de ne pas capturer l'un des pions allignés-------------------
{
    int c=0;
    if(T4[0]=1)
        if( x=='a' || x=='b' || x=='c' )
        {
            {c=1;}
        }
        else
            c=0;
    if(T4[1]=2)
        if(x=='d'||x=='e'||x=='f')
        {
            {c=1;}
        }
        else
            c=0;
    if(T4[2]=3)
        if(x=='g'||x=='h'||x=='i')
        {
            {c=1;}
        }
        else
            c=0;
    if(T4[3]=4)
        if(x=='j'||x=='k'||x=='l')
        {
            {c=1;}
        }
        else
            c=0;
    if(T4[4]=5)
        if(x=='m'||x=='n'||x=='o')
        {
            {c=1;}
        }
        else
            c=0;
    if(T4[5]=6)
        if(x=='p'||x=='q'||x=='r')
        {
            {c=1;}
        }
        else
            c=0;
    if(T4[6]=7)
        if(x=='s'||x=='t'||x=='u')
        {
            {c=1;}
        }
        else
            c=0;
    if(T4[7]=8)
        if(x=='v'||x=='w'||x=='x')
        {
            {c=1;}
        }
        else
            c=0;
    if(T4[8]=9)
        if(x=='a'||x=='j'||x=='v')
        {
            {c=1;}
        }
        else
            c=0;
    if(T4[9]=10)
        if(x=='d'||x=='k'||x=='s')
        {
            {c=1;}
        }
        else
            c=0;
    if(T4[10]=11)
        if(x=='g'||x=='l'||x=='p')
        {
            {c=1;}
        }
        else
            c=0;
    if(T4[11]=12)
        if(x=='b'||x=='e'||x=='h')
        {
            {c=1;}
        }
        else
            c=0;
    if(T4[12]=13)
        if(x=='q'||x=='t'||x=='w')
        {
            {c=1;}
        }
        else
            c=0;
    if(T4[13]=14)
        if(x=='i'||x=='m'||x=='r')
        {
            {c=1;}
        }
        else
            c=0;
    if(T4[14]=15)
        if(x=='f'||x=='n'||x=='u')
        {
            {c=1;}
        }
        else
            c=0;
    if(T4[15]=16)
        if(x=='c'||x=='o'||x=='x')
        {
            {c=1;}
        }
        else
            c=0;
    return c;
}
int cond_deplacer(char y ,char x ,char T[24] ,char T1[24])  //permet de verifier la possibilite de deplacement
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
    char T10[2]="va";
    char T11[4]="jdsl";
    char T12[3]="kgp";
    char T13[3]="irn";
    char T14[4]="mfuo";
    char T15[2]="cx";
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
        for (i=0;i<2;i++)
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
        for (i=0;i<2;i++)
        {
            if(x==T15[i] && T1[pos]!='*' && T1[pos]!='$')  c = 1;
        }
    }
      else if(y=='p')
    {
        for (i=0;i<2;i++)
        {
            if(x==T16[i] && T1[pos]!='*' && T1[pos]!='$')  c = 0;
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
        for (i=0;i<x;i++)
        {
            if(x==T24[i] && T1[pos]!='*' && T1[pos]!='$')  c = 1;
        }
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
