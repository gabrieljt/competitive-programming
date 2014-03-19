// Gabriel Trabasso - 298573
// Laser Sculpture problem - URI - 1107
// Solution #558712 - 2014-03-17 14:20:26 
// Laser Sculpture problem - UVa - 12247
// Solution #13354351 - 2014-03-19 21:41:15

#include <cstdio>

int main()
{
    unsigned int height, length, times, newH, currentH, previousH;

    while (scanf("%u %u", &height, &length) > 0 && (height || length))
    {
        times = 0;
        bool rising = false;
        previousH = newH = height;
        for (unsigned int i = 0; i < length; ++i)
        {
            scanf("%u", &currentH);
            if (currentH <= previousH)
            {
                rising = false;
            }
            else
            {
                // When rising, count times for the previous height
                if (!rising) 
                    times += newH - previousH;
                // Updates the problem height
                newH = currentH;
                rising = true;
            }
            previousH = currentH;
        }
        if (!rising)
        {
            times += newH - previousH;
        }
        printf("%u\n", times);
    }

    return 0;
}
