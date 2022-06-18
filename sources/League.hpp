#pragma once
#include <vector>
#include "Team.hpp"

class League{
    private:
        vector<Team *> allTeams;
    public:
        League();
        ~League();
        vector<Team *> getTeams();
};
