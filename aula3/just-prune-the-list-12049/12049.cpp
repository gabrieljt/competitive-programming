// Gabriel Trabasso - 298573
// Just Prune the List problem - UVa - 12049
// Solution #13429125 - 2014-04-01 19:55:49s
// Compile with -std=c++11 flag

#include <set>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <stdint.h>

int main()
{
    unsigned int tests, list1_size, list2_size;
    std::multiset<int32_t> list1, list2;
    int32_t tmp;

    scanf("%u", &tests);
    while(tests--)
    {
        scanf("%u %u", &list1_size, &list2_size);
        std::vector<int32_t> diff(list1_size + list2_size);

        for (auto n = 0u; n < list1_size; ++n)
        {
            scanf("%d", &tmp);
            list1.insert(tmp);
        }

        for (auto m = 0u; m < list2_size; ++m)
        {
            scanf("%d", &tmp);
            list2.insert(tmp);
        }

        auto itr = std::set_symmetric_difference(list1.begin(), list1.end(), list2.begin(), list2.end(), diff.begin());
        diff.resize(itr - diff.begin());
        printf("%u\n", diff.size());
        list1.clear();
       	list2.clear();
    }

    return 0;
}
