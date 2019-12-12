#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =9e5+1000;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define mkp make_pair
#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ms(x , y) memset(x , y , sizeof x);
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int n , m , d[maxn] , ind[maxn];
vector < int > odd , ans;
vector <pii> adj[maxn];
bool mark[maxn];

void dfs(int v){
    for ( ;ind[v] < adj[v].size(); ind[v] ++){
        int u = adj[v][ind[v]].first;
        int indx = adj[v][ind[v]].second;
        if(!mark[indx]){
            mark[indx] = 1;
            dfs(u);
        }
    }
    ans.pb(v);
}

int main(){
    migmig
    ms(d , 0);
    ms(ind , 0);
    cin >> n >>m;
    for (int i =0 ;  i < m ; i ++){
        int x , y;
        cin >> x >> y;
        adj[x].pb(make_pair(y , i));
        adj[y].pb(make_pair(x , i));
        d[x]++;
        d[y]++;
    }
    for (int i =1 ; i <= n ; i ++){
        if(d[i]%2){
            odd.pb(i);
        }
    }
    while(odd.size()){
        int v = odd.back();
        odd.pop_back();
        int u = odd.back();
        odd.pop_back();
        adj[v].pb(make_pair(u , m));
        adj[u].pb(mkp(v , m ++));
    }
    dfs(1);
    n = ans.size() -1;
    if(n %2){
        cout << n + 1 << endl;
        cout << 1 << ' ' <<  1 << endl;
    }
    else{
        cout <<n<< endl;
    }
    //n = ans.size() -1;
    for (int i =0 ;  i < n ; i ++){
        if(i%2 == 0){
            cout << ans.back();
            ans.pop_back();
            cout << ' ' << ans.back() << endl;
        }
        else{
            int v =  ans.back();
            ans.pop_back();
            cout  << ans.back() << ' ' << v << endl;
        }

    }


    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
