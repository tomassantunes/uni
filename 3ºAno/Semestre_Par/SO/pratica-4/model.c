#include "queue.c"

#define MAX_PROCESS 8
#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

void run(Process* p) {
    p->state = "RUN";

    for(int i = 1; i < p->num; i++) {
      printf("        ");
    }

    printf("   %s    ", p->state);
}

void runProgram(int p[]) {
    int procCount = 0;
    Queue program = CreateQueue(MAX_PROCESS);

    for(int i = 0; i < MAX_PROCESS; i++) {
        if(p[i] > 0) {
            Process process;
            process.state = "READY";
            process.time = p[i];
            process.num = i + 1;
            Enqueue(process, program);
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
        Process process = Dequeue(program);
        procCount--;

        for(; process.time > 0; process.time--) {
            if(i < 10) printf("%d        ", i++);
            else printf("%d       ", i++);

            run(&process);
            for(int j = 0; j < procCount; j++) {
                printf("%s   ", program->Array[j].state);
            }
            printf("\n");
        }
    }
    printf("\n");
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
