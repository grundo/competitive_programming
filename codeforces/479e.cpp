#include <bits/stdc++.h>
using namespace std;

#define Int long long
#define MOD 1000000007
#define f(x) if(x < 0) x += MOD
#define fo(x,y,z) for(Int x=y;x<z;x++)

Int n, a, b, k, pa[5005], ca[5005];

int main(){
	scanf("%I64d %I64d %I64d %I64d", &n, &a, &b, &k);
	fo(i,0,n+1) ca[i] = 1;
	fo(i,0,k){
		fo(i,1,n+1)	pa[i] = (ca[i] + pa[i-1])%MOD;
		fo(i,1,n+1) ca[i] = 0;
		fo(j,1,n+1){
			int d = abs(b-j)-1, v = pa[j]-pa[j-1];
			f(v);			
			if(a < b && j < b){
				ca[j] = pa[j+d] - pa[max(j-d-1,0LL)];
				f(ca[j]); ca[j] -= v; f(ca[j]);
			}
			else if(a > b && j > b){
				ca[j] = pa[min(n,j+d)]-pa[b];
				f(ca[j]); ca[j] -= v; f(ca[j]);
			}
		}
	}
	printf("%I64d\n", ca[a]);
	return 0;
}

