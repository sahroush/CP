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

ll a , b , n;
ll l , m , r;

bool chk(ll x){
	ll cur = a + x * b - b;
	ll sum = (a + l*b - b + cur)*(x - l + 1)/2;
	return((cur <= r and sum <= m * r));
}

int main(){
    migmig
    cin >> a >> b >> n;
    while(n -- ){
		cin >> l >> r >> m;
		ll ans = -1;
		ll L = l-1 , R = r+1;
		while(R - L > 1){
			ll mid = (L + R)/2;
			if(chk(mid)){
				ans = mid;
				L = mid;
			}
			else{
				R = mid;
			}
		}
		cout << ans << endl;
	}
    return(0);
}