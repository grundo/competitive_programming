#include <bits/stdc++.h>
using namespace std;

#define fo(x,y,z) for(int x=y;x<z;x++)
int k, l, s;
bool need[26];

int main(){
	int tc;
	cin >> tc; 
	fo(z,1,tc+1){
		printf("Case #%d: ", z);
		string keyb, targ;
		cin >> k >> l >> s;
		cin >> keyb;
		cin >> targ;

		int ov = 0;
		fo(i,1,l){
			bool pos = 1;
			fo(j,0,l-i) if(targ[j] != targ[j+i]) pos = 0;
			if(pos){
				ov = l-i;
				break;
			}
		}	
		int tb = (s < l)?0:1, cd = l;
		while(cd+(l-ov) <= s){
			tb++;
			cd += (l-ov);
		}
		fo(i,0,26) need[i] = 0;

		fo(i,0,l) need[targ[i]-'A'] = 1;
		fo(i,0,k) need[keyb[i]-'A'] = 0;
		bool tri = 1;
		fo(i,0,26) if(need[i]){
		   	tri = 0;
			break;
		}
		if(!tri) tb = 0;

		long long dem = 1;
		fo(i,0,s) dem *= k;
		long long num = 0;
		fo(i,0,dem){
			int cur = i;
			string temp;
			fo(j,0,s){
				temp += keyb[cur%k];
				cur /= k;
			}
			int nb = 0;
			fo(j,0,s-l+1){
				bool pos = 1;
				fo(i,0,l) if(targ[i] != temp[j+i]) pos = 0;
				if(pos) nb++;
			}
			num += (tb-nb);
		}
		
		double ans = (double)num / (double)dem;		
		printf("%lf\n", ans);
	}
	return 0;
}
