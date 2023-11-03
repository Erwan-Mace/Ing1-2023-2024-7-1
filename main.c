#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#define ligne 10
#define colonne 20

void InitialisationMatrice(char Tableau[ligne][colonne]) {
    char NvTableau[ligne][colonne] = {
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
    for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < colonne; j++) {
            Tableau[i][j] = NvTableau[i][j];
        }
    }
}

void Affichage(char Tab[ligne][colonne], int PosJoueur[2]) {
    for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < colonne; j++) {
            if (PosJoueur[0] == i && PosJoueur[1] == j) {
                printf("P");
            } else {
                printf("%c", Tab[i][j]);
            }
            printf("|");
        }
        printf("\n");
    }
    printf("\n");
}

void DeplacementJoueur(int PosJoueur[2], char touche) {
    if (touche == 'q') {
        if (PosJoueur[1] == 1) {
            printf("Snoopy s'est cogne la tete contre le mur ! Faites plus attention...\n");
        } else {
            PosJoueur[1] = PosJoueur[1] - 1;
        }
    } else if (touche == 'd') {
        if (PosJoueur[1] == 18) {
            printf("Snoopy s'est cogne la tete contre le mur ! Faites plus attention...\n");
        } else {
            PosJoueur[1] = PosJoueur[1] + 1;
        }
    } else if (touche == 'z') {
        if (PosJoueur[0] == 1) {
            printf("Snoopy s'est cogne la tete contre le mur ! Faites plus attention...\n");
        } else {
            PosJoueur[0] = PosJoueur[0] - 1;
        }
    } else if (touche == 'x') {
        if (PosJoueur[0] == 8) {
            printf("Snoopy s'est cogne la tete contre le mur ! Faites plus attention...\n");
        } else {
            PosJoueur[0] = PosJoueur[0] + 1;
        }
    }
}

void AfficheTimer(int timer) {
    printf("Temps restant : %d secondes\n", timer);
}

int main() {
    char Tableau[ligne][colonne];
    int PositionJoueur[2] = {4, 9};
    char pos;
    int NombreOiseaux = 4;
    int f = 0;

    clock_t start = clock();
    int timer = 120; // 120 secondes pour le timer

    InitialisationMatrice(Tableau);
    Affichage(Tableau, PositionJoueur);
    AfficheTimer(timer);

    while (f != NombreOiseaux && timer > 0) {
        if (kbhit()) {
            pos = getch();
            system("cls");
            DeplacementJoueur(PositionJoueur, pos);
            Affichage(Tableau, PositionJoueur);

            // Mise à jour et affichage du timer
            clock_t end = clock();
            double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
            if (elapsed >= 1.0) {
                timer -= (int)elapsed;
                start = clock(); // Réinitialisation du début pour le prochain tick
            }
            AfficheTimer(timer);

            if (Tableau[PositionJoueur[0]][PositionJoueur[1]] == 'O') {
                f++;
                Tableau[PositionJoueur[0]][PositionJoueur[1]] = ' ';
                printf("\nVous avez attrape un oiseau! Il vous en reste %d a attraper.\n", NombreOiseaux - f);
            }
        }

        // si le timer écoulé
        if (timer <= 0) {
            printf("\nLe temps est écoulé ! Vous avez perdu.\n");
            break;
        }
    }

    if (f == NombreOiseaux) {
        printf("Bravo! Vous avez attrape tous les oiseaux!\n");
    }

    return 0;
}
