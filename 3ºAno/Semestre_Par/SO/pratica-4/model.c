#include "queue.c"

#define MAX_PROCESS 8
#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

typedef struct {
    char* state;
    int time;
} Process;

void runProgram(int p[]) {
    int procCount = 0;
    Queue program = CreateQueue(MAX_PROCESS);

    for(int i = 0; i < MAX_PROCESS; i++) {
        if(p[i] > 0) {
            Process* p;
            p.state = ("READY");
            p.time = p[i];
            Enqueue(p, program);
            procCount++;
        }
    }

    printf("instance | ");
    for(int i = 1; i <= procCount; i++) {
        printf("proc%d | ", i);
    }
    printf("\n");

    int i = 1;
    while(!IsEmptyQueue(program)) {
        int instances = Dequeue(program);

        while(instances > 0) {
        }
    }

    // for(int k = 0; k < procCount; k++)
    //     printf("%d ", program->Array[k]);

    DisposeQueue(program);
}

int main() {

    int programas[3][MAX_PROCESS] = {
        {3, 1, 2, 2, 0, 0, 0, 0 },
        {4, 2, 4, 0, 0, 0, 0, 0 },
        {2, 1, 5, 0, 0, 0, 0, 0}};

    for(int i = 0; i < COUNT_OF(programas); i++) {
        runProgram(programas[i]);
    }

}