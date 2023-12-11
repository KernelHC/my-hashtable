//
// Created by User on 12/9/2023.
//
#include "myhash.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>


void testInit() {
    HashTable ht = createHashTable();
    assert(ht);
    destroyHashtable(ht);
}

void testInsert() {
    HashTable ht = createHashTable();
    assert(ht);
    for (int i = 0; i < 9; i++) {
        insert(ht, (Key)i, "abc");
        printf("%d\n", i);
        assert(ht->elements_num == i+1);
    }
    printf("%d\n", ht->size);
    assert(ht->size == 20);
    destroyHashtable(ht);
}

void testInsert2() {

}

void testGet() {

}

void testErase() {

}

void testSameKey() {

}

void testCopy() {

}

void testStress1() {

}

void testStress2() {

}

void (*tests[])() = {
    testInit,
    testInsert,
    testInsert2,
    testCopy,
    testSameKey,
    testErase,
    testStress1,
    testStress2,
    0
};

int main() {
    for (int i = 0; tests[i] != 0; i++) {
        tests[i]();
        printf("Passed!\n");
    }
    return 0;
}
