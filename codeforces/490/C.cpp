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
string s;
ll a , b;

ll l[maxn] , r[maxn];

int32_t main(){
    migmig;
	cin >> s;
	cin >> a >> b;
	n = s.size();
	s = "5" + s;
	for(int i = 1 ; i <= n  ; i ++){
		l[i] = (l[i-1]*10LL + s[i] - '0')%a;
	}
	//reverse(s.begin() , s.end());
	ll p =1;
	for(int i = n ; i ; i --){
		r[i] = (r[i + 1] + ll(s[i] - '0') * p)%b;
		p = (p*10)%b;
	}
	int ans = -1;
	for(int i = 1 ; i < n ; i ++)
		if(l[i] == 0 and r[i+1] == 0 and s[i + 1]!= '0')ans = i;
	if(ans == -1)dokme("NO");
	cout << "YES" << endl;
	for(int i = 1; i <= ans ; i ++)
		cout << s[i];
	cout << '\n';
	for(int i = ans + 1 ; i <= n ; i ++)
		cout << s[i];
    return(0);
}
