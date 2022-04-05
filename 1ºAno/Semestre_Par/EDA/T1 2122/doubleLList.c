#include "doubleLList.h"

struct DNode {
    ElementType data;
    DPosition next;
    DPosition prev;
} DNode;

struct DListStruct {
    int size;
    void(*destroy)(void *data);
    DPosition first;
    DPosition last;
};

DList CreateDList(void) {
    DList list = calloc(1, sizeof(DList));
    return list;
}

void MakeEmptyDList(DList L) {
    DPosition it = L->first;
    while(it) {
        DPosition tmp = it;
        if(L->destroy) 
            L->destroy(tmp);
        
        free(tmp);
    }
    L->first = L->last = NULL;
    free(L);
}

int SizeDList(DList L) {
    return L->size;
}

DPosition DHeader(DList L) {
    return L->first;
}

DPosition DFooter(DList L) {
    return L->last;
}

int IsEmptyDList(DList L) {
    return L->size == 0;
}

void InsertDList(ElementType X, DPosition P) {
    DPosition tmp;
    tmp = malloc(sizeof(struct DNode));
    if(tmp == NULL) {
        printf("Out of Memory\n");
        exit(0);
    }

    tmp->data = X;
    tmp->next = P->next;
    P->next = tmp;
}

void InsertDListIth(ElementType X, int i, DList L) {

}

void addDList(ElementType X, DList L) {
    DPosition tmp;
    tmp = malloc(sizeof(struct DNode));
    if(tmp == NULL) {
        printf("Out of Memory\n");
        exit(0);
    }

    L->last->next = X;
    tmp->data = X;
    tmp->prev = L->last->data;
    L->last = tmp;
}

DPosition FindDList(ElementType e, DList L) {
    for(DPosition it = L->first; it != NULL; it = it->next) {
        if(cmp(it->data, e))
            return it;
    }
}

void DeleteElement(ElementType e, DList L) {
    if(IsEmptyDList(L)) {
        printf("List is empty.\n");
        exit(0);
    }

    for(DPosition it = L->first; it != NULL; it = it->next) {
        if(cmp(it->data, e)) {
            L->size--;

            if(!it->prev && !it->next) { // apenas existe o elemento e
                MakeEmptyDList(L);
                exit(0);
            } else if(!it->next){ // no fim
                it->prev->next = NULL;
                if (L->destroy) {
                    L->destroy(it->data);
                }
                free(it);
                exit(0);
            } else if(!it->prev) { // no inicio
                DPosition next = it->next;
                next->prev = NULL;
                if (L->destroy) {
                    L->destroy(it->data);
                }
                free(it);

                L->first = next;
                exit(0);
            } else { // algures no meio
                DPosition next = it->next;
                DPosition prev = it->prev;

                next->prev = prev;
                prev->next = next;

                if (L->destroy) {
                    L->destroy(it->data);
                }
                free(it);

                exit(0);
            }
        }
    }
}

ElementType RemoveElementAt(int i, DList L) {
    if(IsEmptyDList(L)) {
        printf("List is empty.\n");
        exit(0);
    }

    DPosition it = L->first;
    for(i; i > 0; i--) {
        it = it->next;
    }
    ElementType tmp = it->data;
    RemoveElementAt(tmp, L);
    return tmp;
}

DPosition Advance(DPosition P) {
    return P->next;
}

DPosition Back(DPosition P) {
    return P->prev;
}

ElementType Retrieve(DPosition P) {
    return P->data;
}

void PrintDList(char *name, DList L) {
    
}

int main() {
    printf("Hello World!\n");
}