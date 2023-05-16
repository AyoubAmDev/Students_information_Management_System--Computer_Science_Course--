#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//------------------------------ La structure de donnée ---------------------------------------------------------------------------------------
//                                (the data structure)

typedef struct
{
    char nom[20];
    char prenom[20];
    char CNE[15];
    float notes[4];
    float moyenne;
    char Etat[4]; // validé, Ratt, ou NV
    int age;
    struct Etudiant*next;
} Etudiant;


//------------------------------ Prototypes des fonctions ---------------------------------------------------------------------------------------
//                                 (function prototype)

float Calc_moyn(float n1, float n2, float n3, float n4);
void affich_info(Etudiant *L);
void affich_N_P(Etudiant *L);
char * validation(float moyenne);
Etudiant * inser(Etudiant * L, char nom[], char prenom[], char CNE[], float notes[], float moyenne, char Etat[], int age);
Etudiant * get_info(Etudiant * L);
void chercher_N_P(Etudiant *L);
void cherchCNE(Etudiant *L);
void cherchMemeP(Etudiant *L);
void cherchMemeAge(Etudiant *L);
void cherchMemeMoyn(Etudiant *L);
void PlusGrandM(Etudiant*L);
void PlusPetiteM(Etudiant*L);
float MoyenneDMoyenne(Etudiant*L);
void MoyeInf(Etudiant *L,float M);
void MoyeSup(Etudiant *L,float M);
void ajouter_list(Etudiant*L);
int supprimer_list(Etudiant*L,char C[]);
int ajouter_file(Etudiant * L, char nom[], char prenom[], char CNE[], float notes[]);
int  supprimer_file(char C[]);
Etudiant* trie_alpha(Etudiant* L);
Etudiant * inser_trie(Etudiant * L, char nom[], char prenom[], char CNE[], float notes[], float moyenne, char Etat[], int age);
Etudiant * trie_moyn_decroi(Etudiant * L);
Etudiant * trie_moyn_croi(Etudiant * L);





//------------------------------- La fonction principale ---------------------------------------------------------------------------------------
//                                  (The main function)




int main()
{
    char CN[15];
    char choix;              // user's choice
    int etat,chx;           // also user's choice
    float m;               // variable pour stocker la moyenne des moyennes
    Etudiant * L, *tmp;   // pointeur sur la liste et un autre temporaire pour la parcourir
    L = NULL;            // initialisation par NULL
    L = get_info(L);    // remplissage de la liste par les infos à partir du fichier

    printf("\n\t\t\t\t\t\tBonjour cher utilisateur !!!\n");
    printf("=====================================================================================================================================\n\n");
    printf("\n\t\t\t\t\t\tCe travaille est realise par : \n");
    printf("\n\n\t\t       _____________\t\t    _______________\t\t    _______________\n");
    printf("\n\t\t      | Ayoub Amtdi |\t\t   | Maryam Oublal |\t\t   | Alfred MWAMBA |\n");
    printf("\t\t       _____________\t\t    _______________\t\t    _______________ \n\n");
    printf("\n\n\n\n\tC'est un programme qui permet de gerer les informations des etudiants de G.I 2022/2023 par les listes chainee,");
    printf("\n\t\t tout en offrant plusieurs fonctionnalites comme ajouter et retirer un etudiant de la liste,");
    printf("\n\t\t\t\t\t    trier la liste, afficher...\n\n");
    printf("\n\n\n\n\t\tDecouvrez tous ce que vous pouvez faire, en appuyant sur n'importe quelle touche. ");
    printf("\n\n\n=====================================================================================================================================");
    choix = getch();
ici :
    system("cls");
    printf("\t\t\t\t\t\t   ______________________________________\n");
    printf("\n\t\t\t\t\t\t  |   Menu d'utilisateur    |\n");
    printf("\t\t\t\t      ______________________________________\n\n");
    printf("\t\t    ___________________________________________________________\n\n");
    printf("<1>  Afficher la liste des etudiants ( nom et prenom).     |  <8>  Trier la liste en ordre croissant selon la moyenne\n");
    printf("                                                           |       des etudiants.\n");
    printf("<2>  Afficher les informations d'un etudiant specifique.   |\n");
    printf("                                                           |  <9>  Trier la liste en ordre decroissant selon la moyenne\n");
    printf("<3>  Ajouter un nouveau etudiant a la liste.               |       des etudiants.\n");
    printf("                                                           |\n");
    printf("<4>  Supprimer un etudiant de la liste.                    |  <10>  Trier la liste selon l'ordre alphabetique.\n");
    printf("                                                           |\n");
    printf("<5>  Chercher les etudiant qui ont le meme prenom,age,     |  <11> Calculer la moyenne des moyennes des etudiants.\n");
    printf("     ou moyenne.                                           |\n");
    printf("                                                           |  <12> Chercher tous les etudiants qui ont une moyenne\n");
    printf("<6>  Chercher et afficher les information de l'etudiant    |       >= moyenne des moyennes.\n");
    printf("     ayant la plus grande moyenne (Le majorant).           |\n");
    printf("                                                           |  <13> Chercher tous les etudiants qui sont valides\n");
    printf("<7>  Chercher et afficher les information de l'etudiant    |       (moyenne >= 12).\n");
    printf("     ayant la plus petite moyenne.                         |");
    printf("\n\n\t\t\t\t   ______________________________________________________________\n\n");
    printf("\tTappez l'indice de la commande que vouz voulez utiliser, sinon tappez 0 pour quitter le programme  : ");
    scanf("%d",&chx);
    switch (chx)
    {
    case 0 :
        exit (1);

    case 1 :
        system("cls");
        printf("\tVoici la liste des etudiants : (nom, prenom) \n\n");
        tmp = L;
        while (tmp != NULL)
        {
            affich_N_P(tmp);
            tmp = tmp->next;
        }
        printf("\n\t\t Afficher les informations d'un etudiant specifique ? (o/n)");
        choix = getch();
        system("cls");
        switch(choix)
        {
        case 'o':
            printf("\n\t\t\t\t chercher cette etudiant selon :\n");
            printf("\n\t\t                c: pour CNE            n: pour nom et prenom");
            choix = getch();
            if(choix == 'c')
            {
                printf("\n");
                cherchCNE(L);
                printf("\n\n\t\t Voulez vous revenir au menu principale du programme ou bien quitter.\n\n");
                printf("\t\t\t\t m : Menu \t\t\t q : Quitter\n");
                choix = getch();
                if((choix == 'm' || choix == 'M')) goto ici;
                else if ((choix == 'q') || (choix == 'Q')) exit (1);
            }
            else
            {
                printf("\n");
                chercher_N_P(L);
                exit (1);
            }
        case 'n' :
            printf("\n\n\t\t Voulez vous revenir au menu principale du programme ou bien quitter.\n\n");
            printf("\t\t\t\t m : Menu \t\t\t q : Quitter\n");
            choix = getch();
            if((choix == 'm' || choix == 'M')) goto ici;
            else if ((choix == 'q') || (choix == 'Q')) exit (1);
        }

        break;

    case 2 :
        system("cls");
        printf("\n\t\t\t\t chercher cette etudiant selon :\n");
        printf("\n\t\t                c: pour CNE            n: pour nom et prenom");
        choix = getch();
        if(choix == 'c')
        {
            printf("\n");
            cherchCNE(L);
            printf("\n\n\t\t Voulez vous revenir au menu principale du programme ou bien quitter.\n\n");
            printf("\t\t\t\t m : Menu \t\t\t q : Quitter\n");
            choix = getch();
            if((choix == 'm' || choix == 'M')) goto ici;
            else if ((choix == 'q') || (choix == 'Q')) exit (1);
        }
        else
        {
            printf("\n");
            chercher_N_P(L);
            printf("\n\n\t\t Voulez vous revenir au menu principale du programme ou bien quitter.\n\n");
            printf("\t\t\t\t m : Menu \t\t\t q : Quitter\n");
            choix = getch();
            if((choix == 'm' || choix == 'M')) goto ici;
            else if ((choix == 'q') || (choix == 'Q')) exit (1);
        }

        break;

    case 3 :
        system("cls");
        ajouter_list(L);
        printf("\n\n\t\t Voulez vous revenir au menu principale du programme ou bien quitter.\n\n");
        printf("\t\t\t\t m : Menu \t\t\t q : Quitter\n");
        choix = getch();
        if((choix == 'm' || choix == 'M')) goto ici;
        else if ((choix == 'q') || (choix == 'Q')) exit (1);

        break;

    case 4 :
        system("cls");
        printf("\n\t Entrer le CNE de l'etudiant que vouz voulez supprimer de la liste :");
        getchar();
        gets(CN);
        etat = supprimer_list(L,CN);
        if (etat == 1) printf("\n\n\tL'opperation effectuee avec succes!");
        printf("\n\n\t\t Voulez vous revenir au menu principale du programme ou bien quitter.\n\n");
        printf("\t\t\t\t m : Menu \t\t\t q : Quitter\n");
        choix = getch();
        if((choix == 'm' || choix == 'M')) goto ici;
        else if ((choix == 'q') || (choix == 'Q')) exit (1);
        break;

    case 5 :
        system("cls");
        printf("\n\tChercher les etudiant qui ont le meme :\n\n");
        printf ("\t p : Prenom ? \t\t m : Moyenne ? \t\t a : age ?\n\n");
        choix = getch();
        switch(choix)
        {
        case 'p':
            cherchMemeP(L);
            printf("\n\n\t\t Voulez vous revenir au menu principale du programme ou bien quitter.\n\n");
            printf("\t\t\t\t m : Menu \t\t\t q : Quitter\n");
            choix = getch();
            if((choix == 'm' || choix == 'M')) goto ici;
            else if ((choix == 'q') || (choix == 'Q')) exit (1);
            break;

        case 'm':
            cherchMemeMoyn(L);
            printf("\n\n\t\t Voulez vous revenir au menu principale du programme ou bien quitter.\n\n");
            printf("\t\t\t\t m : Menu \t\t\t q : Quitter\n");
            choix = getch();
            if((choix == 'm' || choix == 'M')) goto ici;
            else if ((choix == 'q') || (choix == 'Q')) exit (1);
            break;

        case 'a':
            cherchMemeAge(L);
            printf("\n\n\t\t Voulez vous revenir au menu principale du programme ou bien quitter.\n\n");
            printf("\t\t\t\t m : Menu \t\t\t q : Quitter\n");
            choix = getch();
            if((choix == 'm' || choix == 'M')) goto ici;
            else if ((choix == 'q') || (choix == 'Q')) exit (1);
            break;

        }
        break;

    case 6 :
        system("cls");
        printf("\n\n\n\n\t\t Le majorant de GI S1 est :\n");
        PlusGrandM(L);
        printf("\n\n\n");
        printf("\n\n\t\t Voulez vous revenir au menu principale du programme ou bien quitter.\n\n");
        printf("\t\t\t\t m : Menu \t\t\t q : Quitter\n");
        choix = getch();
        if((choix == 'm' || choix == 'M')) goto ici;
        else if ((choix == 'q') || (choix == 'Q')) exit (1);
        break;

    case 7 :
        system("cls");
        printf("\n\n\n\n\t\t Lietudiant ayant la plus petite moyenne est :\n");
        PlusPetiteM(L);
        printf("\n\n\n");
        printf("\n\n\t\t Voulez vous revenir au menu principale du programme ou bien quitter.\n\n");
        printf("\t\t\t\t m : Menu \t\t\t q : Quitter\n");
        choix = getch();
        if((choix == 'm' || choix == 'M')) goto ici;
        else if ((choix == 'q') || (choix == 'Q')) exit (1);
        break;

    case 8 :
        system("cls");
        printf("\n\n\tTappez 1 pour trier la liste en ordre croissant selon la moyenne : ");
        scanf("%d",&etat);
        if (etat == 1)
        {
            trie_moyn_croi(L);
            printf("\n\n\t\tLa liste est trie avec succes!! \n\n");
            printf("Voulez vous voir la nouvelle liste triee ? (o/n)\n\n");
            choix = getch();
            if (choix == 'o' || choix == 'O')
            {
                printf("\tVoici la liste triee des etudiants : (nom, prenom) \n\n");
                tmp = L;
                while (tmp != NULL)
                {
                    printf("  %.2f ",tmp->moyenne);
                    affich_N_P(tmp);
                    tmp = tmp->next;
                }
            }
            printf("\n\n\t\t Voulez vous revenir au menu principale du programme ou bien quitter.\n\n");
            printf("\t\t\t\t m : Menu \t\t\t q : Quitter\n");
            choix = getch();
            if((choix == 'm' || choix == 'M')) goto ici;
            else if ((choix == 'q') || (choix == 'Q')) exit (1);
        }

        break;

    case 9 :
        system("cls");
        printf("\n\n\tTappez 1 pour trier la liste en ordre decroissant selon la moyenne : ");
        scanf("%d",&etat);
        if (etat == 1)
        {
            trie_moyn_decroi(L);
            printf("\n\n\t\tLa liste est trie avec succes!! \n\n");
            printf("Voulez vous voir la nouvelle liste triee ? (o/n)\n\n");
            choix = getch();
            if (choix == 'o' || choix == 'O')
            {
                printf("\tVoici la liste triee des etudiants : (nom, prenom) \n\n");
                tmp = L;
                while (tmp != NULL)
                {
                    printf("  %.2f ",tmp->moyenne);
                    affich_N_P(tmp);
                    tmp = tmp->next;
                }
            }
            printf("\n\n\t\t Voulez vous revenir au menu principale du programme ou bien quitter.\n\n");
            printf("\t\t\t\t m : Menu \t\t\t q : Quitter\n");
            choix = getch();
            if((choix == 'm' || choix == 'M')) goto ici;
            else if ((choix == 'q') || (choix == 'Q')) exit (1);
        }
        break;

    case 10 :
        system("cls");
        printf("\n\n\tTappez 1 pour trier la liste en ordre alphabetique : ");
        scanf("%d",&etat);
        if (etat == 1)
        {
            trie_alpha(L);
            printf("\n\n\t\tLa liste est trie avec succes!! \n\n");
            printf("Voulez vous voir la nouvelle liste triee ? (o/n)\n\n");
            choix = getch();
            if (choix == 'o' || choix == 'O')
            {
                printf("\tVoici la liste triee des etudiants : (nom, prenom) \n\n");
                tmp = L;
                while (tmp != NULL)
                {
                    affich_N_P(tmp);
                    tmp = tmp->next;
                }
            }
            printf("\n\n\t\t Voulez vous revenir au menu principale du programme ou bien quitter.\n\n");
            printf("\t\t\t\t m : Menu \t\t\t q : Quitter\n");
            choix = getch();
            if((choix == 'm' || choix == 'M')) goto ici;
            else if ((choix == 'q') || (choix == 'Q')) exit (1);
        }
        break;

    case 11 :
        system("cls");
        m = MoyenneDMoyenne(L);
        printf("\n\n\n\t\t\t\t La moyenne des moyennes des etudiants est : | %.2f |\n\n",m);
        printf("\n\n\t\t Voulez vous revenir au menu principale du programme ou bien quitter.\n\n");
        printf("\t\t\t\t m : Menu \t\t\t q : Quitter\n");
        choix = getch();
        if((choix == 'm' || choix == 'M')) goto ici;
        else if ((choix == 'q') || (choix == 'Q')) exit (1);
        break;

    case 12 :
        system("cls");
        printf("\n\n\t\t Les etudiants qui ont la moyenne >= a la moyenne des moyennes sont : \n\n");
        m = MoyenneDMoyenne(L);
        MoyeSup(L,m);
        printf("\n\n\t\t Voulez vous revenir au menu principale du programme ou bien quitter.\n\n");
        printf("\t\t\t\t m : Menu \t\t\t q : Quitter\n");
        choix = getch();
        if((choix == 'm' || choix == 'M')) goto ici;
        else if ((choix == 'q') || (choix == 'Q')) exit (1);
        break;

    case 13 :
        system("cls");
        printf("\tVoici la liste des etudiants qui sont validee : \n\n");
        tmp = L;
        while (tmp != NULL)
        {
            if(strcmp(tmp->Etat,"VAL") == 0)
            {
                printf("  %.2f ",tmp->moyenne);
                affich_N_P(tmp);
            }
            tmp = tmp->next;
        }
        printf("\n\n\t\t Voulez vous revenir au menu principale du programme ou bien quitter.\n\n");
        printf("\t\t\t\t m : Menu \t\t\t q : Quitter\n");
        choix = getch();
        if((choix == 'm' || choix == 'M')) goto ici;
        else if ((choix == 'q') || (choix == 'Q')) exit (1);
        break;

    }


    return 0;
}


//-------------------------------------------------------------------------------------------------------------------------------------------------



//------------------------------- Définitions des fonctions ---------------------------------------------------------------------------------------
//                                  (function definitions)


//fonction qui calcule la moyenne des notes d'un étudiant *******************************
/* This function calculates the average of a student's grades */


float Calc_moyn(float n1, float n2, float n3, float n4)
{
    return (n1+n2+n3+n4)/4;
}


//fonction qui affiche tout les informations d'un étudiant *******************************
/* This function displays a student's information */


void affich_info(Etudiant *L)
{
    if(L==NULL) printf("La liste est vide");
    else
    {

        printf("\n\n nom : %s\n prenom : %s\n CNE : %s\n age est : %d ", L->nom,L->prenom,L->CNE,L->age);
        printf("\nLes notes : ");

        printf("\n Analyse : %.2f",L->notes[0]);
        printf("\n Algebre : %.2f",L->notes[1]);
        printf("\n Les Circuits Logiques : %.2f",L->notes[2]);
        printf("\n Architecture et Programmation Assembleur : %.2f",L->notes[3]);

        printf("\n La moyenne est : %.2f",L->moyenne);
        printf("\n Etat : %s",L->Etat);
    }
}


//fonction qui affiche just le nom et le prénom d'un étudiant *******************************
/* This function displays a student's first and last name */


void affich_N_P(Etudiant *L)
{
    if(L==NULL)     printf("La liste est vide");
    else            printf("\t\t\t\t %-25s%-25s\n ", L->nom,L->prenom);
}


//Cette fonction vérifie si l'étudiant a réussi ou non dans l'ensemble des exames *******************************
//ou s'il a un examain de rattrapage *******************************

/* This function checks whether or not the student has passed all the tests
  or if he has a resit exam */


char * validation(float moyenne)
{
    if(moyenne >= 12)      return "VAL";
    else if(moyenne >=6)   return "RAT";
    else                   return "NV";
}


//cette fonction lit les informations des étudiants à partir d'un fichier *******************************
//préparé à l'avance, puis ajoute ces informations dans une liste chaînée *******************************

/* this function reads student information from a pre-prepared file and then
   adds that information into a linked list */


Etudiant * get_info(Etudiant * L)
{
    FILE * fp;
    char line[100];
    char nom[20];
    char prenom[20];
    char CNE[15];
    float notes[4];
    float moyenne;
    char Etat[4];
    int age;


    fp = fopen("GI_DS_S1_infos.txt","r");
    if (fp == NULL)
    {
        printf("Error opening file 87\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp))
    {
        sscanf(line, "%s %s %s %f %f %f %f", CNE, nom, prenom, &notes[0], &notes[1], &notes[2], &notes[3]);
        moyenne = Calc_moyn(notes[0], notes[1], notes[2], notes[3]);
        strcpy(Etat,validation(moyenne));

        // puisque on manque l'information exacte concernant l'age de chaque étudiant
        // alors on donne a chaque étudiant un age aléatoire entre 18 et 20

        int age = (rand() % 3 + 18);
        // generation aléatoire des nbrs entre 18 et 20

        L = inser(L, nom, prenom, CNE, notes, moyenne, Etat, age);
    }

    fclose(fp);

    return L;

}


// Cette fonction insère les informations qui lui sont fournies à la queue de la liste *******************************
/* This function inserts the information given to it at the tail of the linked list */


Etudiant * inser(Etudiant * L, char nom[], char prenom[], char CNE[], float notes[], float moyenne, char Etat[], int age)
{
    Etudiant * nouveau, * tmp;

    nouveau = (Etudiant*)malloc(sizeof(Etudiant));

    strcpy(nouveau->nom, nom);
    strcpy(nouveau->prenom, prenom);
    strcpy(nouveau->CNE, CNE);
    for (int i = 0; i < 4; i++)
    {
        nouveau->notes[i] = notes[i];
    }
    nouveau->moyenne = moyenne;
    strcpy(nouveau->Etat, Etat);
    nouveau->age = age;

    nouveau->next = NULL;

    if (L==NULL)
        return nouveau;
    tmp = L;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = nouveau;

    return L;
}


//fonction qui cherche un etudiant selon son nom et prénom *******************************
/* function that searches for a specific student according to his first and last name */


void chercher_N_P(Etudiant *L)
{

    Etudiant*tmp;
    tmp=L;
    char N[20];
    char P[20];
    int c=0;

    printf("Taper le nom de l'etudiant a rechercher : ");
    getchar();
    gets(N);
    printf("Taper le prenom de l'etudiant a rechercher : ");
    gets(P);
    while(tmp!=NULL)
    {
        if(strcmp(tmp->nom,N)==0&&strcmp(tmp->prenom,P)==0)
        {
            affich_info(tmp);
            c = 1;
            break;
        }
        tmp=tmp->next;
    }

    if(c == 0)    printf("\nDesole, l'etudiant que vous avez chrche n'exist pas dans la liste des etudiants G.I S1 2022.\n");
}



//fonction qui cherche un etudiant selon son CNE **********************************************************************************
/* function that searches for a specific student according to his ID(CNE) */


void cherchCNE(Etudiant *L)
{

    Etudiant*tmp;
    tmp=L;
    char C[15];
    int a=0;

    printf("Taper le CNE de l'etudiant a rechercher : ");
    getchar();
    gets(C);
    while(tmp!=NULL)
    {
        if(strcmp(tmp->CNE,C)==0)
        {
            affich_info(tmp);
            a = 1;
            break;
        }
        tmp=tmp->next;
    }

    if(a == 0)    printf("\nDesole, l'etudiant que vous avez chrche n'exist pas dans la liste des etudiants G.I S1 2022.\n");

}


//fonction qui cherche les etudiants qui ont le meme prenom **********************************************************************************
/* function that searches for all students with the same first name */



void cherchMemeP(Etudiant *L)
{

    Etudiant*tmp;
    tmp=L;
    char P[20];
    int a=0;
    printf("Taper le prenom de l'etudiant a rechercher : ");
    getchar();
    gets(P);
    while(tmp!=NULL)
    {
        if(strcmp(tmp->prenom,P)==0)
            affich_N_P(tmp);
        a=1;
        tmp=tmp->next;
    }
    if(a=0) printf("\n\n\t\t Aucun etudiant avec ce prenom.");
}


//fonction qui cherche les etudiants qui ont le meme age **********************************************************************************
/* function that searches for all students with the same age */



void cherchMemeAge(Etudiant *L)
{

    Etudiant*tmp;
    tmp=L;
    int age,b=0;
    printf("\n\n\tTaper l'age de l'etudiant a rechercher : ");
    scanf("%d",&age);
    getchar();
    while(tmp!=NULL)
    {
        if(age == tmp->age)
        {
            printf(" %d ",tmp->age);
            affich_N_P(tmp);
            b=1;
        }

        tmp=tmp->next;
    }
    if(b=0)   printf("\nDésolé, personne de G.I S1 2022 n'a cette age!\n\n");
}


//fonction qui cherche les etudiants qui ont le meme age **********************************************************************************
/* function that searches for all students with the same age */



void cherchMemeMoyn(Etudiant *L)
{

    Etudiant*tmp;
    tmp=L;
    float moyn;
    int b=0;
    printf("\n\n\tTaper la moyenne de l'etudiant a rechercher : ");
    scanf("%f",&moyn);
    getchar();
    while(tmp!=NULL)
    {
        if(moyn == tmp->moyenne)
        {
            affich_N_P(tmp);
            b=1;
        }

        tmp=tmp->next;
    }
    if(b=0)   printf("Désolé, personne de G.I S1 2022 n'a cette moyenne!");
}


//fonction qui cherche et affiche les infos de l'étudiant ayant la plus grande moyenne **********************************************************************************
/* function that searches and displays the infos of the student with the greatest average */



void PlusGrandM(Etudiant*L)
{

    Etudiant*tmp,*ptmp;
    ptmp = tmp = L;
    float max = tmp->moyenne;

    while(tmp!=NULL)
    {
        if(tmp->moyenne > max)
        {
            max = tmp->moyenne;
            ptmp = tmp;
        }

        tmp=tmp->next;
    }
    affich_info(ptmp);

}


//fonction qui cherche et affiche les infos de l'étudiant ayant la plus petite moyenne **********************************************************************************
/* function that searches and displays the infos of the student with the smallest average */



void PlusPetiteM(Etudiant*L)
{

    Etudiant*tmp,*ptmp;
    ptmp = tmp = L;
    float min = tmp->moyenne;

    while(tmp!=NULL)
    {
        if(tmp->moyenne < min)
        {
            min = tmp->moyenne;
            ptmp = tmp;
        }

        tmp=tmp->next;
    }
    affich_info(ptmp);

}


//fonction qui calcule la moyenne des moyennes de tout les étudiants **********************************************************************************
/* this function calculates the average of the average marks of all students  */



float MoyenneDMoyenne(Etudiant*L)
{
    Etudiant*tmp = L;
    int c = 0;
    float moy=0,som=0;

    while(tmp!=NULL)
    {
        c++;
        som+=tmp->moyenne;
        tmp=tmp->next;
    }
    moy=som/c;
    return moy;
}


//fonction qui Chercher tous les étudiants qui ont une moyenne < la moyenne des moyennes **********************************************************************************
/* function that searches for all students who have an average < the average of averages */



void MoyeInf(Etudiant *L,float M)
{

    Etudiant*tmp;
    tmp=L;
    while(tmp!=NULL)
    {
        if(tmp->moyenne < M)     affich_N_P(tmp);
        tmp=tmp->next;
    }
}


//fonction qui Chercher tous les étudiants qui ont une moyenne >= la moyenne des moyennes **********************************************************************************
/* function that searches for all students who have an average >= the average of averages */



void MoyeSup(Etudiant *L,float M)
{

    Etudiant*tmp;
    tmp=L;
    while(tmp!=NULL)
    {
        if(tmp->moyenne >= M)
        {
            printf("  %.2f ",tmp->moyenne);
            affich_N_P(tmp);
        }
        tmp=tmp->next;
    }
}


//fonction qui ajoute un étudiant à la liste d'après l'utilisateur **********************************************************************************
/* function that adds a new student to the list from the user */



void ajouter_list(Etudiant*L)
{
    Etudiant*tmp;
    tmp=L;
    char nom[20];
    char prenom[20];
    char CNE[15];
    float notes[4];
    float moyenne;
    char Etat[4];
    int age,a=1;
    printf("\nEntrer le nom de l'etudiant a ajouter :");
    getchar();
    gets(nom);
    printf("\nEntrer le prenom de l'etudiant a ajouter :");
    gets(prenom);
    printf("\nEntrer le CNE de l'etudiant a ajouter :");
    gets(CNE);
    while(tmp!=NULL)
    {
        if(strcmp(tmp->CNE,CNE)==0)
        {
            printf("\nL'etudiant existe deja dans la liste.");
            a = 0;
            return 0;
        }
        tmp=tmp->next;
    }

    printf("\nEntrer la note de L'analyse :");
    scanf("%f",&notes[0]);
    getchar();
    printf("\nEntrer la note de L'algebre :");
    scanf("%f",&notes[1]);
    getchar();
    printf("\nEntrer la note des circuits logiques :");
    scanf("%f",&notes[2]);
    getchar();
    printf("\nEntrer la note de l'Architecture et Programmation Assembleur :");
    scanf("%f",&notes[3]);
    getchar();
    moyenne=Calc_moyn(notes[0],notes[1],notes[2],notes[3]);
    printf("\nEntrer l'age de l'etudiant : ");
    scanf("%d",&age);
    getchar();
    strcpy(Etat,validation(moyenne));
    L=inser(L, nom, prenom, CNE, notes, moyenne, Etat, age);
    ajouter_file(L,nom,prenom,CNE,notes);
    if(a) printf("\n\tL'etudiant est ajoute avec succes.\n");

}


//fonction qui supprime un étudiant de la liste chainée **********************************************************************************
/* function that delets student from the linked list */



int supprimer_list(Etudiant*L,char C[])
{
//cette fct retourne 1 si la suppression est terminée avec succes, si non elle retourne 0

    Etudiant*tmp,*ptmp;
    ptmp = tmp = L;
    int c=0;

    while(tmp!=NULL)
    {
        if(strcmp(tmp->CNE,C)==0)
        {
            c = 1;
            break;
        }

        ptmp=tmp;
        tmp=tmp->next;
    }

    if(c == 0)
    {
        printf("Desole, l'etudiant que vous avez chrché n'exist pas dans la liste des etudiants G.I S1 2022.");
        return 0;
    }

    ptmp->next=tmp->next;
    free(tmp);
    supprimer_file(C);

    return 1;
}


//fonction qui ajoute les infos d'un étudiant à un fichier **********************************************************************************
/* function that adds a new student's infos to a file */



int ajouter_file(Etudiant * L, char nom[], char prenom[], char CNE[], float notes[])
{
    FILE * fp;

    fp = fopen("GI_DS_S1_infos.txt","a");
    if (fp == NULL)
    {
        printf("Error opening file 99\n");
        return 0;
    }
    fprintf(fp, "%s %s %s %f %f %f %f\n", CNE, nom, prenom, &notes[0], &notes[1], &notes[2], &notes[3]);
    fclose(fp);
    return 1;
}


//fonction qui supprime les infos d'un étudiant dans un fichier **********************************************************************************
/* function that delets a student's infos from a file */



int  supprimer_file(char C[])
{
    FILE *fp, *ftmp;
    char line[100];
    int sizeC = strlen(C);

    // Ouvrir le fichier d'origine en mode "read"
    fp = fopen("GI_DS_S1_infos.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening the file 28.\n");
        exit (0);
    }

    // Ouvrir un fichier temporaire en mode "write"
    ftmp = fopen("temp.txt", "w");
    if (ftmp == NULL)
    {
        printf("Error creating the temporary file.\n");
        exit(1);
    }

    // Lire chaque ligne du fichier d'origine et écrire les lignes non correspondantes
    // dans le fichier temporaire

    while (fgets(line, 100, fp))
    {
        if (strncmp(line, C, sizeC) != 0)       fputs(line, ftmp);
    }

    // fermer les deux fichiers
    fclose(fp);
    fclose(ftmp);

    // supprimer le fichier originale
    remove("GI_DS_S1_infos.txt");

    // Renamer le fichier temporaire par le nom du fichier originale
    rename("temp.txt", "GI_DS_S1_infos.txt");

    return 0;
}


//fonction pour trier la liste par ordre alphabétique ***************************************
/*function to sort the list in alphabetical order */




Etudiant* trie_alpha(Etudiant* L)
{
    Etudiant *current, *prev, *tmp, *next2;
    int swapped;

    if (L == NULL)
    {
        return NULL;
    }

    do
    {
        swapped = 0;
        prev = NULL;
        current = L;

        while (current->next != NULL)
        {
            next2 = current->next;
            if (strcmp(current->nom, next2->nom) > 0)
            {
                tmp = current->next;
                current->next = tmp->next;
                tmp->next = current;

                if (prev == NULL)
                {
                    L = tmp;
                }
                else
                {
                    prev->next = tmp;
                }

                prev = tmp;
                swapped = 1;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
    }
    while (swapped);

    return L;
}


//fonction pour insérer un nouvel étudiant dans la liste et le garder dans l'ordre alphabétique ***************************************
/*function to insert a new student in the list and keep it ordered in alphabetical order */



Etudiant * inser_trie(Etudiant * L, char nom[], char prenom[], char CNE[], float notes[], float moyenne, char Etat[], int age)
{

    Etudiant * nouveau, *tmp, *prev;

    nouveau = (Etudiant*)malloc(sizeof(Etudiant));

    strcpy(nouveau->nom, nom);
    strcpy(nouveau->prenom, prenom);
    strcpy(nouveau->CNE, CNE);
    for (int i = 0; i < 4; i++)
    {
        nouveau->notes[i] = notes[i];
    }
    nouveau->moyenne = moyenne;
    strcpy(nouveau->Etat, Etat);
    nouveau->age = age;

    nouveau->next = NULL;

    if (L == NULL || strcmp(L->nom, nom) > 0)
    {
        nouveau->next = L;
        return nouveau;
    }

    tmp = L->next;
    prev = L;
    while (tmp != NULL && strcmp(tmp->nom, nom) < 0)
    {
        prev = tmp;
        tmp = tmp->next;
    }

    prev->next = nouveau;
    nouveau->next = tmp;
    return L;
}


//Fonction pour trier les étudiants par moyenne dans l'ordre décroissant ***************************************
/*Function To Sort The students By average In Descending Order */



Etudiant * trie_moyn_decroi(Etudiant * L)
{
    Etudiant * current, * prev, * next;
    int is_sorted = 0;

    // Iterate until the list is sorted
    while (!is_sorted)
    {
        is_sorted = 1;
        current = L;
        prev = NULL;
        while (current->next != NULL)
        {
            next = current->next;

            // If the current node's moyenne is less than the next node's moyenne, swap them
            if (current->moyenne < next->moyenne)
            {
                is_sorted = 0;

                if (prev != NULL)
                {
                    prev->next = next;
                }
                else
                {
                    L = next;
                }

                current->next = next->next;
                next->next = current;

                prev = next;
            }
            else
            {
                prev = current;
                current = next;
            }
        }
    }

    return L;
}


//Fonction pour trier les étudiants par moyenne dans l'ordre croissant ***************************************
/*Function To Sort The students By average In ascending Order */



Etudiant * trie_moyn_croi(Etudiant * L)
{
    Etudiant * current, * prev, * next;
    int is_sorted = 0;

    // Iterate until the list is sorted
    while (!is_sorted)
    {
        is_sorted = 1;
        current = L;
        prev = NULL;
        while (current->next != NULL)
        {
            next = current->next;

            // If the current node's average is greater than the next node's average, swap them

            if (current->moyenne > next->moyenne)
            {
                is_sorted = 0;

                if (prev != NULL)
                {
                    prev->next = next;
                }
                else
                {
                    L = next;
                }

                current->next = next->next;
                next->next = current;

                prev = next;
            }
            else
            {
                prev = current;
                current = next;
            }
        }
    }

    return L;
}
