#include <stdio.h>

#define MAX_N   1001
#define MIN(A,B)    ((A) < (B) ? (A) : (B))

int main()
{
    freopen("input.txt", "r", stdin);

    int cnt;
    scanf("%d", &cnt);

    int value[MAX_N][3] = {0,};
    int dp[MAX_N][3] = {0,};

    for(int i=0; i<cnt; i++)
    {
        for(int j=0; j<3; j++){
            scanf("%d", &value[i][j]);
        }
    }

    dp[0][0] = value[0][0];
    dp[0][1] = value[0][1];
    dp[0][2] = value[0][2];

    for(int i=1; i<cnt; i++)
    {
        dp[i][0] = MIN(dp[i-1][1], dp[i-1][2]) + value[i][0];
        dp[i][1] = MIN(dp[i-1][0], dp[i-1][2]) + value[i][1];
        dp[i][2] = MIN(dp[i-1][0], dp[i-1][1]) + value[i][2];

        // int a = MIN(dp[i-1][1], dp[i-1][2]);
        // int b = MIN(dp[i-1][0], dp[i-1][2]);
        // int c = MIN(dp[i-1][0], dp[i-1][1]);
        // printf("%u: %d(%d+%d)  %d(%d+%d)  %d(%d+%d) \n", i, 
        //     dp[i][0], a, value[i][0],
        //     dp[i][1], b, value[i][1],
        //     dp[i][2], c, value[i][2]);
    }

    // printf("%d %d %d", dp[cnt-1][0], dp[cnt-1][1], dp[cnt-1][2]);
    int ret = MIN(dp[cnt-1][0], dp[cnt-1][1]);
    ret = MIN(ret, dp[cnt-1][2]);

    printf("%d\n", ret);
}