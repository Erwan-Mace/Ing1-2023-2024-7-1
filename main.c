#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <time.h>
#include<unistd.h>
#include <string.h>
//#include <pthread.h>
#include "programmes.h"

#define LIGNE 10 
#define COLONNE 20
#define OBSTACLE 8
#define PIEGE 6
#define OBSTACLE_DEPLACABLE 6
#define OBSTACLE_CASSABLE 4

int main() {
    // Définition des mots de passe
    char MDP1[] = "Andy"; // Mot de passe pour le niveau 1
    char MDP2[] = "Molly"; // Mot de passe pour le niveau 2
    char MDP3[] = "Spike"; // Mot de passe pour le niveau 3
    char MDP4[] = "Olaf"; // Mot de passe pour le niveau 4
    // Initialisation d'un tableau de caractères en utilisant les longueurs des mots de passe
    char tabMDP[4] = {MDP1[strlen(MDP1)], MDP2[strlen(MDP2)], MDP3[strlen(MDP3)], MDP4[strlen(MDP4)]};
    int valmenu = menu(); // variable indiquant le numéro de la fonction choisie et appelée par le menu

    // Si l'option 1 du menu est choisie : démarrer une partie
    if (valmenu == 1) {
        system("cls"); // Nettoyage de la console
        printf("Chargement du premier niveau...\n");
        sleep(3); // Délai de 3 secondes
        system("cls"); // Nettoyage de la console
        if (jeu(1) == 2) { // Si le jeu s'arrête
            main(); // Retour au menu
        }
    }
    // Si l'option 2 du menu est choisie : continuer une partie
    else if (valmenu == 2) {
        system("cls"); // Nettoyage de la console
        char valsauvegarde[50];
        // Saisie de la sauvegarde
        printf("Quelle sauvegarde voulez-vous utiliser ?\n");
        scanf("%s", valsauvegarde);
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
            if (jeu(1) == 2) {
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
            if (jeu(2) == 2) {
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
            if (jeu(3) == 2) {
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
            if (jeu(4) == 2) {
                main(); // Retour au menu
            }
            //Charger le quatrieme niveau.
        }
        // Si le mot d epasse saisi ne correspond à aucun mot de passe de la base de données
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
        printf("Dans l'arene, quatre oiseaux, representes par le symbole 'O', sont places aux quatre coins. Le joueur, incarne par le caractere 'P', doit les collecter tous.\n");
        printf("Cependant, des precautions doivent etre prises pour eviter les blocs tueurs symbolises par %c. Ces derniers sont mortels au contact.\n",
               177);
        printf("L'arene comprend egalement des blocs immobiles, egalement representes par %c, qui servent d obstacles.\n",
               223);
        printf("Une balle, designee par %c, rebondit à l interieur de l arene et peut eliminer le joueur si elle n est pas esquivee avec succes.\n",
               0x02);
        printf("Enfin, des blocs poussables, marques par %c, peuvent etre deplaces par le joueur. Ces blocs sont inoffensifs et ne causent aucun degat lorsqu ils sont pousses.\n",
               64);
        printf("Le but du jeu est de recuperer tous les oiseaux sans subir de degats des blocs tueurs ou de la balle rebondissante, tout en se servant judicieusement des blocs poussables pour faciliter la tache.\n");
        printf("tout ceci dans les 120 secondes impartie.\n");
        sleep(20); // Délai de 20 secondes
        system("cls"); // Nettoyage de la console
        main(); // Retour au menu
    }
    // Si l'option 5 du menu est choisie : afficher les scores
    else if (valmenu == 5) {
        system("cls"); // Nettoyage de la console
        // Affichage des valuer des scores
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
