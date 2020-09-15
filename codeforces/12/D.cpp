/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 5e5+100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define all(x) x.begin() , x.end()
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
pair < int , pii > inp[maxn];
pii a[maxn];
int ind[maxn];
vector < int > vec;
int seg[maxn*4];

void add(int x , int pos , int v = 1  , int l = 1 ,int r = maxn){
	if(pos >= r or pos < l)
		return;
	if(r - l == 1){
		seg[v] = max(seg[v] , x);
		return;
	}
	add(x , pos , 2*v , l , (l+r)/2);
	add(x , pos , 2*v + 1, (l + r)/2 , r);
	seg[v] = max(seg[2*v] , seg[2*v + 1]);
}
int get(int L , int R , int v = 1 , int l = 1 , int r = maxn){
	if(R <= l or r <= L)
		return(0);
	if(L <= l and r <= R)
		return(seg[v]);
	return(max(
		get(L , R , 2*v , l , (l + r)/2),
		get(L , R , 2*v+1 , (l + r)/2 , r)
	));
}

bool mark[maxn];

int32_t main(){
    migmig
	cin >> n;
	for(int i = 0 ; i < n ; i ++)
		cin >> inp[i].first;
	for(int i = 0 ; i < n ; i ++)
		cin >> inp[i].second.first;
	for(int i = 0 ; i < n ; i ++)
		cin >> inp[i].second.second;
	sort(inp , inp + n);
	for(int i = 0 ; i < n ; i ++)
		a[i] = inp[i].second,
		vec.pb(a[i].first),
		vec.pb(a[i].second),
		ind[i] = inp[i].first;
	sort(all(vec));
	vec.resize(unique(all(vec)) - vec.begin());
	for(int i = 0 ; i < n ; i ++)
		a[i].first = lower_bound(all(vec) , a[i].first) - vec.begin(), a[i].first++,
		a[i].second = lower_bound(all(vec) , a[i].second) - vec.begin(), a[i].second++;
	reverse(a , a + n);
	reverse(ind , ind + n);
	int ans = 0;
	for(int i = 0 ; i < n ;i++){
		if(mark[i])continue;
		for(int j = i ; j < n ; j ++)
			if(ind[j]!=ind[i])break;
			else if(get(a[j].first + 1 , maxn) > a[j].second) ans++;
		for(int j = i ; j < n ; j ++)
			if(ind[j]!=ind[i])break;
			else add(a[j].second , a[j].first),mark[j]=1;
	}
	cout << ans;
    return(0);
}