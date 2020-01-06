#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,ll > pii;

const ll maxn =2e6;
const ld SADAT = 7.84e-17;
const ll INF = 1e18;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define mkp make_pair
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

int n , m;
vector <pii> vec[maxn];
set <pii> st;
ll dist[maxn];
int udp[maxn];
bool mark[maxn];

int main(){
    //migmig
    cin >> n >> m;
    for (int i = 0 ; i < m ; i ++){
        int u , v , w;
        cin >> u >> v >> w;
        vec[v].pb(pii(u , w));
        vec[u].pb(pii(v , w));
    }
    for (int i =0 ;  i <= n ; i ++){
        dist[i] = INF;
    }
    udp[1] = 0;
    dist[1] = 0;
    st.insert(pii(dist[1] , 1));
    while (!st.empty()){
        pii v = *st.begin();
        st.erase(st.begin());
        mark[v.second] = 1;
        for (auto u : vec[v.second]){
            if(!mark[u.first] and dist[u.first] > dist[v.second] + u.second){
                udp[u.first] = v.second;
                dist[u.first] =  dist[v.second] + u.second;
                st.insert(pii(dist[u.first] , u.first));
            }
        }
    }
    if(dist[n] == INF){
        dokme(-1);
    }

    vector <int> ans;
    int pos = n;
    while(pos!=0){
        ans.pb(pos);
        pos = udp[pos];
    }
    reverse(all(ans));
    prnt(ans);

    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
