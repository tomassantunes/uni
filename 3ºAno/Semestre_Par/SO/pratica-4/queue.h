#ifndef _Queue_h
#define _Queue_h

typedef struct {
    char* state;
    int time;
    int num;
} Process;

typedef Process ElementType;

struct QueueRecord;
typedef struct QueueRecord *Queue;

Queue CreateQueue( int MaxElements );
void DisposeQueue( Queue Q );

bool IsEmptyQueue( Queue Q );
bool IsFullQueue( Queue Q );
void MakeEmptyQueue( Queue Q );

ElementType Front( Queue Q );
void Enqueue( ElementType X, Queue Q );
ElementType Dequeue( Queue Q );

#endif
