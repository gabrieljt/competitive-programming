// Gabriel Trabasso - 298573
// Free Spots problem - UVa - 10703
// Solution #13383720 - 2014-03-24 21:46:22
// C++11 - compile with -std=c++11 flag

#include <cstdio>
#include <algorithm>

int main()
{
    unsigned int width, height, subBoards;
    while (scanf("%u %u %u", &width, &height, &subBoards) && (width || height || subBoards))
    {
        unsigned int freeSpots = width * height;
        unsigned int board[width][height];
        for (auto i = 0u; i < width; ++i)
            for (auto j = 0u; j < height; ++j)
                board[i][j] = 0u;

        unsigned int x1, y1, x2, y2;       
        for (auto n = 0u; n < subBoards; ++n)
        {
            scanf("%u %u %u %u", &x1, &y1, &x2, &y2);
            // Order Coordinates
            /*
                x2y2    .
                .       x1y1    
            */
            if (x1 >= x2 && y1 >= y2)
            {
                std::swap(x1, x2);
                std::swap(y1, y2);
            } 
            /*
                .       x1y1
                x2y2    .       
            */
            else if (x1 >= x2 && y1 <= y2)
            {
                auto subBoardWidth = x1 - x2;
                x1 -= subBoardWidth;
                x2 += subBoardWidth;
            }
            /*
                .       x2y2
                x1y1    .
            */
            else if (x1 <= x2 && y1 >= y2)
            {
                auto subBoardHeight = y1 - y2;
                y1 -= subBoardHeight;
                y2 += subBoardHeight;
            }

            for (auto i = x1 - 1u; i < x2; ++i)
                for (auto j = y1 - 1u; j < y2; ++j)
                {
                    if (board[i][j] == 0u)
                    {
                        board[i][j] = 1u;
                        --freeSpots;
                    }
                }
        }
        switch (freeSpots)
        {
            case 0u:
                printf("There is no empty spots.\n");
                break;
            case 1u:
                printf("There is one empty spot.\n");
                break;
            default:
                printf("There are %u empty spots.\n", freeSpots);
        }
    }

    return 0;
}

