/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 5e5+10;
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

const int Log = 20;

string s;
int n;
int a[Log+2][maxn];
vector < int > pos[2*maxn];

int solve(int l , int r = n-1){
	int cur = l;
	for(int i = Log-1 ; i >= 0 ; i --){
		if(cur + (1 << i) > r)continue;
		if(a[i][cur] >= a[0][l]-1)cur += (1 << i);
	}
	auto &v = pos[a[0][l]-1 + maxn];
	return(upper_bound(v.begin() , v.end() , cur) - 
	 upper_bound(v.begin() , v.end() , l ) + 1);
}

int32_t main(){
    migmig;
    cin >> n;
	cin >> s;
	SA(s);
	LCP(s);
	for(int i = 0 ; i < n ; i ++)
		a[0][i] = ((i)? a[0][i - 1] : 0) + ((s[i] == '(')? 1 : -1) , pos[a[0][i]+maxn].pb(i);
	for(int i = 0 ; i < Log ; i ++)
		for(int j = 0 ; j < n ; j ++)
			a[i+1][j] = min(a[i][j] , (j + (1 << i)>=n)?a[i][j]:a[i][j+(1 << i)]);
	ll ans = 0;
	for(int i = 0 ; i < n ; i ++){
		if(s[sa[i]] == ')')break;
		ans += solve(sa[i]) - solve(sa[i] , sa[i] + lcp[i] - 1);
	}
	cout << ans;
    return(0);
}
