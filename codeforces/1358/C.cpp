#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
ll a1 , b1 , a2 , b2;

int main(){
    migmig
    cin >> q;
    
    while(q -- ){
		cin >> a1 >> b1 >> a2 >> b2;
		ll x = a2 - a1;
		ll y = b2 - b1;
		if(x == 0 or y == 0){
			cout << 1 << endl;
			continue;
		}
		ll ans = 0;
		ll mx = min(x , y);
		ans += mx*(mx+1) - mx * (x==y);
		ll lines = (2*y + 2*x - 2)/2;
		lines -= 2*mx - (x==y);
		ans += lines * mx;
		cout << ans+1 << endl;
	}
    return(0);
}