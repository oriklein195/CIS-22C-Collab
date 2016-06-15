//
//  HashTable.cpp
//  Hashtables
//
//  Created by Ori Klein on 6/14/16.
//  Copyright (c) 2016 Ori Klein. All rights reserved.
//

#include <stdio.h>
#include "HashTable.h"

template <class Type> HashTable<Type>::HashTable()
{
    array = new SinglyLinkedList<Type>[ 13 ];
	length = 13;
}


// Constructs the empty Hash Table object.
// Array length is set to 13 by default.

template <class Type> HashTable<Type>::HashTable( int tableLength )
{
    if (tableLength <= 0)
        tableLength = 13;
    array = new SinglyLinkedList<Type>[ tableLength ];
    length = tableLength;
}

// Returns an array location for a given item key.
template <class Type> int HashTable<Type>::hash( int key )
{
    return (3*key + 7) % length;
}

// Adds an item to the Hash Table.
template <class Type> void HashTable<Type>::insertItem(int key, Type newItem)
{
    int index = hash(key);
	array[index].addLast(newItem, key);
}

// Deletes an Item by key from the Hash Table.
// Returns true if the operation is successful.
template <class Type> bool HashTable<Type>::removeItem(int key)
{
    int index = hash(key);
    return array[index].remove(key);
}

// Returns an item from the Hash Table by key.
// If the item isn't found, a null pointer is returned.
template <class Type> Type HashTable<Type>::getItemByKey(int key)
{
    int index = hash(key);
    return array[index].get(key);
}

// Display the contents of the Hash Table to console window.
template <class Type> void HashTable<Type>::printTable()
{
    cout << "\n\nHash Table:\n";
    for ( int i = 0; i < length; i++ )
    {
        cout << "Bucket " << i + 1 << ": ";
        array[i].print();
    }
}

// Prints a histogram illustrating the Item distribution.
template <class Type> void HashTable<Type>::printHistogram()
{
    cout << "\n\nHash Table Contains ";
    cout << getNumberOfItems() << " Items total\n";
    for ( int i = 0; i < length; i++ )
    {
        cout << i + 1 << ":\t";
        for ( int j = 0; j < array[i].getSize(); j++ )
            cout << " X";
        cout << "\n";
    }
}

// Returns the number of locations in the Hash Table.
template <class Type> int HashTable<Type>::getLength()
{
    return length;
}

// Returns the number of Items in the Hash Table.
template <class Type> int HashTable<Type>::getNumberOfItems()
{
    int itemCount = 0;
    for ( int i = 0; i < length; i++ )
    {
        itemCount += array[i].getSize();
    }
    return itemCount;
}

// De-allocates all memory used for the Hash Table.
template <class Type> HashTable<Type>::~HashTable()
{
    delete [] array;
}
