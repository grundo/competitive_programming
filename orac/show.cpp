#include <bits/stdc++.h>
using namespace std;

#define fo(x,y,z) for(int x=y;x<z;x++)
#define N 500002
typedef long long ll;

ll t[1000005], ans, temp;
int n;

void build(){
	for(int i = N-1; i > 0; i--) t[i] = max(t[i<<1],t[i<<1|1]);
}

void up(int p, ll v){
	for(t[p += N] = v; p > 1; p >>= 1) t[p>>1] = max(t[p],t[p^1]);
}

ll qu(int l, int r){
	ll ret = 0;
	for(l += N, r += N; l < r; l >>= 1, r >>= 1){
		if(l&1) ret = max(ret,t[l++]);
		if(r&1) ret = max(ret,t[--r]);
	}
	return ret;
}	

int main(){
	freopen("show.in", "r", stdin);
	freopen("show.out", "w", stdout);
	scanf("%d", &n);
	fo(i,0,n){
		int x, a, b, phi;
		scanf("%d %d %d %d", &x, &a, &b, &phi);
		temp = qu(a,b+1) + (ll)phi;
		ans = max(temp,ans);
		up(x,temp);
	}
	printf("%lld\n", ans);
	return 0;
}

