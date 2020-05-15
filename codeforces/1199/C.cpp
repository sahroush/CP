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

ll n , l;
ll a[maxn];
ll cnt[maxn];
ll prt[maxn];

int main(){
    migmig
    cin >> n >> l ;
    for(int i = 0 ; i < n ; i ++)
		cin >> a[i];
	l*=8;
	sort(a , a + n);
	ll mx = l/n;
	mx = (1 << mx);
	ll cur = 1;
	for(int i = 0 ; i < n ; i ++)
		if(i)
			if(a[i]==a[i-1])
				cnt[cur]++;
			else 
				++cnt[++cur];
		else
			++cnt[cur];
	if(l/n >= 19 or mx >= cur){
		dokme(0);
	}
	for(int i = 1 ; i <= cur ; i ++)
		prt[i] = prt[i-1]+cnt[i];
    ll ans = n;
    for(int i = 1 ; i <= cur - mx  + 1 ; i ++){
		ans = min(ans , n - (prt[i + mx - 1] - prt[i-1]));
	}
	cout << ans;
    return(0);
}