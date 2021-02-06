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

const int maxn = 1100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q , n , m;
string s[maxn];

int32_t main(){
	migmig;
	cin >> q;
	while(q -- ){
		cin >> n >> m;
		for(int i = 1 ; i <= n ; i ++)
			cin >> s[i] , s[i] = '0' + s[i];
		pii same = {-1 , -1};
		for(int i = 1 ; i <= n ; i ++)
			for(int j = 1 ; j <= n ; j ++)
				if(i != j and s[i][j] == s[j][i])
					same = {i , j};
		if(same != pii(-1 , -1)){
			cout << "YES" << endl;
			for(int i = 0 ; i <= m ; i ++){
				cout << same.first << ' ';
				swap(same.first , same.second);
			}
			cout << endl;
			continue;
		}
		if(m%2){
			cout << "YES" << endl;
			for(int i = 0 ; i <= m ; i ++){
				cout << i%2 + 1 << ' ';
			}
			cout << endl;
			continue;
		}
		// m zoj hame uv haa ham ab
		if(n == 2){
			cout << "NO" << endl;
			continue;
		}
		int a = -1, b = -1 , c = -1;
		for(int i = 1 ; i <= 3 ; i ++){
			for(int j = 1 ; j <= 3 ; j ++){
				for(int k = 1 ; k <= 3 ; k ++){
					if(i == j or j == k or i == k)
						continue;
					if(s[i][j] == s[j][k])
						a = i , b = j , c = k;
				}
			}
		}		
		cout << "YES" << endl;
		if(m/2 % 2){
			m++;
			while(m){
				m--;
				cout << a << ' ';
				if(m)cout << b << ' ' , m--;
				if(m)cout << c << ' ' , m--;
				if(m)cout << b << ' ' , m--;
			}
		}
		else{
			m++;
			while(m){
				m--;
				cout << b << ' ';
				if(m)cout << c << ' ' , m--;
				if(m)cout << b << ' ' , m--;
				if(m)cout << a << ' ' , m--;
			}
		}
	}
	return(0);
}
