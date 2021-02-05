/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e6;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int n , m;
int a[maxn] , b[maxn] , c[maxn];

vector < int > bad[maxn] , ans;

int32_t main(){
	migmig;
	cin >> q;
	while(q --){
		cin >> n >> m;
		for(int i = 1 ; i <= n ; i ++)
			bad[i].clear() , cin >> a[i];
		for(int i = 1 ; i <= n ; i ++)
			cin >> b[i];
		for(int i = 1 ; i <= m ; i ++)
			cin >> c[i];
		int lst = 0;
		bool ok = 1;
		for(int i = 1 ; i <= n ; i ++)
			if(b[i] == c[m])lst = i;
		for(int i = 1 ; i <= n ; i ++)
			if(a[i] != b[i] and b[i] == c[m])lst = i;
		for(int i = 1 ; i <= n ; i ++)
			if(a[i] != b[i] and i != lst)
				bad[b[i]].pb(i);
		if(lst == 0)ok = 0;
		ans.clear();
		for(int i = 1 ; i <= m ; i ++)
			if(bad[c[i]].size())
				ans.pb(bad[c[i]].back()) ,a[bad[c[i]].back()] = c[i] ,bad[c[i]].pop_back();
			else
				ans.pb(lst) , a[lst] = c[i];
		for(int i = 1 ; i <= n ; i ++)if(a[i] != b[i])ok = 0;
		if(!ok){
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		for(int i : ans)
			cout << i << ' ';
		cout << endl;
	}
	return(0);
}
