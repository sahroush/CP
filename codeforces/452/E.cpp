//*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll  ,ll > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e5+100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int sa[maxn];
int rk[maxn];
int tp[maxn];
int cnt[maxn];
int lcp[maxn];

void SA(string &s){
	int A = 'z' , p = 0 , n = s.size();
	if(n == 1){
		sa[0] = rk[0] = 0;
		return;
	}
	for(int i = 0 ; i < n ; i ++)
		sa[i] = i , rk[i] = s[i];
	for(int j = 1 ; p < n - 1 ; j<<=1){
		p = 0;
		int k = (j>>1);
		for(int i = n - k ; i < n ; i ++)
			tp[p ++ ] = i;
		for(int i = 0 ; i < n ; i ++)
			if(sa[i] >= k)
				tp[p ++] = sa[i] - k;
		for(int i = 0 ; i <= A ; i ++)
			cnt[i] = 0;
		for(int i = 0 ; i < n ; i ++)
			cnt[rk[i]] ++;
		for(int i = 1 ; i <= A ; i ++)
			cnt[i] += cnt[i - 1];
		for(int i = n - 1 ; i >= 0 ; i --)
			sa[--cnt[rk[tp[i]]]] = tp[i];
		swap(rk , tp);
		rk[sa[0]] = p = 0;
		for(int i = 1 ; i < n ; i ++)
			p += (tp[sa[i - 1]]!=tp[sa[i]] || sa[i - 1] + k  >= n ||
			 tp[sa[i - 1]+k] != tp[sa[i] + k]) , rk[sa[i]] = p;
		A = p;
	}
}

void LCP(string &s){
	for(int i = 0 , k = 0 ; i < s.size() ; i ++){
		if(rk[i] == 0)continue;
		if(k) k --;
		while(s[i + k] == s[sa[rk[i] - 1] + k]) k ++;
		lcp[rk[i]] = k;
	}
}

string a , b , c;
ll ans[maxn] , contrib[maxn];
vector < int > pos[maxn];
int par[maxn] , sz[maxn];
ll A[maxn] , B[maxn] , C[maxn];

ll res = 0;

int getpar(int v){
	return((v == par[v])?v : par[v] = getpar(par[v]));
}

void merge(int u , int v){
	u = getpar(u) , v = getpar(v);
	if(u == v)return;
	res-=contrib[v] + contrib[u];
	res += 10LL*mod;
	res%=mod;
	if(sz[u] > sz[v])
		swap(u , v);
	par[u] = v;
	sz[v]+=sz[u];
	A[v]+=A[u];
	B[v]+=B[u];
	C[v]+=C[u];
	res+=(contrib[v] = ((A[v]*B[v])%mod*C[v])%mod);
	res%=mod;
}

int32_t main(){
    migmig;
	cin >> a >> b >> c;
	int mn = min({a.size() , b.size() , c.size()});
	string s = a + char(1) + b + char(2) + c;
	int n = s.size();
	SA(s);
	LCP(s);
	for(int i = 0 ; i < maxn ; i ++)par[i]=i , sz[i] = 1;
	for(int i = 0 ; i < n ; i ++) pos[lcp[i]].pb(i);
	for(int i = 0 ; i < n ; i ++){
		if(i<a.size())A[i]=1;
		else if(i>a.size() and i <= a.size()+b.size())B[i]=1;
		else C[i]=1;
	}
	for(int i = n ; i ; i -- ){
		for(int x : pos[i])
			merge(sa[x] , sa[x - 1]);
		ans[i] = res;
	}
	for(int i = 1 ; i <=  mn ; i ++)
		cout << ans[i]%mod << ' ';
    return(0);
}
