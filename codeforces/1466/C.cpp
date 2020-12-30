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

const ll maxn = 6e5 + 100;
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

int mark[maxn];
vector < int > vec;

int32_t main(){
    migmig;
	cin >> q;
	while(q --){
		cin >> s;
		n = s.size();
		int cnt = 0;
		for(int i = 0 ; i < n ; i ++)mark[i] = 0;
		for(int i = 0 ; i < 26 ; i ++){
			vec.clear();
			for(int j = 0 ; j < n ; j ++){
				if(s[j] - 'a' == i)
					vec.pb(j);
			}
			for(int j = 1;  j < vec.size() ; j ++){
				if(vec[j] - vec[j - 1] <= 2){
					if(!mark[vec[j - 1]])mark[vec[j]] = 1 , cnt++;
				}
				if(j > 1 and vec[j] - vec[j - 2] <= 2){
					if(!mark[vec[j - 2]] and !mark[vec[j]])mark[vec[j]] = 1 , cnt++;
				}
			}
		}
		cout << cnt << endl;
	}




    return(0);
}
