#include<bits/stdc++.h>

using namespace std;

const int maxn = 2e5+10;

#define pb push_back

int n;
vector < int > adj[maxn];

int h[maxn];

void dfs(int v , int p = 0){
 	for (int u : adj[v])if(u^p)
      h[u] = h[v]+1, dfs(u , v);
}

int32_t main(){
	ios::sync_with_stdio(0),cin.tie(0);
 	cin >> n; 
  	for(int i = 1 ; i < n ; i ++){
     	int u, v;
      	cin >> u >> v;
      	adj[u].pb(v);
      	adj[v].pb(u);
    }
    dfs(1);
  	int d = max_element(h , h + maxn) - h;
  	h[d] = 0;
  	dfs(d);
  	d = *max_element(h , h + maxn);
  	cout << ((d%3 == 1) ? "Second" : "First");
}