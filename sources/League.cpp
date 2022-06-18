#include "League.hpp"

League::League(){
    //Loop for 20 iterations and create 20 teams
    for(int i=1; i< 21; i++){
        string tempTeamName = "Team" + to_string(i);
        double tempSkillLevel = ((double) rand() / (RAND_MAX)) + 1;
        Team *tempTeam = new Team(tempTeamName,tempSkillLevel);
        this->allTeams.push_back(tempTeam);
    }
}

League::~League(){
    for(unsigned int i=0;i<this->allTeams.size();i++){
        delete this->allTeams.at(i);
    }
}

vector<Team *> League::getTeams(){
    return this->allTeams;
}