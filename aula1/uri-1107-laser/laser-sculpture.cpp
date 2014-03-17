// Gabriel Trabasso - 298573
// Laser Sculpture problem - URI - 1107

#include <cstdio>

int main()
{
    auto height = 0u;
    auto length = 0u;
    unsigned int currentH, previousH;

    while (scanf("%u %u", &height, &length) > 0 && (height || length))
    {
        auto times = 0u;
        bool up = false;
        previousH = height;
        for (auto i = 0u; i < length; ++i)
        {
            scanf("%u", &currentH);

            if (currentH <= previousH)
            {
                up = false;
            }
            else
            {
                if (!up)
                    times += height - previousH;
                height = currentH;
                up = true;
            }
            previousH = currentH;
        }
        if (!up)
            times += height - previousH;
        printf("%u\n", times);
    }

    return 0;
}
