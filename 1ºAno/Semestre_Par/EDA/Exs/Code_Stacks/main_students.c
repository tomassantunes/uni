//
//  Complete o programa para que seja possível, ler uma
//  expressão em infix e fazer a conversão para postfix
//  usando o algoritmo dexcrito nas aulas teóricas
//
//
//  Created by Ligia Ferreira on 12/03/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fatal.h"


int priority(char c){
   // to be done
    return 1;
}


char *ler_input(){
    static char name[100];
    printf("Os tokens devem aprearecer separados por espaço \n");
    
    printf("Exemplo ( 2 + 6 ) * 10 \n");
    printf("infix : ");
    scanf("%[^\n]s",name);
    return name;
}


int isNumber(char *token){
   
    return 0;
}

char *tostring(char x){
    static char toReturn[2];
    toReturn[0]=x;
    toReturn[1]='\0';
    return toReturn;
}

// usar strtok para tokenizar a string input
// usar strcat pata concatenar strings

void conversion(char input[], char output[]){
    
    char* token;
    output[0]='\0';
    token=strtok(input," ");
    while (token !=NULL){
        printf("token %s\n",token);
        //algoritmo aqui...
    
        token=strtok(NULL," ");
    }
}

int main(int argc, const char * argv[]) {
  
    char* infix;
    
    infix=ler_input();
    char postfix[strlen(infix)];
    conversion(infix, postfix);
    printf("postfix-> %s\n",postfix);
    
    return 0;
}