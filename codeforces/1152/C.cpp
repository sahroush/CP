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

ll a , b;
ll mn = 4e18;
ll ans= 0;
ll val = -1;

void chk(ll k){
	ll need = (k - (a%k))%k;
	ll lcm = (a + need) * (b + need) / __gcd(a + need , b + need);
	if((b + need)%k!=0)return;
	if(lcm < mn){
		mn = lcm;
		ans = need;
	}
	if(lcm == mn){
		ans = min(ans , need);
	}
}

int main(){
    migmig
    cin >> a >> b;
    if(a > b)swap(a , b);
    ll x = b - a;
    for(int i = 1 ; i * i <= x ; i ++){
		if(x%i == 0){
			chk(i);
			chk(x / i);
		}
	}
    ll lcm = a*b / __gcd(a , b);
    if(lcm <= mn)dokme(0);
    cout << ans;
    return(0);
}

