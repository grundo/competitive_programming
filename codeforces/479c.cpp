#include <bits/stdc++.h>
using namespace std;

#define A first
#define B second
#define fo(x,y,z) for(int x=y;x<z;x++)

int n;
pair<int, int> a[5005];

int main(){
	scanf("%d", &n);
	fo(i,0,n) scanf("%d %d", &a[i].A, &a[i].B);
	sort(a, a+n);
	int ans = -1;
	fo(i,0,n) ans = (a[i].B >= ans)?a[i].B:a[i].A;
	printf("%d\n", ans);
}

