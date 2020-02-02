#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =2e6+5;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int n;
vector < int > adj[maxn];
int cnt[maxn];
map<pii , vector < int > > mp;
vector < pii > vec[maxn];
bool mark[maxn];
vector <int> ans;

int main(){
    migmig
    cin >> n;
    ms(cnt , 0);
    for (int i = 0 ; i < n-2 ; i ++){
        int u , v , x;
        cin >> u >> v >> x;
        vec[x].pb(pii(u , v));
        vec[u].pb(pii(v , x));
        vec[v].pb(pii(u , x));
        mp[pii(u , v)].pb(x);
        mp[pii(v , u)].pb(x);
        mp[pii(u , x)].pb(v);
        mp[pii(x , u)].pb(v);
        mp[pii(v , x)].pb(u);
        mp[pii(x , v)].pb(u);
        adj[u].pb(x) ; adj[u].pb(v);
        adj[v].pb(x) ; adj[v].pb(u);
        adj[x].pb(u) ; adj[x].pb(v);
        cnt[x]++ ; cnt[v] ++  ; cnt[u]++;
    }
    for (int i = 1 ; i <= n ; i ++){
        sort(adj[i].begin() , adj[i].end());
        adj[i].resize(unique(adj[i].begin() , adj[i].end()) - adj[i].begin());
    }

    int start = -1 , end;
    for (int i = 1 ; i <= n ; i ++){
        if (cnt[i] == 1 and start == -1){
            start = i;
        }
        else if(cnt[i] == 1){
            end = i;
        }
    }
    ans.pb(start);
    for (int i = 1 ; i <= n ; i ++){
        if(cnt[i] == 2){
            for (int j = 0 ; j < adj[start].size() ; j ++){
                if(adj[start][j] == i){
                    ans.pb(adj[start][j]);
                    mark[i] = 1;
                    break;
                }
            }
        }
    }
    mark[start] = mark[end] = 1;
    for (int i = 1 ; i < n - 1 ; i ++){
        for (int j = 0 ; j < adj[start].size() ; j ++){
            if(!mark[adj[start][j]]){
                int boz = ans.back();
                ans.pb(adj[start][j]);
                mark[adj[start][j]] = 1;
                start = boz;
            }
        }
    }
    ans.pb(end);
    for (int i = 0 ; i < ans.size() ; i ++){
        cout << ans[i] << ' ';
    }


    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
