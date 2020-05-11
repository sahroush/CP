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

int n , q;
string s;
ll one[maxn];

int main(){
    migmig
    cin >> n >> q;
    cin >> s;
    s = '0'+s;
    for(int  i= 1 ; i <= n ; i ++){
		one[i] = one[i - 1] + s[i]-'0';
	}
    while(q -- ){
		ll l , r;
		cin >> l >> r;
		ll ones = one[r] - one[l - 1];
		ll ans = pw(2 , ones);
		ans+= mod-1;
		ans%=mod;
		ll x = ans;
		ll zeros = (r - l )+ 1 - ones;
		ans = (ans + ((pw(2 , zeros) - 1 + mod)%mod * x)%mod)%mod;
		cout << ans << endl;
		
	}
    return(0);
}