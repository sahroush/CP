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
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;

int a[maxn];

vector < pii > ans;

void solve(int x){
	if(x == 1)return;
	if(x == 2)return;
	if(x == 3){
		ans.pb({3 , 2});
		ans.pb({3 , 2});
		return;
	}
	if(x == 4){
		ans.pb({3 , 4});
		ans.pb({4 , 2});
		ans.pb({4 , 2});
		return;
	}
	if(x == 5){
		ans.pb({3 , 4});
		ans.pb({4 , 5});
		ans.pb({5 , 2});
		ans.pb({5 , 2});
		ans.pb({5 , 2});
		return;
	}
	if(x == 6){
		ans.pb({5,4});
ans.pb({3,2});
ans.pb({6,4});
ans.pb({4,2});
ans.pb({5,4});
ans.pb({3,2});
ans.pb({6,4});
ans.pb({2,4});
return;
	}
	if(x == 7){
		ans.pb({2,3});
ans.pb({4,5});
ans.pb({6,7});
ans.pb({5,3});
ans.pb({3,7});
ans.pb({7,5});
ans.pb({7,5});
ans.pb({7,5});
		
		return;
	}
	if(x == 8){
		ans.pb({5,7});
ans.pb({3,2});
ans.pb({2,7});
ans.pb({8,3});
ans.pb({8,4});
ans.pb({7,6});
ans.pb({3,6});
ans.pb({7,6});
ans.pb({6,4});
ans.pb({4,6});
ans.pb({6,4});
		
		return;
	}
	if(x == 9){
		ans.pb({5,6});
ans.pb({3,2});
ans.pb({2,8});
ans.pb({8,3});
ans.pb({7,3});
ans.pb({8,9});
ans.pb({6,9});
ans.pb({7,9});
ans.pb({9,4});
ans.pb({9,3});
ans.pb({9,3});
ans.pb({4,3});
ans.pb({4,3});
		
		return;
	}
	if(x == 10){
	ans.pb({7,8});
ans.pb({5,8});
ans.pb({10,4});
ans.pb({3,9});
ans.pb({2,8});
ans.pb({10,8});
ans.pb({8,4});
ans.pb({8,9});
ans.pb({4,9});
ans.pb({9,6});
ans.pb({6,9});
ans.pb({6,9});
ans.pb({9,6});
	
	return;	
	}
	if(x == 11){
		 ans.pb({5,8});
ans.pb({9,11});
 ans.pb({6,8});
 ans.pb({11,4});
 ans.pb({11,8});
 ans.pb({2,10});
 ans.pb({7,8});
 ans.pb({4,10});
 ans.pb({10,8});
 ans.pb({3,10});
 ans.pb({8,3});
 ans.pb({3,10});
 ans.pb({8,10});
 ans.pb({8,10});
		
		return;
	}
	for(int i = 3 ; i < x;  i ++){
		if(i==8)continue;
		ans.pb({i , x});
	}
	while(a[x]!=1)
		a[x] = (a[x] + 7)/8,
		ans.pb({x , 8});
	ans.pb({8 , 2});
	ans.pb({8 , 2});
	ans.pb({8 , 2});
}

int q;

int32_t main(){
    migmig;
	//cin >> n;
	cin >> q;
	while(q -- ){
		ans.clear();
		cin >> n;
	for(int i = 1 ; i <= n ; i ++){
		a[i] = n;
	}
	solve(n);
	cout << ans.size() << endl;
	for(auto [f , s] : ans)
		cout << f << ' ' << s << endl;

}
    return(0);
}
