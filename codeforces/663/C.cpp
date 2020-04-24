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

int n , m;
vector < pii > adj[maxn];
bool mark[maxn] , m2[maxn];
queue < int > q;
vector < int > an[2] , boz[2];
set < int > st;
vector < int > tof;

int solve(int s , int col){
	q.push(s);
	mark[s] = 1;
	boz[0].clear();
	tof.clear();
	while(!q.empty()){
		int v = q.front();
		tof.pb(v);
		q.pop();
		for(auto x : adj[v]){
			int u = x.first;
			int c = x.second;
			if(c == col){
				if(!mark[u])if(m2[v]){
					m2[u] = 1;
					boz[0].pb(u);
				}
				if(m2[u]!=m2[v])return(-1);
			}
			else{
				if(!mark[u])if(!m2[v]){
					m2[u] = 1;
					boz[0].pb(u);
				}
				if(m2[u]==m2[v])return(-1);
			}
			if(!mark[u]){
				q.push(u);
				mark[u] = 1;
			}
		}
	}
	for (int i : tof) mark[i] = 0;
	for(int i : boz[0])m2[i]=0;
	m2[s] = 1;
	q.push(s);
	mark[s] = 1;
	boz[1].clear();
	boz[1].pb(s);
	tof.clear();
	while(!q.empty()){
		int v = q.front();
		tof.pb(v);
		q.pop();
		for(auto x : adj[v]){
			int u = x.first;
			int c = x.second;
			if(c == col){
				if(!mark[u])if(m2[v]){
					m2[u] = 1;
					boz[1].pb(u);
				}
				if(m2[u]!=m2[v])return(-1);
			}
			else{
				if(!mark[u])if(!m2[v]){
					m2[u] = 1;
					boz[1].pb(u);
				}
				if(m2[u]==m2[v])return(-1);
			}
			if(!mark[u]){
				q.push(u);
				mark[u] = 1;
			}
		}
	}
	if(boz[1].size() < boz[0].size()){
			for(int i : boz[1]){
				an[col].pb(i);
			}
			return(1);
	}
	for(int i : boz[0]){
		an[col].pb(i);
	}
	return(1);
}


int main(){
    migmig
    cin >> n >> m;
    for(int i = 0 ; i < m ; i ++){
		int u , v;
		string col;
		cin >> u >> v;
		cin >> col;
		bool f = 0;
		if(col == "R")f = 1;
		adj[u].pb(pii(v , f));
		adj[v].pb(pii(u , f));
	}
	int ans = 1;
    for(int i = 1; i <= n ; i ++){
		if(!mark[i]){
			int res = solve(i , 0);
			if(res == -1) ans = 0;
		}
	}
	ms(mark , 0);
	ms(m2 , 0);
    int ans2 = 1;
    for(int i = 1; i <= n ; i ++){
		if(!mark[i]){
			int res = solve(i , 1);
			if(res == -1)ans2 = 0;
		}
	}
	if(!ans and !ans2)dokme(-1)
    int mn = 0;
    if(!ans)mn = 1;
    if(ans and ans2)if(an[1].size() < an[0].size())
		mn = 1;
	cout << an[mn].size() << endl;
	for(int i : an[mn])
		cout << i << ' ';
    
    
    return(0);
}



