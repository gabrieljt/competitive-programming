// Gabriel Trabasso - 298573
// Jollo problem - UVa - 12247
// Solution #13354138 - 2014-03-19 21:13:01
// C++11 - compile with -std=c++11 flag

#include <cstdio>
#include <vector>
#include <array>
#include <algorithm>

namespace
{
    const int MAX_CARD = 52;
    const int NO_CARD = -1;
}

int main()
{
    int herCards[3], hisCards[2];

    while
    (
        scanf("%d %d %d %d %d", &herCards[0], &herCards[1], &herCards[2], &hisCards[0], &hisCards[1]) 
        &&
        (herCards[0] || herCards[1] || herCards[2] || hisCards[0] || hisCards[1])          
    )
    {
        std::sort(herCards, herCards + 3);
        std::sort(hisCards, hisCards + 2);

        // Prince already won all the possible games no matter what, deal the lowest possible card
        if (hisCards[0] > herCards[2])
        {
            int winningCard = 1;
            while (winningCard == herCards[0] || winningCard == herCards[1] || winningCard == herCards[2]
                    || winningCard == hisCards[0] || winningCard == hisCards[1])
                ++winningCard;
            printf("%d\n", winningCard);
        }
        else 
        {
            std::vector<std::array<int, 5>> games;
            std::vector<int> winningCards;
            // Generate her 3! games
            do
            {
                // Generate his 2! games
                do
                {
                    // Generate 3! * 2! games
                    std::array<int, 5> game {herCards[0], hisCards[0], herCards[1], hisCards[1], herCards[2]};
                    games.push_back(game);
                    // Crybaby Prince cannot depend on his own...
                    if (herCards[0] > hisCards[0] && herCards[1] > hisCards[1])
                    {
                        winningCards.push_back(NO_CARD);
                    }
                    // Prince already won this round, deal the lowest possible card
                    else if (hisCards[0] > herCards[0] && hisCards[1] > herCards[1])
                    {
                        int winningCard = 1;
                        while (winningCard == herCards[0] || winningCard == herCards[1] || winningCard == herCards[2] || winningCard == hisCards[0] || winningCard == hisCards[1])
                            ++winningCard;
                        winningCards.push_back(winningCard);
                    }
                    // Prince can cheat, find possible winning card
                    else
                    {
                        int winningCard = herCards[2] + 1;
                        while (winningCard == herCards[0] || winningCard == herCards[1] || winningCard == herCards[2] || winningCard == hisCards[0] || winningCard == hisCards[1])
                            ++winningCard;
                        if (winningCard <= MAX_CARD)
                            winningCards.push_back(winningCard);                   
                        // She has the highest possible card! This round is lost... and there is no definitive winning card
                        else
                            winningCards.push_back(NO_CARD);
                    }
                }
                while (std::next_permutation(hisCards, hisCards + 2));
            }
            while (std::next_permutation(herCards, herCards + 3));

            std::sort(winningCards.begin(), winningCards.end());
            if (winningCards[0] == NO_CARD)
            {
                printf("%d\n", NO_CARD);
            }
            else 
            {
                // Find lowest winning card that wins ALL games
                for (auto winningCard : winningCards)
                {
                    bool winAllGames = true;
                    for (auto game : games)
                    {
                        // Prince still needs to show the last card
                        if (game[0] > game[1] || game[2] > game[3])
                        {
                            if (winningCard < game[4])
                                winAllGames = false;
                        }
                    }
                    if (winAllGames)
                    {
                        printf("%d\n", winningCard);
                        break;
                    }
                }
            }
        }
    }

    return 0;
}

