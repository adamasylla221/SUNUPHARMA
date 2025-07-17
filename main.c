#include <stdio.h>
#include "pharmacie.h"

int main() {
    int choix;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Afficher les categories\n");
        printf("2. Ajouter une categorie\n");
        printf("3. Supprimer une categorie\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                infoCategorie();
                break;
            case 2:
                ajouterCategorie();
                break;
            case 3:
                supprimerCategorie();
                break;
            case 0:
                printf("Fin du programme.\n");
                break;
            default:
                printf("Choix invalide.\n");
        }

    } while (choix != 0);

    return 0;
}
