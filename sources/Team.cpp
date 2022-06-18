#include <iostream>
#include "Team.hpp"

using namespace std;

Team::Team(const string &name, const double skill){
    this->t_name = name;
    this->t_skill = skill;
    this->total_hoops = 0;
    this->total_lose = 0;
    this->total_win = 0;
    this->winStreak = 0;
    this->loseStreak = 0;
    this->hoops_recived =0;
}

string Team::getName()const{
    return this->t_name;
}

double Team::getSkill(){
    return this->t_skill;
}

int Team::getWins(){
    return this->total_win;
}

int Team::getLoses(){
    return this->total_lose;
}

int Team::getHoops(){
    return this->total_hoops;
}
void Team::winInc(){
    this->total_win++;
    this->winStreak++;
    this->loseStreak = 0;
}

void Team::loseInc(){
    this->total_lose++;
    this->loseStreak++;
    this->winStreak =0;
}

int Team::getLoseStreak(){
    return this->loseStreak;
}

int Team::getWinStreak(){
    return this->winStreak;
}

int Team::getRecivedHoops(){
    return this->hoops_recived;
}

void Team::hoopsInc(int score){
    this->total_hoops += score; 
}

void Team::hoopsRecivedInc(int scoreRecived){
    this->hoops_recived += scoreRecived;
}

std::ostream &operator<<(std::ostream &out, const Team &team){
    out << "Team information:" << endl << " Name: " << team.t_name << endl << " Skills: " << team.t_skill
     << endl << "  Wins: " << team.total_win << endl << "   Lose: " << team.total_lose << endl << " Hoops: " << team.total_hoops << endl;
    return out;
}