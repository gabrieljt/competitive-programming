// Gabriel Trabasso - 298573
// Coin Collector - UVa - 11264
// #13546020 - 2014-04-25 06:55:20

#include <cstdio>
#include <array>

int n, count;
std::array<int, 1000> coins;

void withdraw(int amount, int index)
{
    if (index == n - 1)
        return;
    
    if (amount + coins[index] < coins[index + 1])
    {
        ++count;
        withdraw(amount + coins[index], index + 1);
    }
    else
        withdraw(amount, index + 1);
}

int main()
{
    int tests, amount;

    scanf("%d", &tests);
    while (tests--)
    {
        amount = 0;
        count = 1;
        scanf("%d", &n);        
        for (int i = 0; i < n; ++i)
            scanf("%d", &coins[i]);
        withdraw(amount, 0);
        printf("%d\n", count);
    }

    return 0;
}
