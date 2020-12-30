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

const ll maxn = 5e5 + 100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int a[maxn];

vector < int > comp;

int l[maxn] , r[maxn] , lst[maxn];

int seg[maxn * 4];

#define lc (v << 1)
#define rc (lc | 1)
#define mid ((l + r)>>1)

void update(int pos , int x , int v = 1 , int l = 0 , int r = n){
	if(r - l == 1){
		seg[v] = x;
		return;
	}
	if(pos < mid)
		update(pos, x , lc , l , mid);
	else
		update(pos, x , rc , mid , r);
	seg[v] = max(seg[lc] , seg[rc]);
}

int query(int R , int v = 1 , int l = 0 , int r = n ){
	if(l >= R)
		return(0);if(r - l == 1){
		if(seg[v] > R)
			return(l);
		return(0);
	}
	if(r >= R){
	    int x = query(R , rc , mid , r);
		if(x)
			return(x);
		return(query(R , lc , l , mid));
	}
	
	if(seg[rc] > R)	
		return(query(R , rc , mid , r));
	if(seg[lc] < R)
		return(0);
	return(query(R , lc, l , mid));
}

int dp[maxn];
int bq[maxn];
vector < int > vec[maxn];
int sem[maxn];

int prv(int i){
	for(int j = 0; j < 3 ; j ++)
		i = l[i];
	return(i);
}

vector < int > ans;

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i], comp.pb(a[i]);
	sort(comp.begin() , comp.end());
	comp.resize(unique(comp.begin() , comp.end()) - comp.begin());
	for(int i = 1 ; i <= n ; i ++)
		a[i] = lower_bound(comp.begin() , comp.end() , a[i]) - comp.begin() , a[i]++;
	for(int i = 1 ; i <= n ; i ++)
		l[i] = lst[a[i]],
		r[l[i]] = i,
		lst[a[i]] = i;
	for(int i = 1 ; i <= n ; i ++){
		int x = query(l[i]);
		
		if(!x){
			dp[i] = dp[i-1];
			bq[i] = -1;
		}
		else{
			dp[i] = max(dp[i - 1] , dp[x - 1] + 1);
			if(dp[i - 1] >= dp[x - 1] + 1)
				bq[i] = -1;
			else
				bq[i] = x;
		}
		x = prv(i);
		if(x){
			if(dp[x - 1] + 1 > dp[i]){
				dp[i] = 1 + dp[x - 1];
				sem[i] = 1;
			}
		}
		vec[r[i]].pb(i);
		for(int j : vec[i])
			update(j , i);
	}
	cout << 4 * dp[n] << endl;
	int pos = n;
	while(pos > 0){
		if(sem[pos]){
			for(int i = 0 ; i < 4 ; i ++)
				ans.pb(a[pos]);
			pos = prv(pos);
			pos--;
		}
		else if(bq[pos] == -1){
			pos --;
		}
		else{
			ans.pb(a[pos]);
			ans.pb(a[r[bq[pos]]]);
			ans.pb(a[pos]);
			ans.pb(a[r[bq[pos]]]);
			pos = bq[pos] - 1;
		}
	}
	reverse(ans.begin() , ans.end());
	for(int i : ans)cout << comp[i - 1] << ' ';
    return(0);
}
