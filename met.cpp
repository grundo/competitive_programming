#include <bits/stdc++.h>
using namespace std;

#define fo(x,y,z) for(int x=y;x<z;x++)
typedef long long ll;

struct pbs{
	int s, e, m;
};
struct pp{
	int A, B;
};
bool operator<(pp a, pp b){ return a.A > b.A;}
int n, m, k, pos[300005], ans[300005]; 
ll rq[300005], tr[600005], dirty[600005]; 
vector<int> st[300005]; pbs a[300005], mtr[300005]; 

void clean(int me){
	if(dirty[me]){
		tr[me] += dirty[me];
		if(me*2 < 600002) dirty[me*2+1] = dirty[me*2] = dirty[me];
		dirty[me] = 0;
	}
}

void up(int me, int s, int e, int rs, int re, int v){
	clean(me);
	if(s >= re || e <= rs) return;
	if(rs <= s && re >= e || re-rs <= 1){
		dirty[me] = v; return;
	}
	up(me*2, s, (s+e)/2, rs, re, v);
	up(me*2+1, (s+e)/2, e, rs, re, v);
}

ll q(int me, int s, int e, int pos){
	clean(me);
	if(e-s <= 1) return tr[me];
	int mid = (s+e)/2;
	if(pos < m) return q(me*2,s,mid,pos);
	else return q(me*2+1,mid,e,pos);
}

int main(){
	int t; pp tp;
	scanf("%d %d", &n, &m);
	fo(i,0,m){
		scanf("%d", &t);
		st[t].push_back(i+1);
	}
	fo(i,0,n+1) ans[i] = 1<<30;
	fo(i,0,n) scanf("%lld", &rq[i+1]);
	scanf("%d", &k);
	fo(i,0,k) scanf("%d %d %d", &mtr[i].s, &mtr[i].e, &mtr[i].m);
	fo(i,1,n+1){ a[i].s = 0; a[i].e = k;}
	priority_queue<pp> pq;
	while(1){
		while(!pq.empty()) pq.pop();
		memset(tr, 0, sizeof tr); memset(dirty, 0, sizeof dirty);
		bool sb = 1;
		fo(i,1,n+1) if(a[i].s <= a[i].e){
			pos[i] = 0;
			sb = 0; a[i].m = (a[i].s+a[i].e)/2;
			tp.A = a[i].m; tp.B = i; pq.push(tp);
		}
		if(sb) break;		
		fo(i,0,k+1){
			fo(j,1,m+1) printf("%d ", q(1,1,m+1,j));
			printf("\n");
			while(!pq.empty() && pq.top().A <= i){
				ll cur = 0;
				tp = pq.top(); pq.pop();				
				fo(j,0,st[tp.B].size()) cur += q(1,1,m+1,st[tp.B][j]);
				if(cur >= rq[tp.B])	pos[tp.B] = 1;
			}
			if(i == k) break;
			if(mtr[i].s > mtr[i].e){
				up(1,1,m+1, mtr[i].s, m+1, mtr[i].m);
				up(1,1,m+1, 1, mtr[i].e+1, mtr[i].m);
			}
			else up(1, 1, m+1, mtr[i].s, mtr[i].e+1, mtr[i].m);
		}
		fo(i,1,n+1) if(a[i].s <= a[i].e){
			if(pos[i]){
				ans[i] = min(ans[i], a[i].m);
				a[i].e = a[i].m-1;
			}
			else a[i].s = a[i].m+1;
		}
	}
	fo(i,0,n) (ans[i+1]==1<<30)?printf("NIE\n"):printf("%d\n", ans[i+1]);
}
