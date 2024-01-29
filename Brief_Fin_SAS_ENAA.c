#include <stdio.h>
int index;
int taille = 0;
struct Tache{
        char name[50];
        char description[50];
        char date_d_echeance[50];
        char priotite[50];
};
void ajouter(struct Tache task[]) {
    printf("Entrer le nom de la tache :\n");
    scanf(" %[^\n]", task[taille].name);    
    printf("Entrer sa description :\n");
    scanf(" %[^\n]", task[taille].description);
    printf("Entrer la date d'echeance de cette tache :\n");
    scanf(" %[^\n]", task[taille].date_d_echeance);    
    printf("Entrer la priotite :\n");
    scanf(" %[^\n]", task[taille].priotite);
    //while (getchar() != '\n');
    taille++;
}
void afficher(struct Tache task[]){
    for (int i = 0; i < taille; i++)
    {
        printf("tache %d: %s \n",i + 1,task[i].name);
        printf("Sa description est : %s \n",task[i].description);
        printf("Sa date d'echeance est : %s \n",task[i].date_d_echeance);
        printf("Sa priotite est : %s \n",task[i].priotite);
    
        printf("\n");
    }
}
void modifier(struct Tache task[]){
    printf("Quelle tache souhaitez-vous modifier ?\n");
    scanf("%d",&index);
    if(index >= 1 && index <= taille){
        printf("Entrer le nouveau nom : \n");
        scanf(" %[^\n]",task[index - 1].name);
        printf("Entrer la nouvelle description : \n");
        scanf(" %[^\n]",task[index - 1].description);
        printf("Entrer la nouvelle date d'echeance de cette tache :\n");
        scanf(" %[^\n]", task[taille].date_d_echeance);    
        printf("Entrer la nouvelle priotite :\n");
        scanf(" %[^\n]", task[taille].priotite);
    }
    else
    printf("choix invalid !");
}
void supprimer(struct Tache task[]){
    printf("Quelle tache souhaitez-vous supprimer ?\n");
    scanf("%d",&index);
    for(int i = 0; i <= index ; i--){
    if(index >= 1 && index <= taille){
        task[index - 1] = task[index];
        printf("supprime avec succes \n");
        break;
    }
    else
    printf("choix invalid !");
    }
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
        case 4:
            supprimer(task);
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
