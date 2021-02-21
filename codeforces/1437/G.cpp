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

const int maxn = 3e5 + 100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

const int sigma = 27;

int n;
string s;
int pos[maxn];
int val[maxn];
set < pii > st[maxn];
int sz = 0;
bool endpoint[maxn];
int nxt[sigma][maxn] , f[maxn] , ext[maxn];
int mx[maxn];

int add(string &s){
	int cur = 0;
	for(char c : s){
		if(!nxt[c - 'a'][cur])nxt[c - 'a'][cur] = ++sz;
		cur = nxt[c - 'a'][cur];
	}
	endpoint[cur] = 1;
	return(cur);
}

struct que{
	int l = 0 , r = 0;
	int q[maxn];
	void push(int x){
		q[r++] = x;
	}
	int front(){
		return(q[l]);
	}
	void pop(){
		l++;
	}
	int size(){
		return(r - l);
	}
}q;

void build(){
	for(int i = 0 ; i < sigma ; i ++)if(nxt[i][0])q.push(nxt[i][0]);
	while(q.size()){
		int v = q.front();
		q.pop();
		if(endpoint[f[v]])ext[v] = f[v];
		else ext[v] = ext[f[v]];
		for(int i = 0 ; i < sigma ; i ++)
			if(!nxt[i][v])nxt[i][v] = nxt[i][f[v]];
			else f[nxt[i][v]] =  nxt[i][f[v]] , q.push(nxt[i][v]);
	}
}

int32_t main(){
	migmig;
	int q;
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i ++){
		cin >> s;
		pos[i] = add(s);
		st[pos[i]].insert({0 , i});
	}
	build();
	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			int i , x;
			cin >> i >> x;
			st[pos[i]].erase({val[i] , i});
			val[i] = x;
			st[pos[i]].insert({val[i] , i});
			mx[pos[i]] = (*st[pos[i]].rbegin()).first;
		}
		else{
			string s;
			cin >> s;
			int ans = -1;
			int cur = 0;
			for(char c : s){
				cur = nxt[c - 'a'][cur];
				int Cur = cur;
				while(Cur){
					if(endpoint[Cur])ans = max(ans , mx[Cur]);
					Cur = ext[Cur];
				}
			}
			cout << ans << endl;
		}
	}
	return(0);
}
