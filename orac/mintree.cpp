#include <bits/stdc++.h>
#include "family.h"
using namespace std;

#define fo(x,y,z) for(int x=y;x<z;x++)
#define INF 1 << 30

int n, *ar, t[10000], a, b;

void build(){
	for(int i = n-1; i > 0; i--) t[i] = min(t[i<<1],t[i<<1|1]);
}

void add(int p, int val){
	for(t[p += n] = val; p > 1; p >>= 1) t[p>>1] = min(t[p],t[p^1]);
}

int query(int l, int r){
	int ret = INF;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1){
		if(l&1) ret = min(ret,t[l++]);
		if(r&1) ret = min(ret,t[--r]);
	}
	return ret;
}

int main(){
	n = getNumElements(); ar = getElementArray();
	for(int i = 0; i < n; i++) t[i+n] = ar[i];
	build();
	while(getNextQuery(&a, &b)){
		int m = query(a, b+1);
		haveSolution(m);
	}
	return 0;
}
