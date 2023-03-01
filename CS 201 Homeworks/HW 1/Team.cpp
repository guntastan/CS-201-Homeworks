///////////////////// GUN TASTAN - SECTION 3 - 22101850//////////////////////



#include "Team.h"
#include <string>
#include  "Player.h"

using namespace std;

Team::Team(string aName, int aYear)
{
    name = aName;
    year = aYear;
    teamSize=0;
    totalSalary =0;
    //players =new Player[teamSize];
    players = nullptr; //newly added

}
Team::Team(){
    name="";
    year= 0;
    players = nullptr;
}
Team::~Team(){
    if(players !=nullptr){
        delete [] players;
    }
}
void Team::addPlayer(string playerName, int playerJerseyNum, int playerSalary){
    bool doesExist = false;
    for (int i= 0;i<teamSize;i++){
        if (players[i].getJerseyNumber()== playerJerseyNum){
            doesExist = true;
        }
    }
    if (!doesExist){
        teamSize++;
        Player newPlayer(playerName,playerJerseyNum,playerSalary);
        Player *newPlayers = new Player[teamSize];

        for(int i=0; i<teamSize-1; i++){
            newPlayers[i] = players[i];
        }
        newPlayers[teamSize-1]= newPlayer;

        if(players !=nullptr){
            delete [] players;
        }

        players = newPlayers;
        cout<<"Added player "<<playerName<<" to team "<<name<<endl;
    }
    else{
        cout<<"Cannot add player. Jersey number "<< playerJerseyNum <<" already exists in team "<< name<<"."<<endl;
    }

}
void Team::removePlayer(string playerName){
    bool playerExist = false;
    for (int i=0; i<teamSize;i++){
        if(players[i].getName()== playerName){
            playerExist = true;
        };
    };
    if(playerExist){


        bool *playersToKeep = new bool[teamSize];
        int entries =0;
        for (int i=0; i!=teamSize;++i){
            if(players[i].getName() != playerName){
                playersToKeep[i]=true;
                entries++;
            }
            else{
                playersToKeep[i]= false;
            }
        }
        Player *updatedTeam = new Player[teamSize-1];
        int i= 0;
        int j= 0;
        while (i<teamSize&&j<teamSize-1){
            if(playersToKeep[i]){
                updatedTeam[j]=players[i];
                j++;
            }
            i++;
        }
        delete [] playersToKeep;
        delete [] players;
        players = updatedTeam;
        teamSize--;
        cout<<"Removed player "<<playerName<<" from team "<<name<<endl;
    }

    else{
        cout<<"Cannot remove player. Player "<< playerName<< " does not exist."<<endl;
    }
}
void Team::displayPlayers(){
    for (int i=0; i<teamSize;i++){
        cout<<players[i].getName()<<", jersey "<< players[i].getJerseyNumber()<<", "<<players[i].getSalary()<<" TL salary"<<endl;
    }
}
string Team::getName(){
    return name;
}
int Team::getTeamSize(){
    return teamSize;
}

void Team::removeAllPlayers(){
    delete [] players;
}

int Team::getTotalSalary(){
    totalSalary=0;
    for (int i= 0; i<teamSize;i++){
        totalSalary = totalSalary + players[i].getSalary();
    }
    return totalSalary;
}
int Team::getYear(){
    return year;
}
Player * Team::getPlayers(){
    return players;
}
bool Team::doesInclude(string aName){
    int playersIndex=-1;
    for(int i= 0; i<teamSize;i++){
        if(players[i].getName()==aName){
            playersIndex=i;
            return true;
        }
    }
    return false;
}
int Team::getJersey(string aName){
    int playersIndexatTeam = -1;
    for (int i=0; i<teamSize;i++){
        if(players[i].getName()==aName){
            playersIndexatTeam=i;
        }
    }
    return players[playersIndexatTeam].getJerseyNumber();
}
int Team::getSalary(string aName){
    int playersIndexatTeam = -1;
    for (int i=0; i<teamSize;i++){
        if(players[i].getName()==aName){
            playersIndexatTeam=i;
        }
    }
    return players[playersIndexatTeam].getSalary();
}


void Team::transferAdd( string playerName,  int playerJerseyNum,  int playerSalary, string depName,  string arrName){
    bool jerseyExist=false;

    for (int i=0; i<teamSize;i++){
        if(players[i].getJerseyNumber()==playerJerseyNum){
            jerseyExist=true;
        }
    }

    if (!jerseyExist){
        teamSize++;
        Player newPlayer(playerName,playerJerseyNum,playerSalary);
        Player *newPlayers = new Player[teamSize];

        for(int i=0; i<teamSize-1; i++){
            newPlayers[i] = players[i];
            }
        newPlayers[teamSize-1]= newPlayer;
        delete [] players;
        players = newPlayers;
        cout<<"Transferred player "<<playerName<<" from "<<depName<<" to "<<arrName<<"."<<endl;

    }
    else{
        cout<<"Cannot transfer player. Jersey number "<< playerJerseyNum <<" already exists in team "<< name<<"."<<endl;
    }
}

bool Team::doesJerseyExist(int jerseyNum){
        bool jerseyExist=false;

    for (int i=0; i<teamSize;i++){
        if(players[i].getJerseyNumber()==jerseyNum){
            jerseyExist=true;
        }
    }
    return jerseyExist;
}

void Team::transferRemove(string aName){
        bool *playersToKeep = new bool[teamSize];
        int entries =0;
        for (int i=0; i!=teamSize;++i){
            if(players[i].getName() != aName){
                playersToKeep[i]=true;
                entries++;
            }
            else{
                playersToKeep[i]= false;
            }
        }
        Player *updatedTeam = new Player[entries];
        int i= 0;
        int j= 0;
        while (i!=teamSize&&j!=entries){
            if(playersToKeep[i]){
                updatedTeam[j++]=players[i];
            }
            i++;
        }
        delete [] playersToKeep;
        delete [] players;
        players = updatedTeam;
        teamSize--;
}




