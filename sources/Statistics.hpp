#pragma once
#include "League.hpp"
#include "Schedule.hpp"

class Statistics{
    private:
        vector<Team *> teams;
    public:
        Statistics(League &l);
        ~Statistics();
        vector<Team *> points();
        vector<Team *> topTeams(int number);
        int longestWinStreak();
        int longetLoseStreak();
        int moreScoredThenRecived();
};
