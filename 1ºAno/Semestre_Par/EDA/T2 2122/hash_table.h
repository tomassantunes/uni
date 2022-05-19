#ifndef hash_table_h
#define hash_table_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* ElementType;

unsigned long int hash_function(ElementType str);

typedef struct HT_Item HT_Item;
typedef struct LinkedList LinkedList;
typedef struct HashTable HashTable;

static LinkedList* allocate_list();
static LinkedList* linkedlist_insert(LinkedList* list, HT_Item* item);
static HT_Item* linkedlist_remove(LinkedList* list);
static void free_linkedlist(LinkedList* list);
static LinkedList** create_overflow_buckets(HashTable* table);
static void free_overflow_buckets(HashTable* table);

HT_Item* create_item(ElementType key, ElementType value);
HashTable* create_table(int size);
void free_item(HT_Item* item);
void free_table(HashTable* table);
void handle_collision(HashTable* table, unsigned long index, HT_Item* item);
void ht_insert(HashTable* table, ElementType key, ElementType value);
ElementType ht_search(HashTable* table, ElementType key);
void ht_delete(HashTable* table, ElementType key);
void print_search(HashTable* table, ElementType key);
void print_table(HashTable* table);

// https://www.journaldev.com/35238/hash-table-in-c-plus-plus

#endif /* hash_table_h */