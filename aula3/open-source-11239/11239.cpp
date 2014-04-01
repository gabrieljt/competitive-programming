// Gabriel Trabasso - 298573
// Open Source problem - UVa - 11239
// Solution #
// Compile with -std=c++11 flag

#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <ctype.h>

typedef std::pair<std::string, std::string> UserProject;
typedef std::pair<std::string, unsigned int> ProjectSignUps;

bool resultSort(ProjectSignUps l, ProjectSignUps r)
{
	bool result;
	l.second == r.second ? result = l.first < r.first : result = l.second > r.second;
	return result;
}

int main()
{
    std::string input, project, user;
    std::map<std::string, std::string> signUps;
    std::map<std::string, unsigned int> projects;
    std::vector<std::string> banList;

    std::getline(std::cin, input);
    while (input != "0")
    {
        project = "";
        user = "";
       	
        // It's a project name
        if (isupper(input[0]))
        {
            project = input;
            projects[project] = 0u;
        }
        std::getline(std::cin, input);

        // It's an user id
        while (islower(input[0]))
        {
            user = input;
            auto banned = std::find(banList.begin(), banList.end(), user);
            if (banned == banList.end()) 
            {
	            auto inserted = signUps.insert(UserProject(user, project));
	            if (!inserted.second && signUps[user] != project)
	            {
	                signUps.erase(user);
	                banList.push_back(user);
	            }
        	}                       
            std::getline(std::cin, input);
        }
        
        // Print test case result
        if (input == "1")
        {
            while (!signUps.empty())
            {
                auto itr = signUps.begin();
                ProjectSignUps projectSignUps(itr->second, 0u);

                for (auto& currentSignUp : signUps)
                {
                    if (currentSignUp.second == projectSignUps.first)
                    {
                        projectSignUps.second++;
                        signUps.erase(currentSignUp.first);
                    }
                }
                projects[projectSignUps.first] += projectSignUps.second;
            }
            std::vector<ProjectSignUps> results;
            for (auto& signUp : projects)
                results.push_back(signUp);
            std::sort(results.begin(), results.end(), resultSort);
            for (auto i = 0u; i < results.size(); ++i)
                printf("%s %u\n", results[i].first.c_str(), results[i].second);

            signUps.clear();
            projects.clear();
            std::getline(std::cin, input);
        }
    }

    return 0;
}
