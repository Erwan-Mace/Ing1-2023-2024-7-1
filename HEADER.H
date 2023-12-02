
#define LIGNE 10
#define COLONNE 20
#define OBSTACLE_MAX 13
#define PIEGE_MAX 26
#define OBSTACLE_DEPLACABLE_MAX 5
#define OBSTACLE_CASSABLE_MAX 14

#ifndef PROJET_SNOOPY_HEADER_H
#define PROJET_SNOOPY_HEADER_H


int Vie(int nb_vies);

int checkingVie(int vies);

void pause(int isPaused, int timer);

void InitialisationOiseaux(int TabOiseaux[2][4]);

void InitialisationMatrice(char Tableau[LIGNE][COLONNE]);

void InitialisationObstaclePiege(int Piege[2][PIEGE_MAX], int PIEGE);

void InitialisationObstacle(int tab[2][OBSTACLE_MAX], int OBSTACLE);

void InitialisationObstacleDeplacable(int Tableau[3][OBSTACLE_DEPLACABLE_MAX], int OBSTACLE_DEPLACABLE);

void InitialisationObstacleCassable(int Tab[2][OBSTACLE_CASSABLE_MAX], int OBSTACLE_CASSABLE);

void Affichage(int OBSTACLE, int OBSTACLE_CASSABLE, int OBSTACLE_DEPLACABLE, int PIEGE, char Tab[LIGNE][COLONNE],
               int PosJoueur[2], int Obstacle[2][OBSTACLE_MAX], int Piege[2][PIEGE_MAX],
               int ObstDeplacable[3][OBSTACLE_DEPLACABLE_MAX], int ObstCassable[2][OBSTACLE_CASSABLE_MAX],
               int Oiseaux[2][4]);

int menu();

int DeplacementJoueur(int OBSTACLE, int OBSTACLE_CASSABLE, int OBSTACLE_DEPLACABLE, int PIEGE, int PosJoueur[2],
                      char touche, int Obst[2][OBSTACLE_MAX], int Piege[2][PIEGE_MAX],
                      int ObstDeplacable[3][OBSTACLE_DEPLACABLE_MAX], int ObsCassable[2][OBSTACLE_CASSABLE_MAX],
                      int vies);

void AfficheTimer(int timer);

void gestionObstacles(char Tab[LIGNE][COLONNE], char tabObstacle[OBSTACLE_MAX], int tabPiege[2][PIEGE_MAX],
                      int posJoueur[2]);

int comparaison(char str1[], char str2[]);

int gestionMDP(char MDP[], char Motdepasse1[], char Motdepasse2[], char Motdepasse3[], char Motdepasse4[]);

void gestionChoixNiveau(int niveau);

int jeu(int OBSTACLE, int OBSTACLE_CASSABLE, int OBSTACLE_DEPLACABLE, int PIEGE, int niveau,
        int TabObstCassable[2][OBSTACLE_CASSABLE_MAX], int ObstDeplacable[3][OBSTACLE_DEPLACABLE_MAX],
        int TabObstPiege[2][PIEGE_MAX], int PositionJoueur[2], int Oiseaux[2][4], int Obstacle[2][OBSTACLE_MAX],
        int NombreOiseauxTrouve, int vies, int score, int timer);

void sauvegarde(int OBSTACLE, int OBSTACLE_CASSABLE, int OBSTACLE_DEPLACABLE, int PIEGE, char Tab[LIGNE][COLONNE],
                int TabObstaclesDep[3][OBSTACLE_DEPLACABLE_MAX], int TabObstPiege[2][PIEGE_MAX],
                int TabObstCassable[2][OBSTACLE_CASSABLE_MAX], int PosJoueur[2],
                int NombreOiseauxTrouve, int Oiseaux[2][4], int Obstacle[2][OBSTACLE_MAX], int niveau, int Vie,
                int score,
                int timer);

void chargementMatrice(int *OBSTACLE, int *OBSTACLE_CASSABLE, int *OBSTACLE_DEPLACABLE, int *PIEGE,
                       int TabObstCassable[2][OBSTACLE_CASSABLE_MAX],
                       int TabObstaclesDep[3][OBSTACLE_DEPLACABLE_MAX],
                       int TabObstPiege[2][PIEGE_MAX], int PosJoueur[2], int Oiseaux[2][4], int *NombreOiseauxTrouve,
                       char nomChargement[100], int Obstacle[2][OBSTACLE_MAX], int *niveau, int *vie, int *score,
                       int *timer);

#endif //PROJET_SNOOPY_HEADER_H

