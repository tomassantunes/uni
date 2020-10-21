#include <stdio.h>

int main(){

    float raio, perimetro, area, volume;
    float pi=3.141593;

    printf("raio: ");
    scanf("%f", &raio);

    perimetro = 2 * pi * raio;
    printf("perimetro: %f \n", perimetro);

    area = pi * (raio * raio);
    printf("área: %f \n", area);

    volume = (4 * pi * (raio * raio * raio)) / 3;
    printf("volume: %f \n", volume);

    return 0;
}