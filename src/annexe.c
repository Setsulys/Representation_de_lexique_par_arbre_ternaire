#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "construction.h"
#include "annexe.h"

/*---------------------------Menu-----------------------------*/
    char menu(){
        char choix;
        printf("[l] : affichage alphabetique\n");
        printf("[s] : sauvegarde alphabetique dans un fichier.LEX\n");
        printf("[r] : recherche d'un mot\n");
        printf("[S] : Sauvegarde sous forme préfixe de l'arbre\n");
        printf("[q] : quitter le programme\n");

        do{
            printf("Choisisez une option\n");
            scanf("%c",&choix);
        }while(choix != 'l' && choix != 's' && choix != 'r' && choix != 'S' && choix != 'q');

        printf("\n");

        return choix;
    }

/* modifie le fichier */
    void cree_nom(char const *nom, char format[TAILLE], char file[TAILLE]){
        int i = 0, j;

        strcpy(file, nom);

        while(file[i]!='\0' && file[i]!='.'){
            i++;
        }

        for( j = 0 ; format[j] != '\0'; j++){
            file[i + j] = format[j];
        }
    }