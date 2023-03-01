//Student Name: Gün TASTAN
//Section: 3
//Student ID Number: 22101850


#ifndef __TRANSACTION_H
#define __TRANSACTION_H

#include <string>
using namespace std;

class Transaction{

    private:
        int subscriberID;
        int movieID;
        bool isReturned = false;



    public:

        Transaction (int aSubscriberID, int aMovieID);
        Transaction( const Transaction &otherTransaction );
        Transaction(){subscriberID = 0,movieID = 0;};



        void operator=(const Transaction& right);
        bool operator>(const Transaction& right) const;
        bool operator !=(const Transaction& right) const;

        int getSubscriberID()const{return subscriberID;};
        int getMovieID()const{return movieID;};
        bool getIsReturned()const{return isReturned;};

        void changeReturnStatus(){isReturned = !isReturned;};

        void displayForSubscriber();
        void displayForMovie();

};

#endif


