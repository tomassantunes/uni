#include "crosswords.h"

HashTable* words;
HashTable* prefixos;

char** board;

void readWords(char* filename) {
    char array[50][40];

    FILE *file = fopen(filename, "r");

    int i = 0;

    char *word;
    while(fgets(word, 40, file) != NULL)
        strcpy(array[i], strdup(word));
    
    fclose(file);

    printf("%s\n", array[0]);

    for(int i = 2; i < 17; i++)
        ht_insert(words, i-2, array[i]);

}

void readPrefixes(char* filename) {
    FILE *file = fopen(filename, "r");
}


int main() {
    int n = 16;
    char* board[16];

    words = create_table(n * 2);
    prefixos = create_table(n * 10);
    
    char* filename = "smallPuzzle.txt";

    readWords(filename);

    print_table(words);
}