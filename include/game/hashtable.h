#pragma once

typedef struct _hti HashTableItem;
typedef struct _hti {
    const char *key;
    void *value;
    HashTableItem *next;
} HashTableItem;

typedef struct _ht {
    HashTableItem **items;
    unsigned long int count;
} HashTable;

HashTable *HTCreate();
void HTDestroy(HashTable *self);

void HTSet(HashTable *self, const char *key, void *value);
void *HTGet(HashTable *self, const char *key);
void HTDelete(HashTable *self, const char *key);
const char **HTGetKeys(HashTable *self, int *count);
