
/* plagerismCatcher.h

 */

#ifndef BST_312_H
#define BST_312_H

#include <cstdlib>  // Provides size_t
#include <iostream>
#include <vector>

using namespace std;
template <typename K, typename V>
//HashNode class
class HashNode
{
    public:
    V value;
    K key;

    HashNode(K key, V value)
    {
        this->value = value;
        this->key = key;
    }
};

template <typename K, typename V>
class HashMap
{
    HashNode<K,V> **hashTable;
    int capacity;
    int size;
    HashNode<K,V> *dummy;

    public:
    HashMap()
    {
        capacity = 10007;
        size = 0;
        hashTable = new HashNode<K,V>*[capacity];

        // initialize hash table
        for(int i=0; i<capacity; i++)
        {
            hashTable[i] = NULL;
        }
    }

    int hashCode(K key)
    {
        return key % capacity;
    }

    void insertNode(K key, V value)
    {
        HashNode<K,V> *temp = new HashNode<K,V>(key,value);

        int hashIndex = hashCode(key);

        while(hashTable[hashIndex] != NULL && hashTable[hashIndex]->key != key && hashTable[hashIndex]->key != -1)
        {
            hashIndex++;
            hashIndex %= capacity;
        }

        if(hashTable[hashIndex] == NULL || hashTable[hashIndex]->key == -1)
        {
            size++;
            hashTable[hashIndex] = temp;
        }
    }

    V deleteNode(int key)
    {
        /*int hashIndex = hashCode(key);

        while(hashTable[hashIndex] != NULL)
        {
            if(hashTable[hashIndex]->key == key)
            {
                HashNode<K,V> *temp = hashTable[hashIndex];
            }
        }*/
    }

    V get(int key)
    {
        int hashIndex = hashCode(key);
        int counter = 0;

        while(hashTable[hashIndex] != NULL)
        {
            int counter = 0;

            if(counter++ > capacity)
            {
                return NULL;
            }

            if(hashTable[hashIndex]->key == key)
            {
                return hashTable[hashIndex]->value;
            }

            hashIndex++;
            hashIndex %= capacity;
        }

        return NULL;
    }

    int sizeofMap()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void display()
    {
        for(int i=0; i<capacity; i++)
        {
            if(hashTable[i] != NULL && hashTable[i]->key != -1)
            {
                cout << "key = " << hashTable[i]->key << " value = " << hashTable[i]->value << endl;
            }
        }
    }

};

#endif