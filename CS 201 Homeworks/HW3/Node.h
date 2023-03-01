//Student Name: Gün TASTAN
//Section: 3
//Student ID Number: 22101850


#ifndef _NODE
#define _NODE

//I HAVE USED THE NODE CLASS BELOW FROM OUR COURSEBOOK/TEXTBOOK: CARRANO

template < class ItemType>
class Node
{
private :
ItemType item;
Node<ItemType>* next;

public :

Node();
Node( const ItemType& anItem);
Node( const ItemType& anItem, Node<ItemType>* nextNodePtr);
void setItem( const ItemType& anItem);
void setNext(Node<ItemType>* nextNodePtr);
ItemType getItem() const ;
Node<ItemType>* getNext() const ;


ItemType* getByIndex();


};

#endif
