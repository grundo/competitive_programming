#include <bits/stdc++.h>
using namespace std;

#define fo(x,y,z) for(int x=y;x<z;x++)

int r, c, w;

int main(){
	int tc;
	scanf(" %d ", &tc);
	fo(z,1,tc+1){
		printf("Case #%d: ", z);
		scanf("%d %d %d", &r, &c, &w);
		int ans = 0;
		ans += (r-1)*(c/w);
		ans += (c/w) + w - 1;
		if(c%w) ans++;
		printf("%d\n", ans);
	}
	return 0;
}
