#include <stdio.h>

int horasMin(int min){
    if(min > 1440){
        return 1;
    } else {
        return 0;
    }
}

int main(){
    int min;

    printf("minutos: ");
    scanf("%d", &min);

    int horas = min / 60;
    int minutos = min % 60;

    if(horasMin(min) == 1){
        printf("%d minutos correspondem a %dh:%dmin; e superior a um dia.\n", min, horas, minutos);        
    } else {
        printf("%d minutos correspondem a %dh:%dmin; nao e superior a um dia.\n", min, horas, minutos);
    }
«}