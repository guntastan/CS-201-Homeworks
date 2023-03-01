//Student Name: Gün TASTAN
//Section: 3
//Student ID Number: 22101850


#ifndef _MOVIE_RENTAL_SYSTEM_H
#define _MOVIE_RENTAL_SYSTEM_H


#include <string>

#include "Movie.h"
#include "Subscriber.h"

using namespace std;

class MovieRentalSystem {
public:

    MovieRentalSystem( const string movieInfoFileName,const string subscriberInfoFileName );

    ~MovieRentalSystem();

    void removeMovie( const int movieId );
    void addMovie( const int movieId, const int numCopies );

    void removeSubscriber( const int subscriberId );

    void rentMovie( const int subscriberId, const int movieId );
    void returnMovie( const int subscriberId, const int movieId );

    void showMoviesRentedBy( const int subscriberId ) const;
    void showSubscribersWhoRentedMovie( const int movieId ) const;

    void showAllMovies() const;
    void showAllSubscribers() const;



    void addSubscriber(const int subscriberID);

    int getNumberofMovies(){return movieCount;};
    int getNumberofSubscribers(){return subscribeCount;};




    bool doesMovieExist(int movieID)const;
    bool doesSubscriberExist(int subscriberID)const;
    int findMovieIndex(int movieID)const;
    int findSubscriberIndex(int subscriberID) const;

    MovieRentalSystem(const MovieRentalSystem &otherMovieRentalSystem);
    void operator=(const MovieRentalSystem& right);





private:
    LinkedList<Movie> movies;
    LinkedList<Subscriber> subscribers;

    int movieCount = 0;
    int subscribeCount = 0;
};


#endif
