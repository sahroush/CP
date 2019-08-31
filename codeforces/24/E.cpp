#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll maxn = 5e5+10;
const ll ZERO = 0; 
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
 
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int n;
int v[maxn],x[maxn];
double l=0 , r=1e10,m,ma;
 
int main(){
	migmig;
	cin >> n;
	for (int i = 0 ; i < n ; i ++){
		cin >> x[i] >> v[i];
		//scanf("%d",x+i);scanf("%d",v+i);
	}
	
	for (int i=0 ; i < 66 ; i++){	
		m=(l+r)/2.0;
		bool f = false;
		ma=-1e40;
		//f=ma :))
		for (int j = 0 ; j < n ; j ++){
			double d=m*v[j]+x[j];
			if (v[j]>0) ma=max(ma,d);
			else if(d<=ma){
				f = true;
				break;
			}
		}
		if (f) r=m;
		else l=m;
	}
	if (r >= 1e10) {
		dokme(-1);	
	}
	else cout << fixed << setprecision(10) << (l+r)/2;
		
	return(0);
}