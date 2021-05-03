//曇り空 のぞいた予感
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1<<18;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define f ((maxn - 1)^a[i])
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int a[maxn] , p[maxn];
pii mx[maxn][2];
pii Mx[maxn];
ll sum , ans;

int getpar(int v){
	if(v == -1)return -1;
	return ((p[v]) ? p[v] = getpar(p[v]) : v);
}

void build(){
	for(int i = 0 ; i < maxn ; i ++)mx[i][0] = mx[i][1] = {-1 , -1};
	for(int i = 1 ; i <= n ; i ++){
		auto &v = mx[a[i]];
		if(v[0] == pii(-1 , -1)) v[0] = pii(a[i] , i);
		else if(v[1] == pii(-1 , -1) and getpar(v[0].second) != getpar(i)) v[1] = pii(a[i] , i);
	}
	for(int i = 0 ; i < maxn ; i ++){
		for(int j = 0 ; j < 18 ; j ++)if(i & (1 << j)){
			auto &v = mx[i];
			auto &u = mx[i^(1<<j)];
			for(int k = 0 ; k < 2 ; k ++)
			if(v[1] >= u[k])continue;
			else if(v[0] < u[k] and getpar(v[0].second) == getpar(u[k].second))v[0] = u[k];
			else if(v[0] < u[k] and getpar(v[1].second) == getpar(u[k].second))v[1] = u[k] , swap(v[0] , v[1]);
			else if(v[0] < u[k])v[1] = u[k] , swap(v[0] , v[1]);
			else if(v[1] < u[k] and getpar(v[1].second) == getpar(u[k].second))v[1] = u[k];
			else if(v[1] < u[k] and getpar(v[0].second) != getpar(u[k].second))v[1] = u[k];
		}
	}
}

void merge(int u , int v){
	if(getpar(u) == getpar(v))return;
	ans += a[u] + a[v];
	p[getpar(u)] = getpar(v);
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)cin >> a[i] , sum += a[i];
	n++;
	for(int t = 1 ; t ;){
		t = 0;
		build();
		ms(Mx , 0);
		for(int i = 1 ; i <= n ; i ++){
			if(mx[f][0].second ^ - 1 and getpar(mx[f][0].second) != getpar(i))
				if(a[Mx[getpar(i)].first] + a[Mx[getpar(i)].second] <= a[i] + mx[f][0].first)
					Mx[getpar(i)] = pii(i , mx[f][0].second);
			if(mx[f][1].second ^ - 1 and getpar(mx[f][1].second) != getpar(i))
				if(a[Mx[getpar(i)].first] + a[Mx[getpar(i)].second] <= a[i] + mx[f][1].first)
					Mx[getpar(i)] = pii(i , mx[f][1].second);
		}
		for(int i = 1 ; i <= n ; i ++)if(Mx[getpar(i)].first)
			merge(Mx[getpar(i)].first , Mx[getpar(i)].second) , t = 1;
	}
	cout << ans - sum;
	return(0);
}
