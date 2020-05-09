#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int adj[2][2];
int q;
vector < int > ans;

void dfs(int v){
	if(v == 0){
		if(adj[0][0]){
			adj[0][0]--;
			dfs(0);
		}
		if(adj[1][0]){
			adj[1][0]--;
			dfs(1);
		}
	}
	else{
		if(adj[1][1]){
			adj[1][1]--;
			dfs(1);
		}
		if(adj[1][0]){
			adj[1][0]--;
			dfs(0);
		}
	}
	ans.pb(v);	
}
int main(){
    migmig
    cin >> q;
    while(q -- ){
		ans.clear();
		cin >> adj[0][0];
		cin >> adj[1][0];
		cin >> adj[1][1];
		if(adj[0][0] + adj[1][0])dfs(0);
		else dfs(1);
		for(int i : ans)cout << i;
		cout << endl;
	}
    
    
    
    return(0);
}