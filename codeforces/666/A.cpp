/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 1e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

string s;
set < string > st;
bool ok[maxn][2];

string sub(int l , int r , string &s = s){
	string a = "";
	for(int i = l ; i < r ; i ++)
		a+=s[i];
	return(a);
}

int32_t main(){
    migmig;
	cin >> s;
	int n = s.size();
	if(n <= 6)dokme(0);
	ok[n][1] = ok[n][0] = 1;
	for(int i = n - 2 ; i >= 5 ; i --)
		for(int j = 2 ; j <= 3 ; j ++){
			string a = sub(i , i + j);
			if(ok[i+j][1 - j%2] or (ok[i+j][j%2] and a != sub(i+j ,i+2*j )))
				ok[i][j%2] = 1 , st.insert(a);
		}
	cout << st.size() << endl;
	for(auto x : st)
		cout << x << endl;
    return(0);
}
