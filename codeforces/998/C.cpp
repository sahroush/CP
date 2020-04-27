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

ll n , x , y;
string s;

int main(){
    migmig
    cin >> n >> x >> y;
    cin >> s;
    ll seg=  0;
    s+="1";
    for(int i = 1 ; i <= n;  i ++){
		if(s[i] == '1' and s[i - 1] == '0')
			seg++;
	}
	if(!seg)dokme(0);
	seg--;
	ll ans = y + min(x , y) * seg ;
	cout << ans;
    return(0);
}

