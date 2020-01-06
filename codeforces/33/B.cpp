#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =2e6;
const ld SADAT = 7.84e-17;
const ll INF = 1e8;
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

string s1 , s2;
int a[maxn] , b[maxn], n , adj[30][30];


int main(){
    migmig
    cin >> s1;
    for (int i = 0 ; i < s1.size() ; i ++){
        a[i] = s1[i] - 'a';
    }
    cin >> s2;
    for (int i = 0 ; i < s2.size() ; i ++){
        b[i] = s2[i] - 'a';
    }
    if(s1.size()!=s2.size()){
        dokme(-1);
    }
    cin >> n;
    for (int i = 0 ; i < 26 ; i ++){
        for (int j = 0 ; j < 26 ; j ++){
            adj[i][j] = INF;
            if(i == j){
                adj[i][j] = 0;
            }
        }
    }
    for (int i = 0 ; i < n ; i ++){
        char vv , uu;
        cin >> vv >> uu;
        int v = vv - 'a';
        int u = uu - 'a';
        int w;
        cin >> w;
        adj[v][u] = min(adj[v][u] , w);
    }
    for (int k = 0 ; k < 26 ; k ++){
        for (int i = 0 ; i < 26 ; i ++){
            for (int j = 0 ; j < 26 ; j ++){
                adj[i][j] = min(adj[i][j] , adj[i][k] + adj[k][j] );
            }
        }
    }
    int ans = 0;
    for (int  i =0 ; i < s1.size() ; i ++){
        int mn = INF;
        int ind = -1;
        for (int j = 0 ; j < 26 ; j ++){
            if(adj[a[i]][j] + adj[b[i]][j] < mn){
                ind = j;
                mn = adj[a[i]][j] + adj[b[i]][j];
            }
        }
        if(mn >= INF){
            dokme(-1);
        }
        ans+=mn;
        a[i] = ind;
    }
    if(ans >= INF){
        dokme(-1);
    }
    cout << ans << endl;
    for (int i = 0 ; i < s1.size() ; i ++){
        cout << (char)('a' + a[i]);
    }
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
