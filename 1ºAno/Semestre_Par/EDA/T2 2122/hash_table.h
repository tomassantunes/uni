#ifndef hash_table_h
#define hash_table_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElementTypeKey;
typedef char* ElementTypeValue;

int hash_function(ElementTypeKey key, int size);

typedef struct HT_Item HT_Item;
typedef struct HashTable HashTable;

HT_Item* create_item(ElementTypeKey key, ElementTypeValue value);
HashTable* create_table(int size);
void free_item(HT_Item* item);
void free_table(HashTable* table);
void handle_collision(HashTable* table, unsigned long index, HT_Item* item, int i);
void ht_insert(HashTable* table, ElementTypeKey key, ElementTypeValue value);
ElementTypeValue ht_search(HashTable* table, ElementTypeKey key);
void ht_delete(HashTable* table, ElementTypeKey key);
void print_search(HashTable* table, ElementTypeKey key);
void print_table(HashTable* table);

#endif /* hash_table_h */