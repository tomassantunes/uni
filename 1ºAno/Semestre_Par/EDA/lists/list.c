#include "list.h"
#include <stdlib.h>
//#include <stdbool.h>
#include <stdio.h>
#include "fatal.h"


struct Node{
    ElementType Element;
    Position    Next;
};


List MakeEmpty( List L ){
    if( L != NULL ){
        DeleteList( L ); // se a lista estiver a apontar para algo na memória
    } else {             // chamamos a função DeleteList
        L = malloc( sizeof( struct Node )); // se a lista não estiver a apontar para nada 
        if( L == NULL )                     // na memória, temos que alocar espaço para a
            FatalError("Out of memory!");   // mesma, e depois remover os elementos
        L->Next = NULL;                     // fazendo com o que os próximos elementos não apontem para a memória
    }
}

bool IsEmpty( List L ){
    return L->Next == NULL; // verificar se não está a apontar para nenhum valor na memória
}                           

bool IsLast( Position P, List L ){
    return P->Next == NULL; // verificar se é a última posição na lista,
}                           // comparando o valor para que este indíce 
                            // está a apontar na memória. sendo que se for nenhum, este é o último.

Position Find( ElementType X, List L ){ // encontrar a posição do elemento X na Lista
    Position P;                             
    P = First( L ); // definir a posição no início da lista

    while( P != NULL && P->Element != X ){ // sendo que o elemento na posição P aponta para um valor na memória
        P = P->Next;                       // e não é igual ao elemento X, ir para o próximo.
    }
    
    return P;
}


Position FindPrevious( ElementType X, List L ) { // encontrar o elemento anterior
    Position P;
    P = Header( L );

    while( P->Next != NULL &&P->Next->Element != X ){
        P = P->Next;
    }

    return P;
}


void Insert( ElementType X, List L, Position P ) { // inserir X como elemento seguinte na posição P
    Position tmp;

    tmp = malloc( sizeof(struct Node) ); // alocar espaço na memória para a variável temporária
    
    if(tmp == NULL)
        FatalError("Out of memory!");

    tmp->Element = X;
    tmp->Next = P->Next;
    P->Next = tmp;
}

void Delete( ElementType X, List L ){ // apagar o elemento X na lista L
    Position P, tmp;
    P = FindPrevious(X, L);
    if( !IsLast(P, L) ){
        tmp = P->Next;
        P->Next = tmp->Next;
        free(tmp);
    }
}


void DeleteList( List L ) { // apagar a lista inteira
    Position P, tmp;

    P = First(L);
    L->Next = NULL;
    while( P != NULL ){
        tmp = P->Next;
        free(P);
        P = tmp;
    }
}


Position Header( List L ) {
    return L;
}


Position First( List L ) { // primeiro elemento da lista
    return L->Next;
}


Position Advance( Position P ) { // ir para o próximo elemento
    return P->Next;
}


ElementType Retrieve( Position P ) { // mostrar o elemento na posição P da lista
    return P->Element;
}

int main() {
    
}