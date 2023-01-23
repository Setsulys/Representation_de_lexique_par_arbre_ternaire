#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "construction.h"



/*---------------------------Fonction d'allocation de cellules-----------------------------*/

    Arbre alloueNoeud(char lettre){
        Arbre tmp= (Noeud*)malloc(sizeof(Noeud));
        if(tmp==NULL){
            return tmp;
        }
        tmp->lettre = lettre;
        tmp->fg=NULL;
        tmp->fd=NULL;
        tmp->fils=NULL;
        return tmp;
    }

/*---------------------------Fonction de construction-----------------------------*/
    /*construction de l'arbre a partir d'un fichier donné*/

    int constrarbrebis(Arbre *a,char mot[],int i){
        char lettre = tolower(mot[i]);

        if(mot[i] == '\0'){
            *a = alloueNoeud('\n');
            return 1;
        }
        else{

            if(*a==NULL){
                *a = alloueNoeud(lettre);

                i++;
                return constrarbrebis(&((*a)->fils),mot,i);
            }
            if((*a)->lettre >lettre){
                return constrarbrebis(&((*a)->fg),mot,i);
            }
            else if((*a)->lettre < lettre){
                return constrarbrebis(&((*a)->fd),mot,i);
            }
            else{
                i++;
                return constrarbrebis(&((*a)->fils),mot,i);
            }
        }
    }


    void constrarbre(Arbre *a,FILE*fichier){
        char mot[TAILLE];
        int i;
        while(fscanf(fichier,"%s",mot)!=EOF){
            i=0;
            constrarbrebis(a,mot,i);
        }
    }

/*-------------------------utilisation du fichier.DIC pour creer l'arbre--------------------------*/
void dic_to_arbre(FILE *fichier, Arbre *a){
    char lettre = fgetc(fichier);
    if(lettre != ' '){
        *a = alloueNoeud(lettre);
        if(lettre == '\n'){
            dic_to_arbre(fichier, &((*a)->fd));
        }else{
            dic_to_arbre(fichier, &((*a)->fg));
            dic_to_arbre(fichier, &((*a)->fils));
            dic_to_arbre(fichier, &((*a)->fd));
        }
    }
}

/*---------------------------Liberation de la memoire-----------------------------*/
    void liberation(Arbre *a){ /*liberation de l'espace alloué en passant par un parcours préfixe de l'arbre*/
        Arbre tmp=*a;
        if(a==NULL){
            return;
        }
        if(tmp->fg!=NULL){
            liberation(&tmp->fg);
        }
        if(tmp->fd!=NULL){
            liberation(&tmp->fd);
        }
        if(tmp->fils!=NULL){
            liberation(&tmp->fils);
        }
        free(tmp);
        a = NULL;
    }