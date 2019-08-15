#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX = 5e5+10;
const ll ZERO = 0; 
const ll SADAT = 7.84e-17;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll m,n,k;
bool chk(ll x){
    ll r = 0;
    for(int i = 1 ;i < n+1 ;i++) r+=min((ll)m,x/i);
    return r < k;
}

int main(){
	cin >> n  >> m >> k;
  	ll l = 0,r = (ll) 1e15;
    while(l < r){
        ll m=(l+r)/2;
        if(chk(m))  l= m+1;
        else r = m;
    }
    cout << l;
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
