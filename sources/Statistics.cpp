#include"Statistics.hpp"
#include <algorithm>

Statistics::Statistics(League &l){
    this->teams = l.getTeams();
}

Statistics::~Statistics(){
    for(unsigned int i=0; i<this->teams.size();i++){
        delete this->teams.at(i);
    }
}

bool compareTeam(Team t1, Team t2){
    double t1WinLoseRation;
    double t2WinLoseRation;
    if(t1.getLoses() != 0){t1WinLoseRation = t1.getWins()/t1.getLoses();}
    else{t1WinLoseRation = t1.getWins();}
    if(t2.getLoses() != 0){t2WinLoseRation = t2.getWins()/t2.getLoses();} 
    else{t2WinLoseRation = t2.getWins();}

    // if ratio is same need to decide by hoops in total season
    if(t1WinLoseRation == t2WinLoseRation){
        return t1.getHoops() > t2.getHoops();
    }
    return t1WinLoseRation > t2WinLoseRation;
}

vector<Team *> Statistics::points(){
    //sort(begin(this->teams), end(this->teams),compareTeam);
    return this->teams; // returned sorted 
}

vector<Team *> Statistics::topTeams(int number){
    this->teams = this->points();
    vector <Team *> toReturn;
    for(unsigned int i =0 ; i < number; i++){
        toReturn.push_back(this->teams.at(i));
    }
    return toReturn;
}

int Statistics::longestWinStreak(){
    int temp = 0;
    for(unsigned int i=0; i<this->teams.size();i++){
        if(this->teams.at(i)->getWinStreak() > temp){
            temp = this->teams.at(i)->getWinStreak();
        }
    }
    return temp;
}

int Statistics::longetLoseStreak(){
    int temp = 0;
    for(unsigned int i=0; i<this->teams.size();i++){
        if(this->teams.at(i)->getLoseStreak() > temp){
            temp = this->teams.at(i)->getLoseStreak();
        }
    }
    return temp;
}

int Statistics::moreScoredThenRecived(){
    int counter = 0;
    for(unsigned int i=0; i<this->teams.size();i++){
        if(this->teams.at(i)->getHoops() > this->teams.at(i)->getRecivedHoops()){
            counter++;
        }
    }
    return counter;
}