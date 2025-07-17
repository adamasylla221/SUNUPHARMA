#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "pharmacie.h"

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
