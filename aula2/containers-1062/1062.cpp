// Gabriel Trabasso - 298573
// Containers Problem - UVa - 1062
// Solution #13383995
// C++ - compile with -std=c++11 flag

#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string containers;
    auto caseNumber = 1u;
    while (std::cin >> containers && containers != "end")
    {
        std::string stacks;
        stacks += containers[0];
        for (auto i = 1u; i < containers.size(); ++i)
        {
            std::sort(stacks.begin(), stacks.end());
            auto container = containers[i];
            auto stacked = false;
            for (auto j = 0u; j < stacks.size(); ++j)
            {
                auto stackTop = stacks[j];
                if (container <= stackTop)
                {
                    stacks[j] = container;
                    stacked = true;                    
                    break;
                }
            }
            if (!stacked)
                stacks += container;
        }
        printf("Case %u: %u\n", caseNumber, stacks.size());
        ++caseNumber;
    }

    return 0;
}

