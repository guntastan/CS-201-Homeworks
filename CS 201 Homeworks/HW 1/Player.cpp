///////////////////// GUN TASTAN - SECTION 3 - 22101850//////////////////////



#include "Player.h"
#include <string>

using namespace std;


Player::Player(string aName, int aJerseyNumber, int aSalary)
{
    SetPlayer(aName, aJerseyNumber,aSalary);
}
Player::Player(){
    name = "";
    jerseyNumber =0;
    salary = 0;
}

void Player::SetPlayer(string aName, int aJerseyNumber, int aSalary)
{
    name = aName;
    jerseyNumber = aJerseyNumber;
    salary = aSalary;
}
int Player::getJerseyNumber(){
    return jerseyNumber;
}
string Player::getName(){
    return name;
}
int Player::getSalary(){
    return salary;
}

