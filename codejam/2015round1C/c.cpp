#include <bits/stdc++.h>
using namespace std;

#define fo(x,y,z) for(int x=y;x<z;x++)
int c, d, v, dp[20005], a[105];

int main(){
	int tc;
	scanf(" %d ", &tc);
	fo(z,1,tc+1){
		printf("Case #%d: ", z);
		scanf("%d %d %d", &c, &d, &v);
		if(z == 18) fprintf(stderr, "HERE %d %d %d\n", c, d, v);
		fo(i,0,20005) dp[i] = 0;
		int big = -1;
		fo(i,0,d){
			scanf("%d", &a[i]);
			big = max(big, a[i]);
		}
		dp[0] = 1;
		fo(i,0,d) for(int j = 10000; j >= 0; j--) fo(k,1,c+1) if(dp[j] && j+k*a[i] <= 10000) dp[j+k*a[i]] = 1;
		int ans = 0;
		fo(i,0,big){
			if(!dp[i]){
				ans++;
				for(int j = 10000; j >= 0; j--) fo(k,1,c+1) if(dp[j] && j+k*i <= 10000) dp[j+k*i] = 1;
			}
		}
		long long cm;
		fo(i,0,10000){
			if(!dp[i]){
				cm = i-1; break;
			}
		}
		while(cm < v){
			cm = (cm+1)*(c+1)-1;
			ans++;
		}
				
		printf("%d\n", ans);
	}
	return 0;
}
