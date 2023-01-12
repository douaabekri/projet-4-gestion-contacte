# projet-4-gestion-contacte
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

struct personne
{
    char prenom[30];
    char nom[20];       /* Le nom de la personne */
    char email[30];
    char instegram[20];
    char numero[11];    /* le numero de telephone */
};

typedef struct personne PERS;

void saisir_personne(PERS *pp);
void saisir_contact(PERS rep[]);
void afficher_contact(PERS rep[], int nb);
char *chercher_personne(PERS rep[], int nb,char *prenom ,char *nom);
char *Supprimer_contact(PERS rep[], int nb,char *prenom, char *nom);

int main()
{
    PERS monRep[20];
    int choix;
    char nom[20],prenom[30],instegram[20],email[30], *pnum;

    do
    {
        do
        {
             system("cls");
             printf("\n");
             printf ("\t{}                                                                               {} \n");
             printf ("\t{}  [1] : ==========<<<<<<<  Creer un contacts             >>>>>>========      {} \n");
             printf ("\t{}  [2] : ==========<<<<<<<  Afficher les contacts           >>>>>>========      {} \n");
             printf ("\t{}  [3] : ==========<<<<<<<  Rechercher un contact           >>>>>>========      {} \n");
             printf ("\t{}  [4] : ==========<<<<<<<  Modifier un contact             >>>>>>========      {} \n");
             printf ("\t{}  [5] : ==========<<<<<<<  Supprimer un contact            >>>>>>========      {} \n");
             printf ("\t{}  [11]: ==========<<<<<<<  Quitter                         >>>>>>========      {} \n");
             printf ("\t{}                                                                               {} \n");
             printf("Veuillez faire votre choix : ");
             scanf("%d", &choix);
        }
        while (choix < 1 || choix > 3);
        switch (choix)
        {
            case 1 : saisir_contact(monRep);break;
            case 2 : afficher_contact(monRep, 20);break;

            case 3 : printf("prenom et nom a rechercher : ");break;
                     scanf("%s", prenom);
                     scanf("%s", nom);
                     pnum = chercher_personne(monRep,20,prenom, nom);
                     if (pnum == NULL)
                     {
                        printf(" Personne inexistante\n");
                     }
                     else
                     {
                        printf("--> Numero de %s: %s\n", nom, pnum);
                     }
                      break;
            case 5 :
                printf("prenom et nom a Supprimer : ");
                     scanf("%s", prenom);
                     scanf("%s", nom);
                 pnum = Supprimer_contact(monRep, 20,prenom, nom);
                 if (pnum == NULL)
                 {
                    printf(" Personne inexistante\n");
                 }
                 else
                 {
                    printf("--> Numero de %s: %s\n", nom, pnum);
                 }
            break; 
            default : printf("Merci et au revoir!\n");
        }
    }
    while (choix != 11);
    return 0;
}

void saisir_personne(PERS *pp)
{
    printf("Prenom : "); scanf("%s", pp->prenom);
    printf("Nom : "); scanf("%s", pp->nom);
    printf("instegram : "); scanf("%s", pp->instegram);
    printf("email :"); scanf("%s", pp->email);
    printf("Numero : "); scanf("%s", pp->numero);
}

void saisir_contact(PERS rep[])
{
    int i,nb;
    printf("le nombre de personnes a ajouter :\n");
    scanf("%d", &nb);
    printf("Saisie du contacte de %d personnes :\n", nb);
    for (i=0; i<nb; i++)
    {
        saisir_personne(&rep[i]);
    }
}
void afficher_contact(PERS rep[], int nb)
{
    int i;
    printf("Affichage du contact\n");
    printf("%20s     %3s      %3s   %5s        Numero\n\n","prenom","nom","instegram","email");
    for (i=0; i<sizeof(rep); i++)
    {
        printf("%20s | %3s | %3s |  %5s |     %s\n",rep[i].prenom ,rep[i].nom,rep[i].instegram,rep[i].email,rep[i].numero);
    }
}

char *chercher_personne(PERS rep[], int nb,char *prenom, char *nom)
{
    int i;
    for (i=0; i<nb; i++)
    {
        if (strcmp(nom, rep[i].nom) == 0 && strcmp(prenom, rep[i].prenom) == 0)
        {
            return rep[i].numero;
        }
    }
    return NULL;
}


char *Supprimer_contact(PERS rep[], int nb,char *prenom, char *nom)
{
    int i,j;
    for (i=0; i<nb; i++)
    {
        if (strcmp(nom, rep[i].nom) == 0 && strcmp(prenom, rep[i].prenom) == 0)
        {
            return 0;
        }
    }

    return NULL;
}
