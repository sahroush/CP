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


int l,w;
int a[maxn];
ll b[maxn];
ll ans  = 1e10;


int main(){
	cin >> w >> l;
	for(int i = 1; i <= w-1 ; i++) {
        cin >> a[i];
    	b[i] =a[i] + b[i-1];
    }
    for(int i = l; i <= w - 1; i++) {
        ans = min(ans, b[i] - b[i - l]);
    }
    cout << ans;
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
