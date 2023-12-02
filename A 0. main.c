
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "header.h"
#include <conio.h>

#define LIGNE 10
#define COLONNE 20
#define OBSTACLE_MAX 13
#define PIEGE_MAX 26
#define OBSTACLE_DEPLACABLE_MAX 5
#define OBSTACLE_CASSABLE_MAX 14

int main() {

    // Définition des mots de passe
    char MDP1[] = "Andy"; // Mot de passe pour le niveau 1
    char MDP2[] = "Molly"; // Mot de passe pour le niveau 2
    char MDP3[] = "Spike"; // Mot de passe pour le niveau 3
    char MDP4[] = "Olaf"; // Mot de passe pour le niveau 4

    int Oiseaux[2][4];
    int TabObstCassable[2][OBSTACLE_CASSABLE_MAX];
    int TabObstaclesDep[3][OBSTACLE_DEPLACABLE_MAX];
    int TabObstPiege[2][PIEGE_MAX];
    int PosJoueur[2] = {4, 9};
    int NombreOiseauxTrouve = 0;
    int Obstacle[2][OBSTACLE_MAX];
    char nomChargement[100];
    int niveau;
    int vie = 3;
    int score;
    int timer;
    int OBSTACLE;
    int OBSTACLE_CASSABLE;
    int OBSTACLE_DEPLACABLE;
    int PIEGE;

    // Initialisation d'un tableau de caractères en utilisant les longueurs des mots de passe
    char tabMDP[4] = {MDP1[strlen(MDP1)], MDP2[strlen(MDP2)], MDP3[strlen(MDP3)], MDP4[strlen(MDP4)]};
    int valmenu = menu(); // Variable indiquant le numéro de la fonction choisie et appelée par le menu

    char sortirRegles;

    // Si l'option 1 du menu est choisie : démarrer une partie
    if (valmenu == 1) {
        system("cls"); // Nettoyage de la console
        printf("Chargement du premier niveau...\n");
        sleep(3); // Délai de 3 secondes
        system("cls");// Nettoyage de la console
        //InitialisationObstacle(Obstacle);
        chargementMatrice(&OBSTACLE, &OBSTACLE_CASSABLE, &OBSTACLE_DEPLACABLE, &PIEGE, TabObstCassable, TabObstaclesDep,
                          TabObstPiege, PosJoueur, Oiseaux, &NombreOiseauxTrouve,
                          "Niveau1", Obstacle, &niveau, &vie, &score, &timer);
        //InitialisationOiseaux(Oiseaux);
        //InitialisationObstaclePiege(TabObstPiege);
        //InitialisationObstacleDeplacable(TabObstaclesDep);
        //InitialisationObstacleCassable(TabObstCassable);

        // Si le jeu commande le retour au menu
        if (jeu(OBSTACLE, OBSTACLE_CASSABLE, OBSTACLE_DEPLACABLE, PIEGE, 1, TabObstCassable, TabObstaclesDep,
                TabObstPiege, PosJoueur, Oiseaux, Obstacle, NombreOiseauxTrouve,
                vie, score, timer) == 2) {
            main(); // Retour au menu
        }
    }

        // Si l'option 2 du menu est choisie : continuer une partie
    else if (valmenu == 2) {
        system("cls"); // Nettoyage de la console
        //InitialisationOiseaux(Oiseaux);
        //InitialisationObstacle(Obstacle);
        //InitialisationObstaclePiege(TabObstPiege);
        //InitialisationObstacleDeplacable(TabObstaclesDep);
        //InitialisationObstacleCassable(TabObstCassable);
        printf("Veuillez indiquer le nom du fichier a charger:\n");
        scanf("%s", nomChargement);
        system("cls");
        printf("Chargement de votre sauvegarde...");
        sleep(3); // Délai de 3 secondes
        system("cls");
        chargementMatrice(&OBSTACLE, &OBSTACLE_CASSABLE, &OBSTACLE_DEPLACABLE, &PIEGE, TabObstCassable, TabObstaclesDep,
                          TabObstPiege, PosJoueur, Oiseaux, &NombreOiseauxTrouve,
                          nomChargement, Obstacle, &niveau, &vie, &score, &timer);
        //printf("%d", NombreOiseauxTrouve);
        //printf("\n");
        jeu(OBSTACLE, OBSTACLE_CASSABLE, OBSTACLE_DEPLACABLE, PIEGE, 1, TabObstCassable, TabObstaclesDep, TabObstPiege,
            PosJoueur, Oiseaux, Obstacle, NombreOiseauxTrouve, vie,
            score, timer);
        //char valsauvegarde[50];
        // Saisie de la sauvegarde
        //printf("Quelle sauvegarde voulez-vous utiliser ?\n");
        //scanf("%s", valsauvegarde);
        //Charger la sauvegarde du même nom.
        //INTRODUIRE VIES
    }

        // Si l'option 3 du menu est choisie : charger une partie
    else if (valmenu == 3) {
        system("cls"); // Nettoyage de la console
        char valmdp[100];
        printf("Entrez votre mot de passe : \n");
        scanf("%s", valmdp); // Saisie du mot de passe

        // Appel de la fonction de gestion des mots de passe pour vérifier le mot de passe saisi
        int validation = gestionMDP(valmdp, MDP1, MDP2, MDP3, MDP4);
        //INTRODUIRE VIES

        // Si le mot de passe saisi correspond à celui du premier niveau
        if (validation == 1) {
            system("cls"); // Nettoyage de la console
            printf("Chargement du premier niveau...\n");
            sleep(2); // Délai de 2 secondes
            system("cls"); // Nettoyage de la console
            chargementMatrice(&OBSTACLE, &OBSTACLE_CASSABLE, &OBSTACLE_DEPLACABLE, &PIEGE, TabObstCassable,
                              TabObstaclesDep, TabObstPiege, PosJoueur, Oiseaux, &NombreOiseauxTrouve,
                              "Niveau1", Obstacle, &niveau, &vie, &score, &timer);

            // Si le jeu commande le retour au menu
            if (jeu(OBSTACLE, OBSTACLE_CASSABLE, OBSTACLE_DEPLACABLE, PIEGE, 1, TabObstCassable, TabObstaclesDep,
                    TabObstPiege, PosJoueur, Oiseaux, Obstacle,
                    NombreOiseauxTrouve, vie, score, timer) == 2) {
                main(); // Retour au menu
            }
            // Charger le premier niveau
        }

            // Si le mot des passe saisi correspond à celui du deuxième niveau
        else if (validation == 2) {
            system("cls"); // Nettoyage de la console
            printf("Chargement du deuxieme niveau...\n");
            sleep(2); // Délai de 2 secondes
            system("cls"); // Nettoyage de la console
            chargementMatrice(&OBSTACLE, &OBSTACLE_CASSABLE, &OBSTACLE_DEPLACABLE, &PIEGE, TabObstCassable,
                              TabObstaclesDep, TabObstPiege, PosJoueur, Oiseaux, &NombreOiseauxTrouve,
                              "Niveau2", Obstacle, &niveau, &vie, &score, &timer);

            // Si le jeu commande le retour au menu
            if (jeu(OBSTACLE, OBSTACLE_CASSABLE, OBSTACLE_DEPLACABLE, PIEGE, 2, TabObstCassable, TabObstaclesDep,
                    TabObstPiege, PosJoueur, Oiseaux, Obstacle,
                    NombreOiseauxTrouve, vie, score, timer) == 2) {
                main(); // Retour au menu
            }
            // Charger le deuxième niveau
        }

            // Si le mot des passe saisi correspond à celui du troisième niveau
        else if (validation == 3) {
            system("cls"); // Nettoyage de la console
            printf("Chargement du troisieme niveau...\n");
            sleep(2); // Délai de 2 secondes
            system("cls"); // Nettoyage de la console
            chargementMatrice(&OBSTACLE, &OBSTACLE_CASSABLE, &OBSTACLE_DEPLACABLE, &PIEGE, TabObstCassable,
                              TabObstaclesDep, TabObstPiege, PosJoueur, Oiseaux, &NombreOiseauxTrouve,
                              "Niveau3", Obstacle, &niveau, &vie, &score, &timer);


            // Si le jeu commande le retour au menu
            if (jeu(OBSTACLE, OBSTACLE_CASSABLE, OBSTACLE_DEPLACABLE, PIEGE, 3, TabObstCassable, TabObstaclesDep,
                    TabObstPiege, PosJoueur, Oiseaux, Obstacle,
                    NombreOiseauxTrouve, vie, score, timer) == 2) {
                main(); // Retour au menu
            }
            // Charger le troisieme niveau
        }

            // Si le mot des passe saisi correspond à celui du quatrième niveau
        else if (validation == 4) {
            system("cls"); // Nettoyage de la console
            printf("Chargement du quatrieme niveau...\n");
            sleep(2); // Délai de 2 secondes
            system("cls"); // Nettoyage de la console
            chargementMatrice(&OBSTACLE, &OBSTACLE_CASSABLE, &OBSTACLE_DEPLACABLE, &PIEGE, TabObstCassable,
                              TabObstaclesDep, TabObstPiege, PosJoueur, Oiseaux, &NombreOiseauxTrouve,
                              "Niveau4", Obstacle, &niveau, &vie, &score, &timer);

            // Si le jeu commande le retour au menu
            if (jeu(OBSTACLE, OBSTACLE_CASSABLE, OBSTACLE_DEPLACABLE, PIEGE, 4, TabObstCassable, TabObstaclesDep,
                    TabObstPiege, PosJoueur, Oiseaux, Obstacle,
                    NombreOiseauxTrouve, vie, score, timer) == 2) {
                main(); // Retour au menu
            }
            // Charger le quatrieme niveau
        }

            // Si le mot de passe saisi ne correspond à aucun mot de passe de la base de données
        else {
            system("cls"); // Nettoyage de la console
            printf("Le mot de passe que vous avez saisi n'est pas dans la base de donnees...\n");
            sleep(2); // Délai de 2 secondes
            system("cls"); // Nettoyage de la console
            main(); // Retour au menu
        }
    }

        // Si l'option 4 du menu est choisie : afficher les règles du jeu
    else if (valmenu == 4) {
        system("cls"); // Nettoyage de la console

        // Affichage des règles du jeu
        system("cls");
        printf("Voici les regles du jeu :                                                                 Appuyer sur x pour quitter\n\n"
               "Votre but est de sauver les 4 oiseaux qui sont representes par des 'O' repartis aux 4 coins de la matrice de 10x20.\n"
               "Cette matrice comprend des blocs qui ont pour objectif de ralentir la progression de Snoopy : \n\n"
               "Les blocs cassables : %c \n- Lorsque Snoopy se trouve sur une case adjacente a l'un de ces blocs, il peut les casser en appuyant sur 'c'.\n\n"
               "Les blocs deplacable : %c \n- Lorsque Snoopy se trouve sur une case adjacente a l'un de ces blocs, il peut les deplacer en appuyant sur la touche directionnelle (zqsd) qui va dans la direction du bloc.\n\n"
               "Les blocs pieges : %c \n- Lorsque Snoopy se trouve sur un bloc piege, il perd une vie et recommence le niveau.\n\n"
               "Les blocs de teleportation : %c \n- Il n'y a rien ici pour l'instant...\n\n"
               "Les blocs tapis-roulant : %c \n- Il n'y a rien ici pour l'instant...\n\n"
               "Les blocs invincibles : * \n- Ils sont en bordures de la matrice et Snoopy ne peut pas les traverser.\n\n"
               "Les obstacles : %c \n- Ils sont innofensifs pour Snoopy, mais il ne peut pas les traverser.\n\n"
               "Vous disposez de 120 secondes pour terminer le niveau en cours. Une fois ce temps depasse, vous perdez une vie et recommencez le niveau.\n"
               "Snoopy dispose de 3 vies pour chaque niveau.\n"
               "Il est possible de sauvegarder sa progression a tout moment en appuyant sur 'x'.\n"
               "L'utilisation de mot de passe est egalement possible pour acceder aux niveaux superieur en n'ayant pas a rejouer les premiers niveaux, vous obtenez ces mots de passes en finissant les niveaux.\n"
               "Qui sait, peut-etre qu'il y a meme un niveau cache...\n"
               "Amusez vous bien !.\n", 184, 244, 178, 'F', 'G', 223);
        while (1) {
            if (kbhit()) {
                sortirRegles = getch();
                if (sortirRegles == 'x') {
                    break;
                }
            }
        }
        system("cls");
        main(); //Retour

    }

        // Si l'option 5 du menu est choisie : afficher les scores
    else if (valmenu == 5) {
        system("cls"); // Nettoyage de la console

        // Affichage des valeurs des scores
        printf("Voici les scores : \n[Fichier de sauvegarde] : \n[Fichier de sauvegarde] : \n[Fihcier de sauvegarde] : \n[Fichier de sauvegarde] : \n");

        // Pensez à mettre une boucle for pour avoir le nombre de fichiers de sauvegarde et à ne pas afficher des valeurs vides...

        sleep(5); // Délai de 5 secondes
        system("cls"); // Nettoyage de la console

        // Afficher les scores ici

        main(); // Retour au menu
    }

        // Si l'option 6 du menu est choisie : quitter
    else if (valmenu == 6) {
        return 0; // Fin de jeu
    }
}

