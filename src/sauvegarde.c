#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "construction.h"
#include "sauvegarde.h"


/*---------------------------Fonction de sauvegarde alphabetique-----------------------------*/
    void sauvegardealpha(Arbre a,char mot[],int i,FILE* savealpha){
        if(a == NULL){
            return;
        }

        sauvegardealpha(a->fg, mot, i,savealpha);
        mot[i] = a->lettre;

        if(a->fils == NULL){
            mot[i+1] = '\0';
            fprintf(savealpha,"%s", mot);
        }
        else{
            sauvegardealpha(a->fils, mot, i + 1,savealpha);
            sauvegardealpha(a->fd, mot, i,savealpha);
        }
    }


    /*---------------------------Fonction de sauvegarde prefix dans un fichier DIC-----------------------------*/ /*fonction fini et fonctionnelle*/
    void sauvegardeprefixe(Arbre a,FILE*save) {

        if (NULL == a){
            fprintf(save," ");
            return;
        }
        fprintf(save,"%c", a->lettre);
        if(a->lettre !='\n'){
            sauvegardeprefixe(a->fg,save);
            sauvegardeprefixe(a->fils,save);
            sauvegardeprefixe(a->fd,save);
        }
        else{
            sauvegardeprefixe(a->fd,save);
        }
    }