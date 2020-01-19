#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

void Color(int couleurDuTexte,int couleurDeFond);
void menu(char T[24],char T2[24]);
void plateau(char T[24],char T2[24]);
int posPion(char x,char T2[24]);
//void execute();
int Player(int count1);
void nbrPions(int count1);
int condition(int count1, char s, char T[24],char T2[24]);
int MOULIN(char T2[24]);
int cond_deplacer(char y ,char x ,char T[24] ,char T1[24]);
void deplacer(char y, char x, char T[24], char T1[24]);


#endif // FONCTIONS_H_INCLUDED
