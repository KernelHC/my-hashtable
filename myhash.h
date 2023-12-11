#ifndef MY_HASH_H
#define MY_HASH_H

#include "myhash_test.h"


typedef struct hash_table *HashTable;

typedef void* Key;
typedef void* Value;

#ifdef DEBUG
typedef struct hash_node* HashNode;
struct hash_node {
    Key key;
    Value value;
    struct hash_node* next;
};

struct hash_table {
    int size;
    int elements_num;
    HashNode* table;
};
#endif

HashTable createHashTable();
void destroyHashtable(HashTable ht);
Value get(HashTable ht, Key key);
void insert(HashTable ht, Key key, Value val);
void erase(HashTable ht, Key key);

#endif //MY_HASH_H

