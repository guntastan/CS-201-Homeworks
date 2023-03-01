///////////////////// GUN TASTAN - SECTION 3 - 22101850//////////////////////



#include "LeagueManagementSystem.h"
#include "Team.h"
#include "Player.h"

#include <iostream>
#include <string>
 using namespace std;

 LeagueManagementSystem::LeagueManagementSystem(){
    leagueSize = 0;
    teams = nullptr;
 }
LeagueManagementSystem::~LeagueManagementSystem(){
    if(teams !=nullptr){
        delete []teams;
    }

};

 void LeagueManagementSystem::addTeam(const string aName, const int aYear){
        bool doesExist = false;
        for (int i= 0;i<leagueSize;i++){
            if (teams[i].getName()== aName){
                doesExist = true;
            }
        }
        if (!doesExist){
            leagueSize++;
            Team newTeam(aName,aYear);
            Team *newTeams = new Team[leagueSize];
            for (int i= 0; i<leagueSize-1;i++){
                newTeams[i]= teams[i];
            }
            newTeams[leagueSize-1]= newTeam;

            if(teams !=nullptr){
                delete [] teams;
            }

            teams = newTeams;
            cout<<"Added team "<< aName<<"."<<endl;
        }
        else{
            cout<<"Cannot add team. Team "<< aName<<" already exists."<<endl;
        }
 }

void LeagueManagementSystem::addPlayer(const string teamName, const string playerName,const int jersey, const int salary){

    bool teamExist = false;
    int toBeAdded=-1;
    for (int i = 0; i<leagueSize;i++){
        if (teams[i].getName()==teamName){
            teamExist =true;
            toBeAdded=i;
        }
    }
    if(teamExist){
        teams[toBeAdded].addPlayer(playerName,jersey,salary);
    }
    if(teamExist ==false){
        cout<<"Cannot add player. Team "<< teamName<<" does not exist."<<endl;
    }
}

void LeagueManagementSystem::removeTeam(const string name){
    bool teamExist = false;
    int index = -1;
    for  (int i = 0; i<leagueSize;i++){
        if (teams[i].getName()== name){
            teamExist=true;
            index =i;
        }
    }
    if(teamExist){
       teams[index].removeAllPlayers();
       bool *teamsToKeep = new bool[leagueSize];
        int entries =0;
        for (int i=0; i!=leagueSize;++i){
            if(teams[i].getName() != name){
                teamsToKeep[i]=true;
                entries++;
            }
            else{
                teamsToKeep[i]= false;
            }
        }
        Team *updatedLeague = new Team[entries];
        int i= 0;
        int j= 0;
        while (i!=leagueSize&&j!=entries){
            if(teamsToKeep[i]){
                updatedLeague[j++]=teams[i];
            }
            i++;
        }
        delete [] teamsToKeep;
        delete [] teams;
        teams = updatedLeague;
        leagueSize--;
        cout<<"Removed team "<<name<<"."<<endl;
    }
    else{
        cout<<"Cannot remove team. Team "<< name<<" does not exist."<<endl;
    }

}
void LeagueManagementSystem::removePlayer(const string teamName, const string playerName){
    bool teamExist = false;
    bool playerExist = false;
    int teamIndex = -1;

    for (int i=0; i<leagueSize;i++){
        if(teams[i].getName()==teamName){
            teamExist=true;
            teamIndex=i;
        }
    }
    if(teamExist){
        teams[teamIndex].removePlayer(playerName);
    }
    else{
        cout<<"Cannot remove player. Team "<<teamName<<" does not exist."<<endl;
    }
}
void LeagueManagementSystem::transferPlayer(const string playerName,const string departTeamName, const string arriveTeamName){
    bool doesDepartExist = false;
    bool doesArriveExist= false;
    bool doesPlayerExist = false;
    int departPlayerTeamIndex=-1;
    int arrivePlayerTeamIndex=-1;
    for (int i = 0; i<leagueSize;i++){
        if(teams[i].getName()==departTeamName){
            doesDepartExist=true;
            departPlayerTeamIndex=i;
        }
        if(teams[i].getName()==arriveTeamName){
            arrivePlayerTeamIndex=i;
            doesArriveExist=true;
        }
    }
    string copyPlayerName = playerName;
    string copyDepartTeamName = departTeamName;
    string copyArriveTeamName = arriveTeamName;
    doesPlayerExist= teams[departPlayerTeamIndex].doesInclude(playerName);
    if(doesArriveExist&&doesDepartExist&&doesPlayerExist){
        teams[arrivePlayerTeamIndex].transferAdd(copyPlayerName,teams[departPlayerTeamIndex].getJersey(copyPlayerName),teams[departPlayerTeamIndex].getSalary(
                                                                                                                                                              copyPlayerName),copyDepartTeamName,copyArriveTeamName);

        if(teams[departPlayerTeamIndex].doesJerseyExist(teams[departPlayerTeamIndex].getJersey(copyPlayerName))){
            teams[departPlayerTeamIndex].transferRemove(copyPlayerName);
        }
    }
    else if (doesArriveExist&&doesDepartExist&&(!doesPlayerExist)){
        cout<<"Cannot transfer player.Player "<< copyPlayerName<<" does not exist in team "<<copyDepartTeamName<<endl;
    }
    else if(doesArriveExist&&(!doesDepartExist)&&doesPlayerExist){
        cout<<"Cannot transfer player. Team "<<copyDepartTeamName<<" does not exist."<<endl;
    }
    else if((!doesArriveExist)&&doesDepartExist&&doesPlayerExist){
        cout<<"Cannot transfer player. Team "<<copyArriveTeamName<<" does not exist."<<endl;
    }
    else if ((!doesArriveExist)&&(doesDepartExist)&&(!doesPlayerExist)){
        cout<<"Cannot transfer player. Team "<<copyArriveTeamName<< " and player "<<copyPlayerName<<" does not exist."<<endl;
    }
    else if( (doesArriveExist)&&(!doesDepartExist)&&(!doesPlayerExist)){
        cout<<"Cannot transfer player. Team "<<copyDepartTeamName<<" and player "<<copyPlayerName<<" does not exist."<<endl;
    }
    else{
        cout<<"Cannot transfer player. Team " << copyArriveTeamName<<", "<<copyDepartTeamName<<" and player "<<copyPlayerName<<" does not exist."<<endl;
    }

}

void LeagueManagementSystem::showAllTeams()const{
    if(leagueSize<1){
        cout<<"Teams in the league management system:"<<endl;
        cout<<"None"<<endl;
    }
    else{
        cout<<"Teams in the league management system:"<<endl;
        for (int i= 0; i<leagueSize;i++){
            cout<<teams[i].getName()<<", "<<teams[i].getYear()<<", "<<teams[i].getTeamSize()<<" players, "<<teams[i].getTotalSalary()<<" TL total salary"<<endl;
        }
        cout<<endl;

    }

}


void LeagueManagementSystem::showTeam(const string name)const{
    bool doesExist = false;
    int index=-1;
    for (int i=0; i<leagueSize;i++){
        if (teams[i].getName()==name){
            doesExist =true;
            index = i;
        }
    }
    if (doesExist){
        cout<<"Team:"<<endl;
        cout<<teams[index].getName()<<", "<<teams[index].getYear()<<", "<<teams[index].getTeamSize()<<" players, "<<teams[index].getTotalSalary()<<" TL total salary"<<endl;
        teams[index].displayPlayers();
    }
    else{
        cout<<"Team "<<name<<" does not exist."<<endl;
    }
}
void LeagueManagementSystem::showPlayer(const string name)const{
    bool doesExist = false;
    for (int i = 0;i<leagueSize;i++){
            for (int j=0; j<teams[i].getTeamSize();j++){
                if(teams[i].getPlayers()[j].getName()==name){
                    doesExist=true;
                    cout<<"Player:"<<endl;
                    cout<<name<<", "<<"jersey "<<teams[i].getPlayers()[j].getJerseyNumber()<<", "<<teams[i].getPlayers()[j].getSalary()<<" TL salary"<<endl;
                    cout<<"Plays in team "<<teams[i].getName()<<"."<<endl;
                }

            }
        }
    if(!doesExist){
        cout<<"Player "<<name<<" does not exist."<<endl;
    }
}





