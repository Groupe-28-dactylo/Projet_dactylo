#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Fonction pour mélanger les mots de façon aléatoire
void melangerMots(char *mots[], int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char *temp = mots[i];
        mots[i] = mots[j];
        mots[j] = temp;
    }
}

int main() {
    int nbMots;
    printf("Entrez le nombre de mots à saisir dans la partie : ");
    scanf("%d", &nbMots);

    char joueur1[50], joueur2[50];
    printf("Entrez le pseudo du joueur 1 : ");
    scanf("%s", joueur1);
    printf("Entrez le pseudo du joueur 2 : ");
    scanf("%s", joueur2);

    char *mots[] = {"ordinateur", "clavier", "programmation", "dactylographie", "rapidité", "joueur", "saisie", "affichage"};
    melangerMots(mots, 8);

    printf("C'est parti !\n");

    time_t debut, fin;

    double tempsJoueur1, tempsJoueur2;

    debut = time(NULL);
    for (int i = 0; i < nbMots; i++) {
        char motPropose[50];
        printf("Joueur 1, saisissez le mot suivant : %s\n", mots[i]);
        scanf("%s", motPropose);
        while (strcmp(motPropose, mots[i]) != 0) {
            printf("Ce n'est pas le bon mot. Réessayez : ");
            scanf("%s", motPropose);
        }
    }
    fin = time(NULL);
    tempsJoueur1 = difftime(fin,debut);

    debut = time(NULL);
    for (int i = 0; i < nbMots; i++) {
        char motPropose[50];
        printf("Joueur 2, saisissez le mot suivant : %s\n", mots[i]);
        scanf("%s", motPropose);
        while (strcmp(motPropose, mots[i]) != 0) {
            printf("Ce n'est pas le bon mo+t. Réessayez : ");
            scanf("%s", motPropose);
        }
    }
    fin = time(NULL);
    tempsJoueur2 = difftime(fin,debut);

    printf("Temps de saisie pour %s : %.lf secondes\n", joueur1, tempsJoueur1);
    printf("Temps de saisie pour %s : %.lf secondes\n", joueur2, tempsJoueur2);

    if (tempsJoueur1 < tempsJoueur2) {
        printf("%s est plus rapide au clavier !\n", joueur1);
    } else if (tempsJoueur1 > tempsJoueur2) {
        printf("%s est plus rapide au clavier !\n", joueur2);
    } else {
        printf("Les deux joueurs ont le même temps de saisie.\n");
    }

    return 0;
}
