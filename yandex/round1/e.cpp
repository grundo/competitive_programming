#include <bits/stdc++.h>
using namespace std;

#define fo(x,y,z) for(int x=y;x<z;x++)

struct query{
	int type, k, x, y;
} t, q[200005];
int cv=1, cs, a[200005], k, x, y, ts = 1;
char temp;

int main(){
	scanf(" %d ", &m);	
	fo(i,0,m){
		scanf(" %c ", temp);
		if(temp == '+'){
			t.type = 0;
			scanf(" %d ", &t.k);
			q[i] = t;
			ts = (ts*t.k)+1;
		}
		else{
			t.type = 1;
			scanf(" %d %d ", &t.x, &t.y);
			q[i] = t;
		}
	}

	for(int i = m-1; i-- >= 0;){	
		if(!q[i].type()){
			cv *= q[i].k;
			a[cs++] = cv;
		}
	}
	fo(i,0,m) if(q[i].type()){

	}

