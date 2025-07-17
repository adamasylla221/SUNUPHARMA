<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define CYAN    "\033[1;36m"
#define MAGENTA "\033[1;35m"
#define RESET   "\033[0m"
typedef struct {
    char code[10];
    char designation[50];
    char categorie_Produit[30];
    char date_peremption[11]; // format : MM/YYYY
    int quantite;
    float prix;
} Produit;

void initialiserFichier() {
    FILE *f = fopen("product.dat", "ab");
    if (f == NULL) {
        printf("Erreur lors de la création de product.dat\n");
        exit(1);
    }
    fclose(f);
}


void ajouterProduit() {
    Produit p;
    FILE *f = fopen("product.dat", "ab");
    if (!f) {
        printf("Erreur ouverture fichier.\n");
        return;
    }

    fflush(stdin);
    printf(MAGENTA"\n--- Ajout d'un produit ---\n"RESET);
    printf("Code : ");
    scanf("%s", p.code);
    fflush(stdin);

    printf("Désignation : ");
    fgets(p.designation, sizeof(p.designation), stdin);
    p.designation[strcspn(p.designation, "\n")] = 0;

    printf("Catégorie : ");
    fgets(p.categorie_Produit, sizeof(p.categorie_Produit), stdin);
    p.categorie_Produit[strcspn(p.categorie_Produit, "\n")] = 0;

    printf("Date de péremption (MM/YYYY) : ");
    scanf("%s", p.date_peremption);

    printf("Quantité : ");
    scanf("%d", &p.quantite);

    printf("Prix unitaire : ");
    scanf("%f", &p.prix);

    fwrite(&p, sizeof(Produit), 1, f);
    fclose(f);

    printf(GREEN "✅Produit ajouté avec succès.\n"RESET);
}

void afficherProduits() {
    Produit p;
    FILE *f = fopen("product.dat", "rb");
    if (!f) {
        printf("Erreur ouverture fichier.\n");
        return;
    }

    printf(MAGENTA"\n=== LISTE DES PRODUITS ===\n"RESET);
    while (fread(&p, sizeof(Produit), 1, f)) {
        printf("Code : %s\n", p.code);
        printf("Désignation : %s\n", p.designation);
        printf("Catégorie : %s\n", p.categorie_Produit);
        printf("Date de péremption : %s\n", p.date_peremption);
        printf("Quantité : %d\n", p.quantite);
        printf("Prix : %.2f XOF\n", p.prix);
        printf("-------------------------------\n");
    }

    fclose(f);
}

void modifierProduit() {
    char code[10];
    int trouve = 0;
    Produit p;

    printf(MAGENTA"\n--- Modifier un produit ---\n"RESET);
    printf("Code du produit à modifier : ");
    scanf("%s", code);

    FILE *f = fopen("product.dat", "rb+");
    if (!f) {
        printf("Erreur ouverture fichier.\n");
        return;
    }

    while (fread(&p, sizeof(Produit), 1, f)) {
        if (strcmp(p.code, code) == 0) {
            printf("➤ Nouveau prix : ");
            scanf("%f", &p.prix);
            printf("➤ Nouvelle quantité : ");
            scanf("%d", &p.quantite);
            printf("➤ Nouvelle date de péremption : ");
            scanf("%s", p.date_peremption);
            printf("➤ Nouvelle categorie: ");
            scanf("%s", p.categorie_Produit);
             printf("➤ Nouveau code: ");
            scanf("%s", p.code);
            printf("➤ Nouvelle designation: ");
            scanf("%s", p.designation);
            fseek(f, -sizeof(Produit), SEEK_CUR);
            fwrite(&p, sizeof(Produit), 1, f);
            trouve = 1;
            break;
        }
    }

    fclose(f);

    if (trouve)
        printf(GREEN "✅ Produit modifié avec succès.\n" RESET);
    else
        printf(RED "❌ Produit non trouvé.\n" RESET);
}

void supprimerProduit() {
    char code[10];
    Produit p;
    int trouve = 0;

    printf(MAGENTA "\n--- Supprimer un produit ---\n"RESET);
    printf("Code du produit à supprimer : ");
    scanf("%s", code);

    FILE *f = fopen("product.dat", "rb");
    FILE *tmp = fopen("temp.dat", "wb");

    if (!f || !tmp) {
        printf("Erreur fichiers.\n");
        return;
    }

    while (fread(&p, sizeof(Produit), 1, f)) {
        if (strcmp(p.code, code) != 0) {
            fwrite(&p, sizeof(Produit), 1, tmp);
        } else {
            trouve = 1;
        }
    }

    fclose(f);
    fclose(tmp);

    remove("product.dat");
    rename("temp.dat", "product.dat");

    if (trouve)
        printf( GREEN"✅ Produit supprimé avec succès.\n" RESET);
    else
        printf( RED "❌ Produit non trouvé.\n" RESET);
}

void verification_stock() {
    char designation[50];
    int qteDemandee;
    int trouve = 0;
    Produit p;

    FILE *f = fopen("product.dat", "rb");
    if (!f) {
        printf("Erreur ouverture fichier.\n");
        return;
    }

    fflush(stdin);
    printf( MAGENTA"\n--- Vérification du stock ---\n"RESET);
    printf("Désignation du produit : ");
    fgets(designation, sizeof(designation), stdin);
    designation[strcspn(designation, "\n")] = 0;

    printf("Quantité voulue : ");
    scanf("%d", &qteDemandee);

    while (fread(&p, sizeof(Produit), 1, f)) {
        if (strcmp(p.designation, designation) == 0) {
            trouve = 1;
            if (p.quantite >= qteDemandee) {
                printf(GREEN "✅ Stock suffisant (%d disponibles).\n"RESET , p.quantite);
            } else {
                printf(RED "⚠️ Stock insuffisant (seulement %d en stock).\n"RESET, p.quantite);
            }
            break;
        }
    }

    if (!trouve) {
        printf( RED "❌ Produit non trouvé.\n");
    }

    fclose(f);
}


=======
>>>>>>> f56135b11b1caa95f49a5faafca0ce56c2312c3c

