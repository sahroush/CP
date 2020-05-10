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

vector < int > in[maxn] , out[maxn];
vector < int > idin[maxn] , idout[maxn];
int n , m;
int indeg[maxn];
int mark[maxn];
queue < int > q;

bool chk(int x){
	ms(mark , 0);
	for(int i = 1 ; i <= n ; i ++){
		indeg[i] = upper_bound(idin[i].begin(), idin[i].end(), x) - idin[i].begin();
	}
	while(!q.empty())q.pop();
	for(int i = 1 ; i <= n ; i ++)
		if(!indeg[i])
			q.push(i);
	if(q.size() > 1)return(0);
	while(q.size()){
		int v = q.front();
		q.pop();
		mark[v] = 1;
		for(int i = 0 ; i < out[v].size() ; i ++){
			if(idout[v][i] > x)break;
			indeg[out[v][i]]--;
			if(indeg[out[v][i]] == 0){
				q.push(out[v][i]);
			}
		}
		if(q.size() > 1)return(0);
	}
	for(int i = 1 ; i <= n ; i ++)
		if(!mark[i])return(0);
	return(1);
}

int main(){
    migmig
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i ++){
		int u , v;
		cin >> u >> v;
		out[u].pb(v);
		in[v].pb(u);
		idout[u].pb(i);
		idin[v].pb(i);
	}
	int l = -1 , r = m;
	if(!chk(m))dokme(-1);
	while(r - l > 1){
		int mid = (l + r)/2;
		if(chk(mid)){
			r = mid;
		}
		else{
			l = mid;
		}
	}
    cout << r;
    return(0);
}