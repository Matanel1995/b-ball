#pragma once
#include"League.hpp"
#include "Game.hpp"
#include <vector>

class Schedule{
    private:
        vector<Game *> allGames;
        unsigned int gameIndex;
    public:
        Schedule(League &l);
        ~Schedule();
        int gamesLeft();
        Game * getGame();
        void nextGame();
};