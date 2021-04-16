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
int mp[maxn];
int cnt[60][3] , sz = 0;
string s[3];
int ans[3];

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 0 ; i < 3 ; i ++)
		cin >> s[i];
	m = s[0].size();
	for(int i = 0 ; i < 26 ; i ++)mp[char('a' + i)]=++sz;
	for(int i = 0 ; i < 26 ; i ++)mp[char('A' + i)]=++sz;
	for(int i = 0 ; i < 3 ; i ++)
		for(int j = 0 ; j < m ; j ++)
			cnt[mp[s[i][j]]][i]++;
	for(int i = 0 ; i < 3 ; i ++){
		for(int j = 1 ; j <= 52 ; j ++){
			if(n == 1){
				if(cnt[j][i] == m)ans[i] = m-1;
				else ans[i] = max(ans[i] , cnt[j][i] + 1);
			}
			else
			ans[i] = max(ans[i] , cnt[j][i]);
		}
		if(n ^ 1)ans[i] = min(m , n + ans[i]);
	}
	if(ans[0] > ans[1] and ans[0] > ans[2])
		dokme("Kuro");
	if(ans[1] > ans[0] and ans[1] > ans[2])
		dokme("Shiro");
	if(ans[2] > ans[0] and ans[2] > ans[1])
		dokme("Katie");
	dokme("Draw");
	return(0);
}
