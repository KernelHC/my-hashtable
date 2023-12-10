#include "myhash.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//************************************************* Definitions ******************************************************//
#define INIT_SIZE (10)
#define UPPER_LOAD_FACTOR (0.75)
#define LOWER_LOAD_FACTOR (0.5)
#define UP (false)
#define DOWN (true)

//************************************************* Declarations *****************************************************//

typedef struct hash_node* HashNode;

HashNode createHashNode(Key key, Value val);
void destroyHashNode(HashNode hn);

// Auxiliary functions:
void emptyTable(HashTable ht);
void resize(HashTable ht, bool down);
int hash(int size, Key key);
void insertNode(HashNode* table, int size, HashNode node);

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
    HashNode ptr = ht->table[hash(ht->size, key)];
    while (ptr) {
        if (ptr->key == key) return ptr->value;
        ptr = ptr->next;
    }
    return NULL;
}

void insert(HashTable ht, Key key, Value val) {
    if (!ht || !key || !val) return;
    if ((double)ht->elements_num/(double)ht->size > UPPER_LOAD_FACTOR) resize(ht, UP);
    int hash_key = hash(ht->size, key);
    HashNode ptr = ht->table[hash_key];
    if (!ptr) {
        ht->table[hash_key] = createHashNode(key, val);
        ht->elements_num++;
        return;
    }
    while (ptr->next) {
        if (ptr->key == key) {
            ptr->value = val;
            return;
        }
        ptr = ptr->next;
    }
    if (ptr->key == key) ptr->value = val;
    else ptr->next = createHashNode(key, val);
}

void erase(HashTable ht, Key key) {
    if (!ht || !key) return;
    if ((double)ht->elements_num/(double)ht->size < LOWER_LOAD_FACTOR) resize(ht, DOWN);
    int hash_key = hash(ht->size, key);
    HashNode prev = ht->table[hash_key];
    if (!prev) return;
    if (prev->key == key) {
        ht->table[hash_key] = NULL;
        destroyHashNode(prev);
        ht->elements_num--;
        return;
    }
    HashNode ptr = prev->next;
    while (ptr) {
        if (ptr->key == key) {
            prev->next = ptr->next;
            destroyHashNode(ptr);
            ht->elements_num--;
            return;
        }
        ptr = ptr->next;
    }
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


void resize(HashTable ht, bool down) {
    if (!ht) return;
    HashNode* new_table = down?
            malloc((ht->size/2) * sizeof (HashNode)):
            malloc(2 * ht->size * sizeof (HashNode));
    for (int i = 0; i < ht->size; i++) {
        HashNode ptr = ht->table[i];
        while (ptr) {
            HashNode current = ptr;
            ptr = ptr->next;
            insertNode(new_table, 2*ht->size, current);
        }
    }
    free(ht->table);
    ht->size *= 2;
    ht->table = new_table;
}


int hash(int size, Key key) {
    return (int)((long long)key % size);
}


void insertNode(HashNode* table, int size, HashNode node) {
    if (!table || !node) return;
    node->next = NULL;
    int hash_key = hash(size, node->key);
    HashNode ptr = table[hash_key];
    if (!ptr) {
        table[hash_key] = node;
        return;
    }
    while (ptr->next) {
        ptr = ptr->next;
    }
    ptr->next = node;
}
