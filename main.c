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

    Sleep(4000); // Attendre 4 secondes

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
    printf("\t\t\t\t\t\t\tEntrez le nombre de mots a saisir dans la partie : ");
    scanf("%d", &nbMots);

    char joueur1[50], joueur2[50];
    printf("\t\t\t\t\t\t\tEntrez le pseudo du joueur 1 : ");
    scanf("%s", joueur1);
    printf("\t\t\t\t\t\t\tEntrez le pseudo du joueur 2 : ");
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
            printf("Ce n'est pas le bon mot. Reessayez : ");
            scanf("%s", motPropose);
        }
    }
    fin = time(NULL);
    tempsJoueur1 = difftime(fin, debut);

    debut = time(NULL);
    for (int i = 0; i < nbMots; i++) {
        char motPropose[50];
        printf("Joueur 2, saisissez le mot suivant : %s\n", mots[i]);
        scanf("%s", motPropose);
        while (strcmp(motPropose, mots[i]) != 0) {
            printf("Ce n'est pas le bon mot. Reessayez : ");
            scanf("%s", motPropose);
        }
    }
    fin = time(NULL);
    tempsJoueur2 = difftime(fin, debut);

    printf("Temps de saisie pour %s : %.0lf secondes\n", joueur1, tempsJoueur1);
    printf("Temps de saisie pour %s : %.0lf secondes\n", joueur2, tempsJoueur2);

    if (tempsJoueur1 < tempsJoueur2) {
        printf("%s est plus rapide au clavier !\n", joueur1);
    } else if (tempsJoueur1 > tempsJoueur2) {
        printf("%s est plus rapide au clavier !\n", joueur2);
    } else {
        printf("Les deux joueurs ont le meme temps de saisie.\n");
    }

}

void configurer()
{
    system("cls");  // Efface l'écran (fonctionne sur Windows)

    char mots_nouveaux[100][50];
    int nb_mots_nouveaux = 0;

    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t===== CONFIGURATION =====\n");
    printf("\t\t\t\t\t\t\tVoulez-vous ajouter de nouveaux mots ? (o/n) : ");

    char reponse;
    scanf(" %c", &reponse);

    if (reponse == 'o' || reponse == 'O')
    {
        printf("\t\t\t\t\t\t\tEntrez les mots a ajouter (tapez 'stop' pour terminer) :\n");

        while (1)
        {
            printf("\t\t\t\t\t\t\tMot %d : ", nb_mots_nouveaux + 1);
            scanf("%s", mots_nouveaux[nb_mots_nouveaux]);

            if (strcmp(mots_nouveaux[nb_mots_nouveaux], "stop") == 0)
                break;

            nb_mots_nouveaux++;
        }

        // Ouvrir le fichier en mode écriture (ajout)
        FILE *fichier = fopen("mots.txt", "a");

        if (fichier == NULL)
        {
            printf("\t\t\t\t\t\t\tErreur d'ouverture du fichier.\n");
            return;  // Sortie de la fonction si le fichier n'est pas ouvert correctement
        }

        // Écrire les nouveaux mots dans le fichier
        for (int i = 0; i < nb_mots_nouveaux; i++)
        {
            fprintf(fichier, "%s\n", mots_nouveaux[i]);
        }

        fclose(fichier);

        printf("\t\t\t\t\t\t\tVoici les mots ajoutes :\n");
        for (int i = 0; i < nb_mots_nouveaux; i++)
        {
            printf("\t\t\t\t\t\t\t- %s\n", mots_nouveaux[i]);
        }

        printf("\t\t\t\t\t\t\tLes nouveaux mots ont ete ajoutes avec succes !\n");
    }
    else
    {
        printf("\t\t\t\t\t\t\tRetour a l'ecran d'accueil.\n");
    }

    sleep(3);  // Attendre 3 secondes (fonctionne sur Unix-like systems)
    main();
}



void aide()
{
    int choix_aide;
    system("cls");
    printf("\n");
    printf("\t======== DESCRIPTION DE L'APPLICATION ========\n\n");
    printf("\tLe jeu vise a mesurer et ameliorer la vitesse de saisie au clavier des joueurs. \n\tLes joueurs s'affrontent en saisissant rapidement des mots affiches aleatoirement a l'ecran.\n\tLe joueur qui saisit correctement et le plus rapidement remporte la partie.\n\n");

    printf("\t========       VERSION DU JEU         ========\n\n");
    printf("\t Version 2.2 \n");

    printf("\t========       CONCEPTEURS            ========\n\n");
    printf("\tMAYAMBA MUNONGO Christian\n\n\tMUSONDA MBUYA Medalie\n\n\tMUTOMBO BASAKWA Vacus\n\n\tMUSAKAYI KABONGO Elie\n\n");

    printf("\t========       DATE DE CONCEPTION     ========\n");
    printf("\tLa date de la conception du jeu a debute le 05/06/2024\n");
    printf("\tPour prendre fin le 15/06/2024\n");

}


void quitter()
{
    exit(0);
}

void choix_utilisateur(int choix)
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


}
