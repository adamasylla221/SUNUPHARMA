#ifndef PHARMACIE_H
#define PHARMACIE_H
typedef struct{
    char code[5];
    char designation[50];
    int quantite;
    float prix;
    char categorie_Produit[20];
    char date_peremption[12];

} Produit;


 typedef struct{
     int id;
     char libelle[30];
 } Categorie;

 typedef enum{
     admin,
     pharmacien
 } Role;



 typedef struct{
     char login[6];
     char password[20];
     char nom[20],prenom[30],telephone[12];
     Role role; //choix au niveau du role soit admin ou pharmacien
     int actif;
 } Utilisateur;

 typedef struct {
    char numero[15];
    char loginPharmacien[6];
    Produit produits[100];
    int quantites[100];
    int nbProduits;
    float total;
} Vente;

void menu();
//produits
void saisitproduit();
void infoProduit();
void ajouterProduit();
void modifierProduit();
void supprimerProduit();
void recherchecode();
void verification_stock();
void activerCouleurConsole();
 void afficherProduits();
//categories
void infoCategorie();
void ajouterCategorie();
void supprimerCategorie();

//Utilisateur
void infoUtilisateur();
void creerUtilisateur();
void bloquerUtilisateur();
void debloquerUtilisateur();

//Vente et facture
void infoVente();
void generfacture();
void imprimfacture();
void consultstock();
void verification(FILE *tmp);
#endif
