//
// Created by User on 12/9/2023.
//
#include "myhash.h"
#include <stdio.h>
#include <assert.h>

void testInit() {
    HashTable ht = createHashTable();
    assert(!ht);
    destroyHashtable(ht);
}

void testInsert() {

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
