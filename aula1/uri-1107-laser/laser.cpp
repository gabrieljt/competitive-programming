#include <cstdio>

int main()
{
    int alt, comp, vezes, inicial, anterior, atual;
    while (scanf("%d %d", &alt, &comp) && (alt || comp))
    {
        vezes = 0;
        inicial = anterior = alt;
        bool subindo = false;
        for (int i = 0; i < comp; i++)
        {
            scanf("%d", &atual);
            if (atual < anterior)
            {
                subindo = false;
            }
            else if (atual > anterior)
            {
                if (!subindo)
                    vezes += inicial - anterior;
                inicial = atual;
                subindo = true;
            }
            anterior = atual;
        }
        if (!subindo)
            vezes += inicial - anterior;
        printf("%d\n", vezes);
    }
    return 0;
}
