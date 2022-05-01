#include "bigInt.h"

struct BigInt {
    char* number;
    int size;
};

int[] tranfosrmCharInt(BigInt a) {
    int result[a->size];

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
    int[] firstNum = tranfosrmCharInt(a);
    int[] secondNum = tranfosrmCharInt(b);
    int sz1 = a->size, sz2 = b->size;

    if(sz1 > sz2) {
        int aux = sz1 - sz2 + 1;
        
        sz1++;
        sz2 += aux;

        int arr3[sz1], arr4[sz2];
        arr3[0] = 0;

        for(int i = 0; i < aux; i++) {
            arr4[i] = 0;
        }

        for(int i = 1; i < sz1; i++) {
            arr3[i] = firstNum[i-1];
        }


        for(int i = aux; i < sz2; i++) {
            arr4[i] = secondNum[i-aux];
        }
    } else {
        int aux = sz2 - sz1 + 1;
        
        sz1 += aux;
        sz2++;

        int arr3[sz1], arr4[sz2];
        arr4[0] = 0;

        for(int i = 0; i < aux; i++) {
            arr3[i] = 0;
        }

        for(int i = aux; i < sz2; i++) {
            arr3[i] = firstNum[i-aux];
        }

        for(int i = 1; i < sz1; i++) {
            arr4[i] = secondNum[i-1];
        }
    }

    int sum[sz1], tmp;
    for(int i = 0; i < sz1; i++) 
        sum[i] = 0;

    for(int i = sz1 - 1; i >= 0; i--) {
        tmp = arr3[i] + arr4[i];
        if(tmp >= 10) {
            tmp -= 10;
            sum[i-1]++;
        }
        
        sum[i] += tmp;
    }

    char result[sz1];
    for(int i = 0; i < sz1; i++)
        result[i] = (char)(sum[i] + '0');

    BigInt resultBig = big_new(result);
    return resultBig;
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
