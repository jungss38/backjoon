#include <stdio.h>

#define MAX_N   10001
#define MAX(A,B)    ((A) > (B) ? (A) : (B))

int main()
{
    int value[MAX_N] = {0,};
    int dp[MAX_N] = {0,};
    int cnt, num;

    freopen("input.txt", "r", stdin);
    scanf("%d", &cnt);

    for(int i=0; i<cnt; i++)
    {
        scanf("%d", value+i+1);
    }

    dp[1] = value[1];
    dp[2] = dp[1] + value[2];
    for(int i=3; i<=cnt; i++)
    {
        // int first_case = dp[i-1];
        // int second_case = value[i] + dp[i-2];
        // int third_case = value[i] + value[i-1] + dp[i-3];
        // dp[i] = MAX(first_case, second_case);
        // dp[i] = MAX(dp[i], third_case);

        dp[i] = MAX(dp[i-1], value[i] + dp[i-2]);
        dp[i] = MAX(dp[i], value[i] + value[i-1] + dp[i-3]);
    }

    printf("%d\n", dp[cnt]);
}
