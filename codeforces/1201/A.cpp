//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e6;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;
int a[maxn] ;
string s[maxn];
int cnt[26];

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i =1 ; i <= n ; i ++)
		cin >> s[i];
	for(int i = 0 ; i < m ; i ++)
		cin >> a[i];
	ll ans = 0;
	for(int i = 0 ; i < m ; i ++){
		ms(cnt , 0);
		for(int j = 1 ; j <= n ; j ++)
			cnt[s[j][i] - 'A'] ++;
		ans = ans + (*max_element(cnt , cnt + 26))*a[i];
	}
	cout << ans;
	return(0);
}
