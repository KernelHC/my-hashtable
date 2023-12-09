#include "myhash.h"
#include <stdio.h>

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

HashNode createHashNode() {

}

void destroyHashNode(HashNode hn) {

}

//******************************************** HashTable Implementation **********************************************//
