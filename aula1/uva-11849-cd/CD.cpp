// Gabriel Trabasso - 298573
// CD Problem - UVA - 11849

#include <cstdio>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[])
{
    auto jack = 0u;
    auto jill = 0u;
    auto both = 0u;
    auto CD   = 0u;
    std::vector<unsigned int> CDs;

    // Read Jack and Jill total CDs
    scanf("%d %d", &jack, &jill);
    while (jack > 0 || jill > 0)
    {
        // Read Jack CDs IDs
        for (auto i = 0u; i < jack; ++i)
        {
            scanf("%d", &CD);
            CDs.push_back(CD);
        }
        // Read Jill CDs IDs and check if they both own
        for (auto i = 0u; i < jill; ++i)
        {
            scanf("%d", &CD);
            if (std::binary_search(CDs.begin(), CDs.end(), CD))
                ++both;
        }
        // Print output and clear variables for the next test case
        printf("%d\n", both);
        CDs.clear();
        both = 0;
        scanf("%d %d", &jack, &jill);
    }

    return 0;
}

