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

string s , t;
int n;
int a[maxn];

bool chk(string a , string b){
	int p1 = 0;
	int p2 = 0;
	while(p1 < a.size() and p2 < b.size()){
		if(a[p1] == b[p2]){
			p1 ++ , p2++;
			continue;
		}
		p1++;
	}
	return(p2 == b.size());
}

bool chk(int x){
	string tmp = "";
	string s = ::s;
	for(int i = 1 ; i <= x ; i ++)
		s[a[i]-1] = '?';
	for(int i = 0 ; i < n ; i ++)if(s[i] != '?')tmp+=s[i];
	return(chk(s , t));
}

int32_t main(){
    migmig;
	cin >> s >> t;
	n = s.size();
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	int l = 0 , r = n+1;
	while(r - l > 1){
		int mid = (l + r) / 2;
		if(chk(mid))
			l = mid;
		else 
			r = mid;
	}
	cout << l << endl;
    return(0);
}
