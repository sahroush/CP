#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll  ,ll > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e7+100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int ch[maxn][2];
int cnt[maxn][2];
int cur = 0;
ll n;
int a[1001000];

void add(ll x){
	int pos = 0;
	for(int i = 29 ; i>=0 ; i --){
		int nxt = (x & (1 << i))>0;
		if(ch[pos][nxt]!=0){
			cnt[pos][nxt]++;
			pos = ch[pos][nxt];
		}
		else{
			ch[pos][nxt] = ++cur;
			cnt[pos][nxt]++;
			pos = ch[pos][nxt];
		}
	}
}

ll solve(ll x , ll l){
	int pos = 0;
	ll ans = 0;
	for(int i = 29 ; i>=0 ; i --){
		int tl= (l & (1 << i))>0;
		int tx= (x & (1 << i))>0;
		if(tx and tl){
			ans+=cnt[pos][1];
			if(cnt[pos][0]==0)break;
			pos = ch[pos][0];
		}
		if(!tx and !tl){
			if(cnt[pos][0]==0)break;
			pos = ch[pos][0];
		}
		if(tx and !tl){
			if(cnt[pos][1] == 0)break;
			pos = ch[pos][1];
		}
		if(tl and !tx){
			ans+=cnt[pos][0];
			if(cnt[pos][1] == 0)break;
			pos = ch[pos][1];
		}
	}
	return(ans);
}

ll k;

int main(){
    migmig
	cin >> n >> k;
	add(0);
	ll ans = 0;
	for(ll i = 1 ; i <= n ; i ++){
		cin >> a[i];
		a[i] = a[i]^a[i-1];
		ans+=solve(a[i] , k);
		add(a[i]);
	}
	cout << n*(n+1)/2LL-ans;
    return(0);
}