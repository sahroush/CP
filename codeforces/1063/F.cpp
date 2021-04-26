//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 5e5+10;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
string s;

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
	for(int i = 0 , k = 0 ; i < (int)s.size() ; i ++){
		if(rk[i] == 0)continue;
		if(k) k --;
		while(s[i + k] == s[sa[rk[i] - 1] + k]) k ++;
		lcp[rk[i]] = k;
	}
}

#define lc (v << 1)
#define rc (lc | 1)
#define mid ((l + r) >> 1)


struct segtree{
	int mx[maxn<<2];
	void modify(int pos , int x , int v = 1 , int l = 1 , int r = n + 1){
		if(r - l == 1){
			mx[v] = x;
			return;
		}
		if(pos < mid)modify(pos , x , lc , l , mid);
		else modify(pos , x , rc , mid , r);
		mx[v] = max(mx[lc] , mx[rc]);
	}
	int get(int L , int R , int v = 1 , int l = 1 , int r = n + 1){
		if(r <= L or R <= l)return 0;
		if(L <= l and r <= R)return mx[v];
		return max(get(L , R , lc , l , mid) , get(L , R , rc , mid , r));
	}
	int getl(int L , int R , int x , int v = 1 , int l = 1 , int r = n + 1){
		if(r - l == 1){
			if(-mx[v] < x)return l;
			return 0;
		}
		if(L <= l and r <= R){
			if(-mx[rc] < x)
				return getl(L , R , x , rc , mid , r);
			if(-mx[lc] < x)
				return getl(L , R , x , lc , l , mid);
			return 0;
		}
		int res = 0;
		if(R > mid){
			res = getl(L , R , x , rc , mid , r);
			if(res)return res;
		}
		if(L < mid){
			res = getl(L , R , x , lc , l , mid);
			if(res)return res;
		}
		return 0;
	}
	int getr(int L , int R , int x , int v = 1 , int l = 1 , int r = n + 1){
		if(r - l == 1){
			if(-mx[v] < x)return l;
			return R;
		}
		if(L <= l and r <= R){
			if(-mx[lc] < x)
				return getr(L , R , x , lc , l , mid);
			if(-mx[rc] < x)
				return getr(L , R , x , rc , mid , r);
			return R;
		}
		int res = R;
		if(L < mid){
			res = getr(L , R , x , lc , l , mid);
			if(res^R)return res;
		}
		if(R > mid){
			res = getr(L , R , x , rc , mid , r);
			if(res^R)return res;
		}
		return R;
	}
	pii segment(int pos, int x){
		return pii(getl(1 , pos , x)+1 , getr(pos , n+1 , x));
	}
}mn, mx;

int dp[maxn];

bool chk(int i){
	if(dp[i] == 1)return 1;
	if(i + dp[i] > n)return 0;
	pii seg = mn.segment(rk[i] , dp[i] - 1);
	if(mx.get(seg.first , seg.second+1) >= dp[i] - 1)return 1;
	seg = mn.segment(rk[i+1] , dp[i] - 1);
	if(mx.get(seg.first , seg.second+1) >= dp[i] - 1)return 1;
	return 0;
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> s;
	SA(s);
	LCP(s);
	for(int i = n ; i >= 1 ; i --)sa[i] = sa[i-1]+1 , rk[i] = rk[i-1]+1 , mn.modify(i , -lcp[i]);
	for(int i = n ; i >= 1 ; i --){
		dp[i] = dp[i + 1] + 1;
		chk(i);
		while(!chk(i)){
			dp[i] --;
			if(i + dp[i] <= n) mx.modify(rk[i + dp[i]] , dp[i + dp[i]]);
		}
	}
	cout << *max_element(dp , dp + maxn);
	return(0);
}
