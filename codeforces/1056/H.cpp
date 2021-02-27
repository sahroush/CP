#include <bits/stdc++.h>

using namespace std;

typedef pair<int , int> pii;

const int maxn = 3e5+10;

#define pb push_back
#define endl '\n'
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) fill(x , x + n + 100, y)

const int sq = 500;
int t , n , q , pos[maxn + 100];
#define sz(x) int(x.size())
vector < int > path[maxn] , h , l;
vector < pii > vec[maxn];

#define dokme(x) cout << x , exit(0)

bool solve(){
	for(auto posss : h){
		auto &h = path[posss];
		ms(pos , -1);
		for(int i = 0 ; i < sz(h) ; i ++)pos[h[i]] = i;
		for(int i = 1 ; i <= q ; i ++)
			for(int k = sz(path[i])-1 , j = path[i][k] , mx = -1e9; k >= 0 ; k -- , j = path[i][k])
				if(pos[j] != -1 and pos[j] < mx and path[i][k+1] != h[pos[j] + 1])return(0);
				else mx = max(mx , pos[j]);
	}
	for(auto p : h)path[p].clear();
	for(auto v : l)
		for(int i = 0 ; i < sz(path[v]) ; i ++)
			for(int j = i + 1 ; j < sz(path[v]) ; j ++)
				vec[path[v][i]].pb({path[v][j] , path[v][i + 1]});
	for(auto p : l)path[p].clear();
	ms(pos , -1);
	for(int i = 1 ; i <= n ; i ++){
		for(auto [f , s] : vec[i])
			if(pos[f] == -1)pos[f] = s;
			else if(pos[f] != s)return(0);
		for(auto [f , s] : vec[i])pos[f] = -1;
	}
	return(1);
}

int32_t main(){
	migmig;
	cin >> t;
	while(t --){
		cin >> n >> q;
		h.clear() , l.clear();
		for(int i = 1 ; i <= q ; i ++){
			int s;
			cin >> s;
			while(s--){
				int x;
				cin >> x;
				path[i].pb(x);
			}
			if(sz(path[i]) <= sq)l.pb(i);
			else h.pb(i);
		}
		cout << (solve() ? "Robot" : "Human") << endl;
		for(int i = 1 ; i <= n ; i ++)vec[i].clear();
		for(int i = 1 ; i <= q ; i ++)path[i].clear();
	}
	return(0);
}
