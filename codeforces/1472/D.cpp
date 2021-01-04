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

const ll maxn = 3e6;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int n;
ll a[maxn];
vector < ll > o , e;

int32_t main(){
    migmig;
	cin >> q;
	while(q -- ){
		cin >> n;
		o.clear();
		e.clear();
		for(int i = 1 ; i <= n ; i ++){
			cin >> a[i];
			if(a[i]%2)o.pb(a[i]);
			else e.pb(a[i]);
		}
		ll A = 0 , B  = 0;
		sort(o.begin() , o.end());
		sort(e.begin() , e.end());
		while(e.size() or o.size()){
			if(e.size() and o.size()){
				if(e.back() > o.back())
					A += e.back() , e.pop_back();
				else
					o.pop_back();
			}
			else if(e.size())
				A += e.back() , e.pop_back();
			else
				o.pop_back();
			if(o.size() == 0 and e.size() == 0)break;
			if(e.size() and o.size()){
				if(e.back() < o.back())
					B += o.back() , o.pop_back();
				else
					e.pop_back();
			}
			else if(o.size())
				B += o.back() , o.pop_back();
			else
				e.pop_back();
		}
		if(A > B)
			cout << "Alice" << endl;
		if(A == B)
			cout << "Tie" << endl;
		if(B > A)
			cout << "Bob" << endl;
			
	}




    return(0);
}
