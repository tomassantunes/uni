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
    ElementType X = 0;          // respeitando o formato First In First Out
    if(IsEmptyQueue(Q)){
        Error("Queue is empty."); 
    } else {
        X = Q->Array[Q->Front];
        Q->Front = successor(Q->Front, Q); // para remover o primeiro elemento adicionamos 1 
    }                                      // ao índice front
    return X;
}

// 2. (da ficha queues)
Queue inverte( Queue q ){ // função para inverter a queue
    int queue[size(q)];
    int h = size(q);

    for(int i = 0; i < h; i++){
        queue[i] = Dequeue(q); // guardar todos os elementos da queue no array queue
    }

    for(int j = h-1, i = 0; j >= i; j--){
        Enqueue(queue[j], q); // voltar a por os elementos na queue mas por ordem inversa
    }

    printf("Inverso \n");

    for(int i = 0; i<h; i++){
        printf("%d \n", Dequeue(q) ); // fazer print dos elementos da queue
    }
}

void Troca( ElementType *Lhs, ElementType *Rhs ){
    ElementType Tmp = *Lhs;
    *Lhs = *Rhs;
    *Rhs = Tmp;
} 

void Bubblesort(ElementType A[], int size){

    for (int i=1;i<size;i++){
        //printf("Passagem %d: \n", i);
        for (int j=0;j<size-i;j++) {
            if (A[j]>A[j+1]){
                //printf("troca %d com %d\n",A[j],A[j+1]);
                Troca(&A[j],&A[j+1]);
            }
        }
    }
}

int main() {
    Queue Q = CreateQueue(100);
    Queue R = CreateQueue(100);

    Queue fixed = CreateQueue(100);

    Enqueue(10, Q);
    Enqueue(1, Q);
    Enqueue(30, Q);
    Enqueue(69, R);
    Enqueue(-1, R);
    Enqueue(-7, R);

    int sz = 6;
    int array[sz];

    int i;

    while(!IsEmptyQueue(Q)) {
        array[i] = Dequeue(Q);
        i++;
    }

    while(!IsEmptyQueue(R)) {
        array[i] = Dequeue(R);
        i++;
    }

    Bubblesort(array, sz);
    for(int j = 0; j < sz; j++)
        Enqueue(array[j], fixed);

    for(int k = 0; k < sz; k++)
        printf("%d ", fixed->Array[k]);
}