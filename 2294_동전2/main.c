
#if 0
#include <stdio.h>

#define MAX_K   10001
#define MAX_N   101
#define INF     9999999

#define MIN(A,B)    ((A) < (B) ? (A) : (B))

int dp[MAX_K];

int main()
{
    freopen("input.txt", "r", stdin);

    int n,k;
    int v[MAX_N];

    scanf("%d %d", &n, &k);
    for(int i=0; i<n;i++){
        scanf("%d", v+i);
    }

    register int i=0;
    for(i=0; i<=MAX_K; i++)    dp[i] = INF;
    dp[0] = 0;

    for(i=0;i<n;i++)
    {
        for (int j = v[i]; j <= k; j++) {
			dp[j] = MIN(dp[j], dp[j - v[i]] + 1);
		}
    }

    printf("%d\n", dp[k] == INF ? -1 : dp[k]);
}
#endif


// 시간초과
#if 0

#include <stdio.h>
#include <memory.h>

#define MAX_N       101
#define MAX_K       10001

#define INF         999999
#define MIN(A,B)    ((A) < (B) ? (A) : (B))

int n, k;
int coins[MAX_N];
int cache[MAX_K][MAX_N];


int minimize(int capacity, int item)
{
    if(item==n)
    {
        if(capacity==0)
            return 0;
        else
            return INF;
    }
    
    if(cache[capacity][item]!=-1) return cache[capacity][item];
    
    int result=INF;
    
    for(int i=0; i<=capacity/coins[item]; i++)
    {
        result = MIN(result, i + minimize(capacity-coins[item]*i,item+1));
    }
    
    return cache[capacity][item]=result;
}

int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++){
        scanf("%d", coins+i);
    }

    memset(cache, -1, sizeof(int) * MAX_K * MAX_N);

    int result=minimize(k,0);
    printf("%d\n", result > INF ? -1 : result);
}
#endif

#if 1
#include <stdio.h>
int n,coin[105],cache[10005];
int coin1(int sum){
        int i;
        if(sum==0) return 0;
        if(cache[sum]!=-1) return cache[sum];
        cache[sum]=987654321;
        for(i=0;i<n;++i) {
                if(sum>=coin[i] && cache[sum]>(coin1(sum-coin[i])+1)){
                        cache[sum]=(coin1(sum-coin[i])+1);
                }
        }
        return cache[sum];
}
int main () {
        int i,k;
        scanf("%d %d",&n,&k);
        for(i=0;i<n;++i) scanf("%d",&coin[i]);
        for(i=0;i<10005;++i) cache[i]=-1;
        coin1(k)!=987654321?printf("%d",coin1(k)):printf("%d",-1);
        return 0;
}
#endif
