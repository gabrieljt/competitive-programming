// Gabriel Trabasso - 298573
// Printer Queue problem - UVa - 12100
// Solution #13385195 - 2014-03-25 06:24:58
// C++11 - compile with -std=c++11 flag

#include <cstdio>
#include <deque>

int main()
{
    unsigned int tests, jobs, myJob, job;
    std::deque<unsigned int> printerQueue;
    scanf("%u", &tests);
    for (auto i = 0u; i < tests; ++i)
    {

        scanf("%u %u", &jobs, &myJob);
        for (auto j = 0u; j < jobs; ++j)
        {
            scanf("%u", &job);
            printerQueue.push_back(job);
        }
        auto myJobPtr = &printerQueue[myJob];
        auto minutes = 0u;
        auto printed = false;
        while (!printed)
        {
            auto delayed = false;
            auto currentJob = printerQueue.front();
            for (auto jobItr = printerQueue.begin() + 1; jobItr != printerQueue.end(); ++jobItr)
            {
                if (currentJob < *jobItr)
                {
                    printerQueue.push_back(currentJob);
                    if (myJobPtr == &printerQueue.front()) 
                        myJobPtr = &printerQueue.back();
                    printerQueue.pop_front();
                    delayed = true;
                    break;
                }
            }

            if (!delayed)
            {
                ++minutes;
                if (myJobPtr == &printerQueue.front())
                    printed = true;
                printerQueue.pop_front();
            }
        }

        printf("%u\n", minutes);
        printerQueue.clear();
    }
    return 0;
}
