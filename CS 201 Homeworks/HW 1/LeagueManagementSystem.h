///////////////////// GUN TASTAN - SECTION 3 - 22101850//////////////////////

#ifndef  LEAGUE_MANAGEMENT
#define LEAGUE_MANAGEMENT

#include <iostream>
#include <string>

#include "Player.h"
#include "Team.h"

class LeagueManagementSystem {

private:
    int leagueSize;
    Team *teams{nullptr} ;

public:
    LeagueManagementSystem();
    ~LeagueManagementSystem();
    void addTeam( const string name, const int year );
    void removeTeam( const string name );

    void addPlayer( const string teamName, const string playerName,
        const int jersey, const int salary );

    void removePlayer( const string teamName, const string playerName );

    void transferPlayer( const string playerName,
        const string departTeamName, const string arriveTeamName );


    void showAllTeams() const;
    void showTeam( const string name ) const;
    void showPlayer( const string name ) const;

    void displayTeams();



};

#endif
