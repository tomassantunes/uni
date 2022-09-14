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

    unsigned char array[MAXLINES][100];
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
    
    for(int i = 0; i < dims[0]; i++) {
        printf("%s\n", array[n + i]);
    }
}

int main() {
    char* filename = "smallPuzzle.txt";
    
    char ns[10];
    FILE *file = fopen(filename, "r");
    int n = strtol(fgets(ns, sizeof(ns), file), (char**) NULL, 10);

    words = create_table(n * 2);
    prefixos = create_table(n * 10);

    readWords(filename);
    print_table(words);

    readPrefixes(filename);
    print_table(prefixos);

    printBoard(filename);
}