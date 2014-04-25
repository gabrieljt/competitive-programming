// Gabriel Trabasso - 298573
// Bus Driver - UVa - 11389
// #13547527 - 2014-04-25 13:38:38

#include <cstdio>
#include <array>
#include <functional>
#include <algorithm>

int main()
{
    int n, d, r, driverHours, extraPayment;
    std::array<int, 100> morning, afternoon;

    while (scanf("%d %d %d", &n, &d, &r) && n && d && r)
    {
        driverHours = 0;
        extraPayment = 0;

        for (int i = 0; i < n; ++i)
            scanf("%d", &morning[i]);
        std::sort(morning.begin(), morning.begin() + n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &afternoon[i]);
        std::sort(afternoon.begin(), afternoon.begin() + n, std::greater<int>());

        // for each driver, morning hours ascending + afternoon hours descending
        for (int i = 0; i < n; ++i)
        {
            driverHours = morning[i] + afternoon[i];
            if (driverHours > d)
                extraPayment += (driverHours - d) * r;
        }

        printf("%d\n", extraPayment);
    }

    return 0;
}
