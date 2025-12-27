#if 0
#include <stdio.h>

int cnt = 0;

void recursive(int target, int now)
{
    if(target <= now)
    {
        if(target == now)
            cnt++;
        return;
    }

    recursive(target, now + 1);
    recursive(target, now + 2);
    recursive(target, now + 3);
}

int main()
{
    freopen("input.txt", "r", stdin);

    // while(1){
    //     int num;
    //     if(scanf("%d", &num) == EOF)
    //         break;

    //     cnt = 0;
    //     recursive(num, 0);
    //     printf("%d\n", cnt);
    // }

    int tc, num;
    scanf("%d", &tc);
    for(int i=0;i<tc;i++)
    {
        scanf("%d", &num);
        cnt = 0;
        recursive(num, 0);
        printf("%d\n", cnt);
    }

    return 0;
}
#endif

#if 1
#include <stdio.h>

int recursive(int target, int now)
{
    if(target <= now)
    {
        if(target == now)
            return 1;
        return 0;
    }

    int sum = 0;
    sum += recursive(target, now + 1);
    sum += recursive(target, now + 2);
    sum += recursive(target, now + 3);
    return sum;
}

int main()
{
    freopen("input.txt", "r", stdin);

    int tc, num;
    scanf("%d", &tc);
    for(int i=0;i<tc;i++)
    {
        scanf("%d", &num);
        int cnt = recursive(num, 0);
        printf("%d\n", cnt);
    }

    return 0;
}
#endif