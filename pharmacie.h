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
<<<<<<< HEAD
     char libelle[50];
=======
     char libelle[30];
>>>>>>> d294c8714c48641b2589898e3811368f21e8cb87
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
<<<<<<< HEAD
    char loginPharmacien[6];
=======
<<<<<<< HEAD
    char loginPharmacien[6];
=======
<<<<<<< HEAD
    char loginPharmacien[6];
=======
    char date[10];
    char loginPharmacien[10];
>>>>>>> 8085a31d8f808adaf71d70fcb524ef10c8a6895b
>>>>>>> f4499a739c63b652d77124ccfcbc509a52472b2e
>>>>>>> d294c8714c48641b2589898e3811368f21e8cb87
    Produit produits[100];
    int quantites[100];
    int nbProduits;
    float total;
} Vente;

void menu();
//produits
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
void saisitproduit();
=======
>>>>>>> f56135b11b1caa95f49a5faafca0ce56c2312c3c
>>>>>>> 8085a31d8f808adaf71d70fcb524ef10c8a6895b
>>>>>>> f4499a739c63b652d77124ccfcbc509a52472b2e
>>>>>>> d294c8714c48641b2589898e3811368f21e8cb87
void infoProduit();
void ajouterProduit();
void modifierProduit();
void supprimerProduit();
void recherchecode();
void verification_stock();
<<<<<<< HEAD

=======
<<<<<<< HEAD

=======
<<<<<<< HEAD

=======
<<<<<<< HEAD
void activerCouleurConsole();
 void afficherProduits();
=======

>>>>>>> f56135b11b1caa95f49a5faafca0ce56c2312c3c
>>>>>>> 8085a31d8f808adaf71d70fcb524ef10c8a6895b
>>>>>>> f4499a739c63b652d77124ccfcbc509a52472b2e
>>>>>>> d294c8714c48641b2589898e3811368f21e8cb87
//categories
void infoCategorie();
void ajouterCategorie();
void supprimerCategorie();

//Utilisateur
<<<<<<< HEAD
=======
<<<<<<< HEAD
void creerUtilisateur();
void bloquerUtilisateur();
void debloquerUtilisateur();
int connexionUtilisateur(Utilisateur *u);
void changerMotDePasse(Utilisateur *u);

void menuAdmin(Utilisateur u);
void menuPharmacien(Utilisateur u);
void infoUtilisateurConnecte(Utilisateur *u);




=======
>>>>>>> d294c8714c48641b2589898e3811368f21e8cb87
void infoUtilisateur();
void creerUtilisateur();
void bloquerUtilisateur();
void debloquerUtilisateur();
<<<<<<< HEAD
=======
>>>>>>> f4499a739c63b652d77124ccfcbc509a52472b2e
>>>>>>> d294c8714c48641b2589898e3811368f21e8cb87

//Vente et facture
void infoVente();
void generfacture();
void imprimfacture();
void consultstock();
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
void verification(FILE *tmp);
=======
>>>>>>> f56135b11b1caa95f49a5faafca0ce56c2312c3c
>>>>>>> 8085a31d8f808adaf71d70fcb524ef10c8a6895b
>>>>>>> f4499a739c63b652d77124ccfcbc509a52472b2e
>>>>>>> d294c8714c48641b2589898e3811368f21e8cb87
#endif
