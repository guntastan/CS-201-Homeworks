//Student Name: Gün TASTAN
//Section: 3
//Student ID Number: 22101850


#include "Transaction.h"
#include <iostream>
#include <string>


using namespace std;

Transaction::Transaction(int aSubscriberID, int aMovieID){
    this->subscriberID = aSubscriberID;
    this->movieID = aMovieID;

}


void Transaction::operator=( const Transaction& right){
    this->subscriberID = right.subscriberID;
    this->movieID = right.movieID;
    this->isReturned = right.isReturned;

}
//Overloading this > operator is critical because of the
//output concerns. Since sorting cannot be done only comparing ID's
//it should also makes sures that Transactions are sorted
//according to their return status's as well.
bool Transaction::operator>(const Transaction& right) const{
        if(subscriberID == right.subscriberID){
            if(movieID>right.movieID){
                return true;
            }
            else if(movieID==right.movieID){
                if(isReturned==true&&right.isReturned==false){
                    return false;
                }// Considering return status as well
                else if(isReturned==false&&right.isReturned==true){
                    return true;
                }
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if(subscriberID>right.subscriberID){
                return true;
            }
            else if(subscriberID==right.subscriberID){
                if(isReturned==true&&right.isReturned==false){// Considering return status as well
                    return false;
                }
                else if(isReturned==false&&right.isReturned==true){
                    return true;
                }
                return true;
            }
            else{
                return false;
            }
        }

}
bool Transaction::operator!=(const Transaction& right) const{
    if ((movieID != right.movieID) && (subscriberID != right.subscriberID)&& (isReturned != right.isReturned) ){
        return true;
    }
    return false;
}

Transaction::Transaction(const Transaction &otherTransaction ){
    this->subscriberID = otherTransaction.getSubscriberID();
    this->movieID = otherTransaction.getMovieID();
    this->isReturned = otherTransaction.getIsReturned();
}

void Transaction::displayForSubscriber(){
    if(isReturned){
        cout<<movieID<< " "<< "returned"<<endl;
    }
    else{
        cout<<movieID<< " "<<"not returned"<<endl;
    }
}
void Transaction::displayForMovie(){
    if(isReturned){
        cout<<subscriberID<< " "<< "returned"<<endl;
    }
    else{
        cout<<subscriberID<< " "<<"not returned"<<endl;
    }
}

