//Student Name: Gün TASTAN
//Section: 3
//Student ID Number: 22101850


#ifndef __SUBSCRIBER_H
#define __SUBSCRIBER_H

#include "LinkedList.h"
#include <string>
#include "Transaction.h"
using namespace std;

class Subscriber{

    private:
        int subscriberID;
        LinkedList<Transaction> subscriberTransaction;



    public:

        Subscriber (int anID=0);
        Subscriber( const Subscriber &otherSubscriber );
        ~Subscriber();

        void operator=(const Subscriber& right);
        bool operator>(const Subscriber& right) const;
        bool operator !=(const Subscriber& right);

        int getID() const;
        void display() const;

        void addTransaction(Transaction tran);
        void displayTransactions();

        int getNumberOfTransaction()const{return subscriberTransaction.getLength();};

        bool doesTransactionExist(int movieID);
        void changeReturnStatus(int subID);
        int findTransaction(int subID);


        bool hasReturnedAll(int movieID);
        bool hasReturnedAllOfMovies();

};

#endif

