// Gabriel Trabasso - 298573
// 3n + 1 problem - UVa - 100 
// Solution #13337114 - 2014-03-17 02:20:30
// C++11 - compile with -std=c++11 flag

#include <cstdio>
#include <vector>
#include <algorithm>

int main()
{
    auto i = 0u;
    auto j = 0u;
    std::vector<unsigned int> cycles;

    while (scanf("%u %u", &i, &j) > 0)
    {
        // Keeps i smaller than j (for loop)
        auto swapped = false;
        if (i > j)
        {
            auto tmp = i;
            i = j;
            j = tmp;
            swapped = true;
        }

        for (auto n = i; n <= j; ++n)
        {
            auto m = n;
            auto cycle = 1u; // The number itself
            while (m != 1u)
            {
                if (m % 2u == 0u)
                    m /= 2u;
                else
                    m = 3u*m + 1u;
                ++cycle;
            }
            cycles.push_back(cycle);
        }       
        auto maxCycle = std::max_element(cycles.begin(), cycles.end()); // Returns Iterator
        // Must print the output in the original order
        swapped ? printf("%u %u %u\n", j, i, *maxCycle) : printf("%u %u %u\n", i, j, *maxCycle);
        cycles.clear();
    }

    return 0;
}

