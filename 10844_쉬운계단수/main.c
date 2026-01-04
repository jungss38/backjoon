#if 1

#include <stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);

    int n;
    scanf("%d", &n);

    int v = 100;
    while(n > 0)
    {
        int a = n / v;
        n %= v;
        v /= 10;

        printf("%d %d\n", n, v);
        if(!a)
            continue;

    }
}

#endif