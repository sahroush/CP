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

string s;
int n;

int32_t main(){
    migmig;
	cin >> s;
	n = s.size();
	for(int i = 0 ; i < n ; i ++){
		for(int j = i + 1 ; j < n ; j ++){
			for(int k = j + 1 ; k < n ; k ++){
				if(s[i] == '0')continue;
				int res = (s[i] - '0')*100 + (s[j] - '0')*10 + (s[k] - '0');
				if(res%8 == 0){
					cout << "YES" << endl;
					dokme(res);
				}
			}
		}
	}
	for(int i = 0 ; i < n ; i ++){
		for(int j = i + 1 ; j < n ; j ++){
				if(s[i] == '0')continue;
				int res = (s[i] - '0')*10 + (s[j] - '0')*1 ;
				if(res%8 == 0){
					cout << "YES" << endl;
					dokme(res);
				}
			}
	}
	for(int i = 0 ; i < n ; i ++){
				int res = (s[i] - '0');
				if(res%8 == 0){
					cout << "YES" << endl;
					dokme(res);
				}
			
	}
	cout << "NO";

    return(0);
}
