#pragma once
#include <iostream>
#include <vector>
#include "Team.hpp"

using namespace std;

class Game{
    private:
        Team home_Team;
        Team away_Team;
        int scores[2];
    public:
        Game(const Team &home, const Team &away);
        ~Game(){free(scores);}
        Team getHome();
        Team getAway();
        void playGame();
        friend ostream &operator<<(ostream &out, const Game &game);
    };
