#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

// Affichage de l'écran d'acceuil
void ecran_accueil()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t***************************************\n");
    printf("\t\t\t\t\t\t\t*****    UDBL - DACTYLOGICIEL     *****\n");
    printf("\t\t\t\t\t\t\t*  Par:  MAYAMBA MUNONGO Christian*****\n");
    printf("\t\t\t\t\t\t\t*        MUSONDA MBUYA Medalie    *****\n");
    printf("\t\t\t\t\t\t\t*        MUTOMBO BASAKWA Vacus    *****\n");
    printf("\t\t\t\t\t\t\t*        MUSAKAYI KABONGO Elie    *****\n");
    printf("\t\t\t\t\t\t\t***************************************\n");

    sleep(4); // Attendre 4 secondes

    //Pour effacer l'écran
    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t1. Demarrer\n");
    printf("\t\t\t\t\t\t\t\t2. Configurer\n");
    printf("\t\t\t\t\t\t\t\t3. Aide\n");
    printf("\t\t\t\t\t\t\t\t4. Quitter\n");
}

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

void demarrer()
{
    system("cls");

    int nbMots;
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\tEntrez le nombre de mots à saisir dans la partie : ");
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

}

void configurer()
{
    system("cls");
}

void aide()
{
    int choix_aide;
    system("cls");
    printf("\n");
    printf("\t======== DESCRIPTION DE L'APPLICATION ========\n");
    printf("\tCe projet consiste à proposer un logiciel d'aide à l'amelioration de la saisie rapide au clavier communément appelé 'Dactylogiciel'. \n");

    printf("\t======== VERSION DU JEU ========\n");
    printf("\t \n");

    printf("\t======== CONCEPTEURS ========\n");
    printf("\tMAYAMBA MUNONGO Christian\n\tMUSONDA MBUYA Medalie\n\tMUTOMBO BASAKWA Vacus\n\tMUSAKAYI KABONGO Elie\n");

    printf("\t======== DATE DE CONCEPTION ========\n");

    printf("\tTapez 1 pour retourner a l'ecran d'acceuil\n ==> ");
    scanf("%d", &choix_aide);

    switch (choix_aide)
    {
    case 1:
        ecran_accueil();
        break;
    default:
        printf("Choix invalide.\n");
    }
}

void quitter()
{
    system("exit");
}

int choix_utilisateur(int choix)
{

    switch (choix)
    {
    case 1:
        demarrer();
        break;
    case 2:
        configurer();
        break;
    case 3:
        aide();
        break;
    case 4:
        quitter();
        break;
    default:
        printf("Choix invalide.\n");
        break;
    }
}
int main()
{

    int choix;
    ecran_accueil();

    printf("Entrez votre choix: \n ==> ");
    scanf("%d", &choix);
    choix_utilisateur(choix);

    if (choix == 4){
        system("exit");
    }
    return 0;

}
