#include <iostream>
#include <string>

namespace
{
    const unsigned int MAX_LENGTH = 2000000;
}

int main()
{
    unsigned int length;

    while (std::cin >> length && length)
    {
        std::string road;
        std::cin >> road;
        if (road.find('Z') != std::string::npos)
        {
            std::cout << '0' << std::endl;
        }
        else
        {
            char currentCheckpoint, lastCheckpoint;
            auto minimumDistance = MAX_LENGTH;
            auto currentDistance = 0u;
            bool foundCheckpoint = false;
            for (auto i = 0u; i < length; ++i)
            {
                currentCheckpoint = road[i];

                // lastCheckpoint initialization
                if (currentCheckpoint != '.' && !foundCheckpoint)
                {
                    lastCheckpoint = currentCheckpoint;
                    foundCheckpoint = true;
                }

                // a nearest 'D' or 'R'
                if (currentCheckpoint == lastCheckpoint)
                {
                    lastCheckpoint = currentCheckpoint;
                    currentDistance = 0u;
                }
                // a distance between 'D' and 'R' or 'R' and 'D'
                else if (currentCheckpoint == 'D' || currentCheckpoint == 'R')
                {
                    ++currentDistance;
                    if (currentDistance < minimumDistance)
                        minimumDistance = currentDistance;                    
                    lastCheckpoint = currentCheckpoint;
                    currentDistance = 0u;
                }
                // a '.'
                else if (foundCheckpoint)
                {
                    ++currentDistance;
                }        
            }
            std::cout << minimumDistance << std::endl;
        }
    }

    return 0;
}
