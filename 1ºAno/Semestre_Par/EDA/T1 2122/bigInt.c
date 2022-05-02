#include "bigInt.h"

struct BigInt {
    char* number;
    int size;
};

int* tranfosrmCharInt(BigInt a) {
    int* result = malloc(a->size);

    for(int i = 0; i < a->size; i++) {
        result[i] = (int)a->number[i] - '0';    
    }

    return result;
}

BigInt big_new(char* num) {
    BigInt new = calloc(1, sizeof(BigInt));

    new->number = num;

    int sz = 0;
    for(int i = 0; num[i] != '\0'; i++) {
        sz++;
    }

    new->size = sz;

    return new;
}

BigInt sum_b(BigInt a, BigInt b) {
    if(a->size > b->size) {
        int aux = a->size - b->size + 1;
        
        int sza = a->size + 1;
        int szb = a->size + aux; 

        DList aList = CreateDList();
        DList bList = CreateDList();

        addDList(0, aList);
        for(int i = 0; i < a->size; i++)
            addDList((int)a->number[i] - '0', aList);

        for(int i = 0; i < aux; i++)
            addDList(0, bList);

        for(int i = 0; i < b->size; i++)
            addDList((int)b->number[i] - '0', bList);

        PrintDList("tommy", aList);
        PrintDList("daniels", bList);


    } else if(a->size < b->size) {
        int aux = a->size - b->size + 1;

        int sza = b->size + aux; 
        int szb = b->size + 1;

    } else if(a->size == b->size) {
        int sza = a->size + 1;
        int szb = b->size + 1;

    }
}

BigInt sub_b(BigInt a, BigInt b) {}

BigInt mult_b(BigInt a, BigInt b) {}

BigInt div_b(BigInt a, BigInt b) {}

BigInt mod_b(BigInt a, BigInt b) {}

void print_b(BigInt a) {
    printf("%s\n", a->number);
}

// <nome do bigInt>->number para teres o array
// <nome do bigInt>->size para teres o size

int main() {
    BigInt a = big_new("123456");
    BigInt b = big_new("126");
    sum_b(a, b);
}
