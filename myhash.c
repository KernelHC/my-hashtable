#include "myhash.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct hash_node {
    Key key;
    Value value;
    struct hash_node* next;
}* HashNode;

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
