#define TAILLE 25

/*-----Structures-----*/
    typedef struct noeud{
        char lettre;            /* étiquette */
        struct noeud *fg;       /* fils gauche */
        struct noeud *fd;       /* fils droit */
        struct noeud *fils;     /* fils principal */
    } Noeud, *Arbre;

/*-----Fonction d'allocation de cellules-----*/

    Arbre alloueNoeud(char lettre);

/*-----Fonction de construction-----*/

    int constrarbrebis(Arbre *a,char mot[],int i);
    void constrarbre(Arbre *a,FILE*fichier);

/*-----Fonction qui converti un fichier.DIC en arbre-----*/

    void dic_to_arbre(FILE *fichier, Arbre *a);

/*-----Fonction de liberation de la mémoire-----*/

    void liberation(Arbre *a);