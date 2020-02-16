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
int cond_capture(char x);
int Deplacement_Machine(char y,char T[24],char T1[24]);
void PionPose(char T2[24]);
void PionPoseMACHINE3(char T2[24]);
int Connd_Deplacement_Machine(char y,char T[24],char T1[24]);
int Blockage_Deplacement(char y ,char T[24] ,char T1[24]);
int Blockage_J1(char T[24] ,char T1[24]);
int Blockage_J2(char T[24] ,char T1[24]);
char Block_MoulinM(char T[24],char T2[24]);
int nbr_Pion(char Tx[3],char T[24],char T2[24]);
int nbr_PionM(char Tx[3],char T[24],char T2[24]);
char Moulin_Machine(char T[24],char T2[24]);
char captureM(char T[24],char T2[24]);
char Moulin_Machine(char T[24],char T2[24]);
char Attaque_depl_libre(char T[24],char T2[24]);
void joueur_ordinateur(char T[24],char T2[24]);
void joueur_humain(char T[24],char T2[24]);
void Moulin_Machine_Moyenne(int i,char T[24],char T2[24]);
void Moulin_Machine_Facile(int i,char T[24],char T2[24]);
void Rejouer(char T[24],char T2[24]);
void YOU();
void MoulinJ2(int i,char T[24],char T2[24]);
void MoulinJ1(int i,char T[24],char T2[24]);

#endif // FONCTIONS_H_INCLUDED
