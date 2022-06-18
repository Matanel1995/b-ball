#pragma once
#include <string>

using namespace std;

class Team{
    private:
        string t_name;   // Team name
        double t_skill;  // Team skills between 0 and 1
        int total_win;   // Total team wins
        int total_lose;  // Total team loses
        int total_hoops; // Total team hoops
        int hoops_recived;
        int winStreak;
        int loseStreak;
    public:
        Team(const string &name, const double skill);
        Team();
        Team(const Team &otherTeam);
        ~Team() = default;
        string getName()const;
        double getSkill();
        int getWins();
        int getLoses();
        int getHoops();
        int getRecivedHoops();
        void winInc();
        void loseInc();
        int getWinStreak();
        int getLoseStreak();
        void hoopsInc(int score);
        void hoopsRecivedInc(int scoreRecived);

        //Overload for << operator to print all the Team data
        friend std::ostream &operator<<(std::ostream &out, const Team &team);

    };
