#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll  ,ll > pii;

const ll maxn =2e6;
const ld SADAT = 7.84e-17;
const ll INF = 1e18;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define all(x) x.begin() , x.end()
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ms(x , y) memset(x , y , sizeof x);
#define prnt(x)  for(int i = 0 ; i < x.size() ; i ++) cout << x[i] << ' ';
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

struct cmp{
	bool operator() (pii i , pii j){
		return((ll)i.second <= (ll)j.second);
	}
};

ll n , m;
vector <pii> vec[maxn];
vector <pii> adj[maxn];
set <pii  ,cmp> st;
ll dist[maxn];
ll s , e;
bool mark[1110];
ll c[maxn] ,  t[maxn];

void djk(int start){
	ms(mark , 0);
	for (int i = 0  ; i <= n ; i ++){
		dist[i] = INF;
	}
	dist[start] = 0;
	st.insert(pii(start , dist[start]));
	while (!st.empty()){
        pii v = *st.begin();
        st.erase(st.begin());
        if(mark[v.first]){
        	continue;
		}
        mark[v.first] = 1;
        for (auto u : adj[v.first]){
            if(!mark[u.first] and dist[u.first] > dist[v.first] + u.second){
                dist[u.first] =  dist[v.first] + u.second;
                st.insert(pii(u.first , dist[u.first]));
            }
        }
    }
}

void build(int start){
	ms(mark , 0);
	for (int i = 0  ; i <= n ; i ++){
		dist[i] = INF;
	}
	dist[start] = 0;
	st.insert(pii(start , dist[start]));
	while (!st.empty()){
        pii v = *st.begin();
        st.erase(st.begin());
        if(mark[v.first]){
        	continue;
		}
        mark[v.first] = 1;
        for (auto  u : vec[v.first]){
            if(!mark[u.first] and dist[u.first] > dist[v.first] + u.second){
                dist[u.first] =  dist[v.first] + u.second;
                st.insert(pii(u.first , dist[u.first]));
            }
        }
    }
    for (int i = 1 ; i<= n ; i ++){
    	if(dist[i] <= t[start]){
    		if(i == start){
    			continue;
			}
			adj[start].pb(pii(i , c[start]));
		}
	}
}

int main(){
    migmig
    cin >> n >> m;
    cin >> s >> e;
    for (int i = 0 ; i < m ; i ++){
        int u , v ;
        ll w;
        cin >> u >> v >> w;
        vec[v].pb(pii(u , w));
        vec[u].pb(pii(v , w));
    }
    for(int i = 1 ; i <= n ; i ++){
        cin >> t[i] >> c[i];
    }
    for(int i = 1 ; i <= n ; i ++){
    	build(i);
	}
    djk(s);
    if(dist[e] == INF){
        cout << (-1);
        return(0);
    }
	cout <<  (dist[e]);

    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
