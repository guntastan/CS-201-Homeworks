//Student Name: Gün TASTAN
//Section: 3
//Student ID Number: 22101850



#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "Node.h"

//I HAVE USED THE LINKEDLIST CLASS BELOW FROM OUR COURSEBOOK/TEXTBOOK: CARRANO

template < class ItemType>
class LinkedList
{
private :
Node<ItemType>* headPtr;
int itemCount;

Node<ItemType>* getNodeBefore( const ItemType& anEntry) const ;

Node<ItemType>* getNodeAt( int position) const ;


public :
LinkedList();
LinkedList(const LinkedList<ItemType>& aList);
void operator=(const LinkedList<ItemType>& right);



virtual ~LinkedList();
void insertSorted( const ItemType& newEntry);
bool removeSorted( const ItemType& anEntry);
int getPosition( const ItemType& newEntry) const ;

bool isEmpty() const ;
int getLength() const ;
bool remove( int position);
void clear();
ItemType getEntry( int position) const ;

void displayList() const;

ItemType* getByIndex(int index);


};

#endif
