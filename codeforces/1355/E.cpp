#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n, a , r , m;
ll h[maxn];

ll solve(ll x){
	ll more = 0;
	ll need = 0;
	for(int i = 0 ; i < n ; i ++){
		if(h[i] > x)
			more+=h[i]-x;
		else
			need+=x-h[i];
	}
	ll cost = more*r + need * a;
	if(m < r+a){
		cost-=(r+a)*min(need , more);
		cost+=m*min(need , more);
	}
	return(cost);
}

int main(){
    migmig
    cin >> n >> a >> r >> m;
    for(int i = 0 ; i < n ; i ++)
		cin >> h[i];
    ll l = 0 , r=1e9+10;
    while(r-l>1){
		ll mid = (r + l)/2;
		if(solve(mid) > solve(mid+1)){
			l = mid;
		} 
		else{
			r = mid;
		}
	}
	ll ans = solve(l);
	for(int i = 1 ; i < 10 ; i ++){
		ans = min(ans , solve(l+i));
		ans = min(ans , solve(l-i));
	}
    cout << ans;
    return(0);
}