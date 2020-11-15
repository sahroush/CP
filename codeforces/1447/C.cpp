/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<ll  ,ll > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int n;
ll lim;
pii w[maxn];

vector < pii > vec;
vector < int > ans;

int32_t main(){
    migmig;
	cin >> q;
	while(q -- ){
		cin >> n >> lim;
		ll l = (lim + 1) / 2 , r = lim;
		vec.clear();
		for(int i = 0;  i < n ; i ++)cin >> w[i].first , w[i].second = i+1 ;
		sort(w , w + n);
		ll sum = 0;
		for(int i = 0 ; i < n ; i ++){
			if(w[i].first > r)continue;
			vec.pb(w[i]);
			sum += w[i].first;
		}
		if(sum < l or vec.size() == 0){
			cout << -1 << endl;
			continue;
		}
		reverse(vec.begin() , vec.end());
		while(sum > r)
			sum-=vec.back().first , vec.pop_back();
		cout << vec.size() << endl;
		for(auto [a , b] : vec)
			cout << b << ' ';
		cout << endl;
		
	}
    return(0);
}
