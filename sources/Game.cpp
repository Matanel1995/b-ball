#include <iostream>
#include <iomanip>
#include <string>
#include <random>
#include <cmath>
#include "Game.hpp"

const double standard_dev = 10;
const double home_standart = 75;
const double away_standart = 70;


Game::Game(const Team &home, const Team &away){
    this->home_Team = new Team();
    this->away_Team = new Team();
    this->scores[0] = 0;
    this->scores[1] = 0;
}

Team Game::getHome(){
    return this->home_Team;
}

Team Game::getAway(){
    return this->away_Team;
}

std::ostream &operator<<(std::ostream &out, const Game &game){
    out << "Home: " << game.home_Team.getName() << "    VS    " << game.away_Team.getName() << endl
    << "    " << game.scores[0] << "            " << game.scores[1] << endl;
    return out;
}

// Function to run the game and return the winning team
void Game::playGame(){
    // Using random disterbution (link was provided in the asssignmant)
    random_device rd{};
    mt19937 gen{rd()};
    normal_distribution<> homeDis{home_standart,standard_dev}; // creating normal_distribution for home with avg: 75 dev: 10
    normal_distribution<> awayDis{away_standart,standard_dev}; // creating normal_distribution for home with avg: 70 dev: 10

    //Generatre scores and make sure they dont get over 100
    int homePoints = 100;
    int awayPoints = 100;
    while (homePoints > 99 || awayPoints >99){
        homePoints = homeDis(gen);
        awayPoints = awayDis(gen);
    }

    // Add up to 10 points based on skill
    homePoints += (home_Team.getSkill() * 10) / 1;
    home_Team.hoopsInc(homePoints);
    this->scores[0] = homePoints;
    awayPoints += (away_Team.getSkill() * 10) / 1;
    away_Team.hoopsInc(awayPoints);
    this->scores[1] = awayPoints;



    if(homePoints > awayPoints){
        home_Team.winInc();
        away_Team.loseInc();
    }
    else{
        away_Team.winInc();
        home_Team.loseInc();
    }
}