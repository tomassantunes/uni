#include "bigInt.h"

#define rep(i,n) for(i=0;i<n;i++)
#define N 156

struct BigInt {
    DList number;
    bool negative;
};

BigInt big_new(char* num) {
    int i;
    BigInt new = calloc(1, sizeof(BigInt));
    new->number = CreateDList();

    if(num[0] == '-') {
        new->negative = true;
        i = 1;
    } else {
        new->negative = false;
        i = 0;
    }

    for(i; num[i] != '\0'; i++) {
        addDList((int)num[i] - '0', new->number);
    }

    return new;
}

int BigIntGreater(BigInt a, BigInt b) {
    if((SizeDList(a->number) > SizeDList(b->number) || (SizeDList(a->number) == SizeDList(b->number) && a->number->first->data > b->number->first->data))) {
        return 1;
    }
    return 0;
}

int BigIntGreaterEqual(BigInt a, BigInt b) {
    if((SizeDList(a->number) >= SizeDList(b->number) || (SizeDList(a->number) == SizeDList(b->number) && a->number->first->data >= b->number->first->data))) {
        return 1;
    }
    return 0;
}

int BigIntEqual(BigInt a, BigInt b) {
    DPosition ita = a->number->first;
    DPosition itb = b->number->first;
    
    if(SizeDList(a->number) != SizeDList(b->number)) { return 0; }
    while(ita != NULL && itb != NULL) {
        if(ita->data != itb->data) {
            return 0;
        }
        ita = ita->next;
        itb = itb->next;
    }
    
    return 1;
}

BigInt BigIntCpy(BigInt src, BigInt dest) {
    if(!IsEmptyDList(dest->number)) {
        MakeEmptyDList(dest->number);
    }

    DPosition ita = src->number->first;
    while(ita != NULL) {
        addDList(ita->data, dest->number);
        ita = ita->next;
    }
    return dest;
}

int* BigIntToArr(BigInt src) {
    int sz = SizeDList(src->number);
    int* result = malloc(sz * sizeof(int));
    DPosition ita = src->number->first;
    
    for(int i = 0; i < sz && ita != NULL; i++) {
        result[i] = ita->data;
        ita = ita->next;
    }

    return result;
}

BigInt ArrToBigInt(int* src, int sz) {
    char* conv = malloc(sz * sizeof(char));
    int j = 0;
    while(src[j] == 0) { j++; }

    for(int i = 0; i < sz; i++) {
        if(j < sz)
            conv[i] = (char)src[j] + '0';
        j++;
    }

    BigInt result = big_new(conv);
    return result;
}

void ClearZero(BigInt a) {
    if(IsEmptyDList(a->number)) {
        printf("List is empty.");
        exit(0);
    }

    while(a->number->first->data == 0 && a->number->first != NULL) {
        a->number->first = a->number->first->next;
        a->number->first->prev = NULL;
    }
}

BigInt sum_b(BigInt a, BigInt b) {
    if(a->negative && b->negative) {
        a->negative = false;
        b->negative = false;

        BigInt result = sum_b(a, b);
        result->negative = true;

        return result;
    }

    if(BigIntGreater(a, b)) {
        if(!a->negative && b->negative) {
            b->negative = false;
        
            BigInt result = sub_b(a, b);
        
            return result;
        }
    
        if(a->negative && !b->negative) {
            a->negative = false;
            
            BigInt result = sub_b(a, b);
            result->negative = true;

            return result;
        }
    } else {
        if(!a->negative && b->negative) {
            b->negative = false;

            BigInt result = sub_b(b, a);
            result->negative = true;

            return result;
        }

        if(a->negative && !b->negative) {
            a->negative = false;

            BigInt result = sub_b(b, a);

            return result;
        }
    }

    if(SizeDList(a->number) > SizeDList(b->number)) {
        int aux = SizeDList(a->number) - SizeDList(b->number) + 1;
        
        InsertDListIth(0, 0, a->number);

        for(int i = 0; i < aux; i++)
            InsertDListIth(0, 0, b->number);

    } else if(SizeDList(a->number) < SizeDList(b->number)) {
        int aux = SizeDList(b->number) - SizeDList(a->number) + 1;
        
        InsertDListIth(0, 0, b->number);

        for(int i = 0; i < aux; i++)
            InsertDListIth(0, 0, a->number);

    } else if(SizeDList(a->number) == SizeDList(b->number)) {
        InsertDListIth(0, 0, a->number);
        InsertDListIth(0, 0, b->number);
    }


    int sz = SizeDList(a->number)-1;
    int sum[sz], tmp;
    for(int i = 0; i < sz; i++) {
        sum[i] = 0;
    }


    DPosition ita = a->number->last;
    DPosition itb = b->number->last;
    
    if(!a->negative && !b->negative) {
        for(int i = sz - 1; i >= 0; i--) {
            if(ita == NULL || itb == NULL) { break; }
        
            if(!a->negative && !b->negative) {
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
        }
    }

    char result[sz];
    int i = 0;
    while(sum[i] == 0)
        i++;
    for(int j = 0; j < sz; j++) { 
        if(i < sz)
            result[j] = (char)(sum[i] + '0'); 
        i++;
    }
    BigInt resultBig = big_new(result);
    return resultBig;
}

BigInt sub_b(BigInt a, BigInt b) {
    int sza = SizeDList(a->number);
    int szb = SizeDList(b->number);
    if(sza > szb) {
        int aux = SizeDList(a->number) - SizeDList(b->number) + 1;
        
        InsertDListIth(0, 0, a->number);

        for(int i = 0; i < aux; i++)
            InsertDListIth(0, 0, b->number);

    } else if(sza < szb) {
        int aux = SizeDList(a->number) - SizeDList(b->number) + 1;
        
        InsertDListIth(0, 0, b->number);

        for(int i = 0; i < aux; i++)
            InsertDListIth(0, 0, a->number);

    } else if(sza == szb) {
        InsertDListIth(0, 0, a->number);
        InsertDListIth(0, 0, b->number);
    } 

    int sz;
    if(SizeDList(a->number) > SizeDList(b->number))
        sz = SizeDList(a->number);
    else
        sz = SizeDList(b->number); 
    int sub[sz];
    
    if(!a->negative && !b->negative) {
        if(sza > szb || (sza == szb && a->number->first->data >= b->number->first->data)) {
            DPosition it = a->number->first;
            for(int i = 0; i < sz && it != NULL; i++) {
                sub[i] = it->data;
                it = it->next;
            }

            DPosition itb = b->number->last;
            int tmp;
            for(int i = sz - 1; i >= 0; i--) {
                if(itb == NULL) { break; }
                tmp = sub[i] - itb->data;
                if(tmp < 0) {
                    tmp += 10;
                    sub[i-1]--;
                }
                sub[i] = tmp;
                itb = itb->prev;
            }

        } else {
            BigInt result = sub_b(b, a);
            result->negative = true;
            return result;
        }
    }
    char resultSub[sz];
    int j = 0;
    while(sub[j] == 0)
        j++;

    for(int i = 0; i < sz; i++) {
        if(j < sz)
            resultSub[i] = (char)(sub[j] + '0'); 
        j++;
    }

    BigInt resultSubBig = big_new(resultSub);
    return resultSubBig;
}

BigInt mult_b(BigInt a, BigInt b) {
    int* aArr = BigIntToArr(a);
    int* bArr = BigIntToArr(b);

    int szc = SizeDList(a->number) + SizeDList(b->number);
    int* c = malloc((szc) * sizeof(int));
    for(int i = 0; i < szc; i++) { c[i] = 0; }

    int i = SizeDList(a->number) - 1, j = SizeDList(b->number) - 1, k = szc - 1;
    int carry = 0, tmp, push_left = 0;
    while(i >= 0) {
        k = szc - 1 - push_left++;
        j = SizeDList(b->number) - 1;
        while(j >= 0 || carry > 0) {
            if(j >= 0) {
                tmp = aArr[i] * bArr[j];
            } else { tmp = 0; }

            tmp += carry;
            carry = tmp / 10;
            c[k] += tmp % 10;
            carry += c[k] / 10;
            c[k] %= 10;
            j--; k--;
        }
        i--;
    }
    
    BigInt result = ArrToBigInt(c, szc);
    if((a->negative && !b->negative) || (!a->negative && b->negative)) { result->negative = true; }
    return result;
}

BigInt div_b(BigInt a, BigInt b) {} 

BigInt mod_b(BigInt a, BigInt b) {}

void print_b(BigInt a) {
    if(a->negative)
        printf("-");

    PrintDList(".", a->number);
}
