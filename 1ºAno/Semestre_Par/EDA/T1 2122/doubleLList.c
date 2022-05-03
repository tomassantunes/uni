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
        it = it->next;
        if(L->destroy) 
            L->destroy(tmp->data);
        
        free(tmp);
    }
    L->first = L->last = NULL;
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
        if(i == 0) {
            DPosition tmp = L->first;
            L->first = new;
            L->first->next = tmp;
            tmp->prev = new;
            head = L->first;
        } else if(i >= SizeDList(L)) {
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

            if(!it->prev && !it->next) {
                MakeEmptyDList(L);
                break;
            } else if(!it->next){
                it->prev->next = NULL;
                if (L->destroy) {
                    L->destroy(it->data);
                }
                free(it);
                break;
            } else if(!it->prev) {
                DPosition next = it->next;
                next->prev = NULL;
                if (L->destroy) {
                    L->destroy(it->data);
                }
                free(it);

                L->first = next;
                break;
            } else {
                DPosition next = it->next;
                DPosition prev = it->prev;

                next->prev = prev;
                prev->next = next;

                if (L->destroy)
                    L->destroy(it->data);
                free(it);

                break;
            }
        }
    }
}

ElementType RemoveElementAt(int i, DList L) {
    if(IsEmptyDList(L)) {
        printf("List is empty.\n");
        exit(0);
    }

    if(i >= SizeDList(L)) {
        printf("The list does not have an index of %d.\n", i);
        exit(0);
    }

    DPosition it = L->first;
    for(i; i > 0; i--) {
        it = Advance(it);
    }
    ElementType tmp = it->data;
    DeleteElement(tmp, L);
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
    if(IsEmptyDList(L)) {
        printf("List is empty.\n");
        exit(0);
    }

    DPosition it = L->first;

    while(it != NULL) {
        printf("%d", it->data);
        it = it->next;
    }
    printf("\n");
}
