#if 1

#include <stdio.h>

#define MAX_N   101
#define MOD     1000000000

int dp[MAX_N][MAX_N] = {0,};
// 자릿수, 끝나는 숫자

int main()
{
    freopen("input.txt", "r", stdin);

    int n;
    scanf("%d", &n);

    // intialize
    dp[1][1]=dp[1][2]=dp[1][3]=dp[1][4]=dp[1][5]=dp[1][6]=dp[1][7]=dp[1][8]=dp[1][9]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i][0] = dp[i-1][1];
        dp[i][9] = dp[i-1][8];
        for(int j=1;j<=8;j++)
        {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
        }
    }

    int ret = 0;
    for(int i=0;i<=9;i++){
        ret = (ret+dp[n][i]) % MOD;
    }

    printf("%d\n", ret);
}

#endif