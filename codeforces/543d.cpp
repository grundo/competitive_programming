#include <bits/stdc++.h>
using namespace std;

#define fo(x,y,z) for(int x=y;x<z;x++)
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> pp;

unordered_map<ll,ll> dp;
int n, a, par[200005];
vector<int> e[200005];

ll solve(int at, int par){
	ll val = (ll)at<<32 + (ll)par;
	if(dp.find(val) != dp.end()) return dp[val];
	ll ret = 1;
	fo(i,0,e[at].size()) if(e[at][i] != par){ 
		ret = (ret*solve(e[at][i],at)) % MOD;
	}
	if(at != par) ret = (ret+1)%MOD;
	return dp[val] = ret;
}

int main(){
	scanf("%d", &n);
	fo(i,2,n+1){
		scanf("%d", &a);
		e[a].push_back(i);
		e[i].push_back(a);
	}
	
	fo(i,1,n+1) printf("%lld ", solve(i, i));
	printf("\n");
	return 0;
}
	
