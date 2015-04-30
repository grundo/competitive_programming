#include <bits/stdc++.h>
using namespace std;

#define fo(x,y,z) for(int x=y;x<z;x++)

vector<int> ch[200005];
int n, rem[200005], par[200005], col[200005];
queue<int> bfs; vector<int> op[200005];

int solve(int mode){
	int cpar[200005], m=0;
	while(!bfs.empty()) bfs.pop(); fo(i,0,200001) op[i].clear();
	fo(i,1,n+1){
		cpar[i] = par[i];
		if(!cpar[i]){
		   bfs.push(i); m++;
		   op[i].push_back(1);
		}
	}
	while(!bfs.empty()){
		int t = bfs.front(), ans = 0; bfs.pop();
		if(col[t] == mode){
			ans = 1<<30;
			fo(i,0,op[t].size()) ans = min(ans, op[t][i]);
		}
		else fo(i,0,op[t].size()) ans += op[t][i];
		if(t == 1){
			if(mode) return m-ans+1;
			else return ans;
		}
		else{
			op[rem[t]].push_back(ans);
			if(!(--cpar[rem[t]])) bfs.push(rem[t]);
		}
	}
	return 0;
}

void mc(int at, int cc){
	col[at] = cc;
	fo(i,0,ch[at].size()) mc(ch[at][i], (cc+1)%2);
}

int main(){
	scanf("%d", &n);
	fo(i,1,n){
		int u, v;
		scanf("%d %d", &u, &v);
		rem[v] = u; ch[u].push_back(v);
		par[u]++;
	}

	mc(1,1);
	printf("%d %d\n", solve(1), solve(0));
	return 0;
}

