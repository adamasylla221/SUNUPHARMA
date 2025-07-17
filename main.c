#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <stdio.h>
#include <windows.h>
#include "pharmacie.h"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define CYAN    "\033[1;36m"
#define MAGENTA "\033[1;35m"
#define RESET   "\033[0m"
//infoProduit();
//ajouterProduit();
//modifierProduit();
//supprimerProduit();
// verification_stock();
int main() {
    SetConsoleOutputCP(CP_UTF8);
    int choix;

    do {
        printf("CYAN\n═══════════════════════════════════════════\n");
        printf("      📦 MENU DE GESTION DES PRODUITS      \n");
        printf("═══════════════════════════════════════════\n" RESET);
        printf(YELLOW "1. Ajouter un produit\n" RESET);
        printf(YELLOW "2. Modifier un produit\n" RESET);
        printf(YELLOW "3. Supprimer un produit\n" RESET);
        printf(YELLOW "4. Vérifier le stock\n" RESET);
        printf(YELLOW "5. afficher les produits\n" RESET);
        printf(YELLOW "0. Quitter\n" RESET);
        printf("Choix ➤ ");
        scanf("%d", &choix);

        switch(choix) {
            case 1:
                ajouterProduit();
                break;
            case 2:
                modifierProduit();
                break;
            case 3:
                supprimerProduit();
                break;

            case 4:
                verification_stock();
                break;

            case 5:
                afficherProduits();
                break;
            case 0:
                printf(GREEN "\n[✓] Merci d'avoir utilisé notre application.\n" RESET);
                 exit(0);
                break;

            default:
                printf(RED "\n[✗] Choix invalide. Réessayez.\n" RESET);
        }

    } while (choix != 0);


    return 0;
}


=======

int main()
{
    printf("Hello world!\n");
    return 0;
}
>>>>>>> f56135b11b1caa95f49a5faafca0ce56c2312c3c
