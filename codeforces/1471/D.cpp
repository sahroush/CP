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

const ll maxn = 1e6 + 100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q , Q;
int n;
int cnt[maxn];
vector < int > undo;
ll w;
ll val[maxn];

bool prime[maxn];

int32_t main(){
    migmig;
	cin >> Q;
	for(int i = 2 ; i < maxn ; i ++)prime[i] = 1;
	for(int i = 2 ; i < maxn ; i ++){
		val[i] = 1;
		if(!prime[i])continue;
		for(int j = i + i ; j < maxn ; j += i)
			prime[j] = 0;
	}
	for(int i = 2 ; i < maxn ; i ++){
		if(!prime[i])continue;
		ll cur = 1;
		while(cur*i < maxn){
			cur = cur*i;
			for(int j = cur ; j < maxn ; j += cur){
				if(val[j]%i == 0)
					val[j]/=ll(i);
				else
					val[j]*=ll(i);
			}
		}
	}
	val[1] = 1;
	while(Q --){
		cin >> n;
		for(int i = 0 ; i < n ; i ++){
			int a;
			cin >> a;
			cnt[val[a]]++;
			undo.pb(val[a]);
		}
		undo.pb(1);
		sort(undo.begin() , undo.end());
		undo.resize(unique(undo.begin() , undo.end()) - undo.begin());
		int mx0 = 0;
		for(int i : undo)
			mx0 = max(mx0 , cnt[i]);
		int mx1 = 0;
		for(int i : undo)
			if(i > 1 and cnt[i]%2 == 0)
				cnt[1] += cnt[i] , cnt[i] = 0;
		for(int i : undo)
			mx1 = max(mx1 , cnt[i]);
		cin >> q;
		while(q -- ){
			cin >> w;
			if(w == 0)
				cout << mx0 << endl;
			else
				cout << mx1 << endl;
		}
		for(int i : undo)
			cnt[i] = 0;
		undo.clear();
	}




    return(0);
}
