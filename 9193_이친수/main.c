
#include <stdio.h>
#include <stdlib.h> 

#define MAX_N 90

int main()
{
    long long int dp[MAX_N][2];

    dp[0][0] = 0;
    dp[0][1] = 1;

    for(int i=1; i<MAX_N; i++){
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }

    int N;

#if 0
    freopen("input.txt", "r", stdin);
    scanf("%d", &N);

    printf("%d,%lld\n", N, dp[N-1][0] + dp[N-1][1]);
#else
// debugging
#if 0
    // print all results
    for(N=1; N<=90; N++)
    {
        printf("%lld\n", dp[N-1][0] + dp[N-1][1]);
    }
#else

    freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    long long int expectValue = dp[N-1][0] + dp[N-1][1];

    FILE *resultFile = fopen("result.txt", "r");
    if (resultFile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    char line[100];
    int line_no = 1;
    while(fgets(line, sizeof(line), resultFile) != NULL)
    {
        if(line_no == N)
            break;
        line_no++;
    }

    int resultValue = atoi(line);
    printf("expect = %lld, real = %lld ==> %s", expectValue, resultValue, 
        (expectValue == resultValue) ? "true" : "false");
#endif
#endif
}