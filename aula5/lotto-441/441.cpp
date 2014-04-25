// Gabriel Trabasso - 298573
// Lotto Problem - UVa - 441
// Solution #13545548 - 2014-04-25 04:20:32
// Compile with -std=c++11 (#include <array>)

#include <cstdio>
#include <array>

int k;
std::array<int, 12> numbers;
std::array<int, 12> game;
std::array<int, 12> used;

void backtrack(int current, int index)
{
    if (current == 6)
    {
        printf("%u %u %u %u %u %u\n"
            , game[0], game[1], game[2]
            , game[3], game[4], game[5]);
        return;
    }
    
    for (int i = index; i < k; ++i)
    {
        if (used[i] == 0)
        {
            used[i] = 1;
            game[current] = numbers[i];
            backtrack(current + 1, i);
            used[i] = 0;
        }
    }    
}

int main()
{
    int count = 0;
    while (scanf("%u", &k) && k)
    {
        if (count > 0)
            printf("\n");
        numbers.fill(0);
        game.fill(0);
        used.fill(0);
        for (int i = 0; i < k; ++i)
            scanf("%u", &numbers[i]);
        backtrack(0, 0);
        ++count;
    }

    return 0;
}

