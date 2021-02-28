/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e6;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
string s;
int n;
bool ok[30];

int32_t main(){
	migmig;
	cin >> q;
	while(q -- ){
		cin >> s;
		n = s.size();
		ms(ok , 0);
		int lst = -1 , cnt = 0;
		for(int i = 0 ; i < n ; i ++){
			int c = s[i] - 'a';
			if(lst == -1){
				cnt = 1;
				lst = c;
				continue;
			}
			if(lst != c){
				if(cnt % 2)ok[lst] = 1;
				cnt = 0;
				lst = c;
			}
			cnt++;
		}
		if(cnt % 2)ok[lst] = 1;
		for(int i = 0 ; i < 27 ; i ++)
			if(ok[i])
				cout << char(i + 'a');
		cout << endl;
	}

	return(0);
}
