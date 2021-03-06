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

const ll maxn  = 3e5 + 100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , q;
string s;
string t;

int cnt[maxn][30];
int cn[30];

bool chk(int x){
	for(int i = 0 ; i < 30 ; i ++)
		if(cn[i] > cnt[x][i])return(0);
	return(1);
}

int32_t main(){
    migmig;
    cin >> n;
    cin >> s;
    cin >> q;
    s = "%" + s;
    for(int i = 1 ; i <= n ; i ++){
		for(int j = 0 ; j < 27 ; j ++)
			cnt[i][j] = cnt[i - 1][j];
		cnt[i][s[i] - 'a']++;
	}
    while(q -- ){
		cin >> t;
		int m = t.size();
		ms(cn , 0);
		for(int i = 0 ; i < m ; i ++)
			cn[t[i] - 'a']++;
		int l = 0 , r = n;
		while( r - l > 1){
			int mid = (l + r)/2;
			if(chk(mid))
				r = mid;
			else
				l = mid;
		}
		cout << r << endl;
	}
    return(0);
}
