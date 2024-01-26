#include <stdio.h>
int taille = 0;
struct Tache{
        char name[50];
        char description[50];
};
void ajouter(struct Tache task[]) {
    printf("Entrer le nom de la tache :\n");
    scanf("%s", task[taille].name);    
    printf("Entrer la description :\n");
    scanf("%s", task[taille].description);
    taille++;
}

void afficher(struct Tache task[]){
    for (int i = 0; i < taille; i++)
    {
        printf("tache %d: %s",task[i].name);
        printf("tache : %s",task[i].description);
    }
}
int menu(){
    int choix;
    printf("MENU\n");
    printf("1 AJOUTER\n");
    printf("2 AFFICHER\n");
    printf("3 SUPPRIMER\n");
    printf("4 MODIFIER\n");
    printf("5 ORDONNER\n");
    printf("6 FILTRER\n");
    printf("7 QUITTER\n");
    scanf("%d",&choix);
    return choix;
}
int main (){
    struct Tache task[50];
    do{
        switch (menu())
        {
        case 1:
            ajouter(task);
            taille++;
            break;
        case 2:
        afficher(task);
        taille++;
        break;
        default:
        printf("Choix invalide. Entrer un choix entre 1 et 7!\n");
            break;
        }
    }while(menu() != 3);

    return 0;
}