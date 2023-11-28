
#define LIGNE 10
#define COLONNE 20
#define OBSTACLE 8
#define PIEGE 6
#define OBSTACLE_DEPLACABLE 6
#define OBSTACLE_CASSABLE 6

#ifndef PROJET_SNOOPY_HEADER_H
#define PROJET_SNOOPY_HEADER_H


int Vie(int nb_vies);

int checkingVie();

void pause(int isPaused, int timer);

void InitialisationMatrice(char Tableau[LIGNE][COLONNE]);

void InitialisationObstaclePiege(int Piege[2][PIEGE]);

void InitialisationObstacle(int tab[2][OBSTACLE]);

void InitialisationObstacleDeplacable(int Tableau[3][OBSTACLE_DEPLACABLE]);

void InitialisationObstacleCassable(int Tab[2][OBSTACLE_CASSABLE]);

void Affichage(char Tab[LIGNE][COLONNE], int PosJoueur[2], int Obstacle[2][OBSTACLE], int Piege[2][PIEGE],
               int ObstDeplacable[3][OBSTACLE_DEPLACABLE], int ObstCassable[2][OBSTACLE_CASSABLE]);

int menu();

int DeplacementJoueur(int PosJoueur[2], char touche, int Obst[2][OBSTACLE], int Piege[2][PIEGE],
                      int ObstDeplacable[3][OBSTACLE_DEPLACABLE], int ObsCassable[2][OBSTACLE_CASSABLE],int vies);

void AfficheTimer(int timer);

void gestionObstacles(char Tab[LIGNE][COLONNE], char tabObstacle[OBSTACLE], int tabPiege[2][PIEGE], int posJoueur[2]);

int comparaison(char str1[], char str2[]);

int gestionMDP(char MDP[], char Motdepasse1[], char Motdepasse2[], char Motdepasse3[], char Motdepasse4[]);

void gestionChoixNiveau(int niveau);

int jeu(int niveau);

#endif //PROJET_SNOOPY_HEADER_H
