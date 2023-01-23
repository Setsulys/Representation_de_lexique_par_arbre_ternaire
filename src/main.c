#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "construction.h"
#include "sauvegarde.h"
#include "parcours.h"
#include "annexe.h"

/*---------------------------Main-----------------------------*/

int main(int argc, char* argv[]){
    /*----initialisaiton des variables----*/
    Arbre a = NULL;
    char dico[TAILLE], file[TAILLE];
    char mot[TAILLE], choix;
    int ouvre = 1; /* on ouvre par défaut, le premier argument */
    FILE* arbre = NULL;
    FILE* fichier = NULL;

    /*----Gestion de certaines erreurs possibles----*/
    if(argc > 4 || argc <1){
        printf("Nombre d'arguments invalide, veuiller en mettre entre 1 et 4\n");
        return 0;
    }
    if(argc==1){
    	printf("Erreur pas de texte pris en compte\n");
    	return 0;
    }

    if(argv[1][0] == '-'){
        ouvre = 2; /* on ouvre le 2e argument */
    }

    /*----ouverture du document----*/
    fichier = fopen(argv[ouvre], "r");

    if(fichier == NULL){
        printf("Il y a un problème avec le fichier ou pas de fichier renseigné\n");
        return 0;
    }

    cree_nom(argv[ouvre], ".DIC\0", dico);
    arbre = fopen(dico, "r");

    if(arbre != NULL){
        dic_to_arbre(arbre, &a);
        fclose(arbre);
    }else{
        constrarbre(&a,fichier);
        fclose(fichier);
    }

    if(argc == 2){
        choix = menu();
    }else{
        choix = argv[1][1];
    }

    switch(choix){
        case 'l' : parcours(a, mot, 0); break;
        case 's' : {
            /*----creation du fichier .LEX avec le nom de fichier placé en argument----*/
            cree_nom(argv[2], ".LEX\0", file);
            fichier = fopen(file, "w+");
            sauvegardealpha(a, mot, 0, fichier);
            printf("Lexique sauvegardé dans le fichier %s\n",file);
            fclose(fichier);

            break;
        }case 'r' : {
            if(ouvre == 2 && argv[3] != NULL){
                strcpy(mot, argv[3]);
            }else{
                printf("Choisisez un mot \n");
                scanf("%s", mot);
            }

            if(recherche(a,mot,0) == 1){
                printf("Le fichier %s contient le mot : %s\n", argv[ouvre], mot);
            }else{
                printf("Le fichier %s ne contient pas ce mot: %s\n", argv[ouvre], mot);
            }
            break;
        }case 'S' : {
            /*----creation du fichier .DIC avec le nom de fichier placé en argument----*/
            fichier = fopen(dico,"w+");
            sauvegardeprefixe(a, fichier);
            printf("Arbre sauvegardé dans le fichier %s\n",dico);
            fclose(fichier);
            break;
        }case 'q' : return 0;
        default : printf("veuillez réessayer");return 0;

    }

    return 0;
}