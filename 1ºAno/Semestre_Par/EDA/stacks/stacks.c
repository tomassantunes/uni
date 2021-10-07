#include "stackar.h"
#include "fatal.h"
#include <stdlib.h>
#include <stdio.h>

#define EmptyTOS -1 
#define MinStackSIze 5

struct StackRecord{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};

Stack CreateStack(int MaxElements) {
    Stack S;

    if(MaxElements < MinStackSIze)
        Error("Stack size is too small.");

    S = malloc(sizeof(struct StackRecord));
    if(S == NULL)
        FatalError("Out of space!!!");

    S->Array = malloc(sizeof(ElementType) * MaxElements);
    if(S->Array == NULL) 
        FatalError("Out of space!!!");

    S->Capacity = MaxElements;
    MakeEmpty(S);

    return S;
}

void DisposeStack(Stack S) {
    if(S != NULL) {
        free(S->Array);
        free(S);
    }
}

int isEmpty(Stack S) {
    return S->TopOfStack == EmptyTOS;
}

int isFull(Stack S) {
    return S->TopOfStack == S->Capacity - 1;
}

void MakeEmpty(Stack S) {
    S->TopOfStack == EmptyTOS;
}

void Push(ElementType X, Stack S) {
    if(isFull(S))
        Error("Stack is full.");
    S->Array[++S->TopOfStack] = X;
}

ElementType Top(Stack S) {
    if(isEmpty(S))
        Error("Stack is empty.");
    return S->Array[S->TopOfStack];
}

ElementType Pop(Stack S) {
    return S->Array[S->TopOfStack--];
}

Stack q1(Stack X, Stack A1, Stack A2) {
    
    if(isEmpty(X))
        return A1;
    else
        Push(Pop(X), A1);

    while(!isEmpty(X)) {
        if(Top(X) < Top(A1)) {
            Push(Pop(A1), A2);
            Push(Pop(X), A1);
        } else 
            Push(Pop(X), A2);
    }

    return q1(A2, A1, X);
}

int main() {
    Stack X = CreateStack(100);
    Stack A = CreateStack(100);
    Stack B = CreateStack(100);

    Push(13, X);
    Push(2, X);
    Push(7, X);
    Push(21, X);
    Push(3, X);
    Push(52, X);
    Push(28, X);

    q1(X, A, B);

    printf("X: \n");

    while(!isEmpty(X))
        printf("%d \n", Pop(X));

    printf("A: \n");

    while(!isEmpty(A))
        printf("%d \n", Pop(A));

    printf("B: \n");

    while(!isEmpty(B))
        printf("%d \n", Pop(B));
}