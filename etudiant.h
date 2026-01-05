#ifndef _ETUDIANT_H
#define _ETUDIANT_H

typedef struct {
  int jour;
  int mois;
  int annee;
} Date;

typedef struct {
  char nom[30];
  char prenom[30];
  char matricule[20];
  char filiere[30];
  char departement[30];
  char region[30];
  Date dateNaissance;
} Etudiant;

typedef struct {
  Etudiant *etudiants;
  int taille;
  int nbEtudiants;
} ListeEtudiants;

void enregistrerEtudiant(ListeEtudiants *liste, Etudiant e);
void afficherEtudiant(Etudiant e); // Affiche un seul étudiant
void afficherEtudiants(ListeEtudiants liste); // Affiche la liste des étudiants
void rechercherEtudiant(ListeEtudiants liste);
void trierParNom(ListeEtudiants liste);
void trierParFiliere(ListeEtudiants liste);
void trierParMatricule(ListeEtudiants liste);
int rechercheDichotomique(ListeEtudiants liste, char matricule[]);
void ecrireListeDansFichier(ListeEtudiants liste, char* nomFichier);
int calculerAge(Etudiant e);

#endif