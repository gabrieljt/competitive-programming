// Gabriel Trabasso - 298573
// Hartals problem - UVa - 10050
// Solution #13424219 - 2014-03-31 23:21:56
// C++11 - compile with -std=c++11 flag

#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>

int main()
{
    unsigned int tests, days, parties;

    scanf("%u", &tests);
    for (auto i = 0u; i < tests; ++i)
    {
        scanf("%u %u", &days, &parties);

        // Get hartal schedule for each party
        unsigned int hartalFrequency;
        std::vector<std::vector<unsigned int>> hartals(parties);
        for (auto j = 0u; j < parties; ++j)
        {
            std::vector<unsigned int> hartalDays;
            scanf("%u", &hartalFrequency);
            auto currentDay = hartalFrequency;
            while (currentDay <= days)
            {
                hartalDays.push_back(currentDay);
                currentDay += hartalFrequency;
            }
            hartals[j] = hartalDays;
        }

        // 1..days vector
        std::vector<unsigned int> hartalsPeriod(days);
        for (auto j = 0u; j < days; ++j)
            hartalsPeriod[j] = j + 1u;

        // Build set with all hartal days from all parties
        std::set<unsigned int> result;
        for (auto hartal : hartals)
        {
            std::vector<unsigned int> intersection(days);
            auto itr = std::set_intersection(hartalsPeriod.begin(), hartalsPeriod.end(), hartal.begin(), hartal.end(), intersection.begin());
            intersection.resize(itr - intersection.begin());
            for (auto j = 0u; j < intersection.size(); ++j)
                result.insert(intersection[j]);
        }

        // Calculate the answer
        auto lostWorkingDays = 0u;
        for (auto itr = result.begin(); itr != result.end(); ++itr)
        {
            if (!((*itr + 1u) % 7u == 0u || *itr % 7u == 0u))
                ++lostWorkingDays;
        }
        printf("%u\n", lostWorkingDays);
    }

    return 0;
}

