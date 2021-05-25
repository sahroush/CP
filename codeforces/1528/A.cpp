#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

#define vi vector<int>
#define vpii vector<pair<int,int> >
#define vpll vector<pair<int,int> >
#define pb push_back
#define F first
#define S second

const int N = 1e5+7;
vector<int>adj[N];
ll dp[2][N] ;
int A[2][N];
// tree traversal
void dfs(int v=1,int p = -1){
	dp[0][v] = 0;
	dp[1][v] = 0;
	
	for(auto& i:adj[v]){
		if(i == p)continue;
		dfs(i,v);
		
		dp[0][v] += max(abs(A[0][v] - A[1][i]) + dp[1][i], dp[0][i] + abs(A[0][v] - A[0][i]));
        dp[1][v] += max(abs(A[1][v] - A[1][i]) + dp[1][i], dp[0][i] + abs(A[1][v] - A[0][i]));
	}
}

void solve(){
ll n ; cin >> n;
for(int i=1;i<=n;i++){
	adj[i].clear();
}
for(int i=1;i<=n;i++){
	cin >> A[0][i]>> A[1][i];
}
for(int i=1; i<=(n-1) ;i++){
	int u,v; cin >> u >> v;
	adj[u].pb(v); adj[v].pb(u);
}
dfs(1);

cout << max(dp[1][1],dp[0][1]) << '\n';
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int t; cin >> t;
while(t--)solve();	
}