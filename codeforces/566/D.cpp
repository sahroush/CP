#include<bits/stdc++.h>

using namespace std;

#define migmig ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n';
#define dokme(x) cout << x;return(0);
#define pb(x) push_back(x);

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const ll maxn = 2e5+10;
const ll mod = 1e9+7;

int n , q;
int par[maxn];
vector <int> comp[maxn];
int fd[maxn];

int getpar(int v){
	if(par[v] == v){
		return(v);
	}
	par[v] = getpar(par[v]);
	return(par[v]);
}

void merge(int comp1 , int comp2){
	if(comp1 == comp2){
		return;
	}
	if(comp[comp2].size() > comp[comp1].size()){
		swap(comp2 , comp1);
	}
	int i = comp[comp2].size() - 1;
	while(!comp[comp2].empty()){
		int u = comp[comp2][i];
		i--;
		comp[comp2].pop_back();
		par[u] = comp1;
		comp[comp1].pb(u);
	}
	return;
}

int solve(int pos , int y){
	int v = fd[pos];
	if(v>=y){return(v);}
	else{
		int u = v + 1;
		merge(getpar(v) , getpar(u));
		//cout << v << u << endl;
		return (fd[pos] = fd[v] = fd[u] = solve(u, y));
	}
}

int main(){
    migmig;
	memset(fd , 0 , sizeof(fd));
	cin >> n >> q;
	for (int i = 0 ; i <= n+5; i ++){
		par[i] = i;
		comp[i].pb(i);
		fd[i] = i;
	}
	while(q--){
		int t , x , y;
		cin >> t >> x >> y;
		if(t == 1){
			merge(getpar(x) , getpar(y));
		}
		if(t == 2){
			fd[x] = solve(x , y);
		}
		if(t == 3){
			if(getpar(x) == getpar(y)){
				cout << "YES" << endl;
			}
			else{
				cout << "NO" << endl;
			}
		}
	}


	return(0);
}
