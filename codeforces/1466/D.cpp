/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn = 3e6;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll sum = 0;

int q;
int n;
int d[maxn];
vector < pii >st;

ll w[maxn];

int32_t main(){
    migmig;
	cin >> q;
	while(q -- ){
		cin >> n;
		sum = 0;
		st.clear();
		for(int i = 1 ; i <= n ; i ++)
			cin >> w[i] , sum += w[i];
		for(int i = 1 ; i < n ; i ++){
			int u , v;
			cin >> u >> v;
			d[u] ++ , d[v]++;
		}
		for(int i = 1 ; i <= n ; i ++){
			d[i] --;
			if(d[i])st.pb({w[i] , i});
		}
		sort(st.begin() , st.end());
		cout << sum << ' ';
		while(st.size()){
			auto [qq , x] = st.back();
			st.pop_back();
			d[x]--;
			sum += w[x];
			if(d[x])st.pb({w[x] , x});
			cout << sum << ' ';
		}
		cout << endl;
	}




    return(0);
}
