#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 1e5+100;
const ll ZERO = 0; 
const ll SADAT = 7.84e-17;
const ll INF = 1000100000;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int n,m,w;
ll a[maxn], s[maxn], d[maxn];

bool check(ll x){
	ll ans = ZERO;
	fill(s,s+maxn,0);
	fill(d,d+maxn,0);
	for (int i = 0 ; i < n  ; i ++)
		if(x > a[i])
			d[i] = x - a[i];
	ll rd = 0;
	for ( int  i = 0 ; i < n ; i ++){
		if(i) s[i] += s[i-1];
		d[i] += s[i];
		if(i + w - 1 < n){
			if(d[i] > 0){
				int y = d[i];
				ans += (ll)y;
				s[i] -= y;
				s[i+w] += y;
			}
		}
		else rd = max(rd, d[i]);
	}
	ans += rd;
	return (ans <= m);
}





int main(){
	cin >> n >> m >> w;
	for (int  i = 0 ; i < n ; i ++) cin >> a[i];
	ll mid , l=0  , r = INF;
	
	
	while(l < r){
		mid = (l+r)/2;
		//cout << check(mid);
		if(check(mid)) l = mid;
		else r = mid-1;
		if(l == r-1){
			if(check(r)) {
				dokme(r);	
			}
			dokme(l);
			break;
		}
	}
	dokme(l);
	




	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
