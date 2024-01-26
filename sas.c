#include <stdio.h>

int taille = 0;

struct date {
    int day;
    int month;
    int year;
};

struct Taches {
    char tache_name[50];
    char description[100];
    char priority[50];
    struct date tacheDate;
};

void add_tache(struct Taches tache[]) {
    printf("++ Votre tache:\n ");
    scanf(" %[^\n]s", tache[taille].tache_name);

    printf("+ Description :\n");
    scanf(" %[^\n]s", tache[taille].description);

    printf("+ Priorite:\n");
    scanf(" %[^\n]s", tache[taille].priority);

    printf("+ Date :\n");
    scanf("%d/%d/%d", &tache[taille].tacheDate.day, &tache[taille].tacheDate.month, &tache[taille].tacheDate.year);
    printf("\n");

    while (getchar() != '\n'); // Pour consommer le caractère de nouvelle ligne restant dans le tampon
    taille++;
}

void Affichage(struct Taches tache[]) {
    for (int i = 0; i < taille; i++) {
        printf("Task %d: %s\n", i + 1, tache[i].tache_name);
        printf("\t-Description :%s\n", tache[i].description);
        printf("\t-Priorite :%s\n", tache[i].priority);
        printf("\t-Date :%d/%d/%d\n", tache[i].tacheDate.day, tache[i].tacheDate.month, tache[i].tacheDate.year);
        printf("\n");
    }
}

void Menu(struct Taches tache[]) {
    int choix;
    do {
        printf("\t:::: Menu ::::\t\n");
        printf("< 1 > Ajouter une Tache \n");
        printf("< 2 > Afficher la Liste des Taches \n");
        printf("< 3 > Supprimer une Tache \n");
        printf("< 4 > Modifier une Tache \n");
        printf("< 5 > Ordonne les Tache \n");
        printf("< 6 > filtrer les Tache \n");
        printf("< 7 > Quitter \n");
        printf("==============choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                add_tache(tache);
                break;

            case 2:
                Affichage(tache);
                break;

            case 3:
                printf("Fonction de suppression non implémentée.\n");
                break;

            default:
                printf("Choix invalide. Entrer un choix entre 1 et 7!\n");

        }
    } while (choix != 7);
}

int main() {
    struct Taches tache[50];
    Menu(tache);

    return 0;
}