#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pharmacie.h"

void infoCategorie() {
    FILE *f = fopen("CATEGORIES.dat", "rb");
    if (!f) {
        printf("Erreur ouverture fichier.\n");
        return;
    }

    Categorie cat;
    printf("Liste des categories :\n");

    while (fread(&cat, sizeof(Categorie), 1, f)) {
        printf("ID: %d | Libelle: %s\n", cat.id, cat.libelle);
    }

    fclose(f);
}

void ajouterCategorie() {
    char libelle[50];
    printf("Entrez le libelle : ");
    scanf(" %[^\n]", libelle); // lit une chaine avec espaces

    FILE *f = fopen("CATEGORIES.dat", "ab+");
    if (!f) {
        printf("Erreur ouverture fichier.\n");
        return;
    }

    int id = 1;
    fseek(f, 0, SEEK_END);
    long taille = ftell(f);

    if (taille >= sizeof(Categorie)) {
        fseek(f, -sizeof(Categorie), SEEK_END);
        Categorie dernier;
        if (fread(&dernier, sizeof(Categorie), 1, f) == 1) {
            id = dernier.id + 1;
        }
    }

    Categorie nouveau;
    nouveau.id = id;
    strncpy(nouveau.libelle, libelle, sizeof(nouveau.libelle) - 1);
    nouveau.libelle[sizeof(nouveau.libelle) - 1] = '\0';

    fwrite(&nouveau, sizeof(Categorie), 1, f);
    fclose(f);
    printf("Categorie ajoutee avec succes.\n");
}

void supprimerCategorie() {
    int idSupprimer;
    printf("Entrez ID a supprimer : ");
    scanf("%d", &idSupprimer);

    FILE *f = fopen("CATEGORIES.dat", "rb");
    FILE *temp = fopen("TEMP.dat", "wb");

    if (!f || !temp) {
        printf("Erreur ouverture fichier.\n");
        return;
    }

    Categorie cat;
    int trouve = 0;

    while (fread(&cat, sizeof(Categorie), 1, f)) {
        if (cat.id != idSupprimer) {
            fwrite(&cat, sizeof(Categorie), 1, temp);
        } else {
            trouve = 1;
        }
    }

    fclose(f);
    fclose(temp);
    remove("CATEGORIES.dat");
    rename("TEMP.dat", "CATEGORIES.dat");

    if (trouve)
        printf("Categorie supprimee.\n");
    else
        printf("ID non trouve.\n");
}
