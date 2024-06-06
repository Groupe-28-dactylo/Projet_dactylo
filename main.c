#include <stdio.h>
#include <stdlib.h>


// Affichage de l'écran d'acceuil
void ecran_accueil()
{
    printf("\t1. Demarrer\n");
    printf("\t2. Configurer\n");
    printf("\t3. Aide\n");
    printf("\t4. Quitter\n");
}

void demarrer()
{
    int nbredes_mots_à_saisir;
    char nom_utilisateur[20];

}

void configurer()
{

}

void aide()
{

}

void quitter()
{

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
    return 0;
}
