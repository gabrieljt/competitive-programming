#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[])
{
    auto jack = 0u;
    auto jill = 0u;
    auto both = 0u;
    std::vector<int> CDs;

    scanf("%d %d", &jack, &jill);

    int m, n;
    scanf("%d %d", &m, &n);
    while (m > 0 || n > 0)
    {
        CDs.push_back(m);
        CDs.push_back(n);
        scanf("%d %d", &m, &n);
    }
    
    int count = 0;
    for (auto i = 0u; i < jack; ++i)
    {
        count = std::count(CDs.begin(), CDs.end(), CDs[i]);
        if (count > 1)
            ++both;
    }

    std::cout << both;
        
    return 0;
}

