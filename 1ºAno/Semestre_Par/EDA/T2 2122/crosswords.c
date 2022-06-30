#include "crosswords.h"

HashTable* words;
HashTable* prefixos;

int MAXLINES = 100;

char** board;

void readWords(char* filename) {
    FILE *file = fopen(filename, "r");

    if(file == 0)
        exit(1);

    char array[MAXLINES][100];
    int i = 0;

    while(i < MAXLINES && fgets(array[i], sizeof(array[0]), file)) {
        array[i][strlen(array[i]) - 1] = '\0';
        i++;
    }

    fclose(file);

    int n = (int) strtol(array[0], (char**) NULL, 10);

    for(int i = 2; i < n + 2; i++) {
        ht_insert(words, i - 2, array[i]);
    }
}

void readPrefixes(char* filename) {
    FILE *file = fopen(filename, "r");

    if(file == 0)
        exit(1);

    char array[MAXLINES][100];
    int i = 0;

    while(i < MAXLINES && fgets(array[i], sizeof(array[0]), file)) {
        array[i][strlen(array[i]) - 1] = '\0';
        i++;
    }

    fclose(file);

    int n = (int) strtol(array[0], (char**) NULL, 10);
    int k = 0;

    for(int i = 2; i < n + 2; i++) {
        int j = 0;
        char c[100] = "";
        strncat(c, &array[i][0], 1);
        while(array[i][j++] != '\0') {
            ht_insert(prefixos, k++, c);
            strncat(c, &array[i][j], 1);
        }
    }
}

void printBoard(char* filename) {
    FILE *file = fopen(filename, "r");

    if(file == 0)
        exit(1);

    char array[MAXLINES][100];
    int i = 0;

    while(i < MAXLINES && fgets(array[i], sizeof(array[0]), file)) {
        array[i][strlen(array[i]) - 1] = '\0';
        i++;
    }

    fclose(file);

    int n = (int) strtol(array[0], (char**) NULL, 10);
    n += 2;

    int dims[2];
    dims[0] = (int) strtol(strtok(array[n], " "), (char**) NULL, 10);
    dims[1] = (int) strtol(strtok(NULL, " "), (char**) NULL, 10);

    n++;

    printf("   ");
    for(int i = 0; i < dims[1]; i++) {
        if(i < 10)
            printf("  %d", i + 1);
        else
            printf(" %d", i + 1);
    }

    printf("\n  ");
    for(int i = 0; i < dims[1]; i++)
        printf(" -");

    printf("\n");

    for(int i = 0; i < dims[0]; i++) {
        if(i < 10)
            printf(" %d |", i);
        else
            printf("%d |", i);

        for(int j = 0; j < dims[1]; j++) {
            printf(" %c", array[n + i][j]);
        }
        printf(" |\n");
    }

}

int main() {
    int n = 16;
    char* board[16];

    words = create_table(n * 2);
    prefixos = create_table(n * 10);
    
    char* filename = "smallPuzzle.txt";

    readWords(filename);

    readPrefixes(filename);

    printBoard(filename);
}