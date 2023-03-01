//Student Name: Gün TASTAN
//Section: 3
//Student ID Number: 22101850


#ifndef __MOVIE_H
#define __MOVIE_H

#include <string>
#include "Transaction.h"
#include"LinkedList.h"

using namespace std;

class Movie{

    private:
        int movieID;
        int numOfCopy;
        int availableCopy=0;
        LinkedList<Transaction> movieTransaction;

    public:
        int numberOfTransaction=0;
        Movie ( int ID=0,  int copies=0);
        Movie( const Movie &otherMovie );
        ~Movie();


        void operator=(const Movie& right);
        bool operator>(const Movie& right) const;
        bool operator !=(const Movie& right) const;

        int getID() const;
        int getNumOfCopy() const;
        int getAvailableCopy() const ;

        void setCopyNo(int aCopyNo);
        void setAvailableNo(int availableCopyNo);

        void display() const;

        void addTransaction(Transaction t1);
        void displayTransactions();
        int getNumberOfTransaction()const{return movieTransaction.getLength();};
        void decreaseAvailableCopy();
        void increaseAvailableCopy();

        bool doesTransactionExist(int subscriberID);
        void changeReturnStatus(int subID);
        int findTransaction(int subID);

        bool hasReturnedAll(int subID);

        void removeTransactionsOfSubscriber(int subscriberID);


};

#endif
