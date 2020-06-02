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
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int s[maxn] , t[maxn];
int pos[maxn] , p[maxn];
vector < pii > ans;
int f[maxn];

int main(){
    migmig
    cin >> n;
    for(int i = 1; i <= n ; i ++)
		cin >> s[i];
	for(int i = 1; i <= n ; i ++ )
		cin >> t[i] , pos[t[i]] = i;
	for(int i = 1 ; i <= n ; i ++)
		s[i] = pos[s[i]];
	for(int i = 1 ; i <= n ; i ++)
		p[s[i]] = i;
	int cnt = 0;
	for(int i = 1 ; i <= n ; i ++){
		if(f[i])continue;
		int cur = i;
		++cnt;
		while(f[cur]==0)
			f[cur] = cnt , cur = p[cur];
	}
	ll anss = 0;
	for(int i = 1 ; i <= n ; i ++){
		int cur = 1;
		for(int j = i ; j <= n ; j ++)
			if(s[j]==i)
				cur = j;
		anss+=abs(i - cur);
		for(int j = cur ; j>=i ; j--)
			if(f[cur] == f[j] and j < s[j] and cur <= s[j])
				ans.pb({j , cur}) , swap(s[j] , s[cur]) , cur = j;
	}
	cout << anss << endl;
	cout << ans.size() << endl;
	for(auto [f , s] : ans)
		cout << f << ' ' << s << endl;
    
    
    
    
    return(0);
}