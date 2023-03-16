#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "queue.h"
#include "fatal.h"


#define MinQueueSize ( 5 )

struct QueueRecord{
    int Capacity;
    int Front;
    int Rear;
    ElementType *Array;
};


/* FUNCOES AUXILIARES */
/* numero de elementos na fila */
int size( Queue Q ){
    return ( Q->Capacity - Q->Front + Q->Rear ) % Q->Capacity;
}


/* indice do proximo elemento  */
int successor( int i, Queue Q ){
    if (i == Q->Capacity - 1){
        return 0;
    } else {
        return i + 1;
    }
}



/* FUNCOES DE MANIPULACAO DE QUEUES */
Queue CreateQueue( int MaxElements ){
    Queue Q;

    if( MaxElements < MinQueueSize )
        Error( "Queue size is too small" );

    Q = malloc( sizeof( struct QueueRecord ) );
    if( Q == NULL )
        FatalError( "Out of space!!!" );

    Q->Array = malloc( sizeof( ElementType ) * MaxElements );
    if( Q->Array == NULL )
        FatalError( "Out of space!!!" );

    Q->Capacity = MaxElements+1;
    MakeEmptyQueue( Q );

    return Q;
}


void DisposeQueue( Queue Q ){
    if( Q != NULL ){
        free( Q->Array );
        free( Q );
    }
}


bool IsEmptyQueue( Queue Q ){ // verificar se a queue estiver vazia
    return Q->Front == Q->Rear; // se o front e o rear forem iguais a queue está vazia
}                               


bool IsFullQueue( Queue Q ){ // verificar se a queue está cheia
    return size( Q ) == Q->Capacity - 1;
}


void MakeEmptyQueue( Queue Q ){ // esvaziar a queue
    Q->Front = 0; // para esvaziar a queue temos de dar reset
    Q->Rear = 0;  // às variáveis front e rear, dando-lhes o valor 0
}


void Enqueue( ElementType X, Queue Q ){ // adicionar um elemento à queue
    if(IsFullQueue(Q))
        Error("Queue is already full.");
    Q->Array[Q->Rear] = X; // definir o último elemento (na posição rear)
    Q->Rear = successor(Q->Rear, Q); // definir o próximo índice com a função successor
}


ElementType Front( Queue Q ){ // mostrar o primeiro elemento da queue
    if(IsEmptyQueue(Q))
        Error("Queue is empty.");
    return Q->Array[Q->Front];
}


ElementType Dequeue( Queue Q ){ // remover o primeiro elemento da queue
    ElementType X;          // respeitando o formato First In First Out
    if(IsEmptyQueue(Q)){
        Error("Queue is empty."); 
    } else {
        X = Q->Array[Q->Front];
        Q->Front = successor(Q->Front, Q); // para remover o primeiro elemento adicionamos 1 
    }                                      // ao índice front
    return X;
}