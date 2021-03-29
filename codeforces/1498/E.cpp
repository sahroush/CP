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

const int maxn = 510;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
pii d[maxn];
vector < int > vec[maxn];
int ans = 0;
pii mx = {1 , 1};

int c2(int x){
	return x * (x - 1) / 2;
}

int32_t main(){
	migmig;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> d[i].first , d[i].second = i;
	sort(d + 1 , d + 1 + n);
	int cur = 1;
	int sum = 0;
	for(int i = 1 ; i <= n ; i ++){
		sum += d[i].first;
		vec[cur].pb(i);
		if(sum == c2(i))
			cur++;
	}
	if(cur == n + 1)dokme("! 0 0");
	for(int i = 1 ; i <= cur ; i ++)if(vec[i].size() >= 2){
		int sz = vec[i].size();
		for(int j = 0 ; j < sz ; j ++)
			for(int k = j+1 ; k < sz ; k ++)
				if(abs(d[vec[i][j]].first - d[vec[i][k]].first) >= ans)
					ans = abs(d[vec[i][j]].first - d[vec[i][k]].first) , 
					mx = {d[vec[i][j]].second , d[vec[i][k]].second};
	}
	cout << "! " << mx.first << ' ' << mx.second;
	return(0);
}
