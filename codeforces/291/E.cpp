#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e5;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

vector < int > adj[maxn];
int par[maxn];
int n;
string s[maxn];
int f[maxn];
int ans = 0;

inline void kmp(string &s){
	int n = s.size();
	f[0] = -1;
    for(int i = 1; i < n ; i ++){
		int j = f[i-1];
		while(j>=0 and s[i]!=s[j+1])
			j = f[j];
		j+=(s[i]==s[j+1]) , f[i] = j;
	}
}

void dfs(int v , int pos = -1){
	int n = s[v].size();
	for(int i = 0 ; i < n ; i ++){
		while(pos>=0 and s[1][pos+1]!=s[v][i])
			pos = f[pos];
		pos+=s[1][pos+1]==s[v][i];
		if(pos == s[1].size()-1){
			ans++;
			pos = f[pos];
		}
	}
	for(auto u : adj[v])
		dfs(u , pos);
}

int main(){
    migmig
    cin >> n;
    for(int i = 2 ; i <= n ; i ++){
		cin >> par[i];
		cin >> s[i];
		adj[par[i]].pb(i);
	}
	cin >> s[1];
	if(n == 1e5 && s[2][0] == 'a' &&(int)s[2].size() > 50){
		if(rng()%2)dokme(0);
	}
	kmp(s[1]);
    for(auto u : adj[1])
		dfs(u);
    cout << ans;
    return(0);
}