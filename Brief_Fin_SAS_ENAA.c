#include <stdio.h>
int numero;
int taille = 0;
struct date {
    int day;
    int month;
    int year;
};
struct Tache{
        char name[50];
        char description[50];
        struct date Date_d_echeance;
        int priotite;
};
void ajouter(struct Tache task[]) {
        printf("Entrer le nom de la tache :\n");
        scanf(" %[^\n]", task[taille].name);    
        printf("Entrer sa description :\n");
        scanf(" %[^\n]", task[taille].description);
        printf("Entrer sa date d'echeance :\n");
        scanf("%d/%d/%d", &task[taille].Date_d_echeance.day, &task[taille].Date_d_echeance.month, &task[taille].Date_d_echeance.year);   
        printf("Entrer la priotite (1 = Normal , 2 = Important) :\n");
        scanf(" %d", &task[taille].priotite);
    //while (getchar() != '\n');
    taille++;
}
void afficher(struct Tache task[]){
    for (int i = 0; i < taille; i++)
    {
        printf("tache %d: %s \n",i + 1,task[i].name);
        printf("Sa description est : %s \n",task[i].description);
        printf("Sa date d'echeance est : %d/%d/%d \n", task[i].Date_d_echeance.day, task[i].Date_d_echeance.month, task[i].Date_d_echeance.year);
        if(task)
        printf("Sa priotite est : %d \n",task[i].priotite);
        printf("\n");
    }
}
void modifier(struct Tache task[]){
    printf("Quelle tache souhaitez-vous modifier ?\n");
    scanf("%d",&numero);
    if(numero >= 1 && numero <= taille){
        printf("Entrer le nouveau nom : \n");
        scanf(" %[^\n]",task[numero - 1].name);
        printf("Entrer la nouvelle description : \n");
        scanf(" %[^\n]",task[numero - 1].description);
        printf("Entrer la nouvelle date d'echeance de cette tache :\n");
        scanf(" %[^\n]", task[taille].Date_d_echeance.day, &task[taille].Date_d_echeance.month, &task[taille].Date_d_echeance.year);   
        printf("Entrer la nouvelle priotite (1 = Normal , 2 = Important) :\n");
        scanf(" %d", &task[taille].priotite);
    }
    else
    printf("choix invalid !");
}
void supprimer(struct Tache task[]){
    printf("Quelle tache souhaitez-vous supprimer ?\n");
    scanf("%d",&numero);
    for(int i = 0; i <= numero ; i--){
    if(numero >= 1 && numero <= taille){
        task[numero - 1] = task[numero];
        printf("supprime avec succes \n");
        break;
    }
    else
    printf("choix invalid !");
    }
}
void ordonner_croissant(struct Tache task[]){
    for (int i = 0; i < taille - 1; i++){
        for(int j = i + 1 ; j < taille ; j++){
            if ((task[i].Date_d_echeance.year > task[j].Date_d_echeance.year) || (task[i].Date_d_echeance.year == task[j].Date_d_echeance.year) && task[i].Date_d_echeance.month > task[j].Date_d_echeance.month || (task[i].Date_d_echeance.month == task[j].Date_d_echeance.month && task[i].Date_d_echeance.day > task[j].Date_d_echeance.day))
            {
                struct Tache temp;
                temp = task[i];
                task[i] = task [j];
                task[j] = temp;
            }
        }
    }  
    afficher(task);
}
void ordonner_decroissant(struct Tache task[]){
    for (int i = 0; i < taille - 1; i++){
        for(int j = i + 1 ; j < taille ; j++){
            if (task[i].Date_d_echeance.year < task[j].Date_d_echeance.year || task[i].Date_d_echeance.year == task[j].Date_d_echeance.year && task[i].Date_d_echeance.month < task[j].Date_d_echeance.month || (task[i].Date_d_echeance.month == task[j].Date_d_echeance.month && task[i].Date_d_echeance.day < task[j].Date_d_echeance.day))
            {
                struct Tache temp;
                temp = task[i];
                task[i] = task [j];
                task[j] = temp;
            }
        }
    } 
    afficher(task);
}
void filtrer(struct Tache task[]){
    int choix;
    printf("choisit entre 1 pour Normal ou 2 pour Important \n");
    scanf("%d",&choix);
    printf("Resultats :\n");
    for(int i = 0; i < taille ; i++){
    if(task[i].priotite == choix){
            printf("%s",task[i].name);
        }
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
    printf("5 POUR ORDONNER LES TACHES EN ORDRE CROISSANT \n");
    printf("6 POUR ORDONNER LES TACHES EN ORDRE DECROISSANT\n");
    printf("7 FILTRER LES TACHES PAR PRIORITES\n");
    printf("8 QUITTER\n");
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
            ordonner_croissant(task);
            break;
        case 6:    
            ordonner_decroissant(task);
            break;
        case 7: 
            filtrer(task);
            break;
        case 8:
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
