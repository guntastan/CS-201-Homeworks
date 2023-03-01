//Student Name: Gün TASTAN
//Section: 3
//Student ID Number: 22101850

#include "LinkedList.h"
#include "Node.cpp"
#include <cstddef>
#include <string>
#include <iostream>

//I HAVE USED THE LINKEDLIST CLASS BELOW FROM OUR COURSEBOOK/TEXTBOOK: CARRANO

template < class ItemType>
LinkedList<ItemType>::LinkedList()
{
    headPtr = nullptr;
    itemCount = 0;
}

template <class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList <ItemType>& aList)
{
    itemCount = aList.itemCount;
    Node<ItemType>* origChainPtr = aList.headPtr;

    if (origChainPtr == nullptr){
        headPtr = nullptr;
    }
    else{
        headPtr = new Node<ItemType>();
        headPtr->setItem(origChainPtr->getItem());

        Node<ItemType>* newChainPtr = headPtr;
        origChainPtr = origChainPtr->getNext();
        while (origChainPtr != nullptr){
            ItemType nextItem = origChainPtr->getItem();
            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
            newChainPtr->setNext(newNodePtr);
            newChainPtr = newChainPtr->getNext();
            origChainPtr = origChainPtr->getNext();
        }
        newChainPtr->setNext(nullptr);
    }

}

template < class ItemType>
void LinkedList<ItemType>::insertSorted( const ItemType& newEntry)
{
    Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
    Node<ItemType>* prevPtr = getNodeBefore(newEntry);
    if (isEmpty() || (prevPtr == nullptr ))
    {
    newNodePtr->setNext(headPtr);
    headPtr = newNodePtr;
    }
    else
    {
    Node<ItemType>* aftPtr = prevPtr->getNext();
    newNodePtr->setNext(aftPtr);
    prevPtr->setNext(newNodePtr);
    }
    itemCount++;
}


template < class ItemType>
Node<ItemType>* LinkedList<ItemType>::
getNodeBefore( const ItemType& anEntry) const
{
    Node<ItemType>* curPtr = headPtr;
    Node<ItemType>* prevPtr = nullptr;
    while ( (curPtr != nullptr) && (anEntry > curPtr->getItem()) )
    {
    prevPtr = curPtr;
    curPtr = curPtr->getNext();
    }
    return prevPtr;
}

template < class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt( int position) const
{
    if ((position >= 1) && (position <= itemCount) ){
        Node<ItemType>* curPtr = headPtr;
        for ( int skip = 1; skip < position; skip++){
            curPtr = curPtr->getNext();
        }
        return curPtr ;
    }
    else{
        return nullptr;
    }
}


template < class ItemType>
bool LinkedList<ItemType>::remove( int position)
{
bool ableToRemove = (position >= 1) && (position <= itemCount);
if (ableToRemove)
{
Node<ItemType>* curPtr = nullptr ;
if (position == 1)
{
// Remove the first node in the chain
curPtr = headPtr; // Save pointer to node
headPtr = headPtr->getNext();
}
else
{

Node<ItemType>* prevPtr = getNodeAt(position - 1);

curPtr = prevPtr->getNext();
prevPtr->setNext(curPtr->getNext());
}
curPtr->setNext( nullptr );
delete curPtr;
curPtr = nullptr ;
itemCount --;
}
return ableToRemove;
}

template < class ItemType>
bool LinkedList<ItemType>::removeSorted( const ItemType& anEntry)
{
bool ableToRemove = false ;
if (!LinkedList<ItemType>::isEmpty())
{
    int position = getPosition(anEntry);
    ableToRemove = position > 0;
    if (ableToRemove)
    ableToRemove = LinkedList<ItemType>::remove(position);
}
return ableToRemove;
}

template< class ItemType>
    ItemType LinkedList<ItemType>::getEntry( int position) const
    {

        Node<ItemType>* nodePtr = getNodeAt(position);
        return nodePtr->getItem();

    }

template < class ItemType>
int LinkedList<ItemType>::getPosition( const ItemType& anEntry) const
{
    int position = 1;
    int length = LinkedList<ItemType>::getLength();
    while ( (position <= length) &&
    (anEntry > LinkedList<ItemType>::getEntry(position)) )
    {
        position++;
    }
    if ( (position > length) ||
    (anEntry != LinkedList<ItemType>::getEntry(position)) )
    {
        position = -position;
    }
    return position;
}

template < class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
return itemCount == 0;
} // end isEmpty

template < class ItemType>
int LinkedList<ItemType>::getLength() const
{
    return itemCount;
} // end getLength

template < class ItemType>
void LinkedList<ItemType>::clear()
{
    while (!isEmpty()){
        remove(1);
}
}

template < class ItemType>
LinkedList<ItemType>::~LinkedList()
{
clear();
} // end destructor

template <class ItemType>
void LinkedList<ItemType>::displayList() const{
    for (int i = 1; i<=getLength();i++){
        getEntry(i).display();
    }
}

template <class ItemType>
void LinkedList<ItemType>::operator=(const LinkedList<ItemType>& right){
        itemCount = right.itemCount;
        Node<ItemType>* origChainPtr = right.headPtr;

    if (origChainPtr == nullptr){
        headPtr = nullptr;
    }
    else{
        headPtr = new Node<ItemType>();
        headPtr->setItem(origChainPtr->getItem());

        Node<ItemType>* newChainPtr = headPtr;
        origChainPtr = origChainPtr->getNext();
        while (origChainPtr != nullptr){
            ItemType nextItem = origChainPtr->getItem();
            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
            newChainPtr->setNext(newNodePtr);
            newChainPtr = newChainPtr->getNext();
            origChainPtr = origChainPtr->getNext();
        }
        newChainPtr->setNext(nullptr);
    }

}

template< class ItemType>
    ItemType* LinkedList<ItemType>::getByIndex( int position)
    {

        Node<ItemType>* nodePtr = getNodeAt(position);
        return nodePtr->getByIndex();

    }

