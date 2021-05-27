//叫んで 藻掻もがいて 瞼まぶたを腫らしても
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e6;
const ll mod = 1e9+7;

#define pb push_back
//#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int rmn = 60;

int ask(int x){
	cout << "> " << x << endl;
	cin >> x;
	rmn --;
	return x;
}

int get(int i){
	cout << "? " << i << endl;
	cin >> i;
	rmn --;
	return i;
}

bool mark[maxn];

vector < ll > bz;

void solve(){
	int l = -1 , r = 1e9;
	while(r - l > 1){
		int mid = (l + r) / 2;
		if(ask(mid)) l = mid;
		else r = mid;
	}
	int x = n;
	while(x and ((n - x) <= rmn)){
		int r = rng()%n + 1;
		while(mark[r])r = rng()%n + 1;
		mark[r] = 1;
		bz.pb(r);
		x--;
	}
	for(int i = 0 ; i < (int)bz.size() ; i ++)
		bz[i] = get(bz[i]);
	sort(bz.begin() , bz.end());
	if(bz.back() != r)bz.pb(r);
	x = bz.size();
	ll d = bz[1] - bz[0];
	for(int i = 1 ; i < x ; i ++)
		d = __gcd(d , bz[i] - bz[i-1]);
	cout << "! " << r - d * (n - 1) << ' ' << d;
}

int lg(int x){
	int res = 0;
	while(x>1)res++ , x = (x + 1)/2;
	return res;
}

vector < ll > khr;

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	if(n <= 60){
		solve();
		return 0;
	}
	int x = 60;
	while(x){
		int r = rng()%n + 1;
		while(mark[r])r = rng()%n + 1;
		mark[r] = 1;
		bz.pb(r);
		x--;
	}
	ll l = -1, r = 1e9;
	for(int i = 0 ; i < 60 ; i ++){
		if(rmn == lg(r - l))break;
		khr.pb(get(bz[i]));
		l = max(l , khr.back() - 1);
	}
	while(r - l > 1){
		int mid = (l + r) / 2;
		if(ask(mid)) l = mid;
		else r = mid;
	}
	sort(khr.begin() , khr.end());
	swap(khr , bz);
	if(bz.back() != r)bz.pb(r);
	x = bz.size();
	ll d = bz[1] - bz[0];
	for(int i = 1 ; i < x ; i ++)
		d = __gcd(d , bz[i] - bz[i-1]);
	cout << "! " << r - d * (n - 1) << ' ' << d;
	return(0);
}
