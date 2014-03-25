#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

struct TeamMember
{
    TeamMember(unsigned int id)
    : team()
    , id(id)
    {
    }

    TeamMember(unsigned int team, unsigned int id)
    : team(team)
    , id(id)
    {
    }

    bool operator()(const TeamMember& tm) const
    {
        return tm.id == id;
    }

    unsigned int team;
    unsigned int id;
};

int main()
{
    unsigned int numberOfTeams, numberOfMembers, memberId;
    auto scenarioNumber = 1u;
    while(scanf("%u", &numberOfTeams) && numberOfTeams)
    {
        std::vector<TeamMember> teams;
        for (auto team = 0u; team < numberOfTeams; ++team)
        {
            scanf("%u", &numberOfMembers);
            for (auto member = 0u; member < numberOfMembers; ++member)
            {   
                scanf("%u", &memberId);

                TeamMember teamMember(team, memberId);
                teams.push_back(teamMember);
            }
        }
        std::string command;
        std::list<TeamMember> teamQueue;
        printf("Scenario #%u\n", scenarioNumber);
        // Process Commands
        do 
        {
            std::cin >> command;
            if (command == "ENQUEUE")
            {
                std::cin >> memberId;
                auto memberItr = std::find_if(teams.begin(), teams.end(), TeamMember(memberId));               
                TeamMember teamMember(memberItr->team, memberItr->id);
                bool foundTeam = false;
                for (auto itr = teamQueue.begin(); itr != teamQueue.end(); ++itr)
                {
                    if (itr->team == teamMember.team)
                    {
                        foundTeam = true;
                        while (itr->team == teamMember.team)
                            ++itr;
                        teamQueue.insert(itr, teamMember);
                        break;
                    }
                }
                if (!foundTeam)
                    teamQueue.push_back(teamMember);
            }
            else if (command == "DEQUEUE")
            {                
                auto itr = teamQueue.begin();
                TeamMember teamMember(itr->team, itr->id);
                std::cout << teamMember.id << std::endl;
                teamQueue.pop_front();
            }
        } 
        while(command != "STOP");
        ++scenarioNumber;
        std::cout << std::endl;
    }

    return 0;
}
