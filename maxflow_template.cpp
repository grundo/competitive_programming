#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 222
#define M (N*N)
#define fo(i,a,b) for (int i = (a); i < (b); i++)

namespace MF {
	int n, m, s, t, fr[M], to[M]; ll fl[M], cp[M]; int dst[N];
	char sn[N];
	vector<int> al[N];
	queue<int> q;

	void init(int _n) {
		n = _n+2; m = 0; s = _n; t = _n+1;
		fo(i,0,n) al[i].clear(), sn[i] = 0;
	}
	void add(int a, int b, ll c) {
		al[a].push_back(m); fr[m] = a; to[m] = b; fl[m] = 0; cp[m] = c; m++;
		al[b].push_back(m); fr[m] = b; to[m] = a; fl[m] = 0; cp[m] = 0; m++;
	}
	bool bfs() {
		fo(i,0,n) dst[i] = i==s ? 0 : -1;
		q.push(s);
		while (!q.empty()) {
			int at = q.front(); q.pop();
			fo(i,0,al[at].size()) {
				int e = al[at][i];
				if (dst[to[e]] != -1 || fl[e] == cp[e]) continue;
				dst[to[e]] = dst[at]+1;
				q.push(to[e]);
			}
		}
		return dst[t] != -1;
	}
	ll aug(int at, ll cf) {
		if (at==t) return cf;
		fo(i,0,al[at].size()) {
			int e = al[at][i];
			if (dst[to[e]] != dst[at]+1 || fl[e] == cp[e]) continue;
			ll tf = aug(to[e], min(cf, cp[e] - fl[e]));
			if (tf) {
				fl[e] += tf;
				fl[e^1] -= tf;
				return tf;
			}
		}
		dst[at] = -1;
		return 0;
	}
	ll mf() {
		ll ans = 0;
		while (bfs()) for (int add = aug(s,1e18); add; add = aug(s,1e18)) ans += add;
		return ans;
	}
	void dfs(int at) {
		sn[at] = 1;
		fo(i,0,al[at].size()) {
			int eid = al[at][i];
			if (fl[eid] != cp[eid]) {
				if (!sn[to[eid]]) dfs(to[eid]);
			}
		}
	}
	vector<int> mc() {
		dfs(s);
		vector<int> ret;
		fo(i,0,m) if (sn[fr[i]] && !sn[to[i]]) ret.push_back(i);
		return ret;
	}
}
