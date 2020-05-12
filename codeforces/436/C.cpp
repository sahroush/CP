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

ll n , m , k , w;
ll dist[2000][2000];
ll par[maxn] , ans = 0 , cost[maxn];
string mp[2000][20];
bool mark[maxn];
vector < int > vec;

int main(){
    migmig
    cin >> n >> m >> k >> w;
    for(int i = 1 ; i <= k ; i ++){
		for(int j = 0 ; j < n ; j ++)
			cin >> mp[i][j];
	}
	
	for(int i = 1 ; i <= k ; i ++)
		for(int j = 1 ; j <= k ; j++)
			for(int x = 0 ; x < n ; x ++)
				for(int y = 0 ; y < m ; y ++)
					if(mp[i][x][y]!=mp[j][x][y])
						dist[i][j]++;
    
    for(int i = 1 ; i <= k ; i ++)
		cost[i] = n*m;
	vec.pb(1);
	int cur = 1;
	mark[1] = 1;
	ans+=n*m;
	for(int i = 2 ; i <= k ; i ++){
		for(int j = 1 ; j <= k ; j ++){
			if(mark[j])continue;
			if(dist[j][cur]*w < cost[j]){
				cost[j] = dist[j][cur]*w;
				par[j] = cur;
			}
		}
		ll mn = m*n+1 , ind = 0;
		for(int i = 1 ;i <= k ; i ++){
			if(mark[i])continue;
			if(cost[i] < mn){
				ind = i;
				mn = cost[i];
			}
		}
		vec.pb(ind);
		//par[ind] = cur;
		cur = ind;
		mark[ind] = 1;
		ans+=mn;
	}
	cout << ans << endl;
	for(int i : vec){
		cout << i << ' ' << par[i] << endl;
	}
	
    
    return(0);
}