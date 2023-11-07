int main() {
    int f = 0;
    int Obstacle[2][obstacle];
    char Tableau[ligne][colonne];
    char pos;
    char oiseaux = 'O';
    int nb_vies = 3;
    int NombreOiseaux = 4;
    int PositionJoueur[2] = {4, 9};
    clock_t start = clock();
    int timer = 120;// 120 secondes pour le timer
    int score=0;

    InitialisationMatrice(Tableau);
    InitialisationObstacle(Obstacle);
    Affichage(Tableau, PositionJoueur, Obstacle);
    AfficheTimer(timer);

    while (f != NombreOiseaux && timer > 0) {
        // Mise à jour et affichage du timer
        clock_t end = clock();
        double elapsed = (double) (end - start) / CLOCKS_PER_SEC;

        if (elapsed >= 1.0) {
            timer -= (int) elapsed;
            start = clock(); // Réinitialisation du début pour le prochain tick
        }
        if (kbhit()) {
            pos = getch();
            system("cls");
            DeplacementJoueur(PositionJoueur, pos, Obstacle);
            Affichage(Tableau, PositionJoueur, Obstacle);

            AfficheTimer(timer);

            if (Tableau[PositionJoueur[0]][PositionJoueur[1]] == 'O') {
                f++;
                Tableau[PositionJoueur[0]][PositionJoueur[1]] = ' ';
                printf("\nVous avez attrape un oiseau! Il vous en reste %d a attraper.\n", NombreOiseaux - f);
            }
        }
        gotoligcol(11, 0);
        AfficheTimer(timer);

        // si le timer écoulé
        if (timer == 0) {
            Vie(nb_vies);
            if (Vie(nb_vies) > 0) {
                printf("\nLe temps est ecoule ! Vous avez perdu.\n Il ne vous reste plus que %d vies.", Vie(nb_vies));
                sleep(2);
            } else {
                printf("\nVous n'avez plus de vie !\n Attendez avant de retenter votre chance.");
                sleep(2);
            }
            break;
        }
        score=timer*100;
    }
    if (f == NombreOiseaux && timer>0){
        printf("Bravo! Vous avez attrape tous les oiseaux! Votre score est de %d",score);
        sleep(3);
    }
    else  {
        printf("Time's up, Vous avez perdu...\n");
        sleep(3);
    }
    return 0;
}
