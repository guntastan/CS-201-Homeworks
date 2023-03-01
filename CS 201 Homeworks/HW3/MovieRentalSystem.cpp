//Student Name: Gün TASTAN
//Section: 3
//Student ID Number: 22101850

#include <string>
#include <iostream>
#include "MovieRentalSystem.h"
#include "LinkedList.cpp"
#include <fstream>


using namespace std;



MovieRentalSystem::MovieRentalSystem(const string movieInfoFileName,const string subscriberInfoFileName){
    string movieFileName = movieInfoFileName;
    string subscrbierFileName = subscriberInfoFileName;
    ifstream inputFileSub;
    ifstream inputFileMovie;
    int counterSub =0;
    int counterMovie =0;
    int sizeOfSubscriber=0;
    int sizeOfMovie=0;
    inputFileSub.open(subscrbierFileName.c_str(),ios_base::in);
    inputFileMovie.open(movieFileName.c_str(),ios_base::in);

    if(inputFileSub&&inputFileMovie){ //IF BOTH TXT FILES EXIST

        while (inputFileSub.eof()==false&&counterSub<=sizeOfSubscriber){
            int subID=0;
            if(counterSub ==0){
                inputFileSub>>sizeOfSubscriber;
            }
            else{
                inputFileSub>>subID;
                Subscriber s1(subID);
                subscribers.insertSorted(s1);
            }
            counterSub++;
        }
        while(inputFileMovie.eof()==false&&counterMovie<=sizeOfMovie){
            int movieID =0;
            int copyNo=0;
            if(counterMovie==0){
                inputFileMovie>>sizeOfMovie;
            }
            else{
                inputFileMovie>>movieID;
                inputFileMovie>>copyNo;
                Movie m1(movieID,copyNo);
                movies.insertSorted(m1);
            }
            counterMovie++;
        }
        cout<<sizeOfSubscriber<<" subscribers and "<<sizeOfMovie<<" movies have been loaded"<<endl;

    }
    else if((!inputFileSub)&&inputFileMovie){
        cout<<"Input file "<<subscrbierFileName<<" does not exist"<<endl;
        while(inputFileMovie.eof()==false&&counterMovie<=sizeOfMovie){
            int movieID =0;
            int copyNo=0;
            if(counterMovie==0){
                inputFileMovie>>sizeOfMovie;
            }
            else{
                inputFileMovie>>movieID;
                inputFileMovie>>copyNo;
                Movie m1(movieID,copyNo);
                movies.insertSorted(m1);
            }
            counterMovie++;
        }

    }
    else if(inputFileSub&& (!inputFileMovie)){
        cout<<"Input file "<<movieFileName<<" does not exist"<<endl;
        while (inputFileSub.eof()==false&&counterSub<=sizeOfSubscriber){
            int subID=0;
            if(counterSub ==0){
                inputFileSub>>sizeOfSubscriber;
            }
            else{
                inputFileSub>>subID;
                addSubscriber(subID);
            }
            counterSub++;
        }
    }
    else{
        cout<<"Input files "<<movieFileName<<" and "<<subscrbierFileName <<" do not exist"<<endl;
    }
    inputFileMovie.close();
    inputFileSub.close();
}



MovieRentalSystem::~MovieRentalSystem(){
    movies.clear();
    subscribers.clear();
}

//This method adds movie to the system. If movie already exists, method
//gives a warning message
void MovieRentalSystem::addMovie(const int movieId, const int numCopies){
    if (movies.getLength()==0){
        Movie addedMovie(movieId, numCopies);
        movies.insertSorted(addedMovie);
        cout<<"Movie "<<movieId<<" has been added"<<endl;
        movieCount++;
    }
    else{
        bool doesExist = false;
        for (int i=1; i<movies.getLength()+1; i++){
            if (movies.getEntry(i).getID()== movieId){
                doesExist = true;
            }
        }
        if(!doesExist){
            Movie addedMovie(movieId, numCopies);
            movies.insertSorted(addedMovie);
            cout<<"Movie "<<movieId<<" has been added"<<endl;
            movieCount++;
        }
        else{
            cout<<"Movie "<<movieId<<" already exists"<<endl;
        }
    }
}

//This method is responsible for renting a movie
void MovieRentalSystem::rentMovie(const int subscriberId, const int movieId){

    bool doesSubExist = false;
    int SubIndex = -1;
    int MovieIndex = -1;
    bool doesMovieExist = false;

    for (int i=1; i<movies.getLength()+1; i++){
        if (movies.getEntry(i).getID()== movieId){ //CHECKS IF MOVIE EXISTS
            doesMovieExist = true;
            MovieIndex = i;
        }
    }
    for (int i=1; i<subscribers.getLength()+1; i++){
        if (subscribers.getEntry(i).getID()== subscriberId){ //CHECK IF SUBSCRIBER EXISTS
            doesSubExist = true;
            SubIndex = i;
        }
    }
    if (doesMovieExist&& (!doesSubExist)){
        cout<<"Subscriber "<<subscriberId<<" does not exist"<<endl;
    }
    else if ((!doesMovieExist)&& doesSubExist){
        cout<<"Movie "<<movieId<<" does not exist"<<endl;
    }
    else if ((!doesMovieExist)&&(!doesSubExist)){
        cout<<"Subscriber "<<subscriberId<<" and movie "<<movieId<<" do not exist"<<endl;
    }
    else{ //IF BOTH OF THEM EXISTS, AND THERE IS AN AVAILABLE COPY OF THE MOVIE; RENTING IS PERFORMED
        if(movies.getByIndex(MovieIndex)->getAvailableCopy()>=1){
            movies.getByIndex(MovieIndex)->decreaseAvailableCopy(); ///////
            Transaction t1(subscriberId,movieId);
            movies.getByIndex(MovieIndex)->addTransaction(t1);
            subscribers.getByIndex(SubIndex)->addTransaction(t1);
            cout<<"Movie "<<movieId<<" has been rented by subscriber "<<subscriberId<<endl;
        }
        else{
            cout<<"Movie "<<movieId<<" has no available copy for renting"<<endl;
        }
    }
}

void MovieRentalSystem::addSubscriber(const int subscriberID){
    Subscriber addedSubscriber(subscriberID);
    subscribers.insertSorted(addedSubscriber);
    subscribeCount++;
}
void MovieRentalSystem::showAllMovies()const{
    cout<<"Movies in the movie rental system:"<<endl;
    movies.displayList();
}
void MovieRentalSystem::showAllSubscribers()const{
    cout<<"Subscribers in the movie rental system:"<<endl;
    subscribers.displayList();
}
void MovieRentalSystem::showMoviesRentedBy(const int subscriberId) const{
    bool doesSubExist = this->doesSubscriberExist(subscriberId);
    if(!doesSubExist){
        cout<<"Subscriber "<< subscriberId<<" does not exist"<<endl;
    }
    else{
        int indexSub = this->findSubscriberIndex(subscriberId);
        if(subscribers.getEntry(indexSub).getNumberOfTransaction()==0){
            cout<<"Subscriber "<<subscriberId<<" has not rented any movies"<<endl;
        }
        else{
            cout<<"Subscriber "<<subscriberId<<" has rented the following movies:"<<endl;
            subscribers.getEntry(indexSub).displayTransactions();
        }

    }
}
void MovieRentalSystem::showSubscribersWhoRentedMovie(const int movieId)const{
    bool doesMovieExist = this->doesMovieExist(movieId);
    if(!doesMovieExist){
        cout<<"Movie "<<movieId<<" does not exist"<<endl;
    }
    else{
        int indexMovie = this->findMovieIndex(movieId);
        if(movies.getEntry(indexMovie).getNumberOfTransaction()==0){
            cout<<"Movie "<<movieId<<" has not been rented by any subscriber"<<endl;
        }
        else{
            cout<<"Movie "<<movieId<<" has been rented by the following subscribers:"<<endl;
            movies.getEntry(indexMovie).displayTransactions();
        }
    }
}
bool MovieRentalSystem::doesMovieExist(int movieID)const{
    bool doesExist = false;

    for(int i=1; i<=movies.getLength();i++){
        if(movies.getEntry(i).getID()==movieID){
            doesExist = true;
        }
    }
    return doesExist;
}

bool MovieRentalSystem::doesSubscriberExist(int subscriberID)const{
    bool doesMovieExist =false;

    for (int i=1; i<=subscribers.getLength();i++){
        if(subscribers.getEntry(i).getID()==subscriberID){
            doesMovieExist = true;
        }
    }
    return doesMovieExist;
}
int MovieRentalSystem::findMovieIndex(int movieID)const{
    int movieIndex = -1;

    for(int i=1; i<=movies.getLength();i++){
        if(movies.getEntry(i).getID()==movieID){
            movieIndex =i;
        }
    }
    return movieIndex;
}
int MovieRentalSystem::findSubscriberIndex(int subscriberID)const{
    int subIndex = -1;

    for(int i=1; i<=subscribers.getLength();i++){
        if(subscribers.getEntry(i).getID()==subscriberID){
            subIndex =i;
        }
    }
    return subIndex;
}

//THIS METHOD IS RESPONSIBLE FOR RETURNING OF A MOVIE
void MovieRentalSystem::returnMovie( const int subscriberId, const int movieId){
    bool doesSubExist = this->doesSubscriberExist(subscriberId);
    bool doesMovieExist = this->doesMovieExist(movieId);
    if(doesSubExist&&(!doesMovieExist)){
        cout<<"No rental transaction for subscriber "<<subscriberId<<" and movie "<<movieId<<endl;
    }
    else if((!doesSubExist)&&doesMovieExist){
        cout<<"No rental transaction for subscriber "<<subscriberId<<" and movie "<<movieId<<endl;
    }
    else if ((!doesSubExist)&&(!doesMovieExist)){
        cout<<"No rental transaction for subscriber "<<subscriberId<<" and movie "<<movieId<<endl;
    }
    else{ //IF BOTH SUBSCRIBER AND MOVIE

        int subIndex = findSubscriberIndex(subscriberId);
        int movieIndex = findMovieIndex(movieId);

        bool doesSubHas = subscribers.getByIndex(subIndex)->doesTransactionExist(movieId);
        bool doesMovieHas = movies.getByIndex(movieIndex)->doesTransactionExist(subscriberId);

        //IF THEY BOTH HAVE THE TRANSACTIONS OF EACH OTHER

        if(doesSubHas&&doesMovieHas){
            // IF BOTH OF THEM THE TRANSACTION RECORDS, IT CHECKS WHETER MOVIE IS ALREADY RETURNED OR NOT
            bool hasReturnedAll = movies.getEntry(movieIndex).hasReturnedAll(subscriberId);
            bool hasReturnedAll2 = subscribers.getEntry(subIndex).hasReturnedAll(movieId);
            if(!hasReturnedAll && !hasReturnedAll2){
                //IF IT IS NOT RETURNED, RETURNING OPERATION IS PERFORMED
                movies.getByIndex(movieIndex)->increaseAvailableCopy();
                subscribers.getByIndex(subIndex)->changeReturnStatus(movieId);
                movies.getByIndex(movieIndex)->changeReturnStatus(subscriberId);

                cout<<"Movie "<<movieId<<" has been returned by subscriber "<<subscriberId<<endl;
            }
            else{
                cout<<"No rental transaction for subscriber "<<subscriberId<<" and movie "<<movieId<<endl;
            }

        }
        else{
            cout<<"No rental transaction for subscriber "<<subscriberId<<" and movie "<<movieId<<endl;
        }
    }
}
void MovieRentalSystem::removeMovie(const int movieId ){
    bool doesExist = this->doesMovieExist(movieId);
    if(doesExist){
        int indexOfMovie = this->findMovieIndex(movieId);
        if(movies.getEntry(indexOfMovie).getAvailableCopy()==movies.getEntry(indexOfMovie).getNumOfCopy()){
            movies.remove(indexOfMovie);
            cout<<"Movie "<<movieId<<" has been removed"<<endl;
        }
        else{
            cout<<"Movie "<<movieId<<" cannot be removed -- at least one copy has not been returned"<<endl;
        }
    }
    else{
        cout<<"Movie "<<movieId<<" does not exist"<<endl;
    }
}
void MovieRentalSystem::removeSubscriber(const int subscriberId){
    bool doesExist = this->doesSubscriberExist(subscriberId);
    if(doesExist){
        int indexOfSubscriber = this->findSubscriberIndex(subscriberId);
        bool hasReturnedAllMovies = subscribers.getEntry(indexOfSubscriber).hasReturnedAllOfMovies();
        if(hasReturnedAllMovies){
            cout<<"Subscriber "<<subscriberId<<" has been removed"<<endl;
            subscribers.remove(indexOfSubscriber);
            for(int i=1;i<=movies.getLength();i++){
                for(int j=1;j<=movies.getEntry(i).getNumberOfTransaction();j++){
                    if(movies.getEntry(i).doesTransactionExist(subscriberId)){
                        movies.getByIndex(i)->removeTransactionsOfSubscriber(subscriberId);
                        j--;
                    }
                }
            }
        }
        else{
            cout<<"Subscriber "<<subscriberId<<" cannot be removed -- at least one movie has not been returned"<<endl;
        }
    }
    else{
        cout<<"Subscriber "<<subscriberId<<" does not exist"<<endl;
    }
}

void MovieRentalSystem::operator=(const MovieRentalSystem &right){
    this->movies = right.movies;
    this->subscribers = right.subscribers;
    this->movieCount = right.movieCount;
    this->subscribeCount = right.subscribeCount;
}
MovieRentalSystem::MovieRentalSystem(const MovieRentalSystem &otherMovieRentalSystem){
    movies = otherMovieRentalSystem.movies;
    subscribers = otherMovieRentalSystem.subscribers;
    movieCount = otherMovieRentalSystem.movieCount;
    subscribeCount = otherMovieRentalSystem.subscribeCount;
}

