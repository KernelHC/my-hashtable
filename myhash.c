#include "myhash.h"
#include <stdio.h>
#include <stdlib.h>

//************************************************* Definitions ******************************************************//
#define INIT_SIZE (10)


//************************************************* Declarations *****************************************************//

typedef struct hash_node* HashNode;

HashNode createHashNode(Key key, Value val);
void destroyHashNode(HashNode hn);

//********************************************** Struct Definitions **************************************************//

struct hash_node {
    Key key;
    Value value;
    struct hash_node* next;
};

struct hash_table {
    int size;
    HashNode* table;
};

//******************************************** HashNode Implementation ***********************************************//

HashNode createHashNode(Key key, Value val) {
    HashNode new_node = malloc(sizeof (struct hash_node));
    new_node->key = key;
    new_node->value = val;
    new_node->next = NULL;
    return new_node;
}

void destroyHashNode(HashNode hn) {
    free(hn);
}

//******************************************** HashTable Implementation **********************************************//

HashTable createHashTable() {
    HashTable ht = malloc(sizeof (struct hash_table));
    ht->size = INIT_SIZE;
    ht->table = malloc(INIT_SIZE * sizeof (HashNode));
    return ht;
}


void destroyHashtable(HashTable ht) {

    free(ht->table);
    free(ht);
}


void* get(HashTable ht, Key key) {

}

void insert(Key key, Value val);