#include "hash_table.h"

#define CAPACITY 50000

unsigned long int hash_function(ElementType str){
    unsigned long i = 0;
    for(int j = 0; str[j]; j++)
        i += str[j];
    return i % CAPACITY;
}

struct HT_Item{
    ElementType key;
    ElementType value;
};

struct LinkedList{
    HT_Item* item;
    LinkedList* next;
};

struct HashTable{
    HT_Item** items;
    LinkedList** overflow_buckets;
    int size;
    int count;
};

static LinkedList* allocate_list(){
    LinkedList* list = (LinkedList*) malloc (sizeof(LinkedList));
    return list;
}

static LinkedList* linkedlist_insert(LinkedList* list, HT_Item* item){
    if(!list) {
        LinkedList* head = allocate_list();
        head->item = item;
        head->next = NULL;
        list = head;

        return list;
    } else if(list->next == NULL) {
        LinkedList* node = allocate_list();
        node->item = item;
        node->next = NULL;
        list->next = node;

        return list;
    }

    LinkedList* temp = list;
    while(temp->next->next) {
        temp = temp->next;
    }

    LinkedList* node = allocate_list();
    node->item = item;
    node->next = NULL;
    temp->next = node;

    return list;
}

static HT_Item* linkedlist_remove(LinkedList* list){
    if(!list || !list->next)
        return NULL;

    LinkedList* node = list->next;
    LinkedList* temp = list;
    temp->next = NULL;
    list = node;
    HT_Item* it = NULL;

    memcpy(temp->item, it, sizeof(HT_Item));
    free(temp->item->key);
    free(temp->item->value);
    free(temp->item);
    free(temp);
    
    return it;
}

static void free_linkedlist(LinkedList* list){
    LinkedList* temp = list;
    while(list) {
        temp = list;
        list = list->next;

        free(temp->item->key);
        free(temp->item->value);
        free(temp->item);
        free(temp);
    }
}

static LinkedList** create_overflow_buckets(HashTable* table){
    LinkedList** buckets = (LinkedList**) calloc (table->size , sizeof(LinkedList*));
    
    for(int i = 0; i < table->size; i++)
        buckets[i] == NULL;
    
    return buckets;
}

static void free_overflow_buckets(HashTable* table){
    LinkedList** buckets = table->overflow_buckets;
    
    for(int i = 0; i < table->size; i++)
        free_linkedlist(buckets[i]);

    free(buckets);   
}

HT_Item* create_item(ElementType key, ElementType value){
    HT_Item* item = (HT_Item*) malloc (sizeof(HT_Item));
    item->key = (ElementType) malloc (strlen(key) + 1);
    item->value = (ElementType) malloc (strlen(value) + 1);

    strcpy(item->key, key);
    strcpy(item->value, value);

    return item;
}

HashTable* create_table(int size){
    HashTable* table = (HashTable*) malloc (sizeof(HashTable));
    
    table->size = size;
    table->count = 0;
    table->items = (HT_Item**) calloc (table->size, sizeof(HT_Item*));

    for(int i = 0; i < table->size; i++)
        table->items[i] == NULL;

    table->overflow_buckets = create_overflow_buckets(table);

    return table;
}

void free_item(HT_Item* item){
    free(item->key);
    free(item->value);
    free(item);
}

void free_table(HashTable* table){
    for(int i = 0; i < table->size; i++) {
        HT_Item* item = table->items[i];
        if(item != NULL)
            free_item(item);
    }

    free_overflow_buckets(table);
    free(table->items);
    free(table);    
}

void handle_collision(HashTable* table, unsigned long index, HT_Item* item){
    LinkedList* head = table->overflow_buckets[index];

    if(head == NULL) {
        head = allocate_list();
        head->item = item;
        table->overflow_buckets[index] = head;
        return;
    } else {
        table->overflow_buckets[index] = linkedlist_insert(head, item);
        return;
    }
}

void ht_insert(HashTable* table, ElementType key, ElementType value){
    HT_Item* item = create_item(key, value);

    unsigned long index = hash_function(key);
    
    HT_Item* current_item = table->items[index];

    if(current_item == NULL) {
        if(table->count == table->size) {
            printf("Insert Error: Hash table is full.\n");
            free_item(item);
            return;
        }

        table->items[index] = item;
        table->count++;
        return;
    }
    
    if(!strcmp(current_item->key, key)) {
        strcpy(table->items[index]->value, value);
        return;
    }

    handle_collision(table, index, item);
}

ElementType ht_search(HashTable* table, ElementType key){
    int index = hash_function(key);
    HT_Item* item = table->items[index];
    LinkedList* head = table->overflow_buckets[index];

    while(item != NULL) {
        if(!strcmp(item->key, key))
            return item->value;
        if(head == NULL)
            return NULL;
        item = head->item;
        head = head->next;
    }

    return NULL;
}

void ht_delete(HashTable* table, ElementType key){
    int index = hash_function(key);
    HT_Item* item = table->items[index];
    LinkedList* head = table->overflow_buckets[index];

    if(item == NULL)
        return;

    if(head == NULL && !strcmp(item->key, key)) {
        table->items[index] = NULL;
        free_item(item);
        table->count--;
        return;

    } else if(head != NULL) {
        if(!strcmp(item->key, key)){
            free_item(item);
            LinkedList* node = head;
            head = head->next;
            node->next = NULL;
            table->items[index] = create_item(node->item->key, node->item->value);

            free_linkedlist(node);
            table->overflow_buckets[index] = head;
        }

        LinkedList* curr = head;
        LinkedList* prev = NULL;

        while(curr) {
            if(!strcmp(curr->item->key, key)) {
                if(prev == NULL) {
                    free_linkedlist(head);
                    table->overflow_buckets[index] = NULL;
                    
                    return;
                } else {
                    prev->next = curr->next;
                    curr->next = NULL;
                    free_linkedlist(curr);
                    table->overflow_buckets[index] = head;
                    
                    return;
                }
            }
            curr = curr->next;
            prev = curr;
        }
    }
}

void print_search(HashTable* table, ElementType key){
    ElementType val;
    if((val = ht_search(table, key)) == NULL) {
        printf("%s não existe.\n", key);
        return;
    } else {
        printf("Key: %s, Value: %s\n", key, val);
    }
}

void print_table(HashTable* table){
    printf("\n-------------------\n");
    
    for(int i = 0; i < table->size; i++) {
        if(table->items[i]) {
            printf("Index: %d, Key: %s, Value: %s", i, table->items[i]->key, table->items[i]->value);
            if(table->overflow_buckets[i]) {
                printf("=> Overflow Bucket => ");
                LinkedList* head = table->overflow_buckets[i];
                while(head) {
                    printf("Key: %s, Value: %s", head->item->key, head->item->value);
                    head = head->next;
                }
            }
            printf("\n");
        }
    }
    printf("-------------------\n");
}