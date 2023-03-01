//Student Name: Gün TASTAN
//Section: 3
//Student ID Number: 22101850


#include "Movie.h"
#include <iostream>
#include <string>
#include "LinkedList.cpp"

using namespace std;

Movie::Movie( int ID,  int copies){
    this->movieID = ID;
    setCopyNo(copies);
    for (int i=1; i<=copies;i++){
        availableCopy = availableCopy+1;
    }
}

Movie::~Movie(){
    movieTransaction.clear();
}

void Movie::operator=( const Movie& right){
    this->movieID= right.movieID;
    this->numOfCopy= right.numOfCopy;
    this->availableCopy = right.availableCopy;
    this->movieTransaction = right.movieTransaction;
}

bool Movie::operator>(const Movie& right) const{
    if (this->movieID>right.movieID){
        return true;
    }
    return false;
}
bool Movie::operator!=(const Movie& right) const{
    if (movieID != right.movieID){
        return true;
    }
    return false;
}

Movie::Movie(const Movie &otherMovie ){
    movieID= otherMovie.getID();
    numOfCopy = otherMovie.getNumOfCopy();
    availableCopy = otherMovie.getAvailableCopy();
    movieTransaction = otherMovie.movieTransaction;
}

int Movie::getID() const{
    return movieID;
}

int Movie::getNumOfCopy()const{
    return numOfCopy;
}
int Movie::getAvailableCopy()const{
    return availableCopy;
}

void Movie::setCopyNo(int aCopyNo){
    numOfCopy = aCopyNo;
}


void Movie::display() const{
    cout<< movieID<<" "<<numOfCopy<<endl;

}

void Movie::addTransaction(Transaction t1){
    movieTransaction.insertSorted(t1);
}

void Movie::displayTransactions(){
    for (int i=1; i<=movieTransaction.getLength();i++){ //oynandý
        movieTransaction.getEntry(i).displayForMovie();
    }
}

void Movie::setAvailableNo(int availableCopyNo){
    availableCopy = availableCopyNo;
}
void Movie::decreaseAvailableCopy(){
    availableCopy--;
}
void Movie::increaseAvailableCopy(){
    availableCopy++;
}
bool Movie::doesTransactionExist(int subscriberID){
    bool doesExist = false;
    for (int i=1; i<=movieTransaction.getLength();i++){
        if(movieTransaction.getEntry(i).getSubscriberID()==subscriberID){
            doesExist=true;
        }
    }
    return doesExist;
}
int Movie::findTransaction(int subID){
    int index = -1;
    for(int i=1; i<=movieTransaction.getLength();i++){
        if(movieTransaction.getEntry(i).getSubscriberID()==subID && (!movieTransaction.getEntry(i).getIsReturned())){
            index = i;
            break;
        }
    }
    return index;
}
void Movie::changeReturnStatus(int subID){
    int transactionIndex = this->findTransaction(subID);
    movieTransaction.getByIndex(transactionIndex)->changeReturnStatus();
}

bool Movie::hasReturnedAll(int subID){
    int counter =0;
    bool hasReturnedAll =true;
    for(int i=1; i<=movieTransaction.getLength();i++){
        if(movieTransaction.getEntry(i).getSubscriberID()==subID && (!movieTransaction.getEntry(i).getIsReturned())){
            counter++;
        }
    }
    if(counter>0){
        hasReturnedAll = false;
    }
    return hasReturnedAll;

}
//When subscriber is removed from the movie rental system, this method deletes all of the
//transactions that subscriber has contributed from the transactions of a certain movie
void Movie::removeTransactionsOfSubscriber(int subscriberID){
    for(int i=1;i<=movieTransaction.getLength();i++){
        if(movieTransaction.getEntry(i).getSubscriberID()==subscriberID){
            movieTransaction.remove(i);
        }
    }
}
