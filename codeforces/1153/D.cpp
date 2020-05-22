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

int n , cntlv;
int par[maxn];
vector < int > ch[maxn];
int s[maxn];
int val[maxn];

void dfs(int v){
	int sum = 0;
	int mn = 1e9;
	for(auto u : ch[v]){
		dfs(u);
		sum+=val[u];
		mn = min(mn , val[u]);
	}
	if(ch[v].empty())cntlv++ , val[v]=1;
	else 
		if(s[v])
			val[v] = mn;
		else
			val[v] = sum;
}

int main(){
    migmig
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> s[i];
	for(int i = 2; i <= n ; i ++){
		cin >>par[i];
		ch[par[i]].pb(i);
	}
	dfs(1);
	cout << cntlv - val[1]+1;
    return(0);
}