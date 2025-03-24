#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAX_LOCUTION_LEN 100

/*
Génére un nombre aléatoire compris entre deux bornes

\param b1 : borne minimale
\param b2 : borne maximale

\return un entier aléatoire compris entre b1 et b2
*/
int my_random(int b1, int b2)
{
    return rand() % (b2 - b1 + 1) + b1;
}

/*
Copie une chaîne de caractère à la fin d'une autre chaîne de caractère

\param src : chaîne de caractère source à copier sur dst
\param dst : chaîne de caractère destination à laquelle on ajoutera src

\note dst est supposé suffisamment grand pour contenir dst + src
*/
void str_append(const char *src, char *dst)
{
    int i, j;

    for (i = 0; dst[i] != '\0'; i++){;}
    
    for (j = 0; src[j] != '\0'; j++)
    {
        dst[i + j] = src[j];
    }
    dst[i + j] = '\0';
}

/*
Ajoute une locution aléatoire issue d'un fichier texte à la fin d'une chaîne de caractères

\param file_name : chemin du fichier contenant les locutions
\param sentence : chaîne de caractères à compléter avec la locution
*/
void append_random_locution(const char *file_name, char *sentence)
{
    FILE *file = NULL;
    int nb_locution, i_chosen_locution;
    char locution[MAX_LOCUTION_LEN];

    file = fopen(file_name, "r");
    if (NULL == file)
    {
        printf("Error : unable to open file '%s'\n");
        return;
    }

    fscanf(file, "%d ", &nb_locution);
    i_chosen_locution = my_random(0, nb_locution-1);

    do
    {
        fscanf(file, " %[^\n]", locution);
        i_chosen_locution--;
    }while (i_chosen_locution >= 0);
    
    fclose(file);
    
    str_append(locution, sentence);
}

int main(void)
{
    char bullshit_sentence[4*MAX_LOCUTION_LEN];
    
    srand(time(0));

    append_random_locution("locutions/subjects", bullshit_sentence);
    append_random_locution("locutions/verbs", bullshit_sentence);
    append_random_locution("locutions/objects", bullshit_sentence);
    append_random_locution("locutions/conclusions", bullshit_sentence);
    
    printf("%s\n", bullshit_sentence);
    
    return EXIT_SUCCESS;
}