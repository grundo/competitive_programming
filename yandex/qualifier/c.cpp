#include <cstdio>
#include <queue>

typedef long long ll;
struct doctype{
	ll val;
	int pos;
};
bool operator<(doctype a, doctype b){
	return a.val < b.val;
}

int n, doc[100005][100];

int main(){
   	ll cval[100005], a[105]; 
	doctype top10[10];
	std::priority_queue<doctype> pq;

	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]); 
	}

	int d;
	scanf("%d", &d);
	for(int i = 0; i < d; i++){
		ll csum = 0;
		for(int j = 0; j < n; j++){
			scanf("%d", &doc[i][j]);
			csum += a[j]*((ll)doc[i][j]);
		}
		cval[i] = csum;

		doctype temp;
		temp.val = csum;
		temp.pos = i;
		pq.push(temp);
	}

	for(int i = 0; i < 10; i++){
		top10[i] = pq.top();
		pq.pop();
	}

	int q;
	scanf("%d", &q);
	for(int x = 0; x < q; x++){
		int dummy;
		scanf("%d", &dummy);
		if(dummy-1){
			int cdoc, cj, nval;
			scanf("%d %d %d", &cdoc, &cj, &nval);	
			cj--; cdoc--;
			cval[cdoc] -= ((ll)doc[cdoc][cj])*a[cj];
			cval[cdoc] += ((ll)nval)*a[cj];
			doc[cdoc][cj] = nval;
			doctype temp;
			temp.val = cval[cdoc];
			temp.pos = cdoc;
			pq.push(temp);

			for(int i = 0; i < 10; i++) pq.push(top10[i]);

			for(int i = 0; i < 10; i++){
				if(cval[pq.top().pos] == pq.top().val){
					top10[i] = pq.top();
				}
				else{
					i--;
				}
				pq.pop();
			}
		}
		else{
			int k;
			scanf("%d", &k);
			for(int i = 0; i < k; i++){
				printf("%d%c", top10[i].pos+1, (i==(k-1))?'\n':' ');
			}
		}
	}

	return 0;
}

