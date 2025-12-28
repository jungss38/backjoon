#include <stdio.h>
#define MAX_N   101

int dp[10001];

int main()
{
    freopen("input.txt", "r", stdin);

    int n, k;
    int v[MAX_N] = {0,};

    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", v+i);
    }

    dp[0] = 1; 

	// 동전의 종류마다 최대 k번까지 경우의 수가 갱신된다.
	for(int i = 1; i <= n; i++){
		// 동전의 크기를 첫번째 동전 크기부터 k원까지 1씩 늘리면서 
		for(int j = v[i]; j <= k; j++){
			// 점화식에 따라 테이블 갱신 
			dp[j] += dp[j - v[i]]; 
		}
	}

    printf("%d\n", dp[k]);
}