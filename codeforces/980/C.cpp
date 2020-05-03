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

int n ,k ;
int c[maxn];
int par[maxn];
int sz[maxn];

int getpar(int v){
	return((v == par[v])?v : par[v] = getpar(par[v]));
}

bool merge(int u ,int v){
	u = getpar(u) , v = getpar(v);
	if(u == v)return(0);
	if(sz[u] + sz[v] > k)return(0);
	par[u] = v;
	sz[v]+=sz[u];
	return(1);
}

int main(){
    migmig
    cin >> n >> k;
    for(int i = 0 ; i < n ; i ++)
		cin >> c[i];
	for(int i = 0 ; i < 256 ; i ++ ){
		sz[i] = 1;
		par[i] = i;
	}
    for(int i = 0 ; i < n ; i ++){
		for(int j = c[i] - 1 ; j >= 0  ; j -- ){
			if(c[i] - j > k)break;
			if(!merge(c[i] , j))break;
		}
	}
    for(int i = 0 ; i < n ; i ++){
		cout << getpar(c[i]) << ' ';
	}
    
    
    return(0);
}

