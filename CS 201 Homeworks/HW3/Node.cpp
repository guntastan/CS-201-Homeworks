//Student Name: Gün TASTAN
//Section: 3
//Student ID Number: 22101850


#include "Node.h"
#include <cstddef>

//I HAVE USED THE NODE CLASS BELOW FROM OUR COURSEBOOK/TEXTBOOK: CARRANO

template < class ItemType>
Node<ItemType>::Node() : next( nullptr )
{
}
template < class ItemType>
Node<ItemType>::Node( const ItemType& anItem) : item(anItem), next( nullptr )
{
}
template < class ItemType>
Node<ItemType>::Node( const ItemType& anItem, Node<ItemType>* nextNodePtr) :
item(anItem), next(nextNodePtr)
{
}
template < class ItemType>
void Node<ItemType>::setItem( const ItemType& anItem)
{
item = anItem;
}
template < class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
next = nextNodePtr;
}
template < class ItemType>
ItemType Node<ItemType>::getItem() const
{
return  item;
}
template < class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
return next;
}

template < class ItemType>
ItemType* Node<ItemType>::getByIndex()
{
    ItemType* itemptr = &item;
    return  itemptr;
}
