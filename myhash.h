#ifndef MY_HASH_H
#define MY_HASH_H

typedef struct hash_table *HashTable;

typedef void* Key;
typedef void* Value;

HashTable createHashTable();
void destroyHashtable(HashTable ht);
Value get(HashTable ht, Key key);
void insert(HashTable ht, Key key, Value val);
void erase(HashTable ht, Key key);

#endif //MY_HASH_H

