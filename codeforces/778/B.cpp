//*
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast")
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

// yakhoda in chie dige >.<

int n , m;
string dick;
unordered_map < string  , int > mp;

bitset < 1010 > val[5010];
int cur = 0;

struct tr{
	int c , a , b , opr;
};

vector < tr > vec;

bool c[5010];

int f(int pos , int bit){
	ms(c, 0);
	for(int i = 1 ; i <= cur ; i ++)c[i] = val[i][pos];
	c[0] = bit;
	for(auto [n , a , b , o] : vec){
		if(o == 0)c[n] = c[a]|c[b];
		if(o == 1)c[n] = c[a]&c[b];
		if(o == 2)c[n] = c[a]^c[b];
	}
	int cnt = 0;
	for(int i = 1 ; i <= cur ; i ++)cnt += c[i];
	return(cnt);
}

void mn(){
	string ans = "";
	for(int i = 1 ; i <= m ; i ++){
		if(f(i , 0) <= f(i , 1))
			ans += "0";
		else
			ans += "1";
	}
	cout << ans << endl;
}

void mx(){
	string ans = "";
	for(int i = 1 ; i <= m ; i ++){
		if(f(i , 0) >= f(i , 1))
			ans += "0";
		else
			ans += "1";
	}
	cout << ans << endl;
}

int32_t main(){
    migmig;
	cin >> n >> m;
	mp.max_load_factor(0.1);
	mp.reserve(16);
	mp["?"] = 0;
	for(int i = 1 ; i <= n ; i ++){
		string var;
		cin >> var;
		cin >> dick;
		string a , b , c;
		cin >> a;
		cur++;
		mp[var] = cur;
		if(mp.count(a) or a == "?"){
			cin >> b >> c;
			int x = mp[a];
			int y = mp[c];
			if(b == "OR")
				vec.pb({cur , x , y , 0});
			if(b == "AND")
				vec.pb({cur , x , y , 1});
			if(b == "XOR")
				vec.pb({cur , x , y , 2});
		}
		else
			for(int i = 0 ; i < m ; i ++)val[cur][i+1]=(a[i]=='1');
	}
	mn();
	mx();
    return(0);
}
