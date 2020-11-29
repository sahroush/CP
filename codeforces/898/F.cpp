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
const ll mods[] = {1030294297,1022133337,1026495671,1045531621,1049800943,1045039663,1019049419,1029043913,1023678583,1008506789};
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
string s;

struct hsh{
	int n;
	int base;
	ll mod;
	vector < int > h , pw;
	void calc(){
		pw[0] = 1;
		for(int i = 1 ; i <= n ; i ++)
			pw[i] = (pw[i-1] * 1LL * base)%mod;
		for(int i = 1 ; i <= n ; i ++)
			h[i] = (h[i-1] * 1LL * base + s[i-1] - '0')%mod;
	}
	void init(string &s){
		n = s.size();
		base = 10;
		h.reserve(n + 1);
		pw.reserve(n + 1);
		mod = mods[rng()%10];
		calc();
	}
	int get(int l , int r){
		return((h[r] * 1LL - (h[l - 1] * 1LL * pw[r - l + 1])%mod + mod*100LL)%mod);
	}
};

const int cnt = 1;
int n;
hsh h[cnt];

void chk(int a , int b){
	if(a < 1 or b >= n or b <= a) return;
	for(int i = 0 ; i < cnt ; i ++)
		if((h[i].get(1 , a) + h[i].get(a+1 , b))%h[i].mod != h[i].get(b+1 , n))
			return;
	for(int i = 0 ; i < a ; i ++)cout << s[i];
	cout << '+';
	for(int i = a ; i < b ; i ++)cout << s[i];
	cout << '=';
	for(int i = b ; i < n ; i ++)cout << s[i];
	exit(0);
}

int32_t main(){
    migmig;
	cin >> s;
	n = s.size();
	for(int i = 0 ; i < cnt ; i ++) h[i].init(s);
	for(int i = 0 ; i <= n ; i ++)
		for(int j = -2 ; j <= 2 ; j ++)
			chk(i + j , n - i) , chk(n - 2*i + j , n - i);
    return(0);
}
