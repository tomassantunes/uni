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
    DList aList = CreateDList();
    DList bList = CreateDList();
    if(a->size > b->size) {
        int aux = a->size - b->size + 1;
        
        addDList(0, aList);
        for(int i = 0; i < a->size; i++)
            addDList((int)a->number[i] - '0', aList);

        for(int i = 0; i < aux; i++)
            addDList(0, bList);

        for(int i = 0; i < b->size; i++)
            addDList((int)b->number[i] - '0', bList);

    } else if(a->size < b->size) {
        int aux = b->size - a->size + 1;
        
        addDList(0, bList);
        for(int i = 0; i < b->size; i++)
            addDList((int)b->number[i] - '0', bList);

        for(int i = 0; i < aux; i++)
            addDList(0, aList);

        for(int i = 0; i < a->size; i++)
            addDList((int)a->number[i] - '0', aList);

    } else if(a->size == b->size) {
        addDList(0, aList);
        addDList(0, bList);

        for(int i = 0; i < a->size; i++) {
            addDList((int)a->number[i] - '0', aList);
            addDList((int)b->number[i] - '0', bList);
        }
    }

    int sz = SizeDList(aList);
    int sum[sz], tmp;
    for(int i = 0; i < sz; i++) {
        sum[i] = 0;
    }


    DPosition ita = aList->last;
    DPosition itb = bList->last;

    for(int i = sz - 1; i >= 0; i--) {
        if(ita == NULL || itb == NULL) { break; }
        tmp = ita->data + itb->data;
        
        if(tmp >= 10) {
            tmp -= 10;
            sum[i-1]++;
        }

        sum[i] += tmp;
        if(sum[i] >= 10) {
            sum[i] -= 10;
            sum[i-1]++;
        }
        ita = ita->prev;
        itb = itb->prev;
    }

    char result[sz];
    for(int i = 0; i < sz; i++)
        result[i] = (char)(sum[i] + '0');
    
    BigInt resultBig = big_new(result);
    return resultBig;

}

BigInt sub_b(BigInt a, BigInt b) {
    DList aList = CreateDList();
    DList bList = CreateDList();
    if(a->size > b->size) {
        int aux = a->size - b->size + 1;
        
        addDList(0, aList);
        for(int i = 0; i < a->size; i++)
            addDList((int)a->number[i] - '0', aList);

        for(int i = 0; i < aux; i++)
            addDList(0, bList);

        for(int i = 0; i < b->size; i++)
            addDList((int)b->number[i] - '0', bList);

    } else if(a->size < b->size) {
        int aux = b->size - a->size + 1;
        
        addDList(0, bList);
        for(int i = 0; i < b->size; i++)
            addDList((int)b->number[i] - '0', bList);

        for(int i = 0; i < aux; i++)
            addDList(0, aList);

        for(int i = 0; i < a->size; i++)
            addDList((int)a->number[i] - '0', aList);

    } else if(a->size == b->size) {
        addDList(0, aList);
        addDList(0, bList);

        for(int i = 0; i < a->size; i++) {
            addDList((int)a->number[i] - '0', aList);
            addDList((int)b->number[i] - '0', bList);
        }
    }
}

BigInt mult_b(BigInt a, BigInt b) {
    
}

BigInt div_b(BigInt a, BigInt b) {}

BigInt mod_b(BigInt a, BigInt b) {} // sub ate <= que b

void print_b(BigInt a) {
    printf("%s\n", a->number);
}

int main() {

}
