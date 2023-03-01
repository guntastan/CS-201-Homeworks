///////////////////// GUN TASTAN - SECTION 3 - 22101850//////////////////////

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
using namespace std;

class Player
{
private:
    string name;
    int jerseyNumber;
    int salary;

public:
    Player(string aName, int aJerseyNumber, int aSalary);
    Player();

    void SetPlayer(string name,int jerseyNumber,int salary);

    void displayName() {cout<< name<<endl;}
    void displayJerseyNumber() { cout<< jerseyNumber<<endl; }
    void displaySalary()  { cout<< salary<<endl; }
    int getJerseyNumber();
    string getName();
    int getSalary();
};

#endif



