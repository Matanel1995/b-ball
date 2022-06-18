#include "Schedule.hpp"
#include <iterator>
#include <algorithm>
#include <random>

Schedule::Schedule(League &l){
    this->gameIndex = 0;
    vector<Team *> tempTeams= l.getTeams();
    // Double looping so i cover all teams one against the other
    for(unsigned int i=0; i<tempTeams.size();i++){
        for(unsigned int j=0; j<tempTeams.size();j++){
            if(i != j){
                Game *tempGame = new Game(*(tempTeams.at(i)), *(tempTeams.at(j)));
                this->allGames.push_back(tempGame);
            }
        }
    }
    // using vector permutation i will shuffle the games
    shuffle(begin(tempTeams), end(tempTeams),default_random_engine{1});
}

Schedule::~Schedule(){
    for(unsigned int i=0; i< this->allGames.size();i++){
        delete this->allGames.at(i);
    }
}

int Schedule::gamesLeft(){
    return this->allGames.size() - this->gameIndex;
}

void Schedule::nextGame(){
    if(gameIndex < this->allGames.size()){
        this->gameIndex++;
    }
}

Game * Schedule::getGame(){
    return this->allGames.at(this->gameIndex);
}