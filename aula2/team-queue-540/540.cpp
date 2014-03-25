// Gabriel Trabasso - 298573
// Team Queue problem - UVa - 540
// Solution #13384798 - 2014-03-25 04:48:25
// C++11 - compile with -std=c++11 flag

#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <deque>

typedef std::pair<unsigned int, unsigned int> TeamMember;

int main()
{
    unsigned int numberOfTeams, numberOfMembers, memberId;
    auto scenarioNumber = 1u;
    while(scanf("%u", &numberOfTeams) && numberOfTeams)
    {
        std::map<unsigned int, unsigned int> teams;
        for (auto team = 0u; team < numberOfTeams; ++team)
        {
            scanf("%u", &numberOfMembers);
            for (auto member = 0u; member < numberOfMembers; ++member)
            {   
                scanf("%u", &memberId);
                teams[memberId] = team;
            }
        }
        
        std::string command;
        std::deque<TeamMember> teamQueue;
        printf("Scenario #%u\n", scenarioNumber);
        // Process Commands
        do 
        {
            std::cin >> command;
            if (command == "ENQUEUE")
            {
                scanf("%u", &memberId);
                auto team = teams[memberId];
                auto teamMember = std::make_pair(memberId, team);
                auto foundTeam = false;
                for (auto itr = teamQueue.begin(); itr != teamQueue.end(); ++itr)
                {
                    if (itr->second == teamMember.second)
                    {
                        foundTeam = true;
                        while (itr->second == teamMember.second && itr != teamQueue.end())
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
	        	printf("%u\n", itr->first);
                teamQueue.pop_front();
            }
        } 
        while(command != "STOP");
        ++scenarioNumber;
        std::cout << std::endl;
    }

    return 0;
}
