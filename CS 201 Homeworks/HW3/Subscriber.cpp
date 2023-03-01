//Student Name: Gün TASTAN
//Section: 3
//Student ID Number: 22101850


#include "Subscriber.h"
#include <iostream>
#include "LinkedList.cpp"
#include <string>

using namespace std;

Subscriber::Subscriber(int anID){
    this->subscriberID = anID;

}

Subscriber::~Subscriber(){
    subscriberTransaction.clear();
}

void Subscriber::operator=( const Subscriber& right){
    this->subscriberID= right.subscriberID;
    this->subscriberTransaction = right.subscriberTransaction;

}

bool Subscriber::operator>(const Subscriber& right) const{
    if (this->subscriberID>right.subscriberID){
        return true;
    }
    return false;
}
bool Subscriber:: operator !=(const Subscriber& right){
    if(subscriberID != right.subscriberID){
        return true;
    }
    return false;
}

Subscriber::Subscriber(const Subscriber &otherSubscriber ){
    subscriberID = otherSubscriber.getID();
    subscriberTransaction = otherSubscriber.subscriberTransaction;
}

int Subscriber::getID() const{
    return subscriberID;
}


void Subscriber::display() const{
    cout<< subscriberID<<endl;
}

void Subscriber::addTransaction(Transaction tran){
    subscriberTransaction.insertSorted(tran);
}
void Subscriber::displayTransactions(){
    for(int i=1;i<=subscriberTransaction.getLength();i++){ //
        subscriberTransaction.getEntry(i).displayForSubscriber();
    }
}
bool Subscriber::doesTransactionExist(int movieID){ //checks wheter a subscriber has transaction with given movie id
    bool doesExist = false;
    for(int i=1;i<=subscriberTransaction.getLength();i++){
        if(subscriberTransaction.getEntry(i).getMovieID()==movieID){
            doesExist = true;
        }
    }
    return doesExist;
}
int Subscriber::findTransaction(int movieID){ //finds the transaction which has the given movie id in history of subscriber
    int index = -1;
    for(int i=1; i<=subscriberTransaction.getLength();i++){
        if(subscriberTransaction.getEntry(i).getMovieID()==movieID&& (!subscriberTransaction.getEntry(i).getIsReturned())){
            index = i;
            break;
        }
    }
    return index;
}
void Subscriber::changeReturnStatus(int movieID){
    int transactionIndex = this->findTransaction(movieID);
    subscriberTransaction.getByIndex(transactionIndex)->changeReturnStatus();
}
bool Subscriber::hasReturnedAll(int movieID){ //Checks whether a subscriber returned all of his/Her movies
    int counter =0;
    bool hasReturnedAll =true;
    for(int i=1; i<=subscriberTransaction.getLength();i++){
        if(subscriberTransaction.getEntry(i).getMovieID()==movieID && (!subscriberTransaction.getEntry(i).getIsReturned())){
            counter++;
        }
    }
    if(counter>0){
        hasReturnedAll = false;
    }
    return hasReturnedAll;

}
//CHECKS WHETER A SUBSCRIBER HAS RETURNED ALL OF HIS/HER MOVIES
//MEANING THAT, CHECKS IF ALL THE TRANSACTIONS HAS RETURNED PROPERTY
bool Subscriber::hasReturnedAllOfMovies(){
    bool hasReturnedAllOfTheMovies = false;
    int counter =0;
    for (int i=1; i<=subscriberTransaction.getLength();i++){
        if(subscriberTransaction.getEntry(i).getIsReturned()==true){
            counter++;
        }
    }
    if(counter==subscriberTransaction.getLength()){
        hasReturnedAllOfTheMovies =true;
    }
    return hasReturnedAllOfTheMovies;
}





