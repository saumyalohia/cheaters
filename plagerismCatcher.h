
/* plagerismCatcher.h

 */

#ifndef BST_312_H
#define BST_312_H

#include <cstdlib>  // Provides size_t
#include <iostream>
#include <vector>

using namespace std;
template <typename K, typename V>
class HashNode
{
private:
    K key;
    V value;
    HashNode* next;

public:
    HashNode(K key, V value)
    {
        this->value = value;
        this->key = key;
    }

    V getValue() const
    {
<<<<<<< HEAD
        return this->value;
=======
        capacity = 10007;
        size = 0;
        hashTable = new HashNode<K,V>*[capacity];

        // initialize hash table
        for(int i=0; i<capacity; i++)
        {
            hashTable[i] = NULL;
        }
>>>>>>> d83964ef0d3c9212f0a102fdb99aea6d1b72bf2b
    }

};


template <typename K, typename V>
class HashTable
{
private:
    static const int TABLE_SIZE = 1007;
    HashNode<K,V> **table;

public:
    HashTable()
    {
        table = new HashNode<K,V>[TABLE_SIZE];
        for(int i=0; i<TABLE_SIZE; i++)
        {
            table[i] = NULL;
        }
    }

    V get(K key){}

    int hashCode(K key){}

    void addNode(K key, V value){}

    void removeNode(K key){}

    bool isEmpty(){}

    ~HashTable()
    {
        for(int i =0; i<TABLE_SIZE; i++)
        {
            if(table[i] != NULL)
            {
                delete table[i];
            }
        }
        delete table;
    }
};

#endif
