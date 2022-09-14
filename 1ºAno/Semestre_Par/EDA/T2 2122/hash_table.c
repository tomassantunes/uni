#include "hash_table.h"

int hash_function(ElementTypeKey key, int size){
    return key % size;
}

struct HT_Item{
    ElementTypeKey key;
    ElementTypeValue value;
};

struct HashTable{
    HT_Item** items;
    int size;
    int count;
};

HT_Item* create_item(ElementTypeKey key, ElementTypeValue value){
    HT_Item* item = (HT_Item*) malloc (sizeof(HT_Item));
    item->value = (ElementTypeValue) malloc (strlen(value) + 1);

    item->key = key;
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

    return table;
}

void free_item(HT_Item* item){
    free(item->value);
    free(item);
}

void free_table(HashTable* table){
    for(int i = 0; i < table->size; i++) {
        HT_Item* item = table->items[i];
        if(item != NULL)
            free_item(item);
    }

    free(table->items);
    free(table);    
}

void handle_collision(HashTable* table, unsigned long index, HT_Item* item, int i){
    index += (i * i);

    while(index > table->size - 1)
        index -= table->size;

    if(table->items[index] != NULL) {
        handle_collision(table, index, item, i++);
        return;
    }

    table->items[index] = item;
}

void ht_insert(HashTable* table, ElementTypeKey key, ElementTypeValue value){
    HT_Item* item = create_item(key, value);

    int index = hash_function(key, table->size);
    
    while(index > table->size - 1)
        index -= table->size;

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
    
    if(current_item->key == key && current_item->value == NULL) {
        strcpy(table->items[index]->value, value);
        return;
    }

    handle_collision(table, index, item, 1);
}

ElementTypeValue ht_search(HashTable* table, ElementTypeKey key){
    int index = hash_function(key, table->size);
    HT_Item* item = table->items[index];

    if(item->key == key)
        return item->value;

    return NULL;
}

void ht_delete(HashTable* table, ElementTypeKey key){
    int index = hash_function(key, table->size);
    HT_Item* item = table->items[index];

    if(item == NULL)
        return;

    table->items[index] = NULL;
    free_item(item);
    table->count--;

}

void print_search(HashTable* table, ElementTypeKey key){
    ElementTypeValue val;
    if((val = ht_search(table, key)) == NULL) {
        printf("Key: %d não existe.\n", key);
        return;
    } else {
        printf("Key: %d, Value: %s\n", key, val);
    }
}

void print_table(HashTable* table){
    for(int i = 0; i < table->size; i++) {
        if(table->items[i]) {
            printf("Index: %d, Key: %d, Value: %s\n", i, table->items[i]->key, table->items[i]->value);
        }
    }
    printf("\n");
}