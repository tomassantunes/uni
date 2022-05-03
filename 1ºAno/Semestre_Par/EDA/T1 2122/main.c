#include <stdio.h>
#include "bigInt.c"

int main() {
    BigInt a = big_new("1823718937183291");
    BigInt b = big_new("-1283128931273812");
    BigInt test = mult_b(a, b);
    print_b(test);
}
