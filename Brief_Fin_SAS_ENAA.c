#include <stdio.h>
int index;
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
    //while (getchar() != '\n');
    taille++;
}
void afficher(struct Tache task[]){
    for (int i = 0; i < taille; i++)
    {
        printf("tache %d: %s \n",i + 1,task[i].name);
        printf("Sa description est : %s \n",task[i].description);
        printf("\n");
    }
}
void modifier(struct Tache task[]){
    printf("Quelle tache souhaitez-vous modifier ?\n");
    scanf("%d",&index);
    if(index >= 1 && index <= taille){
        printf("Entrer le nouveau nom : \n");
        scanf("%s",task[index - 1].name);
        printf("Entrer la nouvelle description : \n");
        scanf("%s",task[index - 1].description);
    }
    else
    printf("choix invalid !");
}
void menu(struct Tache task[]){
    int choix;
    do{
    printf("MENU\n");
    printf("1 AJOUTER\n");
    printf("2 AFFICHER\n");
    printf("3 MODIFIER\n");
    printf("4 SUPPRIMER\n");
    printf("5 QUITTER\n");
    scanf("%d",&choix);
        switch (choix)
        {
        case 1:
            ajouter(task);
            break;
        case 2:
            afficher(task);
            break;
        case 3:
            modifier(task);
            break;
        case 5:
            printf("Au revoir !");
            break; 
        default:
            printf("Choix invalide. Entrer un choix entre 1 et 7!\n");
        }
    }while(choix != 5);
}
int main (){
    struct Tache task[50];
    menu(task);
    return 0;
}