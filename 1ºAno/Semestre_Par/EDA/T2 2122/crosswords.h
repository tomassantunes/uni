#include <stdio.h>
#include "hash_table.c"
#include "string.h"
#include "wchar.h"


// direções:
// 0 -> E
// 1 -> SE
// 2 -> S
// 3 -> SO
// 4 -> O
// 5 -> NO
// 6 -> N
// 7 -> NE

void readWords(char* filename);
void readPrefixes(char* filename);
void printBoard(char* filename);