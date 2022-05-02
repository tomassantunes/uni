#include "doubleLList.h"

struct DNode {
    ElementType data;
    DPosition next;
    DPosition prev;
};

struct DListStruct {
    void(*destroy)(ElementType data);
    DPosition first;
    DPosition last;
};

DPosition head = NULL;

DList CreateDList(void) {
    DList list = calloc(1, sizeof(DList));
    return list;
}

void MakeEmptyDList(DList L) {
    DPosition it = L->first;
    while(it) {
        DPosition tmp = it;
        if(L->destroy) 
            L->destroy(tmp->data);
        
        free(tmp);
    }
    L->first = L->last = NULL;
    free(L);
}

int SizeDList(DList L) {
    int count = 0;
    DPosition it = L->first;
    while(it != NULL) {
        count++;
        it = it->next;
    }

    return count;
}

DPosition DHeader(DList L) {
    return L->first ? L->first : NULL;
}

DPosition DFooter(DList L) {
    return L->last ? L->last : NULL;
}

int IsEmptyDList(DList L) {
    return SizeDList(L) == 0;
}

void InsertDList(ElementType X, DPosition P) {
    P->data = X;
}

void InsertDListIth(ElementType X, int i, DList L) {
    DPosition new = malloc(sizeof(DPosition));
    new->data = X;
    new->prev = NULL;
    new->next = NULL;
    
    if(L->first != NULL) {
        if(i >= SizeDList(L)) {
            DPosition tmp = L->first;
            while(tmp->next != NULL) {
                tmp = tmp->next;
            }
            tmp->next = new;
            new->prev = tmp;
            L->last = new;

        } else {
            DPosition it = L->first;
            DPosition temp = NULL;

            for(i; i > 0; i--)
                it = Advance(it);
            
            temp = it->next;
            temp->prev = it;

            it->next = new;
            new->prev = it;
            new->next = temp;
            temp->prev = new;
        }
    } else {
        L->first = new;
        L->last = new;
        head = L->first;
    }
}

void addDList(ElementType X, DList L) {
    DPosition new = malloc(sizeof(DPosition));
    new->data = X;
    new->prev = NULL;
    new->next = NULL;
    
    if(L->first != NULL) {
        DPosition tmp = L->first;

        while(tmp->next != NULL)
            tmp = Advance(tmp);

        tmp->next = new;
        new->prev = tmp;
        L->last = new;
    } else {
        L->first = new;
        L->last = new;
        head = L->first;
    }

}

DPosition FindDList(ElementType e) {
    DPosition tmp = head;
    while(tmp != NULL) {
        if(tmp->data == e) { return tmp; }
        tmp = Advance(tmp);
    }

    printf("%d does not exist.", e);
    exit(0);
}

void DeleteElement(ElementType e, DList L) {
    if(IsEmptyDList(L)) {
        printf("List is empty.\n");
        exit(0);
    }

    for(DPosition it = L->first; it != NULL; it = it->next) {
        if(it->data == e) {

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
        it = Advance(it);
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
    DPosition it = L->first;

    while(it != NULL) {
        printf("%d ", it->data);
        it = it->next;
    }
    printf("\n");
}
