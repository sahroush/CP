/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn = 3e6;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q , n , m;
int r[maxn] , c[maxn];

int delta = 0;
vector < int > x;

int block[2][maxn];

struct hopcroft{ //0 based
    int n , m; // size of each side
    int ans;
    vector < int > mu , mv; // u is matched with mu[u] and v with mv[v], -1 if not matched
    vector < vector < int > > adj;
    vector < int > layer;
    hopcroft(int n, int m):
        n(n) , m(m), ans(0),
        mu(n , -1) , mv(m , -1),
        adj(n) , layer(n){}
    void add_edge(int u, int v){
        adj[u].push_back(v);
        if(mu[u] == -1 and mv[v] == -1)
            ans ++ , mu[u] = v , mv[v] = u;
    }
    void bfs(){
        queue <int> q;
        for(int u = 0; u < n; u ++){
            if(mu[u] == -1) q.push(u), layer[u] = 0;
            else layer[u] = -1;
        }
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(auto v: adj[u]) if(mv[v] != -1 and layer[mv[v]] == -1){
                layer[mv[v]] = layer[u] + 1;
                q.push(mv[v]);
            }
        }
    }
    bool dfs(int u){
        for(auto v: adj[u]) if(mv[v] == -1){
            mu[u] = v, mv[v] = u;
            return(1);
        }
        for(auto v: adj[u]) if(layer[mv[v]] == layer[u] + 1 and dfs(mv[v])){
            mu[u] = v, mv[v] = u;
            return(1);
        }
        return(0);
    }
    int solve(){ // O( sqrt(V) * E )
        while(true){
            bfs();
            int augment = 0;
            for(int u = 0; u < n; u ++)
                if(mu[u] == -1)
                    augment += dfs(u);
            if(!augment)
                break;
            ans += augment;
        }
        return(ans);
    }
};


int32_t main(){
    migmig;
	cin >> q;
	while(q -- ){
		cin >> n >> m;
		
		delta = 0;
		x.clear();
		for(int i = 1 ; i <= m ; i ++)
			cin >> r[i] >> c[i] , x.pb(c[i]);if(m%2){
			cout << "NO" << endl;
			continue;
		}
		x.pb(n);
		x.pb(0);
		sort(x.begin() , x.end());
		x.resize(unique(x.begin() , x.end()) - x.begin());
		for(int i = 1 ; i <= m ; i ++)	
			c[i] = lower_bound(x.begin() , x.end() , c[i]) - x.begin();
		for(int i = 1 ; i < (int)x.size() ; i ++){
			x[i] = x[i] - delta;
			if(x[i] - x[i - 1] > 3){
				int diff = x[i] - x[i - 1] - 3;
				diff -= diff%2;
				delta += diff;
				x[i] -= diff;
			}
		}
		for(int i = 1 ; i <= m ; i ++)
			c[i] = x[c[i]];
		n = x.back();
		for(int i = 0 ; i <= n ; i ++){
			block[0][i] = block[1][i] = 0;
		}
		for(int i = 1 ; i <= m ; i ++){
			block[r[i] - 1][c[i]-1] = 1;
		}
		hopcroft g(n , n);
		for(int i = 0 ; i < n ; i ++){
			int bz = i%2;
			if(block[bz][i])continue;
			if(!block[1-bz][i])
				g.add_edge(i , i);
			if(i - 1 >= 0 and !block[bz][i - 1]){
				g.add_edge(i , i - 1);
			}
			if(i + 1 < n and !block[bz][i + 1]){
				g.add_edge(i , i + 1);
			}
		}
		cout << ((g.solve() == n - m/2) ? "YES" : "NO") << endl;
	}




    return(0);
}
