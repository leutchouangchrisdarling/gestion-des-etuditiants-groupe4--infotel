
#include <stdio.h>
#include <string.h>
#include "structure.h"
#define MAX 100

void enregistrerEtudiant(Etudiant etudiants[], int *n) {
    if (*n >= MAX) {
        printf("Tableau plein.\n");
        return;
    }

    printf("Nom : ");
    scanf("%s", etudiants[*n].nom);

    printf("Prenom : ");
    scanf("%s", etudiants[*n].prenom);

    printf("Matricule : ");
    scanf("%s", etudiants[*n].matricule);

    printf("Filiere : ");
    scanf("%s", etudiants[*n].filiere);

    printf("Departement : ");
    scanf("%s", etudiants[*n].departement);

    printf("Region : ");
    scanf("%s", etudiants[*n].region);

    (*n)++;
    printf("Etudiant enregistre avec succes.\n");
}

void afficherEtudiants(Etudiant etudiants[], int n) {
    int i;
    if (n == 0) {
        printf("Aucun etudiant enregistre.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        printf("\nEtudiant %d\n", i + 1);
        printf("Nom : %s\n", etudiants[i].nom);
        printf("Prenom : %s\n", etudiants[i].prenom);
        printf("Matricule : %s\n", etudiants[i].matricule);
        printf("Filiere : %s\n", etudiants[i].filiere);
        printf("Departement : %s\n", etudiants[i].departement);
        printf("Region : %s\n", etudiants[i].region);
    }
}

void rechercherEtudiant(Etudiant etudiants[], int n) {
    char mat[20];
    int i, trouve = 0;

    printf("Entrer le matricule a rechercher : ");
    scanf("%s", mat);

    for (i = 0; i < n; i++) {
        if (strcmp(etudiants[i].matricule, mat) == 0) {
            printf("Etudiant trouve : %s %s\n",
                   etudiants[i].nom,
                   etudiants[i].prenom);
            trouve = 1;
            break;
        }
    }

    if (!trouve)
        printf("Etudiant non trouve.\n");
}

void trierParNom(Etudiant etudiants[], int n) {
    int i, j;
    Etudiant temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(etudiants[i].nom, etudiants[j].nom) > 0) {
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
}

void trierParFiliere(Etudiant etudiants[], int n) {
    int i, j;
    Etudiant temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(etudiants[i].filiere, etudiants[j].filiere) > 0) {
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
}

void trierParMatricule(Etudiant etudiants[], int n) {
    int i, j;
    Etudiant temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(etudiants[i].matricule, etudiants[j].matricule) > 0) {
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
}

int rechercheDichotomique(Etudiant etudiants[], int n, char matricule[]) {
    int debut = 0, fin = n - 1, milieu;
    int cmp;

    while (debut <= fin) {
        milieu = (debut + fin) / 2;
        cmp = strcmp(etudiants[milieu].matricule, matricule);

        if (cmp == 0)
            return milieu;
        else if (cmp < 0)
            debut = milieu + 1;
        else
            fin = milieu - 1;
    }

    return -1;
}
