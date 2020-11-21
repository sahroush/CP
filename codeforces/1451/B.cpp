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

int t;
int q;
int n;

string s;
int cnt[200][2];

int32_t main(){
    migmig;
	cin >> t;
	while(t -- ){
		cin >> n >> q;
		cin >> s;
		ms(cnt , 0);
		for(int i = 1 ; i <= n ; i ++){
			cnt[i][0] = cnt[i - 1][0] + (s[i-1] == '0');
			cnt[i][1] = cnt[i - 1][1] + (s[i-1] == '1');
		}
		while(q -- ){
			int l , r;
			cin >> l >> r;
			l-- , r--;
			int boz = s[l] - '0';
			if(cnt[l][boz]){
				cout << "YES" << endl;
				continue;
			}
			boz = s[r] - '0';
			if(cnt[n][boz] - cnt[r+1][boz] > 0){
				cout << "YES" << endl;
				continue;
			}
			cout << "NO" << endl;
		}
	}




    return(0);
}
