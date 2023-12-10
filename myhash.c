#include "myhash.h"
#include <stdio.h>
#include <stdlib.h>

//************************************************* Definitions ******************************************************//
#define INIT_SIZE (10)
#define LOAD_FACTOR (0.75)

//************************************************* Declarations *****************************************************//

typedef struct hash_node* HashNode;

HashNode createHashNode(Key key, Value val);
void destroyHashNode(HashNode hn);

// Auxiliary functions:
void emptyTable(HashTable ht);
void resize(HashTable ht);
int hash(HashTable ht, Key key);

//********************************************** Struct Definitions **************************************************//

struct hash_node {
    Key key;
    Value value;
    struct hash_node* next;
};

struct hash_table {
    int size;
    HashNode* table;
    int elements_num;
};

//******************************************** HashTable Implementation **********************************************//

HashTable createHashTable() {
    HashTable ht = malloc(sizeof (struct hash_table));
    ht->size = INIT_SIZE;
    ht->table = malloc(INIT_SIZE * sizeof (HashNode));
    return ht;
}


void destroyHashtable(HashTable ht) {
    if (!ht) return;
    emptyTable(ht);
    free(ht->table);
    free(ht);
}


Value get(HashTable ht, Key key) {
    if (!ht || !key) return NULL;
    HashNode ptr = ht->table[hash(ht, key)];
    while (ptr) {
        if (ptr->key == key) return ptr->value;
        ptr = ptr->next;
    }
    return NULL;
}

void insert(HashTable ht, Key key, Value val) {

}

void erase(HashTable ht, Key key) {

}

//******************************************** HashNode Implementation ***********************************************//

HashNode createHashNode(Key key, Value val) {
    HashNode new_node = malloc(sizeof (struct hash_node));
    new_node->key = key;
    new_node->value = val;
    new_node->next = NULL;
    return new_node;
}

void destroyHashNode(HashNode hn) {
    if (hn) free(hn);
}

//******************************************** HashNode Implementation ***********************************************//

void emptyTable(HashTable ht) {
    for (int i = 0; i < ht->size; i++) {
        HashNode ptr = ht->table[i];
        while (ptr) {
            HashNode to_delete = ptr;
            ptr = ptr->next;
            destroyHashNode(to_delete);
        }
    }
}


void resize(HashTable ht) {
    if (!ht) return;
    HashNode* new_table = malloc(2 * ht->size * sizeof (HashNode));
    for (int i = 0; i < ht->size; i++) {
        HashNode ptr = ht->table[i];
        while (ptr) {
            ptr = ptr->next;
        }
    }
    free(ht->table);
    ht->size *= 2;
    ht->table = new_table;
}


int hash(HashTable ht, Key key) {
    return (int)((long long)key % ht->size);
}

