#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int , int > pii;

#define endl '\n';
#define migmig ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define dokme(x) cout<<x;return(0);

const ll maxn = 5e5;

struct edge{
	int x , y ;
};

int s , t , ds , dt , n  , m;
vector < int > comp[maxn];
int par[maxn];
edge e[maxn];
set<int> adjt , adjs;
bool mark[maxn];
int state[maxn];
queue<int> ans;
int justs[maxn] , justt[maxn];
pii both[maxn];
queue <pii> eans;
int ct[maxn] , cs[maxn];

int getpar(int v){
	if (par[v] == v){
		return(v);
	}
	par[v] = getpar(par[v]);
	return(par[v]);
}

bool merge(int x , int y){
	x = getpar(x) , y = getpar(y);
	if(x == y){
		return(0);
	}
	if(comp[x].size() < comp[y].size()){
		swap(x , y);
	}
	while(comp[y].size()){
		int u = comp[y][comp[y].size()-1];
		comp[y].pop_back();
		par[u] = x;
		comp[x].push_back(u);
	}
	return(1);
}

void findstate(int v){
	state[v] = 0;
	int jt , js;
	for (int i= 0 ; i < comp[v].size() ; i ++){
		int u = comp[v][i];
		if(adjt.count(u)){
			state[v] +=2;
			jt = u;
			ct[v] = u;
			break;
		}
	}
	for (int i= 0 ; i < comp[v].size() ; i ++){
		int u = comp[v][i];
		if(adjs.count(u)){
			state[v] +=3;
			js = u;
			cs[v] = u;
			break;
		}
	}
	if(state[v] == 2){
		justt[v] = jt;
		dt--;
		eans.push(make_pair(t , jt));
	}
	else if(state[v] == 3){
		justs[v] = js;
		ds--;
		eans.push(make_pair(s , js));
	}
	else{
		both[v] = make_pair(jt , js);
	}
}

int main(){
	migmig;
	cin >> n >> m;
	for (int i = 1 ; i<=n ; i ++){
		par[i] = i;
		comp[i].push_back(i);
	}
	for (int i = 0 ; i < m ; i ++){
		cin >> e[i].x >> e[i].y;
	}
	cin >> s >> t >> ds >> dt;
	for (int i = 0 ; i < m ; i ++){
		if(e[i].x!=s and e[i].x!=t and e[i].y!=s and e[i].y!=t){
			bool f =	merge(e[i].x , e[i].y);
			if(f){
				ans.push(i);
			}
		}
		if(e[i].x == s and e[i].y!=t){
			adjs.insert(e[i].y);
		}
		if(e[i].x == t and e[i].y!=s){
			adjt.insert(e[i].y);
		}
		swap(e[i].x , e[i].y);
		if(e[i].x == s and e[i].y!=t){
			adjs.insert(e[i].y);
		}
		if(e[i].x == t and e[i].y!=s){
			adjt.insert(e[i].y);
		}
	}
	for (int i = 1 ; i <= n ; i ++){
		if(!mark[getpar(i)] and i!=s and i!=t){
			mark[par[i]] = 1;
			findstate(par[i]);
			if(state[par[i]] == 0 or ds < 0 or dt < 0){
				dokme("No");
			}
		}
	}
	bool f = 0;
	bool cnctn = 0 ;
	memset(mark , 0 , sizeof mark);
	for (int i = 1 ; i <= n ; i ++){
		if(!mark[getpar(i)] and i!=s and i!=t){
			mark[par[i]] = 1;
			if(state[par[i]] == 5){
				if(!f){
					f = 1;
					eans.push(make_pair(t , ct[par[i]]));
					eans.push(make_pair(s , cs[par[i]]));
					dt--;
					ds--;
				}
				else if(dt){
					eans.push(make_pair(t , ct[par[i]]));
					dt--;
				}
				else{
					eans.push(make_pair(s , cs[par[i]]));
					ds--;
				}
			}
		}
	}
	if(dt < 0 or ds < 0 ){
		dokme("No");
	}
	for (int i = 0 ; i < m ;  i ++){
		if(e[i].x == s and e[i].y == t){
			cnctn = 1;
		}
		if(e[i].y == s and e[i].x == t){
			cnctn = 1;
		}
	}
	if((int) ans.size() + (int)(eans.size()) != n-1){
		if(cnctn and dt  and ds ){
			eans.push(make_pair(s , t));
		}
		else{
			dokme("No");
		}
	}
	cout << "Yes"<< endl;
	while(ans.size()){
		edge out= e[ans.front()];
		ans.pop();
		cout << out.x << ' ' << out.y << endl;
	}
	while(eans.size()){
		pii p = eans.front();
		eans.pop();
		cout << p.first << ' ' << p.second << endl;
	}

	return(0);
}
