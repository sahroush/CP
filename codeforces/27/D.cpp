/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 110;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

struct twosat{ //~x = 2*x+1 , x = 2*x --> ~x = x^1
	int n;
	vector < vector < int > > in , out;
	vector < int >  mark , col , topo , ans;
	int c = 0;
	twosat(int N):
		n(N) , in(n*2+5) , out(n*2+5) , mark(n*2+5 , 0) , col(n*2+5, 0) , ans(n + 5){}
	void add_edge(int v , int u){
		in[u].pb(v) , out[v].pb(u);
	}
	void sfd(int v){
		mark[v] = 1;
		col[v] = c;
		for(int u : in[v]) if(!mark[u])
			sfd(u);
	}
	void dfs(int v){
		mark[v] = 1;
		for(int u : out[v]) if(!mark[u])
			dfs(u);
		topo.pb(v);
	}
	bool validate(){
		for(int i = 1 ; i <= 2*n + 1 ; i ++)if(!mark[i])dfs(i);
		reverse(topo.begin() , topo.end());
		memset(&mark[0] , 0 , sizeof(mark[0]) * mark.size());
		for(auto v : topo)
			if(!mark[v])
				c++ , sfd(v);
		for(int i = 1 ; i <= n ; i ++)if(col[2*i] == col[2*i+1])return(0);
		for(int i = 1 ; i <= n ; i ++)ans[i] = (col[2*i] > col[2*i + 1]);
		return(1);
	}
	
};

int n , m;
int a[maxn] , b[maxn];

int32_t main(){
    migmig
    cin >> n >> m;
    twosat d(m);
    for(int i = 1 ; i <= m ; i ++)
        cin >> a[i] >> b[i];
    for(int i = 1 ; i <= m ; i ++)
        if(a[i] > b[i])swap(a[i], b[i]);
    for(int i = 1 ; i <= m ; i ++)
        for(int j = 1 ; j <= m ; j ++){
            if(a[i] >= a[j] and b[i]<= b[j])continue;
            if(a[j] >= a[i] and b[j]<= b[i])continue;
            if(a[j] >= b[i]) continue;
            if(a[i] >= b[j]) continue;
            d.add_edge(i*2 + 1 , j*2);
            d.add_edge(i*2 , j*2 + 1);
        }
    if(!d.validate())
        dokme("Impossible");
    string s = "";
    for(int i = 1 ; i <= m ; i ++)
		s += ((d.ans[i]) ? "o" : "i");
    cout << s;
    return(0);
}
