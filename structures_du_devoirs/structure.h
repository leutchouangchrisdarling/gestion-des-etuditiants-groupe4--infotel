

typedef struct {
    char nom[30];
    char prenom[30];
    char matricule[20];
    char filiere[30];
    char departement[30];
    char region[30];
} Etudiant;

/* ===== Prototypes des fonctions ===== */
void enregistrerEtudiant(Etudiant etudiants[], int *n);
void afficherEtudiants(Etudiant etudiants[], int n);
void rechercherEtudiant(Etudiant etudiants[], int n);
void trierParNom(Etudiant etudiants[], int n);
void trierParFiliere(Etudiant etudiants[], int n);
void trierParMatricule(Etudiant etudiants[], int n);
int rechercheDichotomique(Etudiant etudiants[], int n, char matricule[]);
