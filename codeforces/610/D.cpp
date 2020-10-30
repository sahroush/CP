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

const ll maxn  = 8e5;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

struct BIT {
	int fen[maxn];
	void add(int x , int pos){
		for(pos += 5 ; pos < maxn ; pos += pos & -pos)
			fen[pos] += x;
	}
	int get(int pos){
		int ans = 0;
		for(pos += 5 ; pos ; pos -= pos & -pos)
			ans += fen[pos];
		return(ans);
	}
	int get(int l , int r){
		return(get(r) - get(l - 1));
	}
};

BIT fen;

int n;

struct line{
	ll x1 , y1 , x2 , y2;
	line(int a , int b , int c , int d):
		x1(a) , y1(b) , x2(c) , y2(d){}
	bool vertical(){
		return(x1 == x2);
	}
	ll sum(){
		return(abs(x1 - x2) + abs(y1 - y2));
	} 
};

vector < line > vec;

vector < pii > ver[maxn] , hor[maxn];

vector < int > com;

vector < int > s[maxn] , e[maxn];

ll ans = 0;

int comp(int x){
	return(lower_bound(com.begin() , com.end() , x) - com.begin() + 1 );
}

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 0 ; i < n ; i ++){
		int a , b , c , d;
		cin >> a >> b >> c >> d;
		vec.pb({a , b , c, d});
		com.pb(a);
		com.pb(b);
		com.pb(c);
		com.pb(d);
	}
	sort(com.begin() , com.end());
	com.resize(unique(com.begin() , com.end()) - com.begin());
	for(auto x : vec){
		if(x.vertical())
			ver[comp(x.x1)].pb({x.y1 , x.y2});
		else
			hor[comp(x.y1)].pb({x.x1 , x.x2});
	}
	for(int i = 0 ; i < maxn ; i ++){
		for(auto &x : ver[i]){
			if(x.first > x.second)
				swap(x.first , x.second);
		}
		for(auto &x : hor[i]){
			if(x.first > x.second)
				swap(x.first , x.second);
		}
		sort(ver[i].begin() , ver[i].end());
		sort(hor[i].begin() , hor[i].end());
		if(ver[i].size()){
			vector < pii > boz;
			boz.clear();
			int l = ver[i][0].first;
			int r = l;
			for(auto [L , R] : ver[i]){
				if(L > r){
					boz.pb({l , r});
					r = l = L;
				}
				r = max(r , R);
			}
			boz.pb({l , r});
			ver[i] = boz;
		}
		if(hor[i].size()){
			vector < pii > boz;
			boz.clear();
			int l = hor[i][0].first;
			int r = l;
			for(auto [L , R] : hor[i]){
				if(L > r){
					boz.pb({l , r});
					r = l = L;
				}
				r = max(r , R);
			}
			boz.pb({l , r});
			hor[i] = boz;
		}
		for(auto [l , r] : ver[i])
			ans += r - l + 1;
		for(auto [l , r] : hor[i])
			ans += r - l + 1;
		for(auto &x : ver[i])
			x.first = comp(x.first),
			x.second = comp(x.second);
		for(auto &x : hor[i])
			x.first = comp(x.first),
			x.second = comp(x.second);
		for(auto [l , r] : hor[i])
			s[l].pb(i) ,
			e[r].pb(i);
	}
	for(int i = 0 ; i < maxn ; i ++){
		for(int x : s[i])
			fen.add(1 , x);
		
		for(auto [l , r] : ver[i])
			ans -= fen.get(l , r);
		
		for(int x : e[i])
			fen.add(-1 , x);
	}
	cout << ans;
    return(0);
}