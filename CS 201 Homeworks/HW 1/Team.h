///////////////////// GUN TASTAN - SECTION 3 - 22101850//////////////////////


#ifndef  TEAM_H
#define TEAM_H

#include <iostream>
#include <string>

#include "Player.h"

using namespace std;

class Team
{
private:
    string name;
    int year;
    int teamSize;
    int totalSalary;
    Player *players{nullptr};

public:
    Team(string aName, int aYear);
    Team();
    ~Team();

    void SetTeam(string aName, int aYear);

    void displayName() {cout<< name<<endl;}
    void displayYear() { cout<< year<<endl;}
    void addPlayer(string playerName, int playerJerseyNum, int playerSalary);
    void removePlayer(string playerName);
    void displayPlayers();
    string getName();
    int getTeamSize();
    void removeAllPlayers();
    int getTotalSalary();
    int getYear();
    Player * getPlayers();
    bool doesInclude(string aName);
    bool doesJerseyExist(int jerseyNum);


    void transferAdd(string playerName,  int playerJerseyNum,  int playerSalary, string depName,  string arrName);
    void transferRemove(string aName);
    int getJersey(string aName);
    int getSalary(string aName);


};

#endif




