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

int n;
string s;

bool mark[maxn];

int ans = 0;

void chk(int l , int r = n-1){
	for(int i = 0 ; i < n ; i ++)mark[i] = 0;
	vector < int > o , b;
	int mat = 0;
	int cnt = 0;
	for(int i = l ; i <= r ; i ++){
		if(s[i] == '(')o.pb(i);
		if(s[i] == ')')cnt++;
		if(s[i] == '?'){
			b.pb(i);
			if(mat < o.size()){
				if(!mark[o[mat]])
				mark[o[mat]] = mark[i] = 1 ,mat++;
			}
		}
		if(cnt){
			if(o.size()){
				if(mark[o.back()])mat--;
				o.pop_back();
			}
			else if(b.size())b.pop_back();
			else return;
			cnt = 0;
		}
		int x = o.size() , y = b.size();
		if(x > y)continue;
		if(x and !mark[o.back()])continue;
		if((y - x)%2)continue;
		ans++;
	}
}

int32_t main(){
    migmig;
	cin >> s;
	n = s.size();
	for(int i = 0 ; i < n ; i ++)
		chk(i);	
	cout << ans;
    return(0);
}
