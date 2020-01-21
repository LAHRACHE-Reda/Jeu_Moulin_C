#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

void Color(int couleurDuTexte,int couleurDeFond);
void regles();
void menu(char T[24],char T2[24]);
void plateau(char T[24],char T2[24]);
int posPion(char x,char T2[24]);
void changer(int count1,char x,char T[24],char T2[24]);
void coloriage(int x,char T[24],char T2[24]);
int Player(int count1);
void nbrPions(int count1);
int condition(int count1, char s, char T[24],char T2[24]);
void MOULIN(char T2[24]);
int cond_deplacer(char y ,char x ,char T[24] ,char T1[24]);
void deplacer(char y, char x, char T[24], char T1[24]);
void Moulin2(char T2[24]);
int nbrPionPoseJ1(char T2[24]);
int nbrPionPoseJ2(char T2[24]);
void loading1();
void loading2();
cond_capture(char x);
//void deplacement(char T[24],char T2[24]);
//void execute();


#endif // FONCTIONS_H_INCLUDED
