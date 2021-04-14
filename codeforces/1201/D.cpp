//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e6;
const ll mod = 1e9+7;

#define pb push_back
#define int ll
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m , k , q;
int l[maxn] , r[maxn] , gd[maxn];


int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m >> k >> q;
	ms(l , 63);
	int mx = 0;
	for(int i = 1 ; i <= k ; i ++){
		int x , y;
		cin >> x >> y;
		mx = max(mx , x);
		l[x] = min(l[x] , y);
		r[x] = max(r[x] , y);
	}
	for(int i = 1 ; i <= q ; i ++)
		cin >> gd[i];
	sort(gd + 1 , gd + q + 1);
	int curl , curr , L , R;
    if(r[1])
		curl = r[1] - 1 + r[1] - l[1], curr = r[1] - 1, L = l[1], R = r[1];
	else
		curl = curr = 0 , L = R = 1;
    for(int i = 2 ; i <= mx ; i ++)if(r[i]){
		int el = lower_bound(gd + 1 , gd + q + 1 , L) - gd;
		int er = lower_bound(gd + 1 , gd + q + 1 , R) - gd;
		int ul = 1e17 , ur = 1e17 , LL = 1e17 , lr = 1e17 , rl = 1e17 , rr = 1e17;
		if(el <= q)lr = gd[el];
		if(el > 1)LL = gd[el - 1];
		if(er > 1)rl = gd[er - 1];
		if(er <= q)rr = gd[er];
		ul = min(ul , curl + abs(L - LL) + abs(LL - r[i]) + (r[i]-l[i]));
		ul = min(ul , curl + abs(L - lr) + abs(lr - r[i]) + (r[i]-l[i]));
		ul = min(ul , curr + abs(R - rl) + abs(rl - r[i]) + (r[i]-l[i]));
		ul = min(ul , curr + abs(R - rr) + abs(rr - r[i]) + (r[i]-l[i]));
		ur = min(ur , curl + abs(L - LL) + abs(LL - l[i]) + (r[i]-l[i]));
		ur = min(ur , curl + abs(L - lr) + abs(lr - l[i]) + (r[i]-l[i]));
		ur = min(ur , curr + abs(R - rl) + abs(rl - l[i]) + (r[i]-l[i]));
		ur = min(ur , curr + abs(R - rr) + abs(rr - l[i]) + (r[i]-l[i]));
		curl = ul  , curr = ur , L = l[i] , R = r[i];
	}
	cout << min(curl , curr)+ mx - 1;
	return(0);
}
