#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOCUTION_LEN 100

/*
Génére un nombre aléatoire compris entre deux bornes

\param b1 borne minimale
\param b2 borne maximale

\return un entier aléatoire compris entre b1 et b2
*/
int my_random(int b1, int b2)
{
    return rand() % (b2 - b1 + 1) + b1;
}

/*
Affiche une locution aléatoire issue d'un fichier texte

\param file_name chemin du fichier contenant les locutions
*/
void print_random_locution(const char *file_name)
{
    int nb_locution, i_chosen_locution;
    char locution[MAX_LOCUTION_LEN];
    
    FILE *file = fopen(file_name, "r");
    if (!file)
    {
        printf("Error : unable to open file '%s'\n", file_name);
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d ", &nb_locution);
    i_chosen_locution = my_random(0, nb_locution-1);

    do
    {
        fscanf(file, " %[^\n]", locution);
        i_chosen_locution--;
    }while (i_chosen_locution >= 0);
    
    fclose(file);

    printf("%s", locution);
}

int main(int argc, char *argv[])
{
    int nb_sentence = (argc == 2) ? strtof(argv[1], NULL) : 1;

    srand(time(0));

    for (int i = 0; i < nb_sentence; i++)
    {
        print_random_locution("locutions/subjects");
        print_random_locution("locutions/verbs");
        print_random_locution("locutions/objects");
        print_random_locution("locutions/conclusions");
        printf("\n");
    }

    return EXIT_SUCCESS;
}