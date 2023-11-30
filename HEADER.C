//
// Created by dia2l on 28-11-23.
//

#include "header.h"
#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <time.h>
#include<unistd.h>
#include <string.h>

#define LIGNE 10
#define COLONNE 20
#define OBSTACLE 8
#define PIEGE 6
#define OBSTACLE_DEPLACABLE 6
#define OBSTACLE_CASSABLE 6
#define VIE 3

//initialisation teleportation 
int Teleporteur1Depart[2] = {3, 3};
int Teleporteur1Arrivee[2] = {7, 7};
int Teleporteur2Depart[2] = {2, 6};
int Teleporteur2Arrivee[2] = {5, 10};
int Teleporteur3Depart[2] = {1, 9};
int Teleporteur3Arrivee[2] = {6, 15};

// Sous-programme de gestion du nombre de vies
int Vie(int nb_vies) {
    // Décremente le nombre de vies
    nb_vies = nb_vies - 1;
    return nb_vies; // renvoie la nouvelle valeur du nombre de vie
}

void pause(int isPaused, int timer) {
    char ch;
    isPaused = 1;
    int timerInter = timer;
    system("cls");
    printf("Le jeu est actuellement en pause, Appuyer sur p de nouveau pour reprendre la partie.");
    while (1) {
        if (kbhit()) {
            ch = getch();
            if (ch == 'p') {
                isPaused = 0;
                system("cls");
                printf("3");
                sleep(1);
                system("cls");
                printf("2");
                sleep(1);
                system("cls");
                printf("1");
                sleep(1);
                system("cls");
                timer = timerInter;
                break;
            }
        }
    }
}


// Sous-programme qui vérifie l'état du nombre de vies
int checkingVie(int vies) {
    // Si le nombre de vies est égal à 0
    if (vies == 0) {
        return 'a'; // le sous-programme retourne le charactère a
    }
        // Si le nombre de vies est supériieur à 0
    else {
        return 'b'; // le sous-programme retourne le charactère b
    }
}

// Sous-programme initialisant la matrice (plateau de jeu)
void InitialisationMatrice(char Tableau[LIGNE][COLONNE]) {

    // Déclaration d'un nouveau tableau
    char NvTableau[LIGNE][COLONNE] = {
            {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
            {'*', 'O', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O', '*'},
            {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
            {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
            {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
            {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
            {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
            {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
            {'*', 'O', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O', '*'},
            {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    };

    // Intégration des éléments du nouveau tableau dans le tableau principal
    for (int i = 0; i < LIGNE; i++) {
        for (int j = 0; j < COLONNE; j++) {
            Tableau[i][j] = NvTableau[i][j];
        }
    }
}

// Sous-programme initialisant les blocs piégés
void InitialisationObstaclePiege(int Piege[2][PIEGE]) {

    // Déclaration des positions des blocs piégés dans le tableau TabPiege
    int TabPiege[2][PIEGE] = {
            {4, 4,  1, 1,  8, 8,},
            {7, 11, 4, 15, 4, 15}};

    // Copie des éléments de TabPiege dans le tableau Piege
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < PIEGE; j++) {
            Piege[i][j] = TabPiege[i][j];
        }
    }
}

// Sous-programme initialisant les blocs fixes
void InitialisationObstacle(int tab[2][OBSTACLE]) {

    // Déclaration des positions des blocs fixes dans le tableau TabObstacles
    int TabObstacle[2][OBSTACLE] = {
            {2, 7, 2,  7,  2, 3, 5, 6},
            {2, 2, 17, 17, 9, 9, 9, 9}};

    // Copie des éléments de TabObstacles dans le tableau principal
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < OBSTACLE; j++) {
            tab[i][j] = TabObstacle[i][j];
        }
    }
}

// Sous-programme initialisant les blocs déplacables
void InitialisationObstacleDeplacable(int Tableau[3][OBSTACLE_DEPLACABLE]) {

    // Déclaration des positions des blocs déplacables dans le tableau NewTab
    int NewTab[3][OBSTACLE_DEPLACABLE] = {
            {4, 4,  1, 5,  8, 8},
            {4, 13, 8, 16, 7, 13},
            {0, 0,  0, 0,  0, 0,}};

    // Copie des éléments de NewTab dans le tableau principal
    for (int k = 0; k < 3; k++) {
        for (int z = 0; z < OBSTACLE_DEPLACABLE; z++) {
            Tableau[k][z] = NewTab[k][z];
        }
    }
}

// Sous-programme initialisant les blocs cassables
void InitialisationObstacleCassable(int Tab[2][OBSTACLE_CASSABLE]) {

    // Déclaration des positions des blocs déplacables dans le tableau ObstCassables
    int ObstCassable[3][OBSTACLE_CASSABLE] = {
            {3, 3,  6,  6, 6, 2},
            {2, 16, 12, 6, 2, 6,}};

    // Copie des éléments de ObstCassables dans le tableau principal
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < OBSTACLE_CASSABLE; j++) {
            Tab[i][j] = ObstCassable[i][j];
        }
    }
}

// Sous-programme gérant l'affichage de la matrice avec les différents blocs
void Affichage(char Tab[LIGNE][COLONNE], int PosJoueur[2], int Obstacle[2][OBSTACLE], int Piege[2][PIEGE],
               int ObstDeplacable[3][OBSTACLE_DEPLACABLE], int ObstCassable[2][OBSTACLE_CASSABLE], int PosBalle[2]) {
    int indicateur = 0;
    for (int i = 0; i < LIGNE; i++) {
        for (int j = 0; j < COLONNE; j++) {
            if (PosJoueur[0] == i && PosJoueur[1] == j) {
                printf("P");
                indicateur = 1;
            }
            else if(PosBalle[0] == i && PosBalle[1] == j){
                printf("B");
                indicateur = 1;
            }
            else {
                for (int z = 0; z < PIEGE; z++) {
                    if (Piege[0][z] == i && Piege[1][z] == j) {
                        printf("%c", 178);
                        indicateur = 1;
                    }
                }
                for (int k = 0; k < OBSTACLE; k++) {
                    if (Obstacle[0][k] == i && Obstacle[1][k] == j) {
                        printf("%c", 223);
                        indicateur = 1;
                    }
                }
                for (int y = 0; y < OBSTACLE_DEPLACABLE; y++) {
                    if (ObstDeplacable[0][y] == i && ObstDeplacable[1][y] == j) {
                        printf("%c", 244);
                        indicateur = 1;
                    }
                }
                for (int w = 0; w < OBSTACLE_CASSABLE; w++) {
                    if (ObstCassable[0][w] == i && ObstCassable[1][w] == j) {
                        printf("%c", 184);
                        indicateur = 1;
                    }
                }
            }
            if (indicateur == 0) {
                printf("%c", Tab[i][j]);
            }
            printf("|");
            indicateur = 0;
        }
        printf("\n");
    }
    printf("\n");
}

// Sous-programme affichant le menu du jeu
int menu() {
    int valmenu; // Valeur saisie par le joueur pour choisir une option du menu
    printf("****************************************************************\n");
    printf("                       SNOOPY MAGIC SHOW                                      \n");
    printf("****************************************************************\n");
    printf("\n 1 - Commencer une nouvelle partie\n 2 - Continuer\n 3 - Utiliser un mot de passe\n 4 - Regles du jeu\n 5 - Scores\n 6 - Quitter\n");
    scanf("%d", &valmenu); // Sasie du choix d'une option du menu
    return valmenu; // Retourne le numéro du chois saisi
}

// Sous-programme gérant les déplacements de Snoopy
int DeplacementJoueur(int PosJoueur[2], char touche, int Obst[2][OBSTACLE], int Piege[2][PIEGE],
                      int ObstDeplacable[3][OBSTACLE_DEPLACABLE], int ObsCassable[2][OBSTACLE_CASSABLE],int vies, int PositionBalle[2]) {
    int indicateur = 0; // Initialisation d'une variable indicatrice
    // Si la touche q est pressée (pour aller à gauche)
    if (touche == 'q') {

        // Si Snoopy est à droite d'un mur
        if (PosJoueur[1] == 1) {
            // La position de Snoopy n'est pas modifiée
            printf("AIE... Snoopy s'est cogne la tete contre le mur !\n");
            indicateur = 1; // L'indicateur prend la valeur 1
        }

            // Si Snoopy n'est pas à droite d'un mur
        else {
            for (int k = 0; k < OBSTACLE; k++) {
                // Si Snoopy est du côté droit d'un obstacle fixe
                if (PosJoueur[0] == Obst[0][k] && PosJoueur[1] == Obst[1][k] + 1) {
                    // La position de Snoopy n'est pas modifiée
                    printf("Ceci est un obstacle...\n ");
                    indicateur = 1; // L'indicateur prend la valeur 1
                }
            }
            for (int y = 0; y < PIEGE; y++) {
                // Si Snoopy est du côté droite d'un bloc piégé
                if (PosJoueur[0] == Piege[0][y] && PosJoueur[1] == Piege[1][y] + 1) {
                    system("cls"); // Nettoyage de la console
                    printf("BOOUUMM!!!\n");
                    sleep(2); // Délai de 2 secondes
                    system("cls"); // Nettoyage de la console
                    // Appel de du sous-programme gérant le nombre de vies et mise à jour de la valeur
                    vies = Vie(vies);
                    printf("Vies : %d\n", vies); // Affichage du nouveau nombre de vies
                    sleep(2); // Délai de 2 secondes
                    system("cls"); // Nettoyage de la console
                    return 2; // Retourne la valeur 2
                }
            }
            for (int p = 0; p < OBSTACLE_DEPLACABLE; p++) {
                // Si Snoopy est du côté droite d'un bloc déplacable
                if (PosJoueur[0] == ObstDeplacable[0][p] && PosJoueur[1] == ObstDeplacable[1][p] + 1 &&
                    ObstDeplacable[2][p] == 0) {
                    if (ObstDeplacable[1][p] != 1) {
                        // Le bloc deplacable est décalé d'une case vers la gauche
                        ObstDeplacable[1][p] = ObstDeplacable[1][p] - 1;
                        // Snoopy est décalé d'une case vers la gauche
                        PosJoueur[1] = PosJoueur[1] - 1;
                        ObstDeplacable[2][p] = 1;
                    }
                    indicateur = 1; // L'indicateur prend la valeur 1
                }
                    // Si le bloc deplacable a deja été deplacé
                else {
                    if (PosJoueur[0] == ObstDeplacable[0][p] && PosJoueur[1] == ObstDeplacable[1][p] + 1 &&
                        ObstDeplacable[2][p] == 1) {
                        // La position de Snoopy n'est pas modifiée
                        indicateur = 1; // L'indicateur prend la valeur 1
                    }
                }
            }
            for (int h = 0; h < OBSTACLE_CASSABLE; h++) {
                // Si Snoopy est du côté droite d'un bloc cassable
                if (PosJoueur[0] == ObsCassable[0][h] && PosJoueur[1] == ObsCassable[1][h] + 1) {
                    // La position de Snoopy n'est pas modifiée
                    indicateur = 1; // L'indicateur prend la valeur 1
                }
            }
        }
        // Si la valeur de l'indicateur n'a pas été modifiée (soit égale à 1)
        if (indicateur == 0) {
            // Snoopy avance d'une case vers la gauche
            PosJoueur[1] = PosJoueur[1] - 1;
        }
    }

        // Si la touche d est pressée (pour aller à droite)
    else if (touche == 'd') {

        // Si Snoopy est à gauche d'un mur
        if (PosJoueur[1] == 18) {
            // La position de Snoopy n'est pas modifiée
            printf("Snoopy s'est cogne la tete contre le mur ! Faites plus attention...\n");
            indicateur = 1; // L'indicateur prend la valeur 1
        }

            // Si Snoopy n'est pas à droite d'un mur
        else {
            for (int k = 0; k < OBSTACLE; k++) {
                // Si Snoopy est à gauche d'un bloc fixe
                if (PosJoueur[0] == Obst[0][k] && PosJoueur[1] == Obst[1][k] - 1) {
                    // La position de Snoopy n'est pas modifiée
                    printf("Ceci est un obstacle\n");
                    indicateur = 1; // L'indicateur prend la valeur 1
                }
            }
            for (int y = 0; y < PIEGE; y++) {
                // Si Snoopy est à gauche d'un bloc piège
                if (PosJoueur[0] == Piege[0][y] && PosJoueur[1] == Piege[1][y] - 1) {
                    system("cls"); // Nettoyer la console
                    printf("BOOUUMM!!!\n");
                    sleep(2); // Délai de 2 secondes
                    system("cls"); // Nettoyer la console
                    // Appel de du sous-programme gérant le nombre de vies et mise à jour de la valeur
                    vies = Vie(vies);
                    printf("Vies : %d\n", vies); // Affichage du nouveau nombre de vies
                    sleep(2); // Délai de 2 secondes
                    system("cls"); // Nettoyer la console
                    return 2; // Retourne la valeur 2
                }
            }
            for (int p = 0; p < OBSTACLE_DEPLACABLE; p++) {
                // Si Snoopy est à gauche d'un bloc deplacable
                if (PosJoueur[0] == ObstDeplacable[0][p] && PosJoueur[1] == ObstDeplacable[1][p] - 1 &&
                    ObstDeplacable[2][p] == 0) {
                    if (ObstDeplacable[1][p] != 18) {
                        // Le bloc deplacable est décalé d'une case vers la gauche
                        ObstDeplacable[1][p] = ObstDeplacable[1][p] + 1;
                        // Snoopy est décalé d'une case vers la gauche
                        PosJoueur[1] = PosJoueur[1] + 1;
                        ObstDeplacable[2][p] = 1;
                    }
                    indicateur = 1; // L'indicateur prend la valeur 1
                }
                    // Si le bloc deplacable a deja été deplacé
                else {
                    if (PosJoueur[0] == ObstDeplacable[0][p] && PosJoueur[1] == ObstDeplacable[1][p] - 1 &&
                        ObstDeplacable[2][p] == 1) {
                        // La position de Snoopy n'est pas modifiée
                        indicateur = 1; // L'indicateur prend la valeur 1
                    }
                }
            }
            for (int h = 0; h < OBSTACLE_CASSABLE; h++) {
                // Si Snoopy est à gauche d'un bloc cassable
                if (PosJoueur[0] == ObsCassable[0][h] && PosJoueur[1] == ObsCassable[1][h] - 1) {
                    // La position de Snoopy n'est pas modifiée
                    indicateur = 1; // L'indicateur prend la valeur 1
                }
            }
        }
        // Si la valeur de l'indicateur n'a pas été modifiée (soit égale à 1)
        if (indicateur == 0) {
            // Snoopy avance d'une case vers la droite
            PosJoueur[1] = PosJoueur[1] + 1;
        }
    }

        // Si la touche z est pressée (pour aller vers le haut)
    else if (touche == 'z') {

        // Si Snoopy est sous un mur
        if (PosJoueur[0] == 1) {
            // La position de Snoopy n'est pas modifiée
            printf("Snoopy s'est cogne la tete contre le mur ! Faites plus attention...\n");
            indicateur = 1; // L'indicateur prend la valeur 1
        }

            // Si Snoopy n'est pas sous un mur
        else {
            for (int k = 0; k < OBSTACLE; k++) {
                // Si Snoopy est sous un bloc fixe
                if (PosJoueur[0] == Obst[0][k] + 1 && PosJoueur[1] == Obst[1][k]) {
                    // La position de Snoopy n'est pas modifiée
                    printf("Ceci est un obstacle\n");
                    indicateur = 1; // L'indicateur prend la valeur 1
                }
            }
            for (int y = 0; y < PIEGE; y++) {
                // Si Snoopy est sous un bloc piégé
                if (PosJoueur[0] == Piege[0][y] + 1 && PosJoueur[1] == Piege[1][y]) {
                    system("cls"); // Nettoyage de la console
                    printf("BOOUUMM!!!\n");
                    sleep(2); // Délai de 2 secondes
                    system("cls"); // Nettoyage de la console
                    // Appel de du sous-programme gérant le nombre de vies et mise à jour de la valeur
                    vies = Vie(vies);
                    printf("Vies : %d\n", vies); // Affichage du nouveau nombre de vies
                    sleep(2); // Délai de 2 secondes
                    system("cls"); // Nettoyage de la console
                    return 2; // Retourne la valeur 2
                }
            }
            for (int p = 0; p < OBSTACLE_DEPLACABLE; p++) {
                // Si Snoopy est sous un bloc deplacable
                if (PosJoueur[1] == ObstDeplacable[1][p] && PosJoueur[0] == ObstDeplacable[0][p] + 1 &&
                    ObstDeplacable[2][p] == 0) {
                    if (ObstDeplacable[0][p] != 1) {
                        // Le bloc deplacable est décalé d'une case vers le haut
                        ObstDeplacable[0][p] = ObstDeplacable[0][p] - 1;
                        // Snoopy est décalé d'une case vers le haut
                        PosJoueur[0] = PosJoueur[0] - 1;
                        ObstDeplacable[2][p] = 1;
                    }
                    indicateur = 1; // L'indicateur prend la valeur 1
                }
                    // Si le bloc déplacable a déjà été déplacé
                else {
                    if (PosJoueur[1] == ObstDeplacable[1][p] && PosJoueur[0] == ObstDeplacable[0][p] + 1 &&
                        ObstDeplacable[2][p] == 1) {
                        // La position de Snoopy n'est pas modifiée
                        indicateur = 1; // L'indicateur prend la valeur 1
                    }
                }
            }
            for (int h = 0; h < OBSTACLE_CASSABLE; h++) {
                // Si Snoopy est sous un bloc cassable
                if (PosJoueur[1] == ObsCassable[1][h] && PosJoueur[0] == ObsCassable[0][h] + 1) {
                    // La position de Snoopy n'est pas modifiée
                    indicateur = 1; // L'indicateur prend la valeur 1
                }
            }
        }
        // Si la valeur de l'indicateur n'a pas été modifiée (soit égale à 1)
        if (indicateur == 0) {
            // Snoopy se déplace d'une case vers le haut
            PosJoueur[0] = PosJoueur[0] - 1;
        }
    }
// Si la touche c est pressée (pour casser un obstacle cassable)
    else if (touche == 'c') {
        for (int w = 0; w < OBSTACLE_CASSABLE; w++) {
            // Si Snoopy est en-dessous, au-dessus, à droite ou à gauche d'un bloc cassable
            if (PosJoueur[0] == ObsCassable[0][w] && PosJoueur[1] == ObsCassable[1][w] - 1 ||
                PosJoueur[0] == ObsCassable[0][w] && PosJoueur[1] == ObsCassable[1][w] + 1 ||
                PosJoueur[1] == ObsCassable[1][w] && PosJoueur[0] == ObsCassable[0][w] - 1 ||
                PosJoueur[1] == ObsCassable[1][w] && PosJoueur[0] == ObsCassable[0][w] + 1) {
                // La position du bloc cassable va en dehors de la matrice pour ne plus apparaitre dans la zone de jeu
                ObsCassable[0][w] = 12;
                ObsCassable[1][w] = 0;
            }
        }
    }
        // Si la touche s est pressée (pour )
    else if (touche == 's') {
        if (PosJoueur[0] == 8) {
            printf("Snoopy s'est cogne la tete contre le mur ! Faites plus attention...\n");
            indicateur = 1; // L'indicateur prend la valeur 1
        } else {
            for (int k = 0; k < OBSTACLE; k++) {
                if (PosJoueur[0] == Obst[0][k] - 1 && PosJoueur[1] == Obst[1][k]) {
                    printf("Ceci est un obstacle\n");
                    indicateur = 1; // L'indicateur prend la valeur 1
                }
            }
            for (int y = 0; y < PIEGE; y++) {
                if (PosJoueur[0] == Piege[0][y] - 1 && PosJoueur[1] == Piege[1][y]) {
                    system("cls"); // Nettoyer la console
                    printf("BOOUUMM!!!\n");
                    sleep(2); // Délai de 2 secondes
                    system("cls"); // Nettoyer la console
                    vies = Vie(vies);
                    printf("Vies : %d\n", vies);
                    sleep(2); // Délai de 2 secondes
                    system("cls"); // Nettoyer la console
                    return 2;
                }
            }
            for (int p = 0; p < OBSTACLE_DEPLACABLE; p++) {
                if (PosJoueur[1] == ObstDeplacable[1][p] && PosJoueur[0] == ObstDeplacable[0][p] - 1 &&
                    ObstDeplacable[2][p] == 0) {
                    if (ObstDeplacable[0][p] != 8) {
                        ObstDeplacable[0][p] = ObstDeplacable[0][p] + 1;
                        PosJoueur[0] = PosJoueur[0] + 1;
                        ObstDeplacable[2][p] = 1;
                    }
                    indicateur = 1; // L'indicateur prend la valeur 1
                } else {
                    if (PosJoueur[1] == ObstDeplacable[1][p] && PosJoueur[0] == ObstDeplacable[0][p] - 1 &&
                        ObstDeplacable[2][p] == 1) {
                        indicateur = 1; // L'indicateur prend la valeur 1
                    }
                }
            }
            for (int h = 0; h < OBSTACLE_CASSABLE; h++) {
                if (PosJoueur[1] == ObsCassable[1][h] && PosJoueur[0] == ObsCassable[0][h] - 1) {
                    indicateur = 1; // L'indicateur prend la valeur 1
                }
            }
            if (indicateur == 0) {
                PosJoueur[0] = PosJoueur[0] + 1;
            }
        }
    }
    indicateur = 0; // L'indicateur prend la valeur 0
    return 1; // Retourne la valeur 1
}

// Sous-programme affichant le timer
void AfficheTimer(int timer) {
    printf("Temps restant : %d secondes\n", timer);
}


int deplacementBalle(int posBalle[2],char Tab[LIGNE][COLONNE],int ind,int posBalleint[2]) {
    /*
    * Pour la vitesse de la balle, il faut juste mettre le temps qu'il sécoule entre 2 déplacements de la balle. (temps qu'elle prend pour passer d'une case à l'autre).
     * Le fonctionnement est assez complexe pour pas grand chose mais ça marche donc je touche plus.
    */
    if(posBalle[0] == 8 && posBalle[1] == 1){
        posBalleint[0] = posBalle[0];
        posBalleint[1] = posBalle[1];
        posBalle[0]--;
        posBalle[1]++;
        ind = 2;
        return ind;
    }
    else if(posBalle[0] == 1 && posBalle[1] == 1){
        posBalleint[0] = posBalle[0];
        posBalleint[1] = posBalle[1];
        posBalle[0]++;
        posBalle[1]++;
        ind = 3;
        return ind;
    }
    else if(posBalle[0] == 1 && posBalle[1] == 18){
        posBalleint[0] = posBalle[0];
        posBalleint[1] = posBalle[1];
        posBalle[0]++;
        posBalle[1]--;
        ind = 4;
        return ind;
    }
    else if(posBalle[0] == 8 && posBalle[1] == 18){
        posBalleint[0] = posBalle[0];
        posBalleint[1] = posBalle[1];
        posBalle[0]--;
        posBalle[1]--;
        ind = 1;
        return ind;
    }
    if(ind == 1){
        if(posBalleint[0] == posBalle[0] - 1){
            posBalleint[0] = posBalle[0];
            posBalleint[1] = posBalle[1];
            posBalle[0]++;
            posBalle[1]++;
        }
        else {
            posBalleint[0] = posBalle[0];
            posBalleint[1] = posBalle[1];
            posBalle[0]--;
            posBalle[1]++;
        }
        if(posBalle[1] == 18){
            ind = 4;
            return ind;
        }
        else if(posBalle[0] == 1){
            ind = 3;
            return ind;
        }
        else if(posBalle[0] == 8){
            ind = 2;
            return ind;
        }
        return ind;
    }
    else if(ind == 2){
        if(posBalleint[1] == posBalle[1] + 1){
            posBalleint[0] = posBalle[0];
            posBalleint[1] = posBalle[1];
            posBalle[0]--;
            posBalle[1]--;
        }
        else {
            posBalleint[0] = posBalle[0];
            posBalleint[1] = posBalle[1];
            posBalle[0]--;
            posBalle[1]++;
        }
        if(posBalle[1] == 18){
            ind = 4;
            return ind;
        }
        else if(posBalle[1] == 1){
            ind = 1;
            return ind;
        }
        else if(posBalle[0] == 1){
            ind = 3;
            return ind;
        }
        return ind;
    }
    else if(ind == 3){
        if(posBalleint[1] == posBalle[1] + 1){
            posBalleint[0] = posBalle[0];
            posBalleint[1] = posBalle[1];
            posBalle[0]++;
            posBalle[1]--;
        }
        else {
            posBalleint[0] = posBalle[0];
            posBalleint[1] = posBalle[1];
            posBalle[0]++;
            posBalle[1]++;
        }
        if(posBalle[1] == 18){
            ind = 4;
            return ind;
        }
        else if(posBalle[1] == 1){
            ind = 1;
            return ind;
        }
        else if(posBalle[0] == 8){
            ind = 2;
            return ind;
        }
        return ind;
    }
    else if(ind == 4){
        if(posBalleint[0] == posBalle[0] + 1){
            posBalleint[0] = posBalle[0];
            posBalleint[1] = posBalle[1];
            posBalle[0]--;
            posBalle[1]--;
        }
        else {
            posBalleint[0] = posBalle[0];
            posBalleint[1] = posBalle[1];
            posBalle[0]++;
            posBalle[1]--;
        }
        if(posBalle[0] == 1){
            ind = 3;
            return ind;
        }
        else if(posBalle[1] == 1){
            ind = 1;
            return ind;
        }
        else if(posBalle[0] == 8){
            ind = 2;
            return ind;
        }
        return ind;
    }
    return 0;
}

// Sous programme évaluant l'exactitude du mot de passe saisi
int comparaison(char str1[], char str2[]) {
    int value = 1; // Par défaut, le mot de passe saisi est correct
    // Pour chaque charactère saisi
    for (int i = 0; i < strlen(str1); i++) {
        // Comparaison de la saisie et du mot de passe enregistré
        if (str1[i] != str2[i]) {
            // Si 2 caractères sont différents
            value = 0; // Le mot de passe est faux
            return value; // Retourne la valeur 0 pour le mot de passe faux
        }
    }
    // Si chaque caractère est correct
    return value; // Retourne la valeur du mot de passe correct (1)
}

// Sous-programme de gestion des mots de passe
int gestionMDP(char MDP[], char Motdepasse1[], char Motdepasse2[], char Motdepasse3[], char Motdepasse4[]) {
    int value = 0; // Numéro des niveaux correspondant aux mots de passes saisis
    // Si le mot de passe pour le niveau 1 saisi est juste
    if (comparaison(MDP, Motdepasse1) == 1) {
        value += 1;
        return value; // Retourne le numéro du niveau correspondant au mot de passe
    }
    // Si le mot de passe pour le niveau 2 saisi est juste
    if (comparaison(MDP, Motdepasse2) == 1) {
        value += 2;
        return value; // Retourne le numéro du niveau correspondant au mot de passe
    }
    // Si le mot de passe pour le niveau 3 saisi est juste
    if (comparaison(MDP, Motdepasse3) == 1) {
        value += 3;
        return value; // Retourne le numéro du niveau correspondant au mot de passe
    }
    // Si le mot de passe pour le niveau 4 saisi est juste
    if (comparaison(MDP, Motdepasse4) == 1) {
        value += 4;
        return value; // Retourne le numéro du niveau correspondant au mot de passe
    }
        // Si le mot de passe saisi ne correspond à aucun mot de passe enregistré
    else {
        return 5; // Commande le retour au menu
    }
}

// Sous-programme gérant le choix des niveaux
void gestionChoixNiveau(int niveau) {
    // Attribution des fichiers textes à chaque niveau
    FILE *Niveau1;
    FILE *Niveau2;
    FILE *Niveau3;
    FILE *Niveau4;
    // Si le niveau 1 est choisi
    if (niveau == 1) {
        // Le fichier texte du niveau 1 est appelé
        Niveau1 = fopen("niveau1.txt", "r");
        // Message d'erreur
        if (Niveau1 == NULL) {
            printf("Impossible d'ouvrir le fichier.");
            return;
        }
    }
}

// Sous-programme gérant la partie du jeu
int jeu(int niveau) {
    int f = 0;
    int Obstacle[2][OBSTACLE];
    char Tableau[LIGNE][COLONNE];
    int Piege[2][PIEGE];
    int ObstDeplacable[3][OBSTACLE_DEPLACABLE];
    int ObstCassable[2][OBSTACLE_CASSABLE];
    char pos;
    char ch;
    int timerInter;
    char oiseaux = 'O';
    int NombreOiseaux = 4;
    int PositionJoueur[2] = {4, 9};
    //int positionBalle[2] = {3, 7};
    int Paused = 0;
    clock_t pauseStart = 0;
    // Départ du timer
    clock_t start = clock();
    int vies = VIE;
    int timer = 120; // 120 secondes pour le timer
    int posBalle[2] = {0,3};
    int posBalleint[2] = {posBalle[0],posBalle[1]};
    int indic = deplacementBalle(posBalle,Tableau,4,posBalleint);
    // Appels des sous-programmes initialisant la matrice, les blocs fixes, piégés, deplacables et cassables
    InitialisationMatrice(Tableau);
    InitialisationObstacle(Obstacle);
    InitialisationObstaclePiege(Piege);
    InitialisationObstacleDeplacable(ObstDeplacable);
    InitialisationObstacleCassable(ObstCassable);

    // Appels des sous-programmes affichant la matrice complète et le timer
    Affichage(Tableau, PositionJoueur, Obstacle, Piege, ObstDeplacable, ObstCassable,posBalle);
    AfficheTimer(timer);

    // Tant que le tous les oiseaux n'ont pas été attrapés et que le timer ne s'est pas terminé
    while (f != 4 && timer > 0) {
        // Si une touche du clavier est activée
        if (kbhit()) {
            //deplacementBalle(positionBalle,Tableau);
            pos = getch(); // Prise en compte de la touche pressée sans avoir à presser ENTRER
            system("cls"); // Nettoyer la console
            if (DeplacementJoueur(PositionJoueur, pos, Obstacle, Piege, ObstDeplacable, ObstCassable,vies, posBalle) == 2) {
                timer = 120;
                PositionJoueur[0] = 4;
                PositionJoueur[1] = 9;
                Tableau[1][1] = 'O';
                Tableau[1][18] = 'O';
                Tableau[8][1] = 'O';
                Tableau[8][18] = 'O';
                vies -= 1;
                // Si le nombre de vies restantes a atteint 0
                if (checkingVie(vies) == 'a') {
                    system("cls"); // Nettoyer la console
                    printf("Vous n'avez plus de vies...!\n");
                    sleep(2); // Délai de 2 secondes
                    system("cls"); // Nettoyer la console
                    printf("GAME OVER\n");
                    sleep(2); // Délai de 2 secondes
                    vies=3;
                    system("cls"); // Nettoyer la console
                    return 2; // Commande le retour au menu
                }
            }
            if (Paused == 0) {
                clock_t end = clock();
                double elapsed = (double) (end - start) / CLOCKS_PER_SEC;
                if (elapsed >= 0.5) {
                    if (pos == 'p') {
                        pause(Paused, timer);
                    }
                    indic = deplacementBalle(posBalle,Tableau,indic,posBalleint); //Oui oui c'est bien de la récursivité partielle.
                    timer -= (int) elapsed;
                    start = clock(); // Réinitialisation du début pour le prochain tick
                } else {
                    pauseStart = clock();
                }
                system("cls");
                // Affichage de la matrice complète avec les blocs et Snoopy
                Affichage(Tableau, PositionJoueur, Obstacle, Piege, ObstDeplacable, ObstCassable,posBalle);
                // Mise à jour et affichage du timer
                // Affichage du timer
                AfficheTimer(timer);
                // Si Snoopy va sur la position d'un oiseau
                if(posBalle[0] == PositionJoueur[0] && posBalle[1] == PositionJoueur[1]){
                    system("cls");
                    printf(" Ping Pong, sport d'encule ouais.");
                    sleep(2);
                    system("cls");
                    printf("Vies = %d",vies - 1);
                    vies = Vie(vies);
                    if(checkingVie(vies) == 'a'){
                        system("cls");
                        printf("Vous n'avez plus de vies...!\n");
                        sleep(2);
                        system("cls");
                        printf("GAME OVER\n");
                        sleep(2);
                        vies = 3;
                        system("cls");
                        return 2;
                    }
                    sleep(2);
                    timer = 125;
                    PositionJoueur[0] = 4;
                    PositionJoueur[1] = 9;
                    posBalle[0] = 2;
                    posBalle[1] = 3;
                    Tableau[1][1] = 'O';
                    Tableau[1][18] = 'O';
                    Tableau[8][1] = 'O';
                    Tableau[8][18] = 'O';
                    system("cls");
                    Affichage(Tableau, PositionJoueur, Obstacle, Piege, ObstDeplacable, ObstCassable,posBalle);
                    AfficheTimer(120);
                }
                if (Tableau[PositionJoueur[0]][PositionJoueur[1]] == 'O') {
                    // Le nombre d'oiseaux attrapés augmente de 1
                    f++;
                    // Le symbole de l'oiseau est remplacé par une case vide
                    Tableau[PositionJoueur[0]][PositionJoueur[1]] = ' ';
                    // Affichage du nombre d'oiseaux qu'il reste à attraper
                    NombreOiseaux--;
                    printf("\nVous avez attrape un oiseau! Il vous en reste %d a attraper.\n", NombreOiseaux);
                }
                //Sauvegarde
                if(pos == 'x'){
                    system("cls");
                    sauvegarde(Tableau,ObstDeplacable,Piege,ObstCassable,PositionJoueur,NombreOiseaux);
                    sleep(1);
                    system("cls");
                    return 2;
                }
            }
            // Si le timer est écoulé
            if (timer <= 0) {
                // Appel du sous-programme calculant le nombre de vies restantes
                Vie(vies);
                // Si il reste plus de 0 vie
                system("cls");
                printf("\n Le temps est écoulé, vous avez perdu.\n Il ne vous reste plus que %d vies",vies - 1);
                vies = Vie(vies);
                if(checkingVie(vies) == 'a'){
                    system("cls");
                    printf("Vous n'avez plus de vies...!\n");
                    sleep(2);
                    system("cls");
                    printf("GAME OVER\n");
                    sleep(2);
                    vies = 3;
                    system("cls");
                    return 2;
                }
                sleep(2);
                system("cls");
                timer = 122;
                PositionJoueur[0] = 4;
                PositionJoueur[1] = 9;
                Tableau[1][1] = 'O';
                Tableau[1][18] = 'O';
                Tableau[8][1] = 'O';
                Tableau[8][18] = 'O';
                system("cls");
                Affichage(Tableau, PositionJoueur, Obstacle, Piege, ObstDeplacable, ObstCassable, posBalle);
                AfficheTimer(timer);
            }
        }
        // Si tous les oiseaux ont été attrapés
        if (f == 4) {
            printf("Bravo! Vous avez attrape tous les oiseaux!...\n");
            sleep(2); // Délai de 2 secondes
            printf("Votre score est de...\n");
            sleep(2); // Délai de 2 secondesz
            // Affichage et calcul du score (temps restant * 100)
            printf("%d !\n", timer * 100);
            sleep(2); // Délai de 2 secondes
            printf("Merci d'avoir joue !\n");
            sleep(2); // Délai de 2 secondes
            f = 0;
            return 2;
        }
    }
    return 1; // Commande le retour au menu
}
//POUR LINSTANT CA NE FONCTIONNE PAS
void sauvegarde(char Tab[LIGNE][COLONNE],int TabObstaclesDep[3][OBSTACLE_DEPLACABLE], int TabObstPige[2][PIEGE], int TabObstCassable[2][OBSTACLE_CASSABLE],int PosJoueur[2], int nombreOiseaux){ //Penser à rajouter la position de la balle quand le mouvement de la balle sera fait.
    printf("Vous avez choisi de sauvegarder la partie en cours...\n"
           "Veuillez entrer le nom du fichier de sauvegarde : \n");
    char nomSauvegarde[1000];
    scanf("%s",nomSauvegarde);
    FILE *sauvegarde;
    sauvegarde = fopen(nomSauvegarde,"w");
    fprintf(sauvegarde,"%s","Tableau des obstacles cassables : ");
    fprintf(sauvegarde,"%s","\n------------------------------------------------\n");
    for(int i = 0; i<2;i++){
        for(int y = 0;y<OBSTACLE_CASSABLE;y++){
            fprintf(sauvegarde,"%c",'[');
            fprintf(sauvegarde,"%d",TabObstCassable[i][y]);
            fprintf(sauvegarde,"%c",']');
            fprintf(sauvegarde,"%s"," | ");
        }
        fprintf(sauvegarde,"\n");
    }
    fprintf(sauvegarde,"%s","------------------------------------------------\n");
    fprintf(sauvegarde,"%s","Tableau des obstacles deplacables : ");
    fprintf(sauvegarde,"%s","\n------------------------------------------------\n");
    for(int i = 0; i<2;i++){
        for(int y = 0;y<OBSTACLE_DEPLACABLE;y++){
            fprintf(sauvegarde,"%c",'[');
            fprintf(sauvegarde,"%d",TabObstaclesDep[i][y]);
            fprintf(sauvegarde,"%c",']');
            fprintf(sauvegarde,"%s"," | ");
        }
        fprintf(sauvegarde,"\n");
    }
    fprintf(sauvegarde,"%s","------------------------------------------------\n");
    fprintf(sauvegarde,"%s","Tableau des pieges : ");
    fprintf(sauvegarde,"%s","\n------------------------------------------------\n");
    for(int i = 0; i<2;i++){
        for(int y = 0;y<PIEGE;y++){
            fprintf(sauvegarde,"%c",'[');
            fprintf(sauvegarde,"%d",TabObstPige[i][y]);
            fprintf(sauvegarde,"%c",']');
            fprintf(sauvegarde,"%s"," | ");
        }
        fprintf(sauvegarde,"\n");
    }
    fprintf(sauvegarde,"%s","------------------------------------------------\n");
    fprintf(sauvegarde,"%s","Position du joueur : ");
    fprintf(sauvegarde,"%s","\n------------------------------------------------\n");
    for(int i = 0;i<2;i++){
        fprintf(sauvegarde,"%c",'[');
        fprintf(sauvegarde,"%d",PosJoueur[i]);
        fprintf(sauvegarde,"%c",']');
        fprintf(sauvegarde,"%s"," | ");
    }
    fprintf(sauvegarde,"%s","\n------------------------------------------------\n");
    fprintf(sauvegarde,"%s", "Oiseaux = ");
    fprintf(sauvegarde,"%d",nombreOiseaux);
    fprintf(sauvegarde,"%s","\n------------------------------------------------\n");
    fprintf(sauvegarde,"%s","Coordonnees des oiseaux sur la matrice : ");
    fprintf(sauvegarde,"%s","\n------------------------------------------------\n");
    if(Tab[1][18] == 'O'){
        fprintf(sauvegarde,"%d",1);
        fprintf(sauvegarde,"%c",' ');
        fprintf(sauvegarde,"%d",18);
        fprintf(sauvegarde,"%s"," | ");
    }
    if(Tab[1][1] == 'O'){
        fprintf(sauvegarde,"%d",1);
        fprintf(sauvegarde,"%c",' ');
        fprintf(sauvegarde,"%d",1);
        fprintf(sauvegarde,"%s"," | ");
    }
    if(Tab[8][1] == 'O'){
        fprintf(sauvegarde,"%d",8);
        fprintf(sauvegarde,"%c",' ');
        fprintf(sauvegarde,"%d",1);
        fprintf(sauvegarde,"%s"," | ");
    }
    if(Tab[8][18] == 'O'){
        fprintf(sauvegarde,"%d",8);
        fprintf(sauvegarde,"%c",' ');
        fprintf(sauvegarde,"%d",18);
        fprintf(sauvegarde,"%s"," | ");
    }
    fprintf(sauvegarde,"%s","\n------------------------------------------------\n");
}
