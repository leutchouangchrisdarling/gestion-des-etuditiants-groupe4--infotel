#include <stdio.h>
#include <string.h>
#include "structure.h"
#define MAX 100


int main() {
    Etudiant etudiants[MAX];
    int n = 0;
    int choix;
    char mat[20];
    int pos;

    do {
        printf("\n===== GESTION DES ETUDIANTS =====\n");
        printf("1. Enregistrer un etudiant\n");
        printf("2. Afficher les etudiants\n");
        printf("3. Rechercher un etudiant (simple)\n");
        printf("4. Trier les etudiants par nom\n");
        printf("5. Trier les etudiants par filiere\n");
        printf("6. Rechercher un etudiant par dichotomie (matricule)\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                enregistrerEtudiant(etudiants, &n);
                break;
            case 2:
                afficherEtudiants(etudiants, n);
                break;
            case 3:
                rechercherEtudiant(etudiants, n);
                break;
            case 4:
                trierParNom(etudiants, n);
                printf("Tri par nom effectue.\n");
                break;
            case 5:
                trierParFiliere(etudiants, n);
                printf("Tri par filiere effectue.\n");
                break;
            case 6:
                trierParMatricule(etudiants, n);
                printf("Entrer le matricule a rechercher : ");
                scanf("%s", mat);
                pos = rechercheDichotomique(etudiants, n, mat);
                if (pos != -1) {
                    printf("Etudiant trouve : %s %s\n",
                           etudiants[pos].nom,
                           etudiants[pos].prenom);
                } else {
                    printf("Etudiant non trouve.\n");
                }
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