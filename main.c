#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <string.h>
#include "pharmacie.h"
int main() {
    int choix;
    Utilisateur u;

    do {
        printf("\n=== BIENVENUE � SUNUPHARMA ===\n");
        printf("1. S'inscrire (Cr�er un compte utilisateur)\n");
        printf("2. Se connecter\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        viderBuffer();

        switch (choix) {
            case 1:
                creerUtilisateur();
                break;
            case 2:
                if (connexionUtilisateur(&u)) {
                    if (u.role == admin) {
                        menuAdmin(u);
                    } else {
                        menuPharmacien(u);
                    }
                } else {
                    printf("[ERREUR] �chec de la connexion.\n");
                }
                break;
            case 0:
                printf("Merci d'avoir utilis� SUNUPHARMA. � bient�t !\n");
                break;
            default:
                printf("Choix invalide, veuillez r�essayer.\n");
=======
<<<<<<< HEAD

int main()
{
    printf("Hello world!\n");
    return 0;
}
=======
<<<<<<< HEAD
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "pharmacie.h"
=======
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
>>>>>>> f4499a739c63b652d77124ccfcbc509a52472b2e
        }

    } while (choix != 0);

<<<<<<< HEAD
    return 0;
}
=======

    return 0;
}


=======
>>>>>>> 9ed36685a89b46fa6444100bafdb869af933b4b9

#define MAX_PRODUITS 100
#define MAX_VENTES 100

// Prototypes
void infoVente(Vente *vente, Produit produits[], int nbProduitsDispo, const char *loginPharmacien);
void generfacture(Vente V);
void consultstock(Produit produits[], int nbProduits);

int main() {
    // Création du dossier BILLS si non existant
    struct stat st = {0};
    if (stat("./BILLS", &st) == -1) {
        mkdir("./BILLS");
    }

    // Produits disponibles
    Produit produits[MAX_PRODUITS] = {
        {"P001", "Paracetamol", 100, 500.0, "Antidouleur", "01/2024"},
        {"P002", "Amoxicilline", 50, 1500.0, "Antibiotique", "12/2025"},
        {"P003", "Vitamine C", 200, 300.0, "Complément", "06/2026"}
    };
    int nbProduits = 3;

    // Stockage des ventes
    Vente ventes[MAX_VENTES];
    int nbVentes = 0;

    const char *loginPharmacien = "MAME ALE SYLLA";

    int choix;
    do {
        printf("\n\033[1;36m========= MENU PRINCIPAL =========\033[0m\n");
        printf("1. Nouvelle vente\n");
        printf("2. Consulter le stock\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        getchar(); // pour consommer le \n

        switch (choix) {
            case 1:
                infoVente(&ventes[nbVentes], produits, nbProduits, loginPharmacien);
                generfacture(ventes[nbVentes]);
                nbVentes++;
                break;
            case 2:
                consultstock(produits, nbProduits);
                break;
            case 0:
                printf("\n\033[1;34mMerci d'avoir utilisé SUNUPHARMA !\033[0m\n");
                break;
            default:
                printf("\033[1;31m[ERREUR] Choix invalide.\033[0m\n");
        }
    } while (choix != 0);

    printf("\n\033[1;32m[✓] Nombre total de ventes enregistrées : %d\033[0m\n", nbVentes);
    return 0;
}
>>>>>>> f56135b11b1caa95f49a5faafca0ce56c2312c3c
>>>>>>> 8085a31d8f808adaf71d70fcb524ef10c8a6895b
>>>>>>> f4499a739c63b652d77124ccfcbc509a52472b2e
